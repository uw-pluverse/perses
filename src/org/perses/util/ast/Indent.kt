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
package org.perses.util.ast

import java.io.PrintStream

data class Indent private constructor(
  val numOfIndents: Int,
  private val numOfSpacesPerIndent: Int,
) {

  init {
    require(numOfIndents >= 0)
    require(numOfSpacesPerIndent >= 0)
  }

  val increasedIndent: Indent by lazy {
    Indent(
      numOfIndents = numOfIndents + 1,
      numOfSpacesPerIndent,
    )
  }

  val decreasedIndent: Indent by lazy {
    Indent(
      numOfIndents = numOfIndents - 1,
      numOfSpacesPerIndent,
    )
  }

  fun printIndent(stream: PrintStream): PrintStream {
    for (i in 0 until numOfIndents * numOfSpacesPerIndent) {
      stream.print(' ')
    }
    return stream
  }

  companion object {
    fun createEmptyIndent(numOfSpacesPerIndent: Int): Indent {
      require(numOfSpacesPerIndent >= 0)
      return Indent(
        numOfIndents = 0,
        numOfSpacesPerIndent = numOfSpacesPerIndent,
      )
    }

    val FOUR_CHAR_EMPTY_INDENT = createEmptyIndent(4)
  }
}
