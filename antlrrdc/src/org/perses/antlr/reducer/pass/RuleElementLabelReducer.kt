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
package org.perses.antlr.reducer.pass

import com.google.common.collect.ImmutableList
import com.google.common.flogger.FluentLogger
import org.perses.antlr.ast.AbstractAstEditor
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.PersesGrammar
import org.perses.antlr.ast.PersesRuleElementLabel
import org.perses.antlr.ast.RuleNameRegistry
import org.perses.antlr.pnf.MutableGrammar
import org.perses.antlr.reducer.io.GrammarReductionIOManager
import org.perses.reduction.TestScriptExecutorService
import org.perses.util.ktInfo

class RuleElementLabelReducer(
  ioManager: GrammarReductionIOManager,
  testScriptExecutorService: TestScriptExecutorService,
) : AbstractRuleElementReducer(
  ioManager,
  testScriptExecutorService,
) {

  // TODO: this can be merged with ActionReducer.
  override fun reduceRuleDef(
    origDef: AbstractPersesRuleElement,
    immutableRuleDefs: PersesGrammar,
    mutableGrammar: MutableGrammar,
    ruleName: RuleNameRegistry.RuleNameHandle,
  ): AbstractPersesRuleElement {
    var newDef = origDef
    val labels = RuleElementLabelCollector.collectLabels(newDef)
    for (label in labels) {
      val defCandidate = removeLabel(newDef, label)
      if (!testNewDef(immutableRuleDefs, mutableGrammar, ruleName, origDef, defCandidate)) {
        continue
      }
      logger.ktInfo { "Delete one label" }
      newDef = defCandidate
    }
    return newDef
  }

  private fun removeLabel(
    def: AbstractPersesRuleElement,
    label: PersesRuleElementLabel,
  ): AbstractPersesRuleElement {
    val editor = LabelRemover(label)
    return editor.bottomUpApply(def)!!
  }

  class LabelRemover(val label: PersesRuleElementLabel) :
    AbstractAstEditor() {

    override fun visit(
      ast: PersesRuleElementLabel,
      newChildren: ImmutableList<AbstractPersesRuleElement>,
    ): AbstractPersesRuleElement {
      if (ast === label) {
        check(newChildren.size == 1)
        return newChildren.single()
      }
      return super.visit(ast, newChildren)!!
    }
  }

  companion object {
    private val logger = FluentLogger.forEnclosingClass()
  }
}
