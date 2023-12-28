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

import com.google.common.collect.LinkedHashMultimap
import org.perses.antlr.ast.AbstractPersesRuleDefAst
import org.perses.antlr.ast.PersesGrammar
import org.perses.antlr.ast.RuleNameRegistry
import org.perses.util.toImmutableList

class DuplicateRuleEliminationPass(private val startRuleName: String) : AbstractPnfPass() {

  override fun processGrammar(
    grammar: GrammarPair,
  ): GrammarPair {
    val parserGrammar = grammar.parserGrammar ?: return grammar
    val startRuleName = parserGrammar
      .symbolTable
      .ruleNameRegistry
      .getOrThrow(startRuleName)
    val processedParserGramamr = AstUtil.fixpoint(parserGrammar) { inputGrammar ->
      val candidates = searchForCandidates(inputGrammar)
      if (candidates.isEmpty()) {
        return@fixpoint inputGrammar
      }
      val mutable = MutableGrammar.createParserRulesFrom(inputGrammar)
      for (rules in candidates) {
        require(rules.size > 1)
        val sortedRules = rules
          .asSequence()
          .filter { def: AbstractPersesRuleDefAst -> def.ruleNameHandle != startRuleName }
          .sortedBy { it.ruleNameHandle }
          .toImmutableList()
        var canonicalName: RuleNameRegistry.RuleNameHandle
        var others: List<AbstractPersesRuleDefAst>
        if (sortedRules.size == rules.size) {
          canonicalName = sortedRules[0].ruleNameHandle
          others = sortedRules.subList(1, sortedRules.size)
        } else {
          check(sortedRules.size + 1 == rules.size)
          canonicalName = startRuleName
          others = sortedRules
        }
        for (other in others) {
          val oldRuleName = other.ruleNameHandle
          mutable.removeRule(oldRuleName)
          RuleRefRenamingEdit.renameDefMap(mutable, oldRuleName, canonicalName)
        }
      }
      inputGrammar.copyWithNewParserRuleDefs(mutable.toParserRuleAstList())
    }
    return grammar.withNewParserGrammar(processedParserGramamr)
  }

  companion object {
    private fun searchForCandidates(
      persesGrammar: PersesGrammar,
    ): List<Set<AbstractPersesRuleDefAst>> {
      val map = LinkedHashMultimap.create<String, AbstractPersesRuleDefAst>()
      persesGrammar.flattenedAllRules
        .asSequence()
        .filter { it.isParserRule } // Not a fragment.
        .forEach { rule: AbstractPersesRuleDefAst -> map.put(rule.body.sourceCode, rule) }
      val duplicateRules = ArrayList<Set<AbstractPersesRuleDefAst>>()
      for (sourceCode in map.keySet()) {
        val ruleDefinitions = map[sourceCode]
        if (ruleDefinitions.size > 1) {
          duplicateRules.add(ruleDefinitions)
        }
      }
      return duplicateRules
    }
  }
}
