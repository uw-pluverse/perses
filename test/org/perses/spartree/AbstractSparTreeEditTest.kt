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
import org.antlr.v4.runtime.CommonTokenFactory
import org.junit.Test
import org.perses.grammar.ParseErrorHandling
import org.perses.grammar.onetoken.OneTokenParserFacade
import org.perses.program.AbstractPersesToken
import org.perses.program.PersesTokenFactory
import org.perses.program.TokenPosition

class AbstractSparTreeEditTest {
  private val tokenFactory = PersesTokenFactory
  private val commonTokenFactory = CommonTokenFactory()

  @Test
  fun testComputeDeletedCode() {
    // Line 1: "  token1 token2"
    // token1 at pos 2, length 6
    // token2 at pos 10, length 6
    val t1 = createToken("token1", 1, 2)
    val t2 = createToken("token2", 1, 10)

    // Line 2: "token3"
    // token3 at pos 0, length 6
    val t3 = createToken("token3", 2, 0)

    // Line 5: "    token4"
    // token4 at pos 4, length 6
    val t4 = createToken("token4", 5, 4)

    val n1 = LexerRuleSparTreeNode(1, t1, null)
    val n2 = LexerRuleSparTreeNode(2, t2, null)
    val n3 = LexerRuleSparTreeNode(3, t3, null)
    val n4 = LexerRuleSparTreeNode(4, t4, null)

    val result =
      AbstractSparTreeEdit.computeDeletedCodeForAntlrTokens(
        listOf(t1, t2, t3, t4),
      )

    val expected =
      """
      1:  token1  token2
      2:token3
      5:    token4
      """.trimIndent()

    assertThat(result).isEqualTo(expected)
  }

  private fun createToken(
    text: String,
    line: Int,
    charPos: Int,
  ): AbstractPersesToken.AntlrToken {
    val antlrToken = commonTokenFactory.create(1, text)
    antlrToken.line = line
    antlrToken.charPositionInLine = charPos
    return tokenFactory.createPersesToken(antlrToken, TokenPosition(line, charPos))
  }

  @Test
  fun testComputeDeletedCodeMultipleNodes() {
    val t1 = createToken("abc", 1, 0)
    val t2 = createToken("def", 1, 5)

    val result = AbstractSparTreeEdit.computeDeletedCodeForAntlrTokens(listOf(t1, t2))
    assertThat(result).isEqualTo("1:abc  def")
  }

  @Test
  fun testComputeDeletedCodeAlignment() {
    val t1 = createToken("line1", 1, 0)
    val t2 = createToken("line10", 10, 0)

    val result = AbstractSparTreeEdit.computeDeletedCodeForAntlrTokens(listOf(t1, t2))
    val expected =
      """
       1:line1
      10:line10
      """.trimIndent()
    assertThat(result).isEqualTo(expected)
  }

  @Test
  fun testCompareToWithCharacterCountTieBreaker() {
    val parserFacade = OneTokenParserFacade()
    val tree1 =
      SparTreeParserUtility.buildSparTree(
        sourceCode = "abc",
        parserFacade = parserFacade,
        specifiedSparTreeNodeFactory = null,
        simplifyTree = false,
        canonicalTokenCountComputer = { null },
        errorMode = ParseErrorHandling.STRICT,
      )
    val tree2 =
      SparTreeParserUtility.buildSparTree(
        sourceCode = "abcdef",
        parserFacade = parserFacade,
        specifiedSparTreeNodeFactory = null,
        simplifyTree = false,
        canonicalTokenCountComputer = { null },
        errorMode = ParseErrorHandling.STRICT,
      )

    val edit1 = EmptySparTreeEdit(tree1, "context1")
    val edit2 = EmptySparTreeEdit(tree2, "context2")

    // Both should have 1 token
    assertThat(edit1.program.tokenCount).isEqualTo(1)
    assertThat(edit2.program.tokenCount).isEqualTo(1)

    // edit1 has 3 characters, edit2 has 6 characters.
    // The tie-breaker should favor edit1 (fewer characters).
    assertThat(edit1.compareTo(edit2)).isLessThan(0)
    assertThat(edit2.compareTo(edit1)).isGreaterThan(0)
  }
}
