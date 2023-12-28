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
import org.perses.antlr.RuleType
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.AstTag
import org.perses.antlr.ast.PersesRuleReferenceAst

class OutlineAltBlockPass : AbstractPnfPass() {

  override fun processGrammar(
    grammar: GrammarPair,
  ): GrammarPair {
    val parserGrammar = grammar.parserGrammar ?: return grammar
    val mutable = MutableGrammar.createParserRulesFrom(parserGrammar)
    mutable.nonEmptyAltBlockSequence()
      .toList()
      .forEach { (name, altBlock) ->
        altBlock.forEach { ruleElement ->
          if (ruleElement.tag == AstTag.SEQUENCE) {
            val newChildren = ImmutableList.builder<AbstractPersesRuleElement>()
            var childrenChanged = false
            ruleElement.foreachChildRuleElement {
              if (it.tag == AstTag.ALTERNATIVE_BLOCK) {
                val ruleName = name.createAuxiliaryRuleName(RuleType.ALT_BLOCKS)
                it.foreachChildRuleElement { alt ->
                  mutable.getAltBlock(ruleName).addIfNotEquivalent(alt)
                }
                newChildren.add(PersesRuleReferenceAst.create(ruleName))
                childrenChanged = true
              } else {
                newChildren.add(it)
              }
            }
            if (childrenChanged) {
              altBlock.replace(ruleElement, ruleElement.createWithNewChildren(newChildren.build()))
            }
          }
        }
      }
    return grammar.withNewParserGrammar(
      parserGrammar.copyWithNewParserRuleDefs(mutable.toParserRuleAstList()),
    )
  }
}
