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

import org.perses.antlr.GrammarTestingUtility.createPersesGrammarFromString
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.PersesGrammar
import org.perses.antlr.ast.RuleNameRegistry
import org.perses.util.toImmutableMap

open class PnfRightTestGrammar protected constructor() {
  protected val grammar: PersesGrammar
  protected val a: RuleNameRegistry.RuleNameHandle
  protected val b: RuleNameRegistry.RuleNameHandle
  protected val c: RuleNameRegistry.RuleNameHandle
  protected val d: RuleNameRegistry.RuleNameHandle
  protected val def_a_cb: AbstractPersesRuleElement
  protected val def_a_d: AbstractPersesRuleElement
  protected val def_b_da: AbstractPersesRuleElement
  protected val def_b_cd: AbstractPersesRuleElement
  protected val def_c_c: AbstractPersesRuleElement
  protected val def_d_d: AbstractPersesRuleElement

  init {
    grammar = createPersesGrammarFromString(
      "a : c b | d;",
      "b : d a | c d;",
      "c : 'c';",
      "d : 'd';",
    )
    val ruleNameRegistry = grammar.symbolTable.ruleNameRegistry
    a = ruleNameRegistry.getOrThrow("a")
    b = ruleNameRegistry.getOrThrow("b")
    c = ruleNameRegistry.getOrThrow("c")
    d = ruleNameRegistry.getOrThrow("d")
    val codeToDef = grammar.flattenedParserRulesSequence()
      .map {
        it.second.sourceCode to it.second
      }.toImmutableMap()
    def_a_cb = codeToDef["c b"]!!
    def_a_d = codeToDef["d"]!!
    def_b_da = codeToDef["d a"]!!
    def_b_cd = codeToDef["c d"]!!
    def_c_c = codeToDef["'c'"]!!
    def_d_d = codeToDef["'d'"]!!
  }
}
