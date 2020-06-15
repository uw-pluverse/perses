/*
 * Copyright (C) 2003-2017 Chengnian Sun.
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
package org.perses.reduction.reducer

import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.tree.spar.AbstractSparTreeNode
import java.util.PriorityQueue
import java.util.Queue

/** Perses node reducer, with bfs delta debugging  */
class PersesNodePrioritizedBfsReducer
protected constructor(reducerContext: ReducerContext) :
  PersesNodeBfsReducer(META, reducerContext) {
  override fun createReductionQueue(): Queue<AbstractSparTreeNode> {
    return PriorityQueue(
      DEFAULT_INITIAL_QUEUE_CAPACITY, TreeNodeComparatorInLeafTokenCount.SINGLETON
    )
  }

  companion object {
    const val NAME = "perses_node_priority_with_bfs_delta"
    @JvmField
    val META: ReducerAnnotation = object : ReducerAnnotation() {
      override fun shortName() = NAME

      override fun description() = ""

      override fun create(reducerContext: ReducerContext) =
        PersesNodePrioritizedBfsReducer(reducerContext)
    }
  }
}
