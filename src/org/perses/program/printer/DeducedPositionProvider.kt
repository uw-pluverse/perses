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
import org.perses.antlr.atn.LexerAtnWrapper
import org.perses.program.AbstractPersesToken

class DeducedPositionProvider(
  val lexerAtnWrapper: LexerAtnWrapper,
) : AbstractTokenPositionProvider() {
  override fun getLine(token: AbstractPersesToken): Int = token.asAntlrToken().position.line

  override fun getCharPositionInLine(
    token: AbstractPersesToken,
    currentCursorPositionInLine: Int,
    previousToken: AbstractPersesToken?,
  ): Int {
    return if (previousToken == null) {
      if (token.isPlainText()) {
        return currentCursorPositionInLine
      } else {
        token.asAntlrToken().position.charPositionInLine
      }
    } else {
      if (previousToken.isPlainText()) {
        currentCursorPositionInLine
      } else if (lexerAtnWrapper.canBeConcatWithoutSpace(
          previousToken.tokenType,
          token.tokenType,
        )
      ) {
        currentCursorPositionInLine
      } else {
        currentCursorPositionInLine + 1
      }
    }
  }
}
