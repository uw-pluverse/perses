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
package org.perses.antlr.atn

import com.google.common.truth.Truth.assertThat
import objectexplorer.MemoryMeasurer
import org.junit.Assert
import org.junit.Ignore
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.antlr.TokenType
import org.perses.antlr.toTokenType
import org.perses.grammar.jackson.JacksonParserFacade
import org.perses.grammar.python3.Python3Lexer
import org.perses.grammar.rust.PnfRustLexer
import org.perses.util.Util

@RunWith(JUnit4::class)
class LexerAtnWrapperTest {
  val c = LexerAtnWrapper.createLexerWrapperFromLexerClass(OrigCLexer::class.java)
  val rust = LexerAtnWrapper.createLexerWrapperFromLexerClass(PnfRustLexer::class.java)
  val test = LexerAtnWrapper.createLexerWrapperFromLexerClass(TestLexer::class.java)
  val javascript = LexerAtnWrapper.createLexerWrapperFromLexerClass(TestJavaScriptLexer::class.java)
  val python = LexerAtnWrapper.createLexerWrapperFromLexerClass(Python3Lexer::class.java)

  // TODO(cnsun): this needs improvement. The graph traversal has a bug.
  @Test
  fun testGetAcyclicPathsToGenerateGivenTokenType() {
    val result =
      python.getAcyclicPathsToGenerateGivenTokenType(Python3Lexer.NEWLINE.toTokenType())
    assertThat(result).isNotEmpty()
  }

  @Test
  fun testGenerateCandidateCanonicalTokenTestsGivenTokenType() {
    val result =
      python.generateCandidateCanonicalTokenTextsGivenTokenType(
        ruleType = TokenType(Python3Lexer.NEWLINE),
        countLimit = 2,
      )
    assertThat(result).containsExactly("\n", " ")
  }

  @Test
  fun testHasInformationForTokenFalse() {
    val wrapper = JacksonParserFacade().lexerAtnWrapper
    val tokens = wrapper.metaTokenInfoDB.tokens
    tokens.forEach { token ->
      assertThat(wrapper.hasInformationForToken(token.tokenType)).isFalse()
    }
    assertThat(wrapper.hasInformationForToken(100000.toTokenType())).isFalse()
    assertThat(wrapper.hasInformationForToken(999999.toTokenType())).isFalse()
  }

  @Test
  fun testHasInformationForTokenTrue() {
    val wrapper = python
    listOf(Python3Lexer.FOR, Python3Lexer.IF, Python3Lexer.WHILE)
      .map { it.toTokenType() }
      .forEach {
        assertThat(wrapper.hasInformationForToken(it)).isTrue()
      }
    assertThat(wrapper.hasInformationForToken(Python3Lexer.INDENT.toTokenType())).isFalse()
    assertThat(wrapper.hasInformationForToken(Python3Lexer.DEDENT.toTokenType())).isFalse()
  }

  @Test
  fun test() {
    c.metaTokenInfoDB
      .asSequence()
      .zip(c.metaTokenInfoDB.asSequence())
      .forEach { (first, second) ->
        println("$first, $second")
        try {
          c.canBeConcatWithoutSpace(first.tokenType, second.tokenType)
        } catch (e: Throwable) {
          Assert.fail(
            buildString {
              appendLine("processing $first, $second")
              appendLine("Exception message: ${e.message}")
              appendLine("Stack trace:")
              appendLine(e.stackTraceToString())
            },
          )
        }
      }
    val klasses = HashSet<Class<*>>()
    val bytes =
      MemoryMeasurer
        .measureBytes(c) {
          val klass = it::class.java
          klasses.add(klass)
          true
        }
    klasses.sortedBy { it.canonicalName }.forEach { println(it) }
    assertThat(bytes).isLessThan(Util.SpaceSize.megaBytes(11L).bytes)
  }

  @Ignore("The current algorithm does not handle non-greedy matching.")
  @Test
  fun testBlockCommentWithBlockComment() {
    val tokenType = OrigCLexer.BlockComment.toTokenType()
    assertThat(c.canBeConcatWithoutSpace(tokenType, tokenType)).isTrue()
  }

  @Ignore
  @Test
  fun testCanBeSubsumedForNonGreedyMatching() {
    val nfa = test.copyTokenNfa(TestLexer.GreedyWildcard.toTokenType())
    println(nfa.printTopology())
    val nfa2 = test.copyTokenNfa(TestLexer.NonGreedyWildcard.toTokenType())
    println(nfa2.printTopology())
    Assert.fail()
  }

  @Test
  fun testJavaScriptStringLiteral() {
    val atnPath =
      javascript.findATNPathForLexeme(
        lexeme = "''",
        ruleType = javascript.metaTokenInfoDB.getTokenInfoWithName("StringLiteral")!!.tokenType,
      )!!
    assertThat(atnPath.stateSequence).isNotEmpty()
  }

  @Test
  fun testIdWithId() {
    val tokenType = OrigCLexer.Identifier.toTokenType()
    assertThat(c.canBeConcatWithoutSpace(tokenType, tokenType)).isFalse()
  }

  @Test
  fun testGenerateCandidateCanonicalTokenTextsGivenTokenType() {
    var tokenType = c.metaTokenInfoDB.getTokenInfoWithName("Constant")!!.tokenType
    var lexemes = c.generateCandidateCanonicalTokenTextsGivenTokenType(tokenType, countLimit = 2)
    assertThat(lexemes).containsExactly("0", "1")
    lexemes = c.generateCandidateCanonicalTokenTextsGivenTokenType(tokenType, countLimit = 5)
    assertThat(lexemes).containsExactly("0", "1", "2", "3", "4")
    tokenType = rust.metaTokenInfoDB.getTokenInfoWithName("FullIntLit")!!.tokenType
    lexemes = rust.generateCandidateCanonicalTokenTextsGivenTokenType(tokenType, countLimit = 2)
    assertThat(lexemes).containsExactly("0", "1")
    tokenType = rust.metaTokenInfoDB.getTokenInfoWithName("FloatLit")!!.tokenType
    lexemes = rust.generateCandidateCanonicalTokenTextsGivenTokenType(tokenType, countLimit = 2)
    assertThat(lexemes).containsExactly("0.", "1.")
    tokenType = rust.metaTokenInfoDB.getTokenInfoWithName("StringLit")!!.tokenType
    lexemes = rust.generateCandidateCanonicalTokenTextsGivenTokenType(tokenType, countLimit = 2)
    assertThat(lexemes).containsExactly("\"\"")
  }
}
