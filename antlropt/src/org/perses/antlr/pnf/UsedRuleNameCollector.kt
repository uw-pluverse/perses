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

import org.perses.antlr.ast.DefaultAstVisitor
import org.perses.antlr.ast.PersesRuleReferenceAst
import org.perses.antlr.ast.PersesTerminalAst
import org.perses.antlr.ast.RuleNameRegistry.RuleNameHandle

class UsedRuleNameCollector : DefaultAstVisitor() {
  private val _usedRules = LinkedHashSet<RuleNameHandle>()
  private val _tokenReferences = LinkedHashSet<String>()

  val ruleReferences: Set<RuleNameHandle>
    get() = _usedRules

  val tokenReferences: Set<String>
    get() = _tokenReferences

  override fun visit(ast: PersesRuleReferenceAst) {
    _usedRules.add(ast.ruleNameHandle)
  }

  override fun visit(ast: PersesTerminalAst) {
    if (ast.isTokenRef) {
      _tokenReferences.add(ast.text)
    }
  }
}
