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
package org.perses.reduction.cache

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.grammar.c.LanguageC
import org.perses.program.TokenizedProgram
import org.perses.util.hashing.EnumShaAlgorithm

@RunWith(JUnit4::class)
class ContentShaHashBasedQueryCacheTest {
  // Base program with 2 lines of code
  val origProgram =
    TestUtility.createTokenizedProgramFromString(
      """
      int a;
      int a;
      """.trimIndent(),
      LanguageC,
    )
  val tokens = origProgram.tokens

  val tokenInt1 = tokens[0]
  val tokenA1 = tokens[1]
  val tokenSemi1 = tokens[2]
  val tokenInt2 = tokens[3]
  val tokenA2 = tokens[4]
  val tokenSemi2 = tokens[5]

  // Two varaint programs.
  val firstLine =
    TokenizedProgram(
      ImmutableList.of(tokenInt1, tokenA1, tokenSemi1),
      origProgram.factory,
    )
  val secondLine =
    TokenizedProgram(
      ImmutableList.of(tokenInt2, tokenA2, tokenSemi2),
      origProgram.factory,
    )
  val multiLine =
    TokenizedProgram(
      ImmutableList.of(tokenInt1, tokenA2, tokenSemi2),
      origProgram.factory,
    )
  val multiLine2 =
    TokenizedProgram(
      ImmutableList.of(tokenInt1, tokenA1, tokenSemi2),
      origProgram.factory,
    )

  // enableFormat does not matter here as we directly test internal methods
  val encoder =
    ContentShaHashEncoder(
      origProgram,
      AbstractQueryCacheProfiler.NULL_PROFILER,
      enableFormat = false,
      shaAlgorithm = EnumShaAlgorithm.SHA256,
    )

  @Test
  fun testConvertProgramToRawString() {
    val singleTokenPerLine = "int\na\n;"
    encoder.convertProgramToRawString(firstLine).let {
      assertThat(it).isEqualTo(singleTokenPerLine)
    }
    encoder.convertProgramToRawString(secondLine).let {
      assertThat(it).isEqualTo(singleTokenPerLine)
    }
    encoder.convertProgramToRawString(multiLine).let {
      assertThat(it).isEqualTo(singleTokenPerLine)
    }
  }

  @Test
  fun testConvertProgramToRawStringWithFormat() {
    encoder.convertProgramToRawStringWithFormat(firstLine).let {
      assertThat(it).isEqualTo("int a ; ")
    }
    encoder.convertProgramToRawStringWithFormat(secondLine).let {
      assertThat(it).isEqualTo("int a ; ")
    }
    encoder.convertProgramToRawStringWithFormat(multiLine).let {
      assertThat(it).isEqualTo("int \na ; ")
    }
    encoder.convertProgramToRawStringWithFormat(multiLine2).let {
      assertThat(it).isEqualTo("int a \n; ")
    }
  }
}
