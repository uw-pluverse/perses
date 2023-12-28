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

class LatraGeneralActionSet private constructor(
  actions: ImmutableList<AbstractTreeEditAction>,
  actionsDescription: String,
) : AbstractActionSet<AbstractTreeEditAction>(actions, actionsDescription, canBeSorted = false) {

  class Builder(
    private val actionsDescription: String,
  ) {
    private val deletedNodeUpToNow = HashSet<AbstractSparTreeNode>()
    private val actionSetBuilder = ImmutableList.Builder<AbstractTreeEditAction>()

    fun deleteNode(targetNode: AbstractSparTreeNode) {
      actionSetBuilder.add(NodeDeletionAction(targetNode))
      check(deletedNodeUpToNow.add(targetNode))
    }

//   checking here might be expensive
    fun replaceNode(targetNode: AbstractSparTreeNode, replacingNode: AbstractSparTreeNode) {
      for (node in deletedNodeUpToNow) {
        val targetNodeCommonAncestor = AbstractTreeNode.findLowestAncestor(node, targetNode)
        check(targetNodeCommonAncestor != node)
        check(replacingNode.parent == null)
      }
      deletedNodeUpToNow.add(targetNode)
      actionSetBuilder.add(NodeReplacementAction(targetNode, replacingNode))
    }

    fun build(): LatraGeneralActionSet? {
      val actionSet = actionSetBuilder.build()
      return if (actionSet.isEmpty()) {
        null
      } else {
        LatraGeneralActionSet(actionSet, actionsDescription)
      }
    }
  }
}
