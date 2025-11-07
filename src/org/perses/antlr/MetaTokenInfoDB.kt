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

import com.google.common.collect.ImmutableList
import org.antlr.v4.runtime.Lexer
import org.antlr.v4.runtime.Vocabulary
import org.antlr.v4.runtime.atn.ATN
import org.apache.commons.text.StringEscapeUtils
import org.perses.util.ReflectionUtil
import org.perses.util.toImmutableList
import org.perses.util.toImmutableMap

class MetaTokenInfoDB(
  val lexerClass: Class<out Lexer>,
  val tokens: ImmutableList<TokenInfoEntry>,
) {
  val allLiteralLexemes = tokens.mapNotNull { it.literalLexeme }.toImmutableList()

  private val nameToTokenMapping =
    tokens.toImmutableMap(
      keyFunc = { it.symbolicName },
      valueFunc = { it },
    )

  private val typeToTokenMapping =
    tokens.toImmutableMap(
      keyFunc = { it.tokenType },
      valueFunc = { it },
    )

  private val ruleIndexToTokenInformation =
    tokens.toImmutableMap(
      keyFunc = { it.ruleIndex },
      valueFunc = { it },
    )

  fun hasToken(tokenType: TokenType): Boolean = getTokenInfoWithType(tokenType) != null

  fun getMaxAntlrTokenType(): TokenType = tokens.maxBy { it.tokenType.antlrTokenType }.tokenType

  fun getTokenInfoWithName(tokenName: String) = nameToTokenMapping[tokenName]

  fun getTokenInfoWithType(tokenType: TokenType) = typeToTokenMapping[tokenType]

  fun getTokenInfoWithRuleIndex(ruleIndex: RuleIndex) = ruleIndexToTokenInformation[ruleIndex]

  fun asSequence(): Sequence<TokenInfoEntry> = nameToTokenMapping.values.asSequence()

  data class TokenInfoEntry(
    val symbolicName: String,
    val tokenType: TokenType,
    val ruleIndex: RuleIndex,
    val literalLexeme: String?,
  )

  companion object {
    fun <T : Lexer> createForLexerClass(lexerClass: Class<T>): Pair<MetaTokenInfoDB, ATN> {
      val atn =
        AntlrGrammarUtil.getAtnFromLexer(lexerClass)
          ?: error("Atn does not exist in $lexerClass")
      val tokenNameAndTypeMap = TokenNameAndTokenTypeMapping(lexerClass)
      val vocabulary = getVocabulary(lexerClass)
      val tokenInfoList =
        atn.ruleToTokenType
          .withIndex()
          .asSequence()
          .filter {
            // 0 means nothing. Token type starts from 1
            it.value != 0
          }.map { (ruleIndex, tokenType) ->
            TokenInfoEntry(
              symbolicName =
                tokenNameAndTypeMap.getSymbolicTokenName(tokenType)
                  ?: error("No name for the token type $tokenType. $tokenNameAndTypeMap"),
              tokenType = TokenType(tokenType),
              ruleIndex = RuleIndex(ruleIndex),
              literalLexeme =
                vocabulary.getLiteralName(tokenType)?.let {
                  StringEscapeUtils.unescapeJava(it.substring(1, it.length - 1))
                },
            )
          }.toImmutableList()
      return MetaTokenInfoDB(
        lexerClass,
        tokenInfoList,
      ) to atn
    }

    private fun getVocabulary(lexerClass: Class<out Lexer>) =
      ReflectionUtil.readStaticField<Vocabulary>(lexerClass, "VOCABULARY")
  }
}
