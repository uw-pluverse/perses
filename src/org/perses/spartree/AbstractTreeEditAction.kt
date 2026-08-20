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

import com.google.common.base.MoreObjects

/** The base class for editing a tree.  */
sealed class AbstractTreeEditAction : Comparable<AbstractTreeEditAction> {
  override fun compareTo(other: AbstractTreeEditAction): Int {
    val classCmp =
      compareBy<AbstractTreeEditAction> {
        it::class.java.canonicalName
      }.compare(this, other)
    return if (classCmp != 0) {
      classCmp
    } else {
      check(this::class.java == other::class.java)
      internalCompareTo(other)
    }
  }

  protected abstract fun internalCompareTo(o: AbstractTreeEditAction): Int

  abstract val conciseDescription: String

  final override fun toString(): String =
    MoreObjects.toStringHelper(this).addValue(conciseDescription).toString()

  abstract override fun equals(other: Any?): Boolean

  abstract override fun hashCode(): Int

  abstract fun apply()
}

abstract class AbstractTargetedTreeEditAction(
  val targetNode: AbstractSparTreeNode,
) : AbstractTreeEditAction() {
  private var used = false

  override fun apply() {
    check(!used)
    used = true
    internalApply()
  }

  abstract fun internalApply()

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
    val otherAction = other as AbstractTargetedTreeEditAction
    return if (targetNode !== otherAction.targetNode) {
      false
    } else {
      specificEquals(otherAction)
    }
  }

  protected abstract fun specificEquals(other: AbstractTargetedTreeEditAction): Boolean

  override fun hashCode(): Int =
    31 * specificHashCode() + targetNode.nodeId + javaClass.hashCode() * 31 * 31

  protected abstract fun specificHashCode(): Int
}
