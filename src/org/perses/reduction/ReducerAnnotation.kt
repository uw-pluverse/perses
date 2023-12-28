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
package org.perses.reduction

import com.google.common.collect.ImmutableList

fun interface ITokenReducerCreator {

  fun create(reducerContext: ReducerContext): ImmutableList<AbstractTokenReducer>
}

/** Annotation for a reducer.  */
// TODO: test the equals and hashcode function.
abstract class ReducerAnnotation(
  shortName: String,
  description: String,
  val deterministic: Boolean,
  val reductionResultSizeTrend: ReductionResultSizeTrend,
) : AbstractReducerNameAndDesc(shortName, description), ITokenReducerCreator {

  enum class ReductionResultSizeTrend {
    BEST_RESULT_SIZE_INCREASE,
    BEST_RESULT_SIZE_REMAIN,
    BEST_RESULT_SIZE_DECREASE,
  }
}
