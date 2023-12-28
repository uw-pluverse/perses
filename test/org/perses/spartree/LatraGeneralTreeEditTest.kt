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
package org.perses.spartree

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.perses.TestUtility
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
    val builder = LatraGeneralActionSet.Builder("test 1")
    val nodeSemicolCopy = nodeSemicol.recursiveDeepCopy(ReuseNodeIdStrategy)
    val nodeMainCopy = nodeMain.recursiveDeepCopy(ReuseNodeIdStrategy)
    // ";" replace Printf , main replace Int and delete main at int
    builder.replaceNode(nodePrintf, nodeSemicolCopy)
    builder.replaceNode(nodeInt, nodeMainCopy)
    builder.deleteNode(nodeMainCopy)

    val edit = tree.createLatraGeneralEdit(
      builder.build()!!,
    )

    val bufferParentOfPrintf = nodePrintf.parent
    tree.applyEdit(edit)
    // Check printF is replaced, int is replaced
    assertThat(nodePrintf.isPermanentlyDeleted).isTrue()
    assertThat(nodeInt.isPermanentlyDeleted).isTrue()
    assertThat(nodeSemicolCopy.parent).isEqualTo(bufferParentOfPrintf)
    assertThat(!nodeMain.isPermanentlyDeleted).isTrue()
    // check original main is still there
    assertThat(nodeMainCopy.isPermanentlyDeleted).isTrue()
  }

  @Test
  fun testComputeProgram() {
    val expectOutput = """
      main ( ) { { { { { ; ( ( "hello world\n" ) ) ; } } } } }
    """.trimIndent()
    val builder = LatraGeneralActionSet.Builder("test 2")
    val nodeSemicolCopy = nodeSemicol.recursiveDeepCopy(ReuseNodeIdStrategy)
    val nodeMainCopy = nodeMain.recursiveDeepCopy(ReuseNodeIdStrategy)
    // ";" replace Printf , main replace Int and delete main at int
    builder.replaceNode(nodePrintf, nodeSemicolCopy)
    builder.replaceNode(nodeInt, nodeMainCopy)
    builder.deleteNode(nodeMainCopy)

    val edit = tree.createLatraGeneralEdit(
      builder.build()!!,
    )

    tree.applyEdit(edit)
    assertThat(
      edit.computeProgram(tree).tokens.asSequence()
        .map { it.text }
        .joinToString(" "),
    ).isEqualTo(expectOutput)
    assertThat(
      tree.programSnapshot.tokens.asSequence()
        .map { it.text }
        .joinToString(" "),
    ).isEqualTo(expectOutput)
  }
}
