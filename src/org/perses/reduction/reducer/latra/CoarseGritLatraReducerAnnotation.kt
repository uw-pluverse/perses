/*
 * Copyright (C) 2018-2025 University of Waterloo.
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
package org.perses.reduction.reducer.latra

import com.google.common.collect.ImmutableList
import org.perses.program.AbstractDataKind
import org.perses.reduction.AbstractNonDeletionBasedReducer
import org.perses.reduction.AbstractTokenReducer
import org.perses.reduction.ReducerContext

object CoarseGritLatraReducerAnnotation :
  AbstractNonDeletionBasedReducer.NonDeletionBasedReducerAnnotation(
    shortName = "CoarseGritLatraReducer",
    description = "Perform coarse-grit language-specific program transformations",
    reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE,
  ) {
  private val transformationListMap = TransformationRegistry.coarseGritTransformations

  fun isLanguageSupported(language: AbstractDataKind): Boolean =
    transformationListMap.containsKey(language)

  override fun create(reducerContext: ReducerContext): ImmutableList<AbstractTokenReducer> =
    ImmutableList.of(
      DefaultLatraReducer(
        reducerAnnotation = this,
        reducerContext = reducerContext,
        language2transformationListMap = transformationListMap,
        enforceStrictlyMonotonicSizeDecrease = true,
      ),
    )
}
