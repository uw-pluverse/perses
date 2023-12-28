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
package org.perses.ppr.diff.tree

import com.google.common.collect.ImmutableList
import org.perses.reduction.AbstractTokenReducer
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.reduction.reducer.PersesNodeReducer
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.SparTree
import java.util.Queue

/** Perses node reducer, with dfs delta debugging, only reduce specified nodes  */
class CustomizedTreeNodesReducer(
  reducerAnnotation: ReducerAnnotation,
  reducerContext: ReducerContext,
  private val startNodes: List<AbstractSparTreeNode>,
) : PersesNodeReducer(
  reducerAnnotation,
  reducerContext,
  reductionQueueStrategy = IReductionQueueStrategy.FOR_PRIORITY_QUEUE,
) {

  override fun initializeReductionQueue(queue: Queue<AbstractSparTreeNode>, tree: SparTree) {
    queue.addAll(startNodes)
  }

  companion object {
    const val NAME = "customized_tree_diff_node_reducer"

    class ExtendedReducerAnnotation(private val startNodes: ImmutableList<AbstractSparTreeNode>) :
      ReducerAnnotation(
        shortName = NAME,
        description = "",
        deterministic = true,
        reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE,
      ) {
      override fun create(reducerContext: ReducerContext) = ImmutableList.of<AbstractTokenReducer>(
        CustomizedTreeNodesReducer(reducerAnnotation = this, reducerContext, startNodes),
      )
    }
  }
}
