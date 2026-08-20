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
package org.perses.grammar

import org.antlr.v4.runtime.Lexer
import org.antlr.v4.runtime.Parser
import org.antlr.v4.runtime.Vocabulary
import org.antlr.v4.runtime.atn.ATN
import org.antlr.v4.runtime.atn.ATNType
import org.perses.antlr.MetaTokenInfoDB
import org.perses.antlr.RuleIndex
import org.perses.antlr.TokenType
import org.perses.antlr.atn.LexerAtnWrapper
import org.perses.util.ReflectionUtil
import org.perses.util.toImmutableList

abstract class AbstractTwinLexerAntlrBridge(
  val lexerClass: Class<out Lexer>,
  val parserClass: Class<out Parser>,
) {
  val vocabulary = ReflectionUtil.readStaticField<Vocabulary>(parserClass, "VOCABULARY")

  val lexerAtnWrapper =
    run {
      val tokenInfoEntries =
        IntRange(0, vocabulary.maxTokenType)
          .asSequence()
          .mapNotNull { tokenType ->
            val symbolicName = vocabulary.getSymbolicName(tokenType) ?: return@mapNotNull null
            val literalLexeme: String? = vocabulary.getLiteralName(tokenType)
            val ruleIndex = tokenType - 1
            MetaTokenInfoDB.TokenInfoEntry(
              symbolicName = symbolicName,
              tokenType = TokenType(tokenType),
              ruleIndex = RuleIndex(ruleIndex),
              literalLexeme = literalLexeme,
            )
          }.toImmutableList()

      val metaTokenInfoDB = MetaTokenInfoDB(lexerClass = lexerClass, tokens = tokenInfoEntries)
      val atn =
        ATN(ATNType.LEXER, metaTokenInfoDB.getMaxAntlrTokenType().antlrTokenType).apply {
          ruleToTokenType = null
        }
      LexerAtnWrapper(
        atn = atn,
        metaTokenInfoDB = metaTokenInfoDB,
      )
    }
}
