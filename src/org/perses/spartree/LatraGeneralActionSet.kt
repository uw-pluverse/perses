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

/**
 * This action set allows both deletion and replacement,
 * and the actions do not need to be sorted.
 */
class LatraGeneralActionSet private constructor(
  actions: ImmutableList<AbstractTargetedTreeEditAction>,
  contextDescription: String,
  transformationName: String,
) : TargetedActionSet<AbstractTargetedTreeEditAction>(
    actions = actions,
    contextDescription = contextDescription,
    canBeSorted = false,
    transformationName = transformationName,
  ) {
  class Builder(
    private var contextDescription: String,
    private val transformationName: String,
  ) {
    private val deletedNodeUpToNow = HashSet<AbstractSparTreeNode>()
    private val actionSetBuilder = ImmutableList.Builder<AbstractTargetedTreeEditAction>()

    fun deleteNode(targetNode: AbstractSparTreeNode): Builder {
      actionSetBuilder.add(NodeDeletionAction(targetNode))
      check(deletedNodeUpToNow.add(targetNode))
      return this
    }

    fun replaceNode(
      targetNode: AbstractSparTreeNode,
      replacingNode: AbstractSparTreeNode,
      extraActionsDescription: String? = null,
    ): Builder {
      check(replacingNode.parent == null)
      // checking here might be expensive
      for (deleted in deletedNodeUpToNow) {
        val targetNodeCommonAncestor = AbstractTreeNode.findLowestAncestor(deleted, targetNode)
        check(targetNodeCommonAncestor != deleted)
      }
      deletedNodeUpToNow.add(targetNode)
      actionSetBuilder.add(NodeReplacementAction(targetNode, replacingNode))
      if (extraActionsDescription != null) {
        contextDescription += extraActionsDescription
      }
      return this
    }

    fun buildOrNull(): LatraGeneralActionSet? {
      val actionSet = actionSetBuilder.build()
      return if (actionSet.isEmpty()) {
        null
      } else {
        LatraGeneralActionSet(actionSet, contextDescription, transformationName)
      }
    }
  }
}
