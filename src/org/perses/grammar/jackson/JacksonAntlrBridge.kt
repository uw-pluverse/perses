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
package org.perses.grammar.jackson

import com.fasterxml.jackson.core.JsonToken
import com.google.common.collect.ImmutableBiMap
import org.perses.grammar.AbstractTwinLexerAntlrBridge
import org.perses.util.ReflectionUtil

object JacksonAntlrBridge : AbstractTwinLexerAntlrBridge(
  lexerClass = JacksonLexer::class.java,
  parserClass = PnfJacksonParser::class.java,
) {
  val jacksonTokenTypeAntlrTokenTypeMapping =
    ImmutableBiMap
      .builder<JsonToken, Int>()
      .apply {
        val jsonTokenClass = JsonToken::class.java
        val parserClass = PnfJacksonParser::class.java
        lexerAtnWrapper.metaTokenInfoDB.tokens.forEach { tokenInfo ->
          val ruleName = tokenInfo.symbolicName
          val jsonToken = ReflectionUtil.readStaticField<JsonToken>(jsonTokenClass, ruleName)
          val tokenType = ReflectionUtil.readStaticField<Int>(parserClass, ruleName)
          check(tokenType == tokenInfo.tokenType.antlrTokenType) { ruleName }
          put(jsonToken, tokenType)
        }
      }.build()

  fun fromJacksonTokenTypeToAntlrTokenType(jacksonTokenType: JsonToken): Int {
    val result = jacksonTokenTypeAntlrTokenTypeMapping[jacksonTokenType]
    check(result != null) {
      """No antlr token type found for token type $jacksonTokenType.
        |$jacksonTokenTypeAntlrTokenTypeMapping
        |"
      """.trimMargin()
    }
    return result
  }

  init {
    // TODO(cnsun): tests
  }
}
