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
import com.google.common.flogger.FluentLogger
import org.antlr.v4.runtime.Lexer
import org.perses.antlr.atn.LexerAtnWrapper
import org.perses.cmd.OutputFlagGroup
import org.perses.cmd.ReductionControlFlagGroup
import org.perses.grammar.AbstractParserFacade
import org.perses.ppr.diff.PPRDiffUtils
import org.perses.program.LanguageKind
import org.perses.program.PersesTokenFactory.PersesToken
import org.perses.program.TokenizedProgram
import org.perses.program.TokenizedProgramFactory
import org.perses.reduction.AbstractProgramReductionDriver.Companion.createSparTree
import org.perses.reduction.AbstractReductionDriver
import org.perses.reduction.AsyncReductionListenerManager
import org.perses.reduction.createSnapshot
import org.perses.reduction.event.ReductionStartEvent
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.AbstractUnmodifiableSparTree
import org.perses.util.AbstractEditOperation
import org.perses.util.ListAlignment
import org.perses.util.YamlUtil
import java.lang.StringBuilder
import java.lang.ref.WeakReference

class ListDiffReductionDriver private constructor(
  private val cmd: ListDiffCmdOptions,
  ioManagerList: ListDiffReductionIOManager,
  val diff: ImmutableList<AbstractEditOperation<PersesToken>>,
  private val enableDiffDdmin: Boolean,
  private val enableDiffSlicer: Boolean,
  private val listenerManager: AsyncReductionListenerManager,
) : AbstractReductionDriver<
  ImmutableList<AbstractEditOperation<PersesToken>>,
  LanguageKind,
  ListDiffReductionIOManager,
  >(
  ioManagerList,
  cmd.reductionControlFlags.getNumOfThreads(),
  cmd.reductionControlFlags.testScriptExecutionTimeoutInSeconds,
  cmd.reductionControlFlags.testScriptExecutionKeepWaitingAfterTimeout,
) {

  override fun getInitialProgram(): ImmutableList<AbstractEditOperation<PersesToken>> {
    return diff
  }

  override fun reduce() {
    printStartTime()
    sanityCheckOrThrow(diff)

    val reductionState = ListDiffReductionState(diff) {
      ioManager.updateBestResult(it)
    }

    val reducers = createReducers()
    val reductionStartEvent = ReductionStartEvent(
      currentTimeMillis = System.currentTimeMillis(),
      tree = WeakReference(null),
      programSize = reductionState.bestDiff.size,
      commandLineOptions = YamlUtil.toYamlString(
        value = cmd,
        objectMapperCustomizer = YamlUtil::customizeObjectMapperByUsingBasenameForPath,
      ),
      extraData = listToString(reductionState.bestDiff),
    )
    listenerManager.onReductionStart(reductionStartEvent)
    for (reducer in reducers) {
      val fixpointIterationStartEvent = reductionStartEvent.nextFixpointIteration(
        programSize = reductionState.bestDiff.size,
        reducerClass = reducer.nameAndDesc,
        treeStructureDumper = { listToString(reductionState.bestDiff) },
        testScriptStatistics = executorService.statistics.createSnapshot(),
      )
      listenerManager.onFixpointIterationStart(fixpointIterationStartEvent)
      reducer.reduce(reductionState)
      val fixpointIterationEndEvent = fixpointIterationStartEvent.createEndEvent(
        currentTimeMillis = System.currentTimeMillis(),
        programSize = reductionState.bestDiff.size,
        testScriptStatistics = executorService.statistics.createSnapshot(),
      )
      listenerManager.onFixpointIterationEnd(fixpointIterationEndEvent)
    }
    val reductionEndEvent = reductionStartEvent.createEndEvent(
      programSize = reductionState.bestDiff.size,
      testScriptStatistics = executorService.statistics.createSnapshot(),
      extraData = listToString(reductionState.bestDiff),
    )
    listenerManager.onReductionEnd(reductionEndEvent)
  }

  private fun createReducers(): ImmutableList<AbstractListDiffReducer> {
    val builder = ImmutableList.builder<AbstractListDiffReducer>()
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

  private fun listToString(diffList: ImmutableList<AbstractEditOperation<PersesToken>>): String {
    val builder = StringBuilder()
    builder.append("Current diff:\n")
    for (diff in diffList) {
      builder.append("    <${diff.base?.text ?: ""}, ${diff.revision?.text ?: ""}>\n")
    }
    return builder.toString()
  }

  companion object {
    private val logger = FluentLogger.forEnclosingClass()

    private fun createIOManager(
      reductionInputsList: ListDiffReductionInputs,
      reductionControlFlags: ReductionControlFlagGroup,
      outputFlags: OutputFlagGroup,
      program: TokenizedProgram,
      originalAlignment: ListAlignment<PersesToken>,
      originalDiff: List<AbstractEditOperation<PersesToken>>,
      lexerAtnWrapper: LexerAtnWrapper<out Lexer>,
    ): ListDiffReductionIOManager {
      val workingDirectory = reductionInputsList.seedFile.parentFile
      val languageKind = reductionInputsList.seedFile.dataKind
      val programFormatControl = reductionControlFlags.codeFormat.let { codeFormat ->
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
        outputManagerFactory = ListDiffOutputManagerFactory(
          reductionInputsList,
          program,
          originalAlignment,
          originalDiff,
          programFormatControl,
          lexerAtnWrapper,
        ),
        outputDirectory = outputFlags.outputDir,
      )
    }

    @JvmStatic
    fun create(
      cmd: ListDiffCmdOptions,
      reductionInputs: ListDiffReductionInputs,
      parserFacade: AbstractParserFacade,
      listenerManager: AsyncReductionListenerManager,
    ): ListDiffReductionDriver {
      val languageKind = reductionInputs.initiallyDeterminedMainDataKind

      // get seed tokens
      val seedTree = createSparTree(
        reductionInputs.seedFile,
        parserFacade,
      )
      val seedProgram = seedTree.programSnapshot
      val seedPersesToken = seedProgram.tokens

      // get variant tokens
      val variantTokens = parserFacade.parseIntoTokens(cmd.listDiffInputFlags.getVariantFile())
      val variantTokenizedProgramFactory = TokenizedProgramFactory
        .createFactory(variantTokens, languageKind)
      val variantPersesTokens = variantTokenizedProgramFactory.create(variantTokens).tokens

      val listAlignment = ListAlignment.create(
        seedPersesToken,
        variantPersesTokens,
        PPRDiffUtils.EQUALIZER_TOKEN,
      )
      val listAlignmentWithReplace = ListAlignment.mergeIntoReplace(listAlignment)

      // extract insert and replace from listAlignment as the original diff
      val insertAndReplace = ImmutableList.builder<AbstractEditOperation<PersesToken>>()
      for (op in listAlignmentWithReplace.alignment) {
        if (op is AbstractEditOperation.Insert || op is AbstractEditOperation.Replace) {
          insertAndReplace.add(op)
        }
      }
      val originalDiff = insertAndReplace.build()

      // pass listAlignment to IOManager
      val ioManager = createIOManager(
        reductionInputs,
        cmd.reductionControlFlags,
        cmd.resultOutputFlags,
        seedProgram,
        listAlignmentWithReplace,
        originalDiff,
        parserFacade.lexerAtnWrapper,
      )

      return ListDiffReductionDriver(
        cmd,
        ioManager,
        originalDiff,
        cmd.listDiffInputFlags.enableDiffDdmin,
        cmd.listDiffInputFlags.enableDiffSlicer,
        listenerManager,
      )
    }
  }

  class ListDiffSparTree(
    private val diff: ImmutableList<AbstractEditOperation<PersesToken>>,
  ) : AbstractUnmodifiableSparTree() {
    override val programSnapshot: TokenizedProgram
      get() = TODO("Not yet implemented")
    override val root: AbstractSparTreeNode
      get() = TODO("Not yet implemented")

    override fun printTreeStructure(): String {
      TODO("Not yet implemented")
    }
  }
}
