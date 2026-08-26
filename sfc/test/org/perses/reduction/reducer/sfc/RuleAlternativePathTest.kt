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
import org.perses.grammar.AbstractParserFacade
import org.perses.reduction.reducer.sfc.SfcTestUtility.ruleNamed

@RunWith(JUnit4::class)
class RuleAlternativePathTest : AbstractSfcTestWithGeneratedFacade() {
  private val facade: AbstractParserFacade by lazy {
    createFacade(
      grammarName = "AlternativePath",
      // `late` is declared before `early`, but `stmt` spells `early` at its first alternative
      // and `late` at its last: the two orders disagree, which is the case that matters.
      parserRules =
        """
        start : stmt EOF ;
        stmt : early | middle | late ;
        late : 'late' ID ;
        early : 'early' ID ;
        middle : 'middle' ID ;
        """.trimIndent(),
    )
  }

  private val paths: RuleAlternativePath by lazy { RuleAlternativePath(facade.ruleHierarchy) }

  private fun pathFrom(
    fromRuleName: String,
    toRuleName: String,
  ): List<Int>? =
    paths.findSmallestPath(facade.ruleNamed(fromRuleName), facade.ruleNamed(toRuleName))

  @Test
  fun aRuleReachesItselfByTheEmptyPath() {
    assertThat(pathFrom("stmt", "stmt")).isEmpty()
  }

  @Test
  fun thePathIsTheIndexOfTheAlternativeThatSpellsTheRule() {
    assertThat(pathFrom("stmt", "early")).containsExactly(0)
    assertThat(pathFrom("stmt", "middle")).containsExactly(1)
    assertThat(pathFrom("stmt", "late")).containsExactly(2)
  }

  @Test
  fun theOrderOfAlternativesIsNotTheOrderRulesAreDeclaredIn() {
    // `late` is declared before `early`, yet it is spelled by a later alternative, so it is the
    // less canonical of the two. A comparison by declaration order would say the opposite.
    val ruleList = facade.ruleHierarchy.ruleList
    assertThat(ruleList.indexOf(facade.ruleNamed("late")))
      .isLessThan(ruleList.indexOf(facade.ruleNamed("early")))

    assertThat(
      RuleAlternativePath.LEXICOGRAPHIC_ORDER.compare(
        pathFrom("stmt", "early")!!,
        pathFrom("stmt", "late")!!,
      ),
    ).isLessThan(0)
  }

  @Test
  fun thereIsNoPathToARuleTheGrammarCannotDeriveOnItsOwn() {
    assertThat(pathFrom("early", "late")).isNull()
  }

  @Test
  fun aPrefixComesBeforeTheLongerPathItStarts() {
    assertThat(RuleAlternativePath.LEXICOGRAPHIC_ORDER.compare(listOf(1), listOf(1, 0)))
      .isLessThan(0)
    assertThat(RuleAlternativePath.LEXICOGRAPHIC_ORDER.compare(listOf(0, 9), listOf(1)))
      .isLessThan(0)
  }
}
