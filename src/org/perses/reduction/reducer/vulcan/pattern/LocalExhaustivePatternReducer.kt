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
package org.perses.reduction.reducer.vulcan.pattern

import com.google.common.collect.ImmutableList
import org.perses.listminimizer.EnumListMinimizerType
import org.perses.listminimizer.localexhaust.CachedUniformLengthDeletionPatternSets
import org.perses.reduction.AbstractSparTreeReducer
import org.perses.reduction.FixpointReductionState
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.ContextDescription
import org.perses.spartree.SparTree
import org.perses.util.toImmutableList

class LocalExhaustivePatternReducer(
  reducerContext: ReducerContext,
) : AbstractSparTreeReducer(META, reducerContext) {
  private val windowSize =
    reducerContext.configuration.vulcanConfig.windowSizeForLocalExhaustivePatternReduction

  init {
    // Lower bound comes from LocalExhaustMinimizerArguments (window size must be > 2); upper bound
    // is the largest pattern set the enumeration is precomputed for.
    require(
      windowSize in MIN_WINDOW_SIZE..CachedUniformLengthDeletionPatternSets.MAX_PATTERN_LENGTH,
    ) {
      "The local-exhaustive pattern window size must be in " +
        "[$MIN_WINDOW_SIZE, ${CachedUniformLengthDeletionPatternSets.MAX_PATTERN_LENGTH}], " +
        "but got $windowSize."
    }
  }

  override fun computeDefaultListMinimizerType(): EnumListMinimizerType =
    EnumListMinimizerType.LOCAL_EXHAUSTIVE_PATTERN_ENUMERATION

  override fun internalReduce(fixpointReductionState: FixpointReductionState) {
    val tree = fixpointReductionState.inputRepresentation.tree
    computeSequenceOfCandidateNodesToSlideThrough(tree, windowSize).forEach { levelNodes ->
      runListMinimizerOverNodes(
        needToTestEmpty = false,
        tree = tree,
        input = levelNodes,
        fixpointReductionState = fixpointReductionState,
        actionsDescriptionPostfix = ContextDescription.of(NAME_PREFIX),
      )
    }
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
    override fun create(reducerContext: ReducerContext): ImmutableList<AbstractSparTreeReducer> =
      ImmutableList.of(LocalExhaustivePatternReducer(reducerContext))
  }

  companion object {
    internal const val NAME_PREFIX = "token_pattern_reducer"

    private const val MIN_WINDOW_SIZE = 3

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
}
