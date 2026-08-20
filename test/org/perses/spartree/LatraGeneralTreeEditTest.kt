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
package org.perses.spartree

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.perses.TestUtility
import org.perses.grammar.c.LanguageC
import org.perses.spartree.AbstractTreeNode.NodeIdCopyStrategy.ReuseNodeIdStrategy
import java.nio.file.Paths

class LatraGeneralTreeEditTest {
  private val tree = TestUtility.createSparTreeFromFile(Paths.get("test_data/parentheses/t.c"))
  private val nodePrintf = tree.getTokenNodeForText("printf")[0]
  private val nodeSemicol = tree.getTokenNodeForText(";")[0]
  private val nodeInt = tree.getTokenNodeForText("int")[0]
  private val nodeMain = tree.getTokenNodeForText("main")[0]

  @Test
  fun testInternalApply() {
    val builder = LatraGeneralActionSet.Builder("test 1", transformationName = "test")
    val nodeSemicolCopy = nodeSemicol.recursiveDeepCopy(ReuseNodeIdStrategy).result
    val nodeMainCopy = nodeMain.recursiveDeepCopy(ReuseNodeIdStrategy).result
    // ";" replace Printf , main replace Int and delete main at int
    builder.replaceNode(nodePrintf, nodeSemicolCopy)
    builder.replaceNode(nodeInt, nodeMainCopy)
    builder.deleteNode(nodeMainCopy)

    val edit = tree.createLatraGeneralEdit(builder.buildOrNull()!!)

    val bufferParentOfPrintf = nodePrintf.parent
    tree.applyEdit(edit, canonicalTokenCount = null)
    // Check printF is replaced, int is replaced
    assertThat(nodePrintf.isPermanentlyDeleted).isTrue()
    assertThat(nodeInt.isPermanentlyDeleted).isTrue()
    assertThat(nodeSemicolCopy.parent).isEqualTo(bufferParentOfPrintf)
    assertThat(!nodeMain.isPermanentlyDeleted).isTrue()
    // check original main is still there
    assertThat(nodeMainCopy.isPermanentlyDeleted).isTrue()
  }

  @Test
  fun testLatraEditComputeProgram() {
    val expectOutput =
      """
      main ( ) { { { { { ; ( ( "hello world\n" ) ) ; } } } } }
      """.trimIndent()
    val builder = LatraGeneralActionSet.Builder("test 2", transformationName = "test")
    val nodeSemicolCopy = nodeSemicol.recursiveDeepCopy(ReuseNodeIdStrategy).result
    val nodeMainCopy = nodeMain.recursiveDeepCopy(ReuseNodeIdStrategy).result
    // ";" replace Printf , main replace Int and delete main at int
    builder.replaceNode(nodePrintf, nodeSemicolCopy)
    builder.replaceNode(nodeInt, nodeMainCopy)
    builder.deleteNode(nodeMainCopy)

    val edit = tree.createLatraGeneralEdit(builder.buildOrNull()!!)

    tree.applyEdit(edit, canonicalTokenCount = null)
    assertThat(
      edit
        .program
        .tokens
        .asSequence()
        .map { it.lexemeText }
        .joinToString(" "),
    ).isEqualTo(expectOutput)
    assertThat(
      tree.programSnapshot.payload.tokens
        .asSequence()
        .map { it.lexemeText }
        .joinToString(" "),
    ).isEqualTo(expectOutput)
  }

  @Test
  fun testReplaceRootWithLatraEdit() {
    val tree = TestUtility.createSparTreeFromString("int a;", LanguageC)
    val another =
      TestUtility
        .createSparTreeFromString(
          "char c;",
          LanguageC,
        ).detachRootFromTree()
        .also { root ->
          val firstToken = root.beginToken!!
          firstToken.parent!!.replaceChild(
            firstToken,
            newChild =
              TestUtility
                .createSparTreeFromString(
                  ";",
                  LanguageC,
                ).detachRootFromTree(),
            firstToken.payload!!,
          )
        }
    another.fixLinkIntegrity()

    val edit =
      tree.createLatraGeneralEdit(
        LatraGeneralActionSet
          .Builder(
            contextDescription = "test action",
            transformationName = "test",
          ).replaceNode(
            targetNode = tree.realRoot,
            replacingNode = another,
          ).buildOrNull()!!,
      )
    edit.program.tokens.map { it.lexemeText }.let { tokens ->
      assertThat(tokens)
        .containsExactly(
          ";",
          "c",
          ";",
        ).inOrder()
    }
    tree.applyEdit(edit, canonicalTokenCount = null)
    tree.programSnapshot.payload.tokens.map { it.lexemeText }.let { tokens ->
      assertThat(tokens)
        .containsExactly(
          ";",
          "c",
          ";",
        ).inOrder()
    }
  }
}
