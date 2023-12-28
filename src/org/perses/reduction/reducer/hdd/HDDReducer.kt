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
package org.perses.reduction.reducer.hdd

import com.google.common.collect.ImmutableList
import org.perses.delta.xfs.Partition
import org.perses.reduction.AbstractTokenReducer
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.reduction.reducer.TreeTransformations.createNodeDeletionActionSetFor
import org.perses.spartree.AbstractSparTreeEdit
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.SparTree

/** Implementation of the original HDD algorithm.  */
class HDDReducer(reducerContext: ReducerContext) :
  AbstractLevelBasedReducer(META, reducerContext) {

  override fun createTreeEditListByDisablingPartition(
    partition: Partition<AbstractSparTreeNode>,
    tree: SparTree,
  ): List<AbstractSparTreeEdit<*>> {
    val actionSet = createNodeDeletionActionSetFor(partition, "HDD")
    if (nodeActionSetCache.isCachedOrCacheIt(actionSet)) {
      listenerManager.onNodeEditActionSetCacheHit(actionSet)
      return emptyList()
    }
    return ImmutableList.of(tree.createNodeDeletionEdit(actionSet))
  }

  companion object {
    const val NAME = "hdd"

    @JvmField
    val META: ReducerAnnotation = object : ReducerAnnotation(
      shortName = NAME,
      description = "A variant of HDD.",
      deterministic = true,
      reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE,
    ) {
      override fun create(reducerContext: ReducerContext): ImmutableList<AbstractTokenReducer> {
        return ImmutableList.of(HDDReducer(reducerContext))
      }
    }
  }
}
