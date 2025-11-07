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
package org.perses.reduction.reducer.lpr

import com.google.common.collect.ImmutableList
import org.perses.reduction.AbstractTokenReducer
import org.perses.reduction.ReducerContext

class LLMBasedFunctionInliningReducer(
  reducerContext: ReducerContext,
) : AbstractLLMBasedReducer(META, reducerContext) {
  override val primaryQuestion: String =
    """
    |Given the following program, identify all functions (other than the main function).
    |Please write the identified functions into a list.
    |If no function is identified, just give an empty list.
    """.trimMargin()

  override val followupQuestion: String =
    """
    |Given the following program and the specified function, optimize it out via function inlining.
    """.trimMargin()

  object META : AbstractLLMReducerAnnotation(
    shortName = NAME,
    description = "Invoke LLMs for function inlining.",
    reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_INCREASE,
  ) {
    override fun create(reducerContext: ReducerContext): ImmutableList<AbstractTokenReducer> =
      ImmutableList.of(LLMBasedFunctionInliningReducer(reducerContext))
  }

  companion object {
    const val NAME = "llm_based_function_inlining_reducer"
  }
}
