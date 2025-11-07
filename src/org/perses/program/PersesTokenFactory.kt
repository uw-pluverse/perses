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
package org.perses.program

import com.google.common.base.MoreObjects
import org.antlr.v4.runtime.CharStream
import org.antlr.v4.runtime.Token
import org.antlr.v4.runtime.TokenSource
import org.perses.antlr.TokenType
import org.perses.util.Util.lazyAssert

class PersesTokenFactory {
  class Lexeme(
    val id: Int,
    val text: String,
  ) {
    override fun toString(): String =
      MoreObjects
        .toStringHelper(this)
        .addValue("'$text'")
        .toString()
  }

  private val lexemeMap = HashMap<String, Lexeme>(300)

  @Synchronized
  private fun getOrCreateLexeme(text: String): Lexeme {
    val lexeme =
      lexemeMap.computeIfAbsent(text) {
        Lexeme(id = lexemeMap.size, text = it)
      }
    lazyAssert { lexeme.text == text }
    return lexeme
  }

  fun doesLexemeExist(lexeme: String) = lexemeMap.contains(lexeme)

  fun createPersesToken(token: Token): PersesAntlrToken {
    val lexeme = getOrCreateLexeme(token.text)
    return createFromAntlrToken(
      lexeme,
      token,
    ).also { lazyAssert { it.lexemeText === lexeme.text } }
  }

  fun copyPersesTokenWithNewText(
    newText: String,
    existing: PersesAntlrToken,
  ): PersesAntlrToken {
    val lexeme = getOrCreateLexeme(text = newText)
    return existing.copyWithNewLexeme(lexeme).also {
      lazyAssert { it.lexemeText === lexeme.text }
    }
  }

  fun createPlaceholderTokenForGivenType(tokenType: TokenType): PersesTokenPlaceholder =
    PersesTokenPlaceholder(tokenType)

  fun createPlainTextToken(text: String): PersesPlainText {
    val lexeme = getOrCreateLexeme(text)
    return PersesPlainText(lexeme)
  }

  fun numOfLexemes() = lexemeMap.size

  private fun createFromAntlrToken(
    lexeme: Lexeme,
    token: Token,
  ): PersesAntlrToken =
    PersesAntlrToken(
      lexeme = lexeme,
      tokenType = TokenType(token.type),
      position = TokenPosition(line = token.line, charPositionInLine = token.charPositionInLine),
      channel = token.channel,
      tokenIndex = token.tokenIndex,
      startIndex = token.startIndex,
      stopIndex = token.stopIndex,
    )

  // TODO(cnsun): refactor this into a separate class.
  data class TokenPosition(
    val line: Int,
    val charPositionInLine: Int,
  ) {
    // TODO: need to enable these assertions.
//    init {
//      require(line >= 0) { line }
//      require(charPositionInLine >= 0) { charPositionInLine }
//    }
  }

  sealed class AbstractPersesToken {
    abstract val persesLexemeId: Int

    abstract val lexemeText: String

    open val tokenType: TokenType
      get() = error("Cannot call this method on ${this::class}")

    companion object {
      const val PLACEHOLDER_LEXEME_ID = -1000
      const val INVALID_TOKEN_ID = -2000
      const val PLAIN_TEXT_ID = -3000
    }

    fun isPlaceholder() = this is PersesTokenPlaceholder

    fun isPlainText() = this is PersesPlainText

    open fun asAntlrToken(): PersesAntlrToken {
      error("Cannot cast ${this::class} to ${PersesAntlrToken::class}")
    }
  }

  data object InvalidToken : AbstractPersesToken() {
    override val lexemeText: String
      get() = "<!INVALID_TOKEN!>"

    override val persesLexemeId: Int
      get() = INVALID_TOKEN_ID
  }

  class PersesTokenPlaceholder(
    override val tokenType: TokenType,
  ) : AbstractPersesToken() {
    override val lexemeText: String
      get() = "<!PLACEHOLDER!>"

    override val persesLexemeId: Int
      get() = PLACEHOLDER_LEXEME_ID

    val type = tokenType.antlrTokenType
  }

  class PersesPlainText(
    val lexeme: Lexeme,
  ) : AbstractPersesToken() {
    override val persesLexemeId: Int
      get() = lexeme.id

    override val lexemeText: String
      get() = lexeme.text

    override fun toString(): String = MoreObjects.toStringHelper(this).addValue(lexeme).toString()
  }

  class PersesAntlrToken internal constructor(
    val lexeme: Lexeme,
    override val tokenType: TokenType,
    val position: TokenPosition,
    private val channel: Int,
    private val tokenIndex: Int,
    private val startIndex: Int,
    private val stopIndex: Int,
    // Do not keep a reference to the token, as token might hold a reference to a large string.
  ) : AbstractPersesToken(),
    Token {
    override val lexemeText: String
      get() = lexeme.text

    override val persesLexemeId: Int
      get() = lexeme.id

    override fun getText(): String = lexemeText

    override fun asAntlrToken(): PersesAntlrToken = this

    override fun getType() = tokenType.antlrTokenType

    @Deprecated("", ReplaceWith("position"), level = DeprecationLevel.ERROR)
    override fun getLine() = position.line

    @Deprecated("", ReplaceWith("position"), level = DeprecationLevel.ERROR)
    override fun getCharPositionInLine() = position.charPositionInLine

    override fun getChannel() = channel

    override fun getTokenIndex() = tokenIndex

    override fun getStartIndex() = startIndex

    override fun getStopIndex() = stopIndex

    override fun getTokenSource(): TokenSource = throw UnsupportedOperationException()

    override fun getInputStream(): CharStream = throw UnsupportedOperationException()

    override fun toString() =
      MoreObjects
        .toStringHelper(this)
        .addValue("'$lexemeText'")
        .add("line", position.line)
        .add("column", position.charPositionInLine)
        .toString()

    fun copyWithNewLexeme(newLexeme: Lexeme): PersesAntlrToken =
      PersesAntlrToken(
        lexeme = newLexeme,
        tokenType = tokenType,
        position = position,
        channel = channel,
        tokenIndex = tokenIndex,
        startIndex = startIndex,
        stopIndex = stopIndex,
      )

    fun copyWithNewPosition(newPosition: TokenPosition): PersesAntlrToken =
      PersesAntlrToken(
        lexeme = lexeme,
        tokenType = tokenType,
        position = newPosition,
        channel = channel,
        tokenIndex = tokenIndex,
        startIndex = startIndex,
        stopIndex = stopIndex,
      )

    fun copy(): PersesAntlrToken = copyWithNewPosition(position)

    companion object {
    }
  }
}
