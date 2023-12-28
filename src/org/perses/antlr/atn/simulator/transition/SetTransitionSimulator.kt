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

import com.google.common.collect.ImmutableList
import org.antlr.v4.runtime.atn.SetTransition
import org.antlr.v4.runtime.misc.IntervalSet
import org.perses.antlr.atn.AbstractDecisionMaker
import org.perses.util.toImmutableList

class SetTransitionSimulator(
  transition: SetTransition,
) : AbstractAtnTransitionSimulator() {

  private val allowedAsciiChars = intersectPrintableCharacters(transition.label())

  override fun simulate(decisionMaker: AbstractDecisionMaker): Char {
    assert(allowedAsciiChars.isNotEmpty())
    if (allowedAsciiChars.size == 1) {
      return allowedAsciiChars.single()
    }
    return decisionMaker.sampleChar(allowedAsciiChars)
  }

  companion object {

    @JvmStatic
    fun intersectPrintableCharacters(intervals: IntervalSet): ImmutableList<Char> {
      val ascii = PrintableCharacters.createPrintableIntervalSet()
      return ascii.and(intervals)
        .toArray()
        .asSequence()
        .distinct()
        .map { it.toChar() }
        .toImmutableList()
    }
  }
}
