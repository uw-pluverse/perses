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
import org.perses.antlr.RuleType
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.AstTag
import org.perses.antlr.ast.PersesAlternativeBlockAst
import org.perses.antlr.ast.PersesAstBuilder.Companion.combineIntoSequence
import org.perses.antlr.ast.PersesRuleReferenceAst
import org.perses.antlr.ast.PersesRuleReferenceAst.Companion.create
import org.perses.antlr.ast.PersesSequenceAst
import org.perses.antlr.ast.PersesStarAst.Companion.createGreedy
import org.perses.antlr.ast.RuleNameRegistry.RuleNameHandle

abstract class AbstractStarIntroducerPass : AbstractPnfPass() {

  @VisibleForTesting
  fun introduceStars(rules: MutableGrammar, ruleName: RuleNameHandle) {
    val nonRecursivePartsInRecursiveDef = ArrayList<AbstractPersesRuleElement>()
    val nonRecursiveDefs = LinkedHashSet<AbstractPersesRuleElement>()
    val ruleDef = rules.getAltBlock(ruleName)
    classifyDefsAndExtractNonrecursiveParts(
      ruleName,
      ruleDef,
      nonRecursivePartsInRecursiveDef,
      nonRecursiveDefs,
    )
    AstUtil.inPlaceFlattenAltBlocks(nonRecursivePartsInRecursiveDef)
    for (nonRecursivePart in nonRecursivePartsInRecursiveDef) {
      check(nonRecursivePart !is PersesAlternativeBlockAst) {
        nonRecursivePart.sourceCode
      }
    }
    if (nonRecursivePartsInRecursiveDef.isEmpty()) {
      return
    }
    check(nonRecursiveDefs.size > 0)
    rules.removeRule(ruleName)
    val starRuleName = ruleName.createAuxiliaryRuleName(RuleType.KLEENE_STAR)
    val quantifiedRuleName = ruleName.createAuxiliaryRuleName(RuleType.OTHER_RULE)
    val quantifiedBodyRule = AstUtil.flattenAndDeduplicateAlternatives(
      nonRecursivePartsInRecursiveDef,
    )
    rules.getAltBlock(quantifiedRuleName).addAllIfInequivalent(quantifiedBodyRule)
    val starRule = createGreedy(create(quantifiedRuleName))
    rules.getAltBlock(starRuleName).addIfNotEquivalent(starRule)
    val starRuleRef = create(starRuleName)
    if (nonRecursiveDefs.size == 1) {
      val nonRecursiveDef = nonRecursiveDefs.single()
      rules.getAltBlock(ruleName).addIfNotEquivalent(
        combineIntoSequence(constructNewSequenceDef(nonRecursiveDef, starRuleRef)),
      )
    } else {
      val altBlock = AstUtil.flattenAndDeduplicateAlternatives(nonRecursiveDefs)
      assert(altBlock.size > 1)
      val altBlockRuleName = ruleName.createAuxiliaryRuleName(RuleType.OTHER_RULE)
      rules.getAltBlock(altBlockRuleName).addAllIfInequivalent(altBlock)
      rules.getAltBlock(ruleName).addIfNotEquivalent(
        combineIntoSequence(constructNewSequenceDef(create(altBlockRuleName), starRuleRef)),
      )
    }
  }

  private fun classifyDefsAndExtractNonrecursiveParts(
    ruleName: RuleNameHandle,
    definitions: Iterable<AbstractPersesRuleElement>,
    nonRecursivePartsInRecursiveDef: ArrayList<AbstractPersesRuleElement>,
    nonRecursiveDefs: LinkedHashSet<AbstractPersesRuleElement>,
  ) {
    for (def in definitions) {
      val tag = def.tag
      check(tag !== AstTag.ALTERNATIVE_BLOCK) {
        tag ?: "null"
      }
      check(
        tag !== AstTag.RULE_REF ||
          ruleName
            .ruleName != (def as PersesRuleReferenceAst).ruleNameHandle.ruleName,
      )
      if (tag === AstTag.SEQUENCE) {
        val seq = def as PersesSequenceAst
        classifyAndExtractPartsFromSequenceDef(
          ruleName,
          seq,
          nonRecursivePartsInRecursiveDef,
          nonRecursiveDefs,
        )
      } else {
        nonRecursiveDefs.add(def)
      }
    }
  }

  protected abstract fun constructNewSequenceDef(
    nonRecursiveDef: AbstractPersesRuleElement,
    starRuleRef: PersesRuleReferenceAst,
  ): ImmutableList<AbstractPersesRuleElement>

  protected abstract fun classifyAndExtractPartsFromSequenceDef(
    ruleName: RuleNameHandle,
    sequenceDef: PersesSequenceAst,
    nonRecursivePartsInRecursiveDef: ArrayList<AbstractPersesRuleElement>,
    nonRecursiveDefs: LinkedHashSet<AbstractPersesRuleElement>,
  )

  override fun processGrammar(
    grammar: GrammarPair,
  ): GrammarPair {
    val parserGrammar = grammar.parserGrammar ?: return grammar
    val mutable = MutableGrammar.createParserRulesFrom(parserGrammar)
    mutable.ruleNameSequence()
      .sorted()
      .toList() // Materialize the elements to avoid concurrent modification to mutable.
      .forEach { ruleName ->
        introduceStars(mutable, ruleName)
      }
    return grammar.withNewParserGrammar(
      parserGrammar.copyWithNewParserRuleDefs(mutable.toParserRuleAstList()),
    )
  }
}
