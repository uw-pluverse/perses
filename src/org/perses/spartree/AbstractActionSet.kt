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

import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableSet
import org.perses.util.Util.lazyAssert
import org.perses.util.toImmutableMap

sealed class AbstractActionSet<ACTION : AbstractTreeEditAction>(
  val actions: ImmutableList<ACTION>,
  val actionsDescription: String,
  canBeSorted: Boolean,
) {

  private val targetToActionMap = actions
    .asSequence()
    .toImmutableMap(keyFunc = { it.targetNode }, valueFunc = { it!! })

  init {
    if (canBeSorted) {
      checkSortedAndDistinct(actions)
    }
    lazyAssert { actions.size == targetToActionMap.size }
    lazyAssert { actions.size > 0 }
  }

  val targets: ImmutableSet<AbstractSparTreeNode>
    get() = targetToActionMap.keys

  fun containsNodeAsTarget(node: AbstractSparTreeNode): Boolean {
    return targetToActionMap.containsKey(node)
  }

  fun getActionForTarget(targetNode: AbstractSparTreeNode): ACTION? {
    return targetToActionMap[targetNode]!!
  }

  fun size(): Int {
    return actions.size
  }

  val isEmpty: Boolean
    get() = actions.isEmpty()

  override fun equals(other: Any?): Boolean {
    if (other == null) {
      return false
    }
    if (other === this) {
      return true
    }
    if (other !is AbstractActionSet<*>) {
      return false
    }
    return actions == other.actions
  }

  override fun hashCode(): Int {
    return actions.hashCode()
  }

  private fun checkSortedAndDistinct(actions: ImmutableList<ACTION>) {
    val size = actions.size
    if (size <= 1) {
      return
    }
    for (i in 1 until size) {
      val cmp = actions[i - 1]!!.compareTo(actions[i])
      check(cmp < 0) {
        "i-1=${actions[i - 1]}, i=${actions[i]}"
      }
    }
    return
  }
}
