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
import org.perses.listminimizer.EnumListMinimizerType
import org.perses.reduction.AbstractSparTreeReducer
import org.perses.reduction.FixpointReductionState
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.spartree.ContextDescription

/**
 * The canonical-facade counterpart of [LineBasedTokenSlicer]: it stays on the canonical parser
 * facade and groups the canonical tokens that share a source line into a unit via [computeLines],
 * instead of switching to the line grammar. This keeps a single consistent canonical tree across
 * reducers, at the cost of not being able to slice programs that the canonical grammar cannot parse.
 */
class CanonicalLineBasedTokenSlicer(
  reducerContext: ReducerContext,
) : AbstractSparTreeReducer(META, reducerContext) {
  override fun computeDefaultListMinimizerType(): EnumListMinimizerType =
    EnumListMinimizerType.WINDOWED_SLICER

  override fun internalReduce(fixpointReductionState: FixpointReductionState) {
    val tree = fixpointReductionState.inputRepresentation.tree
    val lines =
      CanonicalLineBasedConcurrentTokenSlicer.computeLines(tree.remainingLexerRuleNodes)
    runListMinimizerOverListsOfNodes(
      needToTestEmpty = true,
      tree = tree,
      fixpointReductionState = fixpointReductionState,
      input = lines,
      actionsDescriptionPostfix = ContextDescription.of("ReduceLines"),
      specifiedMinimizerType = null,
    )
  }

  object META : ReducerAnnotation(
    shortName = NAME,
    description = "",
    deterministic = true,
    reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE,
  ) {
    override fun create(reducerContext: ReducerContext): ImmutableList<AbstractSparTreeReducer> =
      ImmutableList.of(CanonicalLineBasedTokenSlicer(reducerContext))
  }

  companion object {
    const val NAME = "canonical_sequential_line_slicer"
  }
}
