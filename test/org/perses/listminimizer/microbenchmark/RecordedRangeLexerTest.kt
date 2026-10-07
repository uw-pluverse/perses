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
import org.perses.util.Interval

@RunWith(JUnit4::class)
class RecordedRangeLexerTest {
  private fun lex(
    text: String,
    vararg tokenSpans: Interval,
  ): List<Token> {
    val lexer = RecordedRangeLexer(CharStreams.fromString(text), tokenSpans.toList())
    return generateSequence { lexer.nextToken().takeIf { it.type != Token.EOF } }.toList()
  }

  @Test
  fun testEverySpanIsExactlyOneTokenAndTheWhitespaceBetweenIsDropped() {
    val tokens =
      lex(
        "int x = 1;\n",
        Interval(0, 3),
        Interval(4, 5),
        Interval(6, 7),
        Interval(8, 9),
        Interval(9, 10),
      )

    assertThat(tokens.map { it.text }).containsExactly("int", "x", "=", "1", ";").inOrder()
    assertThat(tokens.map { it.type }.toSet()).containsExactly(PnfFlatTokenList.TOKEN)
    assertThat(tokens.map { it.startIndex to it.stopIndex })
      .containsExactly(0 to 2, 4 to 4, 6 to 6, 8 to 8, 9 to 9)
      .inOrder()
  }

  @Test
  fun testATokenMaySpanLines() {
    val tokens = lex("<a>\n  </a>", Interval(0, 3), Interval(3, 6), Interval(6, 10))

    assertThat(tokens.map { it.text }).containsExactly("<a>", "\n  ", "</a>").inOrder()
    assertThat(tokens.last().line).isEqualTo(2)
    assertThat(tokens.last().charPositionInLine).isEqualTo(2)
  }

  @Test
  fun testAnEmptyTextLexesToNoTokens() {
    assertThat(lex("")).isEmpty()
  }

  @Test
  fun testLineAndColumnAreWhereEachTokenStarts() {
    val tokens = lex("a\nbc\n d", Interval(0, 1), Interval(2, 4), Interval(6, 7))

    assertThat(tokens.map { it.line to it.charPositionInLine })
      .containsExactly(1 to 0, 2 to 0, 3 to 1)
      .inOrder()
  }

  @Test
  fun testOffsetsCountCodePointsNotUtf16Units() {
    // The emoji is two UTF-16 units but one code point, which is what ANTLR streams index.
    val text = "\uD83D\uDE00 x"
    val tokens = lex(text, Interval(0, 1), Interval(2, 3))

    assertThat(tokens.map { it.text }).containsExactly("\uD83D\uDE00", "x").inOrder()
    assertThat(tokens.last().startIndex).isEqualTo(2)
    assertThat(tokens.last().charPositionInLine).isEqualTo(2)
  }

  @Test
  fun testTheLexerIsRewindable() {
    val lexer =
      RecordedRangeLexer(CharStreams.fromString("ab"), listOf(Interval(0, 1), Interval(1, 2)))
    val first = generateSequence { lexer.nextToken().takeIf { it.type != Token.EOF } }.count()
    lexer.reset()
    val second = generateSequence { lexer.nextToken().takeIf { it.type != Token.EOF } }.count()

    assertThat(first).isEqualTo(2)
    assertThat(second).isEqualTo(2)
  }

  @Test
  fun testSpansMustBeNonEmptyAscendingDisjointAndInsideTheText() {
    assertThrows(IllegalArgumentException::class.java) { lex("abc", Interval(1, 1)) }
    assertThrows(
      IllegalArgumentException::class.java,
    ) { lex("abc", Interval(0, 2), Interval(1, 3)) }
    assertThrows(
      IllegalArgumentException::class.java,
    ) { lex("abc", Interval(2, 3), Interval(0, 1)) }
    assertThrows(IllegalArgumentException::class.java) { lex("abc", Interval(0, 4)) }
  }

  /** Text outside every span is dropped, so it must be what printing at positions restores. */
  @Test
  fun testOnlySpacesAndNewlinesMayLieOutsideTheSpans() {
    assertThrows(IllegalArgumentException::class.java) { lex("a b", Interval(0, 1)) }
    assertThrows(IllegalArgumentException::class.java) { lex("a b", Interval(2, 3)) }
    assertThrows(
      IllegalArgumentException::class.java,
    ) { lex("a\tb", Interval(0, 1), Interval(2, 3)) }
    assertThat(lex(" \n a \n", Interval(3, 4)).single().text).isEqualTo("a")
  }
}
