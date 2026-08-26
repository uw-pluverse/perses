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
import org.perses.reduction.AbstractSparTreeReducer
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.spartree.LexerRuleSparTreeNode
import org.perses.spartree.NodeDeletionActionSet
import org.perses.spartree.SparTree
import org.perses.util.CollectionUtil
import org.perses.util.toImmutableList

private typealias CanonicalLine = ImmutableList<LexerRuleSparTreeNode>

/**
 * The canonical-facade counterpart of [ConcurrentStateBasedLineSlicer]: it stays on the canonical
 * parser facade and groups the canonical tokens that share a source line into a unit via
 * [computeLines], instead of switching to the line grammar. This keeps a single consistent
 * canonical tree across reducers, at the cost of not being able to slice programs that the
 * canonical grammar cannot parse. It reuses [ConcurrentLineSlicingState].
 */
class CanonicalConcurrentStateBasedLineSlicer(
  reducerContext: ReducerContext,
  private val slicerAnnotation: CanonicalConcurrentStateLineSlicerAnnotation,
) : AbstractStateBasedConcurrentReducer<
    ConcurrentLineSlicingState,
    CanonicalLine,
  >(
    slicerAnnotation,
    reducerContext,
  ) {
  init {
    require(slicerAnnotation.granularity > 0) { "$slicerAnnotation" }
  }

  override val parseCheckNeeded: Boolean
    get() = true

  override fun createInputSequence(tree: SparTree): ImmutableList<CanonicalLine> =
    computeLines(tree.remainingLexerRuleNodes)

  // todo : improve efficiency. should avoid computeLines here.
  override fun getStateOnSuccess(
    tree: SparTree,
    state: ConcurrentLineSlicingState,
  ): ConcurrentLineSlicingState? {
    val lineSequenceSize = computeLines(tree.remainingLexerRuleNodes).size
    return state.advanceOnSuccess(lineSequenceSize)
  }

  // todo : improve efficiency. should avoid computeLines here.
  override fun createInitialState(tree: SparTree): ConcurrentLineSlicingState? {
    val lineSequenceSize = computeLines(tree.remainingLexerRuleNodes).size
    return ConcurrentLineSlicingState.create(slicerAnnotation.granularity, lineSequenceSize)
  }

  override fun computeNodeActionSet(
    state: ConcurrentLineSlicingState,
    sequence: ImmutableList<CanonicalLine>,
  ): NodeDeletionActionSet {
    val nodesToDelete =
      sequence
        .withIndex()
        .asSequence()
        .filter { it.index in state.startInclusive until state.endExclusive }
        .map { it.value }
        .flatMap { it.asSequence() }
        .toList()
    return NodeDeletionActionSet.createByDeletingNodes(
      nodesToDelete,
      "$NAME_PREFIX@${state.granularity}",
    )
  }

  object CompositeReducerAnnotation : ReducerAnnotation(
    shortName = NAME_PREFIX,
    description = "A canonical-facade concurrent state based line slicer",
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
    private const val NAME_PREFIX = "canonical_concurrent_state_line_slicer"

    fun computeLines(tokens: ImmutableList<LexerRuleSparTreeNode>): ImmutableList<CanonicalLine> =
      CollectionUtil.mergeContinuousElementsIntoRegions(tokens) { a, b ->
        a.token
          .asAntlrToken()
          .position.line ==
          b.token
            .asAntlrToken()
            .position.line
      }

    val REDUCER_ANNOTATIONS =
      IntRange(start = 1, endInclusive = 14)
        .asSequence()
        .map { CanonicalConcurrentStateLineSlicerAnnotation(NAME_PREFIX, granularity = it) }
        .toImmutableList()

    class CanonicalConcurrentStateLineSlicerAnnotation(
      private val namePrefix: String,
      val granularity: Int,
    ) : ReducerAnnotation(
        shortName = "$namePrefix@$granularity",
        description = "A canonical-facade concurrent state-based line slicer",
        deterministic = true,
        reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE,
      ) {
      init {
        require(granularity > 0)
      }

      override fun create(reducerContext: ReducerContext): ImmutableList<AbstractSparTreeReducer> =
        ImmutableList.of(CanonicalConcurrentStateBasedLineSlicer(reducerContext, this))

      override fun hashCode(): Int = Objects.hashCode(this::class.java, namePrefix, granularity)

      override fun equals(other: Any?): Boolean {
        if (other == null) {
          return false
        }
        if (other::class.java != this::class.java) {
          return false
        }
        val o = other as CanonicalConcurrentStateLineSlicerAnnotation
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
