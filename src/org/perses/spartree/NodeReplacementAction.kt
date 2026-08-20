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

import org.perses.util.Util
import kotlin.comparisons.compareBy

class NodeReplacementAction(
  targetNode: AbstractSparTreeNode,
  val replacingNode: AbstractSparTreeNode,
) : AbstractTargetedTreeEditAction(targetNode) {
  init {
    Util.lazyAssert {
      val errors = replacingNode.checkLeafLinkIntegrity()
      if (errors != null) {
        throw IllegalStateException(errors.toString())
      }
      true
    }
  }

  override fun internalCompareTo(o: AbstractTreeEditAction): Int {
    check(o is NodeReplacementAction) { "$o. ${o::class}" }
    return compareBy<NodeReplacementAction> { it.targetNode.nodeId }
      .thenBy { it.replacingNode.nodeId }
      .compare(this, o)
  }

  override val conciseDescription: String
    get() = "replace_${targetNode.nodeId}_with_${replacingNode.nodeId}"

  override fun specificEquals(other: AbstractTargetedTreeEditAction): Boolean {
    if (other !is NodeReplacementAction) {
      return false
    }
    return other.replacingNode === replacingNode
  }

  override fun specificHashCode(): Int = replacingNode.nodeId

  override fun internalApply() {
    check(!targetNode.isPermanentlyDeleted)
    // only take independent replacingNode now.
    check(replacingNode.parent == null)
    check(!replacingNode.isPermanentlyDeleted) {
      "The replacing node ${replacingNode.nodeId} has been deleted." +
        replacingNode.printTreeStructure()
    }
    val parentNode = targetNode.parent!!
    val targetPayload = targetNode.payload!!
    val payload =
      if (replacingNode.payload != null) {
        AbstractNodePayload.concatenatePaylods(
          targetPayload,
          replacingNode.payload!!,
        )
      } else {
        targetPayload
      }
    replacingNode.resetPayload()
    parentNode.replaceChild(
      targetNode,
      replacingNode,
      payload,
    )

    check(targetNode.parent == null)

    // maintain leaf list
    val targetNodePrev =
      if (targetNode is LexerRuleSparTreeNode) {
        targetNode.prev
      } else {
        targetNode.beginToken?.prev
      } ?: error("unexpected.")
    val targetNodeNext =
      if (targetNode is LexerRuleSparTreeNode) {
        targetNode.next
      } else {
        targetNode.endToken?.next
      } ?: error("unexpected.")
    targetNodePrev.next = replacingNode.beginToken
    replacingNode.beginToken?.prev = targetNodePrev

    targetNodeNext.prev = replacingNode.endToken
    replacingNode.endToken?.next = targetNodeNext

    targetNode.delete()
    SparTree.updateTokenIntervalUpToRoot(parentNode)
  }
}
