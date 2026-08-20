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

import com.google.common.base.Objects
import com.google.common.collect.ImmutableList
import org.perses.grammar.AbstractParserFacade
import org.perses.grammar.line.LineParserFacade
import org.perses.reduction.AbstractSparTreeReducer
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.spartree.LexerRuleSparTreeNode
import org.perses.spartree.NodeDeletionActionSet
import org.perses.spartree.SparTree
import org.perses.util.toImmutableList

class ConcurrentStateBasedLineSlicer(
  reducerContext: ReducerContext,
  private val slicerAnnotation: ConcurrentStateLineSlicerAnnotation,
) : AbstractStateBasedConcurrentReducer<
    ConcurrentLineSlicingState,
    LexerRuleSparTreeNode,
  >(
    slicerAnnotation,
    reducerContext,
  ) {
  init {
    require(slicerAnnotation.granularity > 0) { "$slicerAnnotation" }
  }

  // The line grammar can lex any program, so this slicer does not require the canonical facade to
  // be able to parse the candidate program.
  override val parseCheckNeeded: Boolean
    get() = false

  override fun getPreferredParserFacade(): AbstractParserFacade = LineParserFacade()

  override fun createInputSequence(tree: SparTree): ImmutableList<LexerRuleSparTreeNode> =
    tree.remainingLexerRuleNodes

  override fun getStateOnSuccess(
    tree: SparTree,
    state: ConcurrentLineSlicingState,
  ): ConcurrentLineSlicingState? = state.advanceOnSuccess(tree.remainingLexerRuleNodes.size)

  override fun createInitialState(tree: SparTree): ConcurrentLineSlicingState? =
    ConcurrentLineSlicingState.create(
      slicerAnnotation.granularity,
      tree.remainingLexerRuleNodes.size,
    )

  override fun computeNodeActionSet(
    state: ConcurrentLineSlicingState,
    sequence: ImmutableList<LexerRuleSparTreeNode>,
  ): NodeDeletionActionSet {
    val nodesToDelete =
      sequence
        .withIndex()
        .asSequence()
        .filter { it.index in state.startInclusive until state.endExclusive }
        .map { it.value }
        .toList()
    return NodeDeletionActionSet.createByDeletingNodes(
      nodesToDelete,
      "$NAME_PREFIX@${state.granularity}",
    )
  }

  object CompositeReducerAnnotation : ReducerAnnotation(
    shortName = NAME_PREFIX,
    description = "A concurrent state based line slicer",
    deterministic = true,
    reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE,
  ) {
    override fun create(reducerContext: ReducerContext): ImmutableList<AbstractSparTreeReducer> =
      REDUCER_ANNOTATIONS
        .asSequence()
        .flatMap { it.create(reducerContext) }
        .toImmutableList()
  }

  companion object {
    private const val NAME_PREFIX = "concurrent_state_line_slicer"

    val REDUCER_ANNOTATIONS =
      IntRange(start = 1, endInclusive = 14)
        .asSequence()
        .map { ConcurrentStateLineSlicerAnnotation(NAME_PREFIX, granularity = it) }
        .toImmutableList()

    class ConcurrentStateLineSlicerAnnotation(
      private val namePrefix: String,
      val granularity: Int,
    ) : ReducerAnnotation(
        shortName = "$namePrefix@$granularity",
        description = "A concurrent state-based line slicer",
        deterministic = true,
        reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE,
      ) {
      init {
        require(granularity > 0)
      }

      override fun create(reducerContext: ReducerContext): ImmutableList<AbstractSparTreeReducer> =
        ImmutableList.of(ConcurrentStateBasedLineSlicer(reducerContext, this))

      override fun hashCode(): Int = Objects.hashCode(this::class.java, namePrefix, granularity)

      override fun equals(other: Any?): Boolean {
        if (other == null) {
          return false
        }
        if (other::class.java != this::class.java) {
          return false
        }
        val o = other as ConcurrentStateLineSlicerAnnotation
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
}

data class ConcurrentLineSlicingState(
  val startInclusive: Int,
  val granularity: Int,
  private val lineSize: Int,
) : IConcurrentState<ConcurrentLineSlicingState> {
  val endExclusive: Int
    get() = minOf(startInclusive + granularity, lineSize)

  override fun advance(): ConcurrentLineSlicingState? {
    if (endExclusive >= lineSize) {
      return null
    }
    return ConcurrentLineSlicingState(startInclusive + 1, granularity, lineSize)
  }

  override fun advanceOnSuccess(newSequenceSize: Int): ConcurrentLineSlicingState? {
    if (newSequenceSize == 0 || endExclusive >= lineSize) {
      return null
    }
    return ConcurrentLineSlicingState(startInclusive, granularity, newSequenceSize)
  }

  companion object {
    fun create(
      granularity: Int,
      sequenceSize: Int,
    ): ConcurrentLineSlicingState? {
      if (sequenceSize == 0 || granularity >= sequenceSize) {
        return null
      }
      return ConcurrentLineSlicingState(0, granularity, sequenceSize)
    }
  }
}
