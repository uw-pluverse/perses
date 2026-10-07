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
import org.perses.program.AbstractPersesToken
import org.perses.program.TokenizedProgram
import org.perses.util.FastStringBuilder

/**
 * Prints every token at the line and column it carries, filling the distance from the previous
 * token with newlines and spaces only, and ends the text with a newline. For tokens taken from
 * printer output -- whose gaps are exactly such newlines and spaces -- this reproduces the text up
 * to what follows the last token, which no position records, and a deleted token leaves its place
 * blank while every other token stays where it was.
 *
 * Unlike [OrigFormatPrinter], a token's text may span lines: the cursor follows the text actually
 * printed, which is what XML's whitespace tokens need. Columns count code points, as ANTLR's do. A
 * token without a position, or one the cursor has already passed, is printed where the cursor is.
 */
object RecordedPositionPrinter : AbstractTokenizedProgramPrinter() {
  override fun print(
    program: TokenizedProgram,
    tokenPlacementListener: AbstractTokenPlacementListener?,
  ) = object : AbstractLazySourceCode() {
    override fun computeStringBuilder(): FastStringBuilder {
      val builder = FastStringBuilder(program.tokenCount * 8)
      var line = 1
      var column = 0
      program.tokens.forEach { token ->
        if (token is AbstractPersesToken.AntlrToken) {
          val position = token.position
          if (position.line > line) {
            repeat(position.line - line) { builder.append('\n') }
            line = position.line
            column = 0
          }
          if (position.line == line && position.charPositionInLine > column) {
            repeat(position.charPositionInLine - column) { builder.append(' ') }
            column = position.charPositionInLine
          }
        }
        tokenPlacementListener?.onTokenPlacement(token, line, column)
        val text = token.lexemeText
        builder.append(text)
        text.codePoints().forEach { codePoint ->
          if (codePoint == '\n'.code) {
            ++line
            column = 0
          } else {
            ++column
          }
        }
      }
      if (column > 0) {
        builder.append('\n')
      }
      return builder
    }
  }

  override fun extraEquals(other: Any): Boolean = true

  override fun extraHashCode(): Int = 0
}
