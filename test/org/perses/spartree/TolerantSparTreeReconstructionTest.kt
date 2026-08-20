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
package org.perses.spartree

import com.google.common.truth.Truth.assertThat
import com.google.common.truth.Truth.assertWithMessage
import org.antlr.v4.runtime.Token
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.grammar.ParseErrorHandling
import org.perses.grammar.c.PnfCParserFacade
import org.perses.program.TokenizedProgram
import java.nio.file.Files
import java.nio.file.Paths
import kotlin.io.path.name
import kotlin.io.path.readText

/**
 * Asserts the reconstruction invariant the golden dumps cannot: for every tolerant-parse input under
 * [INPUT_DIR], the spar-tree's leaves cover every non-whitespace input character, so collecting the
 * leaves reconstructs the program. This is the guard the golden tests lack -- a dropped character
 * would fail here, not merely change a frozen dump. Every input -- including the .cpp one, parsed by
 * the C facade to stress it with C++ constructs -- must reconstruct; this holds now that OrigC.g4 no
 * longer skips #define/#pragma/#line/asm. (The inputs deliberately avoid comments, which the grammar
 * still drops from the default channel.)
 */
@RunWith(JUnit4::class)
class TolerantSparTreeReconstructionTest {
  private val cFacade = PnfCParserFacade()

  @Test
  fun testEveryInputReconstructsFromLeaves() {
    val inputs =
      Files.list(Paths.get(INPUT_DIR)).use { stream ->
        stream.filter { it.name.substringAfterLast('.') in SOURCE_EXTENSIONS }.sorted().toList()
      }
    assertThat(inputs).isNotEmpty()
    for (input in inputs) {
      val sourceCode = input.readText()
      val program = buildTolerant(sourceCode).programSnapshot.payload
      assertLeavesCoverNonWhitespace(input.name, sourceCode, program)
    }
  }

  private fun buildTolerant(sourceCode: String): SparTree =
    SparTreeParserUtility.buildSparTree(
      sourceCode = sourceCode,
      parserFacade = cFacade,
      specifiedSparTreeNodeFactory = null,
      simplifyTree = true,
      canonicalTokenCountComputer = { null },
      errorMode = ParseErrorHandling.TOLERANT,
    )

  private fun assertLeavesCoverNonWhitespace(
    name: String,
    input: String,
    program: TokenizedProgram,
  ) {
    val covered = BooleanArray(input.length)
    for (token in program.tokens) {
      if (token !is Token) continue
      val start = token.startIndex
      val stop = token.stopIndex
      if (start < 0 || stop < start || stop >= input.length) continue
      for (i in start..stop) covered[i] = true
    }
    val uncovered =
      input.indices
        .filter { !covered[it] && !input[it].isWhitespace() }
        .map { "'${input[it]}'@$it" }
    assertWithMessage("uncovered non-whitespace characters in $name").that(uncovered).isEmpty()
  }

  companion object {
    private const val INPUT_DIR = "test/org/perses/spartree/tolerant_spartree_inputs"
    private val SOURCE_EXTENSIONS = setOf("c", "cpp", "cc", "cxx")
  }
}
