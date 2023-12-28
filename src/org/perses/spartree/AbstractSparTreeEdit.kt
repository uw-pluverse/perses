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

import com.google.common.base.MoreObjects
import com.google.common.collect.ComparisonChain
import org.perses.program.TokenizedProgram
import java.util.concurrent.atomic.AtomicInteger

// FIXME: this should be a sealed class.
sealed class AbstractSparTreeEdit<T : AbstractTreeEditAction> (
  val actionSet: AbstractActionSet<T>,
  private val tree: SparTree,
) : Comparable<AbstractSparTreeEdit<*>> {

  private val id: Int = idGenerator.getAndIncrement()
  private val treeSnapshotVersion = tree.version

  val program by lazy {
    check(tree.version == treeSnapshotVersion)
    computeProgram(tree)
  }

  fun asNodeDeleteEdit(): NodeDeletionTreeEdit {
    return this as NodeDeletionTreeEdit
  }

  fun asNodeReplacementEdit(): NodeReplacementTreeEdit {
    return this as NodeReplacementTreeEdit
  }

  fun asAnyNodeReplacementEdit(): AnyNodeReplacementTreeEdit {
    return this as AnyNodeReplacementTreeEdit
  }

  val numberOfActions: Int
    get() = actionSet.size()

  fun isNodeATarget(node: AbstractSparTreeNode?): Boolean {
    return actionSet.containsNodeAsTarget(node!!)
  }

  override fun compareTo(other: AbstractSparTreeEdit<*>): Int {
    return ComparisonChain.start()
      .compare(program.tokenCount(), other.program.tokenCount())
      .compare(id, other.id)
      .result()
  }

  abstract fun computeProgram(tree: SparTree): TokenizedProgram

  override fun toString(): String {
    return MoreObjects.toStringHelper(this)
      .add("actions", actionSet).toString()
  }

  /**
   * This method is marked internal, because we do not want this method to be called
   * outside of SparTree. This method should be only called in SparTree so that we can
   * track the edits to a spar tree.
   */
  internal fun applyToTree() {
    check(tree.version == treeSnapshotVersion)
    internalApplyToTree()
  }

  internal abstract fun internalApplyToTree()

  companion object {
    fun createDeletionSparTreeEdit(
      tree: SparTree,
      actionSet: NodeDeletionActionSet,
    ): NodeDeletionTreeEdit {
      return NodeDeletionTreeEdit(tree, actionSet)
    }

    fun createReplacementSparTreeEdit(
      tree: SparTree,
      actionSet: ChildHoistingActionSet,
    ): NodeReplacementTreeEdit {
      return NodeReplacementTreeEdit(tree, actionSet)
    }

    fun createAnyNodeReplacementTreeEdit(
      tree: SparTree,
      actionSet: ChildHoistingActionSet,
    ): AnyNodeReplacementTreeEdit {
      return AnyNodeReplacementTreeEdit(tree, actionSet)
    }

    fun createLatraGeneralTreeEdit(
      tree: SparTree,
      actionSet: LatraGeneralActionSet,
    ): LatraGeneralTreeEdit {
      return LatraGeneralTreeEdit(tree, actionSet)
    }

    private val idGenerator = AtomicInteger()
  }
}
