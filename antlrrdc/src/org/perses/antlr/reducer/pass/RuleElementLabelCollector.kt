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
import org.perses.antlr.ast.PersesRuleElementLabel

class RuleElementLabelCollector private constructor() :
  DefaultAstVisitor() {

  private val labels = ArrayList<PersesRuleElementLabel>()

  override fun visit(ast: PersesRuleElementLabel) {
    labels.add(ast)
  }

  companion object {
    fun collectLabels(ast: AbstractPersesRuleElement): ArrayList<PersesRuleElementLabel> {
      return RuleElementLabelCollector().apply { preorder(ast) }.labels
    }
  }
}
