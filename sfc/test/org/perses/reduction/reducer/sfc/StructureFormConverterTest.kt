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
import org.perses.reduction.reducer.sfc.SfcTestUtility.spelling
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.SparTree

@RunWith(JUnit4::class)
class StructureFormConverterTest : AbstractSfcTestWithGeneratedFacade() {
  private val pnfFacade: AbstractParserFacade by lazy { createToyFacade("ToyPnf", true) }

  private val originalFacade: AbstractParserFacade by lazy { createToyFacade("ToyOrig", false) }

  private var facadeChosenByTest: AbstractParserFacade? = null

  /** The facade the tests parse with; one test switches it to the grammar as written. */
  private val facade: AbstractParserFacade
    get() = facadeChosenByTest ?: pnfFacade

  private fun createToyFacade(
    grammarName: String,
    enablePnfNormalization: Boolean,
  ) = createFacade(
    grammarName = grammarName,
    parserRules =
      """
      start : stmt+ EOF ;
      stmt : expr ';' | 'if' '(' expr ')' stmt | 'while' '(' expr ')' stmt ;
      expr : unary ('&&' unary)* | '~' unary ('&&' unary)* ;
      unary : '!' unary | postfix ;
      postfix : primary ('[' expr ']')* ;
      primary : ID | ID '(' expr ')' | '(' expr ')' ;
      """.trimIndent(),
    enablePnfNormalization = enablePnfNormalization,
  )

  private fun parse(source: String): SparTree =
    TestUtility.createSparTreeFromString(source, facade, simplifyTree = true)

  /** The topmost node of [expectedRule] whose subtree spells [lexemes]. */
  private fun findNode(
    tree: SparTree,
    expectedRule: String,
    lexemes: String,
  ): AbstractSparTreeNode {
    var result: AbstractSparTreeNode? = null
    tree.realRoot.preOrderVisit { node ->
      if (result == null &&
        node.payload?.expectedAntlrRuleType?.ruleName == expectedRule &&
        node.spelling == lexemes
      ) {
        result = node
      }
      node.immutableChildView
    }
    return checkNotNull(result) { "No $expectedRule node spells '$lexemes'." }
  }

  private fun candidatesOf(
    tree: SparTree,
    node: AbstractSparTreeNode,
    isReuseAllowed: (subtreeRoot: AbstractSparTreeNode) -> Boolean = { true },
  ): List<String> =
    StructureFormConverter(facade, tree.sparTreeNodeFactory)
      .convert(node, isReuseAllowed)
      .map { it.lexemes.joinToString(" ") }
      .toList()

  @Test
  fun expressionIsRebuiltFromOtherProductions() {
    val tree = parse("a && b;")
    val expression = findNode(tree, "expr", "a && b")
    val candidates = candidatesOf(tree, expression)
    assertThat(candidates).containsAtLeast("! a", "! b", "a [ b ]", "a ( b )", "( a )", "a", "b")
    assertThat(candidates).doesNotContain("a && b")
    assertThat(candidates).containsNoDuplicates()
  }

  @Test
  fun candidatesAreWellFormedTrees() {
    val tree = parse("a && b;")
    val expression = findNode(tree, "expr", "a && b")
    val converter = StructureFormConverter(facade, tree.sparTreeNodeFactory)
    converter.convert(expression).forEach { candidate ->
      assertThat(candidate.tree.leafTokenCount).isEqualTo(candidate.lexemes.size)
      assertThat(candidate.tree.checkLeafLinkIntegrity()).isNull()
      assertThat(candidate.tree.parent).isNull()
      assertThat(facade.isSourceCodeParsable(candidate.lexemes.joinToString(" ") + ";")).isTrue()
    }
  }

  @Test
  fun predicateExcludesStructures() {
    val tree = parse("a && b;")
    val expression = findNode(tree, "expr", "a && b")
    val candidates =
      candidatesOf(
        tree,
        expression,
      ) { node -> !node.tokenListCostlyComputed.contains("b") }
    assertThat(candidates).containsAtLeast("! a", "( a )")
    candidates.forEach { assertThat(it).doesNotContain("b") }
  }

  @Test
  fun statementIsRebuiltFromOtherProductions() {
    val tree = parse("if (a) b;")
    val statement = findNode(tree, "stmt", "if ( a ) b ;")
    val candidates = candidatesOf(tree, statement)
    assertThat(candidates).containsAtLeast("while ( a ) b ;", "a ;", "b ;")
    // Reused structures keep their original order (Principle 3).
    assertThat(candidates).doesNotContain("if ( b ) a ;")
  }

  @Test
  fun starReusesAllHighestLevelStructures() {
    val tree = parse("f(a) && g(b) && c;")
    val expression = findNode(tree, "expr", "f ( a ) && g ( b ) && c")
    val candidates = candidatesOf(tree, expression)
    assertThat(candidates)
      .containsAtLeast("~ f ( a ) && g ( b ) && c", "c && g ( b )", "! f ( a )", "f ( a ) [ c ]")
    // Only the highest-level structures are reused: `a` is hidden by `f ( a )`.
    assertThat(candidates).doesNotContain("a && g ( b ) && c")
  }

  @Test
  fun reusedStructuresAreIndependent() {
    val tree = parse("a[b];")
    val expression = findNode(tree, "expr", "a [ b ]")
    val candidates = candidatesOf(tree, expression)
    assertThat(candidates).containsAtLeast("a && b", "b [ a ]")
    assertThat(candidates).doesNotContain("a [ a ]")
    assertThat(candidates).doesNotContain("a [ b ] && b")
  }

  @Test
  fun tokenNodesHaveNoAlternatives() {
    val tree = parse("a;")
    val token = tree.getTokenNodeForText("a").single()
    assertThat(candidatesOf(tree, token)).isEmpty()
  }

  @Test
  fun worksWithoutPnfNormalization() {
    facadeChosenByTest = originalFacade
    val tree = parse("a && b;")
    val expression = findNode(tree, "expr", "a && b")
    val candidates = candidatesOf(tree, expression)
    assertThat(candidates).containsAtLeast("! a", "a [ b ]", "( a )")
    assertThat(candidates).doesNotContain("a && b")
  }

  @Test
  fun candidatesShareNoNodeWithTheConvertedTreeNorWithEachOther() {
    val tree = parse("a && b;")
    val expression = findNode(tree, "expr", "a && b")
    val nodesOfTheConvertedTree = nodesUnder(tree.realRoot)

    val candidates =
      StructureFormConverter(facade, tree.sparTreeNodeFactory)
        .convert(expression)
        .take(10)
        .toList()

    // A candidate is only a proposal until the property test accepts it, so it must not hold a
    // node of the tree being reduced, nor a node another candidate holds: a spar-tree edit is
    // keyed by node identity, and applying one edit would then disturb the others.
    val nodesSeenInCandidates = HashSet<AbstractSparTreeNode>()
    assertThat(candidates).isNotEmpty()
    candidates.forEach { candidate ->
      nodesUnder(candidate.tree).forEach { node ->
        assertThat(nodesOfTheConvertedTree).doesNotContain(node)
        assertThat(nodesSeenInCandidates.add(node)).isTrue()
      }
    }
  }

  @Test
  fun aCandidateGetsNodeIdsOfItsOwn() {
    val tree = parse("a && b;")
    val expression = findNode(tree, "expr", "a && b")
    val nodeIdsOfTheConvertedTree = nodesUnder(tree.realRoot).map { it.nodeId }.toSet()

    val candidate =
      StructureFormConverter(facade, tree.sparTreeNodeFactory).convert(expression).first()

    nodesUnder(candidate.tree).forEach {
      assertThat(nodeIdsOfTheConvertedTree).doesNotContain(it.nodeId)
    }
  }

  private fun nodesUnder(root: AbstractSparTreeNode): List<AbstractSparTreeNode> {
    val result = ArrayList<AbstractSparTreeNode>()
    root.preOrderVisit { node ->
      result.add(node)
      node.immutableChildView
    }
    return result
  }
}
