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
package org.perses.reduction.reducer.vulcan.pattern

import com.google.common.collect.ImmutableList
import org.perses.listminimizer.localexhaust.CachedUniformLengthDeletionPatternSets
import org.perses.listminimizer.localexhaust.ElementEditPattern
import org.perses.listminimizer.localexhaust.EnumOperation
import org.perses.reduction.AbstractTokenReducer
import org.perses.reduction.EditTestPayload
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.reduction.TestScriptExecResult
import org.perses.reduction.reducer.token.AbstractConcurrentTokenSlicer
import org.perses.reduction.reducer.token.AbstractSlicingTask
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.NodeDeletionActionSet
import org.perses.spartree.SparTree
import org.perses.util.Util
import org.perses.util.toImmutableList

class LocalExhaustivePatternReducer internal constructor(
  patternReducerAnnotation: LocalExhaustivePatternReducerAnnotation,
  reducerContext: ReducerContext,
) : AbstractConcurrentTokenSlicer(patternReducerAnnotation, reducerContext) {
  constructor(reducerContext: ReducerContext) : this(
    LocalExhaustivePatternReducerAnnotation(
      reducerContext.configuration.vulcanConfig.windowSizeForLocalExhaustivePatternReduction,
    ),
    reducerContext,
  )

  private val deletionPatternSet =
    CachedUniformLengthDeletionPatternSets
      .getDeletionPatternSet(
        patternReducerAnnotation.windowSize,
      ).interestingPatternsInDescendingOfNumOfDeletes

  override fun createSequenceOfIndependentSlicingTasks(
    tokenSlicingGranularity: Int,
    tree: SparTree,
  ): Sequence<ListOfIndependentSlicingTasks> =
    computeSequenceOfCandidateNodesToSlideThrough(tree, tokenSlicingGranularity)
      .map { nodeList ->
        val list =
          Util
            .slideReverseIfSlideable(
              nodeList,
              slidingWindowSize = tokenSlicingGranularity,
            ).flatMap { sublist ->
              val interval = sublist.interval
              check(interval.size() == tokenSlicingGranularity)
              deletionPatternSet.map { deletionPattern ->
                TokenPatternDeleteTask(
                  tree,
                  nodeList,
                  interval.inclusiveStart,
                  deletionPattern,
                )
              }
            }.toImmutableList()
        ListOfIndependentSlicingTasks(list)
      }

  object META : ReducerAnnotation(
    shortName = NAME_PREFIX,
    description =
      "traverse all the sets that contain a fixed number (pattern size) of " +
        "consecutive nodes in each level of the parse tree, " +
        "and try all possible patterns of deletions.",
    deterministic = true,
    reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE,
  ) {
    override fun create(reducerContext: ReducerContext): ImmutableList<AbstractTokenReducer> =
      ImmutableList.of(LocalExhaustivePatternReducer(reducerContext))
  }

  companion object {
    internal const val NAME_PREFIX = "token_pattern_reducer"

    internal fun computeSequenceOfCandidateNodesToSlideThrough(
      tree: SparTree,
      slidingWindowSize: Int,
    ): Sequence<ImmutableList<AbstractSparTreeNode>> =
      sequence {
        var nodesInCurrentLevel = tree.realRoot.immutableChildView.toImmutableList()
        if (nodesInCurrentLevel.size > slidingWindowSize) {
          yield(nodesInCurrentLevel)
        }
        while (nodesInCurrentLevel.any { !it.isTokenNode() && !it.isPermanentlyDeleted }) {
          val remainNodes = nodesInCurrentLevel.filter { !it.isPermanentlyDeleted }
          val previousNodeCount = remainNodes.size
          nodesInCurrentLevel =
            ImmutableList
              .builder<AbstractSparTreeNode>()
              .apply {
                remainNodes.forEach {
                  if (it.isTokenNode()) {
                    add(it)
                  } else {
                    addAll(it.immutableChildView)
                  }
                }
              }.build()
          val nodeCount = nodesInCurrentLevel.size
          check(nodeCount >= previousNodeCount) {
            "nodeCount=$nodeCount previousNodeCount=$previousNodeCount"
          }
          if (nodeCount > slidingWindowSize && nodeCount > previousNodeCount) {
            yield(nodesInCurrentLevel)
          }
        }
      }
  }

  // The code can be merged with [TokenSlicingTask]
  inner class TokenPatternDeleteTask(
    tree: SparTree,
    nodeList: ImmutableList<out AbstractSparTreeNode>,
    startIndex: Int,
    private val tokenEditPattern: ElementEditPattern,
  ) : AbstractSlicingTask(
      tree,
      reducerContext,
      this@LocalExhaustivePatternReducer.executorService::testProgramAsync,
    ) {
    init {
      require(tokenEditPattern.numOfDeletes > 0)
      val patternLength = tokenEditPattern.patternLength
      require(startIndex + patternLength <= nodeList.size)
    }

    private val nodesToEdit =
      nodeList
        .subList(
          startIndex,
          startIndex + tokenEditPattern.patternLength,
        ).onEach { assert(!it.isPermanentlyDeleted) }

    private val actionSet =
      run {
        val operations = tokenEditPattern.operations
        assert(nodesToEdit.size == operations.size)
        val builder = NodeDeletionActionSet.Builder("token_pattern_$tokenEditPattern")
        nodesToEdit.zip(operations).forEach {
          if (it.second == EnumOperation.DELETE) {
            builder.deleteNode(it.first)
          }
        }
        builder.build()
      }

    override fun tryAsyncRunPreconditionCheck(): Boolean =
      nodesToEdit.all { !it.isPermanentlyDeleted }

    override fun createNodeDeletionActionSet(): NodeDeletionActionSet = actionSet

    override fun analyzeResultAndGetBest(futureResult: TestScriptExecResult<EditTestPayload>) =
      this@LocalExhaustivePatternReducer
        .analyzeOneTestFutureAndGetBest(futureResult)
  }
}
