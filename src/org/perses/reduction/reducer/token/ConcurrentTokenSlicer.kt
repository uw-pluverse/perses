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
package org.perses.reduction.reducer.token

import com.google.common.collect.ImmutableList
import org.perses.reduction.AbstractTokenReducer
import org.perses.reduction.EditTestPayload
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.reduction.TestScriptExecResult
import org.perses.spartree.LexerRuleSparTreeNode
import org.perses.spartree.NodeDeletionActionSet
import org.perses.spartree.SparTree
import org.perses.util.Util
import org.perses.util.toImmutableList

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
  ): Sequence<IndependentSlicingTasks> {
    val tokens = tree.remainingLexerRuleNodes
    return sequenceOf(
      IndependentSlicingTasks(
        ImmutableList.builder<AbstractSlicingTask>().apply {
          Util.slideResverseIfSlidable(
            tokens,
            slidingWindowSize = tokenSlicingGranularity,
          ) { add(TokenSlicingTask(tokens, it, tree)) }
        }.build(),
      ),
    )
  }

  inner class TokenSlicingTask(
    val tokens: ImmutableList<LexerRuleSparTreeNode>,
    val interval: Util.NonEmptyInternal,
    tree: SparTree,
  ) : AbstractSlicingTask(
    tree,
    nodeActionSetCache,
    listenerManager,
    queryCache,
    ioManager,
    configuration,
    this@ConcurrentTokenSlicer.executorService::testProgramAsync,
  ) {

    override fun tryAsyncRunPreconditionCheck(): Boolean {
      return !tokens[interval.exclusiveEnd - 1].isPermanentlyDeleted
    }

    override fun createNodeDeletionActionSet(): NodeDeletionActionSet {
      return NodeDeletionActionSet.createByDeletingNodes(
        tokens.subList(interval.inclusiveStart, interval.exclusiveEnd),
        "token slicer@${interval.size()}",
      )
    }

    override fun analyzeResultsAndGetBest(
      futureResult: List<TestScriptExecResult<EditTestPayload>>,
    ) =
      this@ConcurrentTokenSlicer.analyzeResultsAndGetBest(futureResult)
  }

  companion object {

    private const val NAME_PREFIX = "concurrent_token_slicer"

    val REDUCER_ANNOTATIONS = IntRange(start = 1, endInclusive = 14)
      .asSequence()
      .map { ConcurrentTokenSlicerAnnotation(granularity = it) }
      .toImmutableList()

    fun getAnnotationForGranularity(granularity: Int): ConcurrentTokenSlicerAnnotation {
      return REDUCER_ANNOTATIONS.single { it.granularity == granularity }
    }

    val COMPOSITE_REDUCER = object : ReducerAnnotation(
      shortName = NAME_PREFIX,
      description = "",
      deterministic = true,
      reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE,
    ) {
      override fun create(reducerContext: ReducerContext): ImmutableList<AbstractTokenReducer> {
        return REDUCER_ANNOTATIONS
          .asSequence()
          .flatMap { it.create(reducerContext) }
          .toImmutableList()
      }
    }
  }

  class ConcurrentTokenSlicerAnnotation internal constructor(granularity: Int) :
    AbstractTokenSlicerAnnotation(
      NAME_PREFIX,
      granularity,
      description = "concurrent token slicer",
    ) {

    override fun create(reducerContext: ReducerContext): ImmutableList<AbstractTokenReducer> {
      return ImmutableList.of(ConcurrentTokenSlicer(reducerContext, this))
    }
  }
}
