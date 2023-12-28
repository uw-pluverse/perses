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
package org.perses.antlr.util

import com.google.common.truth.Truth
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4

@RunWith(JUnit4::class)
class LexerParserCombinerTest {
  @Test
  fun test() {
    val lexerDef =
      """lexer grammar ToyLexer;
      | BREAK: 'break';
      | NIL_LIT: 'nil';
      | fragment DECIMALS
      |  : [0-9]+
      |  ;
      """.trimMargin()

    val parserDef =
      """parser grammar ToyParser;
      | options {
      |     tokenVocab = ToyLexer;
      |     superClass = ToyParserBase;
      | }
      | 
      | start: BREAK NIL_LIT;
      """.trimMargin()

    val combined = removeWhitespaces(
      LexerParserCombiner.combineLexerAndParser(lexerDef, parserDef, "Toy"),
    )

    val expected = removeWhitespaces(
      """// Combined by org.perses.antlr.util.LexerParserCombiner
      // DO NOT MODIFY.
      grammar Toy;
      BREAK : 'break' ;
      NIL_LIT : 'nil' ;
      fragment DECIMALS : [0-9]+;
      start : BREAK NIL_LIT ;
      """.trimIndent(),
    )
    Truth.assertThat(combined).isEqualTo(expected)
  }

  companion object {
    fun removeWhitespaces(string: String) = string.replace(Regex(pattern = "\\s+"), "")
  }
}
