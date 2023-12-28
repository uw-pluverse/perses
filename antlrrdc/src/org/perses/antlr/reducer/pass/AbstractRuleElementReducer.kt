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

import com.google.common.flogger.FluentLogger
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.PersesGrammar
import org.perses.antlr.ast.RuleNameRegistry
import org.perses.antlr.pnf.MutableGrammar
import org.perses.antlr.reducer.io.GrammarReductionIOManager
import org.perses.reduction.ListenableReductionState
import org.perses.reduction.TestScriptExecutorService
import org.perses.util.ktInfo

abstract class AbstractRuleElementReducer(
  ioManager: GrammarReductionIOManager,
  testScriptExecutorService: TestScriptExecutorService,
) : AbstractAntlrReducer(
  ioManager,
  testScriptExecutorService,
) {

  final override fun reduce(state: ListenableReductionState<PersesGrammar>) {
    val program = state.bestEntity

    val mutableGrammar = MutableGrammar.createParserRulesFrom(program)
    val sortedRuleNames = mutableGrammar
      .ruleNameSequence().sorted().toList()

    for (ruleName in sortedRuleNames) {
      logger.ktInfo { "${javaClass.simpleName}: processing rule $ruleName" }
      val old2NewRules = LinkedHashMap<AbstractPersesRuleElement, AbstractPersesRuleElement>()
      for (origDef in mutableGrammar.getAltBlock(ruleName)) {
        var newDef = reduceRuleDef(
          origDef,
          program,
          mutableGrammar,
          ruleName,
        )
        old2NewRules[origDef] = newDef
      }
      check(old2NewRules.size == mutableGrammar.getAltBlock(ruleName).size())
      check(old2NewRules.isNotEmpty())
      // To make sure the order of alternatives is preserved.
      mutableGrammar.removeRule(ruleName)
      for ((_, value) in old2NewRules.entries) {
        check(mutableGrammar.getAltBlock(ruleName).addIfNotEquivalent(value))
      }
      state.updateBestProgram(
        program.copyWithNewParserRuleDefs(mutableGrammar.toParserRuleAstList()),
      )
    }
  }

  abstract fun reduceRuleDef(
    origDef: AbstractPersesRuleElement,
    immutableRuleDefs: PersesGrammar,
    mutableGrammar: MutableGrammar,
    ruleName: RuleNameRegistry.RuleNameHandle,
  ): AbstractPersesRuleElement

  protected fun testNewDef(
    immutableRuleDefMap: PersesGrammar,
    mutableGrammar: MutableGrammar,
    ruleName: RuleNameRegistry.RuleNameHandle,
    oldDef: AbstractPersesRuleElement,
    newDef: AbstractPersesRuleElement,
  ): Boolean {
    val copyGrammar = mutableGrammar.duplicateByReplacing(
      ruleName,
      oldDef,
      newDef,
    )
    val newPersesGrammar = immutableRuleDefMap
      .copyWithNewParserRuleDefs(copyGrammar.toParserRuleAstList())
    return testProgram(newPersesGrammar)
  }

  companion object {
    val logger = FluentLogger.forEnclosingClass()
  }
}
