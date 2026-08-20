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
package org.perses.reduction.reducer.lpr

import com.google.common.collect.ImmutableList
import org.perses.reduction.AbstractSparTreeReducer
import org.perses.reduction.ReducerContext

class LlmBasedDataTypeEliminationReducer(
  reducerContext: ReducerContext,
) : AbstractLlmBasedReducer(META, reducerContext) {
  override val primaryQuestion: String =
    """
    |Given the following program, identify all redundant data types 
    |(e.g., a data type defined by the programmer via typedef).
    |Please write the identified data type into a list.
    |If no data type is identified, just give an empty list.
    """.trimMargin()

  override val followupQuestion: String =
    """
    |Given the following program and the specified data type, eliminate it,
    |and substitute every instance of it with its associated original data type.
    """.trimMargin()

  object META : AbstractLlmReducerAnnotation(
    shortName = NAME,
    description = "Invoke LLMs for data type elimination.",
    reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_INCREASE,
  ) {
    override fun create(reducerContext: ReducerContext): ImmutableList<AbstractSparTreeReducer> =
      ImmutableList.of(LlmBasedDataTypeEliminationReducer(reducerContext))
  }

  companion object {
    const val NAME = "llm_based_data_type_elimination_reducer"
  }
}
