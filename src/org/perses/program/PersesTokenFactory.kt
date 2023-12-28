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
package org.perses.program

import com.google.common.base.MoreObjects
import org.antlr.v4.runtime.CharStream
import org.antlr.v4.runtime.CommonToken
import org.antlr.v4.runtime.Token
import org.antlr.v4.runtime.Token.DEFAULT_CHANNEL
import org.antlr.v4.runtime.TokenSource
import org.perses.antlr.TokenType
import org.perses.util.Util.lazyAssert

class PersesTokenFactory {

  class Lexeme(val id: Int, val text: String)

  private val lexemeMap = HashMap<String, Lexeme>(300)

  @Synchronized
  private fun getOrCreateLexeme(text: String): Lexeme {
    val lexeme = lexemeMap.computeIfAbsent(text) {
      Lexeme(id = lexemeMap.size, text = it)
    }
    lazyAssert { lexeme.text == text }
    return lexeme
  }

  fun doesLexemeExist(lexeme: String) = lexemeMap.contains(lexeme)

  fun createPersesToken(token: Token): PersesToken {
    val lexeme = getOrCreateLexeme(token.text)
    return createFromAntlrToken(
      lexeme,
      token,
    ).also { lazyAssert { it.text === lexeme.text } }
  }

  fun copyPersesTokenWithNewText(
    newText: String,
    existing: PersesToken,
  ): PersesToken {
    val lexeme = getOrCreateLexeme(text = newText)
    return existing.copyWithNewLexeme(lexeme).also {
      lazyAssert { it.text === lexeme.text }
    }
  }

  fun generatePlaceholderTokenForGivenType(tokenType: TokenType): PersesToken {
    return PersesToken(
      lexeme = Lexeme(id = Integer.MIN_VALUE, text = ""),
      type = tokenType,
      position = TokenPosition.INVALID,
      channel = DEFAULT_CHANNEL,
      tokenIndex = Integer.MIN_VALUE,
      startIndex = Integer.MIN_VALUE,
      stopIndex = Integer.MIN_VALUE,
      antlrTokenClass = AntlrTokenClass.PLACEHOLDER_TOKEN,
    )
  }

  fun numOfLexemes() = lexemeMap.size

  private fun createFromAntlrToken(lexeme: Lexeme, token: Token): PersesToken {
    return PersesToken(
      lexeme = lexeme,
      type = TokenType(token.type),
      position = TokenPosition(line = token.line, charPositionInLine = token.charPositionInLine),
      channel = token.channel,
      tokenIndex = token.tokenIndex,
      startIndex = token.startIndex,
      stopIndex = token.stopIndex,
      antlrTokenClass = AntlrTokenClass.COMMON_TOKEN,
    )
  }

  data class TokenPosition(
    val line: Int,
    val charPositionInLine: Int,
  ) {
    companion object {
      val INVALID = TokenPosition(line = Int.MIN_VALUE, charPositionInLine = Int.MIN_VALUE)
    }
  }
  enum class AntlrTokenClass(val antlrTokenClass: Class<out Token>?) {
    COMMON_TOKEN(CommonToken::class.java),
    PLACEHOLDER_TOKEN(null),
  }

  class PersesToken internal constructor(
    private val lexeme: Lexeme,
    val type: TokenType,
    val position: TokenPosition,
    private val channel: Int,
    private val tokenIndex: Int,
    private val startIndex: Int,
    private val stopIndex: Int,
    // ruleTagtoken representing an entire subtree matched by a parser rule
    // tokenTagToken means this is a Token object representing a token of a particular type
    val antlrTokenClass: AntlrTokenClass,
    /* Do not keep a reference to the token, as token might hold a reference to a large string.*/
  ) : Token {

    val persesLexemeId: Int
      get() = lexeme.id

    override fun getText() = lexeme.text

    override fun getType() = type.antlrTokenType

    @Deprecated("", ReplaceWith("position"), level = DeprecationLevel.ERROR)
    override fun getLine() = position.line

    @Deprecated("", ReplaceWith("position"), level = DeprecationLevel.ERROR)
    override fun getCharPositionInLine() = position.charPositionInLine

    override fun getChannel() = channel

    override fun getTokenIndex() = tokenIndex

    override fun getStartIndex() = startIndex

    override fun getStopIndex() = stopIndex

    override fun getTokenSource(): TokenSource {
      throw UnsupportedOperationException()
    }

    override fun getInputStream(): CharStream {
      throw UnsupportedOperationException()
    }

    override fun toString() =
      MoreObjects.toStringHelper(this).add("token", text).toString()

    fun copyWithNewLexeme(newLexeme: Lexeme): PersesToken {
      return PersesToken(
        lexeme = newLexeme,
        type = type,
        position = position,
        channel = channel,
        tokenIndex = tokenIndex,
        startIndex = startIndex,
        stopIndex = stopIndex,
        antlrTokenClass = antlrTokenClass,
      )
    }

    fun copyWithNewPosition(newPosition: TokenPosition): PersesToken {
      return PersesToken(
        lexeme = lexeme,
        type = type,
        position = newPosition,
        channel = channel,
        tokenIndex = tokenIndex,
        startIndex = startIndex,
        stopIndex = stopIndex,
        antlrTokenClass = antlrTokenClass,
      )
    }

    fun isPlaceholder() = antlrTokenClass == AntlrTokenClass.PLACEHOLDER_TOKEN

    companion object {
      val INVALID_TOKEN = PersesToken(
        lexeme = Lexeme(id = Integer.MIN_VALUE, text = ""),
        type = TokenType(Integer.MIN_VALUE),
        position = TokenPosition.INVALID,
        channel = Integer.MIN_VALUE,
        tokenIndex = Integer.MIN_VALUE,
        startIndex = Integer.MIN_VALUE,
        stopIndex = Integer.MIN_VALUE,
        antlrTokenClass = AntlrTokenClass.COMMON_TOKEN,
      )
    }
  }
}
