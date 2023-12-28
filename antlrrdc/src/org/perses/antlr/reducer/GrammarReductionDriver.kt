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
package org.perses.antlr.reducer

import com.google.common.collect.ImmutableList
import com.google.common.flogger.FluentLogger
import org.perses.antlr.ast.PersesAstBuilder
import org.perses.antlr.ast.PersesGrammar
import org.perses.antlr.reducer.io.GrammarOutputManagerFactory
import org.perses.antlr.reducer.io.GrammarReductionIOManager
import org.perses.antlr.reducer.io.SeparateGrammarReductionInput
import org.perses.antlr.reducer.pass.AbstractAntlrReducer
import org.perses.antlr.reducer.pass.ActionsReducer
import org.perses.antlr.reducer.pass.ArgumentsReducer
import org.perses.antlr.reducer.pass.LocalsReducer
import org.perses.antlr.reducer.pass.ReturnsReducer
import org.perses.antlr.reducer.pass.RuleElementLabelReducer
import org.perses.antlr.reducer.setup.Setup
import org.perses.program.LanguageKind
import org.perses.program.SourceFile
import org.perses.reduction.AbstractReductionDriver
import org.perses.reduction.ListenableReductionState
import org.perses.util.Util
import org.perses.util.ktInfo
import java.nio.file.Path
import java.nio.file.Paths

class GrammarReductionDriver private constructor(
  ioManager: GrammarReductionIOManager,
  numberOfThreads: Int,
  val enableActionReducer: Boolean,
  val enableLocalsReducer: Boolean,
  val enableReturnsReducer: Boolean,
  val enableArgumentsReducer: Boolean,
  val enableLabelReducer: Boolean,
) : AbstractReductionDriver<PersesGrammar, LanguageKind, GrammarReductionIOManager>(
  ioManager,
  numberOfThreads,
  scriptExecutionTimeoutInSeconds = 300L,
  keepWaitingAfterScriptTimeout = true,
) {

  val originalProgram = PersesAstBuilder.loadGrammarFromString(
    ioManager.getConcreteReductionInputs().parserFile.textualFileContent,
  )

  override fun reduce() {
    printStartTime()

    ioManager.backupMainFile()

    sanityCheck(originalProgram)
    val reductionState = ListenableReductionState(originalProgram) {
      ioManager.updateBestResult(it)
    }
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

  private fun createReducers(): ImmutableList<AbstractAntlrReducer> {
    val builder = ImmutableList.builder<AbstractAntlrReducer>()
      .apply {
        if (enableActionReducer) {
          add(ActionsReducer(ioManager, executorService))
        }
        if (enableLocalsReducer) {
          add(LocalsReducer(ioManager, executorService))
        }
        if (enableReturnsReducer) {
          add(ReturnsReducer(ioManager, executorService))
        }
        if (enableArgumentsReducer) {
          add(ArgumentsReducer(ioManager, executorService))
        }
        if (enableLabelReducer) {
          add(RuleElementLabelReducer(ioManager, executorService))
        }
      }
    return builder.build()
  }

  companion object {
    fun createIOManager(
      setup: Setup,
      outputDir: Path,
      testPrograms: ImmutableList<Path>,
    ): GrammarReductionIOManager {
      val parserFile = SourceFile(
        setup.parserFile,
        LanguageAntlr,
      )
      val lexerFile = setup.lexerFile

      val reductionInputs = SeparateGrammarReductionInput(
        testScript = setup.testScript,
        parserFile = parserFile,
        lexerFile = SourceFile(lexerFile, LanguageAntlr),
      )
      return GrammarReductionIOManager(
        workingDir = setup.workingDir,
        reductionInputs = reductionInputs,
        outputManagerFactory = GrammarOutputManagerFactory(
          reductionInputs,
          startRuleName = setup.startRuleName,
          jarFileName = setup.jarFile.path.fileName.toString(),
          testPrograms = testPrograms,
        ),
        outputDirectory = outputDir,
      )
    }

    @JvmStatic
    fun create(
      options: CommandOptions,
    ): GrammarReductionDriver {
      val parentWorkingDir = Paths.get(".").toAbsolutePath()

      val setup = Setup(
        parentWorkingDir,
        parserGrammarPath = options.compulsoryFlags.parserGrammarPath!!,
        lexerGrammarPath = options.compulsoryFlags.lexerGrammarPath!!,
        startRuleName = options.compulsoryFlags.startRuleName,
        testPrograms = Util.globWithFileNameExts(
          options.compulsoryFlags.corpus!!,
          ext = options.compulsoryFlags.fileExtName,
        ),
      )
      val outputDir = options.resultOutputFlags.outputDir!!
      val ioManager = createIOManager(setup, outputDir, setup.parseableTestPrograms)

      return GrammarReductionDriver(
        ioManager,
        options.reductionControlFlags.getNumOfThreads(),
        enableActionReducer = options.reductionControlFlags.enableActionRemover,
        enableArgumentsReducer = options.reductionControlFlags.enableArgumentsRemover,
        enableLabelReducer = options.reductionControlFlags.enableLabelRemover,
        enableLocalsReducer = options.reductionControlFlags.enableLocalsRemover,
        enableReturnsReducer = options.reductionControlFlags.enableReturnsRemover,
      )
    }

    val logger = FluentLogger.forEnclosingClass()
  }
}
