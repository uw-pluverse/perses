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

import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.PersesRuleElementOption
import org.perses.antlr.ast.PersesSequenceAst

class AssociativityParserRuleEliminatorPass :
  AbstractPnfPass() {

  override fun processGrammar(
    grammar: GrammarPair,
  ): GrammarPair {
    val parserGrammar = grammar.parserGrammar ?: return grammar
    val mutable = MutableGrammar.createParserRulesFrom(parserGrammar)
    val ruleNamesCopy = getSortedRuleNames(mutable)
    for (ruleName in ruleNamesCopy) {
      val definitions = mutable.getAltBlock(ruleName)
      if (!containsAssociativityElementOptionDef(definitions)) {
        continue
      }

      val newDefs = ArrayList<AbstractPersesRuleElement>(definitions.size())
      for (oldDef in definitions) {
        if (startsWithAssocElementOption(oldDef)) {
          newDefs.add((oldDef as PersesSequenceAst).subsequence(1))
        } else {
          newDefs.add(oldDef)
        }
      }
      mutable.removeRule(ruleName)
      mutable.getAltBlock(ruleName).addAllIfInequivalent(newDefs)
    }
    return grammar.withNewParserGrammar(
      parserGrammar.copyWithNewParserRuleDefs(mutable.toParserRuleAstList()),
    )
  }

  companion object {
    fun containsAssociativityElementOptionDef(
      defs: Iterable<AbstractPersesRuleElement>,
    ) =
      defs.asSequence().any { startsWithAssocElementOption(it) }

    fun startsWithAssocElementOption(def: AbstractPersesRuleElement): Boolean {
      if (def !is PersesSequenceAst || def.firstChild !is PersesRuleElementOption) {
        return false
      }
      val elementOption = def.firstChild as PersesRuleElementOption
      return "assoc" == elementOption.key
    }
  }
}
