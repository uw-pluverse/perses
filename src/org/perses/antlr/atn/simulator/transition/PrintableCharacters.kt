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

import org.antlr.v4.runtime.misc.IntervalSet
import org.perses.util.toImmutableList

object PrintableCharacters {
  const val MIN_PRINTABLE_CHAR = 32.toChar()
  const val MAX_PRINTABLE_CHAR = 126.toChar()
  val ALL_PRINTABLE_CHARS_LIST = (MIN_PRINTABLE_CHAR..MAX_PRINTABLE_CHAR).toImmutableList()
  val ALL_PRINTABLE_CHARS_STRING = ALL_PRINTABLE_CHARS_LIST.joinToString(separator = "")

  fun createPrintableIntervalSet(): IntervalSet {
    return IntervalSet.of(MIN_PRINTABLE_CHAR.code, MAX_PRINTABLE_CHAR.code)
  }
}
