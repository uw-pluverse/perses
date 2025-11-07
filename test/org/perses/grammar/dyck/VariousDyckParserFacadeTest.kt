/*
 * Copyright (C) 2018-2025 University of Waterloo.
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
package org.perses.grammar.dyck

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.grammar.c.OptCLexer

@RunWith(JUnit4::class)
class VariousDyckParserFacadeTest {
  val brace =
    BraceDyckParserFacade(
      underlyingLexerClass = OptCLexer::class.java,
    )

  val braceParenthesis =
    BraceParenthesisDyckParserFacade(
      underlyingLexerClass = OptCLexer::class.java,
    )

  @Test
  fun testTokenizeWithBraceFacade() {
    val tokens = brace.tokenizeString("int f() {return 0;}")
    val tokenTypes = tokens.map { it.type }
    assertThat(tokenTypes)
      .containsExactly(
        PnfDyckParser.OTHER,
        PnfDyckParser.OTHER,
        PnfDyckParser.OTHER,
        PnfDyckParser.OTHER,
        PnfDyckParser.OPEN_BRACE,
        PnfDyckParser.OTHER,
        PnfDyckParser.OTHER,
        PnfDyckParser.OTHER,
        PnfDyckParser.CLOSE_BRACE,
      ).inOrder()
  }

  @Test
  fun testTokenizeWithBraceParenthesisFacade() {
    val tokens = braceParenthesis.tokenizeString("int f() {return 0;}")
    val tokenTypes = tokens.map { it.type }
    assertThat(tokenTypes)
      .containsExactly(
        PnfDyckParser.OTHER,
        PnfDyckParser.OTHER,
        PnfDyckParser.OPEN_PARENTHESIS,
        PnfDyckParser.CLOSE_PARENTHESIS,
        PnfDyckParser.OPEN_BRACE,
        PnfDyckParser.OTHER,
        PnfDyckParser.OTHER,
        PnfDyckParser.OTHER,
        PnfDyckParser.CLOSE_BRACE,
      ).inOrder()
  }
}
