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
package org.perses.antlr.pnf

import org.perses.antlr.ast.AbstractPersesRuleDefAst
import org.perses.antlr.ast.PersesGrammar
import org.perses.antlr.ast.PersesGrammar.GrammarType
import org.perses.antlr.ast.PersesLexerRuleAst
import org.perses.util.FileNameContentPair

data class GrammarPair(
  val parserGrammar: PersesGrammar?,
  val lexerGrammar: PersesGrammar?,
) {

  init {
    // TODO: enable the following test.
    if (parserGrammar != null) {
      val type = parserGrammar.grammarType
      // Note that a combined grammar can still have separate lexer parsers.
      require(type == GrammarType.COMBINED || type == GrammarType.PARSER)
    }
    if (lexerGrammar != null) {
      require(lexerGrammar.grammarType == GrammarType.LEXER)
    }
  }

  fun withNewParserGrammar(parserGrammar: PersesGrammar): GrammarPair {
    return GrammarPair(parserGrammar, lexerGrammar)
  }

  fun withNewParserAndExtraLexerRules(
    parserGrammar: PersesGrammar,
    extraLexerRules: List<PersesLexerRuleAst>,
  ): GrammarPair {
    if (extraLexerRules.isEmpty()) {
      return withNewParserGrammar(parserGrammar)
    }
    return if (lexerGrammar == null) {
      val newLexerRules = parserGrammar.lexerRules.copyAndPrepend(extraLexerRules)
      val newParserGrammar = parserGrammar.copyWithNewLexerRuleDefs(newLexerRules)
      withNewParserGrammar(newParserGrammar)
    } else {
      val newLexerRules = lexerGrammar.lexerRules.copyAndPrepend(extraLexerRules)
      GrammarPair(parserGrammar, lexerGrammar.copyWithNewLexerRuleDefs(newLexerRules))
    }
  }

  fun isEquivalentTo(other: GrammarPair): Boolean {
    val pairs = listOf(
      Pair(parserGrammar, other.parserGrammar),
      Pair(lexerGrammar, other.lexerGrammar),
    )
    return pairs.all { (left, right) ->
      if ((left == null) != (right == null)) {
        return@all false
      }
      if (left == null && right == null) {
        return@all true
      }
      check(left != null && right != null)
      return@all left.isEquivalent(right)
    }
  }

  fun grammarSequence() = sequenceOf(parserGrammar, lexerGrammar).filterNotNull()

  fun flattenedAllRuleSequence(): Sequence<AbstractPersesRuleDefAst> {
    return grammarSequence()
      .flatMap { it.flattenedAllRules }
  }

  val combinedSourceCode by lazy {
    grammarSequence().joinToString(separator = "\n") { it.sourceCode }
  }

  fun convertParserToFileContentPair(): FileNameContentPair? {
    if (parserGrammar == null) {
      return null
    }
    return FileNameContentPair.createFromString(
      fileName = parserGrammar.computeAntlrBaseFileName(),
      content = parserGrammar.sourceCode,
    )
  }

  fun convertLexerToFileContentPair(): FileNameContentPair? {
    if (lexerGrammar == null) {
      return null
    }
    return FileNameContentPair.createFromString(
      fileName = lexerGrammar.computeAntlrBaseFileName(),
      content = lexerGrammar.sourceCode,
    )
  }
}
