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
package org.perses.antlr.pnf

import com.google.common.collect.ImmutableList
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.PersesAlternativeBlockAst
import org.perses.antlr.ast.PersesAstBuilder.Companion.combineIntoSequence
import org.perses.antlr.ast.PersesEpsilonAst
import org.perses.antlr.ast.PersesOptionalAst
import org.perses.antlr.ast.PersesRuleReferenceAst
import org.perses.antlr.ast.PersesSequenceAst
import org.perses.antlr.ast.RuleNameRegistry.RuleNameHandle
import org.perses.antlr.pnf.RuleRefCounterAstVisitor.Companion.countRuleReferences

class StarRightIntroducerPass : AbstractStarIntroducerPass() {
  override fun classifyAndExtractPartsFromSequenceDef(
    mutableGrammar: MutableGrammar,
    ruleName: RuleNameHandle,
    sequenceDef: PersesSequenceAst,
    nonRecursivePartsInRecursiveDef: ArrayList<AbstractPersesRuleElement>,
    nonRecursiveDefs: LinkedHashSet<AbstractPersesRuleElement>,
  ) {
    val last = sequenceDef.lastChild
    val rest = sequenceDef.subsequence(0, sequenceDef.childCount - 1)
    if (isRefTo(last, ruleName)) {
      nonRecursivePartsInRecursiveDef.add(rest)
      return
    }
    val tailAlternatives = resolveOptionalTail(mutableGrammar, ruleName, last)
    if (tailAlternatives != null && tailAlternatives.any { isRefTo(lastElementOf(it), ruleName) }) {
      // `Y (Z a)?` is `Y | Y Z a`, so expanding the optional exposes the recursion.
      // OptionalIntroducerPass merges `Y | Y Z a` back into `Y (Z a)?`, so this is the
      // only chance to turn it into `(Y Z)* Y`.
      nonRecursiveDefs.add(rest)
      for (alternative in tailAlternatives) {
        if (isRefTo(lastElementOf(alternative), ruleName)) {
          nonRecursivePartsInRecursiveDef.add(
            combineIntoSequence(ImmutableList.of(rest, withoutLastElement(alternative))),
          )
        } else {
          nonRecursiveDefs.add(combineIntoSequence(ImmutableList.of(rest, alternative)))
        }
      }
      return
    }
    nonRecursiveDefs.add(sequenceDef)
  }

  override fun constructNewSequenceDef(
    nonRecursiveDef: AbstractPersesRuleElement,
    starRuleRef: PersesRuleReferenceAst,
  ): ImmutableList<AbstractPersesRuleElement> = ImmutableList.of(starRuleRef, nonRecursiveDef)

  /**
   * Returns the alternatives of the optional's body when [element] is `(...)?`, either inline
   * or outlined by QuantifiedAstNormalizationPass as `optional__x : aux?` / `aux : ...`.
   */
  private fun resolveOptionalTail(
    mutableGrammar: MutableGrammar,
    ruleName: RuleNameHandle,
    element: AbstractPersesRuleElement,
  ): List<AbstractPersesRuleElement>? {
    val optional =
      when (element) {
        is PersesOptionalAst -> element
        is PersesRuleReferenceAst ->
          singleAlternativeOf(mutableGrammar, element.ruleNameHandle) as? PersesOptionalAst
        else -> null
      } ?: return null
    val body = optional.body
    return when {
      body is PersesAlternativeBlockAst -> body.childSequence().toList()
      // Only a rule private to this optional may be expanded; expanding a shared rule would
      // duplicate its alternatives here and drop its node from the parse tree.
      body is PersesRuleReferenceAst &&
        body.ruleNameHandle != ruleName &&
        isReferencedOnce(mutableGrammar, body.ruleNameHandle) ->
        mutableGrammar.getAltBlock(body.ruleNameHandle).toList()
      else -> listOf(body)
    }
  }

  private fun isReferencedOnce(
    mutableGrammar: MutableGrammar,
    ruleName: RuleNameHandle,
  ): Boolean =
    mutableGrammar.containsRule(ruleName) &&
      mutableGrammar.alternativeSequence().sumOf { countRuleReferences(ruleName, it) } == 1

  private fun singleAlternativeOf(
    mutableGrammar: MutableGrammar,
    ruleName: RuleNameHandle,
  ): AbstractPersesRuleElement? {
    if (!mutableGrammar.containsRule(ruleName)) {
      return null
    }
    val altBlock = mutableGrammar.getAltBlock(ruleName)
    return if (altBlock.size() == 1) altBlock[0] else null
  }

  private fun isRefTo(
    element: AbstractPersesRuleElement,
    ruleName: RuleNameHandle,
  ) = element is PersesRuleReferenceAst && element.ruleNameHandle == ruleName

  private fun lastElementOf(element: AbstractPersesRuleElement) =
    if (element is PersesSequenceAst) element.lastChild else element

  private fun withoutLastElement(element: AbstractPersesRuleElement): AbstractPersesRuleElement =
    if (element is PersesSequenceAst) {
      element.subsequence(0, element.childCount - 1)
    } else {
      PersesEpsilonAst()
    }
}
