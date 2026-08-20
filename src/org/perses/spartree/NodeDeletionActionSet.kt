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
import org.perses.util.transformToImmutableList

class NodeDeletionActionSet private constructor(
  actions: ImmutableList<NodeDeletionAction>,
  contextDescription: String,
  transformationName: String,
) : TargetedActionSet<NodeDeletionAction>(
    actions = actions,
    contextDescription = contextDescription,
    canBeSorted = true,
    transformationName = transformationName,
  ) {
  override val structureDescription: String
    get() =
      if (actions.size == 1) {
        actions.joinToString(separator = ",", prefix = "[", postfix = "]") { it.conciseDescription }
      } else {
        actions.joinToString(separator = ",", prefix = "[delete: ", postfix = "]") {
          it.targetNode.nodeId.toString()
        }
      }

  class Builder(
    private val contextDescription: String,
    private val transformationName: String = DELETION,
  ) {
    private val nodesToDelete = LinkedHashSet<AbstractSparTreeNode>()

    fun deleteNode(node: AbstractSparTreeNode): Builder {
      check(!node.isPermanentlyDeleted) {
        "Node ${node.nodeId} has been deleted."
      }
      // Note that we allow to delete a node multiple times.
      nodesToDelete.add(node)
      return this
    }

    fun deleteNodes(nodes: Iterable<AbstractSparTreeNode>): Builder {
      nodes.forEach { deleteNode(it) }
      return this
    }

    fun build(): NodeDeletionActionSet {
      check(nodesToDelete.isNotEmpty()) { "The nodesToDelete list is empty." }
      return NodeDeletionActionSet(
        actions =
          nodesToDelete
            .asSequence()
            .sortedBy { it.nodeId }
            .transformToImmutableList { NodeDeletionAction(it) },
        contextDescription = contextDescription,
        transformationName = transformationName,
      )
    }

    fun size(): Int = nodesToDelete.size
  }

  companion object {
    // The operation kind reported as the transformation name when the caller does not override it;
    // node deletion is the same operation regardless of which reducer drives it.
    const val DELETION = "Deletion"

    @JvmStatic
    fun createByDeleteSingleNode(
      node: AbstractSparTreeNode,
      contextDescription: String,
      transformationName: String = DELETION,
    ): NodeDeletionActionSet =
      NodeDeletionActionSet(
        ImmutableList.of(NodeDeletionAction(node)),
        contextDescription,
        transformationName,
      )

    fun createByDeletingNodes(
      nodes: Iterable<AbstractSparTreeNode>,
      contextDescription: String,
      transformationName: String = DELETION,
    ): NodeDeletionActionSet =
      Builder(contextDescription, transformationName).deleteNodes(nodes).build()
  }
}
