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

import com.google.common.annotations.VisibleForTesting
import com.google.common.collect.ImmutableList
import org.perses.listminimizer.EnumListMinimizerType
import org.perses.reduction.AbstractSparTreeReducer
import org.perses.reduction.FixpointReductionState
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.spartree.ContextDescription
import org.perses.spartree.LexerRuleSparTreeNode
import org.perses.spartree.NodeDeletionActionSet
import org.perses.util.Util.lazyAssert
import org.perses.util.shell.ExitCode

class TokenSlicer(
  reducerContext: ReducerContext,
) : AbstractSparTreeReducer(META, reducerContext) {
  override fun computeDefaultListMinimizerType(): EnumListMinimizerType =
    EnumListMinimizerType.WINDOWED_SLICER

  override fun internalReduce(fixpointReductionState: FixpointReductionState) {
    val tree = fixpointReductionState.inputRepresentation.tree
    runListMinimizerOverNodes(
      needToTestEmpty = true,
      tree = tree,
      fixpointReductionState = fixpointReductionState,
      input = tree.remainingLexerRuleNodes,
      actionsDescriptionPostfix = ContextDescription.of("ReducingAllTokens"),
    )
  }

  object META : ReducerAnnotation(
    shortName = NAME,
    description = "",
    deterministic = true,
    reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE,
  ) {
    override fun create(reducerContext: ReducerContext): ImmutableList<AbstractSparTreeReducer> =
      ImmutableList.of(TokenSlicer(reducerContext))
  }

  companion object {
    const val NAME = "token_slicer"

    @VisibleForTesting
    val INVALID_SYNTAX_EXIT_CODE = ExitCode(99)

    @VisibleForTesting
    fun createNodeDeletionActionSetReverse(
      tokenList: List<LexerRuleSparTreeNode>,
      inclusiveEndIndex: Int,
      tokenCountToDelete: Int,
    ): NodeDeletionActionSet {
      val inclusiveStartIndex = inclusiveEndIndex - tokenCountToDelete + 1
      check(inclusiveStartIndex >= 0) { inclusiveStartIndex }
      val subList = tokenList.subList(inclusiveStartIndex, inclusiveEndIndex + 1)
      subList.forEach {
        lazyAssert({ !it.isPermanentlyDeleted }) { it }
      }
      return NodeDeletionActionSet.createByDeletingNodes(
        subList,
        "token slicer@$tokenCountToDelete",
      )
    }
  }
}
