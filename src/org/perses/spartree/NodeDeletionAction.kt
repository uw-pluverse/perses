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

class NodeDeletionAction(
  targetNode: AbstractSparTreeNode,
) : AbstractTreeEditAction(targetNode) {

  override fun internalCompareTo(o: AbstractTreeEditAction): Int {
    require(o is NodeDeletionAction)
    return targetNode.nodeId.compareTo(o.targetNode.nodeId)
  }

  override val description: String
    get() = MoreObjects.toStringHelper(this).add("target_node", targetNode.nodeId).toString()

  override fun specificEquals(other: AbstractTreeEditAction): Boolean {
    return other.javaClass == javaClass
  }

  override fun specificHashCode(): Int {
    return 0
  }

  override fun internalApply() {
    // TODO: Move this check to deletion action set
    if (targetNode.isPermanentlyDeleted) {
      return
    }
    targetNode.delete()
    SparTree.fixLeafLinkByDeleting(targetNode.beginToken!!, targetNode.endToken!!.next!!)
    val parentNode = targetNode.parent
    if (parentNode != null) {
      parentNode.cleanDeletedImmediateChildren()
      SparTree.updateTokenIntervalUpToRoot(parentNode)
    }
  }
}
