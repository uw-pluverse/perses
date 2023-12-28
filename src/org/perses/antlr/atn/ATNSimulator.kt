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
package org.perses.antlr.atn

import com.google.common.base.MoreObjects
import org.antlr.v4.runtime.atn.ATNState
import org.antlr.v4.runtime.atn.BasicBlockStartState
import org.antlr.v4.runtime.atn.EpsilonTransition
import org.antlr.v4.runtime.atn.PlusBlockStartState
import org.antlr.v4.runtime.atn.PlusLoopbackState
import org.antlr.v4.runtime.atn.RuleStartState
import org.antlr.v4.runtime.atn.StarBlockStartState
import org.antlr.v4.runtime.atn.StarLoopEntryState
import org.antlr.v4.runtime.atn.Transition
import org.perses.antlr.atn.simulator.state.StateSimulatorRegistry
import org.perses.antlr.atn.simulator.transition.TransitionSimulatorRegistry
import org.perses.antlr.atn.tdtree.AbstractTDTreeNode
import org.perses.antlr.atn.tdtree.AlternativeBlockTDTreeNode
import org.perses.antlr.atn.tdtree.TDTree
import org.perses.util.SimpleStack

class ATNSimulator(private val startState: RuleStartState) {

  private val transitionSimulatorRegistry = TransitionSimulatorRegistry()
  private val stateSimulatorRegistry = StateSimulatorRegistry()

  fun simulate(decisionMaker: AbstractDecisionMaker): TDTree {
    val result = TDTree()

    val path = SimpleStack<AbstractTDTreeNode>()
    path.add(result.root)

    val expectingStopStatesSimpleStack = SimpleStack<ATNState>()
    expectingStopStatesSimpleStack.add(startState.stopState)

    check(startState.numberOfTransitions == 1) {
      "The root should have only one transition $startState"
    }
    /*
     * Call it here to simplify the implementation of replay. Make sure every transition
     * is obtained through random.
     */
    val startTransition = decisionMaker.sampleTransition(startState)
    check(startTransition is EpsilonTransition) { startTransition }
    var currentState: ATNState = startTransition.target

    while (true) {
      if (currentState === expectingStopStatesSimpleStack.peek()) {
        expectingStopStatesSimpleStack.remove()
        path.remove()
      }
      if (expectingStopStatesSimpleStack.isEmpty()) {
        check(currentState.numberOfTransitions == 0) {
          "${currentState::class.java}, transitions=${currentState.transitions.toList()}"
        }
        break
      }
      val numOfTransitions = currentState.numberOfTransitions

      val transition = when (currentState) {
        is BasicBlockStartState,
        is StarLoopEntryState,
        is StarBlockStartState,
        -> {
          val stateSimulator = stateSimulatorRegistry.getSimulator(currentState)
          if (expectingStopStatesSimpleStack.peek() === stateSimulator.endState) {
            // This is a loop, and not the first iteration.
            // Do nothing.
          } else {
            val starTDNode = stateSimulator.createTreeNode(result.nextId())
            path.peek().addChild(starTDNode)
            path.add(starTDNode)
            expectingStopStatesSimpleStack.add(stateSimulator.endState)
          }
          stateSimulator.sampleTransition(decisionMaker)
        }
        is PlusBlockStartState -> {
          val plusSimulator = stateSimulatorRegistry.getSimulator(currentState)
          if (expectingStopStatesSimpleStack.peek() == plusSimulator.endState) {
            // This is a loop, and not the first iteration.
            // Do nothing.
          } else {
            val plusTDNode = plusSimulator.createTreeNode(result.nextId())
            path.peek().addChild(plusTDNode)
            path.add(plusTDNode)
            expectingStopStatesSimpleStack.add(plusSimulator.endState)
          }
          val altBlock = AlternativeBlockTDTreeNode(result.nextId())
          path.peek().addChild(altBlock)
          path.add(altBlock)
          expectingStopStatesSimpleStack.add(currentState.endState)
          plusSimulator.sampleTransition(decisionMaker)
        }
        is PlusLoopbackState -> {
          check(currentState.numberOfTransitions == 2)
          decisionMaker.sampleTransition(currentState)
        }
        else -> {
          check(numOfTransitions == 1) { "${currentState::class.java}, $numOfTransitions" }
          decisionMaker.sampleTransition(currentState)
        }
      }

      val currentParent = path.peek()
      val simulatedChar = transitionSimulatorRegistry
        .getOrCreateSimulatorFor(transition).simulate(decisionMaker)
      if (simulatedChar != null) {
        currentParent.addChild(result.createCharNode(simulatedChar))
      }
      currentState = transition.target
    }
    currentState.numberOfTransitions
    return result
  }

  fun printATNToString(): String {
    val builder = StringBuilder()
    dfsATN(
      startState,
      {
        builder.append(getStateLabel(it)).append("\n")
        it.transitionSequence().forEach { transition ->
          builder.append("  ->").append(getStateLabel(transition.target))
            .append(getTransitionLabel(transition)).append('\n')
        }
      },
      { _, _ -> },
    )
    return builder.toString()
  }

  private fun getTransitionLabel(t: Transition): String {
    return "(${t::class.java.simpleName} $t)"
  }

  private fun getStateLabel(state: ATNState): String {
    return "(state $state)[${state::class.java.simpleName}]"
  }

  override fun toString(): String {
    return MoreObjects.toStringHelper(this).add("graph", printATNToString()).toString()
  }
}
