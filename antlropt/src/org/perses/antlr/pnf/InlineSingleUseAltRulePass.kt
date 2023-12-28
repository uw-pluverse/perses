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
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.AstTag
import org.perses.antlr.ast.PersesRuleReferenceAst
import org.perses.util.toImmutableList

class InlineSingleUseAltRulePass : AbstractPnfPass() {
  /**
   * Note that this method is intentionally written in this way, to make sure the new def keeps the
   * original order of alternatives, to avoid ambiguity.
   *
   * @param parserGrammar
   * @return
   *
   * FIXME(cnsun): this needs to be rewritten with the current [MutableGrammar].
   */
  override fun processGrammar(
    grammar: GrammarPair,
  ): GrammarPair {
    val parserGrammar = grammar.parserGrammar ?: return grammar
    val mutableGrammar = MutableGrammar.createParserRulesFrom(parserGrammar)
    val ruleNameList = getSortedRuleNames(mutableGrammar)
    for (ruleName in ruleNameList) {
      val origAlternatives = mutableGrammar.getAltBlock(ruleName).toImmutableList()
      val candidates = computeCandidates(mutableGrammar, origAlternatives)
      if (candidates.isEmpty()) {
        continue
      }
      // Note: we remove the old rule def, to make the alternatives in the new def have the same
      // order.
      mutableGrammar.removeRule(ruleName)
      val oldAltToNewAlts = LinkedHashMap<
        AbstractPersesRuleElement,
        ArrayList<AbstractPersesRuleElement>,
        >()
      for (alternative in origAlternatives) {
        val list = ArrayList<AbstractPersesRuleElement>()
        list.add(alternative)
        oldAltToNewAlts[alternative] = list
      }
      for (candidate in candidates) {
        val orig = candidate.orig
        val newAlts = oldAltToNewAlts[orig]!!
        newAlts.clear()
        assert(!candidate.replacements.isEmpty())
        newAlts.addAll(candidate.replacements)
      }
      val newAlternatives: List<AbstractPersesRuleElement> = oldAltToNewAlts.entries
        .asSequence()
        .flatMap { it.value.asSequence() }
        .toImmutableList()
      for (alt in newAlternatives) {
        if (isEquivalentToAny(alt, mutableGrammar.getAltBlock(ruleName))) {
          continue
        }
        mutableGrammar.getAltBlock(ruleName).addIfNotEquivalent(alt)
      }
    }
    return grammar.withNewParserGrammar(
      parserGrammar.copyWithNewParserRuleDefs(mutableGrammar.toParserRuleAstList()),
    )
  }

  private class Candidate(
    val orig: AbstractPersesRuleElement,
    val replacements: ImmutableList<AbstractPersesRuleElement>,
  )

  companion object {
    private fun computeCandidates(
      mutable: MutableGrammar,
      alternatives: Collection<AbstractPersesRuleElement>,
    ): ImmutableList<Candidate> {
      if (alternatives.isEmpty()) {
        return ImmutableList.of()
      }
      val builder = ImmutableList.builder<Candidate>()
      for (def in alternatives) {
        assert(def.tag !== AstTag.ALTERNATIVE_BLOCK)
        if (def.tag !== AstTag.RULE_REF) {
          continue
        }
        assert(def.tag === AstTag.RULE_REF)
        val ruleRef = def as PersesRuleReferenceAst
        if (countRulesThatCallsRuleOfName(mutable, ruleRef.ruleNameHandle) > 1) {
          // This rule is also used in other rules, and we do not inline it.
          continue
        }
        val calledRules = mutable.getAltBlock(ruleRef.ruleNameHandle)
        if (calledRules.size() < 2) {
          // TODO: maybe we can still inline it.
          // Not a rule with multiple alternatives.
          continue
        }
        // FIXME(cnsun): the logic here is not right.
        calledRules.forEach {
          builder.add(Candidate(def, ImmutableList.copyOf(calledRules)))
        }
      }
      return builder.build()
    }

    private fun isEquivalentToAny(
      element: AbstractPersesRuleElement,
      list: Iterable<AbstractPersesRuleElement>,
    ): Boolean {
      for (listEle in list) {
        if (listEle.isEquivalent(element)) {
          return true
        }
      }
      return false
    }
  }
}
