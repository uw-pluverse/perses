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
package org.perses.program.printer

import org.perses.program.AbstractLazySourceCode
import org.perses.program.TokenizedProgram
import org.perses.util.FastStringBuilder

/**
 * Concatenates the tokens' text with nothing between them. For a program whose tokens carry their
 * own whitespace -- one cut from a text at recorded offsets, where the pieces between the recorded
 * ranges are tokens too -- this reproduces the text exactly, and deleting a token removes exactly
 * its span.
 */
object VerbatimPrinter : AbstractTokenizedProgramPrinter() {
  override fun print(
    program: TokenizedProgram,
    tokenPlacementListener: AbstractTokenPlacementListener?,
  ) = object : AbstractLazySourceCode() {
    override fun computeStringBuilder(): FastStringBuilder {
      val builder = FastStringBuilder(program.tokenCount * 8)
      var line = 1
      var charPositionInLine = 0
      program.tokens.forEach { token ->
        tokenPlacementListener?.onTokenPlacement(token, line, charPositionInLine)
        val text = token.lexemeText
        builder.append(text)
        text.forEach { char ->
          if (char == '\n') {
            ++line
            charPositionInLine = 0
          } else {
            ++charPositionInLine
          }
        }
      }
      return builder
    }
  }

  override fun extraEquals(other: Any): Boolean = true

  override fun extraHashCode(): Int = 0
}
