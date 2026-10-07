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
package org.perses.program.printer

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.antlr.v4.runtime.CommonToken
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.program.AbstractPersesToken
import org.perses.program.EnumFormatControl
import org.perses.program.PersesTokenFactory
import org.perses.program.TokenPosition
import org.perses.program.TokenizedProgram

@RunWith(JUnit4::class)
class RecordedPositionPrinterTest {
  /** A token with [text] at [line] and [column], as the recorded-range lexer emits them. */
  private fun token(
    text: String,
    line: Int,
    column: Int,
  ): AbstractPersesToken =
    PersesTokenFactory.createPersesToken(
      CommonToken(1, text).apply {
        this.line = line
        charPositionInLine = column
      },
      overridingPosition = null,
    )

  private fun print(vararg tokens: AbstractPersesToken) =
    RecordedPositionPrinter.print(TokenizedProgram(ImmutableList.copyOf(tokens))).sourceCode

  @Test
  fun testTokensArePlacedAtTheirLineAndColumn() {
    assertThat(print(token("int", 1, 0), token("x", 1, 4), token(";", 1, 5), token("}", 3, 2)))
      .isEqualTo("int x;\n\n  }\n")
  }

  @Test
  fun testADeletedTokenLeavesItsPlaceBlank() {
    assertThat(print(token("int", 1, 0), token(";", 1, 5))).isEqualTo("int  ;\n")
  }

  /** XML's whitespace tokens contain newlines; what follows them must not move down a line more. */
  @Test
  fun testATokenSpanningLinesMovesTheCursorWithIt() {
    assertThat(
      print(token("<a>", 1, 0), token("\n  ", 1, 3), token("<b/>", 2, 2), token("\n", 2, 6)),
    ).isEqualTo("<a>\n  <b/>\n")
  }

  @Test
  fun testColumnsCountCodePoints() {
    // The emoji is two UTF-16 units but one code point, so "x" at column 2 follows one space.
    assertThat(print(token("\uD83D\uDE00", 1, 0), token("x", 1, 2))).isEqualTo("\uD83D\uDE00 x\n")
  }

  @Test
  fun testPlacementsAreWhereEachTokenIsPrinted() {
    val recorder = TokenPlacementRecorder()
    val tokens = listOf(token("a", 1, 0), token("b", 2, 3))

    RecordedPositionPrinter
      .print(
        TokenizedProgram(ImmutableList.copyOf(tokens)),
        recorder,
      ).sourceCode

    assertThat(recorder.getPositionOrNull(tokens[0])).isEqualTo(TokenPosition(1, 0))
    assertThat(recorder.getPositionOrNull(tokens[1])).isEqualTo(TokenPosition(2, 3))
  }

  @Test
  fun testTheRegistryServesItForTheRecordedPositionFormat() {
    assertThat(
      PrinterRegistry.getPrinter(EnumFormatControl.RECORDED_POSITION),
    ).isEqualTo(RecordedPositionPrinter)
  }
}
