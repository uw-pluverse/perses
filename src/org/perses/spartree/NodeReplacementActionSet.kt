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
import org.perses.util.toImmutableList

class NodeReplacementActionSet private constructor(
  childHoistingActions: ImmutableList<NodeReplacementAction>,
  contextDescription: String,
  transformationName: String,
) : TargetedActionSet<NodeReplacementAction>(
    actions = childHoistingActions,
    contextDescription = contextDescription,
    canBeSorted = true,
    transformationName = transformationName,
  ) {
  init {
    require(childHoistingActions.isNotEmpty())
  }

  override val structureDescription: String
    get() =
      if (actions.size == 1) {
        actions.joinToString(separator = ",", prefix = "[", postfix = "]") { it.conciseDescription }
      } else {
        actions.joinToString(separator = ",", prefix = "[replace: ", postfix = "]") {
          "${it.targetNode.nodeId}_with_${it.replacingNode.nodeId}"
        }
      }

  class Builder(
    private val contextDescription: String,
    private val transformationName: String = REPLACEMENT,
  ) {
    private val node2ReplacementMap = LinkedHashMap<AbstractSparTreeNode, AbstractSparTreeNode>()

    fun replaceNode(
      targetNode: AbstractSparTreeNode,
      replacement: AbstractSparTreeNode,
    ) {
      check(node2ReplacementMap.put(targetNode, replacement) == null)
    }

    fun build(): NodeReplacementActionSet =
      NodeReplacementActionSet(
        node2ReplacementMap.entries
          .asSequence()
          .map { (key, value) -> NodeReplacementAction(key, value) }
          .sorted()
          .toImmutableList(),
        contextDescription,
        transformationName,
      )
  }

  companion object {
    // The operation kind reported as the transformation name when the caller does not override it
    // (astra supplies its own transformation name through this same parameter).
    const val REPLACEMENT = "Replacement"

    @JvmStatic
    fun createByReplacingSingleNode(
      targetNode: AbstractSparTreeNode,
      replacingNode: AbstractSparTreeNode,
      contextDescription: String,
      transformationName: String = REPLACEMENT,
    ): NodeReplacementActionSet =
      createByReplacingSingleNode(
        NodeReplacementAction(targetNode, replacingNode),
        contextDescription,
        transformationName,
      )

    @JvmStatic
    fun createByReplacingSingleNode(
      action: NodeReplacementAction,
      contextDescription: String,
      transformationName: String = REPLACEMENT,
    ): NodeReplacementActionSet =
      NodeReplacementActionSet(ImmutableList.of(action), contextDescription, transformationName)
  }
}
