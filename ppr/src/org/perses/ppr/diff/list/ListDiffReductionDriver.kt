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
package org.perses.ppr.diff.list

import com.google.common.collect.ImmutableList
import org.perses.antlr.atn.LexerAtnWrapper
import org.perses.cmd.OutputFlagGroup
import org.perses.cmd.ReductionControlFlagGroup
import org.perses.grammar.AbstractParserFacade
import org.perses.ppr.diff.PPRDiffUtils
import org.perses.program.LanguageKind
import org.perses.program.PersesTokenFactory.AbstractPersesToken
import org.perses.program.TokenizedProgram
import org.perses.program.TokenizedProgramFactory
import org.perses.reduction.AbstractProgramReductionDriver.Companion.createSparTree
import org.perses.reduction.AbstractReductionDriver
import org.perses.reduction.AsyncReductionListenerManager
import org.perses.reduction.GlobalContext
import org.perses.reduction.createSnapshot
import org.perses.reduction.event.ReductionStartEvent
import org.perses.util.AbstractEditOperation
import org.perses.util.ListAlignment
import org.perses.util.Serialization
import org.perses.util.hashing.EnumShaAlgorithm
import java.lang.StringBuilder
import java.lang.ref.WeakReference

class ListDiffReductionDriver private constructor(
  globalContent: GlobalContext,
  private val cmd: ListDiffCmdOptions,
  ioManagerList: ListDiffReductionIOManager,
  val diff: ImmutableList<AbstractEditOperation<AbstractPersesToken>>,
  private val enableDiffDdmin: Boolean,
  private val enableDiffSlicer: Boolean,
  private val listenerManager: AsyncReductionListenerManager,
) : AbstractReductionDriver<
    ImmutableList<AbstractEditOperation<AbstractPersesToken>>,
    LanguageKind,
    ListDiffReductionIOManager,
  >(
    globalContent,
    ioManagerList,
    cmd.reductionControlFlags.getNumOfThreads(),
    cmd.reductionControlFlags.testScriptExecutionTimeoutInSeconds,
    cmd.reductionControlFlags.testScriptExecutionKeepWaitingAfterTimeout,
    hideTimestampsInLog = cmd.verbosityFlags.hideTimestamps,
  ) {
  override fun getInitialProgram(): ImmutableList<AbstractEditOperation<AbstractPersesToken>> = diff

  override fun reduce() {
    printStartTime()
    sanityCheckOrThrow(diff)

    val reductionState =
      ListDiffReductionState(diff) {
        ioManager.updateBestResult(it)
      }

    val reducers = createReducers()
    val reductionStartEvent =
      ReductionStartEvent(
        currentTimeMillis = System.currentTimeMillis(),
        tree = WeakReference(null),
        programSize = reductionState.bestDiff.size,
        commandLineOptions =
          Serialization.toYamlString(
            value = cmd,
            objectMapperCustomizer = Serialization::customizeObjectMapperByUsingBasenameForPath,
          ),
        extraData = listToString(reductionState.bestDiff),
      )
    listenerManager.onReductionStart(reductionStartEvent)
    for (reducer in reducers) {
      val fixpointIterationStartEvent =
        reductionStartEvent.nextFixpointIteration(
          programSize = reductionState.bestDiff.size,
          reducerClass = reducer.nameAndDesc,
          treeStructureDumper = { listToString(reductionState.bestDiff) },
          testScriptStatistics = executorService.statistics.createSnapshot(),
        )
      listenerManager.onFixpointIterationStart(fixpointIterationStartEvent)
      reducer.reduce(reductionState)
      val fixpointIterationEndEvent =
        fixpointIterationStartEvent.createEndEvent(
          currentTimeMillis = System.currentTimeMillis(),
          programSize = reductionState.bestDiff.size,
          testScriptStatistics = executorService.statistics.createSnapshot(),
        )
      listenerManager.onFixpointIterationEnd(fixpointIterationEndEvent)
    }
    val reductionEndEvent =
      reductionStartEvent.createEndEvent(
        programSize = reductionState.bestDiff.size,
        testScriptStatistics = executorService.statistics.createSnapshot(),
        extraData = listToString(reductionState.bestDiff),
      )
    listenerManager.onReductionEnd(reductionEndEvent)
  }

  private fun createReducers(): ImmutableList<AbstractListDiffReducer> {
    val builder =
      ImmutableList
        .builder<AbstractListDiffReducer>()
        .apply {
          if (enableDiffSlicer) {
            add(ListDiffSlicer(ioManager, executorService))
          }
          if (enableDiffDdmin) {
            add(ListDiffDdmin(ioManager, executorService))
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
      reductionInputsList: ListDiffReductionInputs,
      reductionControlFlags: ReductionControlFlagGroup,
      outputFlags: OutputFlagGroup,
      program: TokenizedProgram,
      originalAlignment: ListAlignment<AbstractPersesToken>,
      originalDiff: List<AbstractEditOperation<AbstractPersesToken>>,
      lexerAtnWrapper: LexerAtnWrapper,
      shaAlgorithm: EnumShaAlgorithm,
    ): ListDiffReductionIOManager {
      val workingDirectory = reductionInputsList.seedFile.parentFile
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
      return ListDiffReductionIOManager(
        workingDirectory,
        reductionInputsList,
        outputManagerFactory =
          ListDiffOutputManagerFactory(
            reductionInputsList,
            program,
            originalAlignment,
            originalDiff,
            programFormatControl,
            lexerAtnWrapper,
            shaAlgorithm,
          ),
        outputDirectory = outputFlags.outputDir,
      )
    }

    @JvmStatic
    fun create(
      globalContent: GlobalContext,
      cmd: ListDiffCmdOptions,
      reductionInputs: ListDiffReductionInputs,
      parserFacade: AbstractParserFacade,
      listenerManager: AsyncReductionListenerManager,
    ): ListDiffReductionDriver {
      val languageKind = reductionInputs.initiallyDeterminedMainDataKind

      // get seed tokens
      val seedTree =
        createSparTree(
          fileToReduce = reductionInputs.seedFile,
          parserFacade = parserFacade,
          hideTimeStampsInLog = cmd.verbosityFlags.hideTimestamps,
        )
      val seedProgram = seedTree.programSnapshot
      val seedPersesToken = seedProgram.tokens

      // get variant tokens
      val variantTokens = parserFacade.tokenizeFile(cmd.listDiffInputFlags.getVariantFile())
      val variantTokenizedProgramFactory =
        TokenizedProgramFactory
          .createFactory(variantTokens, languageKind)
      val variantPersesTokens = variantTokenizedProgramFactory.create(variantTokens).tokens

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

      // pass listAlignment to IOManager
      val ioManager =
        createIOManager(
          reductionInputs,
          cmd.reductionControlFlags,
          cmd.resultOutputFlags,
          seedProgram,
          listAlignmentWithReplace,
          originalDiff,
          parserFacade.lexerAtnWrapper,
          cmd.cacheControlFlags.defaultShaAlgorithm,
        )

      return ListDiffReductionDriver(
        globalContent,
        cmd,
        ioManager,
        originalDiff,
        cmd.listDiffInputFlags.enableDiffDdmin,
        cmd.listDiffInputFlags.enableDiffSlicer,
        listenerManager,
      )
    }
  }
}
