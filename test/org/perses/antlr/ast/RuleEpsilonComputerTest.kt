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
package org.perses.antlr.ast

import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableSet
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.antlr.GrammarTestingUtility.createPersesGrammarFromString
import org.perses.util.toImmutableList

@RunWith(JUnit4::class)
class RuleEpsilonComputerTest {
  @Test
  fun testSimple() {
    var ruleNames = getEpsilonableRuleNames("a : D | ;")
    assertThat(ruleNames).containsExactly("a")
    ruleNames = getEpsilonableRuleNames("a : D;")
    assertThat(ruleNames).isEmpty()
  }

  @Test
  fun testStar() {
    val ruleNames = getEpsilonableRuleNames("a : D*;")
    assertThat(ruleNames).containsExactly("a")
  }

  @Test
  fun testOptional() {
    val ruleNames = getEpsilonableRuleNames("a : D?;")
    assertThat(ruleNames).containsExactly("a")
  }

  @Test
  fun testPlus() {
    val ruleNames = getEpsilonableRuleNames("a : D+;")
    assertThat(ruleNames).isEmpty()
  }

  @Test
  fun testRuleref() {
    assertThat(getEpsilonableRuleNames("a: b;", "b:;")).containsExactly("a", "b")
  }

  @Test
  fun testCyclicRuleref() {
    assertThat(getEpsilonableRuleNames("a:b;", "b:a;")).isEmpty()
  }

  @Test
  fun testSequence() {
    assertThat(getEpsilonableRuleNames("a: b c ;", "b : A* ;", "c: A? ;"))
      .containsExactly("a", "b", "c")
    assertThat(
      getEpsilonableRuleNames("a: b c ;", "b : A* ;", "c: A+ ;"),
    ).containsExactly("b")
  }

  @Test
  fun testPlusWithQuantifiedEpsilon() {
    assertThat(getEpsilonableRuleNames("a : b +;", "b : ;")).containsExactly("a", "b")
  }

  @Test
  fun testAlt() {
    assertThat(getEpsilonableRuleNames("a : D | E;")).isEmpty()
    assertThat(
      getEpsilonableRuleNames("a : b | E ;", "b : C | ;"),
    ).containsExactly("a", "b")
  }

  private fun getEpsilonableRuleNames(vararg lines: String): ImmutableList<String> {
    val grammar = createPersesGrammarFromString(*lines)
    val rules: ImmutableSet<AbstractPersesRuleDefAst> = RuleEpsilonComputer.computeEpsilonableRules(
      grammar.flattenedAllRules,
    ).epsilonableRules
    return rules.asSequence().map { it.ruleNameHandle.ruleName }.toImmutableList()
  }
}
