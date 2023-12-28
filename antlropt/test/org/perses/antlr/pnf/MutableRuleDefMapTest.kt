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

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.antlr.ast.PersesAstBuilder
import org.perses.antlr.ast.PersesRuleReferenceAst

@RunWith(JUnit4::class)
class MutableRuleDefMapTest {

  @Test
  fun test() {
    val grammar = PersesAstBuilder.loadGrammarFromString(
      """
      grammar Test;
      start : s1;
      s1: s2;
      s2: 'a';
      """.trimIndent(),
    )
    val mutable = MutableGrammar.createParserRulesFrom(grammar)
    val startRuleName = grammar.getRuleNameHandleOrThrow("start")
    val s2RuleName = grammar.getRuleNameHandleOrThrow("s2")
    val oldStartDef = grammar.getRuleDefinition(startRuleName)!!
    val newStartDef = PersesRuleReferenceAst.create(s2RuleName)
    val newMutable = mutable.duplicateByReplacing(startRuleName, oldStartDef.body, newStartDef)
    val newGrammar = grammar.copyWithNewParserRuleDefs(newMutable.toParserRuleAstList())

    assertThat(newGrammar.getRuleDefinition("start")!!.body.sourceCode)
      .isEqualTo("s2")
    assertThat(newGrammar.getRuleDefinition("s1")!!.body.sourceCode)
      .isEqualTo("s2")
    assertThat(newGrammar.getRuleDefinition("s2")!!.body.sourceCode)
      .isEqualTo("'a'")
  }
}
