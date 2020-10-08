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

import it.unimi.dsi.fastutil.objects.Object2IntOpenHashMap
import org.antlr.v4.runtime.Token

class PersesTokenFactory
private constructor(private val lexeme2persesTokenIdMap: Object2IntOpenHashMap<String>) {

  class Builder {

    private val lexeme2persesTokenIdMap = Object2IntOpenHashMap<String>(200)

    init {
      lexeme2persesTokenIdMap.defaultReturnValue(DEFAULT_RETURN_VALUE)
    }

    fun create(token: Token): PersesToken {
      val lexeme = token.text
      var persesTokenId = lexeme2persesTokenIdMap.getInt(lexeme)
      if (persesTokenId == Int.MIN_VALUE) {
        persesTokenId = lexeme2persesTokenIdMap.size
        lexeme2persesTokenIdMap[lexeme] = persesTokenId
      }
      return PersesToken(persesTokenId, token)
    }

    fun build() = PersesTokenFactory(lexeme2persesTokenIdMap)
  }

  fun numOfLexemes() = lexeme2persesTokenIdMap.size

  fun getPersesToken(token: Token): PersesToken {
    val persesLexemeId = lexeme2persesTokenIdMap.getInt(token.text)
    check(persesLexemeId != DEFAULT_RETURN_VALUE)
    return PersesToken(persesLexemeId, token)
  }

  companion object {
    const val DEFAULT_RETURN_VALUE = Integer.MIN_VALUE
  }
}
