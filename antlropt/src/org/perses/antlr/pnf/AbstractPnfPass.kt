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

import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.PersesRuleReferenceAst
import org.perses.antlr.ast.PersesSequenceAst
import org.perses.antlr.ast.RuleNameRegistry.RuleNameHandle
import org.perses.antlr.pnf.AstUtil.replaceGapInSequence
import org.perses.util.Interval

abstract class AbstractPnfPass {

  abstract fun processGrammar(
    grammar: GrammarPair,
  ): GrammarPair

  companion object {
    @JvmStatic
    protected fun getSortedRuleNames(map: MutableGrammar): List<RuleNameHandle> {
      return map.ruleNameSequence().sorted().toList()
    }

    @JvmStatic
    protected fun replaceGapWithRuleReference(
      seq: PersesSequenceAst,
      gap: Interval,
      gapReplacement: RuleNameHandle,
    ): AbstractPersesRuleElement {
      val ruleRefAst = PersesRuleReferenceAst.create(gapReplacement)
      return replaceGapInSequence(seq, gap, ruleRefAst)
    }

    @JvmStatic
    protected fun countRulesThatCallsRuleOfName(
      grammar: MutableGrammar,
      ruleName: RuleNameHandle,
    ): Int {
      val counter = RuleRefCounterAstVisitor(ruleName)
      grammar.alternativeSequence().forEach {
        counter.preorder(it)
      }
      return counter.count
    }
  }
}
