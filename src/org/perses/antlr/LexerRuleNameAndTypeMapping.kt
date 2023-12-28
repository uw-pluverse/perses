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
package org.perses.antlr

import com.google.common.collect.ImmutableBiMap
import org.antlr.v4.runtime.Lexer
import org.perses.util.toImmutableBiMap

class LexerRuleNameAndTypeMapping(lexerClass: Class<out Lexer>) {

  internal val bimap: ImmutableBiMap<String, Int>

  init {
    @Suppress("UNCHECKED_CAST")
    val names = lexerClass.getField("ruleNames").get(null) as Array<String>
    bimap = names.asSequence()
      .mapNotNull { symbolicName ->
        try {
          val index = lexerClass.getField(symbolicName).get(null) as Int
          symbolicName to index
        } catch (e: NoSuchFieldException) {
          null // This might be a fragment.
        }
      }.toImmutableBiMap()
  }

  fun getSymbolicTokenName(tokenType: Int): String? {
    return bimap.inverse()[tokenType]
  }

  fun getTokenType(symbolicTokenName: String): Int? {
    return bimap[symbolicTokenName]
  }
}
