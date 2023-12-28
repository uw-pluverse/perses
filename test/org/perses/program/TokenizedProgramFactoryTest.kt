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
package org.perses.program

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.antlr.v4.runtime.Token
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility.createAntlrToken
import org.perses.grammar.c.LanguageC
import org.perses.program.TokenizedProgramFactory.Companion.createFactory
import org.perses.util.toImmutableList

@RunWith(JUnit4::class)
class TokenizedProgramFactoryTest {

  val factory = createAntlrTokens(
    ImmutableList.of("a", "b", "c", "d", "e"),
  ).let {
    createFactory(it, LanguageC)
  }

  @Test
  fun testCreateEmptyTokenizedProgramFactory() {
    val factory = TokenizedProgramFactory.createEmptyFactory(LanguageC)
    val tokenFactory = factory.tokenFactory
    val tokens = createAntlrTokens(listOf("a")).also { tokens ->
      // The perses tokens must be created first.
      tokens.forEach { token -> tokenFactory.createPersesToken(token) }
    }
    val program = factory.create(tokens).tokens
    assertThat(program).hasSize(1)
    assertThat(program.single().text).isEqualTo("a")
  }

  @Test
  fun test() {
    val tokens = createAntlrTokens(ImmutableList.of("b", "e"))
    val program = factory.create(tokens)
    val persesTokens = program.tokens
    assertThat(persesTokens).hasSize(2)
    assertThat(persesTokens[0].persesLexemeId).isEqualTo(1)
    assertThat(persesTokens[1].persesLexemeId).isEqualTo(4)
  }

  @Test
  fun testHistogram() {
    val histogram = factory.histogram
    assertThat(histogram.asList()).containsExactly(1, 1, 1, 1, 1)
  }

  @Test
  fun testCopyPersesToken() {
    val tokens = createAntlrTokens(listOf("b"))
    val program = factory.create(tokens)
    val token = program.tokens.single()
    val copy = program.factory.tokenFactory.copyPersesTokenWithNewText(
      newText = "z",
      token,
    )
    assertThat(copy.text).isEqualTo("z")
    assertThat(copy.position).isEqualTo(
      token.position,
    )
  }

  @Test
  fun testHistogramForPrograms() {
    val tokens = createAntlrTokens(ImmutableList.of("b", "e", "b"))
    val program = factory.create(tokens)
    val histogram = factory.computeHistogramFor(program)
    assertThat(histogram).asList().containsExactly(0, 2, 0, 0, 1)
  }

  private fun createAntlrTokens(lexemes: List<String>): ImmutableList<Token> {
    return lexemes.asSequence()
      .map { createAntlrToken(it) }
      .toImmutableList()
  }
}
