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

import org.antlr.v4.runtime.atn.ATNState
import org.antlr.v4.runtime.atn.RuleStartState
import org.antlr.v4.runtime.atn.RuleStopState
import org.antlr.v4.runtime.atn.RuleTransition
import org.jgrapht.Graph
import org.jgrapht.graph.AbstractBaseGraph
import org.jgrapht.graph.EdgeReversedGraph
import org.jgrapht.graph.builder.GraphTypeBuilder
import org.jgrapht.traverse.DepthFirstIterator
import org.perses.antlr.RuleIndex
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.AstTag
import org.perses.antlr.ast.PersesEpsilonAst
import org.perses.antlr.ast.SmartAstConstructor
import org.perses.antlr.atn.dfsATN
import org.perses.antlr.atn.transitionSequence
import org.perses.antlr.obtainRuleIndex
import org.perses.antlr.pnf.AstUtil
import org.perses.util.SimpleStack
import org.perses.util.Util.lazyAssert

class MutableNFA(
  override var startState: PersesATNState,
  override var acceptingState: PersesATNState,
) : AbstractNFABasedOnJGraphT(
  graph = GraphTypeBuilder
    .directed<PersesATNState, Edge>()
    .allowingSelfLoops(true)
    .buildGraph(),
) {

  init {
    addStateOrThrow(startState)
    addStateOrThrow(acceptingState)
  }

  private fun addEdgeOrThrow(
    source: PersesATNState,
    target: PersesATNState,
    label: AbstractPersesRuleElement,
  ) {
    val edge = Edge(label)
    check(graph.addEdge(source, target, edge)) {
      "source: $source, target: $target, label: $label \n" + printGraph()
    }
  }

  fun removeStatesUnreachableFromAcceptingState(): MutableNFA {
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

  private fun addStateOrThrow(state: PersesATNState) {
    lazyAssert({ !graph.containsVertex(state) }) { "${state::class.java}, $state" }
    check(graph.addVertex(state)) {
      "${state::class.java}, $state"
    }
  }

  fun addStateIfAbsent(state: PersesATNState) = graph.addVertex(state)

  private fun getMaxStateNumber(): Int {
    return graph.vertexSet().maxOf { it.stateNumber }
  }

  private fun createDummyState(): PersesATNState {
    val maxStateNumber = getMaxStateNumber()
    return PersesATNState(maxStateNumber + 1)
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
    lazyAssert { startState !in verticesToDelete }
    lazyAssert { acceptingState !in verticesToDelete }

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
    check(graph.vertexSet().size == 2)
    check(graph.edgeSet().size == 1)
    return graph.edgeSet().single().label.deepCopyTreeStructure()
  }

  @Suppress("UNCHECKED_CAST")
  fun toImmutableNFA(): ImmutableNFA {
    return ImmutableNFA(
      startState = startState,
      acceptingState = acceptingState,
      graph = (graph as AbstractBaseGraph<PersesATNState, Edge>).clone()
        as Graph<PersesATNState, Edge>,
    )
  }

  companion object {

    private const val APPROXIMATION_RECURSION_LIMIT = 5

    fun copyOf(start: RuleStartState): MutableNFA {
      val map = HashMap<ATNState, PersesATNState>()
      val nfa = MutableNFA(
        startState = map.computeIfAbsent(start) {
          PersesATNState(it.stateNumber)
        },
        acceptingState = map.computeIfAbsent(start.stopState) {
          PersesATNState(it.stateNumber)
        },
      )
      dfsATN(
        start,
        stateVisitor = { state ->
          nfa.addStateIfAbsent(map.computeIfAbsent(state) { PersesATNState(it.stateNumber) })
        },
        transitionVisitor = { atnSource, transition ->
          val edgeLabel = if (transition.isEpsilon) {
            PersesEpsilonAst()
          } else {
            PersesTransitionAst(transition)
          }

          val sourceState = map[atnSource]!!
          val targetState = map.computeIfAbsent(transition.target) {
            PersesATNState(it.stateNumber)
          }
          nfa.addStateIfAbsent(targetState)
          nfa.addEdgeOrThrow(sourceState, targetState, edgeLabel)
        },
      )
      return nfa
    }

    fun copyAndInlineOf(start: RuleStartState): MutableNFA {
      return copyAndInlineOf(start, allowApproximation = false)
    }

    fun approximateOf(start: RuleStartState): MutableNFA {
      return copyAndInlineOf(start, allowApproximation = true)
    }

    private fun copyAndInlineOf(
      start: RuleStartState,
      allowApproximation: Boolean,
    ): MutableNFA {
      val cloneStart = PersesATNState(start.stateNumber)
      val cloneStop = PersesATNState(start.stopState.stateNumber)
      val nfa = MutableNFA(cloneStart, cloneStop)
      copyAndInlineOfRec(
        nfa,
        start,
        cloneStart,
        cloneStop,
        SimpleStack.of(start.obtainRuleIndex()),
        allowApproximation,
      )
      return nfa
    }

    private fun copyAndInlineOfRec(
      nfa: MutableNFA,
      start: RuleStartState,
      cloneStart: PersesATNState,
      cloneStop: PersesATNState,
      visitedRuleStack: SimpleStack<RuleIndex>,
      allowApproximation: Boolean,
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
              check(targetState is RuleStartState)
              val cloneChildStart = PersesATNState(targetState.stateNumber)
              val cloneChildStop = PersesATNState(targetState.stopState.stateNumber)

              // Detect recursive rule.
              if (!allowApproximation && visitedRuleStack.contains(
                  targetState.obtainRuleIndex(),
                )
              ) {
                throw NonRegexException.fromRuleIndex(visitedRuleStack.peekBottom())
              } else {
                visitedRuleStack.add(targetState.obtainRuleIndex())
              }

              /* The ATN from which this NFA is constructed may represent a context-free language.
              In this case, there is no way to construct an equivalent NFA, as a NFA can only
              represent a regular language. Therefore, we try to under-approximate the ATN by
              ignoring the recursive RuleTransition after unrolling it certain times. */
              if (visitedRuleStack.count(targetState.obtainRuleIndex()) <
                APPROXIMATION_RECURSION_LIMIT
              ) {
                nfa.addStateIfAbsent(cloneChildStart)
                nfa.addStateIfAbsent(cloneChildStop)
                nfa.addEdgeOrThrow(visited[state]!!, cloneChildStart, edgeLabel)

                // Connect states of the child's states
                copyAndInlineOfRec(
                  nfa,
                  targetState,
                  cloneChildStart,
                  cloneChildStop,
                  visitedRuleStack,
                  allowApproximation,
                )

                val followState = transition.followState
                if (!visited.contains(followState)) {
                  visited[followState] = PersesATNState(followState.stateNumber)
                  nfa.addStateIfAbsent(visited[followState]!!)
                  worklist.add(followState)
                }
                nfa.addEdgeOrThrow(cloneChildStop, visited[followState]!!, edgeLabel)
              }

              visitedRuleStack.remove()
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
}
