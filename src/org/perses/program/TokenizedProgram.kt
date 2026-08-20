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
import com.google.common.collect.ImmutableList
import org.antlr.v4.runtime.Token
import org.perses.util.transformToImmutableList

/** A program represented by a list of tokens.  */
class TokenizedProgram(
  val tokens: ImmutableList<out AbstractPersesToken>,
) {
  val tokenCount: Int
    get() = tokens.size

  val totalCharacterCount: Int by lazy {
    tokens.sumOf { it.lexemeText.length }
  }

  val nonBlankCharacterCount: Int by lazy {
    tokens.sumOf { token ->
      token.lexemeText.count {
        !Character.isWhitespace(it)
      }
    }
  }

  override fun toString() = MoreObjects.toStringHelper(this).add("tokens", tokens).toString()

  fun <PayloadType : Any> computeSize(
    payload: PayloadType,
    canonicalTokenCount: Int?,
  ): ProgramSize<PayloadType> =
    ProgramSize(
      payload,
      canonicalTokenCount = canonicalTokenCount,
      surrogateTokenCount = tokenCount,
      totalCharacterCount = totalCharacterCount,
      nonBlankCharacterCount = nonBlankCharacterCount,
    )

  // TODO(cnsun): needs to be tested.
  fun haveSameLexemeSequence(that: TokenizedProgram): Boolean {
    val thisTokens = tokens
    val size = thisTokens.size
    val otherTokens = that.tokens
    if (size != otherTokens.size) {
      return false
    }
    for (i in 0 until size) {
      val thisToken = thisTokens[i]
      val otherToken = otherTokens[i]
      if (thisToken.lexemeText != otherToken.lexemeText) {
        return false
      }
    }
    return true
  }

  companion object {
    fun createForFreshAntlrLexemes(tokens: List<Token>): TokenizedProgram =
      TokenizedProgram(
        tokens.transformToImmutableList {
          PersesTokenFactory.createPersesToken(it, overridingPosition = null)
        },
      )
  }
}
