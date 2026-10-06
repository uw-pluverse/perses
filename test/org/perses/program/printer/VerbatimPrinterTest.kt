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
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.program.EnumFormatControl
import org.perses.program.PersesTokenFactory
import org.perses.program.TokenPosition
import org.perses.program.TokenizedProgram

@RunWith(JUnit4::class)
class VerbatimPrinterTest {
  private fun program(vararg pieces: String) =
    TokenizedProgram(
      ImmutableList.copyOf(pieces.map { PersesTokenFactory.createPlainTextToken(it) }),
    )

  @Test
  fun testTheTokensAreConcatenatedWithNothingBetween() {
    val printed = VerbatimPrinter.print(program("int ", "x", " = 1;\n"))

    assertThat(printed.sourceCode).isEqualTo("int x = 1;\n")
  }

  @Test
  fun testPlacementsAreTheLineAndColumnEachTokenStartsAt() {
    val recorder = TokenPlacementRecorder()
    val tokens = program("a\n", "bc", "\n d").tokens

    VerbatimPrinter.print(TokenizedProgram(tokens), recorder).sourceCode

    assertThat(recorder.getPositionOrNull(tokens[0])).isEqualTo(TokenPosition(1, 0))
    assertThat(recorder.getPositionOrNull(tokens[1])).isEqualTo(TokenPosition(2, 0))
    assertThat(recorder.getPositionOrNull(tokens[2])).isEqualTo(TokenPosition(2, 2))
  }

  @Test
  fun testTheRegistryServesItForTheVerbatimFormat() {
    assertThat(PrinterRegistry.getPrinter(EnumFormatControl.VERBATIM)).isEqualTo(VerbatimPrinter)
  }
}
