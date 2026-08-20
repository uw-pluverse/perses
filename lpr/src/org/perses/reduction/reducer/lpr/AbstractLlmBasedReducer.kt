/*
 * Copyright (C) 2018-2026 University of Waterloo.
 *
 * This file is part of Perses.
 *
 * Perses is free software; you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 3, or (at your option) any later version.
 *
 * Perses is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * Perses; see the file LICENSE.  If not see <http://www.gnu.org/licenses/>.
 */
package org.perses.reduction.reducer.lpr

import com.google.common.flogger.FluentLogger
import org.perses.grammar.AbstractParserFacade
import org.perses.grammar.onetoken.OneTokenParserFacade
import org.perses.reduction.AbstractNonDeletionBasedReducer
import org.perses.reduction.FixpointReductionState
import org.perses.reduction.ReducerContext
import org.perses.util.AbstractFileContent
import org.perses.util.AutoDeletableFolder
import org.perses.util.FileNameContentPair
import org.perses.util.Util
import org.perses.util.ktInfo
import java.nio.file.Files
import java.nio.file.Path
import kotlin.io.path.isExecutable
import kotlin.io.path.notExists

abstract class AbstractLlmBasedReducer(
  llmBasedReducerAnnotation: AbstractLlmReducerAnnotation,
  reducerContext: ReducerContext,
) : AbstractNonDeletionBasedReducer(llmBasedReducerAnnotation, reducerContext) {
  private val promptSystem =
    """
    |You are an assistant for program analysis and modifications.
    """.trimMargin()
  private val promptToGenerateProgram =
    """
    |Please generate analysis and the whole program in Markdown syntax, and ensure the following:
    |1. The program should be placed at the end of your response.
    |2. Wrap the program by a pair of ```
    |3. Do not include any additional text after the program.
    |
    |Example:
    |```c
    |int main() {
    |  return 0;
    |}
    |```
    """.trimMargin()
  private val promptToGenerateTargetList =
    """
    |Please generate analysis and the target list in Markdown syntax, and ensure the following:
    |1. The target list should be placed at the end of your response.
    |2. Each item in the list should start with * and be on a separate line.
    |3. Do not include any additional text after the list.
    |
    |Example:
    |* fn1
    |* fn2
    |* fn3
    """.trimMargin()
  abstract val primaryQuestion: String
  abstract val followupQuestion: String

  val canonicalParserFacade = reducerContext.configuration.canonicalParserFacade
  val listenerManager = reducerContext.listenerManager

  override fun getPreferredParserFacade(): AbstractParserFacade = OneTokenParserFacade()

  override fun internalReduce(fixpointReductionState: FixpointReductionState) {
    AutoDeletableFolder(
      file =
        executorService.createTempDirectory(
          prefix = "lpr_temp_",
          postfix = this::class.simpleName!!,
        ),
    ).use { tempDir ->
      val llmClientScript: Path =
        reducerContext.configuration.lprConfig.llmClientPath ?: run {
          // No --llm-client-script was provided, so LPR falls back to the bundled default
          // client. Make this fallback transparent: announce it through the listener manager
          // (so it surfaces in the reduction output, like other reducer notices) and explain
          // both what the default does and how to override it.
          val defaultScriptPath = tempDir.file.resolve(DEFAULT_LLM_CLIENT_SCRIPT_BASE_NAME)
          check(defaultScriptPath.notExists()) { "$defaultScriptPath already exists." }
          defaultLLMClientScript.content.writeToFile(defaultScriptPath)
          Util.setExecutable(defaultScriptPath)
          listenerManager.onAdHocMessageEvent(
            fixpointReductionState.createAdHocMessageEvent {
              "No --llm-client-script was provided, so LPR is falling back to the bundled " +
                "default LLM client '$DEFAULT_LLM_CLIENT_SCRIPT_BASE_NAME' " +
                "(materialized at $defaultScriptPath). It is an OpenAI-compatible client that " +
                "by default targets a local ollama server at http://localhost:11434/v1 with " +
                "model 'codellama:13b' and requests 5 completions per call. Pass " +
                "--llm-client-script <path> to use a different LLM client."
            },
          )
          defaultScriptPath
        }
      check(llmClientScript.isExecutable()) { "$llmClientScript must be a executable path." }

      val tree = fixpointReductionState.inputRepresentation.tree

      val llm =
        LargeLanguageModel(
          llmClientScript,
          tempDirectoryCreator = {
            AutoDeletableFolder(Files.createTempDirectory(tempDir.file, "llm-tmp-"))
          },
        )

      val nodeReductionStartEvent =
        fixpointReductionState.fixpointIterationStartEvent.createNodeReductionStartEvent(
          System.currentTimeMillis(),
          perFileSizeMetrics =
            fixpointReductionState.inputRepresentation
              .computePerFileSizeMetrics(),
          program = tree.programSnapshot,
          node = tree.realRoot,
          outputCreator = createOutputCreator(),
        )
      listenerManager.onNodeReductionStart(nodeReductionStartEvent)

      // Ask LLM primary question to get target list
      logger.ktInfo { "Asking the primary question." }
      val targetsToBeTransformed =
        llm.getTargetListFromLLM(
          primaryQuestion = primaryQuestion,
          program =
            reducerContext.configuration.originalFormatPrinter
              .print(
                tree.programSnapshot.payload,
              ).sourceCode,
          promptSystem = promptSystem,
          promptTargetList = promptToGenerateTargetList,
        )
      logger.ktInfo { "Target list to be optimized: $targetsToBeTransformed" }
      if (targetsToBeTransformed.isEmpty()) return

      // Ask LLM followup question for each target and apply the best response to the tree.
      for (target in targetsToBeTransformed) {
        logger.ktInfo { "Starting to optimize target: $target" }

        val programs =
          llm.getProgramsFromLLM(
            followupQuestion = followupQuestion,
            program =
              reducerContext.configuration.originalFormatPrinter
                .print(
                  tree.programSnapshot.payload,
                ).sourceCode,
            promptSystem = promptSystem,
            promptToGenerateProgram = promptToGenerateProgram,
          )

        val edits =
          programs
            .filter { canonicalParserFacade.isSourceCodeParsable(it) }
            .map { program ->
              val treeNode = createSparTreeNodeFromString(program)
              tree.createRootReplacementEdit(
                newRoot = treeNode,
                contextDescription = "LPR transformation: ${this::class}",
                transformationName = "LlmReplacement",
              )
            }

        // Test all valid edits and apply the best one to the tree immediately, so that the
        // following targets are optimized on top of it.
        val bestCandidateEdit =
          ignoreCachedEditsThenFindBestWrtProperty(
            edits,
            fixpointReductionState,
          )
        if (bestCandidateEdit != null) {
          // Applying the edit fires onAfterSparTreeEditApplied, so the driver's logging listener
          // emits onBestProgramUpdated for us; no need to emit it explicitly here.
          tree.applyEdit(
            bestCandidateEdit.edit,
            canonicalTokenCount = computeCanonicalTokenCount(bestCandidateEdit.outputManager),
          )
        }
      }

      listenerManager.onNodeReductionEnd(
        nodeReductionStartEvent.createEndEvent(
          currentTimeMillis = System.currentTimeMillis(),
          remainingQueueSize = 0,
          perFileSizeMetrics =
            fixpointReductionState.inputRepresentation
              .computePerFileSizeMetrics(),
        ),
      )
    }
  }

  abstract class AbstractLlmReducerAnnotation(
    shortName: String,
    description: String,
    reductionResultSizeTrend: ReductionResultSizeTrend,
  ) : NonDeletionBasedReducerAnnotation(
      shortName = shortName,
      description = description,
      reductionResultSizeTrend = reductionResultSizeTrend,
    )

  companion object {
    const val DEFAULT_LLM_CLIENT_SCRIPT_BASE_NAME = "default_llm_client.py"

    /**
     * The bundled LLM client used as a fallback when the user does not pass
     * `--llm-client-script`.
     *
     * This is a copy of `lpr/scripts/llm_client.py`: an OpenAI-compatible client that, by
     * default, targets a local ollama server (`http://localhost:11434/v1`, model `codellama:13b`)
     * and requests 5 completions per call. It is materialized into a temporary file and executed
     * by [internalReduce]; that fallback is announced through the listener manager so it is visible
     * to the user rather than silent.
     */
    val defaultLLMClientScript =
      FileNameContentPair(
        fileName = DEFAULT_LLM_CLIENT_SCRIPT_BASE_NAME,
        content =
          Util
            .openResourceAsStream(
              resourceName =
                "/lpr/src/" +
                  AbstractLlmBasedReducer::class.java.packageName.replace('.', '/') +
                  '/' +
                  DEFAULT_LLM_CLIENT_SCRIPT_BASE_NAME,
              klassUnderSamePkg = AbstractLlmBasedReducer::class.java,
            ).use { inputStream ->
              AbstractFileContent.BinaryFileContent.fromInputStream(inputStream)
            },
      )
    private val logger = FluentLogger.forEnclosingClass()
  }
}
