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

import org.perses.antlr.ast.AstTag
import org.perses.antlr.ast.DefaultAstVisitor
import org.perses.antlr.ast.PersesActionAst
import org.perses.antlr.ast.PersesParserRuleAst
import org.perses.antlr.ast.PersesRuleElementLabel
import org.perses.antlr.ast.TransformDecision

class RemoveUnusedLabelPass : AbstractPnfPass() {

  override fun processGrammar(grammar: GrammarPair): GrammarPair {
    val parserGrammar = grammar.parserGrammar ?: return grammar
    val ruleNamesWithActions = parserGrammar.parserRules.filter(
      this::hasCode,
    ).map { it.ruleNameHandle }
    if (ruleNamesWithActions.isNotEmpty()) {
      return grammar
    }
    val mutableGrammar = MutableGrammar.createParserRulesFrom(parserGrammar)
    mutableGrammar.nonEmptyAltBlockSequence().forEach { (_, altBlock) ->
      val newValues = altBlock.asSequence().map { alternative ->
        when (val decision = RemoveRuleElementLabelEdit().apply(alternative)) {
          is TransformDecision.Keep -> alternative // Do nothing
          is TransformDecision.Replace -> {
            decision.newValue
          }
          else -> error(decision)
        }
      }.toList()
      altBlock.clear()
      newValues.forEach {
        altBlock.addIfNotEquivalent(it)
      }
    }
    return grammar.withNewParserGrammar(
      parserGrammar.copyWithNewParserRuleDefs(mutableGrammar.toParserRuleAstList()),
    )
  }

  internal fun hasCode(ast: PersesParserRuleAst): Boolean {
    val attributes = ast.attributes
    if (attributes.isNotEmpty()) {
      return true
    }
    var hasCode = false
    val visitor = object : DefaultAstVisitor() {
      override fun visit(ast: PersesActionAst) {
        super.visit(ast)
        hasCode = true
      }
    }
    visitor.preorder(ast.body)
    return hasCode
  }

  internal class RemoveRuleElementLabelEdit : ReplaceEdit(
    oldPredicate = {
      it.tag == AstTag.RULE_ELEMENT_LABEL
    },
    newValueComputer = { oldValue ->
      (oldValue as PersesRuleElementLabel).child
    },
  )
}
