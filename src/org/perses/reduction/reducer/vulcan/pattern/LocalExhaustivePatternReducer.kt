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
package org.perses.reduction.reducer.vulcan.pattern

import com.google.common.collect.ImmutableList
import com.google.common.flogger.FluentLogger
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
import org.perses.util.toImmutableMap

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

  private val patternSet = getDeletionPatterns(patternReducerAnnotation.patternSize)

  override fun createSequenceOfIndependentSlicingTasks(
    tokenSlicingGranularity: Int,
    tree: SparTree,
  ): Sequence<IndependentSlicingTasks> {
    return computeSequenceOfCandidateNodesToSlideThrough(tree, tokenSlicingGranularity)
      .map { nodeList ->
        val tasksBuilder = ImmutableList.builder<AbstractSlicingTask>()
        Util.slideResverseIfSlidable(
          nodeList,
          slidingWindowSize = tokenSlicingGranularity,
        ) { interval ->
          check(interval.size() == tokenSlicingGranularity)
          patternSet.patternsInUseDescending.forEach { edit ->
            tasksBuilder.add(
              TokenPatternDeleteTask(
                tree,
                nodeList,
                interval.inclusiveStart,
                edit,
              ),
            )
          }
        }
        IndependentSlicingTasks(tasksBuilder.build())
      }
  }

  companion object {
    internal const val NAME_PREFIX = "token_pattern_reducer"

    val META = object : ReducerAnnotation(
      shortName = NAME_PREFIX,
      description = "traverse all the sets that contain a fixed number (pattern size) of " +
        "consecutive nodes in each level of the parse tree, " +
        "and try all possible patterns of deletions.",
      deterministic = true,
      reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE,
    ) {
      override fun create(reducerContext: ReducerContext): ImmutableList<AbstractTokenReducer> {
        return ImmutableList.of(LocalExhaustivePatternReducer(reducerContext))
      }
    }

    private val PATTERNS = (3..6).asSequence()
      .map { it to NumOfDeletesToPatterns.createDeletionPatterns(totalNumberOfOperations = it) }
      .toImmutableMap()

    internal fun computeSequenceOfCandidateNodesToSlideThrough(
      tree: SparTree,
      slicingGranularity: Int,
    ): Sequence<ImmutableList<AbstractSparTreeNode>> {
      return sequence {
        var nodesInCurrentLevel = tree.root.immutableChildView.toImmutableList()
        if (nodesInCurrentLevel.size > slicingGranularity) {
          yield(nodesInCurrentLevel)
        }
        while (nodesInCurrentLevel.any { !it.isTokenNode && !it.isPermanentlyDeleted }) {
          val remainNodes = nodesInCurrentLevel.filter { !it.isPermanentlyDeleted }
          val previousNodeCount = remainNodes.size
          nodesInCurrentLevel = ImmutableList.builder<AbstractSparTreeNode>().apply {
            remainNodes.forEach {
              if (it.isTokenNode) {
                add(it)
              } else {
                addAll(it.immutableChildView)
              }
            }
          }.build()
          val nodeCount = nodesInCurrentLevel.size
          check(nodeCount >= previousNodeCount)
          if (nodeCount > slicingGranularity && nodeCount > previousNodeCount) {
            yield(nodesInCurrentLevel)
          }
        }
      }
    }

    fun getDeletionPatterns(patternLength: Int): NumOfDeletesToPatterns {
      return requireNotNull(PATTERNS[patternLength])
    }

    private val logger = FluentLogger.forEnclosingClass()
  }

  // The code can be merged with [TokenSlicingTask]
  inner class TokenPatternDeleteTask(
    tree: SparTree,
    private val nodeList: ImmutableList<out AbstractSparTreeNode>,
    private val startIndex: Int,
    private val tokenEditPattern: TokenEditPattern,
  ) : AbstractSlicingTask(
    tree,
    nodeActionSetCache,
    listenerManager,
    queryCache,
    ioManager,
    configuration,
    this@LocalExhaustivePatternReducer.executorService::testProgramAsync,
  ) {

    init {
      require(tokenEditPattern.numOfDeletes > 0)
      val patternLength = tokenEditPattern.patternLength
      require(startIndex + patternLength <= nodeList.size)
    }

    private val nodesToEdit = nodeList.subList(
      startIndex,
      startIndex + tokenEditPattern.patternLength,
    ).onEach { assert(!it.isPermanentlyDeleted) }

    private val actionSet = run {
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

    override fun tryAsyncRunPreconditionCheck(): Boolean {
      return nodesToEdit.all { !it.isPermanentlyDeleted }
    }

    override fun createNodeDeletionActionSet(): NodeDeletionActionSet {
      return actionSet
    }

    override fun analyzeResultsAndGetBest(
      futureResult: List<TestScriptExecResult<EditTestPayload>>,
    ) = this@LocalExhaustivePatternReducer.analyzeResultsAndGetBest(futureResult)
  }
}
