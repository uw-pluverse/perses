/*
 * Copyright (C) 2018-2022 University of Waterloo.
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
import org.antlr.v4.runtime.atn.ATNState
import org.antlr.v4.runtime.atn.RuleStartState
import org.antlr.v4.runtime.atn.RuleStopState
import org.antlr.v4.runtime.atn.RuleTransition
import org.jgrapht.graph.EdgeReversedGraph
import org.jgrapht.graph.builder.GraphTypeBuilder
import org.jgrapht.traverse.BreadthFirstIterator
import org.jgrapht.traverse.DepthFirstIterator
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.AstTag
import org.perses.antlr.ast.PersesEpsilonAst
import org.perses.antlr.ast.SmartAstConstructor
import org.perses.antlr.atn.dfsATN
import org.perses.antlr.atn.transitionSequence
import org.perses.antlr.pnf.AstUtil
import org.perses.util.SimpleStack

class NFA(
  var startState: ATNState,
  var acceptingState: ATNState,
) {

  val graph = GraphTypeBuilder
    .directed<ATNState, Edge>()
    .allowingSelfLoops(true)
    .buildGraph()

  init {
    addStateOrThrow(startState)
    addStateOrThrow(acceptingState)
  }

  fun addEdgeOrThrow(source: ATNState, target: ATNState, label: AbstractPersesRuleElement) {
    val edge = Edge(label)
    check(graph.addEdge(source, target, edge)) {
      "source: $source, target: $target, label: $label \n" + printGraph()
    }
  }

  fun removeStatesUnreachableFromAcceptingState(): NFA {
    val reversedGraph = EdgeReversedGraph(graph)
    val reachableStates = DepthFirstIterator(reversedGraph, acceptingState)
      .asSequence()
      .toSet()
    graph.vertexSet()
      .asSequence()
      .minus(reachableStates)
      .toList() // materialize the elements to avoid concurrent modification
      .forEach { graph.removeVertex(it) }
    return this
  }

  fun addStateOrThrow(state: ATNState) {
    assert(!graph.containsVertex(state)) { "${state::class.java}, $state" }
    check(graph.addVertex(state)) {
      "${state::class.java}, $state"
    }
  }

  fun addStateIfAbsent(state: ATNState) = graph.addVertex(state)

  fun edgeSequence() = graph.edgeSet().asSequence()

  fun getSourceState(edge: Edge): ATNState {
    return graph.getEdgeSource(edge)!!
  }

  fun getTargetState(edge: Edge): ATNState {
    return graph.getEdgeTarget(edge)!!
  }

  fun printGraph(): String {
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

  private fun getLabelForState(state: ATNState): String {
    return MoreObjects.toStringHelper(state).add("id", state).toString()
  }

  override fun toString() = MoreObjects
    .toStringHelper(this)
    .add("start", getLabelForState(startState))
    .add("accepting", getLabelForState(acceptingState))
    .add("graph", printGraph()).toString()

  private fun getMaxStateNumber(): Int {
    return graph.vertexSet().maxOf { it.stateNumber }
  }

  private fun createDummyState(): ATNDummyState {
    val maxStateNumber = getMaxStateNumber()
    return ATNDummyState(maxStateNumber + 1)
  }

  fun simplifyToRegex(): AbstractPersesRuleElement {
    removeStatesUnreachableFromAcceptingState()
    if (graph.inDegreeOf(startState) != 0) {
      val newStartState = createDummyState()
      val oldStartState = startState
      startState = newStartState

      addStateOrThrow(newStartState)
      addEdgeOrThrow(newStartState, oldStartState, PersesEpsilonAst())
    }
    if (graph.outDegreeOf(acceptingState) != 0) {
      val newAcceptingState = createDummyState()
      val oldAcceptingState = acceptingState
      acceptingState = newAcceptingState

      addStateOrThrow(newAcceptingState)
      addEdgeOrThrow(oldAcceptingState, newAcceptingState, PersesEpsilonAst())
    }
    check(graph.inDegreeOf(startState) == 0)
    check(graph.outDegreeOf(acceptingState) == 0)

    val verticesToDelete = graph.vertexSet()
      .asSequence()
      .filter { it != startState && it != acceptingState }
      .sortedBy { it.stateNumber }
      .toMutableList()
    assert(startState !in verticesToDelete)
    assert(acceptingState !in verticesToDelete)

    while (verticesToDelete.isNotEmpty()) {
      val vertex = verticesToDelete.removeLast()
      val selfEdge: Edge? = graph.getEdge(vertex, vertex)?.let {
        val label = it.label
        if (label.tag == AstTag.EPSILON) {
          null
        } else {
          it
        }
      }
      val sourceList = graph.incomingEdgesOf(vertex)
        .asSequence()
        .filter { it !== selfEdge }
        .map { graph.getEdgeSource(it) to it }
        .toList()
      val targetList = graph.outgoingEdgesOf(vertex)
        .asSequence()
        .filter { it !== selfEdge }
        .map { graph.getEdgeTarget(it) to it }
        .toList()
      check(graph.removeVertex(vertex))
      sourceList.forEach { check(!graph.containsEdge(it.second)) }
      targetList.forEach { check(!graph.containsEdge(it.second)) }
      check(sourceList.isNotEmpty()) {
        """$vertex, source: $sourceList, target: $targetList, 
          |graph: 
          |${printGraph()}
        """.trimMargin()
      }
      check(targetList.isNotEmpty()) {
        """$vertex, source: $sourceList, target: $targetList, 
          |graph: 
          |${printGraph()}
        """.trimMargin()
      }
      for (source in sourceList) {
        val sourceVertex = source.first
        val sourceEdge = source.second
        for (target in targetList) {
          val targetVertex = target.first
          val targetEdge = target.second

          val newEdgeAlternative: AbstractPersesRuleElement = AstUtil.concatenateByIgnoringEpsilon(
            ArrayList<AbstractPersesRuleElement>().apply {
              add(sourceEdge.label)
              if (selfEdge != null) {
                // FIXME: need to handle the non-greedy version.
                add(SmartAstConstructor.createForStar(selfEdge.label, isGreedy = true))
              }
              add(targetEdge.label)
            },
          )
          val existingEdge: Edge? = graph.getEdge(source.first, target.first)
          if (existingEdge == null) {
            addEdgeOrThrow(sourceVertex, targetVertex, newEdgeAlternative)
          } else {
            graph.removeEdge(existingEdge)
            val newEdgeAltBlock = when (existingEdge.label) {
              // FIXME: handle the non-greedy version.
              is PersesEpsilonAst -> SmartAstConstructor.createForOptional(
                newEdgeAlternative,
                isGreedy = true,
              )
              else -> AstUtil.createAltBlockIfNecessary(
                listOf(newEdgeAlternative, existingEdge.label),
              )
            }
            addEdgeOrThrow(sourceVertex, targetVertex, newEdgeAltBlock)
          }
        }
      }
    }
    assert(graph.vertexSet().size == 2)
    assert(graph.edgeSet().size == 1)
    return graph.edgeSet().single().label.deepCopyTreeStructure()
  }

  fun stateSequence(): Sequence<ATNState> {
    return graph.vertexSet().asSequence()
  }

  companion object {

    fun copyOf(start: RuleStartState): NFA {
      val nfa = NFA(start, start.stopState)
      dfsATN(
        start,
        { nfa.addStateIfAbsent(it) },
        { sourceState, transition ->
          val edgeLabel = if (transition.isEpsilon) {
            PersesEpsilonAst()
          } else {
            PersesTransitionAst(transition)
          }

          val targetState = transition.target
          nfa.addStateIfAbsent(targetState)
          nfa.addEdgeOrThrow(sourceState, targetState, edgeLabel)
        },
      )
      return nfa
    }

    fun copyAndInlineOf(start: RuleStartState): NFA {
      val cloneStart = PersesATNState(start.stateNumber)
      val cloneStop = PersesATNState(start.stopState.stateNumber)
      val nfa = NFA(cloneStart, cloneStop)
      copyAndInlineOfRec(nfa, start, cloneStart, cloneStop)
      return nfa
    }

    fun copyAndInlineOfRec(
      nfa: NFA,
      start: RuleStartState,
      cloneStart: PersesATNState,
      cloneStop: PersesATNState,
    ) {
      val visited = mutableMapOf<ATNState, PersesATNState>()
      visited[start] = cloneStart
      visited[start.stopState] = cloneStop
      val worklist = SimpleStack<ATNState>()
      worklist.add(start)
      // add every state to both visited and nfa
      while (worklist.isNotEmpty()) {
        val state = worklist.remove()
        if (state is RuleStopState) {
          continue
        }
        state.transitionSequence()
          .forEach { transition ->
            val edgeLabel = if (transition.isEpsilon) {
              PersesEpsilonAst()
            } else {
              PersesTransitionAst(transition)
            }

            val targetState = transition.target
            if (transition is RuleTransition) {
              val cloneChildStart = PersesATNState(targetState.stateNumber)
              val cloneChildStop = PersesATNState(
                (targetState as RuleStartState).stopState.stateNumber,
              )
              nfa.addStateIfAbsent(cloneChildStart)
              nfa.addStateIfAbsent(cloneChildStop)
              nfa.addEdgeOrThrow(visited[state]!!, cloneChildStart, edgeLabel)

              // connect states of the child's states
              copyAndInlineOfRec(nfa, targetState, cloneChildStart, cloneChildStop)

              val followState = transition.followState
              if (!visited.contains(followState)) {
                visited[followState] = PersesATNState(followState.stateNumber)
                nfa.addStateIfAbsent(visited[followState]!!)
                worklist.add(followState)
              }
              nfa.addEdgeOrThrow(cloneChildStop, visited[followState]!!, edgeLabel)
            } else {
              if (!visited.contains(targetState)) {
                visited[targetState] = PersesATNState(targetState.stateNumber)
                nfa.addStateIfAbsent(visited[targetState]!!)
                worklist.add(targetState)
              }
              nfa.addEdgeOrThrow(visited[state]!!, visited[targetState]!!, edgeLabel)
            }
          }
      }
    }
  }

  // Not a data class for using the system identity as hashcode.
  class Edge(val label: AbstractPersesRuleElement) {
    override fun toString(): String {
      return MoreObjects.toStringHelper(this).addValue(label).toString()
    }
  }
}
