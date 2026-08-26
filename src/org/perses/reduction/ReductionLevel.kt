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
package org.perses.reduction

import com.google.common.base.MoreObjects
import com.google.common.collect.ImmutableList
import org.perses.spartree.AbstractSparTreeNode
import org.perses.util.CollectionUtil
import org.perses.util.CollectionUtil.removeElementsFromList
import org.perses.util.lazyAssert
import org.perses.util.toImmutableList

/** Represents a level in a spar-tree.  */
class ReductionLevel(
  val level: Int,
) {
  private val nodes = ArrayList<AbstractSparTreeNode>()

  fun toImmutableList(): ImmutableList<AbstractSparTreeNode> {
    cleanDeletedNodes()
    return nodes.toImmutableList()
  }

  fun addNode(node: AbstractSparTreeNode) {
    lazyAssert({ !node.isPermanentlyDeleted }) { "The node to add is already permanently deleted." }
    nodes.add(node)
  }

  fun replaceNode(
    origNode: AbstractSparTreeNode,
    replacement: AbstractSparTreeNode,
  ) {
    val index = nodes.indexOf(origNode)
    lazyAssert({ index >= 0 }) { nodes }
    nodes[index] = replacement
  }

  fun containsNode(node: AbstractSparTreeNode): Boolean = nodes.contains(node)

  val nodeCount: Int
    get() = nodes.size
  val isEmpty: Boolean
    get() = nodeCount == 0

  fun getNode(index: Int): AbstractSparTreeNode = nodes[index]

  fun forEachNode(consumer: (AbstractSparTreeNode) -> Unit) {
    nodes.forEach(consumer)
  }

  fun cleanDeletedNodes() {
    removeElementsFromList(nodes) { _, node ->
      node.isPermanentlyDeleted
    }
  }

  fun createNextLevel(): ReductionLevel {
    val nextLevel = ReductionLevel(level + 1)
    nodes.forEach { node ->
      node.forEachChild { child -> nextLevel.addNode(child) }
    }
    return nextLevel
  }

  override fun toString(): String =
    MoreObjects
      .toStringHelper(this)
      .add("level", level)
      .add("nodes", nodes)
      .toString()
}
