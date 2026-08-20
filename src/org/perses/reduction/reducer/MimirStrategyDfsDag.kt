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

import org.jgrapht.traverse.TopologicalOrderIterator
import org.perses.reduction.semantics.SccGraph
import org.perses.spartree.NodeDeletionActionSet
import org.perses.util.toImmutableList

class MimirStrategyDfsDag : AbstractMimirStrategy() {
  override fun internalReduce(context: MimirReductionContext) {
    val sccCondensationGraph = context.depGraph.sccCondensationGraph

    val topologicalSortedSCCs = TopologicalOrderIterator(sccCondensationGraph).asSequence().toList()
    for (scc: SccGraph in topologicalSortedSCCs) {
      val allAllNodesInSccDeleted = scc.vertexSet().all { it.isPermanentlyDeleted }
      if (allAllNodesInSccDeleted) {
        continue
      }
      val forwardReachableSCCs =
        context.depGraph
          .getForwardReachableNodesFrom(scc)
          .flatMap { it.vertexSet().filter { vertex -> !(vertex.isPermanentlyDeleted) } }
          .toImmutableList()
      if (forwardReachableSCCs.isEmpty()) {
        continue
      }
      context.testAndApplyDeletionEditIfInteresting(
        NodeDeletionActionSet.createByDeletingNodes(
          forwardReachableSCCs,
          context.commonPostfix.createByAppending("DfsDag").toString(),
        ),
        context.tree,
      )
    }
    if (context.mimirConfig.mimirReductionAlgorithm.deleteShadowing) {
      val input =
        sccCondensationGraph
          .vertexSet()
          .asSequence()
          .filter { scc ->
            sccCondensationGraph.outDegreeOf(scc) != 0 || scc.vertexSet().size > 1
          }.flatMap { it.vertexSet().filter { vertex -> !vertex.isPermanentlyDeleted } }
          .toImmutableList()
      reduceShadowingVariableDefinitionsForcibly(context, input)
    }
  }
}
