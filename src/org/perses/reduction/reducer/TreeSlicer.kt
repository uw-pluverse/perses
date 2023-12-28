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
package org.perses.reduction.reducer

import com.google.common.collect.ImmutableList
import org.perses.program.printer.PrinterRegistry
import org.perses.reduction.AbstractTokenReducer
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.NodeDeletionActionSet
import org.perses.spartree.SparTree

class TreeSlicer(
  reducerContext: ReducerContext,
) : AbstractNodeReducer(
  reducerAnnotation = META,
  reducerContext = reducerContext,
  reductionQueueStrategy = IReductionQueueStrategy.FOR_REGULAR_QUEUE,
  requiresParsableTree = false,
) {

  override fun reduceOneNode(
    tree: SparTree,
    node: AbstractSparTreeNode,
  ): ImmutableList<AbstractSparTreeNode> {
    val actionSet = NodeDeletionActionSet.createByDeleteSingleNode(node, NAME)

    if (nodeActionSetCache.isCachedOrCacheIt(actionSet)) {
      listenerManager.onNodeEditActionSetCacheHit(actionSet)
      return node.copyAndReverseChildren()
    }
    val treeEdit = tree.createNodeDeletionEdit(actionSet)
    val testProgram = treeEdit.program
    val parserFacade = configuration.parserFacade
    if (testProgram.tokenCount() <= 150 &&
      !parserFacade.isSourceCodeParsable(
        PrinterRegistry.getPrinter(ioManager.getDefaultProgramFormat())
          .print(testProgram).sourceCode,
      )
    ) {
      // TODO: dynamically change the threshold, rather than this hard coded 150.
      return node.copyAndReverseChildren()
    }
    val best = testAllTreeEditsAndReturnTheBest(ImmutableList.of(treeEdit))
    return if (best == null) {
      node.copyAndReverseChildren()
    } else {
      tree.applyEdit(best.edit)
      computePendingNodes(node, best.edit).reverse()
    }
  }

  companion object {
    const val NAME = "tree_slicer"

    @JvmStatic
    val META = object : ReducerAnnotation(
      shortName = NAME,
      description = "",
      deterministic = true,
      reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE,
    ) {
      override fun create(
        reducerContext: ReducerContext,
      ): ImmutableList<AbstractTokenReducer> = ImmutableList.of(TreeSlicer(reducerContext))
    }
  }
}
