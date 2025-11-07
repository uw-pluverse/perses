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
package org.perses.reduction.reducer.token

import com.google.common.collect.ImmutableList
import org.perses.reduction.AbstractTokenReducer
import org.perses.reduction.EditTestPayload
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.reduction.TestScriptExecResult
import org.perses.reduction.TreeEditWithItsResult
import org.perses.spartree.LexerRuleSparTreeNode
import org.perses.spartree.NodeDeletionActionSet
import org.perses.spartree.SparTree
import org.perses.util.Util
import org.perses.util.toImmutableList
import org.perses.util.transformToImmutableList

class ConcurrentTokenSlicer(
  reducerContext: ReducerContext,
  reducerAnnotation: ConcurrentTokenSlicerAnnotation,
) : AbstractConcurrentTokenSlicer(
    reducerAnnotation,
    reducerContext,
  ) {
  override fun createSequenceOfIndependentSlicingTasks(
    tokenSlicingGranularity: Int,
    tree: SparTree,
  ): Sequence<ListOfIndependentSlicingTasks> {
    val tokens = tree.remainingLexerRuleNodes
    return sequenceOf(
      ListOfIndependentSlicingTasks(
        Util
          .slideReverseIfSlideable(
            tokens,
            slidingWindowSize = tokenSlicingGranularity,
          ).transformToImmutableList { sublist ->
            TokenSlicingTask(tokens, sublist.interval, tree)
          },
      ),
    )
  }

  inner class TokenSlicingTask(
    val tokens: ImmutableList<LexerRuleSparTreeNode>,
    val interval: Util.NonEmptyInternal,
    tree: SparTree,
  ) : AbstractSlicingTask(
      tree,
      reducerContext,
      this@ConcurrentTokenSlicer.executorService::testProgramAsync,
    ) {
    override fun tryAsyncRunPreconditionCheck(): Boolean =
      !tokens[interval.exclusiveEnd - 1].isPermanentlyDeleted

    override fun createNodeDeletionActionSet(): NodeDeletionActionSet =
      NodeDeletionActionSet.createByDeletingNodes(
        tokens.subList(interval.inclusiveStart, interval.exclusiveEnd),
        "token slicer@${interval.size()}",
      )

    override fun analyzeResultAndGetBest(
      futureResult: TestScriptExecResult<EditTestPayload>,
    ): TreeEditWithItsResult? =
      this@ConcurrentTokenSlicer.analyzeOneTestFutureAndGetBest(futureResult)
  }

  object CompositeReducerAnnotation : ReducerAnnotation(
    shortName = NAME_PREFIX,
    description = "",
    deterministic = true,
    reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE,
  ) {
    override fun create(reducerContext: ReducerContext): ImmutableList<AbstractTokenReducer> =
      REDUCER_ANNOTATIONS
        .asSequence()
        .flatMap { it.create(reducerContext) }
        .toImmutableList()
  }

  companion object {
    private const val NAME_PREFIX = "concurrent_token_slicer"

    val REDUCER_ANNOTATIONS =
      IntRange(start = 1, endInclusive = 14)
        .asSequence()
        .map { ConcurrentTokenSlicerAnnotation(granularity = it) }
        .toImmutableList()

    fun getAnnotationForGranularity(granularity: Int): ConcurrentTokenSlicerAnnotation =
      REDUCER_ANNOTATIONS.single {
        it.windowSize == granularity
      }
  }

  class ConcurrentTokenSlicerAnnotation internal constructor(
    granularity: Int,
  ) : AbstractTokenSlicerAnnotation(
      NAME_PREFIX,
      granularity,
      description = "concurrent token slicer",
    ) {
    override fun create(reducerContext: ReducerContext): ImmutableList<AbstractTokenReducer> =
      ImmutableList.of(ConcurrentTokenSlicer(reducerContext, this))
  }
}
