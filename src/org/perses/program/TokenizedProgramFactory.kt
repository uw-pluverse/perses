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

import com.google.common.collect.ImmutableList
import org.antlr.v4.runtime.Token

class TokenizedProgramFactory private constructor(
  // TODO: build an inverted index for this original program.
  val tokenFactory: PersesTokenFactory,
  val tokensInOrigin: ImmutableList<PersesToken>
) {

  fun create(tokens: List<Token>): TokenizedProgram {
    val persesTokens = tokens.asSequence().fold(
      ImmutableList.builderWithExpectedSize<PersesToken>(tokens.size),
      { builder, token -> builder.add(tokenFactory.getPersesToken(token)) }
    ).build()
    return TokenizedProgram(persesTokens)
  }

  companion object {
    @JvmStatic
    fun createFactory(originalProgram: List<Token>): TokenizedProgramFactory {
      val tokenFactoryBuilder = PersesTokenFactory.Builder()
      val persesTokens = originalProgram.asSequence().fold(
        ImmutableList.builderWithExpectedSize<PersesToken>(originalProgram.size),
        { builder, token -> builder.add(tokenFactoryBuilder.create(token)) }
      ).build()
      return TokenizedProgramFactory(tokenFactoryBuilder.build(), persesTokens)
    }
  }
}
