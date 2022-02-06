/*
 * Copyright (C) 2018-2022 University of Waterloo.
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

import com.google.common.collect.ComparisonChain
import org.perses.program.TokenizedProgram
import java.util.concurrent.atomic.AtomicInteger

// FIXME: this should be a sealed class.
abstract class AbstractSparTreeEdit<T : AbstractTreeEditAction> protected constructor(
  val actionSet: AbstractActionSet<T>,
  val program: TokenizedProgram
) : Comparable<AbstractSparTreeEdit<*>> {

  private val id: Int = idGenerator.getAndIncrement()

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

  companion object {
    fun createDeletionSparTreeEdit(
      tree: SparTree,
      actionSet: NodeDeletionActionSet
    ): NodeDeletionTreeEdit {
      return NodeDeletionTreeEdit(tree, actionSet)
    }

    fun createReplacementSparTreeEdit(
      tree: SparTree,
      actionSet: ChildHoistingActionSet
    ): NodeReplacementTreeEdit {
      return NodeReplacementTreeEdit(tree, actionSet)
    }

    fun createAnyNodeReplacementTreeEdit(
      tree: SparTree,
      actionSet: ChildHoistingActionSet
    ): AnyNodeReplacementTreeEdit {
      return AnyNodeReplacementTreeEdit(tree, actionSet)
    }

    private val idGenerator = AtomicInteger()
  }
}
