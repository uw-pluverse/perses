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
package org.perses.antlr.atn.simulator.transition

import org.antlr.v4.runtime.atn.AtomTransition
import org.antlr.v4.runtime.atn.EpsilonTransition
import org.antlr.v4.runtime.atn.NotSetTransition
import org.antlr.v4.runtime.atn.RangeTransition
import org.antlr.v4.runtime.atn.SetTransition
import org.antlr.v4.runtime.atn.Transition
import org.antlr.v4.runtime.atn.WildcardTransition
import org.perses.antlr.atn.AbstractDecisionMaker
import org.perses.antlr.atn.simulator.AbstractSimulatorRegistry

class TransitionSimulatorRegistry :
  AbstractSimulatorRegistry<Transition, AbstractAtnTransitionSimulator>() {

  override fun createSimulatorFor(element: Transition): AbstractAtnTransitionSimulator {
    return Companion.createSimulatorFor(element)
  }

  fun simulate(element: Transition, decisionMaker: AbstractDecisionMaker): Char? {
    return getOrCreateSimulatorFor(element).simulate(decisionMaker)
  }

  companion object {
    fun createSimulatorFor(element: Transition): AbstractAtnTransitionSimulator {
      return when (element::class.java) {
        EpsilonTransition::class.java -> EpsilonTransitionSimulator
        AtomTransition::class.java -> AtomTransitionSimulator(element as AtomTransition)
        SetTransition::class.java -> SetTransitionSimulator(element as SetTransition)
        NotSetTransition::class.java -> NotSetTransitionSimulator(element as NotSetTransition)
        WildcardTransition::class.java -> WildcardTransitionSimulator()
        RangeTransition::class.java -> RangeTransitionSimulator(element as RangeTransition)
        else -> error("unhandled element ${element::class.java}, $element")
      }
    }
  }
}
