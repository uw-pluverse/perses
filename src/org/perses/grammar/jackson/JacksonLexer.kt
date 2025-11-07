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
package org.perses.grammar.jackson

import com.fasterxml.jackson.dataformat.yaml.YAMLFactory
import com.google.common.collect.ImmutableList
import org.antlr.v4.runtime.CharStream
import org.antlr.v4.runtime.CommonToken
import org.antlr.v4.runtime.Token
import org.antlr.v4.runtime.misc.Interval
import org.perses.grammar.AbstractLexerAdaptor

class JacksonLexer(
  inputStream: CharStream,
) : AbstractLexerAdaptor(inputStream) {
  override fun computeAllTokens(): ImmutableList<Token> = tokenizeWithJackson(inputStream)

  companion object {
    fun tokenizeWithJackson(inputStream: CharStream): ImmutableList<Token> {
      val parser =
        YAMLFactory().createParser(
          inputStream.getText(Interval.of(0, inputStream.size() - 1)),
        )
      val builder = ImmutableList.Builder<Token>()
      while (true) {
        val tokenType = parser.nextToken() ?: break
        val antlrTokenType = JacksonAntlrBridge.fromJacksonTokenTypeToAntlrTokenType(tokenType)
        val lexeme = parser.text
        builder.add(CommonToken(antlrTokenType, lexeme))
      }
      return builder.build()
    }

    val bridge = JacksonAntlrBridge

    @JvmField
    val LEXER_WRAPPER = bridge.lexerAtnWrapper
  }
}
