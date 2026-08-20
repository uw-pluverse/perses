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
import com.google.common.truth.Truth.assertThat
import org.junit.Assert.assertThrows
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.grammar.c.LanguageC
import org.perses.spartree.AbstractSparTreeNode
import org.perses.util.toImmutableList

@RunWith(JUnit4::class)
class NodeContainerForListMinimizerTest {
  @Test
  fun testConstructorWithValidNodes() {
    val tree = TestUtility.createSparTreeFromString("int x = 1;", LanguageC)
    val nodes = ImmutableList.of(tree.realRoot)
    val container = NodeContainerForListMinimizer(nodes)
    assertThat(container.nodes).isEqualTo(nodes)
  }

  @Test
  fun testConstructorWithEmptyNodes() {
    assertThrows(IllegalArgumentException::class.java) {
      NodeContainerForListMinimizer(ImmutableList.of())
    }
  }

  @Test
  fun testTokenCount() {
    val tree = TestUtility.createSparTreeFromString("int x = 1;", LanguageC)
    // "int", "x", "=", "1", ";" -> 5 tokens
    val container = NodeContainerForListMinimizer.of(tree.realRoot)
    assertThat(container.tokenCount).isEqualTo(5)
  }

  @Test
  fun testOfMethod() {
    val tree = TestUtility.createSparTreeFromString("int x = 1;", LanguageC)
    val container = NodeContainerForListMinimizer.of(tree.realRoot)
    assertThat(container.nodes).hasSize(1)
    assertThat(container.nodes[0]).isEqualTo(tree.realRoot)
  }

  @Test
  fun testToStringSingleParserNode() {
    val tree = TestUtility.createSparTreeFromString("int x = 1;", LanguageC)
    val container = NodeContainerForListMinimizer.of(tree.realRoot)
    val toString = container.toString()
    assertThat(toString).startsWith("parser(")
    assertThat(toString).contains("#tokens=5")
    assertThat(toString).contains("last-pos=1:9") // ";" at end of "int x = 1;"
  }

  @Test
  fun testToStringMultipleNodes() {
    val tree = TestUtility.createSparTreeFromString("int x = 1;", LanguageC)
    // Root has multiple children
    var node: AbstractSparTreeNode? = null
    tree.realRoot.preOrderVisit {
      if (it.childCount > 1) {
        node = it
        emptyList()
      } else {
        it.immutableChildView
      }
    }
    checkNotNull(node)
    val container = NodeContainerForListMinimizer(node.immutableChildView.toImmutableList())
    val toString = container.toString()
    // Verify prefixing like "0.parser(...)", "1.parser(...)" etc.
    assertThat(toString).startsWith("0.")
    assertThat(toString).contains(", 1.")
  }

  @Test
  fun testToStringLexerNode() {
    val tree = TestUtility.createSparTreeFromString("int x = 1;", LanguageC)
    // Find a lexer node (token)
    val lexerNodes = tree.realRoot.leafNodeSequence().toImmutableList()
    NodeContainerForListMinimizer.of(lexerNodes.first()).let { container ->
      val toString = container.toString()
      assertThat(toString).startsWith("lexer(")
      assertThat(toString).contains("pos=1:0") // "int" starts at 1:0
    }
    NodeContainerForListMinimizer(lexerNodes).let { container ->
      val toString = container.toString()
      assertThat(toString).startsWith("0.lexer")
      assertThat(toString).contains(", 1.lexer")
    }
  }

  @Test
  fun testTokenCountWithPermanentlyDeletedNodes() {
    val tree = TestUtility.createSparTreeFromString("int x = 1;", LanguageC)
    val lexerNodes = tree.realRoot.leafNodeSequence().toImmutableList()
    // "int", "x", "=", "1", ";" -> 5 tokens
    val container = NodeContainerForListMinimizer(lexerNodes)
    assertThat(container.tokenCount).isEqualTo(5)

    // Delete "int" (index 0)
    lexerNodes[0].delete()
    assertThat(container.tokenCount).isEqualTo(4)

    // Delete "x" (index 1)
    lexerNodes[1].delete()
    assertThat(container.tokenCount).isEqualTo(3)

    // Delete remaining nodes
    lexerNodes[2].delete()
    lexerNodes[3].delete()
    lexerNodes[4].delete()
    assertThat(container.tokenCount).isEqualTo(0)
  }
}
