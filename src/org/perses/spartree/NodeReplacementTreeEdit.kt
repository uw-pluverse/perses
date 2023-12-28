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

import org.perses.util.Util.lazyAssert

class NodeReplacementTreeEdit internal constructor(
  tree: SparTree,
  actionSet: ChildHoistingActionSet,
) : AbstractNodeReplacementTreeEdit(tree, actionSet) {

  init {
    require(actionSet.actions.size == 1) {
      "Only single action is allowed for not."
    }
  }

//  TODO: merge this into AnyNodeReplacement
  override fun internalApplyToTree() {
    val action = actionSet.actions.single()
    val targetNode = action.targetNode
    val childToHoist = action.replacingNode
    childToHoist.parent!!.removeChild(childToHoist)
    lazyAssert { childToHoist.parent == null }
    val payload = AbstractNodePayload.concatenatePaylods(
      targetNode.payload!!,
      childToHoist.payload!!,
    )
    childToHoist.resetPayload()
    targetNode.parent!!.replaceChild(
      targetNode,
      childToHoist,
      payload,
    )
    lazyAssert { targetNode.parent == null }
    targetNode.delete()
    SparTree.fixLeafLinkByDeleting(targetNode.beginToken!!, childToHoist.beginToken!!)
    SparTree.fixLeafLinkByDeleting(childToHoist.endToken!!.next!!, targetNode.endToken!!.next!!)
    childToHoist.parent?.let { SparTree.updateTokenIntervalUpToRoot(it) }
  }
}
