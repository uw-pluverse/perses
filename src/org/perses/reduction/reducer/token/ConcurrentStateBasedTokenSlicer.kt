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

import com.google.common.base.Objects
import com.google.common.collect.ImmutableList
import org.perses.reduction.AbstractTokenReducer
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.spartree.LexerRuleSparTreeNode
import org.perses.spartree.NodeDeletionActionSet
import org.perses.spartree.SparTree
import org.perses.util.toImmutableList

class ConcurrentStateBasedTokenSlicer(
  reducerContext: ReducerContext,
  private val slicerAnnotation: ConcurrentStateTokenSlicerAnnotation,
) : AbstractStateBasedConcurrentReducer<ConcurrentTokenSlicingState, LexerRuleSparTreeNode>(
  slicerAnnotation,
  reducerContext,
) {

  init {
    require(slicerAnnotation.granularity > 0) { "$slicerAnnotation" }
  }

  override val parseCheckNeeded: Boolean
    get() = true

  override fun createInputSequence(tree: SparTree): ImmutableList<LexerRuleSparTreeNode> {
    return tree.remainingLexerRuleNodes
  }

  override fun createInitialState(tree: SparTree): ConcurrentTokenSlicingState? {
    return ConcurrentTokenSlicingState.create(slicerAnnotation.granularity, tree.tokenCount)
  }

  override fun getStateOnSuccess(
    tree: SparTree,
    state: ConcurrentTokenSlicingState,
  ): ConcurrentTokenSlicingState? {
    return state.advanceOnSuccess(tree.tokenCount)
  }

  override fun computeNodeActionSet(
    state: ConcurrentTokenSlicingState,
    sequence: ImmutableList<LexerRuleSparTreeNode>,
  ): NodeDeletionActionSet {
    val nodesToDelete = sequence.subList(state.startInclusive, state.endExclusive)
    return NodeDeletionActionSet.createByDeletingNodes(
      nodesToDelete,
      "concurrent_state_token_slicer@${state.granularity}",
    )
  }

  companion object {

    private const val NAME_PREFIX = "concurrent_state_token_slicer"

    val REDUCER_ANNOTATIONS = IntRange(start = 1, endInclusive = 14)
      .asSequence()
      .map { ConcurrentStateTokenSlicerAnnotation(NAME_PREFIX, granularity = it) }
      .toImmutableList()

    fun getAnnotationForGranularity(granularity: Int): ConcurrentStateTokenSlicerAnnotation {
      return REDUCER_ANNOTATIONS.single { it.granularity == granularity }
    }

    val COMPOSITE_REDUCER = object : ReducerAnnotation(
      shortName = NAME_PREFIX,
      description = "A concurrent state-based token slicer",
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

  class ConcurrentStateTokenSlicerAnnotation(
    private val namePrefix: String,
    val granularity: Int,
  ) : ReducerAnnotation(
    shortName = "$namePrefix@$granularity",
    description = "A concurrent state-based token slicer",
    deterministic = true,
    reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE,
  ) {

    init {
      require(granularity > 0)
    }

    override fun create(reducerContext: ReducerContext): ImmutableList<AbstractTokenReducer> {
      return ImmutableList.of(ConcurrentStateBasedTokenSlicer(reducerContext, this))
    }

    override fun hashCode(): Int {
      return Objects.hashCode(this::class.java, namePrefix, granularity)
    }

    override fun equals(other: Any?): Boolean {
      if (other == null) {
        return false
      }
      if (other::class.java != this::class.java) {
        return false
      }
      val o = other as ConcurrentStateTokenSlicerAnnotation
      if (namePrefix != o.namePrefix) {
        return false
      }
      if (granularity != o.granularity) {
        return false
      }
      return true
    }
  }
}

data class ConcurrentTokenSlicingState(
  val startInclusive: Int,
  val granularity: Int,
  private val tokenSize: Int,
) : IConcurrentState<ConcurrentTokenSlicingState> {

  val endExclusive: Int = minOf(startInclusive + granularity, tokenSize)

  override fun advance(): ConcurrentTokenSlicingState? {
    if (endExclusive >= tokenSize) {
      return null
    }
    return ConcurrentTokenSlicingState(startInclusive + 1, granularity, tokenSize)
  }

  override fun advanceOnSuccess(newSequenceSize: Int): ConcurrentTokenSlicingState? {
    if (newSequenceSize == 0 || endExclusive >= tokenSize) {
      return null
    }
    // because the token at `startInclusive` is deleted,
    // token slicer should start from the same index
    // to avoid missing tokens.
    return ConcurrentTokenSlicingState(startInclusive, granularity, newSequenceSize)
  }

  companion object {
    fun create(granularity: Int, sequenceSize: Int): ConcurrentTokenSlicingState? {
      if (sequenceSize == 0 || granularity >= sequenceSize) {
        return null
      }
      return ConcurrentTokenSlicingState(0, granularity, sequenceSize)
    }
  }
}
