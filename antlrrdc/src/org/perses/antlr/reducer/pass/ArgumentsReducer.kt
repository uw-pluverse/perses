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
import org.perses.antlr.ast.AbstractAstEditor
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.PersesGrammar
import org.perses.antlr.ast.PersesParserRuleAst
import org.perses.antlr.ast.PersesParserRuleAst.ParserRuleAttributes
import org.perses.antlr.ast.PersesRuleReferenceAst
import org.perses.antlr.ast.RuleNameRegistry
import org.perses.antlr.reducer.io.GrammarReductionIOManager
import org.perses.reduction.TestScriptExecutorService

class ArgumentsReducer(
  ioManager: GrammarReductionIOManager,
  testScriptExecutorService: TestScriptExecutorService,
) : AbstractParserRuleAttributeReducer(
  ioManager,
  testScriptExecutorService,
) {

  override fun hasAttribute(attributes: ParserRuleAttributes): Boolean {
    return attributes.hasArguments()
  }

  override fun removeAttribute(attributes: ParserRuleAttributes): ParserRuleAttributes {
    return attributes.copyWithArguments(null)
  }

  override fun createNewGrammarWithNewDef(
    bestProgram: PersesGrammar,
    newDef: PersesParserRuleAst,
  ): PersesGrammar {
    // TODO: there is much room for optimization
    val tempGrammar = bestProgram.copyWithNewRuleDef(newDef)
    val editor = RuleRefArgumentsRemover(newDef.ruleNameHandle)
    return editor.bottomUpApply(tempGrammar)
  }

  class RuleRefArgumentsRemover(val ruleName: RuleNameRegistry.RuleNameHandle) :
    AbstractAstEditor() {

    override fun visit(
      ast: PersesRuleReferenceAst,
      newChildren: ImmutableList<AbstractPersesRuleElement>,
    ): AbstractPersesRuleElement {
      require(newChildren.isEmpty())
      return if (ast.ruleNameHandle == ruleName) {
        PersesRuleReferenceAst.create(ruleName)
      } else {
        ast.createWithNewChildren(newChildren)
      }
    }
  }
}
