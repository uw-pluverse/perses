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
import org.perses.reduction.AbstractSparTreeReducer
import org.perses.reduction.FixpointReductionState
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.spartree.ContextDescription

class LineBasedTokenSlicer(
  reducerContext: ReducerContext,
) : AbstractSparTreeReducer(META, reducerContext) {
  override fun getPreferredParserFacade(): AbstractParserFacade = LineParserFacade()

  override fun computeDefaultListMinimizerType(): EnumListMinimizerType =
    EnumListMinimizerType.WINDOWED_SLICER

  override fun internalReduce(fixpointReductionState: FixpointReductionState) {
    val tree = fixpointReductionState.inputRepresentation.tree
    // The line parser facade lexes each line into a single token, so every remaining lexer node is
    // a whole line and can be minimized directly.
    runListMinimizerOverNodes(
      needToTestEmpty = true,
      tree = tree,
      input = tree.remainingLexerRuleNodes,
      fixpointReductionState = fixpointReductionState,
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
      ImmutableList.of(LineBasedTokenSlicer(reducerContext))
  }

  companion object {
    const val NAME = "sequential_line_slicer"
  }
}
