/*
 * Copyright (C) 2018-2022 University of Waterloo.
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

import org.perses.util.Util.lazyAssert

class AnyNodeReplacementTreeEdit internal constructor(
  tree: SparTree,
  actionSet: ChildHoistingActionSet,
) : AbstractNodeReplacementTreeEdit(tree, actionSet) {

  override fun internalApplyToTree() {
    actionSet.actions.forEach { action ->
      val targetNode = action.targetNode
      val parentNode = targetNode.parent!!
      val replacingNode = action.replacingChild
      lazyAssert { replacingNode.parent == null }
      val payload = targetNode.payload!!
      replacingNode.resetPayload()
      parentNode.replaceChild(
        targetNode,
        replacingNode,
        payload,
      )
      lazyAssert { targetNode.parent == null }
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
}
