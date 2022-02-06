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

/** The base class for editing a tree.  */
abstract class AbstractTreeEditAction protected constructor(
  val targetNode: AbstractSparTreeNode
) : Comparable<AbstractTreeEditAction> {

  override fun compareTo(other: AbstractTreeEditAction): Int {
    return internalCompareTo(other)
  }

  protected abstract fun internalCompareTo(o: AbstractTreeEditAction): Int
  abstract val description: String

  override fun toString(): String {
    return description
  }

  override fun equals(other: Any?): Boolean {
    if (other == null) {
      return false
    }
    if (other === this) {
      return true
    }
    if (javaClass != other.javaClass) {
      return false
    }
    val otherAction = other as AbstractTreeEditAction
    return if (targetNode !== otherAction.targetNode) {
      false
    } else specificEquals(otherAction)
  }

  protected abstract fun specificEquals(other: AbstractTreeEditAction): Boolean

  override fun hashCode(): Int {
    return 31 * specificHashCode() + targetNode.nodeId
  }

  protected abstract fun specificHashCode(): Int
}
