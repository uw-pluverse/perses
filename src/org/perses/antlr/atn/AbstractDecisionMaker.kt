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

import com.google.common.collect.ImmutableList
import org.antlr.v4.runtime.atn.ATNState
import org.antlr.v4.runtime.atn.Transition
import java.util.Random

abstract class AbstractDecisionMaker {

  protected abstract fun nextBoolean(): Boolean

  abstract fun nextInt(bound: Int): Int

  open fun decideOnKleene(): EnumKleeneDecision {
    assert(EnumKleeneDecision.ALL_DECISIONS.size == 2)
    return if (nextBoolean()) {
      EnumKleeneDecision.TAKE
    } else {
      EnumKleeneDecision.SKIP
    }
  }

  open fun sampleTransition(state: ATNState): Transition {
    val numOfTransitions = state.numberOfTransitions
    assert(numOfTransitions > 0)
    return when (numOfTransitions) {
      0 -> error("No outgoing transition")
      1 -> state.transition(0)
      2 -> state.transition(if (nextBoolean()) 0 else 1)
      else -> state.transition(nextInt(numOfTransitions))
    }
  }

  // TODO: List<Char> can be replaced with a String object.
  open fun sampleChar(list: List<Char>): Char {
    return list[nextInt(list.size)]
  }

  open fun sampleChar(char: Char): Char {
    return char
  }

  class DefaultDecisionMaker(seed: Long) : AbstractDecisionMaker() {
    private val random = Random(seed)

    override fun nextBoolean(): Boolean {
      return random.nextBoolean()
    }

    override fun nextInt(bound: Int): Int {
      return random.nextInt(bound)
    }
  }

  enum class EnumKleeneDecision {
    TAKE,
    SKIP,
    ;

    companion object {
      val ALL_DECISIONS = ImmutableList.copyOf(EnumKleeneDecision.values())
    }
  }
}
