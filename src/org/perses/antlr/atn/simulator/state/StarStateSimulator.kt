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
package org.perses.antlr.atn.simulator.state

import org.antlr.v4.runtime.atn.EpsilonTransition
import org.antlr.v4.runtime.atn.LoopEndState
import org.antlr.v4.runtime.atn.StarBlockStartState
import org.antlr.v4.runtime.atn.StarLoopEntryState
import org.antlr.v4.runtime.atn.Transition
import org.perses.antlr.atn.AbstractDecisionMaker
import org.perses.antlr.atn.tdtree.StarTDTreeNode

class StarStateSimulator(
  private val state: StarLoopEntryState,
  private val endingTransition: EpsilonTransition,
  private val nonEndingTransition: EpsilonTransition,
) : AbstractATNStateSimulator() {

  override val endState: LoopEndState = endingTransition.target as LoopEndState

  init {
    require(endingTransition.target === endState)
    require(nonEndingTransition.target !== endState)

    require(state.numberOfTransitions == 2)
    require(
      listOf(nonEndingTransition, endingTransition).containsAll(state.transitions.toList()),
    )
  }

  override fun sampleTransition(decisionMaker: AbstractDecisionMaker): Transition {
    return decisionMaker.sampleTransition(state)
  }

  override fun createTreeNode(nodeId: Int): StarTDTreeNode {
    return StarTDTreeNode(nodeId)
  }

  companion object {

    fun create(state: StarLoopEntryState): StarStateSimulator {
      check(state.numberOfTransitions == 2)
      val t1 = state.transition(0)
      val t2 = state.transition(1)
      check(t1 is EpsilonTransition)
      check(t2 is EpsilonTransition)
      check(t1.target::class.java != t2.target::class.java)
      check(t1.target is LoopEndState || t2.target is LoopEndState)

      val endingTransition: EpsilonTransition
      val nonEndingTransition: EpsilonTransition
      if (t1.target is LoopEndState && t2.target is StarBlockStartState) {
        endingTransition = t1
        nonEndingTransition = t2
      } else if (t1.target is StarBlockStartState && t2.target is LoopEndState) {
        endingTransition = t2
        nonEndingTransition = t1
      } else {
        error("unhandled case here.")
      }
      return StarStateSimulator(state, endingTransition, nonEndingTransition)
    }
  }
}
