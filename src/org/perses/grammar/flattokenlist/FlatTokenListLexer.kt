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
package org.perses.grammar.flattokenlist

import com.google.common.collect.ImmutableList
import org.antlr.v4.runtime.CommonToken
import org.antlr.v4.runtime.Lexer
import org.antlr.v4.runtime.Token
import org.perses.grammar.AbstractLexerAdaptor
import org.perses.grammar.AbstractTwinLexerAntlrBridge
import org.perses.grammar.DroppedCharacter
import org.perses.grammar.ErrorTolerantLexer

/**
 * Reuses the target language's real lexer to tokenize the input, then re-emits every real token as
 * the single [PnfFlatTokenList.TOKEN] type while preserving its text and source position. The parser
 * (`start : TOKEN* EOF`) therefore builds a flat list of one node per real token -- exactly the shape
 * `topformflat`/`delta` operate on. The lexeme text is kept intact so downstream consumers (e.g.
 * [org.perses.reduction.reducer.line.TopFormFlatChunker]) can still recognize `{`, `}` and `;`.
 *
 * Unlike [org.perses.grammar.dyck.DyckLexer] this deliberately maps no brackets and
 * synthesizes no newline delimiters: the flat token list carries no nesting structure of its own.
 */
class FlatTokenListLexer(
  private val underlyingLexer: Lexer,
) : AbstractLexerAdaptor(underlyingLexer.inputStream) {
  override fun computeAllTokens(): ImmutableList<Token> {
    // The dropped characters the real lexer cannot tokenize (e.g. a `\` line-continuation in an
    // unparseable file) are merged in by source position. The canonical facade splices these back
    // into its tree as leaves; the flat list must carry them too, or reconstruction loses them --
    // which silently breaks a `\`-newline splice like `st\<newline>atic` into two tokens the C
    // preprocessor no longer rejoins.
    return ErrorTolerantLexer { underlyingLexer }
      .readAllDefaultChannelTokensWithDroppedCharacters(
        adaptToken = ::adaptToken,
        adaptDroppedCharacter = ::adaptDroppedCharacter,
      )
  }

  private fun adaptToken(oldToken: Token): Token =
    CommonToken(PnfFlatTokenList.TOKEN, oldToken.text).apply {
      charPositionInLine = oldToken.charPositionInLine
      line = oldToken.line
      startIndex = oldToken.startIndex
      stopIndex = oldToken.stopIndex
    }

  private fun adaptDroppedCharacter(dropped: DroppedCharacter): Token =
    CommonToken(PnfFlatTokenList.TOKEN, dropped.text).apply {
      charPositionInLine = dropped.column
      line = dropped.line
      startIndex = dropped.charIndex
      stopIndex = dropped.charIndex + dropped.text.length - 1
    }

  object BRIDGE : AbstractTwinLexerAntlrBridge(
    lexerClass = FlatTokenListLexer::class.java,
    parserClass = PnfFlatTokenList::class.java,
  )

  companion object {
    @JvmField
    val LEXER_WRAPPER = BRIDGE.lexerAtnWrapper
  }
}
