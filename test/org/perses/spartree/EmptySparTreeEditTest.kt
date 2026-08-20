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
import org.perses.spartree.AbstractSparTreeEdit.AbstractDeletedTokens
import java.nio.file.Paths

class EmptySparTreeEditTest {
  private val tree = TestUtility.createSparTreeFromFile(Paths.get("test_data/parentheses/t.c"))
  private val root = tree.realRoot

  @Test
  fun testEmptyTreeEditAction() {
    val action = EmptyTreeEditAction
    assertThat(action.conciseDescription).isEqualTo("EmptyTreeEditAction")

    val anotherAction = EmptyTreeEditAction
    assertThat(action).isEqualTo(anotherAction)
    assertThat(action.hashCode()).isEqualTo(anotherAction.hashCode())
    assertThat(action.compareTo(anotherAction)).isEqualTo(0)

    // Applying should not change anything
    val isPermanentlyDeletedBefore = root.isPermanentlyDeleted
    val childCountBefore = root.childCount
    val parentBefore = root.parent

    val oldProgram = tree.programSnapshot
    val oldVersion = tree.version
    action.apply()

    assertThat(tree.programSnapshot).isSameInstanceAs(oldProgram)
    assertThat(tree.version).isEqualTo(oldVersion)
    assertThat(root.isPermanentlyDeleted).isEqualTo(isPermanentlyDeletedBefore)
    assertThat(root.childCount).isEqualTo(childCountBefore)
    assertThat(root.parent).isEqualTo(parentBefore)
  }

  @Test
  fun testEmptyActionSet() {
    val context = "test context"
    val actionSet = EmptyActionSet(context)
    assertThat(actionSet.actions).isEmpty()
    assertThat(actionSet.contextDescription).isEqualTo(context)
    assertThat(actionSet.isEmpty).isTrue()
  }

  @Test
  fun testEmptySparTreeEdit() {
    val context = "test context"
    val edit = EmptySparTreeEdit(tree, context)

    assertThat(edit.tree).isEqualTo(tree)
    val deletedTokens = edit.lazilyComputedDeletedTokens
    assertThat((deletedTokens as AbstractDeletedTokens.DeletedTokens).tokens).isEmpty()
    assertThat(edit.structureDescription).startsWith("[]")

    val programBefore = tree.programSnapshot.payload
    assertThat(edit.computeProgram()).isEqualTo(programBefore)

    // Applying to tree should change the version (as it's a logical edit) but not the program
    val versionBefore = tree.version
    val rootBefore = tree.realRoot
    tree.applyEdit(edit, canonicalTokenCount = null)
    val programAfter = tree.programSnapshot.payload
    assertThat(programAfter).isEqualTo(programBefore)
    assertThat(tree.version).isEqualTo(versionBefore)
    assertThat(tree.realRoot).isSameInstanceAs(rootBefore)
  }
}
