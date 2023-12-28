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
package org.perses.antlr.atn.tdtree

import com.google.common.base.MoreObjects
import org.perses.spartree.AbstractTreeNode

sealed class AbstractTDTreeNode(
  nodeId: Int,
) : AbstractTreeNode<AbstractTDTreeNode, Any>(nodeId = nodeId) {

  fun toLexeme(
    blanketedNodes: Set<AbstractTDTreeNode> = HashSet(),
  ): String {
    val builder = StringBuilder()
    preOrderVisit { node ->
      if (blanketedNodes.contains(node)) {
        return@preOrderVisit emptyList()
      }
      if (node is CharTDTreeNode) {
        builder.append(node.char)
      }
      node.immutableChildView
    }
    return builder.toString()
  }

  @Deprecated("Call the other addChild method.", ReplaceWith("addChild(child)"))
  override fun addChild(child: AbstractTDTreeNode, payload: Any) {
    error("Should not call this method.")
  }

  fun addChild(child: AbstractTDTreeNode) {
    super.addChild(child, EMPTY_PAYLOAD)
  }

  override fun onChildRemoved(index: Int, child: AbstractTDTreeNode) {
  }

  override fun toString(): String {
    return MoreObjects.toStringHelper(this).add("id", nodeId).toString()
  }

  companion object {
    private val EMPTY_PAYLOAD = Object()
  }
}
