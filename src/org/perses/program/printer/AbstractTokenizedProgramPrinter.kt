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
package org.perses.program.printer

import org.antlr.v4.runtime.Lexer
import org.perses.antlr.atn.LexerAtnWrapper
import org.perses.program.AbstractLazySourceCode
import org.perses.program.PersesTokenFactory
import org.perses.program.TokenizedProgram

abstract class AbstractTokenizedProgramPrinter {

  abstract class AbstractTokenPositionProvider {
    abstract fun getLine(
      token: PersesTokenFactory.PersesToken,
    ): Int
    abstract fun getCharPositionInLine(
      token: PersesTokenFactory.PersesToken,
      currentCursorPositionInLine: Int,
      previousToken: PersesTokenFactory.PersesToken?,
    ): Int

    @Deprecated("Use getLine and getCharPositionInLine instead")
    fun getPosition(
      token: PersesTokenFactory.PersesToken,
      currentCursorPositionInLine: Int,
      previousToken: PersesTokenFactory.PersesToken?,
    ): PersesTokenFactory.TokenPosition {
      return PersesTokenFactory.TokenPosition(
        line = getLine(token),
        charPositionInLine = getCharPositionInLine(
          token,
          currentCursorPositionInLine,
          previousToken,
        ),
      )
    }

    companion object DefaultProvider : AbstractTokenPositionProvider() {
      override fun getLine(
        token: PersesTokenFactory.PersesToken,
      ): Int {
        return token.position.line
      }

      override fun getCharPositionInLine(
        token: PersesTokenFactory.PersesToken,
        currentCursorPositionInLine: Int,
        previousToken: PersesTokenFactory.PersesToken?,
      ): Int {
        return token.position.charPositionInLine
      }
    }
  }

  class DeducedPositionProvider(
    val lexerAtnWrapper: LexerAtnWrapper<out Lexer>,
  ) : AbstractTokenPositionProvider() {

    override fun getLine(token: PersesTokenFactory.PersesToken): Int {
      return token.position.line
    }

    override fun getCharPositionInLine(
      token: PersesTokenFactory.PersesToken,
      currentCursorPositionInLine: Int,
      previousToken: PersesTokenFactory.PersesToken?,
    ): Int {
      return if (previousToken == null) {
        token.position.charPositionInLine
      } else {
        if (lexerAtnWrapper.canBeConcatWithoutSpace(previousToken.type, token.type)) {
          currentCursorPositionInLine
        } else {
          currentCursorPositionInLine + 1
        }
      }
    }
  }

  abstract class AbstractTokenPlacementListener {
    abstract fun onTokenPlacement(
      token: PersesTokenFactory.PersesToken,
      line: Int,
      charPositionInLine: Int,
    )
  }

  abstract fun print(
    program: TokenizedProgram,
    tokenPlacementListener: AbstractTokenPlacementListener? = null,
  ): AbstractLazySourceCode

  override fun equals(other: Any?): Boolean {
    if (other == null) {
      return false
    }
    if (this === other) {
      return true
    }
    if (this::class.java !== other::class.java) {
      return false
    }
    if (hashCode() != other.hashCode()) {
      return false
    }
    return extraEquals(other)
  }

  protected abstract fun extraEquals(other: Any): Boolean

  override fun hashCode(): Int {
    return this::class.java.hashCode() * 31 + extraHashCode()
  }

  protected abstract fun extraHashCode(): Int
}
