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
package org.perses.program

import com.google.common.collect.ImmutableList
import com.google.common.collect.Sets
import com.google.common.truth.Truth.assertThat
import org.antlr.v4.runtime.Token
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.TestUtility.createAntlrToken
import org.perses.grammar.c.LanguageC
import org.perses.util.toImmutableList

@RunWith(JUnit4::class)
class TokenizedProgramTest {
  val antlrTokens =
    createAntlrTokens(
      ImmutableList.of("a", "b", "c", "d", "e"),
    )
  val originalProgram = TokenizedProgram.createForFreshAntlrLexemes(antlrTokens)

  @Test
  fun testCreateProgram() {
    val tokens = createAntlrTokens(listOf("a"))
    val program = TokenizedProgram.createForFreshAntlrLexemes(tokens).tokens
    assertThat(program).hasSize(1)
    assertThat(program.single().lexemeText).isEqualTo("a")
  }

  @Test
  fun test() {
    val tokens = createAntlrTokens(ImmutableList.of("b", "e"))
    val program = TokenizedProgram.createForFreshAntlrLexemes(tokens)
    val persesTokens = program.tokens
    assertThat(persesTokens).hasSize(2)
  }

  @Test
  fun testCopyPersesToken() {
    val tokens = createAntlrTokens(listOf("b"))
    val program = TokenizedProgram.createForFreshAntlrLexemes(tokens)
    val token = program.tokens.single().asAntlrToken()
    val copy =
      PersesTokenFactory.copyPersesTokenWithNewText(
        newText = "z",
        token,
      )
    assertThat(copy.lexemeText).isEqualTo("z")
    assertThat(copy.position).isEqualTo(
      token.position,
    )
  }

  private fun createAntlrTokens(lexemes: List<String>): ImmutableList<Token> =
    lexemes
      .asSequence()
      .map { createAntlrToken(it) }
      .toImmutableList()

  @Test
  fun testCountCharsOfAllTokens() {
    val p =
      TestUtility.createTokenizedProgramFromString(
        sourceCode = "int a ; ",
        LanguageC,
      )
    assertThat(p.totalCharacterCount).isEqualTo(5)
  }

  @Test
  fun testTokenPositionEquality() {
    val token1 = TokenPosition(line = 1, charPositionInLine = 1)
    val token2 = TokenPosition(line = 1, charPositionInLine = 1)
    assertThat(token1).isEqualTo(token2)
    Sets.newIdentityHashSet<TokenPosition>().let { set ->
      set.add(token1)
      set.add(token2)
      assertThat(set).hasSize(2)
      assertThat(set).containsExactly(token1, token2)
    }
    mutableSetOf(token1, token2).let { set ->
      assertThat(set).hasSize(1)
      assertThat(set).containsExactly(token1)
    }
  }

  @Test
  fun testSizeProperty() {
    val p =
      TestUtility.createTokenizedProgramFromString(
        sourceCode = "int a ; ",
        LanguageC,
      )
    val size = p.computeSize(payload = p, canonicalTokenCount = 3)
    assertThat(size.canonicalTokenCount).isEqualTo(3)
    assertThat(size.surrogateTokenCount).isEqualTo(3)
    assertThat(size.totalCharacterCount).isEqualTo(5)
    assertThat(size.nonBlankCharacterCount).isEqualTo(5)
  }

  @Test
  fun testSizeWithMultipleTokens() {
    val tokens = createAntlrTokens(listOf("hello", " world  "))
    val p = TokenizedProgram.createForFreshAntlrLexemes(tokens)
    val size = p.computeSize(payload = p, canonicalTokenCount = null)
    assertThat(size.canonicalTokenCount).isEqualTo(2)
    assertThat(size.surrogateTokenCount).isEqualTo(2)
    assertThat(size.totalCharacterCount).isEqualTo(13)
    assertThat(size.nonBlankCharacterCount).isEqualTo(10)
  }
}
