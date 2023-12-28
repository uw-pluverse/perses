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

import com.google.common.annotations.VisibleForTesting
import com.google.common.collect.ImmutableList
import com.google.common.collect.LinkedHashMultimap
import org.perses.antlr.RuleType
import org.perses.antlr.ast.AbstractPersesQuantifiedAst
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.AstEdit
import org.perses.antlr.ast.AstTag
import org.perses.antlr.ast.PersesRuleReferenceAst
import org.perses.antlr.ast.RuleNameRegistry.RuleNameHandle
import org.perses.antlr.ast.TransformDecision
import org.perses.antlr.pnf.PnfUtil.getRuleTypeIfQuantifiedOrThrow
import org.perses.util.exhaustive

class QuantifiedAstNormalizationPass : AbstractPnfPass() {

  override fun processGrammar(
    grammar: GrammarPair,
  ): GrammarPair {
    val parserGrammar = grammar.parserGrammar ?: return grammar

    val mutable = MutableGrammar.createParserRulesFrom(parserGrammar)
    val toAdd = LinkedHashMultimap.create<RuleNameHandle, AbstractPersesRuleElement>()
    val toReplace = ArrayList<RuleEditTriple>()
    mutable.ruleNameAltPairSequence().forEach { (ruleName, oldDef) ->
      val factorEdit = FactorQuantifiedEdit(
        ruleName,
        isAlternativeBlock = mutable.getAltBlock(ruleName).size() > 1,
      )
      val decision = factorEdit.apply(oldDef)
      when (decision) {
        is TransformDecision.Keep -> {
          check(factorEdit.newRules.isEmpty) { factorEdit.newRules }
        }
        is TransformDecision.Replace -> {
          toReplace.add(RuleEditTriple(ruleName, oldDef, decision.newValue))
          factorEdit.newRules.ruleNameAltPairSequence().forEach {
            toAdd.put(it.key, it.value)
          }
        }
        else -> TODO(decision.toString())
      }.exhaustive
    }
    toReplace.forEach { it.applyTo(mutable) }
    toAdd.entries().forEach { mutable.getAltBlock(it.key).addIfNotEquivalent(it.value) }
    return grammar.withNewParserGrammar(
      parserGrammar.copyWithNewParserRuleDefs(mutable.toParserRuleAstList()),
    )
    // grammar.copyWithNewParserRuleDefs(mutable.toParserRuleAstList(grammar.))
  }

  /** Factors out the quantified parts to conform to the perses normal form.  */
  @VisibleForTesting
  class FactorQuantifiedEdit(
    val currentRuleName: RuleNameHandle,
    private val isAlternativeBlock: Boolean,
  ) : AstEdit() {

    val newRules = MutableGrammar()

    public override fun internalApply(
      element: AbstractPersesRuleElement,
      isRoot: Boolean,
    ): TransformDecision.NonDeleteTransformDecision {
      if (element !is AbstractPersesQuantifiedAst) {
        return TransformDecision.Keep(element)
      }

      check(element.childCount == 1) { element.sourceCode }
      val child = element.getChild(0)
      val possibleNewBody = if (isTerminalOrRuleRef(child)) {
        element
      } else {
        check(child !is AbstractPersesQuantifiedAst)
        val childRuleName = currentRuleName
          .createAuxiliaryRuleName(RuleType.OTHER_RULE)
        newRules.getAltBlock(childRuleName).decomposeAltBlockAndAddIfInequivalent(child)
        element.createWithNewChildren(
          ImmutableList.of(PersesRuleReferenceAst.create(childRuleName)),
        )
      }
      if (isRoot && !isAlternativeBlock) { // If this is NOT an alternative block.
        // No need to change.
        return if (possibleNewBody === element) {
          TransformDecision.Keep(element)
        } else {
          TransformDecision.Replace(oldValue = element, newValue = possibleNewBody)
        }
      }
      val kleeneRuleName = currentRuleName.createAuxiliaryRuleName(
        getRuleTypeIfQuantifiedOrThrow(element.tag!!),
      )
      newRules.getAltBlock(kleeneRuleName).addIfNotEquivalent(possibleNewBody)

      return TransformDecision.Replace(
        oldValue = element,
        newValue = PersesRuleReferenceAst.create(kleeneRuleName),
      )
    }

    companion object {
      private fun isTerminalOrRuleRef(ast: AbstractPersesRuleElement): Boolean {
        val tag = ast.tag
        return tag === AstTag.RULE_REF || tag === AstTag.TERMINAL
      }
    }
  }
}
