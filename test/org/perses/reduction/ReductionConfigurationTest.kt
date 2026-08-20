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
package org.perses.reduction

import com.google.common.collect.ImmutableList
import com.google.common.io.MoreFiles
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.grammar.SingleParserFacadeFactory
import org.perses.grammar.c.LanguageC
import org.perses.listminimizer.EnumListMinimizerType
import org.perses.program.ScriptFile
import org.perses.program.SourceFile
import org.perses.reduction.io.AbstractReductionIOManager
import org.perses.reduction.io.DefaultLanguageOriginalReductionInputs
import org.perses.reduction.io.token.TokenReductionIOManager
import org.perses.reduction.reducer.EnumMimirReductionAlgorithm
import org.perses.reduction.reducer.PersesNodeReducerAnnotations
import org.perses.util.Util
import org.perses.util.hashing.EnumShaAlgorithm
import java.nio.charset.StandardCharsets
import java.nio.file.Files
import java.nio.file.Paths
import kotlin.io.path.ExperimentalPathApi
import kotlin.io.path.deleteRecursively

/** Test for [ReductionConfiguration]  */
@RunWith(JUnit4::class)
class ReductionConfigurationTest {
  private val hashAlgorithm = EnumShaAlgorithm.SHA256
  private val testScript = ScriptFile(Paths.get(FOLDER, "r.sh"))
  private val workingDirectory =
    TestUtility.createCleanWorkingDirectory(ReductionConfigurationTest::class.java)
  private val sourceFile = SourceFile(Paths.get(FOLDER, "t.c"), LanguageC)
  private val outputDir =
    workingDirectory.resolve("perses_output_dir").apply {
      Util.ensureDirExists(this)
    }
  private val originalReductionInputs =
    DefaultLanguageOriginalReductionInputs(
      testScript = testScript,
      mutableFiles = ImmutableList.of(sourceFile),
      immutableDependencyFiles = ImmutableList.of(),
    )

  @OptIn(ExperimentalPathApi::class)
  @After
  fun teardown() {
    workingDirectory.deleteRecursively()
  }

  @Test
  fun testConfiguration() {
    assertThat(Files.isDirectory(workingDirectory)).isTrue()
    val numOfReductionThreads = 2
    val ioManager =
      TokenReductionIOManager(
        workingDirectory,
        originalReductionInputs,
        resultFolder =
          AbstractReductionIOManager.createPopulatedResultFolder(
            originalReductionInputs,
            hashAlgorithm,
            outputDir,
          ),
      )
    val languageKind = ioManager.originalReductionInputs.initiallyDeterminedMainDataKind
    val parserFacade =
      SingleParserFacadeFactory
        .builderWithBuiltinLanguages()
        .build()
        .getParserFacadeListForOrNull(languageKind)!!
        .defaultParserFacade
        .create()
    val configuration =
      ReductionConfiguration(
        globalFixpoint = false,
        mainReducerAnnotation = PersesNodeReducerAnnotations.PrioritizedDfs,
        cleanupReducerAnnotation = PersesNodeReducerAnnotations.Dfs,
        fixpointReductionForMainReducer = true,
        enableDeprecatedQueryCaching = true,
        fullyDeterministicMode = false,
        numOfReductionThreads = numOfReductionThreads,
        canonicalParserFacade = parserFacade,
        persesConfig =
          ReductionConfiguration.PersesConfig(
            enableTopDownReduction = true,
            enableReducingRegularRuleNode = true,
            enableReducingKleeneOptionalNode = true,
            maxEditCountForRegularRuleNode = 100,
            maxBfsDepthForRegularRuleNode = 5,
            stopAtFirstCompatibleChildren = true,
            enableLiteralReplacementForListMinimizer = false,
            enableLiteralReplacementForRegularRuleNode = false,
            listMinimizerTypeForKleene = EnumListMinimizerType.DFS,
            anticipatedFinalTokenCount = 20,
          ),
        listMinimizerConfig =
          ReductionConfiguration.ListMinimizerConfig(
            minSlidingWindowSize = 1,
            maxSlidingWindowSize = 5,
          ),
        vulcanConfig =
          ReductionConfiguration.VulcanConfig(
            nonDeletionIterationLimit = 10,
            windowSizeForLocalExhaustivePatternReduction = 4,
            vulcanFixpoint = false,
          ),
        lprConfig =
          ReductionConfiguration.LPRConfig(
            llmClientPath = null,
            lprFixpoint = false,
          ),
        latraConfig =
          ReductionConfiguration.LatraConfig(
            listMinimizerForTransformations = EnumListMinimizerType.WPROBDD,
          ),
        levelBasedReducerConfig =
          ReductionConfiguration.LevelBasedReducerConfig(
            defaultListMinimizerType = EnumListMinimizerType.CDD,
          ),
        mimirConfig =
          ReductionConfiguration.MimirConfig(
            semanticsProviderCreator = null,
            nodeCountThresholdToUseOneByOne = 10,
            enableBottomUpReductionAfterMainReductionLoop = true,
            bottomUpReductionMaxDepth = 5,
            mimirReductionAlgorithm = EnumMimirReductionAlgorithm.LAYER_BY_LAYER_TOP_DOWN,
            enableMimirForRegularRuleNodes = true,
            deleteDefWithAllItsConcreteUses = false,
          ),
        shaHashAlgorithm = EnumShaAlgorithm.SHA256,
      )
    val mainFile = ioManager.originalReductionInputs.mutableFiles.single() as SourceFile
    assertThat(mainFile.file).isEqualTo(sourceFile.file)
    assertThat(mainFile.textualFileContent)
      .isEqualTo(MoreFiles.asCharSource(sourceFile.file, StandardCharsets.UTF_8).read())
    assertThat(configuration.numOfReductionThreads).isEqualTo(numOfReductionThreads)
    assertThat(configuration.fixpointReductionForMainReducer).isTrue()
  }

  companion object {
    private const val FOLDER = "test_data/delta_1/"
  }
}
