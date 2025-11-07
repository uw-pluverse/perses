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
import com.google.common.collect.ImmutableList

/** A program represented by a list of tokens.  */
class TokenizedProgram(
  val tokens: ImmutableList<out PersesTokenFactory.AbstractPersesToken>,
  val factory: TokenizedProgramFactory,
) {
  val tokenCount: Int
    get() = tokens.size

  val totalCharacterCount: Int by lazy {
    tokens.sumOf { it.lexemeText.length }
  }

  override fun toString() = MoreObjects.toStringHelper(this).add("tokens", tokens).toString()

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
}
