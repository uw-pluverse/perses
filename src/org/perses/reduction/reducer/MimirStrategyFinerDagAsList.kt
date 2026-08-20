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
import org.perses.reduction.semantics.SccGraph
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.NodeDeletionActionSet

class MimirStrategyFinerDagAsList : MimirStrategyFineDagAsList() {
  override fun internalLayerBasedReduce(
    context: MimirReductionContext,
    layersFromTopToBottom: ImmutableList<ImmutableList<SccGraph>>,
  ) {
    super.internalLayerBasedReduce(context, layersFromTopToBottom)
    val layerCount = layersFromTopToBottom.size
    if (layerCount < 2) {
      return
    }
    val condensationGraph = context.depGraph.sccCondensationGraph
    sweepZeroedSccs(layersFromTopToBottom, condensationGraph) { nodes ->
      context.testAndApplyDeletionEditIfInteresting(
        NodeDeletionActionSet.createByDeletingNodes(
          nodes,
          context.commonPostfix.createByAppending("ZeroedSccSweeping").toString(),
        ),
        context.tree,
      )
    }
  }

  fun sweepZeroedSccs(
    layersFromTopToBottom: ImmutableList<ImmutableList<SccGraph>>,
    condensationGraph: org.jgrapht.Graph<SccGraph, org.jgrapht.graph.DefaultEdge>,
    testAndApplyDeletion: (
      nodes: Iterable<AbstractSparTreeNode>,
    ) -> AbstractSparTreeReducer.EditApplicationResult,
  ) {
    for (scc in layersFromTopToBottom.last()) {
      if (scc.vertexSet().all { it.isPermanentlyDeleted }) {
        condensationGraph.removeVertex(scc)
      }
    }
    val layerCount = layersFromTopToBottom.size
    for (layerIndex in layerCount - 2 downTo 0) {
      val layer = layersFromTopToBottom[layerIndex]
      for (scc in layer) {
        val remainingTreeNodes =
          scc.vertexSet().filter {
            !it.isPermanentlyDeleted
          }
        if (remainingTreeNodes.isEmpty()) {
          condensationGraph.removeVertex(scc)
          continue
        }
        val outdegree = condensationGraph.outDegreeOf(scc)
        if (outdegree != 0) {
          continue
        }
        val result = testAndApplyDeletion(remainingTreeNodes)
        if (result == AbstractSparTreeReducer.EditApplicationResult.APPLIED) {
          condensationGraph.removeVertex(scc)
        }
      }
    }
  }
}
