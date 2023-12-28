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
import org.perses.spartree.AbstractTreeNode.Companion.findLowestAncestor
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

    val edit = tree.createNodeDeletionEdit(
      builder.build(),
    )
    tree.applyEdit(edit)
    // Check printF is replaced, int is replaced
    assertThat(nodePrintf.isPermanentlyDeleted).isTrue()
    assertThat(nodeSemicol.isPermanentlyDeleted).isTrue()
    assertThat(ancestor.isPermanentlyDeleted).isTrue()
    assertThat(parent.isPermanentlyDeleted).isTrue()
    assertThat(nodeMain.isPermanentlyDeleted).isTrue()
  }
}
