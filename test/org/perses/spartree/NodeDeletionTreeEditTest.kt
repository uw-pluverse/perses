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
import org.perses.spartree.AbstractTreeNode.Companion.findLowestAncestor
import org.perses.util.MutableInt
import java.nio.file.Paths

class NodeDeletionTreeEditTest {
  val tree = TestUtility.createSparTreeFromFile(Paths.get("test_data/parentheses/t.c"))
  val nodePrintf = tree.getTokenNodeForText("printf")[0]
  val nodeSemicol = tree.getTokenNodeForText(";")[0]
  val nodeMain = tree.getTokenNodeForText("main")[0]

  @Test
  fun testInternalApply1() {
    val builder = NodeDeletionActionSet.Builder("test 1")
    val ancestor = findLowestAncestor(nodePrintf, nodeSemicol)
    builder.deleteNode(nodePrintf)
    builder.deleteNode(nodeSemicol)
    builder.deleteNode(ancestor)

    val parent = nodeMain.parent!!
    builder.deleteNode(parent)
    builder.deleteNode(nodeMain)

    val edit =
      tree.createNodeDeletionEdit(
        builder.build(),
      )
    tree.applyEdit(edit, canonicalTokenCount = null)
    // Check printF is replaced, int is replaced
    assertThat(nodePrintf.isPermanentlyDeleted).isTrue()
    assertThat(nodeSemicol.isPermanentlyDeleted).isTrue()
    assertThat(ancestor.isPermanentlyDeleted).isTrue()
    assertThat(parent.isPermanentlyDeleted).isTrue()
    assertThat(nodeMain.isPermanentlyDeleted).isTrue()
  }

  @Test
  fun testDeleteEmptyNode() {
    val parent = nodePrintf.parent!!
    val edit =
      tree.createNodeDeletionEdit(
        NodeDeletionActionSet.createByDeletingNodes(
          parent.immutableChildView,
          contextDescription = "",
        ),
      )
    tree.applyEdit(edit, canonicalTokenCount = null)
    val nodeCount = MutableInt(0)
    tree.realRoot.postOrderVisit {
      nodeCount.increment()
    }
    val program1 = tree.programSnapshot.payload
    val string = program1.tokens.joinToString(separator = " ") { it.lexemeText }
    assertThat(string).doesNotContain("printf")

    val parentEdit =
      tree.createNodeDeletionEdit(
        NodeDeletionActionSet.createByDeleteSingleNode(parent, contextDescription = ""),
      )
    tree.applyEdit(parentEdit, canonicalTokenCount = null)
    val nodeCount2 = MutableInt(0)
    tree.realRoot.postOrderVisit {
      nodeCount2.increment()
    }
    val program2 = tree.programSnapshot.payload
    assertThat(program1.tokens).isEqualTo(program2.tokens)
    assertThat(nodeCount.get()).isEqualTo(nodeCount2.get() + 1)
  }
}
