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
package org.perses.grammar.dyck

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.grammar.ParseErrorHandling
import org.perses.grammar.c.OptCLexer
import org.perses.spartree.LexerRuleSparTreeNode
import org.perses.spartree.SparTreeParserUtility

@RunWith(JUnit4::class)
class PristineDyckParserFacadeTest {
  private val brace = PristineBraceDyckParserFacade(OptCLexer::class.java)

  private val braceParenthesis = PristineBraceParenthesisDyckParserFacade(OptCLexer::class.java)

  @Test
  fun pristineParserSharesTheLineAwareTokenNumbering() {
    // The pristine facade reuses the line-aware Dyck lexer, whose tokens carry
    // PnfLineAwareDyckParser type numbers, so PnfPristineDyckParser must number every token
    // identically or those reused tokens would be misread.
    fun assertSame(
      pristine: Int,
      lineAware: Int,
    ) = assertThat(pristine).isEqualTo(lineAware)
    assertSame(PnfPristineDyckParser.OPEN_BRACE, PnfLineAwareDyckParser.OPEN_BRACE)
    assertSame(PnfPristineDyckParser.CLOSE_BRACE, PnfLineAwareDyckParser.CLOSE_BRACE)
    assertSame(PnfPristineDyckParser.OPEN_PARENTHESIS, PnfLineAwareDyckParser.OPEN_PARENTHESIS)
    assertSame(PnfPristineDyckParser.CLOSE_PARENTHESIS, PnfLineAwareDyckParser.CLOSE_PARENTHESIS)
    assertSame(PnfPristineDyckParser.OPEN_BRACKET, PnfLineAwareDyckParser.OPEN_BRACKET)
    assertSame(PnfPristineDyckParser.CLOSE_BRACKET, PnfLineAwareDyckParser.CLOSE_BRACKET)
    assertSame(PnfPristineDyckParser.OTHER, PnfLineAwareDyckParser.OTHER)
    assertSame(PnfPristineDyckParser.FABRICATED_NEWLINE, PnfLineAwareDyckParser.FABRICATED_NEWLINE)
  }

  @Test
  fun tokenizationMatchesTheSharedDyckLexer() {
    val tokens = brace.tokenizeString("int f() {return 0;}")
    assertThat(tokens.map { it.type })
      .containsExactly(
        PnfLineAwareDyckParser.OTHER,
        PnfLineAwareDyckParser.OTHER,
        PnfLineAwareDyckParser.OTHER,
        PnfLineAwareDyckParser.OTHER,
        PnfLineAwareDyckParser.OPEN_BRACE,
        PnfLineAwareDyckParser.OTHER,
        PnfLineAwareDyckParser.OTHER,
        PnfLineAwareDyckParser.OTHER,
        PnfLineAwareDyckParser.CLOSE_BRACE,
      ).inOrder()
  }

  @Test
  fun fabricatedNewlinesAreAbsentFromTheTree() {
    val source = "a b\nc d\n{e}\nf g"
    // The stream really carries newline tokens, so their absence from the tree is a genuine drop.
    assertThat(brace.tokenizeString(source).map { it.type })
      .contains(PnfLineAwareDyckParser.FABRICATED_NEWLINE)

    val leaves = collectLeafTokenTypes(source, brace)
    assertThat(leaves).doesNotContain(PnfLineAwareDyckParser.FABRICATED_NEWLINE)
    assertThat(leaves).contains(PnfLineAwareDyckParser.OTHER)
  }

  @Test
  fun multiLineContentNestsByBracketsAloneWithNoLineStructure() {
    // The same content laid out across many lines and on a single line yields the same leaf
    // sequence: the pristine grammar groups purely by balanced delimiters, oblivious to line breaks.
    val multiLine = collectLeafTokenTypes("a\n{\nb\n}\nc", brace)
    val singleLine = collectLeafTokenTypes("a { b } c", brace)
    assertThat(multiLine).isEqualTo(singleLine)
    assertThat(multiLine)
      .containsExactly(
        PnfLineAwareDyckParser.OTHER, // a
        PnfLineAwareDyckParser.OPEN_BRACE,
        PnfLineAwareDyckParser.OTHER, // b
        PnfLineAwareDyckParser.CLOSE_BRACE,
        PnfLineAwareDyckParser.OTHER, // c
      ).inOrder()
  }

  @Test
  fun parenthesesNestUnderTheBraceParenthesisFacade() {
    val leaves = collectLeafTokenTypes("f(x)\n{\ny\n}", braceParenthesis)
    assertThat(leaves)
      .containsExactly(
        PnfLineAwareDyckParser.OTHER, // f
        PnfLineAwareDyckParser.OPEN_PARENTHESIS,
        PnfLineAwareDyckParser.OTHER, // x
        PnfLineAwareDyckParser.CLOSE_PARENTHESIS,
        PnfLineAwareDyckParser.OPEN_BRACE,
        PnfLineAwareDyckParser.OTHER, // y
        PnfLineAwareDyckParser.CLOSE_BRACE,
      ).inOrder()
  }

  private fun collectLeafTokenTypes(
    source: String,
    facade: AbstractDyckParserFacade,
  ): List<Int> {
    val tree =
      SparTreeParserUtility.buildSparTree(
        sourceCode = source,
        parserFacade = facade,
        specifiedSparTreeNodeFactory = null,
        simplifyTree = true,
        canonicalTokenCountComputer = { null },
        errorMode = ParseErrorHandling.STRICT,
      )
    val tokenTypes = ArrayList<Int>()
    tree.realRoot.preOrderVisit { node ->
      if (node is LexerRuleSparTreeNode) {
        tokenTypes.add(node.token.tokenType.antlrTokenType)
      }
      node.immutableChildView
    }
    return tokenTypes
  }
}
