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

import org.perses.antlr.ast.PersesGrammar
import org.perses.antlr.ast.RuleNameRegistry.RuleNameHandle
import org.perses.util.SimpleStack

class EliminateUnreachableRulePass(val startRuleName: String) : AbstractPnfPass() {

  override fun processGrammar(
    grammar: GrammarPair,
  ): GrammarPair {
    val parserGrammar = grammar.parserGrammar ?: return grammar
    val usedRuleNames = computeUsedRuleNames(parserGrammar)
    if (usedRuleNames.isEmpty()) {
      return grammar
    }
    val grammarWithOnlyUsedParserRules = MutableGrammar.createParserRulesFrom(parserGrammar)
      .let { mutableGrammar ->
        mutableGrammar.ruleNameSequence()
          .filter { ruleName ->
            ruleName !in usedRuleNames
          }.toList() // Materialize the rule names to avoid concurrent modification exception
          .forEach { mutableGrammar.removeRule(it) }
        parserGrammar.copyWithNewParserRuleDefs(mutableGrammar.toParserRuleAstList())
      }
    return grammar.withNewParserGrammar(grammarWithOnlyUsedParserRules)
  }

  private fun computeUsedRuleNames(
    grammar: PersesGrammar,
  ): LinkedHashSet<RuleNameHandle> {
    val ruleNameRegistry = grammar.symbolTable.ruleNameRegistry
    val rootRuleName = ruleNameRegistry.getOrThrow(startRuleName)
    val usedRules = LinkedHashSet<RuleNameHandle>()
    val visited = HashSet<RuleNameHandle>()
    val worklist = SimpleStack<RuleNameHandle>()

    usedRules.add(rootRuleName)
    worklist.add(rootRuleName)
    while (worklist.isNotEmpty()) {
      val ruleName = worklist.remove()
      if (!visited.add(ruleName)) {
        continue
      }
      grammar.getRuleDefinition(ruleName)!!.let { def ->
        val collector = UsedRuleNameCollector()
        collector.preorder(def.body)
        usedRules.addAll(collector.ruleReferences)
        worklist.addAll(collector.ruleReferences)
      }
    }
    return usedRules
  }
}
