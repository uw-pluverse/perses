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

import org.antlr.v4.runtime.Token
import org.perses.antlr.TokenType

object PersesTokenFactory {
  fun createPersesToken(
    token: Token,
    overridingPosition: TokenPosition?,
  ): AbstractPersesToken.AntlrToken =
    createFromAntlrToken(
      token.text,
      token,
      overridingPosition,
    )

  fun copyPersesTokenWithNewText(
    newText: String,
    existing: AbstractPersesToken.AntlrToken,
  ): AbstractPersesToken.AntlrToken = existing.copyWithNewLexemeText(newText)

  fun createPlaceholderTokenForGivenType(tokenType: TokenType): AbstractPersesToken.Placeholder =
    AbstractPersesToken.Placeholder(tokenType)

  fun createPlainTextToken(text: String): AbstractPersesToken.PlainText =
    AbstractPersesToken.PlainText(text)

  private fun createFromAntlrToken(
    lexemeText: String,
    token: Token,
    overridingPosition: TokenPosition?,
  ): AbstractPersesToken.AntlrToken =
    AbstractPersesToken.AntlrToken(
      lexemeText = lexemeText,
      tokenType = TokenType(token.type),
      position =
        overridingPosition ?: TokenPosition(
          line = token.line,
          charPositionInLine = token.charPositionInLine,
        ),
      channel = token.channel,
      tokenIndex = token.tokenIndex,
      startIndex = token.startIndex,
      stopIndex = token.stopIndex,
    )
}
