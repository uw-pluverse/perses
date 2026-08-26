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
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.SparTree

/** The worked examples of Sec. 4.1 of the paper, on the real C grammar. */
@RunWith(JUnit4::class)
class StructureFormConverterCTest {
  private val facade = PnfCParserFacade()

  private fun parse(source: String): SparTree =
    TestUtility.createSparTreeFromString(source, facade, simplifyTree = true)

  private fun candidates(
    tree: SparTree,
    source: String,
  ): List<String> =
    StructureFormConverter(facade, tree.sparTreeNodeFactory)
      .convert(findNode(tree, source))
      .map { it.lexemes.joinToString(" ") }
      .toList()

  private fun smallerCandidates(
    tree: SparTree,
    source: String,
  ): List<String> {
    val node = findNode(tree, source)
    return StructureFormConverter(facade, tree.sparTreeNodeFactory)
      .convert(node)
      .filter { it.leafTokenCount < node.leafTokenCount }
      .map { it.lexemes.joinToString(" ") }
      .toList()
  }

  private fun shrunkSmallerCandidates(
    tree: SparTree,
    source: String,
  ): List<String> {
    val node = findNode(tree, source)
    return StructureFormConverter(facade, tree.sparTreeNodeFactory)
      .convert(node, shrinkOversizedCandidates = true)
      .filter { it.leafTokenCount < node.leafTokenCount }
      .map { it.lexemes.joinToString(" ") }
      .toList()
  }

  private fun findNode(
    tree: SparTree,
    source: String,
  ): AbstractSparTreeNode {
    var result: AbstractSparTreeNode? = null
    tree.realRoot.preOrderVisit { node ->
      if (result == null && node.tokenListCostlyComputed.joinToString(" ") == source) {
        result = node
      }
      node.immutableChildView
    }
    return result!!
  }

  @Test
  fun logicalAnd() {
    val tree = parse("int f(int a, int b) { return a && b; }")
    assertThat(smallerCandidates(tree, "a && b")).containsAtLeast("! a", "- a", "a", "b")
    assertThat(candidates(tree, "a && b")).containsAtLeast("a [ b ]", "a . b", "a * b")
  }

  @Test
  fun memberAccess() {
    val tree = parse("struct s { int b; } a; int f() { return a.b; }")
    assertThat(smallerCandidates(tree, "a . b")).containsAtLeast("& a", "a")
  }

  @Test
  fun functionCall() {
    val tree = parse("int f(int a, int b) { return f(a, b); }")
    // `f ( a )` is not among them: C parses the argument list as one comma expression, and only
    // the highest-level compatible structures are reused (Principle 4).
    assertThat(smallerCandidates(tree, "f ( a , b )")).containsAtLeast("-- a", "f ( )", "f . a")
  }

  @Test
  fun shrinkingAReuseRecoversTheDroppedArgument() {
    val tree = parse("int f(int a, int b) { return f(a, b); }")

    // Reusing the whole argument list spells `f ( a , b )` again, which is no smaller. Shrinking
    // that reuse to a structure inside it is what turns the alternative into a real candidate --
    // the `f(e1,e2) => f(e1)` of Section 4.1 of the paper.
    assertThat(smallerCandidates(tree, "f ( a , b )")).doesNotContain("f ( a )")
    assertThat(shrunkSmallerCandidates(tree, "f ( a , b )")).contains("f ( a )")
  }

  @Test
  fun ifStatement() {
    val tree = parse("int f(int a, int b) { if (a = b); }")
    assertThat(smallerCandidates(tree, "if ( a = b ) ;")).contains("a = b ;")
  }

  @Test
  fun forStatement() {
    val tree = parse("int f(int a) { for (; a; a++); }")
    assertThat(
      smallerCandidates(tree, "for ( ; a ; a ++ ) ;"),
    ).containsAtLeast("while ( a ++ ) ;", "while ( a ) ;")
  }
}
