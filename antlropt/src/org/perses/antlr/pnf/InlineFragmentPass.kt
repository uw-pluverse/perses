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

import com.google.common.collect.ImmutableList
import org.perses.antlr.ast.AbstractPersesLexerRuleAst
import org.perses.antlr.ast.AstTag
import org.perses.antlr.ast.LexerRuleList
import org.perses.antlr.ast.PersesAlternativeBlockAst
import org.perses.antlr.ast.PersesTerminalAst
import org.perses.antlr.ast.RuleNameRegistry
import org.perses.antlr.ast.RuleNameRegistry.RuleNameHandle
import org.perses.antlr.ast.TransformDecision
import org.perses.util.toImmutableList

class InlineFragmentPass : AbstractPnfPass() {

  override fun processGrammar(
    grammar: GrammarPair,
  ): GrammarPair {
    val parserGrammar = grammar.parserGrammar ?: return grammar
    val allLexerRules = parserGrammar.lexerRules.flattenedLexerRules
    val mutableGrammar = MutableGrammar.createRulesFrom(allLexerRules)
    inlineLexerRules(
      mutableGrammar,
      rulesToInline = allLexerRules
        .asSequence()
        .filter { it.tag == AstTag.RULE_DEFINITION_LEXER_FRAGMENT }
        .map { it.ruleNameHandle }
        .toImmutableList(),
      ruleNameRegistry = parserGrammar.symbolTable.ruleNameRegistry,
    )
    inlineLexerRules(
      mutableGrammar,
      rulesToInline = allLexerRules
        .asSequence()
        .filter { it.tag == AstTag.RULE_DEFINITION_LEXER }
        .map { it.ruleNameHandle }
        .toImmutableList(),
      ruleNameRegistry = parserGrammar.symbolTable.ruleNameRegistry,
    )
    val defaultMode = transformLexerRules(
      parserGrammar.lexerRules.defaultModeLexerRules,
      mutableGrammar,
    )
    val nonDefaultModes = parserGrammar.lexerRules.nonDefaultModes
      .asSequence()
      .map { mode ->
        mode.copyWithNewLexerRules(transformLexerRules(mode.lexerRules, mutableGrammar))
      }.toImmutableList()
    val newLexerRules = LexerRuleList(defaultMode, nonDefaultModes)
    return grammar.withNewParserGrammar(parserGrammar.copyWithNewLexerRuleDefs(newLexerRules))
  }

  companion object {

    private fun inlineLexerRules(
      grammar: MutableGrammar,
      rulesToInline: List<RuleNameHandle>,
      ruleNameRegistry: RuleNameRegistry,
    ) {
      for (ruleName in rulesToInline) {
        var changed = true
        while (changed) {
          changed = false
          val altBlock = grammar.getAltBlock(ruleName)
          val originalAlts = altBlock.toImmutableList()
          for (originalAlt in originalAlts) {
            val usedRuleNames = UsedRuleNameCollector().let {
              it.preorder(originalAlt)
              it.tokenReferences
            }.map { ruleNameRegistry.getOrThrow(it) }
            if (usedRuleNames.isEmpty()) {
              continue
            }
            check(ruleName !in usedRuleNames) { "Recursion is not expected." }
            // We do not need to preserve the order of alternatives in lexer rules.
            altBlock.removeAlt(originalAlt)
            changed = true
            for (usedRuleName in usedRuleNames) {
              val usedRuleDef = grammar.getAltBlock(usedRuleName).asRuleBody()
              // TODO(cnsun): enable this check in the future.
//              check(usedRuleDef !is PersesLexerCommandAst) {
//                "Cannot inline a lexer command $usedRuleName into $ruleName"
//              }
              val replaceEdit = ReplaceEdit(
                oldPredicate = {
                  it is PersesTerminalAst &&
                    it.isTokenRef &&
                    it.text == usedRuleName.ruleName
                },
                newValueComputer = { usedRuleDef },
              )
              val decision = replaceEdit.apply(originalAlt)
              check(decision is TransformDecision.Replace) {
                "${decision::class}"
              }
              decision.newValue.let {
                if (it is PersesAlternativeBlockAst) {
                  it.alternatives.forEach {
                      alt ->
                    altBlock.addIfNotEquivalent(alt)
                  }
                } else {
                  altBlock.addIfNotEquivalent(decision.newValue)
                }
              }
            }
          }
        }
      }
    }

    fun transformLexerRules(
      rules: ImmutableList<AbstractPersesLexerRuleAst>,
      mutableGrammar: MutableGrammar,
    ): ImmutableList<AbstractPersesLexerRuleAst> {
      return rules
        .asSequence()
        .filter { it.tag == AstTag.RULE_DEFINITION_LEXER } // Delete fragments.
        .map { oldDef ->
          oldDef.copyWithNewBody(mutableGrammar.getAltBlock(oldDef.ruleNameHandle).asRuleBody())
        }.toImmutableList()
    }
  }
}
