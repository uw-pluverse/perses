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
package org.perses.spartree

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.antlr.ast.PersesParserRuleAst
import org.perses.fuzzer.languagemodel.NDepthTreeModel
import org.perses.grammar.AbstractParserFacade
import org.perses.grammar.c.PnfCParserFacade
import java.nio.file.Files
import java.nio.file.Paths
import java.util.Random

@RunWith(JUnit4::class)
class SparTreeGeneratorTest {
  private val workingDir = Files.createTempDirectory(javaClass.simpleName)
  private val cParserFacade = PnfCParserFacade()

  private fun testRandomGeneration(
    parserFacade: AbstractParserFacade,
    expectedSuccessTimes: Int,
    expectedFailedTimes: Int,
  ) {
    var successTimes = 0
    var failedTimes = 0
    val randomGenerator = RandomSparTreeGenerator(
      parserFacade,
      Random(2),
    )
    val languageModel = NDepthTreeModel(
      contextSizeLimit = 5,
      parserFacade,
      allowToEnableGuidance = true,
    )
    val guidedGenerator = GuidedSparTreeGenerator(
      parserFacade,
      Random(2),
      languageModel,
    )
    val rules =
      parserFacade.antlrGrammar.getCombinedRules().filterIsInstance<PersesParserRuleAst>()
    for (element in rules) {
      val ruleToStart = element.ruleNameHandle
      // Following code should not fail
      val tree1 = randomGenerator.generateParserRuleSparTreeNode(ruleToStart)
      val tree2 = guidedGenerator.generateParserRuleSparTreeNode(ruleToStart)
      // When language model has not leaned anything,
      // guidedGenerator should be equivalent to randomGenerator
      if (tree1 == null) {
        assertThat(tree2).isNull()
        ++failedTimes
      } else {
        assertThat(tree1.printTreeStructure()).isEqualTo(tree2!!.printTreeStructure())
        assertThat(tree1.childCount > 0)
        ++successTimes
      }
    }
    assertThat(Pair(successTimes, failedTimes)).isEqualTo(
      Pair(expectedSuccessTimes, expectedFailedTimes),
    )
  }

  @Test
  fun testRandomGenerationWithC() {
    val parserFacade = TestUtility.generateAdhocFacade(
      Paths.get("kitten/test/fuzzer_test_data/grammar_for_testing/OrigC.g4"),
      startRule = "compilationUnit",
      tokenNamesOfIdentifiers = listOf("Identifier"),
      workingDir = workingDir,
      enablePnfNormalization = true,
    )
    testRandomGeneration(
      parserFacade,
      expectedSuccessTimes = 229,
      expectedFailedTimes = 44,
    )
  }

  @Test
  fun testStringLiteralInC() {
    val random = Random(0)
    val generator = RandomSparTreeGenerator(parserFacade = cParserFacade, random)
    val persesToken = generator.generatePersesToken(
      cParserFacade.ruleHierarchy.getRuleHierarchyEntryOrNull("StringLiteral")!!
        .ruleDef.body,
    )
    assertThat(persesToken.type).isEqualTo(
      cParserFacade.lexerAtnWrapper.metaTokenInfoDB
        .getTokenInfoWithName("StringLiteral")!!.tokenType,
    )
  }

  @Test
  fun testRandomGenerationWithRust() {
    val parserFacade = TestUtility.generateAdhocFacade(
      Paths.get("kitten/test/fuzzer_test_data/grammar_for_testing/Rust.g4"),
      startRule = "crate",
      tokenNamesOfIdentifiers = listOf("Ident"),
      workingDir = workingDir,
      enablePnfNormalization = true,
    )
    testRandomGeneration(
      parserFacade,
      expectedSuccessTimes = 589,
      expectedFailedTimes = 122,
    )
  }
}
