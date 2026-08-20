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
package org.perses.antlr.atn.nfa

import org.jgrapht.Graph
import org.jgrapht.alg.connectivity.KosarajuStrongConnectivityInspector
import org.jgrapht.graph.MaskSubgraph
import org.jgrapht.traverse.BreadthFirstIterator
import java.util.function.Predicate

abstract class AbstractNfaBasedOnJGraphT(
  protected val graph: Graph<PersesATNState, Edge>,
) : AbstractNfa() {
  override fun containsState(state: PersesATNState): Boolean = graph.containsVertex(state)

  /**
   * Whether the NFA has a directed cycle that consumes at least one character,
   * i.e. a cycle containing at least one non-epsilon edge. (A cycle formed only
   * of epsilon edges does not count.) Computed as: some strongly connected
   * component contains a non-epsilon edge. For a trimmed NFA this is exactly the
   * condition for the accepted language to be infinite.
   */
  fun hasInputConsumingCycle(): Boolean =
    KosarajuStrongConnectivityInspector(graph)
      .stronglyConnectedComponents
      .any { component -> component.edgeSet().any { !it.isEpsilon } }

  /** The states reachable from [start] by following only epsilon edges. */
  fun epsilonClosureOf(start: PersesATNState): Set<PersesATNState> {
    val epsilonOnlyGraph =
      MaskSubgraph(graph, Predicate<PersesATNState> { false }, Predicate<Edge> { !it.isEpsilon })
    return BreadthFirstIterator(epsilonOnlyGraph, start).asSequence().toSet()
  }

  override fun edgeSequence() = graph.edgeSet().asSequence()

  override fun getSourceState(edge: Edge): PersesATNState = graph.getEdgeSource(edge)!!

  override fun getTargetState(edge: Edge): PersesATNState = graph.getEdgeTarget(edge)!!

  override fun getOutgoingEdgesOf(sourceState: PersesATNState): Set<Edge> =
    graph.outgoingEdgesOf(sourceState)

  override fun containsEdge(edge: Edge): Boolean = graph.containsEdge(edge)

  override fun outDegreeOf(state: PersesATNState) = graph.outDegreeOf(state)

  override fun printGraph(): String {
    val result = StringBuilder()
    val iterator = BreadthFirstIterator(graph, startState)
    while (iterator.hasNext()) {
      val vertex = iterator.next()
      result.append(getLabelForState(vertex)).append('\n')
      graph.outgoingEdgesOf(vertex).forEach { edge ->
        result
          .append("    ")
          .append(edge.toString())
          .append("--->")
          .append(getLabelForState(graph.getEdgeTarget(edge)))
          .append('\n')
      }
    }
    return result.toString()
  }

  override fun stateSequence(): Sequence<PersesATNState> = graph.vertexSet().asSequence()
}
