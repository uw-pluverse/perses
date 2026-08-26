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

@RunWith(JUnit4::class)
class TemplateHoleFillerTest : AbstractSfcTestWithGeneratedFacade() {
  private val facade: AbstractParserFacade by lazy {
    createFacade(
      grammarName = "Filler",
      parserRules =
        """
        start : expr EOF ;
        expr : '!' expr | pair | list | nothing | ID ;
        nothing : '(' ')' ;
        pair : '<' expr ',' expr '>' ;
        list : '(' expr expr ')' ;
        """.trimIndent(),
    )
  }

  /**
   * Every way the holes of one alternative can be filled, one string per filling: the subtrees
   * of one hole are joined by " + " and the holes of one filling by " | ", so that a filling of
   * two holes reads "a | b" and a filling of one hole taking both subtrees reads "a + b".
   */
  private fun renderEveryFilling(
    sourceCode: String,
    lexemesOfSubtreeToConvert: String,
    ruleNameOfAlternative: String,
    alternativeIndex: Int = 0,
  ): List<String> {
    val tree = TestUtility.createSparTreeFromString(sourceCode, facade, simplifyTree = true)
    val subtreeRootToConvert = tree.findNodeSpelling(lexemesOfSubtreeToConvert)
    val template =
      facade
        .templatesOfRule(ruleNameOfAlternative)
        .first { it.alternativeIndex == alternativeIndex }
    return TemplateHoleFiller
      .findEveryFillingOfHoles(template, subtreeRootToConvert) { true }
      .map { filling ->
        filling.filledHoles.joinToString(separator = " | ") { filledHole ->
          filledHole.joinToString(separator = " + ") { it.spelling }
        }
      }.toList()
  }

  @Test
  fun oneHoleIsFilledWithEachReusableSubtreeInTurn() {
    // `expr : '!' expr` has one hole. Besides `a` and `b`, the node spanning the whole converted
    // subtree is offered as well: a Perses tree chains one node per rule, so the node below the
    // converted one spans the same tokens, and the finder keeps it (see
    // StructureReuseFinder.findHighestReusableSubtreesUnder).
    assertThat(
      renderEveryFilling(
        sourceCode = "<a,b>",
        lexemesOfSubtreeToConvert = "< a , b >",
        ruleNameOfAlternative = "expr",
        alternativeIndex = 0,
      ),
    ).containsExactly("< a , b >", "a", "b")
      .inOrder()
  }

  @Test
  fun holesOfOneSymbolAreFilledWithDistinctSubtreesInOrder() {
    // `pair : '<' expr ',' expr '>'` has two holes of one symbol, so the two reusable subtrees
    // are distributed over them, each used once and in the order they are spelled (Principle 3).
    assertThat(
      renderEveryFilling(
        sourceCode = "<a,b>",
        lexemesOfSubtreeToConvert = "< a , b >",
        ruleNameOfAlternative = "pair",
      ),
    ).containsExactly("a | b")
  }

  @Test
  fun thereIsNoFillingWhenTheReusableSubtreesDoNotSufficeForTheHoles() {
    // `pair : '<' expr ',' expr '>'` needs two subtrees, but `a` offers none.
    assertThat(
      renderEveryFilling(
        sourceCode = "a",
        lexemesOfSubtreeToConvert = "a",
        ruleNameOfAlternative = "pair",
      ),
    ).isEmpty()
  }

  @Test
  fun aSubtreeAndTheSubtreesUnderItAreNeverFilledInTogether() {
    // `list : '(' expr expr ')'` has two holes, and `! a` offers the same-span node and `a`,
    // which overlap. No filling uses both, so there is no filling at all.
    assertThat(
      renderEveryFilling(
        sourceCode = "!a",
        lexemesOfSubtreeToConvert = "! a",
        ruleNameOfAlternative = "list",
      ),
    ).isEmpty()
    // With one hole, each of the two is used on its own.
    assertThat(
      renderEveryFilling(
        sourceCode = "!a",
        lexemesOfSubtreeToConvert = "! a",
        ruleNameOfAlternative = "expr",
        alternativeIndex = 0,
      ),
    ).containsExactly("! a", "a")
      .inOrder()
  }

  @Test
  fun anAlternativeWithoutHolesHasExactlyOneFillingThatFillsNothing() {
    // `nothing : '(' ')'` spells itself, so there is nothing to fill and nothing to choose. This
    // is why an empty list of hole groups is not the same as an unusable template: it yields one
    // filling, not none.
    assertThat(
      renderEveryFilling(
        sourceCode = "!a",
        lexemesOfSubtreeToConvert = "! a",
        ruleNameOfAlternative = "nothing",
      ),
    ).containsExactly("")
  }
}
