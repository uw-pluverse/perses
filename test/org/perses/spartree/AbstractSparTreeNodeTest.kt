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
import org.junit.Assert
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.grammar.c.LanguageC
import org.perses.program.TokenizedProgramFactory
import org.perses.util.MutableInt
import org.perses.util.toImmutableList

@RunWith(JUnit4::class)
class AbstractSparTreeNodeTest {
  val facade = TestUtility.getFacade(LanguageC)
  val nodeFactory =
    SparTreeNodeFactory(
      facade.metaTokenInfoDb,
      TokenizedProgramFactory.createEmptyFactory(LanguageC),
      facade.ruleHierarchy,
    )

  @Test
  fun testChildSequence() {
    val tree =
      TestUtility.createSparTreeFromString(
        "int a ; int b = a + 3 + 4 + 5;",
        LanguageC,
        simplifyTree = true,
      )
    val childrenCounter = MutableInt(0)
    tree.realRoot.postOrderVisit { node ->
      val list = mutableListOf<AbstractSparTreeNode>()
      node.forEachChild { child -> list.add(child) }
      assertThat(list).isEqualTo(node.childSequence().toList())
      childrenCounter.incrementBy(list.count())
    }
    assertThat(childrenCounter.get()).isGreaterThan(10) // Just pick a random large number.
  }

  @Test
  fun testUpdateLeafTokenCountSingleStatement() {
    val tree = TestUtility.createSparTreeFromString("int a;", LanguageC)
    tree.updateLeafTokenCount()
    assertThat(tree.realRoot.leafTokenCount).isEqualTo(3)
    val tokens = tree.getTokenNodeForText("int")
    assertThat(tokens).hasSize(1)

    val edit =
      tree.createNodeDeletionEdit(
        NodeDeletionActionSet.createByDeleteSingleNode(tokens.first(), "dummy"),
      )
    tree.applyEdit(edit)
    assertThat(tree.realRoot.leafTokenCount).isEqualTo(2)
    tree.updateLeafTokenCount()
    assertThat(tree.realRoot.leafTokenCount).isEqualTo(2)
    tree.updateLeafTokenCount()
    assertThat(tree.realRoot.leafTokenCount).isEqualTo(2)
    tree.updateLeafTokenCount()
    tree.updateLeafTokenCount()
    assertThat(tree.realRoot.leafTokenCount).isEqualTo(2)
  }

  @Test
  fun testEmptyLeafNodeSequence() {
    val node = nodeFactory.createParserRuleSparTreeNode("statement")
    node.updateLeafTokenCount()
    node.leafNodeSequence().toImmutableList().let {
      assertThat(it).isEmpty()
    }
    assertThat(node.leafTokenCount).isEqualTo(0)
  }

  @Test
  fun testNonEmptyLeafNodeSequence() {
    val token = facade.transformLiteralIntoSingleToken(";")
    val tokenNode = nodeFactory.createLexerRuleSparTreeNodeForAntlrToken(token)
    val ruleNode = nodeFactory.createParserRuleSparTreeNode("expressionStatement")
    ruleNode.addChild(
      tokenNode,
      AbstractNodePayload.SinglePayload(
        facade.ruleHierarchy.getRuleHierarchyEntryWithNameOrThrow("statement"),
      ),
    )
    val exception =
      Assert.assertThrows(Exception::class.java) {
        ruleNode.leafNodeSequence()
      }
    assertThat(exception.message).contains("leaf node links are not updated")
    ruleNode.buildTokenIntervalInfoRecursive()
    assertThat(ruleNode.leafNodeSequence().toImmutableList()).containsExactly(
      tokenNode,
    )
  }

  @Test
  fun testUpdateLeafTokenCountTwoStatements() {
    val tree = TestUtility.createSparTreeFromString("int a; int b=0;", LanguageC)
    tree.updateLeafTokenCount()
    assertThat(tree.realRoot.leafTokenCount).isEqualTo(8)

    assertThat(tree.realRoot.childCount).isEqualTo(1)
    val child = tree.realRoot.getChild(0)

    assertThat(child.childCount).isEqualTo(2)
    val firstStmt = child.getChild(0)
    assertThat(firstStmt.leafTokenCount).isEqualTo(3)

    val secondStmt = child.getChild(1)
    assertThat(secondStmt.leafTokenCount).isEqualTo(5)

    tree
      .createNodeDeletionEdit(
        NodeDeletionActionSet.createByDeleteSingleNode(
          tree.getTokenNodeForText("b").single(),
          "dummy",
        ),
      ).let {
        tree.applyEdit(it)
      }
    assertThat(tree.realRoot.leafTokenCount).isEqualTo(7)
    tree.realRoot.updateLeafTokenCount()
    assertThat(tree.realRoot.leafTokenCount).isEqualTo(7)
  }

  @Test
  fun testIsDeleted() {
    val tree = TestUtility.createSparTreeFromString("int a; int b=0;", LanguageC)
    tree.updateLeafTokenCount()
    tree.realRoot.delete()
    assertThat(kotlin.runCatching { tree.updateLeafTokenCount() }.exceptionOrNull()).isNotNull()
    assertThat(kotlin.runCatching { tree.realRoot.leafTokenCount }.exceptionOrNull()).isNotNull()
    assertThat(tree.realRoot.isPermanentlyDeleted).isTrue()
    assertThat(tree.realRoot.childCount).isEqualTo(0)
  }
}
