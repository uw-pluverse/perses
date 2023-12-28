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
package org.perses.reduction.cache

import com.google.common.truth.Truth.assertThat
import org.junit.Ignore
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.grammar.c.LanguageC
import org.perses.program.TokenizedProgramFactory
import org.perses.reduction.cache.AbstractLinearScanEncoder.Companion.NOT_FOUND
import org.perses.reduction.cache.AbstractQueryCacheProfiler.Companion.NULL_PROFILER
import kotlin.system.measureTimeMillis

@RunWith(JUnit4::class)
class LinearScanEncoderTest {

  private val antlrTokens = TestUtility
    .createAntlrTokens("a", "b", "c", "a", "b", "c")
  private val factory = TokenizedProgramFactory.createFactory(antlrTokens, LanguageC)
  private val baseProgram = factory.create(antlrTokens)
  private val tokens = baseProgram.tokens
  private val token_a1 = tokens[0]
  private val token_b1 = tokens[1]
  private val token_c1 = tokens[2]
  private val token_a2 = tokens[3]
  private val token_b2 = tokens[4]
  private val token_c2 = tokens[5]
  private val encoder = LinearScanTokenizedProgramEncoder(
    baseProgram,
    NULL_PROFILER,
    enableCompression = true,
  )
  private val lexemeIdArray = encoder.persesLexemeIdArray

  @Ignore("disabled by default.")
  @Test
  fun benchmarkEncoding() {
    val minToken = 0
    val maxToken = 2000000
    val antlrTokens = TestUtility.createAntlrToknesFromList(
      (minToken..maxToken).map { it.toString() }.toList(),
    )
    val factory = TokenizedProgramFactory.createFactory(antlrTokens, LanguageC)
    val baseProgram = factory.create(antlrTokens)
    val encoder = LinearScanTokenizedProgramEncoder(
      baseProgram,
      NULL_PROFILER,
      enableCompression = true,
    )

    val middleIndex = antlrTokens.size / 2
    val testProgram = factory.create(
      antlrTokens.subList(0, middleIndex) + antlrTokens.subList(middleIndex + 2, antlrTokens.size),
    )
    val repetitions = 20
    val time = measureTimeMillis {
      (1..repetitions).forEach { _ ->
        encoder.encode(testProgram)
      }
    }
    assertThat(time / repetitions).isEqualTo(0)
  }

  @Test
  fun testRefreshlargearray() {
    val initialSize = 2021
    val intList = IntRange(0, initialSize - 1).asSequence().map { it.toString() }.toList()
    val antlrTokens = TestUtility.createAntlrToknesFromList(intList)
    val factory = TokenizedProgramFactory.createFactory(antlrTokens, LanguageC)
    val baseProgram = factory.create(antlrTokens)
    val encoder = LinearScanTokenizedProgramEncoder(
      baseProgram,
      NULL_PROFILER,
      enableCompression = true,
    )
    assertThat(encoder.persesLexemeIdArray.maxLogicalSize).isEqualTo(initialSize)
    encoder.updateEncoder(factory.create(listOf(antlrTokens[0], antlrTokens[1])))
    assertThat(encoder.persesLexemeIdArray.maxLogicalSize).isEqualTo(2)
  }

  @Test
  fun testSearchforlexemeid() {
    assertThat(
      encoder.searchForLexemeId(0, tokens.size, token_a1.persesLexemeId, lexemeIdArray),
    ).isEqualTo(0)

    assertThat(
      encoder.searchForLexemeId(0, tokens.size, token_b1.persesLexemeId, lexemeIdArray),
    ).isEqualTo(1)

    assertThat(
      encoder.searchForLexemeId(3, tokens.size, token_a1.persesLexemeId, lexemeIdArray),
    ).isEqualTo(3)

    assertThat(
      encoder.searchForLexemeId(3, tokens.size, token_c2.persesLexemeId, lexemeIdArray),
    ).isEqualTo(5)

    assertThat(
      encoder.searchForLexemeId(4, tokens.size, token_a1.persesLexemeId, lexemeIdArray),
    ).isEqualTo(NOT_FOUND)

    assertThat(
      encoder.searchForLexemeId(0, 3, token_a1.persesLexemeId, lexemeIdArray),
    ).isEqualTo(0)

    assertThat(
      encoder.searchForLexemeId(1, 3, token_a1.persesLexemeId, lexemeIdArray),
    ).isEqualTo(NOT_FOUND)

    assertThat(
      encoder.searchForLexemeId(1, tokens.size, token_a1.persesLexemeId, lexemeIdArray),
    ).isEqualTo(3)
  }
}
