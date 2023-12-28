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

import com.google.common.base.MoreObjects
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.PersesEpsilonAst

abstract class AbstractNFA {
  abstract val startState: PersesATNState
  abstract val acceptingState: PersesATNState

  abstract fun edgeSequence(): Sequence<Edge>
  abstract fun getSourceState(edge: Edge): PersesATNState
  abstract fun getTargetState(edge: Edge): PersesATNState
  abstract fun getOutgoingEdgesOf(sourceState: PersesATNState): Set<Edge>
  abstract fun outDegreeOf(state: PersesATNState): Int
  abstract fun printGraph(): String
  abstract fun containsState(state: PersesATNState): Boolean

  override fun toString() = MoreObjects
    .toStringHelper(this)
    .add("start", getLabelForState(startState))
    .add("accepting", getLabelForState(acceptingState))
    .add("graph", printGraph()).toString()

  inline fun createNFAState(stateSelector: (AbstractNFA) -> PersesATNState): NFAState {
    val state = stateSelector(this)
    lazy { containsState(state) }
    return NFAState(this, state)
  }

  abstract fun stateSequence(): Sequence<PersesATNState>

  protected fun getLabelForState(state: PersesATNState): String {
    return MoreObjects.toStringHelper(state).add("id", state).toString()
  }

  fun printTopology(): String {
    return buildString {
      appendLine("======NFA======")
      appendLine("start state: ${startState.stateNumber}")
      appendLine("accepting state: ${acceptingState.stateNumber}")

      appendLine("===States and Transitions===")
      val sortedStates = stateSequence().sortedBy { it.stateNumber }.toList()
      sortedStates.forEach { sourceState ->
        appendLine("State ${sourceState.stateNumber}")

        getOutgoingEdgesOf(sourceState)
          .asSequence()
          .map { Pair(it, getTargetState(it)) }
          .sortedWith(
            compareBy<Pair<AbstractNFA.Edge, PersesATNState>> {
              it.second.stateNumber
            }.thenBy { it.first.toString() },
          ).forEach {
            appendLine("    -->${it.second.stateNumber}: ${it.first}")
          }
      }
    }
  }

  // Not a data class for using the system identity as hashcode.
  class Edge(val label: AbstractPersesRuleElement) {

    val isEpsilon: Boolean
      get() = label is PersesEpsilonAst

    override fun toString(): String {
      return MoreObjects.toStringHelper(this).addValue(label).toString()
    }
  }

  data class NFAState @PublishedApi internal constructor(
    val nfa: AbstractNFA,
    val state: PersesATNState,
  ) {
    fun outgoingEdges(): Sequence<NFAEdge> {
      return nfa.getOutgoingEdgesOf(state).asSequence().map {
        NFAEdge(nfa, it)
      }
    }
  }

  data class NFAEdge(val nfa: AbstractNFA, val edge: Edge) {
    val target: NFAState by lazy {
      NFAState(nfa, nfa.getTargetState(edge))
    }
  }
}
