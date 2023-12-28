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

import org.perses.antlr.RuleType
import org.perses.antlr.ast.AstTag
import org.perses.antlr.ast.PersesAlternativeBlockAst
import org.perses.antlr.ast.PersesOptionalAst
import org.perses.antlr.ast.PersesPlusAst
import org.perses.antlr.ast.PersesRuleReferenceAst
import org.perses.antlr.ast.PersesStarAst
import org.perses.antlr.ast.RuleNameRegistry.RuleNameHandle
import org.perses.antlr.pnf.OptionalExtractionUtil.searchForCandidate

class OptionalIntroducerPass : AbstractPnfPass() {
  override fun processGrammar(
    grammar: GrammarPair,
  ): GrammarPair {
    val parserGrammar = grammar.parserGrammar ?: return grammar
    val mutable = MutableGrammar.createParserRulesFrom(parserGrammar)
    // To make the process deterministic.
    val ruleNameList = getSortedRuleNames(mutable)
    for (ruleName in ruleNameList) {
      while (true) {
        val candidate = searchForCandidate(mutable.getAltBlock(ruleName).asIterable()) ?: break
        mergeTwoSeqs(ruleName, mutable, candidate)
      }
    }
    return grammar.withNewParserGrammar(
      parserGrammar.copyWithNewParserRuleDefs(mutable.toParserRuleAstList()),
    )
  }

  private fun mergeTwoSeqs(
    ruleName: RuleNameHandle,
    mutable: MutableGrammar,
    candidate: OptionalExtractionUtil.Candidate,
  ) {
    val originalGapAst = candidate.getGapAst()
    mutable.getAltBlock(ruleName).removeAlt(candidate.shortSeq.ast)
    val processedGapAst = if (originalGapAst is PersesAlternativeBlockAst) {
      // If this is an alt-block, then decompose it and replace it with a rule reference.
      val wrapperRuleName = ruleName.createAuxiliaryRuleName(RuleType.ALT_BLOCKS)
      mutable.getAltBlock(wrapperRuleName)
        .decomposeAltBlockAndAddIfInequivalent(originalGapAst)
      PersesRuleReferenceAst.create(wrapperRuleName)
    } else {
      originalGapAst
    }
    val gapAstReplacement = when (processedGapAst.tag) {
      AstTag.STAR, AstTag.OPTIONAL -> return // Do nothing, to let other passes take care of this.
      AstTag.PLUS -> {
        val starRuleName = ruleName.createAuxiliaryRuleName(RuleType.KLEENE_STAR)
        mutable.getAltBlock(starRuleName).addIfNotEquivalent(
          (processedGapAst as PersesPlusAst).let { PersesStarAst(it.body, it.isGreedy) },
        )
        starRuleName
      }
      AstTag.TERMINAL, AstTag.RULE_REF -> {
        val optionalRuleName = ruleName
          .createAuxiliaryRuleName(RuleType.OPTIONAL)
        mutable.getAltBlock(optionalRuleName).addIfNotEquivalent(
          PersesOptionalAst.createGreedy(processedGapAst),
        )
        optionalRuleName
      }
      else -> {
        val wrapperRuleName = ruleName.createAuxiliaryRuleName(RuleType.OTHER_RULE)
        mutable.getAltBlock(wrapperRuleName).addIfNotEquivalent(processedGapAst)
        val optionalRuleName = ruleName.createAuxiliaryRuleName(RuleType.OPTIONAL)
        mutable.getAltBlock(optionalRuleName).addIfNotEquivalent(
          PersesOptionalAst.createGreedy(PersesRuleReferenceAst.create(wrapperRuleName)),
        )
        optionalRuleName
      }
    }
    mutable.getAltBlock(ruleName).replace(
      candidate.longSeq.ast,
      replaceGapWithRuleReference(
        candidate.longSeq.ast,
        candidate.gapInLongSequence,
        gapAstReplacement,
      ),
    )
  }
}
