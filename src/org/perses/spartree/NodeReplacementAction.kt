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

class NodeReplacementAction(
  targetNode: AbstractSparTreeNode,
  val replacingNode: AbstractSparTreeNode,
) : AbstractTreeEditAction(targetNode) {

  override fun internalCompareTo(o: AbstractTreeEditAction): Int {
    check(o is NodeReplacementAction)
    // TODO, refactor this with kotlin's comparator.
    return ComparisonChain.start()
      .compare(targetNode.nodeId, o.targetNode.nodeId)
      .compare(replacingNode.nodeId, o.replacingNode.nodeId)
      .result()
  }

  override val description: String
    get() = MoreObjects.toStringHelper(this)
      .add("target_node", targetNode.nodeId)
      .add("replacement", replacingNode.nodeId)
      .toString()

  override fun toString(): String {
    return MoreObjects.toStringHelper(this)
      .add("target", targetNode)
      .add("replacement", replacingNode)
      .toString()
  }

  override fun specificEquals(other: AbstractTreeEditAction): Boolean {
    if (other !is NodeReplacementAction) {
      return false
    }
    return other.replacingNode === replacingNode
  }

  override fun specificHashCode(): Int {
    return replacingNode.nodeId
  }

  override fun internalApply() {
    check(!targetNode.isPermanentlyDeleted)
    val parentNode = targetNode.parent!!
    val payload = targetNode.payload!!
    replacingNode.resetPayload()
//  only take independent replacingNode now.
//  TODO:merge NodeReplacementEdit and AnyNodeReplacementEdit
    check(replacingNode.parent == null)

    parentNode.replaceChild(
      targetNode,
      replacingNode,
      payload,
    )

    check(targetNode.parent == null)
    targetNode.delete()

    // maintain leaf list
    val targetNodePre = if (targetNode is LexerRuleSparTreeNode) {
      targetNode.prev
    } else {
      targetNode.beginToken?.prev
    }
    val targetNodeNext = if (targetNode is LexerRuleSparTreeNode) {
      targetNode.next
    } else {
      targetNode.endToken?.next
    }
    if (targetNodePre != null) {
      targetNodePre.next = replacingNode.beginToken
      replacingNode.beginToken?.prev = targetNodePre
    }

    if (targetNodeNext != null) {
      targetNodeNext.prev = replacingNode.endToken
      replacingNode.endToken?.next = targetNodeNext
    }
    SparTree.updateTokenIntervalUpToRoot(parentNode)
  }
}
