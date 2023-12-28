/*
 * Copyright (C) 2018-2024 University of Waterloo.
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
import org.perses.grammar.AbstractParserFacadeFactory
import org.perses.ppr.diff.PPRDiffUtils
import org.perses.program.LanguageKind
import org.perses.program.PersesTokenFactory.PersesToken
import org.perses.program.ScriptFile
import org.perses.program.SourceFile
import org.perses.program.TokenizedProgram
import org.perses.program.TokenizedProgramFactory
import org.perses.reduction.AbstractProgramReductionDriver.Companion.createSparTree
import org.perses.reduction.AbstractReductionDriver
import org.perses.util.AbstractEditOperation
import org.perses.util.ListAlignment
import org.perses.util.ktInfo
import java.nio.file.Path

class ListDiffReductionDriver private constructor(
  cmd: ListDiffCmdOptions,
  ioManagerList: ListDiffReductionIOManager,
  val diff: ImmutableList<AbstractEditOperation<PersesToken>>,
  private val enableDiffDdmin: Boolean,
  private val enableDiffSlicer: Boolean,
) : AbstractReductionDriver<
  ImmutableList<AbstractEditOperation<PersesToken>>,
  LanguageKind,
  ListDiffReductionIOManager,
  >(
  ioManagerList,
  cmd.reductionControlFlags.getNumOfThreads(),
  cmd.profilingFlags.testScriptExecutionTimeoutInSeconds,
  cmd.profilingFlags.testScriptExecutionKeepWaitingAfterTimeout,
) {

  private val progressMonitor = cmd.profilingFlags.progressDumpFile?.let {
    registerToClose(ProgressMonitor(it, cmd.profilingFlags.appendToProgressDumpFile))
  }

  override fun reduce() {
    printStartTime()
    sanityCheck(diff)

    val reductionState = ListDiffReductionState(diff) {
      ioManager.updateBestResult(it)
    }

    val reducers = createReducers()
    progressMonitor?.onReductionStart(reductionState.bestDiff)
    for (reducer in reducers) {
      logger.ktInfo { "About to run the reducer ${reducer.javaClass.simpleName}" }
      reducer.reduce(reductionState)
      logger.ktInfo { "Finished the reducer ${reducer.javaClass.simpleName}" }
      progressMonitor?.onReducerEnd(reducer.javaClass.simpleName, reductionState.bestDiff)
    }
    progressMonitor?.onReductionEnd(reductionState.bestDiff)
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

  companion object {
    private val logger = FluentLogger.forEnclosingClass()

    fun createReductionInputs(
      parserFacadeFactory: AbstractParserFacadeFactory,
      inputFlags: ListDiffCmdOptions.ListDiffInputFlagGroup,
    ): ListDiffReductionInputs {
      val absoluteSeedFilePath: Path = inputFlags.getSourceFile().toAbsolutePath()
      val absoluteVariantFilePath: Path = inputFlags.getVariantFile()
      val languageKind = parserFacadeFactory.computeLanguageKindOrThrow(absoluteSeedFilePath)
      val seedFile = SourceFile(absoluteSeedFilePath, languageKind)
      val variantFile = SourceFile(absoluteVariantFilePath, languageKind)
      val testScript = ScriptFile(inputFlags.getTestScript().toAbsolutePath())

      require(seedFile.parentFile.toAbsolutePath() == testScript.parentFile.toAbsolutePath()) {
        "The seed file and the test script should reside in the same folder. " +
          "seedFile:$seedFile, testScript:$testScript"
      }
      return ListDiffReductionInputs(
        testScript = testScript,
        seedFile = seedFile,
        variantFile = variantFile,
      )
    }

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
      parserFacadeFactory: AbstractParserFacadeFactory,
    ): ListDiffReductionDriver {
      val reductionInputs = createReductionInputs(
        parserFacadeFactory,
        cmd.listDiffInputFlags,
      )

      val languageKind = reductionInputs.seedFile.dataKind
      val parserFacade = parserFacadeFactory.createParserFacade(languageKind)

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
      )
    }
  }
}
