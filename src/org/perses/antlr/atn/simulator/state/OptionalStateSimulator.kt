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

import org.antlr.v4.runtime.atn.BasicBlockStartState
import org.antlr.v4.runtime.atn.BlockEndState
import org.antlr.v4.runtime.atn.EpsilonTransition
import org.antlr.v4.runtime.atn.Transition
import org.perses.antlr.atn.AbstractDecisionMaker
import org.perses.antlr.atn.tdtree.OptionalTDTreeNode

data class OptionalStateSimulator private constructor(
  private val state: BasicBlockStartState,
  private val endingTransition: EpsilonTransition,
  private val nonEndingTransition: EpsilonTransition,
) : AbstractATNStateSimulator() {

  init {
    require(endingTransition.target == state.endState)
    require(nonEndingTransition.target != state.endState)

    require(state.numberOfTransitions == 2)
    require(
      listOf(endingTransition, nonEndingTransition).containsAll(state.transitions.toList()),
    )
  }

  val isGreedy: Boolean
    get() = !state.nonGreedy

  override val endState: BlockEndState
    get() = state.endState

  override fun sampleTransition(decisionMaker: AbstractDecisionMaker): Transition {
    return decisionMaker.sampleTransition(state)
  }

  override fun createTreeNode(nodeId: Int): OptionalTDTreeNode {
    return OptionalTDTreeNode(nodeId)
  }

  companion object {
    fun create(state: BasicBlockStartState): OptionalStateSimulator {
      check(state.numberOfTransitions == 2)
      val t1 = state.transition(0)
      val t2 = state.transition(1)
      check(t1 is EpsilonTransition)
      check(t2 is EpsilonTransition)
      check(t1.target is BlockEndState || t2.target is BlockEndState) {
        "t1.target=${t1.target::class.java}, t2.target=${t2.target::class.java}"
      }

      val endingTransition: Transition
      val nonEndingTransition: Transition

      if (t1.target is BlockEndState && t2.target !is BlockEndState) {
        check(t1.target === state.endState)
        endingTransition = t1
        nonEndingTransition = t2
      } else if (t1.target !is BlockEndState && t2.target is BlockEndState) {
        check(t2.target == state.endState)
        endingTransition = t2
        nonEndingTransition = t1
      } else {
        error("unreachable.")
      }
      return OptionalStateSimulator(state, endingTransition, nonEndingTransition)
    }
  }
}
