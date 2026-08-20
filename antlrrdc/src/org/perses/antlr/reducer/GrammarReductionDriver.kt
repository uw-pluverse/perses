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
package org.perses.antlr.reducer

import com.google.common.collect.ImmutableList
import com.google.common.flogger.FluentLogger
import org.perses.antlr.ast.PersesAstBuilder
import org.perses.antlr.ast.PersesGrammar
import org.perses.antlr.reducer.io.GrammarOutputManagerFactory
import org.perses.antlr.reducer.io.GrammarReductionIOManager
import org.perses.antlr.reducer.io.SeparateGrammarOriginalReductionInput
import org.perses.antlr.reducer.pass.AbstractAntlrReducer
import org.perses.antlr.reducer.pass.ActionsReducer
import org.perses.antlr.reducer.pass.ArgumentsReducer
import org.perses.antlr.reducer.pass.LocalsReducer
import org.perses.antlr.reducer.pass.ReturnsReducer
import org.perses.antlr.reducer.pass.RuleElementLabelReducer
import org.perses.antlr.reducer.setup.Setup
import org.perses.program.SourceFile
import org.perses.reduction.AbstractReductionDriver
import org.perses.reduction.GlobalContext
import org.perses.reduction.ListenableReductionState
import org.perses.reduction.SanityCheckFailedException
import org.perses.reduction.TestScriptExecutorService
import org.perses.reduction.io.AbstractOutputManagerFactory
import org.perses.reduction.io.ReductionFolder
import org.perses.reduction.io.ReductionFolderManager
import org.perses.util.Util
import org.perses.util.hashing.EnumShaAlgorithm
import org.perses.util.ktInfo
import java.nio.file.Files
import java.nio.file.Path

class GrammarReductionDriver private constructor(
  globalContext: GlobalContext,
  ioManager: GrammarReductionIOManager,
  // The renderer (carries the code format) this driver owns, rather than the IO manager: it renders
  // the original input for the initial sanity check, hands it to the reducers, and renders each
  // accepted best grammar before saving. The grammar stack does not adapt the format, so this is fixed.
  private val outputManagerFactory: AbstractOutputManagerFactory<PersesGrammar>,
  executorService: TestScriptExecutorService,
  val enableActionReducer: Boolean,
  val enableLocalsReducer: Boolean,
  val enableReturnsReducer: Boolean,
  val enableArgumentsReducer: Boolean,
  val enableLabelReducer: Boolean,
) : AbstractReductionDriver<PersesGrammar, GrammarReductionIOManager>(
    globalContext = globalContext,
    ioManager = ioManager,
    executorService = executorService,
    hideTimestampsInLog = false,
  ) {
  init {
    // This driver is standalone (not orchestrated by AbstractMain, which would own the shared
    // executor), so it owns the executor it was built with and closes it when the driver closes.
    registerToClose(executorService)
  }

  private val originalProgram =
    PersesAstBuilder.loadGrammarFromString(
      ioManager.concreteReductionInputs.parserFile.textualFileContent,
    )

  override fun reduce() {
    printStartTime()

    sanityCheckOrThrow()

    val reductionState =
      ListenableReductionState(initialEntity = originalProgram, listenerOnUpdate = {
        ioManager.saveBestProgram(outputManagerFactory.createManagerFor(it))
      })
    // Force to write the best file.
    reductionState.updateBestProgram(reductionState.bestEntity)

    val reducers = createReducers()
    while (true) {
      val prev = reductionState.bestEntity.sourceCode
      var post = prev
      for (reducer in reducers) {
        logger.ktInfo { "About to run the reducer ${reducer.javaClass.simpleName}" }
        val reducerBefore = post
        reducer.reduce(reductionState)
        logger.ktInfo { "Finished running the reducer ${reducer.javaClass.simpleName}" }
        post = reductionState.bestEntity.sourceCode
        logger.ktInfo {
          "One iteration is done. " +
            "#chars before=${reducerBefore.length}, #chars after=${post.length}"
        }
      }
      logger.ktInfo {
        "One iteration is done. #chars before=${prev.length}, #chars after=${post.length}"
      }
      if (prev == post) {
        break
      }
    }
  }

  // The ANTLR grammar reducer does not run behind AbstractMain's Layer-1 pipeline, so it performs
  // its own initial sanity check: render the original input and verify it passes the test script.
  private fun sanityCheckOrThrow() {
    val result =
      executorService
        .testProgramAsyncWithoutPayload(
          preCheck = TestScriptExecutorService.ALWAYS_TRUE_PRECHECK,
          postCheck = TestScriptExecutorService.IDENTITY_POST_CHECK,
          outputManagerFactory.createOutputManagerForOriginalInput(),
        ).getWithTimeoutWarnings()
    if (result.isNotInteresting) {
      throw SanityCheckFailedException(
        "The initial sanity check failed: the original input does not pass the test script.",
      )
    }
  }

  private fun createReducers(): ImmutableList<AbstractAntlrReducer> {
    val builder =
      ImmutableList
        .builder<AbstractAntlrReducer>()
        .apply {
          if (enableActionReducer) {
            add(ActionsReducer(ioManager, executorService, outputManagerFactory))
          }
          if (enableLocalsReducer) {
            add(LocalsReducer(ioManager, executorService, outputManagerFactory))
          }
          if (enableReturnsReducer) {
            add(ReturnsReducer(ioManager, executorService, outputManagerFactory))
          }
          if (enableArgumentsReducer) {
            add(ArgumentsReducer(ioManager, executorService, outputManagerFactory))
          }
          if (enableLabelReducer) {
            add(RuleElementLabelReducer(ioManager, executorService, outputManagerFactory))
          }
        }
    return builder.build()
  }

  companion object {
    fun createOriginalReductionInputs(setup: Setup): SeparateGrammarOriginalReductionInput =
      SeparateGrammarOriginalReductionInput(
        testScript = setup.testScript,
        parserFile = SourceFile(setup.parserFile, LanguageAntlr),
        lexerFile = SourceFile(setup.lexerFile, LanguageAntlr),
      )

    fun createIOManager(
      setup: Setup,
      originalReductionInputs: SeparateGrammarOriginalReductionInput,
      outputDir: Path,
    ): GrammarReductionIOManager =
      GrammarReductionIOManager(
        workingDir = setup.workingDir,
        originalReductionInputs = originalReductionInputs,
        resultFolder = ReductionFolder(originalReductionInputs, outputDir),
      )

    fun createOutputManagerFactory(
      setup: Setup,
      originalReductionInputs: SeparateGrammarOriginalReductionInput,
      testPrograms: ImmutableList<Path>,
      shaAlgorithm: EnumShaAlgorithm,
    ): GrammarOutputManagerFactory =
      GrammarOutputManagerFactory(
        originalReductionInputs,
        startRuleName = setup.startRuleName,
        jarFileName =
          setup.jarFile.path.fileName
            .toString(),
        testPrograms = testPrograms,
        shaAlgorithm = shaAlgorithm,
      )

    @JvmStatic
    fun create(
      globalContext: GlobalContext,
      cmd: CommandOptions,
      workingDirectory: Path,
    ): GrammarReductionDriver {
      val setup =
        Setup(
          workingDirectory,
          parserGrammarPath = cmd.compulsoryFlags.parserGrammarPath!!,
          lexerGrammarPath = cmd.compulsoryFlags.lexerGrammarPath!!,
          startRuleName = cmd.compulsoryFlags.startRuleName,
          testPrograms =
            Util.globWithFileNameExts(
              cmd.compulsoryFlags.corpus!!,
              ext = cmd.compulsoryFlags.fileExtName,
            ),
        )
      val outputDir =
        cmd.resultOutputFlags.outputDir!!.apply {
          Util.ensureDirExists(this)
        }
      val originalReductionInputs = createOriginalReductionInputs(setup)
      // The grammar reducer also writes reduced content into the result folder without backing up the
      // inputs, so the output directory must not coincide with the grammar files.
      originalReductionInputs.checkOutputDirectoryIsNotInPlace(outputDir)
      val ioManager = createIOManager(setup, originalReductionInputs, outputDir)
      val outputManagerFactory =
        createOutputManagerFactory(
          setup,
          originalReductionInputs,
          setup.parseableTestPrograms,
          shaAlgorithm = EnumShaAlgorithm.SHA512,
        )
      // The driver owns this executor and closes it (see the driver's init); the temp root holds the
      // per-test working folders.
      val executorService =
        TestScriptExecutorService(
          reductionFolderManager =
            ReductionFolderManager(
              originalReductionInputs,
              Files.createTempDirectory(workingDirectory, "PersesTempRoot_"),
            ),
          specifiedNumOfThreads = cmd.reductionControlFlags.getNumOfThreads(),
          scriptExecutionTimeoutInSeconds = 300L,
          scriptExecutionKeepTryingAfterTimeout = true,
          globalExecutionCache = globalContext.globalExecutionCache,
        )

      return GrammarReductionDriver(
        globalContext,
        ioManager,
        outputManagerFactory,
        executorService,
        enableActionReducer = cmd.reductionControlFlags.enableActionRemover,
        enableArgumentsReducer = cmd.reductionControlFlags.enableArgumentsRemover,
        enableLabelReducer = cmd.reductionControlFlags.enableLabelRemover,
        enableLocalsReducer = cmd.reductionControlFlags.enableLocalsRemover,
        enableReturnsReducer = cmd.reductionControlFlags.enableReturnsRemover,
      )
    }

    val logger = FluentLogger.forEnclosingClass()
  }
}
