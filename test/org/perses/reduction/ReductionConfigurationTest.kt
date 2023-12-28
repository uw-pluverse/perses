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
package org.perses.reduction

import com.google.common.io.MoreFiles
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.antlr.atn.LexerAtnWrapper
import org.perses.delta.EnumDeltaDebuggerType
import org.perses.grammar.SingleParserFacadeFactory
import org.perses.grammar.c.LanguageC
import org.perses.grammar.c.PnfCLexer
import org.perses.program.EnumFormatControl.ORIG_FORMAT
import org.perses.program.ScriptFile
import org.perses.program.SourceFile
import org.perses.reduction.io.RegularReductionInputs
import org.perses.reduction.io.token.RegularOutputManagerFactory
import org.perses.reduction.io.token.TokenReductionIOManager
import java.nio.charset.StandardCharsets
import java.nio.file.Files
import java.nio.file.Paths
import kotlin.io.path.deleteRecursively

/** Test for [ReductionConfiguration]  */
@RunWith(JUnit4::class)
class ReductionConfigurationTest {
  private val testScript = ScriptFile(Paths.get(FOLDER, "r.sh"))
  private val workingDirectory =
    TestUtility.createCleanWorkingDirectory(ReductionConfigurationTest::class.java)
  private val sourceFile = SourceFile(Paths.get(FOLDER, "t.c"), LanguageC)
  private val outputDir = workingDirectory.resolve("perses_output_dir")
  private val lexerAtnWrapper = LexerAtnWrapper(PnfCLexer::class.java)
  private val reductionInputs = RegularReductionInputs(
    testScript = testScript,
    mainFile = sourceFile,
  )

  @After
  fun teardown() {
    workingDirectory.deleteRecursively()
  }

  @Test
  fun testConfiguration() {
    assertThat(Files.isDirectory(workingDirectory)).isTrue()
    val numOfReductionThreads = 2
    val ioManager = TokenReductionIOManager(
      workingDirectory,
      reductionInputs,
      outputManagerFactory = RegularOutputManagerFactory(
        reductionInputs,
        ORIG_FORMAT,
        lexerAtnWrapper,
      ),
      outputDirectory = outputDir,
    )
    val languageKind = ioManager.reductionInputs.mainDataKind
    val parserFacade = SingleParserFacadeFactory
      .builderWithBuiltinLanguages().build().createParserFacade(languageKind)
    val configuration = ReductionConfiguration(
      statisticsFile = null,
      progressDumpFile = null,
      fixpointReduction = true,
      enableTestScriptExecutionCaching = true,
      defaultDeltaDebuggerTypeForKleene = EnumDeltaDebuggerType.DFS,
      numOfReductionThreads = numOfReductionThreads,
      parserFacade = parserFacade,
      persesNodeReducerConfig = ReductionConfiguration.PersesNodeReducerConfiguration(
        maxEditCountForRegularRuleNode = 100,
        maxBfsDepthForRegularRuleNode = 5,
        stopAtFirstCompatibleChildren = true,
      ),
      vulcanConfig = ReductionConfiguration.VulcanConfig(
        nonDeletionIterationLimit = 10,
        windowSizeForLocalExhaustivePatternReduction = 4,
        vulcanFixpoint = false,
      ),
    )
    val mainFile = (ioManager.reductionInputs as RegularReductionInputs).mainFile
    assertThat(mainFile.file).isEqualTo(sourceFile.file)
    assertThat(mainFile.textualFileContent)
      .isEqualTo(MoreFiles.asCharSource(sourceFile.file, StandardCharsets.UTF_8).read())
    assertThat(configuration.numOfReductionThreads).isEqualTo(numOfReductionThreads)
    val profileFile = ioManager.getProfileFile()
    assertThat(profileFile.parent.toRealPath()).isEqualTo(workingDirectory.toRealPath())
    run {
      val tempRootFolder = ioManager.tempRootFolder
      assertThat(tempRootFolder.parent).isEqualTo(workingDirectory)
      assertThat(tempRootFolder.fileName.toString()).startsWith("PersesTempRoot_t.c_r.sh_")
    }
    assertThat(configuration.fixpointReduction).isTrue()
  }

  companion object {
    private const val FOLDER = "test_data/delta_1/"
  }
}
