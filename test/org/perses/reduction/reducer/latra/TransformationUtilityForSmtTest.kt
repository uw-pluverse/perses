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
package org.perses.reduction.reducer.latra

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.grammar.AbstractParserFacade
import org.perses.grammar.smtlibv2.SmtLibV2ParserFacade
import org.perses.program.TokenizedProgramFactory
import org.perses.spartree.SparTreeNodeFactory

@RunWith(JUnit4::class)
class TransformationUtilityForSmtTest {
  private val smtParserFacade: AbstractParserFacade = SmtLibV2ParserFacade()
  private val tokenFactory =
    TokenizedProgramFactory.createEmptyFactory(
      smtParserFacade.language,
    )
  private val smtHierarchy = smtParserFacade.ruleHierarchy
  private val smtTreeNodeFactory =
    SparTreeNodeFactory(
      smtParserFacade.metaTokenInfoDb,
      tokenFactory,
      smtHierarchy,
    )
  private val smtPrinter = IProgramPrinter.create(smtParserFacade)
  val parsingRelatedArguments =
    LatraArguments(
      smtParserFacade,
      smtTreeNodeFactory,
      smtPrinter,
      prefixLabelFromRootToHere = "[test]",
    )
  private val subroot =
    TransformationUtility.createNodeFromString(
      "( + a b v )",
      "term",
      parsingRelatedArguments,
    )

  @Test
  fun testCreateNodeFromString() {
    val text = parsingRelatedArguments.createStringFromNodes(listOf(subroot))
    assertThat(text.trim()).isEqualTo("( + a b v )")
  }

  @Test
  fun testCreateStringFromNode() {
    val tree =
      TestUtility.createSparTreeFromString(
        "( assert ( + a b v ) )",
        smtParserFacade,
        simplifyTree = true,
        sparTreeNodeFactory = parsingRelatedArguments.sparTreeNodeFactory,
      )
    val text = parsingRelatedArguments.createStringFromNodes(listOf(tree.realRoot))
    assertThat(text.trim()).isEqualTo("( assert ( + a b v ) )")
  }

  @Test
  fun testFindLexerRuleNodesInSubtree() {
    val nodeALocation = TransformationUtility.findLexerRuleNodesInSubtree(subroot, "a")
    assertThat(nodeALocation.size).isEqualTo(1)
  }
}
