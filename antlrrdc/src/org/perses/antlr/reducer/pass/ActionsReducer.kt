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
import org.perses.antlr.ast.PersesActionAst
import org.perses.antlr.ast.PersesGrammar
import org.perses.antlr.ast.PersesSequenceAst
import org.perses.antlr.ast.RuleNameRegistry.RuleNameHandle
import org.perses.antlr.pnf.MutableGrammar
import org.perses.antlr.reducer.io.GrammarReductionIOManager
import org.perses.reduction.TestScriptExecutorService
import org.perses.util.ktInfo

class ActionsReducer(
  ioManager: GrammarReductionIOManager,
  testScriptExecutorService: TestScriptExecutorService,
) : AbstractRuleElementReducer(
  ioManager,
  testScriptExecutorService,
) {

  override fun reduceRuleDef(
    origDef: AbstractPersesRuleElement,
    immutableRuleDefs: PersesGrammar,
    mutableGrammar: MutableGrammar,
    ruleName: RuleNameHandle,
  ): AbstractPersesRuleElement {
    var newDef = origDef
    val actionNodes = ActionNodeCollector.collectActionNodes(origDef)
    for (action in actionNodes) {
      check(newDef is PersesSequenceAst) { newDef.sourceCode }
      val defCandidate = removeAction(newDef, action)
      if (!testNewDef(immutableRuleDefs, mutableGrammar, ruleName, origDef, defCandidate)) {
        continue
      }
      logger.ktInfo { "Delete one action node." }
      newDef = defCandidate
    }
    return newDef
  }

  private fun removeAction(
    def: AbstractPersesRuleElement,
    action: PersesActionAst,
  ): AbstractPersesRuleElement {
    val editor = ActionRemover(action)
    return editor.bottomUpApply(def)!!
  }

  class ActionRemover(val action: PersesActionAst) :
    AbstractAstEditor() {

    override fun visit(
      ast: PersesActionAst,
      newChildren: ImmutableList<AbstractPersesRuleElement>,
    ): AbstractPersesRuleElement? {
      if (action === ast) {
        return null
      }
      return super.visit(ast, newChildren)
    }
  }

  companion object {
    val logger = FluentLogger.forEnclosingClass()
  }
}
