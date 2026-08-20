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
import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableSet
import org.perses.program.TokenizedProgram

object EmptyTreeEditAction : AbstractTreeEditAction() {
  override fun internalCompareTo(o: AbstractTreeEditAction): Int {
    check(o is EmptyTreeEditAction) {
      o::class
    }
    return 0
  }

  override val conciseDescription: String
    get() = this::class.simpleName!!

  override fun equals(other: Any?): Boolean = other === EmptyTreeEditAction

  override fun hashCode(): Int = this::class.hashCode()

  override fun apply() {
    // do nothing
  }
}

class EmptyActionSet(
  contextDescription: String,
) : AbstractActionSet<EmptyTreeEditAction>(
    actions = ImmutableList.of(),
    contextDescription = contextDescription,
    canBeSorted = true,
    // An empty edit is a no-op that SparTree.applyEdit short-circuits before any commit event fires,
    // so this never reaches the statistics; an empty string documents that it has no transformation.
    transformationName = "",
  ) {
  override fun containsNodeAsTarget(node: AbstractSparTreeNode): Boolean = false

  override fun getActionForTarget(targetNode: AbstractSparTreeNode): EmptyTreeEditAction? = null

  override val targets: ImmutableSet<AbstractSparTreeNode>
    get() = ImmutableSet.of()
}

class EmptySparTreeEdit(
  tree: SparTree,
  contextDescription: String,
) : AbstractSparTreeEdit<EmptyTreeEditAction>(
    actionSet = EmptyActionSet(contextDescription),
    tree = tree,
  ) {
  override fun computeDeletedTokens(): AbstractDeletedTokens =
    AbstractDeletedTokens.DeletedTokens(ImmutableList.of())

  override val structureDescriptionPrefix: String
    get() = "[]"

  override fun internalComputeProgram(tree: SparTree): TokenizedProgram =
    tree.programSnapshot.payload

  override fun internalApplyToTree() {
    // do nothing
  }
}
