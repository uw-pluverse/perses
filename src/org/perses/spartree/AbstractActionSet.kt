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
import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableSet
import org.perses.util.lazyAssert
import org.perses.util.toImmutableMap

sealed class AbstractActionSet<ACTION : AbstractTreeEditAction>(
  val actions: ImmutableList<ACTION>,
  // TODO(cnsun): use ActionDescription here.
  val contextDescription: String,
  canBeSorted: Boolean,
  // The bare name of the transformation that produced this edit, so every edit is attributable in the
  // statistics. For reducers with named sub-transformations it is that name (astra: the transformation
  // class; latra: the definition name); otherwise it is the edit's operation kind (e.g. "Deletion",
  // "Replacement"), supplied as the factory default of each action-set type. It is required (never
  // null) so no edit can be left untracked. The owning reducer's name is added by the statistics
  // listener to form a "<reducer>.<transformation>" key, so only the bare name is carried here.
  val transformationName: String,
) {
  init {
    if (canBeSorted) {
      checkSortedAndDistinct(actions)
    }
  }

  open val structureDescription: String
    get() =
      buildString {
        actions.joinTo(this, separator = ",", prefix = "[", postfix = "]") {
          it.conciseDescription
        }
      }

  final override fun toString(): String =
    MoreObjects.toStringHelper(this).addValue(structureDescription).toString()

  abstract val targets: ImmutableSet<AbstractSparTreeNode>

  abstract fun containsNodeAsTarget(node: AbstractSparTreeNode): Boolean

  abstract fun getActionForTarget(targetNode: AbstractSparTreeNode): ACTION?

  fun size(): Int = actions.size

  val isEmpty: Boolean
    get() = actions.isEmpty()

  val isNotEmpty: Boolean = !isEmpty

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

  override fun hashCode(): Int = actions.hashCode()

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

abstract class TargetedActionSet<ACTION : AbstractTargetedTreeEditAction>(
  actions: ImmutableList<ACTION>,
  contextDescription: String,
  canBeSorted: Boolean,
  transformationName: String,
) : AbstractActionSet<ACTION>(
    actions = actions,
    contextDescription = contextDescription,
    canBeSorted = canBeSorted,
    transformationName = transformationName,
  ) {
  private val targetToActionMap =
    actions.toImmutableMap(keyFunc = { it.targetNode }, valueFunc = { it!! })

  init {
    lazyAssert { actions.size == targetToActionMap.size }
  }

  override val targets: ImmutableSet<AbstractSparTreeNode>
    get() = targetToActionMap.keys

  override fun containsNodeAsTarget(node: AbstractSparTreeNode): Boolean =
    targetToActionMap.containsKey(node)

  override fun getActionForTarget(targetNode: AbstractSparTreeNode): ACTION? =
    targetToActionMap[targetNode]
}
