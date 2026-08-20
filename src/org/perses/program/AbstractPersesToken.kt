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

import com.google.common.base.MoreObjects
import org.antlr.v4.runtime.CharStream
import org.antlr.v4.runtime.Token
import org.antlr.v4.runtime.TokenSource
import org.perses.antlr.TokenType

sealed class AbstractPersesToken {
  abstract val lexemeText: String

  open val tokenType: TokenType
    get() = error("Cannot call this method on ${this::class}")

  fun isPlaceholder() = this is Placeholder

  fun isPlainText() = this is PlainText

  open fun asAntlrToken(): AntlrToken {
    error("Cannot cast ${this::class} to ${AntlrToken::class}")
  }

  data object Invalid : AbstractPersesToken() {
    override val lexemeText: String
      get() = "<!INVALID_TOKEN!>"
  }

  class Placeholder(
    override val tokenType: TokenType,
  ) : AbstractPersesToken() {
    override val lexemeText: String
      get() = "<!PLACEHOLDER!>"

    val type = tokenType.antlrTokenType
  }

  class PlainText(
    override val lexemeText: String,
  ) : AbstractPersesToken() {
    override fun toString(): String =
      MoreObjects.toStringHelper(this).addValue(lexemeText).toString()
  }

  class AntlrToken internal constructor(
    override val lexemeText: String,
    override val tokenType: TokenType,
    val position: TokenPosition,
    private val channel: Int,
    private val tokenIndex: Int,
    private val startIndex: Int,
    private val stopIndex: Int,
    // Do not keep a reference to the token, as token might hold a reference to a large string.
  ) : AbstractPersesToken(),
    Token {
    override fun getText(): String = lexemeText

    override fun asAntlrToken(): AntlrToken = this

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

    fun copyWithNewLexemeText(newLexemeText: String): AntlrToken =
      AntlrToken(
        lexemeText = newLexemeText,
        tokenType = tokenType,
        position = position,
        channel = channel,
        tokenIndex = tokenIndex,
        startIndex = startIndex,
        stopIndex = stopIndex,
      )

    fun copyWithNewPosition(newPosition: TokenPosition): AntlrToken =
      AntlrToken(
        lexemeText = lexemeText,
        tokenType = tokenType,
        position = newPosition,
        channel = channel,
        tokenIndex = tokenIndex,
        startIndex = startIndex,
        stopIndex = stopIndex,
      )

    fun copy(): AntlrToken = copyWithNewPosition(position)
  }
}
