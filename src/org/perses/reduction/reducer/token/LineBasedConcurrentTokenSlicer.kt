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
package org.perses.reduction.reducer.token

import com.google.common.collect.ImmutableList
import org.perses.grammar.AbstractParserFacade
import org.perses.grammar.line.LineParserFacade
import org.perses.listminimizer.EnumListMinimizerType
import org.perses.listminimizer.WindowedSlicerSpecificArguments
import org.perses.reduction.AbstractSparTreeReducer
import org.perses.reduction.FixpointReductionState
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.spartree.ContextDescription
import org.perses.util.toImmutableList

/**
 * Slices whole lines with a fixed sliding-window size (the annotation's granularity). Under the line
 * parser facade every remaining lexer node is a whole line, so it delegates to the windowed slicer
 * in the list-minimizer framework -- which runs concurrently when more than one thread is available
 * -- and the [CompositeReducerAnnotation] runs one such reducer per granularity.
 */
class LineBasedConcurrentTokenSlicer(
  reducerContext: ReducerContext,
  private val slicerAnnotation: LineBasedConcurrentTokenSlicerAnnotation,
) : AbstractSparTreeReducer(slicerAnnotation, reducerContext) {
  override fun getPreferredParserFacade(): AbstractParserFacade = LineParserFacade()

  override fun computeDefaultListMinimizerType(): EnumListMinimizerType =
    EnumListMinimizerType.WINDOWED_SLICER

  override fun computeWindowedSlicerArguments(): WindowedSlicerSpecificArguments =
    WindowedSlicerSpecificArguments(
      minSlidingWindowSize = slicerAnnotation.windowSize,
      maxSlidingWindowSize = slicerAnnotation.windowSize,
    )

  override fun internalReduce(fixpointReductionState: FixpointReductionState) {
    val tree = fixpointReductionState.inputRepresentation.tree
    runListMinimizerOverNodes(
      needToTestEmpty = false,
      tree = tree,
      input = tree.remainingLexerRuleNodes,
      fixpointReductionState = fixpointReductionState,
      actionsDescriptionPostfix = ContextDescription.of(NAME_PREFIX),
    )
  }

  object CompositeReducerAnnotation : ReducerAnnotation(
    shortName = NAME_PREFIX,
    description = "",
    deterministic = true,
    reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE,
  ) {
    override fun create(reducerContext: ReducerContext): ImmutableList<AbstractSparTreeReducer> =
      REDUCER_ANNOTATIONS
        .asSequence()
        .flatMap { it.create(reducerContext) }
        .toImmutableList()
  }

  companion object {
    private const val NAME_PREFIX = "line_based_concurrent_token_slicer"

    val REDUCER_ANNOTATIONS =
      IntRange(start = 1, endInclusive = 14)
        .asSequence()
        .map { LineBasedConcurrentTokenSlicerAnnotation(granularity = it) }
        .toImmutableList()
  }

  class LineBasedConcurrentTokenSlicerAnnotation internal constructor(
    granularity: Int,
  ) : AbstractTokenSlicerAnnotation(
      NAME_PREFIX,
      granularity,
      description = "line-based concurrent token slicer",
    ) {
    override fun create(reducerContext: ReducerContext): ImmutableList<AbstractSparTreeReducer> =
      ImmutableList.of(LineBasedConcurrentTokenSlicer(reducerContext, this))
  }
}
