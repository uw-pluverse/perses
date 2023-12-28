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
package org.perses.antlr.ast

import org.perses.antlr.RuleType
import org.perses.antlr.ast.RuleNameRegistry.RuleNameHandle

abstract class AbstractPersesLexerRuleAst protected constructor(
  ruleNameHandle: RuleNameHandle,
  body: AbstractPersesRuleElement,
) : AbstractPersesRuleDefAst(ruleNameHandle, body) {

  init {
    require(RuleType.isLexerRule(ruleNameHandle.ruleName))
  }

  abstract override fun copyWithNewBody(
    newBody: AbstractPersesRuleElement,
  ): AbstractPersesLexerRuleAst

  override val isLexerRule: Boolean
    get() = true
}
