/*
 * Copyright (C) 2018-2026 University of Waterloo.
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
package org.perses.listminimizer.microbenchmark

import com.google.common.truth.Truth.assertThat
import org.antlr.v4.runtime.CharStreams
import org.antlr.v4.runtime.Token
import org.junit.Assert.assertThrows
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.grammar.flattokenlist.PnfFlatTokenList

@RunWith(JUnit4::class)
class RecordedRangeLexerTest {
  private fun lex(
    text: String,
    vararg cutOffsets: Int,
  ): List<Token> {
    val lexer = RecordedRangeLexer(CharStreams.fromString(text), cutOffsets)
    return generateSequence { lexer.nextToken().takeIf { it.type != Token.EOF } }.toList()
  }

  @Test
  fun testEveryPieceBetweenConsecutiveCutsIsOneToken() {
    val tokens = lex("int x = 1;", 0, 4, 5, 10)

    assertThat(tokens.map { it.text }).containsExactly("int ", "x", " = 1;").inOrder()
    assertThat(
      tokens.map {
        it.type
      },
    ).containsExactly(PnfFlatTokenList.TOKEN, PnfFlatTokenList.TOKEN, PnfFlatTokenList.TOKEN)
    assertThat(tokens.map { it.startIndex to it.stopIndex })
      .containsExactly(0 to 3, 4 to 4, 5 to 9)
      .inOrder()
  }

  @Test
  fun testThePiecesReassembleTheText() {
    val text = "<a>foo<b/>bar</a>"

    assertThat(lex(text, 0, 3, 6, 10, 13, 17).joinToString("") { it.text }).isEqualTo(text)
  }

  @Test
  fun testTheWholeTextIsOneTokenWhenThereAreNoInnerCuts() {
    val tokens = lex("ab\ncd", 0, 5)

    assertThat(tokens.map { it.text }).containsExactly("ab\ncd")
  }

  @Test
  fun testAnEmptyTextLexesToNoTokens() {
    assertThat(lex("", 0)).isEmpty()
  }

  @Test
  fun testLineAndColumnAreWhereEachPieceStarts() {
    val tokens = lex("a\nbc\n d", 0, 2, 4, 6, 7)

    assertThat(tokens.map { it.line to it.charPositionInLine })
      .containsExactly(1 to 0, 2 to 0, 2 to 2, 3 to 1)
      .inOrder()
  }

  @Test
  fun testOffsetsCountCodePointsNotUtf16Units() {
    // The emoji is two UTF-16 units but one code point, which is what ANTLR streams index.
    val text = "/* \uD83D\uDE00 */ x"
    val codePoints = text.codePointCount(0, text.length)
    val tokens = lex(text, 0, codePoints - 1, codePoints)

    assertThat(tokens.map { it.text }).containsExactly("/* \uD83D\uDE00 */ ", "x").inOrder()
    assertThat(tokens.last().startIndex).isEqualTo(codePoints - 1)
    assertThat(tokens.last().charPositionInLine).isEqualTo(codePoints - 1)
  }

  @Test
  fun testTheLexerIsRewindable() {
    val lexer = RecordedRangeLexer(CharStreams.fromString("ab"), intArrayOf(0, 1, 2))
    val first = generateSequence { lexer.nextToken().takeIf { it.type != Token.EOF } }.count()
    lexer.reset()
    val second = generateSequence { lexer.nextToken().takeIf { it.type != Token.EOF } }.count()

    assertThat(first).isEqualTo(2)
    assertThat(second).isEqualTo(2)
  }

  @Test
  fun testCutsMustStartAtZeroEndAtTheLengthAndIncrease() {
    assertThrows(IllegalArgumentException::class.java) { lex("abc", 1, 3) }
    assertThrows(IllegalArgumentException::class.java) { lex("abc", 0, 2) }
    assertThrows(IllegalArgumentException::class.java) { lex("abc", 0, 2, 2, 3) }
    assertThrows(IllegalArgumentException::class.java) { lex("abc", 0, 2, 1, 3) }
  }
}
