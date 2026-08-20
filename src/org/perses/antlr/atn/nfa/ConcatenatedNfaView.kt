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

import org.perses.antlr.ast.PersesEpsilonAst

/**
 * A read-only view of the concatenation `L(former) . L(latter)` that avoids
 * materializing a merged graph. It delegates to [former] and [latter] as-is and
 * synthesizes a single bridging epsilon edge from former's accepting state to
 * latter's start state; the accepting state of the concatenation is latter's.
 *
 * [former] and [latter] must be state-disjoint (as they are when built from
 * independent copies), so a state or edge belongs to exactly one of them and can
 * be dispatched by identity membership.
 */
class ConcatenatedNfaView(
  private val former: AbstractNfa,
  private val latter: AbstractNfa,
) : AbstractNfa() {
  private val bridgeEdge = Edge(PersesEpsilonAst())

  override val startState: PersesATNState
    get() = former.startState

  override val acceptingState: PersesATNState
    get() = latter.acceptingState

  override fun getOutgoingEdgesOf(sourceState: PersesATNState): Set<Edge> =
    if (sourceState === former.acceptingState) {
      former.getOutgoingEdgesOf(sourceState) + bridgeEdge
    } else if (former.containsState(sourceState)) {
      former.getOutgoingEdgesOf(sourceState)
    } else {
      latter.getOutgoingEdgesOf(sourceState)
    }

  override fun outDegreeOf(state: PersesATNState): Int = getOutgoingEdgesOf(state).size

  override fun getSourceState(edge: Edge): PersesATNState =
    when {
      edge === bridgeEdge -> former.acceptingState
      former.containsEdge(edge) -> former.getSourceState(edge)
      else -> latter.getSourceState(edge)
    }

  override fun getTargetState(edge: Edge): PersesATNState =
    when {
      edge === bridgeEdge -> latter.startState
      former.containsEdge(edge) -> former.getTargetState(edge)
      else -> latter.getTargetState(edge)
    }

  override fun containsEdge(edge: Edge): Boolean =
    edge === bridgeEdge || former.containsEdge(edge) || latter.containsEdge(edge)

  override fun containsState(state: PersesATNState): Boolean =
    former.containsState(state) || latter.containsState(state)

  override fun stateSequence(): Sequence<PersesATNState> =
    former.stateSequence() + latter.stateSequence()

  override fun edgeSequence(): Sequence<Edge> =
    former.edgeSequence() + latter.edgeSequence() + bridgeEdge

  override fun printGraph(): String = former.printGraph() + latter.printGraph()
}
