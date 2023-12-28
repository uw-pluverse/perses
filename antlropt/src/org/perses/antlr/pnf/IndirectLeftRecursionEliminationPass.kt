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

class IndirectLeftRecursionEliminationPass : AbstractIndirectRecursionEliminationPass() {

  override fun createRuleTransitionGraph(grammar: PersesGrammar): RuleTransitionGraph {
    return RuleTransitionGraph.createForLeftmostTransition(grammar)
  }

  @VisibleForTesting
  public override fun getRuleRefToInline(
    def: AbstractPersesRuleElement,
  ): RuleNameHandle? {
    require(def.tag !== AstTag.ALTERNATIVE_BLOCK)
    return getFirstOrLastRuleRef(def, seekingFirst = true)
  }

  override fun inlineRuleRefIntoSequence(
    originalSequence: PersesSequenceAst,
    toInline: AbstractPersesRuleElement,
    newSeqBuilder: ImmutableList.Builder<AbstractPersesRuleElement>,
  ) {
    check(originalSequence.firstChild.tag === AstTag.RULE_REF)
    when {
      toInline.tag === AstTag.SEQUENCE -> {
        toInline.foreachChildRuleElement { newSeqBuilder.add(it) }
      }
      toInline.tag === AstTag.EPSILON -> {
        // Do not inline epsilon, as it is empty.
      }
      else -> {
        newSeqBuilder.add(toInline)
      }
    }
    var i = 1
    val size = originalSequence.childCount
    while (i < size) {
      newSeqBuilder.add(originalSequence.getChild(i))
      ++i
    }
  }
}
