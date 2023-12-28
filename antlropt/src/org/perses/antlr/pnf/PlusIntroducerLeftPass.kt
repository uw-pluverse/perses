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
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.AstEdit
import org.perses.antlr.ast.AstTag
import org.perses.antlr.ast.PersesAlternativeBlockAst
import org.perses.antlr.ast.PersesGrammar
import org.perses.antlr.ast.PersesPlusAst.Companion.createGreedy
import org.perses.antlr.ast.PersesPlusAst.Companion.createNonGreedy
import org.perses.antlr.ast.PersesRuleReferenceAst
import org.perses.antlr.ast.PersesRuleReferenceAst.Companion.create
import org.perses.antlr.ast.PersesSequenceAst
import org.perses.antlr.ast.PersesStarAst
import org.perses.antlr.ast.RuleNameRegistry.RuleNameHandle
import org.perses.antlr.ast.TransformDecision
import org.perses.util.exhaustive
import org.perses.util.toImmutableList

class PlusIntroducerLeftPass : AbstractPnfPass() {
  override fun processGrammar(
    grammar: GrammarPair,
  ): GrammarPair {
    val parserGrammar = grammar.parserGrammar ?: return grammar
    val mutable = MutableGrammar.createParserRulesFrom(parserGrammar)
    val edit = PlusIntroducerEdit(parserGrammar)
    val toUpdate = ArrayList<RuleEditTriple>()
    mutable.ruleNameAltPairSequence().forEach { (name, oldDef) ->
      check(oldDef.tag !== AstTag.ALTERNATIVE_BLOCK)
      val decision = edit.apply(oldDef)
      when (decision) {
        is TransformDecision.Keep -> return@forEach
        is TransformDecision.Replace ->
          toUpdate.add(RuleEditTriple(name, oldDef, decision.newValue))
        else -> TODO(decision.toString())
      }.exhaustive
    }
    toUpdate.forEach { it.applyTo(mutable) }
    edit.toAdd.forEach { key, value ->
      mutable.getAltBlock(key).addIfNotEquivalent(value)
    }
    return grammar.withNewParserGrammar(
      parserGrammar.copyWithNewParserRuleDefs(mutable.toParserRuleAstList()),
    )
  }

  @VisibleForTesting
  class PlusIntroducerEdit(private val grammar: PersesGrammar) : AstEdit() {
    @JvmField
    @VisibleForTesting
    val toAdd = LinkedHashMultimap
      .create<RuleNameHandle, AbstractPersesRuleElement>()

    public override fun internalApply(
      element: AbstractPersesRuleElement,
      isRoot: Boolean,
    ): TransformDecision.NonDeleteTransformDecision {
      val tag = element.tag
      if (tag !== AstTag.SEQUENCE) {
        return TransformDecision.Keep(element)
      }
      val childCount = element.childCount
      check(childCount > 1)
      val sequence = element as PersesSequenceAst
      val childrenCopy = ArrayList(sequence.children)
      var i = 0
      while (i < childCount) {
        val child = sequence.getChild(i)
        val childTag = child.tag
        check(childTag != null && !childTag.isQuantifier()) {
          "Quantified node is not expected here. " +
            "You can run a normalization pass before this pass to fix the problem."
        }
        if (childTag !== AstTag.RULE_REF) {
          ++i
          continue
        }
        val ruleName = (child as PersesRuleReferenceAst).ruleNameHandle
        val starAst = getStarIfIsKleeneStarRule(ruleName)
        if (starAst == null) {
          ++i
          continue
        }
        val quantified = starAst.body
        i = transformStarToPlus(sequence, i, childrenCopy, quantified, ruleName, starAst)
        ++i
      }
      val newChildren = childrenCopy
        .asSequence()
        .filter { it != null }
        .toImmutableList()
      check(element.tag === AstTag.SEQUENCE)
      check(newChildren.size > 0)
      val finalResult = if (newChildren.size == 1) {
        newChildren.single()
      } else {
        PersesSequenceAst(newChildren)
      }

      return if (finalResult.isEquivalent(sequence)) {
        // FIXME(cnsun): this is a bug, which needs to be fixed.
        //               check(!finalResult.isEquivalent(sequence)) {finalResult}
        TransformDecision.Keep(sequence)
      } else {
        TransformDecision.Replace(oldValue = sequence, newValue = finalResult)
      }
    }

    @VisibleForTesting
    fun transformStarToPlus(
      element: PersesSequenceAst,
      currentIndexOfStar: Int,
      newChildren: ArrayList<AbstractPersesRuleElement?>,
      bodyToMatch: AbstractPersesRuleElement,
      starRuleName: RuleNameHandle,
      starAst: PersesStarAst,
    ): Int {
      val bodySequence = if (bodyToMatch.tag === AstTag.SEQUENCE) {
        (bodyToMatch as PersesSequenceAst).children
      } else {
        ImmutableList.of(bodyToMatch)
      }
      if (reverseMatch(element, currentIndexOfStar - 1, bodySequence)) {
        newChildren[currentIndexOfStar] = mergeStarIntoPlus(starRuleName, starAst)
        var i = 0
        val size = bodySequence.size
        while (i < size) {
          newChildren[currentIndexOfStar - i - 1] = null
          ++i
        }
        return currentIndexOfStar
      }
      if (match(element, currentIndexOfStar + 1, bodySequence)) {
        newChildren[currentIndexOfStar] = mergeStarIntoPlus(starRuleName, starAst)
        var i = 0
        val size = bodySequence.size
        while (i < size) {
          newChildren[currentIndexOfStar + i + 1] = null
          ++i
        }
        return currentIndexOfStar + bodySequence.size
      }
      if (bodyToMatch.tag === AstTag.RULE_REF) {
        val ruleNameHandle = (bodyToMatch as PersesRuleReferenceAst).ruleNameHandle
        val ruleDef = grammar.getRuleDefinition(ruleNameHandle)!!
        if (ruleDef.body is PersesAlternativeBlockAst) {
          return currentIndexOfStar
        }
        return transformStarToPlus(
          element,
          currentIndexOfStar,
          newChildren,
          ruleDef.body,
          starRuleName,
          starAst,
        )
      }
      return currentIndexOfStar
    }

    private fun mergeStarIntoPlus(
      starRuleName: RuleNameHandle,
      starAst: PersesStarAst,
    ): PersesRuleReferenceAst {
      val plusRuleName = starRuleName.createAuxiliaryRuleName(RuleType.KLEENE_PLUS)
      //      toRemove.put(starRuleName, starAst);
      toAdd.put(
        plusRuleName,
        if (starAst.isGreedy) createGreedy(starAst.body) else createNonGreedy(starAst.body),
      )
      return create(plusRuleName)
    }

    @VisibleForTesting
    fun getStarIfIsKleeneStarRule(ruleName: RuleNameHandle): PersesStarAst? {
      val ruleDef = grammar.getRuleDefinition(ruleName) ?: return null
      val body = ruleDef.body
      return if (body is PersesStarAst) {
        body
      } else {
        null
      }
    }

    companion object {
      @JvmStatic
      @VisibleForTesting
      fun reverseMatch(
        sequence: PersesSequenceAst,
        startIndex: Int,
        toMatchList: ImmutableList<AbstractPersesRuleElement>,
      ): Boolean {
        val length = toMatchList.size
        return match(sequence, startIndex - length + 1, toMatchList)
      }

      @JvmStatic
      @VisibleForTesting
      fun match(
        sequence: PersesSequenceAst,
        startIndex: Int,
        toMatchList: ImmutableList<AbstractPersesRuleElement>,
      ): Boolean {
        if (startIndex < 0 || startIndex >= sequence.childCount) {
          return false
        }
        var i = 0
        val size = toMatchList.size
        while (i < size) {
          val toMatch = toMatchList[i]
          val indexInSeq = startIndex + i
          if (indexInSeq >= sequence.childCount) {
            return false
          }
          if (!toMatch.isEquivalent(sequence.getChild(indexInSeq))) {
            return false
          }
          ++i
        }
        return true
      }
    }
  }
}
