/*
 * Copyright (C) 2018-2026 University of Waterloo.
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
package org.perses.program

data class TokenPosition(
  // Consistent with Antlr's convention, the line starts with 1
  val line: Int,
  // Consistent with Antlr's convention, the char position starts with 0.
  val charPositionInLine: Int,
) : Comparable<TokenPosition> {
  // TODO: need to enable these assertions.
//    init {
//      require(line >= 0) { line }
//      require(charPositionInLine >= 0) { charPositionInLine }
//    }

  fun toConcisePosition(): String = "$line:$charPositionInLine"

  override fun compareTo(other: TokenPosition): Int =
    if (line != other.line) {
      line - other.line
    } else {
      charPositionInLine - other.charPositionInLine
    }

  companion object {
    val FIRST_LINE_NUMBER = 1
    val FIRST_CHAR_POSITION_IN_LINE = 0
  }
}
