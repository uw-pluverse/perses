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

class NodeDeletionAction(
  targetNode: AbstractSparTreeNode,
) : AbstractTargetedTreeEditAction(targetNode) {
  override fun internalCompareTo(o: AbstractTreeEditAction): Int {
    require(o is NodeDeletionAction)
    return targetNode.nodeId.compareTo(o.targetNode.nodeId)
  }

  override val conciseDescription: String
    get() = "delete_${targetNode.nodeId}"

  override fun specificEquals(other: AbstractTargetedTreeEditAction): Boolean =
    other.javaClass == javaClass

  override fun specificHashCode(): Int = 0

  override fun internalApply() {
    // TODO: Move this check to deletion action set
    if (targetNode.isPermanentlyDeleted) {
      return
    }
    val parentNode = targetNode.parent
    if (targetNode.leafNodeSequence().none()) {
      // the target node contains no children, then just simply remove this node
      check(targetNode.beginToken == null) { targetNode.printTreeStructure() }
      check(targetNode.endToken == null) { targetNode.printTreeStructure() }
    } else {
      val deletionRegionLeftInclusive =
        targetNode.beginToken
          ?: error("No begin token for the node " + targetNode.printTreeStructure())
      val deletionRegionRightExclusive =
        targetNode.endToken?.next
          ?: error("No end token for the node " + targetNode.printTreeStructure())
      SparTree.fixLeafLinkByDeleting(
        deletionRegionLeftInclusive = deletionRegionLeftInclusive,
        deletionRegionRightExclusive = deletionRegionRightExclusive,
      )
    }
    targetNode.delete()
    if (parentNode != null) {
      parentNode.cleanDeletedImmediateChildren()
      SparTree.updateTokenIntervalUpToRoot(parentNode)
    }
  }
}
