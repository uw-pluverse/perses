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

import com.google.common.collect.ImmutableList
import org.antlr.v4.runtime.Lexer
import org.antlr.v4.runtime.Vocabulary
import org.apache.commons.text.StringEscapeUtils
import org.perses.util.toImmutableList
import org.perses.util.toImmutableMap

class MetaTokenInfoDB(
  val lexerClass: Class<out Lexer>,
  tokens: ImmutableList<TokenInfoEntry>,
) {

  val allLiteralLexemes = tokens.mapNotNull { it.literalLexeme }.toImmutableList()

  private val nameToTokenMapping = tokens
    .asSequence()
    .map { it.symbolicName to it }
    .toImmutableMap()

  private val typeToTokenMapping = tokens
    .asSequence()
    .map { it.tokenType to it }
    .toImmutableMap()

  private val ruleIndexToTokenInformation = tokens
    .asSequence()
    .map { it.ruleIndex to it }
    .toImmutableMap()

  fun getTokenInfoWithName(tokenName: String) =
    nameToTokenMapping[tokenName]

  fun getTokenInfoWithType(tokenType: TokenType) =
    typeToTokenMapping[tokenType]

  fun getTokenInfoWithRuleIndex(ruleIndex: RuleIndex) =
    ruleIndexToTokenInformation[ruleIndex]

  fun asSequence(): Sequence<TokenInfoEntry> = nameToTokenMapping.values.asSequence()

  data class TokenInfoEntry(
    val symbolicName: String,
    val tokenType: TokenType,
    val ruleIndex: RuleIndex,
    val literalLexeme: String?,
  )

  companion object {
    fun <T : Lexer> createFor(lexerClass: Class<T>): MetaTokenInfoDB {
      val atn = AntlrGrammarUtil.getAtnFromLexer(lexerClass)
      val tokenNameTypeMap = LexerRuleNameAndTypeMapping(lexerClass)
      val vocabulary = getVocabulary(lexerClass)
      return MetaTokenInfoDB(
        lexerClass,
        atn.ruleToTokenType
          .withIndex()
          .asSequence()
          .filter { it.value != 0 } // 0 means nothing.
          .map { (ruleIndex, tokenType) ->
            val tokenName = tokenNameTypeMap.getSymbolicTokenName(tokenType)!!
            val literal = vocabulary.getLiteralName(tokenType)?.let {
              StringEscapeUtils.unescapeJava(it.substring(1, it.length - 1))
            }
            TokenInfoEntry(tokenName, TokenType(tokenType), RuleIndex(ruleIndex), literal)
          }.toImmutableList(),
      )
    }

    private fun getVocabulary(lexerClass: Class<out Lexer>) =
      lexerClass.getField("VOCABULARY").get(null) as Vocabulary
  }
}
