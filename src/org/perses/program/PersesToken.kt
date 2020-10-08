/*
 * Copyright (C) 2018-2020 University of Waterloo.
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

class PersesToken internal constructor(val persesLexemeId: Int, token: Token) : Token {

  // Cache the token text, due to the uncertain way how Antlr returns lexeme.
  private val text: String = token.text
  private val type: Int = token.type
  private val line: Int = token.line
  private val charPositionInLine: Int = token.charPositionInLine
  private val channel: Int = token.channel
  private val tokenIndex: Int = token.tokenIndex
  private val startIndex: Int = token.startIndex
  private val stopIndex: Int = token.stopIndex

  override fun getText() = text

  override fun getType() = type

  override fun getLine() = line

  override fun getCharPositionInLine() = charPositionInLine

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

  override fun toString() = MoreObjects.toStringHelper(this).add("token", getText()).toString()
}
