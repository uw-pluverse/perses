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

class LlmBasedDataTypeSimplificationReducer(
  reducerContext: ReducerContext,
) : AbstractLlmBasedReducer(META, reducerContext) {
  override val primaryQuestion: String =
    """
    |In programming, primary data types typically include int, float, short, unsigned, char, etc.
    |Conversely, complex data types typically include structures, classes, arrays, pointers, etc.
    |Please identify all variables with complex data types.
    |Please write the identified variables into a list: [a list of variable names].
    |If no data type is identified, just give an empty list.
    """.trimMargin()

  override val followupQuestion: String =
    """
    |Given the following program and the variable in complex data type,
    |decompose the it into variables with primary data type.
    """.trimMargin()

  object META : AbstractLlmReducerAnnotation(
    shortName = NAME,
    description = "Invoke LLMs for data type simplification.",
    reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_INCREASE,
  ) {
    override fun create(reducerContext: ReducerContext): ImmutableList<AbstractSparTreeReducer> =
      ImmutableList.of(LlmBasedDataTypeSimplificationReducer(reducerContext))
  }

  companion object {
    const val NAME = "llm_based_data_type_simplification_reducer"
  }
}
