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
import org.perses.antlr.ast.AstTag
import org.perses.antlr.ast.PersesAlternativeBlockAst
import org.perses.antlr.ast.PersesEpsilonAst
import org.perses.antlr.ast.PersesOptionalAst
import org.perses.antlr.ast.RuleNameRegistry.RuleNameHandle
import org.perses.antlr.ast.TransformDecision

class EliminateEpsilonPass : AbstractPnfPass() {

  override fun processGrammar(
    grammar: GrammarPair,
  ): GrammarPair {
    val parserGrammar = grammar.parserGrammar ?: return grammar
    val epsilonList = parserGrammar.parserRules
      .asSequence()
      .filter {
        val body = it.body
        body.tag == AstTag.EPSILON ||
          (
            body is PersesAlternativeBlockAst &&
              body.alternatives.any { alt -> alt.tag == AstTag.EPSILON }
            )
      }
      .map { it.ruleNameHandle }
      .distinct()
      .toList()
    if (epsilonList.isEmpty()) {
      return grammar
    }
    val mutable = MutableGrammar.createParserRulesFrom(parserGrammar)
    // TODO: need to introduce a fixpoint loop, and delete epsilon from sequences.
    val singleEpsilonRuleList = ArrayList<RuleNameHandle>()
    epsilonList.forEach { ruleName ->
      val altBlock = mutable.getAltBlock(ruleName)
      assert(altBlock.containsEquivalent(PersesEpsilonAst()))
      if (altBlock.size() == 1) {
        check(altBlock[0].tag == AstTag.EPSILON)
        singleEpsilonRuleList.add(ruleName)
        return@forEach
      }
      check(altBlock.size() > 1) { altBlock }
      check(altBlock.removeAltIf { it.tag == AstTag.EPSILON })
      val remaining = ImmutableList.copyOf(altBlock.asIterable())
      altBlock.clear()
      altBlock.addIfNotEquivalent(
        PersesOptionalAst.createGreedy(
          AstUtil.createAltBlockIfNecessary(remaining),
        ),
      )
    }
    val edits = ArrayList<RuleEditTriple>()
    singleEpsilonRuleList.forEach { epsilonRuleName ->
      mutable.ruleNameAltPairSequence().forEach {
        if (RuleRefCounterAstVisitor.countRuleRefences(epsilonRuleName, it.value) > 0) {
          val edit = InlineEpsilonRuleEdit(epsilonRuleName)
          val decision = edit.apply(it.value)
          when (decision) {
            is TransformDecision.Keep -> Unit // do nothing.
            is TransformDecision.Replace ->
              edits.add(
                RuleEditTriple(name = it.key, oldDef = it.value, newDef = decision.newValue),
              )
            else -> TODO(decision.toString())
          }
        }
      }
    }
    edits.forEach { it.applyTo(mutable) }

    return grammar.withNewParserGrammar(
      parserGrammar.copyWithNewParserRuleDefs(mutable.toParserRuleAstList()),
    )
  }
}
