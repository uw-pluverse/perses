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

import org.perses.antlr.RuleType
import org.perses.antlr.ast.PersesRuleReferenceAst
import org.perses.antlr.ast.PersesTerminalAst

class ConvertAllAltToRuleReferenceOrTerminalPass : AbstractPnfPass() {

  override fun processGrammar(
    grammar: GrammarPair,
  ): GrammarPair {
    val parserGrammar = grammar.parserGrammar ?: return grammar
    val mutable = MutableGrammar.createParserRulesFrom(parserGrammar)
    mutable.nonEmptyAltBlockSequence()
      .toList() // Materialize the sequence to avoid concurrent modification exception
      .forEach { (name, altBlock) ->
        if (altBlock.size() < 2) {
          return@forEach
        }
        altBlock.asSequence()
          .filter { it !is PersesRuleReferenceAst && it !is PersesTerminalAst }
          .forEach { seq ->
            val ruleName = name.createAuxiliaryRuleName(RuleType.OTHER_RULE)
            mutable.getAltBlock(ruleName).addIfNotEquivalent(seq)
            altBlock.replace(seq, PersesRuleReferenceAst.create(ruleName))
          }
      }
    return grammar.withNewParserGrammar(
      parserGrammar.copyWithNewParserRuleDefs(mutable.toParserRuleAstList()),
    )
  }
}
