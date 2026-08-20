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
package org.perses.ppr.diff.list

import com.google.common.collect.ImmutableList
import org.perses.antlr.atn.LexerAtnWrapper
import org.perses.cmd.ReductionControlFlagGroup
import org.perses.grammar.AbstractParserFacade
import org.perses.ppr.diff.DiffOriginalReductionInputs
import org.perses.ppr.diff.PPRDiffUtils
import org.perses.program.AbstractPersesToken
import org.perses.program.ProgramSize
import org.perses.program.TokenizedProgram
import org.perses.reduction.AbstractProgramReductionDriver.Companion.createInputRepresentation
import org.perses.reduction.AbstractReductionDriver
import org.perses.reduction.AsyncReductionListenerManager
import org.perses.reduction.GlobalContext
import org.perses.reduction.TestScriptExecutorService
import org.perses.reduction.createSnapshot
import org.perses.reduction.event.ReductionStartEvent
import org.perses.reduction.io.AbstractOutputManagerFactory
import org.perses.reduction.io.PerFileSizeMetrics
import org.perses.reduction.io.ReductionFolder
import org.perses.util.AbstractEditOperation
import org.perses.util.ListAlignment
import org.perses.util.hashing.EnumShaAlgorithm
import org.perses.util.toImmutableList
import java.lang.StringBuilder
import java.nio.file.Path

class ListDiffReductionDriver private constructor(
  globalContent: GlobalContext,
  private val cmd: ListDiffCmdOptions,
  ioManagerList: ListDiffReductionIOManager,
  val diff: ImmutableList<AbstractEditOperation<AbstractPersesToken>>,
  private val enableDiffDdmin: Boolean,
  private val enableDiffSlicer: Boolean,
  private val listenerManager: AsyncReductionListenerManager,
  // The renderer (carries the code format) this driver owns, rather than the IO manager: it renders
  // the best diff for the Layer-2 sanity check, hands it to the reducers, and renders each accepted
  // best diff before saving. The list-diff stack does not adapt the format, so this is fixed.
  private val outputManagerFactory:
    AbstractOutputManagerFactory<ImmutableList<AbstractEditOperation<AbstractPersesToken>>>,
  // The single whole-reduction start event, created once by AbstractMain and shared by every driver;
  // this driver reuses it for its fixpoint-iteration messages rather than creating its own.
  private val reductionStartEvent: ReductionStartEvent,
  executorService: TestScriptExecutorService,
) : AbstractReductionDriver<
    ImmutableList<AbstractEditOperation<AbstractPersesToken>>,
    ListDiffReductionIOManager,
  >(
    globalContent,
    ioManagerList,
    executorService,
    hideTimestampsInLog = cmd.verbosityFlags.hideTimestamps,
  ) {
  override fun reduce() {
    printStartTime()

    val reductionState =
      ListDiffReductionState(diff) {
        ioManager.saveBestProgram(outputManagerFactory.createManagerFor(it))
      }

    val reducers = createReducers()
    for (reducer in reducers) {
      val fixpointIterationStartEvent =
        reductionStartEvent.nextFixpointIteration(
          perFileSizeMetrics = diffSizeMetrics(reductionState.bestDiff.size),
          reducerClass = reducer.nameAndDesc,
          treeStructureDumper = { listToString(reductionState.bestDiff) },
          testScriptStatistics = executorService.statistics.createSnapshot(),
          // The current diff is what this driver reduces; carry it as per-iteration context so it is
          // reported even though the whole-reduction start/end events (fired once by AbstractMain) no
          // longer carry this ppr-specific extraData.
          extraData = listToString(reductionState.bestDiff),
        )
      listenerManager.onFixpointIterationStart(fixpointIterationStartEvent)
      try {
        // Layer-2 sanity check: the current best diff is the reducer's input representation; verify
        // the program it reconstructs still passes the test before the reducer runs.
        checkRepresentationPreservesPropertyOrThrow(
          outputManagerFactory.createManagerFor(reductionState.bestDiff),
          reducer.nameAndDesc.shortName,
        )
        reducer.reduce(reductionState)
      } catch (e: Exception) {
        listenerManager.onCriticalException(e)
      }
      val fixpointIterationEndEvent =
        fixpointIterationStartEvent.createEndEvent(
          currentTimeMillis = System.currentTimeMillis(),
          perFileSizeMetrics = diffSizeMetrics(reductionState.bestDiff.size),
          testScriptStatistics = executorService.statistics.createSnapshot(),
        )
      listenerManager.onFixpointIterationEnd(fixpointIterationEndEvent)
    }
  }

  // PPR reduces a diff, not a set of files, so there is no genuine per-file program size. To
  // satisfy the event API, attribute the diff size to the seed slot (and zero to the variant),
  // keeping the reported total equal to the diff size.
  private fun diffSizeMetrics(diffSize: Int): PerFileSizeMetrics {
    val inputs = ioManager.originalReductionInputs
    return PerFileSizeMetrics(
      inputs,
      inputs.mutableFiles
        .mapIndexed { index, _ ->
          ProgramSize(
            payload = Unit,
            canonicalTokenCount = if (index == 0) diffSize else 0,
            surrogateTokenCount = if (index == 0) diffSize else 0,
            totalCharacterCount = 0,
            nonBlankCharacterCount = 0,
          )
        }.toImmutableList(),
    )
  }

  private fun createReducers(): ImmutableList<AbstractListDiffReducer> {
    val builder =
      ImmutableList
        .builder<AbstractListDiffReducer>()
        .apply {
          if (enableDiffSlicer) {
            add(ListDiffSlicer(ioManager, executorService, outputManagerFactory))
          }
          if (enableDiffDdmin) {
            add(ListDiffDdmin(ioManager, executorService, outputManagerFactory))
          }
        }
    return builder.build()
  }

  private fun listToString(
    diffList: ImmutableList<AbstractEditOperation<AbstractPersesToken>>,
  ): String {
    val builder = StringBuilder()
    builder.append("Current diff:\n")
    for (diff in diffList) {
      builder.append("    <${diff.base?.lexemeText ?: ""}, ${diff.revision?.lexemeText ?: ""}>\n")
    }
    return builder.toString()
  }

  companion object {
    private fun createIOManager(
      workingDirectory: Path,
      reductionInputsList: DiffOriginalReductionInputs,
      resultFolder: ReductionFolder,
    ): ListDiffReductionIOManager =
      ListDiffReductionIOManager(
        workingDirectory,
        reductionInputsList,
        resultFolder = resultFolder,
      )

    private fun createOutputManagerFactory(
      reductionInputsList: DiffOriginalReductionInputs,
      reductionControlFlags: ReductionControlFlagGroup,
      program: TokenizedProgram,
      originalAlignment: ListAlignment<AbstractPersesToken>,
      originalDiff: List<AbstractEditOperation<AbstractPersesToken>>,
      lexerAtnWrapper: LexerAtnWrapper,
      shaAlgorithm: EnumShaAlgorithm,
    ): ListDiffOutputManagerFactory {
      val languageKind = reductionInputsList.seedFile.dataKind
      val programFormatControl =
        reductionControlFlags.codeFormat.let { codeFormat ->
          if (codeFormat != null) {
            check(languageKind.isCodeFormatAllowed(codeFormat)) {
              "$codeFormat is not allowed for language $languageKind"
            }
            codeFormat
          } else {
            languageKind.defaultCodeFormatControl
          }
        }
      return ListDiffOutputManagerFactory(
        reductionInputsList,
        program,
        originalAlignment,
        originalDiff,
        programFormatControl,
        lexerAtnWrapper,
        shaAlgorithm,
      )
    }

    @JvmStatic
    fun create(
      globalContent: GlobalContext,
      cmd: ListDiffCmdOptions,
      workingDirectory: Path,
      resultFolder: ReductionFolder,
      originalReductionInputs: DiffOriginalReductionInputs,
      parserFacade: AbstractParserFacade,
      listenerManager: AsyncReductionListenerManager,
      reductionStartEvent: ReductionStartEvent,
      executorService: TestScriptExecutorService,
    ): ListDiffReductionDriver {
      val languageKind = originalReductionInputs.initiallyDeterminedMainDataKind

      // get seed tokens
      val seedTree =
        createInputRepresentation(
          fileToReduce = originalReductionInputs.seedFile,
          parserFacade = parserFacade,
          hideTimeStampsInLog = cmd.verbosityFlags.hideTimestamps,
          // TODO(cnsun): need to enable semantics for PPR.
          semanticsProviderCreator = null,
          enableNodeActionSetCache = cmd.cacheControlFlags.nodeActionSetCaching,
          originalReductionInputs = originalReductionInputs,
        )
      val seedProgram = seedTree.tree.programSnapshot
      val seedPersesToken = seedProgram.payload.tokens

      // get variant tokens
      val variantTokens = parserFacade.tokenizeFile(cmd.listDiffInputFlags.variantFile!!)
      val variantPersesTokens =
        TokenizedProgram
          .createForFreshAntlrLexemes(variantTokens)
          .tokens

      val listAlignment =
        ListAlignment.create(
          seedPersesToken,
          variantPersesTokens,
          PPRDiffUtils.EQUALIZER_PERSES_TOKEN,
        )
      val listAlignmentWithReplace = ListAlignment.mergeIntoReplace(listAlignment)

      // extract insert and replace from listAlignment as the original diff
      val insertAndReplace = ImmutableList.builder<AbstractEditOperation<AbstractPersesToken>>()
      for (op in listAlignmentWithReplace.alignment) {
        if (op is AbstractEditOperation.Insert || op is AbstractEditOperation.Replace) {
          insertAndReplace.add(op)
        }
      }
      val originalDiff = insertAndReplace.build()

      val ioManager =
        createIOManager(
          workingDirectory = workingDirectory,
          reductionInputsList = originalReductionInputs,
          resultFolder = resultFolder,
        )
      // pass listAlignment to the renderer factory
      val outputManagerFactory =
        createOutputManagerFactory(
          reductionInputsList = originalReductionInputs,
          reductionControlFlags = cmd.reductionControlFlags,
          program = seedProgram.payload,
          originalAlignment = listAlignmentWithReplace,
          originalDiff = originalDiff,
          lexerAtnWrapper = parserFacade.lexerAtnWrapper,
          shaAlgorithm = cmd.cacheControlFlags.defaultShaAlgorithm,
        )

      return ListDiffReductionDriver(
        globalContent,
        cmd,
        ioManager,
        originalDiff,
        cmd.listDiffInputFlags.enableDiffDdmin,
        cmd.listDiffInputFlags.enableDiffSlicer,
        listenerManager,
        outputManagerFactory,
        reductionStartEvent,
        executorService,
      )
    }
  }
}
