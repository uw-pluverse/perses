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
import org.perses.antlr.ast.AbstractPersesRuleDefAst
import org.perses.antlr.ast.PersesGrammar

abstract class AbstractAntlrGrammar {

  abstract val isCombined: Boolean

  abstract fun getCombinedRules(): ImmutableList<AbstractPersesRuleDefAst>

  open fun asCombined(): CombinedAntlrGrammar {
    check(isCombined)
    throw UnsupportedOperationException()
  }

  open fun asSeparate(): SeparateAntlrGrammar {
    check(!isCombined)
    throw UnsupportedOperationException()
  }

  class CombinedAntlrGrammar(val grammar: PersesGrammar) :
    AbstractAntlrGrammar() {

    override val isCombined = true

    init {
      require(grammar.grammarType == PersesGrammar.GrammarType.COMBINED)
    }

    override fun getCombinedRules() = grammar.flattenedAllRules

    override fun asCombined() = this
  }

  class SeparateAntlrGrammar(val parserGrammar: PersesGrammar, val lexerGrammar: PersesGrammar) :
    AbstractAntlrGrammar() {

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

    override fun getCombinedRules(): ImmutableList<AbstractPersesRuleDefAst> {
      val builder = ImmutableList.builder<AbstractPersesRuleDefAst>()
      builder.addAll(lexerGrammar.flattenedAllRules)
      builder.addAll(parserGrammar.flattenedAllRules)
      return builder.build()
    }

    override fun asSeparate() = this
  }
}
