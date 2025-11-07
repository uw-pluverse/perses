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
package org.perses.program.printer

import org.perses.antlr.atn.LexerAtnWrapper
import org.perses.program.AbstractLazySourceCode
import org.perses.program.PersesTokenFactory
import org.perses.program.TokenizedProgram

abstract class AbstractTokenizedProgramPrinter {
  abstract class AbstractTokenPositionProvider {
    abstract fun getLine(token: PersesTokenFactory.AbstractPersesToken): Int

    abstract fun getCharPositionInLine(
      token: PersesTokenFactory.AbstractPersesToken,
      currentCursorPositionInLine: Int,
      previousToken: PersesTokenFactory.AbstractPersesToken?,
    ): Int

    companion object DefaultProvider : AbstractTokenPositionProvider() {
      override fun getLine(token: PersesTokenFactory.AbstractPersesToken): Int =
        token.asAntlrToken().position.line

      override fun getCharPositionInLine(
        token: PersesTokenFactory.AbstractPersesToken,
        currentCursorPositionInLine: Int,
        previousToken: PersesTokenFactory.AbstractPersesToken?,
      ): Int = token.asAntlrToken().position.charPositionInLine
    }
  }

  class DeducedPositionProvider(
    val lexerAtnWrapper: LexerAtnWrapper,
  ) : AbstractTokenPositionProvider() {
    override fun getLine(token: PersesTokenFactory.AbstractPersesToken): Int =
      token.asAntlrToken().position.line

    override fun getCharPositionInLine(
      token: PersesTokenFactory.AbstractPersesToken,
      currentCursorPositionInLine: Int,
      previousToken: PersesTokenFactory.AbstractPersesToken?,
    ): Int {
      return if (previousToken == null) {
        if (token.isPlainText()) {
          return currentCursorPositionInLine
        } else {
          token.asAntlrToken().position.charPositionInLine
        }
      } else {
        if (previousToken.isPlainText()) {
          currentCursorPositionInLine
        } else if (lexerAtnWrapper.canBeConcatWithoutSpace(
            previousToken.tokenType,
            token.tokenType,
          )
        ) {
          currentCursorPositionInLine
        } else {
          currentCursorPositionInLine + 1
        }
      }
    }
  }

  abstract class AbstractTokenPlacementListener {
    abstract fun onTokenPlacement(
      token: PersesTokenFactory.AbstractPersesToken,
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

  override fun hashCode(): Int = this::class.java.hashCode() * 31 + extraHashCode()

  protected abstract fun extraHashCode(): Int
}
