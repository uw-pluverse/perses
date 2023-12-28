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
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.AstTag
import org.perses.antlr.ast.PersesGrammar
import org.perses.antlr.ast.PersesSequenceAst
import org.perses.antlr.ast.RuleNameRegistry.RuleNameHandle

class IndirectRightRecursionEliminationPass : AbstractIndirectRecursionEliminationPass() {

  override fun createRuleTransitionGraph(grammar: PersesGrammar): RuleTransitionGraph {
    return RuleTransitionGraph.createForRightmostTransition(grammar)
  }

  @VisibleForTesting
  public override fun getRuleRefToInline(
    def: AbstractPersesRuleElement,
  ): RuleNameHandle? {
    return getFirstOrLastRuleRef(def, seekingFirst = false)
  }

  override fun inlineRuleRefIntoSequence(
    originalSequence: PersesSequenceAst,
    toInline: AbstractPersesRuleElement,
    newSeqBuilder: ImmutableList.Builder<AbstractPersesRuleElement>,
  ) {
    check(originalSequence.lastChild.tag === AstTag.RULE_REF)
    val size = originalSequence.childCount
    for (i in 0 until size - 1) {
      newSeqBuilder.add(originalSequence.getChild(i))
    }
    if (toInline.tag === AstTag.SEQUENCE) {
      toInline.foreachChildRuleElement { e: AbstractPersesRuleElement -> newSeqBuilder.add(e) }
    } else if (toInline.tag === AstTag.EPSILON) {
      // Do not inline epsilon, as it is empty.
    } else {
      newSeqBuilder.add(toInline)
    }
  }
}
