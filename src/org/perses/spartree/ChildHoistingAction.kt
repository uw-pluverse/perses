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

import com.google.common.base.MoreObjects
import com.google.common.collect.ComparisonChain

class ChildHoistingAction(
  targetNode: AbstractSparTreeNode,
  val replacingChild: AbstractSparTreeNode
) : AbstractTreeEditAction(targetNode) {

  override fun internalCompareTo(o: AbstractTreeEditAction): Int {
    check(o is ChildHoistingAction)
    // TODO, refactor this with kotlin's comparator.
    return ComparisonChain.start()
      .compare(targetNode.nodeId, o.targetNode.nodeId)
      .compare(replacingChild.nodeId, o.replacingChild.nodeId)
      .result()
  }

  override val description: String
    get() = MoreObjects.toStringHelper(this)
      .add("target_node", targetNode.nodeId)
      .add("replacement", replacingChild.nodeId)
      .toString()

  override fun toString(): String {
    return MoreObjects.toStringHelper(this)
      .add("target", targetNode)
      .add("replacement", replacingChild)
      .toString()
  }
  override fun specificEquals(other: AbstractTreeEditAction): Boolean {
    if (other !is ChildHoistingAction) {
      return false
    }
    return other.replacingChild === replacingChild
  }

  override fun specificHashCode(): Int {
    return replacingChild.nodeId
  }
}
