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
import org.perses.reduction.FixpointReductionState
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.reduction.reducer.token.TokenSlicer.Companion.createNodeDeletionActionSetReverse
import org.perses.reduction.reducer.token.TokenSlicer.Companion.extractLexerRuleNodes
import org.perses.spartree.LexerRuleSparTreeNode
import org.perses.spartree.NodeDeletionActionSet
import org.perses.spartree.SparTree

class MassiveConcurrentTokenSlicer(
  reducerContext: ReducerContext,
  val minSlicingGranularity: Int,
  val maxSlicingGranularity: Int,
) : AbstractTokenReducer(META, reducerContext) {

  init {
    require(minSlicingGranularity in 1..maxSlicingGranularity) {
      "0 < minTokenCount($minSlicingGranularity) <= maxTokneCount($maxSlicingGranularity)."
    }
  }

  // TODO: This algorithm need to be parallelized.
  override fun internalReduce(fixpointReductionState: FixpointReductionState) {
    for (tokenSlicingGranularity in maxSlicingGranularity downTo minSlicingGranularity) {
      sliceTreeForGivenGranularity(fixpointReductionState, tokenSlicingGranularity)
    }
  }

  private fun sliceTreeForGivenGranularity(
    fixpointReductionState: FixpointReductionState,
    tokenSlicingGranularity: Int,
  ) {
    val tree = fixpointReductionState.sparTree
    val tokens = extractLexerRuleNodes(tree)
    val slicingStartEvent = fixpointReductionState
      .fixpointIterationStartEvent
      .createTokenSlicingStartEvent(
        currentTimeMillis = System.currentTimeMillis(),
        programSize = tree.programSnapshot.tokenCount(),
        tokenSlicingGranularity = tokenSlicingGranularity,
      )
    listenerManager.onSlicingTokensStart(slicingStartEvent)
    val slicingTasks = ImmutableList.builder<SlicingTask>().apply {
      for (startIndex in tokens.size - 1 downTo tokenSlicingGranularity - 1) {
        add(
          SlicingTask(
            tokens,
            startIndex,
            tokenSlicingGranularity,
            tree,
          ),
        )
      }
    }.build()

    SlicingTaskConcurrentExecutor<SlicingTask>(
      slicingTasks,
      workingDequeExpectedSize = executorService.specifiedNumOfThreads + 2,
    ).run()

    val slicingEndEvent = slicingStartEvent.createEndEvent(
      currentTimeMillis = System.currentTimeMillis(),
      programSize = tree.programSnapshot.tokenCount(),
    )
    listenerManager.onSlicingTokensEnd(slicingEndEvent)
  }

  inner class SlicingTask(
    val tokens: ImmutableList<LexerRuleSparTreeNode>,
    val startIndex: Int,
    val tokenSlicingGranularity: Int,
    tree: SparTree,
  ) : AbstractSlicingTask(
    tree,
    nodeActionSetCache,
    listenerManager,
    queryCache,
    configuration,
    this@MassiveConcurrentTokenSlicer.executorService::testProgramAsync,
  ) {

    override fun tryAsyncRunPreconditionCheck(): Boolean {
      return !tokens[startIndex].isPermanentlyDeleted
    }

    override fun createNodeDeletionActionSet(): NodeDeletionActionSet {
      return createNodeDeletionActionSetReverse(
        tokens,
        startIndex,
        tokenSlicingGranularity,
      )
    }

    override fun analyzeResultsAndGetBest(
      futureResult: List<EditTestPayload>,
    ) =
      this@MassiveConcurrentTokenSlicer.analyzeResultsAndGetBest(futureResult)
  }

  companion object {

    const val NAME = "massive_concurrent_token_slicer"

    @JvmStatic
    val META = object : ReducerAnnotation() {

      override val deterministic: Boolean
        get() = true

      override fun shortName() = NAME

      override val reductionResultSizeTrend: ReductionResultSizeTrend
        get() = ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE

      override fun description() = ""

      override fun create(reducerContext: ReducerContext) =
        ImmutableList.of<AbstractTokenReducer>(
          MassiveConcurrentTokenSlicer(
            reducerContext,
            minSlicingGranularity = 1,
            maxSlicingGranularity = 14,
          ),
        )
    }
  }
}
