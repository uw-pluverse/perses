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
import org.antlr.v4.runtime.atn.StarLoopEntryState
import java.util.concurrent.ConcurrentHashMap

class StateSimulatorRegistry {

  private val simulators =
    ConcurrentHashMap<ATNState, AbstractATNStateSimulator>()

  fun getSimulator(state: ATNState): AbstractATNStateSimulator {
    return simulators.computeIfAbsent(state) {
      when {
        isOptional(it) -> OptionalStateSimulator.create(it as BasicBlockStartState)
        isAlternativeBlock(it) -> AlternativeBlockStateSimulator(it as BasicBlockStartState)
        it is StarLoopEntryState -> StarStateSimulator.create(it)
        it is StarBlockStartState -> AlternativeBlockStateSimulator(it as BlockStartState)
        it is PlusBlockStartState -> PlusStateSimulator(it)
        else -> error("unhandled ${it::class.java}")
      }
    }
  }

  private fun isAlternativeBlock(state: ATNState): Boolean {
    return !(isOptional(state)) && state::class.java == BasicBlockStartState::class.java
  }

  private fun isOptional(state: ATNState): Boolean {
    if (state::class.java != BasicBlockStartState::class.java) {
      return false
    }
    val blockStart = state as BasicBlockStartState
    if (state.numberOfTransitions != 2) {
      return false
    }
    val t1 = state.transition(0)
    val t2 = state.transition(1)
    return (t1.isEpsilon && t1.target === blockStart.endState) ||
      (t2.isEpsilon && t2.target == blockStart.endState)
  }
}
