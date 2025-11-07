/*
 * Copyright (C) 2018-2025 University of Waterloo.
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
import org.perses.reduction.AbstractNonDeletionBasedReducer
import org.perses.reduction.FixpointReductionState
import org.perses.reduction.ReducerContext
import org.perses.spartree.AbstractSparTreeEdit
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.SparTreeBuilder
import org.perses.util.AbstractFileContent
import org.perses.util.AutoDeletableFolder
import org.perses.util.FileNameContentPair
import org.perses.util.Util
import org.perses.util.ktInfo
import org.perses.util.transformToImmutableList
import java.nio.file.Files
import java.nio.file.Path
import kotlin.io.path.isExecutable
import kotlin.io.path.notExists

abstract class AbstractLLMBasedReducer(
  llmBasedReducerAnnotation: AbstractLLMReducerAnnotation,
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

  val parserFacade = reducerContext.configuration.parserFacade
  val listenerManager = reducerContext.listenerManager

  override fun internalReduce(fixpointReductionState: FixpointReductionState) {
    AutoDeletableFolder(
      file =
        ioManager.lazilyInitializedReductionFolderManager.createTempDirectory(
          prefix = "lpr_temp_",
          postfix = this::class.simpleName!!,
        ),
    ).use { tempDir ->
      val llmClientScript: Path =
        reducerContext.configuration.lprConfig.llmClientPath ?: run {
          val defaultScriptPath = tempDir.file.resolve(DEFAULT_LLM_CLIENT_SCRIPT_BASE_NAME)
          check(defaultScriptPath.notExists()) { "$defaultScriptPath already exists." }
          defaultLLMClientScript.content.writeToFile(defaultScriptPath)
          Util.setExecutable(defaultScriptPath)
          defaultScriptPath
        }
      check(llmClientScript.isExecutable()) { "$llmClientScript must be a executable path." }

      val originalTree = fixpointReductionState.sparTree.getTreeRegardlessOfParsability()
      var bestEdit: AbstractSparTreeEdit<*>? = null
      var bestProgram = originalTree.programSnapshot

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
          program = bestProgram,
          node = originalTree.realRoot,
          outputCreator = {
            ioManager
              .createOutputManager(it)
              .fileContentList
              .transformToImmutableList {
                FileNameContentPair(
                  fileName = it.fileName.baseName,
                  content = it.content,
                )
              }
          },
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
                originalTree.programSnapshot,
              ).sourceCode,
          promptSystem = promptSystem,
          promptTargetList = promptToGenerateTargetList,
        )
      logger.ktInfo { "Target list to be optimized: $targetsToBeTransformed" }
      if (targetsToBeTransformed.isEmpty()) return

      // Ask LLM followup question for each target and select the best response
      for (target in targetsToBeTransformed) {
        logger.ktInfo { "Starting to optimize target: $target" }

        val programs =
          llm.getProgramsFromLLM(
            followupQuestion = followupQuestion,
            program =
              reducerContext.configuration.originalFormatPrinter
                .print(
                  bestProgram,
                ).sourceCode,
            promptSystem = promptSystem,
            promptToGenerateProgram = promptToGenerateProgram,
          )

        val edits =
          programs
            .filter { parserFacade.isSourceCodeParsable(it) }
            .map { program ->
              val treeNode = createSparTreeNodeFromString(program)
              originalTree.createRootReplacementEdit(
                newRoot = treeNode,
                actionsDescription = "LPR transformation: ${this::class}",
              )
            }

        // Test all valid edits and get the best one
        val bestCandidateEdit =
          ignoreCachedEditsThenFindBestWrtProperty(
            edits,
            fixpointReductionState,
          )
        if (bestCandidateEdit != null) {
          listenerManager.onBestProgramUpdated(
            fixpointReductionState.fixpointIterationStartEvent.createBestProgramUpdatedEvent(
              currentTimeMillis = System.currentTimeMillis(),
              programSizeBefore = bestProgram.tokenCount,
              programSizeAfter = bestCandidateEdit.program.tokenCount,
            ),
          )
          bestEdit = bestCandidateEdit
          bestProgram = bestEdit.program
          logger.ktInfo { "Found program with size ${bestEdit.program.tokenCount}" }
        }
      }

      listenerManager.onNodeReductionEnd(
        nodeReductionStartEvent.createEndEvent(
          currentTimeMillis = System.currentTimeMillis(),
          remainingQueueSize = 0,
          program = bestProgram,
        ),
      )

      if (bestEdit != null) {
        originalTree.applyEdit(bestEdit)
      }
    }
  }

  abstract class AbstractLLMReducerAnnotation(
    shortName: String,
    description: String,
    reductionResultSizeTrend: ReductionResultSizeTrend,
  ) : NonDeletionBasedReducerAnnotation(
      shortName = shortName,
      description = description,
      reductionResultSizeTrend = reductionResultSizeTrend,
    )

  private fun createSparTreeNodeFromString(sourceCode: String): AbstractSparTreeNode {
    val parseTreeWithParser = reducerContext.configuration.parserFacade.parseString(sourceCode)
    val sparTreeNodeFactory = reducerContext.sparTreeNodeFactory
    return SparTreeBuilder.createSparTreeNode(sparTreeNodeFactory, parseTreeWithParser)
  }

  companion object {
    const val DEFAULT_LLM_CLIENT_SCRIPT_BASE_NAME = "default_llm_client.py"

    val defaultLLMClientScript =
      FileNameContentPair(
        fileName = DEFAULT_LLM_CLIENT_SCRIPT_BASE_NAME,
        content =
          Util
            .openResourceAsStream(
              resourceName =
                "/src/" +
                  AbstractLLMBasedReducer::class.java.packageName.replace('.', '/') +
                  '/' +
                  DEFAULT_LLM_CLIENT_SCRIPT_BASE_NAME,
              klassUnderSamePkg = AbstractLLMBasedReducer::class.java,
            ).use { inputStream ->
              AbstractFileContent.BinaryFileContent.fromInputStream(inputStream)
            },
      )
    private val logger = FluentLogger.forEnclosingClass()
  }
}
