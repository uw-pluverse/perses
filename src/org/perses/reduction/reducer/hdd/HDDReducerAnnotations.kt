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
package org.perses.reduction.reducer.hdd

import com.google.common.collect.ImmutableList
import org.perses.reduction.AbstractSparTreeReducer
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext

/** Implementation of the original HDD algorithm.  */
class HDDReducerAnnotations {
  object Hdd : ReducerAnnotation(
    shortName = "hdd",
    description = "A variant of HDD.",
    deterministic = true,
    reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE,
  ) {
    override fun create(reducerContext: ReducerContext): ImmutableList<AbstractSparTreeReducer> =
      ImmutableList.of(
        LevelBasedReducer(
          reducerAnnotation = this,
          reducerContext = reducerContext,
          enableMimir = false,
        ),
      )
  }

  object HddWithMimir : ReducerAnnotation(
    shortName = "hdd-mimir",
    description = "A variant of HDD with Mimir enabled.",
    deterministic = true,
    reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE,
  ) {
    override fun create(reducerContext: ReducerContext): ImmutableList<AbstractSparTreeReducer> =
      ImmutableList.of(
        LevelBasedReducer(
          reducerAnnotation = this,
          reducerContext = reducerContext,
          enableMimir = true,
        ),
      )
  }
}
