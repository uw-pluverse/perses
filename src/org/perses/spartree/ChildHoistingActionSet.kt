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
import com.google.common.collect.ImmutableList
import org.perses.util.toImmutableList

/**
 * TODO(gaosen): not sure whether we should rename this class to NodeReplacementActionSet.
 */
class ChildHoistingActionSet private constructor(
  childHoistingActions: ImmutableList<NodeReplacementAction>,
  actionsDescription: String,
) : AbstractActionSet<NodeReplacementAction>(
  childHoistingActions,
  actionsDescription,
  canBeSorted = true,
) {

  init {
    require(childHoistingActions.isNotEmpty())
  }

  class Builder(private val actionsDescription: String) {

    private val node2ReplacementMap = LinkedHashMap<AbstractSparTreeNode, AbstractSparTreeNode>()

    fun replaceNode(
      targetNode: AbstractSparTreeNode,
      replacement: AbstractSparTreeNode,
    ) {
      check(node2ReplacementMap.put(targetNode, replacement) == null)
    }

    fun build(): ChildHoistingActionSet {
      return ChildHoistingActionSet(
        node2ReplacementMap.entries
          .asSequence()
          .map { (key, value) -> NodeReplacementAction(key, value) }
          .sorted()
          .toImmutableList(),
        actionsDescription,
      )
    }
  }

  override fun toString(): String {
    return MoreObjects.toStringHelper(this)
      .add("desc", actionsDescription)
      .add("actions", actions).toString()
  }

  companion object {

    @JvmStatic
    fun createByReplacingSingleNode(
      targetNode: AbstractSparTreeNode,
      replacingNode: AbstractSparTreeNode,
      actionsDescription: String,
    ): ChildHoistingActionSet {
      return createByReplacingSingleNode(
        NodeReplacementAction(targetNode, replacingNode),
        actionsDescription,
      )
    }

    @JvmStatic
    fun createByReplacingSingleNode(
      action: NodeReplacementAction,
      actionsDescription: String,
    ): ChildHoistingActionSet {
      return ChildHoistingActionSet(ImmutableList.of(action), actionsDescription)
    }
  }
}
