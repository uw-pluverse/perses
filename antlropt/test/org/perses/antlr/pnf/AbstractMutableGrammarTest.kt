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

import org.perses.antlr.ast.PersesRuleReferenceAst
import org.perses.antlr.ast.SymbolTable

open class AbstractMutableGrammarTest {
  val symbolTable = SymbolTable()
  val nameA = createName("a")
  val refA = PersesRuleReferenceAst.create(nameA)
  val nameB = createName("b")
  val refB = PersesRuleReferenceAst.create(nameB)
  val nameC = createName("c")
  val refC = PersesRuleReferenceAst.create(nameC)
  val nameD = createName("d")
  val refD = PersesRuleReferenceAst.create(nameD)
  fun createName(name: String) =
    symbolTable.ruleNameRegistry.createOrThrow(name)
}
