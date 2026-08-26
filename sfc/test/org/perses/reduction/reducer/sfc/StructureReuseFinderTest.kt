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
import org.perses.grammar.c.PnfCParserFacade
import org.perses.reduction.reducer.sfc.SfcTestUtility.findNodeSpelling
import org.perses.reduction.reducer.sfc.SfcTestUtility.ruleNamed
import org.perses.reduction.reducer.sfc.SfcTestUtility.spelling
import org.perses.spartree.AbstractSparTreeNode

@RunWith(JUnit4::class)
class StructureReuseFinderTest {
  private val facade = PnfCParserFacade()

  private fun expressionNode(
    sourceCode: String,
    lexemes: String,
  ): AbstractSparTreeNode =
    TestUtility
      .createSparTreeFromString(sourceCode, facade, simplifyTree = true)
      .findNodeSpelling(lexemes)

  private fun reusesOf(
    subtree: AbstractSparTreeNode,
    symbolName: String,
    reusabilityPredicate: (AbstractSparTreeNode) -> Boolean = { true },
  ): List<String> =
    StructureReuseFinder
      .findHighestReusableSubtreesUnder(subtree, facade.ruleNamed(symbolName), reusabilityPredicate)
      .map { it.spelling }

  @Test
  fun onlyTheHighestLevelStructuresAreReused() {
    val subtree = expressionNode("int f(int a, int b) { return f(a) && b; }", "f ( a ) && b")

    // `a` is inside `f ( a )` and is never offered on its own.
    assertThat(reusesOf(subtree, "expression")).containsAtLeast("f ( a )", "b")
    assertThat(reusesOf(subtree, "expression")).doesNotContain("a")
  }

  @Test
  fun theSearchDescendsThroughNodesSpanningTheWholeSubtree() {
    val subtree = expressionNode("int f(int a, int b) { return a && b; }", "a && b")

    // Perses trees chain one node per rule (expression -> ... -> postfixExpression), so the top
    // of such a chain spans the whole subtree; it must not hide the structures below it.
    assertThat(reusesOf(subtree, "expression")).containsAtLeast("a", "b")
  }

  @Test
  fun incompatibleSymbolsHaveNoReuse() {
    val subtree = expressionNode("int f(int a, int b) { return a && b; }", "a && b")

    assertThat(reusesOf(subtree, "compoundStatement")).isEmpty()
  }

  @Test
  fun predicateExcludesStructures() {
    val subtree = expressionNode("int f(int a, int b) { return a && b; }", "a && b")

    val reuses =
      reusesOf(subtree, "expression") { node ->
        !node.tokenListCostlyComputed.contains("b")
      }
    assertThat(reuses).contains("a")
    reuses.forEach { assertThat(it).doesNotContain("b") }
  }

  private fun firstReusableDescendantOf(
    subtree: AbstractSparTreeNode,
    symbolName: String,
    reusabilityPredicate: (AbstractSparTreeNode) -> Boolean = { true },
  ): String? =
    StructureReuseFinder
      .findFirstReusableDescendantOf(
        subtree,
        facade.ruleNamed(symbolName),
        reusabilityPredicate,
      )?.spelling

  @Test
  fun aReusedSubtreeShrinksToAStructureInsideIt() {
    val subtree = expressionNode("int f(int a, int b) { return f(a) && b; }", "f ( a ) && b")

    // The subtree itself is the highest reuse for `expression`, and shrinking it means taking a
    // structure strictly inside it, which spells strictly fewer tokens.
    val descendant = firstReusableDescendantOf(subtree, "expression")
    assertThat(descendant).isNotNull()
    assertThat(descendant).isNotEqualTo("f ( a ) && b")
    assertThat(subtree.spelling).contains(descendant!!)
  }

  @Test
  fun aStructureWithNothingSmallerInsideItDoesNotShrink() {
    val subtree = expressionNode("int f(int a, int b) { return a && b; }", "a && b")
    val identifier = expressionNode("int f(int a, int b) { return a && b; }", "a")

    assertThat(firstReusableDescendantOf(identifier, "expression")).isNull()
    // The predicate is asked about the descendants too, so a veto on all of them shrinks nothing.
    assertThat(firstReusableDescendantOf(subtree, "expression") { false }).isNull()
  }

  @Test
  fun aSubtreeOverlapsItselfAndTheSubtreesReachableFromIt() {
    val subtree = expressionNode("int f(int a, int b) { return f(a) && b; }", "f ( a ) && b")
    val reuses =
      StructureReuseFinder.findHighestReusableSubtreesUnder(
        subtree,
        facade.ruleHierarchy.getRuleHierarchyEntryWithNameOrThrow("expression"),
        { true },
      )

    fun nodeOf(source: String) =
      reuses.first { it.tokenListCostlyComputed.joinToString(" ") == source }

    val whole = nodeOf("f ( a ) && b")
    val call = nodeOf("f ( a )")
    val operand = nodeOf("b")

    assertThat(StructureReuseFinder.doSubtreesOverlap(call, operand)).isFalse()
    assertThat(StructureReuseFinder.doSubtreesOverlap(whole, call)).isTrue()
    assertThat(StructureReuseFinder.doSubtreesOverlap(call, call)).isTrue()
  }
}
