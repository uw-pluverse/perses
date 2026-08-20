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
package org.perses.antlr

import com.google.common.collect.ImmutableList
import org.perses.antlr.ast.AbstractPersesLexerRuleAst
import org.perses.antlr.ast.AbstractPersesRuleDefAst
import org.perses.antlr.ast.PersesGrammar
import org.perses.antlr.ast.PersesLexerRuleAst
import org.perses.antlr.ast.PersesParserRuleAst
import org.perses.util.toImmutableList

abstract class AbstractAntlrGrammar(
  val startRuleName: String,
) {
  abstract val isCombined: Boolean

  val parserRules: ImmutableList<PersesParserRuleAst> by lazy {
    computeParserRules()
  }

  val allLexerRules: ImmutableList<AbstractPersesLexerRuleAst> by lazy {
    computeLexerRules()
  }

  val lexerRules: ImmutableList<PersesLexerRuleAst> by lazy {
    allLexerRules.filterIsInstance<PersesLexerRuleAst>().toImmutableList()
  }

  val combinedRules: ImmutableList<AbstractPersesRuleDefAst> by lazy {
    val builder =
      ImmutableList
        .builderWithExpectedSize<AbstractPersesRuleDefAst>(parserRules.size + allLexerRules.size)
    builder.addAll(allLexerRules)
    builder.addAll(parserRules)
    builder.build()
  }

  abstract fun computeParserRules(): ImmutableList<PersesParserRuleAst>

  abstract fun computeLexerRules(): ImmutableList<AbstractPersesLexerRuleAst>

  open fun asCombined(): CombinedAntlrGrammar {
    check(isCombined)
    throw UnsupportedOperationException()
  }

  open fun asSeparate(): SeparateAntlrGrammar {
    check(!isCombined)
    throw UnsupportedOperationException()
  }

  class CombinedAntlrGrammar(
    startRuleName: String,
    val grammar: PersesGrammar,
  ) : AbstractAntlrGrammar(startRuleName) {
    override val isCombined = true

    init {
      require(grammar.grammarType == PersesGrammar.GrammarType.COMBINED) {
        "The given grammar is ${grammar.grammarType}, " +
          "but expected to be ${PersesGrammar.GrammarType.COMBINED}"
      }
    }

    override fun computeLexerRules(): ImmutableList<AbstractPersesLexerRuleAst> =
      grammar.lexerRules.flattenedLexerRules

    override fun computeParserRules(): ImmutableList<PersesParserRuleAst> = grammar.parserRules

    override fun asCombined() = this
  }

  class SeparateAntlrGrammar(
    startRuleName: String,
    val parserGrammar: PersesGrammar,
    val lexerGrammar: PersesGrammar,
  ) : AbstractAntlrGrammar(startRuleName) {
    override val isCombined = false

    init {
      require(
        parserGrammar.grammarType == PersesGrammar.GrammarType.PARSER ||
          parserGrammar.grammarType == PersesGrammar.GrammarType.COMBINED,
      ) {
        parserGrammar.grammarType
      }
      require(lexerGrammar.grammarType == PersesGrammar.GrammarType.LEXER)
    }

    override fun computeParserRules(): ImmutableList<PersesParserRuleAst> =
      parserGrammar.parserRules

    override fun computeLexerRules(): ImmutableList<AbstractPersesLexerRuleAst> =
      lexerGrammar.lexerRules.flattenedLexerRules

    override fun asSeparate() = this
  }
}
