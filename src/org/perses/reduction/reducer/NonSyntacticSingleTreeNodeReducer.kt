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
package org.perses.reduction.reducer

import com.google.common.collect.ImmutableList
import org.perses.reduction.AbstractSparTreeReducer
import org.perses.reduction.FixpointReductionState
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.reduction.semantics.ISemanticsProvider
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.ContextDescription
import org.perses.spartree.SparTree
import org.perses.util.toImmutableList

class NonSyntacticSingleTreeNodeReducer(
  reducerContext: ReducerContext,
) : AbstractNodeReducer(
    reducerAnnotation = META,
    reducerContext = reducerContext,
    reductionQueueStrategy = IReductionQueueStrategy.FOR_REGULAR_QUEUE,
  ) {
  override fun reduceOneNode(
    tree: SparTree,
    node: AbstractSparTreeNode,
    semanticsProvider: ISemanticsProvider?,
    fixpointReductionState: FixpointReductionState,
  ): ImmutableList<AbstractSparTreeNode> {
    runListMinimizerOverNodes(
      needToTestEmpty = true,
      tree = tree,
      fixpointReductionState = fixpointReductionState,
      input = node.immutableChildView.toImmutableList(),
      actionsDescriptionPostfix = ContextDescription.of("ReduceEachChildNodeSeparately"),
    )
    node.cleanDeletedImmediateChildren()
    return node.immutableChildView.asReversed().toImmutableList()
  }

  object META : ReducerAnnotation(
    shortName = NAME,
    description = "",
    deterministic = true,
    reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE,
  ) {
    override fun create(reducerContext: ReducerContext): ImmutableList<AbstractSparTreeReducer> =
      ImmutableList.of(NonSyntacticSingleTreeNodeReducer(reducerContext))
  }

  companion object {
    const val NAME = "tree_slicer"
  }
}
