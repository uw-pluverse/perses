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
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.spartree.LexerRuleSparTreeNode
import org.perses.spartree.NodeDeletionActionSet
import org.perses.spartree.SparTree

class ConcurrentStateBasedDeltaReducer(
  reducerContext: ReducerContext,
) : AbstractStateBasedConcurrentReducer<ConcurrentDeltaDebuggingState, LexerRuleSparTreeNode>(
  META,
  reducerContext,
) {

  override val parseCheckNeeded: Boolean
    get() = false

  override fun createInputSequence(tree: SparTree): ImmutableList<LexerRuleSparTreeNode> {
    return tree.remainingLexerRuleNodes
  }

  override fun createInitialState(tree: SparTree): ConcurrentDeltaDebuggingState? {
    return ConcurrentDeltaDebuggingState.create(tree.tokenCount)
  }

  override fun getStateOnSuccess(
    tree: SparTree,
    state: ConcurrentDeltaDebuggingState,
  ): ConcurrentDeltaDebuggingState? {
    return state.advanceOnSuccess(tree.tokenCount)
  }

  override fun computeNodeActionSet(
    state: ConcurrentDeltaDebuggingState,
    sequence: ImmutableList<LexerRuleSparTreeNode>,
  ): NodeDeletionActionSet {
    val nodesToDelete = sequence.subList(state.index, state.end)
    return NodeDeletionActionSet.createByDeletingNodes(
      nodesToDelete,
      "$NAME@chunk${state.chunkSize}",
    )
  }

  companion object {

    const val NAME = "concurrent_state_ddmin"

    @JvmStatic
    val META = object : ReducerAnnotation(
      shortName = NAME,
      description = "A parallel ddmin",
      deterministic = true,
      reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE,
    ) {
      override fun create(reducerContext: ReducerContext): ImmutableList<AbstractTokenReducer> {
        return ImmutableList.of(ConcurrentStateBasedDeltaReducer(reducerContext))
      }
    }
  }
}

data class ConcurrentDeltaDebuggingState(
  val index: Int,
  val chunkSize: Int,
  private val tokenSize: Int,
) : IConcurrentState<ConcurrentDeltaDebuggingState> {

  val end: Int
    get() = minOf(index + chunkSize, tokenSize)

  fun realChunk() = end - index

  override fun advance(): ConcurrentDeltaDebuggingState? {
    var nextIndex = index + chunkSize
    var nextChunkSize = chunkSize
    if (nextIndex >= tokenSize) {
      nextChunkSize /= 2
      if (nextChunkSize < 1) {
        return null
      }
      nextIndex = 0
    }
    return this.copy(index = nextIndex, chunkSize = nextChunkSize, tokenSize = tokenSize)
  }

  override fun advanceOnSuccess(newSequenceSize: Int): ConcurrentDeltaDebuggingState? {
    if (newSequenceSize == 0) {
      return null
    }
    val newState = this.copy(index = index, chunkSize = chunkSize, tokenSize = newSequenceSize)
    return if (newState.index >= newState.tokenSize) {
      newState.advance()
    } else {
      newState
    }
  }

  companion object {
    fun create(sequenceSize: Int): ConcurrentDeltaDebuggingState? {
      if (sequenceSize == 0) {
        return null
      }
      return ConcurrentDeltaDebuggingState(0, sequenceSize, sequenceSize)
    }
  }
}
