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

import org.antlr.v4.runtime.atn.ATNState
import org.antlr.v4.runtime.atn.BasicBlockStartState
import org.antlr.v4.runtime.atn.BlockStartState
import org.antlr.v4.runtime.atn.PlusBlockStartState
import org.antlr.v4.runtime.atn.StarBlockStartState
import org.antlr.v4.runtime.atn.Transition
import org.perses.antlr.atn.AbstractDecisionMaker
import org.perses.antlr.atn.tdtree.AbstractTDTreeNode
import org.perses.antlr.atn.tdtree.AlternativeBlockTDTreeNode

class AlternativeBlockStateSimulator(
  private val state: BlockStartState,
) : AbstractATNStateSimulator() {

  init {
    require(
      state is StarBlockStartState ||
        state is PlusBlockStartState ||
        state is BasicBlockStartState,
    ) {
      "$state of class ${state::class.java}"
    }
    require(state.numberOfTransitions > 0)
  }

  override fun sampleTransition(decisionMaker: AbstractDecisionMaker): Transition {
    return decisionMaker.sampleTransition(state)
  }

  override val endState: ATNState
    get() = state.endState

  override fun createTreeNode(nodeId: Int): AbstractTDTreeNode {
    return AlternativeBlockTDTreeNode(nodeId)
  }
}
