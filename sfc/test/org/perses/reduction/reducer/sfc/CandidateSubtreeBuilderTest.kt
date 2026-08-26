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
package org.perses.reduction.reducer.sfc

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.grammar.AbstractParserFacade
import org.perses.reduction.reducer.sfc.SfcTestUtility.findNodeSpelling
import org.perses.reduction.reducer.sfc.SfcTestUtility.spelling
import org.perses.reduction.reducer.sfc.SfcTestUtility.templatesOfRule
import org.perses.spartree.AbstractSparTreeNode

@RunWith(JUnit4::class)
class CandidateSubtreeBuilderTest : AbstractSfcTestWithGeneratedFacade() {
  private val facade: AbstractParserFacade by lazy {
    createFacade(
      grammarName = "CandidateSubtree",
      parserRules =
        """
        start : expr EOF ;
        expr : '!' expr | pair | list | nothing | ID ;
        pair : '<' expr ',' expr '>' ;
        list : '(' expr expr ')' ;
        nothing : '(' ')' ;
        """.trimIndent(),
    )
  }

  /** The subtree built from the one filling of [ruleNameOfAlternative], spelled out. */
  private fun buildCandidate(
    sourceCode: String,
    lexemesOfSubtreeToConvert: String,
    ruleNameOfAlternative: String,
    alternativeIndex: Int = 0,
  ): AbstractSparTreeNode {
    val tree = TestUtility.createSparTreeFromString(sourceCode, facade, simplifyTree = true)
    val subtreeRootToConvert = tree.findNodeSpelling(lexemesOfSubtreeToConvert)
    val template =
      facade
        .templatesOfRule(ruleNameOfAlternative)
        .first { it.alternativeIndex == alternativeIndex }
    val filling =
      TemplateHoleFiller
        .findEveryFillingOfHoles(template, subtreeRootToConvert) { true }
        .first()
    return checkNotNull(
      CandidateSubtreeBuilder(facade, tree.sparTreeNodeFactory)
        .build(template, filling, positionOfConvertedSubtree = null),
    )
  }

  @Test
  fun theConstantsOfTheAlternativeAreSpelledAroundTheReusedSubtrees() {
    assertThat(
      buildCandidate(
        sourceCode = "<a,b>",
        lexemesOfSubtreeToConvert = "< a , b >",
        ruleNameOfAlternative = "pair",
      ).spelling,
    ).isEqualTo("< a , b >")
  }

  @Test
  fun anAlternativeOfConstantsOnlySpellsItself() {
    assertThat(
      buildCandidate(
        sourceCode = "<a,b>",
        lexemesOfSubtreeToConvert = "< a , b >",
        ruleNameOfAlternative = "nothing",
      ).spelling,
    ).isEqualTo("( )")
  }

  @Test
  fun theBuiltSubtreeIsAWellFormedTreeOfItsOwn() {
    val candidate =
      buildCandidate(
        sourceCode = "<a,b>",
        lexemesOfSubtreeToConvert = "< a , b >",
        ruleNameOfAlternative = "pair",
      )

    assertThat(candidate.parent).isNull()
    assertThat(candidate.checkLeafLinkIntegrity()).isNull()
    assertThat(candidate.leafTokenCount).isEqualTo(candidate.tokenListCostlyComputed.size)
  }

  @Test
  fun theReusedSubtreesAreCopiedSoThatTheConvertedTreeIsUntouched() {
    val tree = TestUtility.createSparTreeFromString("<a,b>", facade, simplifyTree = true)
    val subtreeRootToConvert = tree.findNodeSpelling("< a , b >")
    val template = facade.templatesOfRule("pair").first()
    val filling =
      TemplateHoleFiller
        .findEveryFillingOfHoles(template, subtreeRootToConvert) { true }
        .first()
    val reusedSubtreeRoots = filling.filledHoles.flatMap { it.subtreesToCopy }

    val candidate =
      checkNotNull(
        CandidateSubtreeBuilder(facade, tree.sparTreeNodeFactory)
          .build(template, filling, positionOfConvertedSubtree = null),
      )

    reusedSubtreeRoots.forEach { reused ->
      assertThat(reused.parent).isNotNull()
      candidate.preOrderVisit { node ->
        assertThat(node).isNotSameInstanceAs(reused)
        node.immutableChildView
      }
    }
  }

  @Test
  fun aCandidateCanBeParsedBackAsTheRuleItWasBuiltFor() {
    val candidate =
      buildCandidate(
        sourceCode = "<a,b>",
        lexemesOfSubtreeToConvert = "< a , b >",
        ruleNameOfAlternative = "expr",
        alternativeIndex = 0,
      )

    assertThat(facade.isSourceCodeParsable(candidate.spelling)).isTrue()
  }
}
