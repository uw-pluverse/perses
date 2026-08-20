/*
 * Copyright (C) 2018-2026 University of Waterloo.
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

import org.perses.antlr.ast.PersesGrammar
import org.perses.antlr.ast.PersesParserRuleAst
import org.perses.antlr.ast.PersesParserRuleAst.ParserRuleAttributes
import org.perses.antlr.reducer.io.GrammarReductionIOManager
import org.perses.reduction.AbstractReducerNameAndDesc
import org.perses.reduction.ListenableReductionState
import org.perses.reduction.TestScriptExecutorService
import org.perses.reduction.io.AbstractOutputManagerFactory

abstract class AbstractParserRuleAttributeReducer(
  nameAndDesc: AbstractReducerNameAndDesc,
  ioManager: GrammarReductionIOManager,
  testScriptExecutorService: TestScriptExecutorService,
  outputManagerFactory: AbstractOutputManagerFactory<PersesGrammar>,
) : AbstractAntlrReducer(
    nameAndDesc,
    ioManager,
    testScriptExecutorService,
    outputManagerFactory,
  ) {
  final override fun reduce(state: ListenableReductionState<PersesGrammar>) {
    val rules = state.bestEntity.parserRules
    for (origRule in rules) {
      val attributes = origRule.attributes
      if (!hasAttribute(attributes)) {
        continue
      }
      val newAttributes = removeAttribute(attributes)
      val newDef = origRule.copyWithNewAttributes(newAttributes)
      val bestProgram = state.bestEntity
      val newProgram = createNewGrammarWithNewDef(bestProgram, newDef)
      if (testProgram(newProgram)) {
        state.updateBestProgram(newProgram)
      }
    }
  }

  abstract fun hasAttribute(attributes: ParserRuleAttributes): Boolean

  abstract fun removeAttribute(attributes: ParserRuleAttributes): ParserRuleAttributes

  open fun createNewGrammarWithNewDef(
    bestProgram: PersesGrammar,
    newDef: PersesParserRuleAst,
  ): PersesGrammar = bestProgram.copyWithNewRuleDef(newDef)
}
