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
package org.perses.grammar

import org.antlr.v4.runtime.CharStream
import org.antlr.v4.runtime.DefaultErrorStrategy
import org.antlr.v4.runtime.Parser
import org.antlr.v4.runtime.Token
import org.antlr.v4.runtime.TokenSource
import org.antlr.v4.runtime.misc.Pair

/**
 * A [DefaultErrorStrategy] whose [getMissingSymbol] tolerates a current token whose
 * [Token.getTokenSource] is null.
 *
 * The Dyck lexers wrap another lexer instead of reading a [CharStream] directly, so the tokens they
 * emit -- notably EOF -- can carry a null token source. Stock [DefaultErrorStrategy.getMissingSymbol]
 * fabricates the "missing" token via `current.tokenSource.inputStream` with no null check, so error
 * recovery on unbalanced input (a `{` with no matching `}`) NPEs deep in the generated parser instead
 * of recovering. This mirrors the stock logic but builds the fabricated token with a null
 * [CharStream] when the source is absent; the token carries explicit text, so the token factory does
 * not need the stream. Behaviour is identical to the stock strategy whenever the source is non-null,
 * so this is safe to use for every tolerant parse.
 */
class TolerantErrorStrategy : DefaultErrorStrategy() {
  override fun getMissingSymbol(recognizer: Parser): Token {
    val currentSymbol = recognizer.currentToken
    val expecting = getExpectedTokens(recognizer)
    val expectedTokenType = if (expecting.isNil) Token.INVALID_TYPE else expecting.minElement
    val tokenText =
      if (expectedTokenType == Token.EOF) {
        "<missing EOF>"
      } else {
        "<missing ${recognizer.vocabulary.getDisplayName(expectedTokenType)}>"
      }
    var current = currentSymbol
    val lookback = recognizer.inputStream.LT(-1)
    if (current.type == Token.EOF && lookback != null) {
      current = lookback
    }
    // The only departure from the stock implementation: null-safe access to the token source's stream.
    val source: TokenSource? = current.tokenSource
    return recognizer.tokenFactory.create(
      Pair<TokenSource?, CharStream?>(source, source?.inputStream),
      expectedTokenType,
      tokenText,
      Token.DEFAULT_CHANNEL,
      INVALID_INDEX,
      INVALID_INDEX,
      current.line,
      current.charPositionInLine,
    )
  }

  private companion object {
    private const val INVALID_INDEX = -1
  }
}
