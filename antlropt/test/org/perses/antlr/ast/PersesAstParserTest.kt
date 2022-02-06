/*
 * Copyright (C) 2018-2022 University of Waterloo.
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

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4

@RunWith(JUnit4::class)
class PersesAstParserTest {

  @Test
  fun test_multipleLexerActions() {
    val grammar = PersesAstBuilder.loadGrammarFromString(
      """
      lexer gramar Test;
      ID: 'i' -> popMode, skip, more, pushMode(TT), more, popMode, pushMode(TT);
      """.trimIndent()
    )
    assertThat(grammar.flattenedAllRules).hasSize(1)
    assertThat(grammar.flattenedAllRules.first().body.sourceCode)
      .contains("popMode, skip, more, pushMode(TT), more, popMode, pushMode(TT)")
  }

  @Test
  fun test_popMode() {
    val grammar = PersesAstBuilder.loadGrammarFromString(
      """
      lexer grammar Test;
      OPEN: '[' -> popMode;
      """.trimIndent()
    )
    assertThat(grammar.sourceCode).contains("'[' -> popMode")
  }

  @Test
  fun test_skip() {
    val grammar = PersesAstBuilder.loadGrammarFromString(
      """
      lexer grammar Test;
      OPEN: '[' -> skip;
      """.trimIndent()
    )
    assertThat(grammar.sourceCode).contains("'[' -> skip")
  }

  @Test
  fun test_pushMode() {
    val grammar = PersesAstBuilder.loadGrammarFromString(
      """
      lexer grammar Test;
      OPEN: '[' -> pushMode(CODE_MODE);
      """.trimIndent()
    )
    assertThat(grammar.sourceCode).contains("'[' -> pushMode(CODE_MODE)")
  }

  @Test
  fun test_channel() {
    val grammar = PersesAstBuilder.loadGrammarFromString(
      """
      lexer grammar Test;
      OPEN: '[' -> channel(SKIP);
      """.trimIndent()
    )
    assertThat(grammar.sourceCode).contains("'[' -> channel(SKIP)")
  }

  @Test
  fun test_lexer_modes() {
    val grammar = PersesAstBuilder.loadGrammarFromString(
      """
      lexer grammar Test;
      // A lexer grammar has to have lexer rules in the default mode.
      ID: 'id';
      
      mode M1;
      A_m1: 'a_m1';
      B_m1: 'b_m1';
      
      mode M2;
      A_m2: 'a_m2';
      B_m2: 'b_m2';
      
      mode M3;
      A_m3: 'a_m3';
      B_m3: 'b_m3';
      
      mode M4;
      A_m4: 'a_m4';
      B_m4: 'b_m4';
      """.trimIndent()
    )
    val lexerRules = grammar.lexerRules
    val defaultModeLexerRules = lexerRules.defaultModeLexerRules
    assertThat(defaultModeLexerRules).hasSize(1)
    assertThat(defaultModeLexerRules.get(0).ruleNameHandle.ruleName).isEqualTo("ID")
    assertThat(defaultModeLexerRules.get(0).body.sourceCode).isEqualTo("'id'")

    val nonDefaultModes = lexerRules.nonDefaultModes
    assertThat(nonDefaultModes).hasSize(4)

    val m1 = nonDefaultModes.get(0)
    assertThat(m1.lexerRules).hasSize(2)
    assertThat(m1.lexerRules[0].ruleNameHandle.ruleName).isEqualTo("A_m1")

    assertThat(m1.lexerRules[1].ruleNameHandle.ruleName).isEqualTo("B_m1")

    val m2 = nonDefaultModes.get(1)
    assertThat(m2.lexerRules).hasSize(2)

    val m3 = nonDefaultModes.get(2)
    assertThat(m3.lexerRules).hasSize(2)

    val m4 = nonDefaultModes.get(3)
    assertThat(m4.lexerRules).hasSize(2)
    assertThat(m4.lexerRules[0].ruleNameHandle.ruleName).isEqualTo("A_m4")
    assertThat(m4.lexerRules[0].body.sourceCode).isEqualTo("'a_m4'")
    assertThat(m4.lexerRules[1].ruleNameHandle.ruleName).isEqualTo("B_m4")
    assertThat(m4.lexerRules[1].body.sourceCode).isEqualTo("'b_m4'")
  }
}
