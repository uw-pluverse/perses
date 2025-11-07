/*
 * Copyright (C) 2018-2025 University of Waterloo.
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
package org.perses.grammar.dyck

import com.google.common.collect.ImmutableList
import org.antlr.v4.runtime.CommonToken
import org.antlr.v4.runtime.Lexer
import org.antlr.v4.runtime.Token
import org.perses.antlr.AntlrGrammarUtil
import org.perses.grammar.AbstractLexerAdaptor
import org.perses.util.transformToImmutableList

abstract class AbstractDyckLexer(
  private val underlyingLexer: Lexer,
) : AbstractLexerAdaptor(underlyingLexer.inputStream) {
  override fun computeAllTokens(): ImmutableList<Token> =
    AntlrGrammarUtil
      .readAllTokensInDefaultChannel(underlyingLexer)
      .transformToImmutableList { oldToken ->
        adaptToken(oldToken)
      }

  private fun adaptToken(oldToken: Token): Token {
    val text = oldToken.text
    val newToken = convertToNewToken(text)
    newToken.charPositionInLine = oldToken.charPositionInLine
    newToken.line = oldToken.line
    newToken.startIndex = oldToken.startIndex
    newToken.stopIndex = oldToken.stopIndex
    return newToken
  }

  protected abstract fun convertToNewToken(text: String): CommonToken
}
