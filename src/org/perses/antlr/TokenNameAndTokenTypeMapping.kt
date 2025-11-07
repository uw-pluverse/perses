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
package org.perses.antlr

import com.google.common.base.MoreObjects
import com.google.common.collect.ImmutableBiMap
import org.antlr.v4.runtime.Lexer
import org.perses.util.ReflectionUtil
import org.perses.util.toImmutableBiMap
import org.perses.util.toImmutableList

/**
 * Note that this class is better than Vocabulary. Vocabulary does not have symbolic names
 * for inlined, unnamed tokens.
 *
 * Antlr generates symbolic token names for unnamed tokens, but these symbolic names are not
 * included in Vocabulary.
 */
class TokenNameAndTokenTypeMapping(
  lexerClass: Class<out Lexer>,
) {
  @Suppress("UNCHECKED_CAST")
  private val ruleNames =
    ReflectionUtil
      .readStaticField<Array<String>>(lexerClass, "ruleNames")
      .toImmutableList()
  internal val bimap: ImmutableBiMap<String, Int> =
    ruleNames
      .asSequence()
      .mapNotNull { ruleName ->
        try {
          val index = ReflectionUtil.readStaticField<Int>(lexerClass, ruleName)
          ruleName to index
        } catch (e: NoSuchFieldException) {
          null // This might be a fragment.
        }
      }.toImmutableBiMap()

  fun getSymbolicTokenName(tokenType: Int): String? = bimap.inverse()[tokenType]

  fun getTokenType(symbolicTokenName: String): Int? = bimap[symbolicTokenName]

  override fun toString(): String =
    MoreObjects
      .toStringHelper(this)
      .add("ruleNames", ruleNames)
      .add("bimap", bimap)
      .toString()
}
