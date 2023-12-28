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
package org.perses.reduction.reducer

import com.google.common.collect.ImmutableList
import org.perses.reduction.AbstractTokenReducer
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext

/** Perses node reducer, with dfs delta debugging  */
object PersesNodeDfsReducer {

  const val NAME = "perses_node_with_dfs_delta"

  @JvmField
  val META: ReducerAnnotation = object : ReducerAnnotation(
    shortName = NAME,
    description = "",
    deterministic = true,
    reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE,
  ) {
    override fun create(reducerContext: ReducerContext) = ImmutableList.of<AbstractTokenReducer>(
      PersesNodeReducer(
        this,
        reducerContext,
        AbstractNodeReducer.IReductionQueueStrategy.FOR_REGULAR_QUEUE,
      ),
    )
  }
}
