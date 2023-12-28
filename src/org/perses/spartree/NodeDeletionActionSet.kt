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

import com.google.common.collect.ImmutableList
import org.perses.util.toImmutableList

class NodeDeletionActionSet private constructor(
  actions: ImmutableList<NodeDeletionAction>,
  actionsDescription: String,
) : AbstractActionSet<NodeDeletionAction>(actions, actionsDescription, canBeSorted = true) {

  class Builder(private val actionsDescription: String) {
    private val nodesToDelete = LinkedHashSet<AbstractSparTreeNode>()
    fun deleteNode(node: AbstractSparTreeNode): Builder {
      check(nodesToDelete.add(node))
      return this
    }

    fun deleteNodes(nodes: Iterable<AbstractSparTreeNode>): Builder {
      nodes.forEach { deleteNode(it) }
      return this
    }

    fun build(): NodeDeletionActionSet {
      return NodeDeletionActionSet(
        nodesToDelete.asSequence()
          .sortedBy { it.nodeId }
          .map { NodeDeletionAction(it) }
          .toImmutableList(),
        actionsDescription,
      )
    }

    fun size(): Int {
      return nodesToDelete.size
    }
  }

  companion object {
    @JvmStatic
    fun createByDeleteSingleNode(
      node: AbstractSparTreeNode,
      actionsDescription: String,
    ): NodeDeletionActionSet {
      return NodeDeletionActionSet(
        ImmutableList.of(NodeDeletionAction(node)),
        actionsDescription,
      )
    }

    fun createByDeletingNodes(
      nodes: Iterable<AbstractSparTreeNode>,
      actionsDescription: String,
    ): NodeDeletionActionSet {
      return Builder(actionsDescription).deleteNodes(nodes).build()
    }
  }
}
