/*
 * Copyright (C) 2018-2022 University of Waterloo.
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

import com.google.common.collect.ImmutableList
import com.google.common.primitives.ImmutableIntArray
import org.antlr.v4.runtime.Token
import org.perses.util.toImmutableList

class TokenizedProgramFactory private constructor(
  // TODO: build an inverted index for this original program.
  val tokenFactory: PersesTokenFactory,
  val tokensInOrigin: ImmutableList<PersesTokenFactory.PersesToken>,
  val languageKind: LanguageKind
) {

  val histogram = ImmutableIntArray.copyOf(
    computeLexemeHistogram(tokenFactory, tokensInOrigin)
  )

  fun computeHistogramFor(program: TokenizedProgram): IntArray {
    assert(program.factory === this)
    return computeLexemeHistogram(tokenFactory, program.tokens)
  }

  fun create(tokens: List<Token>): TokenizedProgram {
    val persesTokens = tokens
      .asSequence()
      .map { tokenFactory.getPersesTokenOrThrow(it) }
      .toImmutableList()
    return TokenizedProgram(persesTokens, this)
  }

  companion object {

    @JvmStatic
    fun computeLexemeHistogram(
      tokenFactory: PersesTokenFactory,
      tokensInOrigin: ImmutableList<PersesTokenFactory.PersesToken>
    ): IntArray {
      val histogram = IntArray(tokenFactory.numOfLexemes())
      for (token in tokensInOrigin) {
        ++histogram[token.persesLexemeId]
      }
      return histogram
    }

    @JvmStatic
    fun createFactory(
      originalProgram: List<Token>,
      languageKind: LanguageKind
    ): TokenizedProgramFactory {
      val tokenFactory = PersesTokenFactory()
      val persesTokens = originalProgram
        .asSequence()
        .map { tokenFactory.createPersesToken(it) }
        .toImmutableList()
      return TokenizedProgramFactory(tokenFactory, persesTokens, languageKind)
    }
  }
}
