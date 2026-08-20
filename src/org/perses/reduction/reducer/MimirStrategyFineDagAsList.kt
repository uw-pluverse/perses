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
import org.perses.reduction.semantics.SccGraph
import org.perses.spartree.AbstractSparTreeNode

open class MimirStrategyFineDagAsList : AbstractLayerBasedMimirStrategy() {
  override fun internalLayerBasedReduce(
    context: MimirReductionContext,
    layersFromTopToBottom: ImmutableList<ImmutableList<SccGraph>>,
  ) {
    val input =
      computeInput(layersFromTopToBottom, context)
    context.runListMinimizerOverListsOfNodes(
      false,
      context.tree,
      input,
      context.fixpointReductionState,
      context.commonPostfix.createByAppending("FineDagAsList"),
      context.testWhetherToUseADifferentMinimizerIfInputIsSmall(input),
    )
  }

  fun computeInput(
    layersFromTopToBottom: ImmutableList<ImmutableList<SccGraph>>,
    context: MimirReductionContext,
  ): ImmutableList<ImmutableList<AbstractSparTreeNode>> {
    val depGraph = context.depGraph
    val parentsOfNodesInDepGraph = depGraph.allNodes.mapNotNull { it.parent }.toSet()
    val result = ImmutableList.builder<ImmutableList<AbstractSparTreeNode>>()
    for (layer in layersFromTopToBottom) {
      for (scc in layer) {
        val vertexSet = scc.vertexSet()
        for (node in vertexSet) {
          result.add(getConcreteUsesForDef(node, depGraph, parentsOfNodesInDepGraph))
        }
      }
    }
    return result.build()
  }
}
