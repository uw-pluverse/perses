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
package org.perses.antlr.atn.nfa

import org.jgrapht.Graph
import org.jgrapht.traverse.BreadthFirstIterator

abstract class AbstractNFABasedOnJGraphT(
  protected val graph: Graph<PersesATNState, Edge>,
) : AbstractNFA() {

  override fun containsState(state: PersesATNState): Boolean {
    return graph.containsVertex(state)
  }

  override fun edgeSequence() = graph.edgeSet().asSequence()
  override fun getSourceState(edge: Edge): PersesATNState {
    return graph.getEdgeSource(edge)!!
  }

  override fun getTargetState(edge: Edge): PersesATNState {
    return graph.getEdgeTarget(edge)!!
  }

  override fun getOutgoingEdgesOf(sourceState: PersesATNState): Set<Edge> =
    graph.outgoingEdgesOf(sourceState)

  override fun outDegreeOf(state: PersesATNState) = graph.outDegreeOf(state)
  override fun printGraph(): String {
    val result = StringBuilder()
    val iterator = BreadthFirstIterator(graph, startState)
    while (iterator.hasNext()) {
      val vertex = iterator.next()
      result.append(getLabelForState(vertex)).append('\n')
      graph.outgoingEdgesOf(vertex).forEach { edge ->
        result.append("    ").append(edge.toString()).append("--->")
          .append(getLabelForState(graph.getEdgeTarget(edge))).append('\n')
      }
    }
    return result.toString()
  }

  override fun stateSequence(): Sequence<PersesATNState> {
    return graph.vertexSet().asSequence()
  }
}
