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

import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.DefaultAstVisitor
import org.perses.antlr.ast.PersesActionAst
import org.perses.antlr.ast.PersesGrammar

class ActionNodeCollector private constructor() :
  DefaultAstVisitor() {

  private val actions = ArrayList<PersesActionAst>()

  override fun visit(ast: PersesActionAst) {
    actions.add(ast)
  }

  companion object {

    fun collectActionNodes(grammar: PersesGrammar): ArrayList<PersesActionAst> {
      val visitor = ActionNodeCollector()
      visitor.preorderGrammar(grammar)
      return visitor.actions
    }

    fun collectActionNodes(ast: AbstractPersesRuleElement): ArrayList<PersesActionAst> {
      return ActionNodeCollector().apply { preorder(ast) }.actions
    }
  }
}
