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
import org.perses.grammar.AbstractParserFacade
import org.perses.grammar.ParseErrorHandling
import org.perses.grammar.c.OptCLexer
import org.perses.spartree.LexerRuleSparTreeNode
import org.perses.spartree.SparTreeParserUtility

@RunWith(JUnit4::class)
class VariousDyckParserFacadeTest {
  val brace =
    BraceDyckParserFacade(
      underlyingLexerClass = OptCLexer::class.java,
    )

  val braceParenthesis =
    BraceParenthesisDyckParserFacade(
      underlyingLexerClass = OptCLexer::class.java,
    )

  val braceParenthesisBracket =
    BraceParenthesisBracketDyckParserFacade(
      underlyingLexerClass = OptCLexer::class.java,
    )

  @Test
  fun bracketFacadeNestsSquareBrackets() {
    val tokens = braceParenthesisBracket.tokenizeString("a[b]")
    assertThat(tokens.map { it.type })
      .containsExactly(
        PnfLineAwareDyckParser.OTHER, // a
        PnfLineAwareDyckParser.OPEN_BRACKET,
        PnfLineAwareDyckParser.OTHER, // b
        PnfLineAwareDyckParser.CLOSE_BRACKET,
      ).inOrder()
  }

  @Test
  fun braceParenthesisFacadeLeavesSquareBracketsAsOther() {
    // The brace+parenthesis facade does not enable brackets, so `[`/`]` stay OTHER.
    val tokens = braceParenthesis.tokenizeString("a[b]")
    assertThat(tokens.map { it.type })
      .containsExactly(
        PnfLineAwareDyckParser.OTHER, // a
        PnfLineAwareDyckParser.OTHER, // [
        PnfLineAwareDyckParser.OTHER, // b
        PnfLineAwareDyckParser.OTHER, // ]
      ).inOrder()
  }

  @Test
  fun testTokenizeWithBraceFacade() {
    val tokens = brace.tokenizeString("int f() {return 0;}")
    val tokenTypes = tokens.map { it.type }
    assertThat(tokenTypes)
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
  fun anUnlexableCharacterIsKeptAsAnOtherTokenInSourceOrder() {
    // A `\` line continuation the C lexer cannot tokenize must survive as an OTHER token (with the
    // line-break delimiter after it), or reconstruction drops it and a `st\<newline>atic` splice
    // breaks into two tokens the C preprocessor no longer rejoins into `static`.
    val tokens = brace.tokenizeString("st\\\natic")
    assertThat(tokens.map { it.text }).containsExactly("st", "\\", "\n", "atic").inOrder()
    assertThat(tokens.map { it.type })
      .containsExactly(
        PnfLineAwareDyckParser.OTHER,
        PnfLineAwareDyckParser.OTHER,
        PnfLineAwareDyckParser.FABRICATED_NEWLINE,
        PnfLineAwareDyckParser.OTHER,
      ).inOrder()
  }

  @Test
  fun testNewlineSynthesizedAtEveryLineBreakIncludingBraces() {
    val tokens = brace.tokenizeString("a b\nc\n{d}\ne")
    val tokenTypes = tokens.map { it.type }
    assertThat(tokenTypes)
      .containsExactly(
        PnfLineAwareDyckParser.OTHER, // a
        PnfLineAwareDyckParser.OTHER, // b
        PnfLineAwareDyckParser.FABRICATED_NEWLINE, // between b (line 1) and c (line 2)
        PnfLineAwareDyckParser.OTHER, // c
        PnfLineAwareDyckParser.FABRICATED_NEWLINE, // between c (line 2) and '{' (line 3)
        PnfLineAwareDyckParser.OPEN_BRACE,
        PnfLineAwareDyckParser.OTHER, // d
        PnfLineAwareDyckParser.CLOSE_BRACE,
        PnfLineAwareDyckParser.FABRICATED_NEWLINE, // between '}' (line 3) and e (line 4)
        PnfLineAwareDyckParser.OTHER, // e
      ).inOrder()
  }

  @Test
  fun testNewlineAfterOpenBraceMaterializesBareLine() {
    // The newline between '{' (line 1) and 'a' (line 2) has no node before it on
    // its line, so it is emitted and parses as a bare-FABRICATED_NEWLINE line.
    val tokens = brace.tokenizeString("{\na\n}")
    val tokenTypes = tokens.map { it.type }
    assertThat(tokenTypes)
      .containsExactly(
        PnfLineAwareDyckParser.OPEN_BRACE,
        PnfLineAwareDyckParser.FABRICATED_NEWLINE, // between '{' (line 1) and a (line 2)
        PnfLineAwareDyckParser.OTHER, // a
        PnfLineAwareDyckParser.FABRICATED_NEWLINE, // between a (line 2) and '}' (line 3)
        PnfLineAwareDyckParser.CLOSE_BRACE,
      ).inOrder()
  }

  @Test
  fun testBlankLineDoesNotProduceEmptyLine() {
    val tokens = brace.tokenizeString("a\n\n\nb")
    val tokenTypes = tokens.map { it.type }
    assertThat(tokenTypes)
      .containsExactly(
        PnfLineAwareDyckParser.OTHER, // a
        PnfLineAwareDyckParser.FABRICATED_NEWLINE, // a single delimiter despite two blank lines
        PnfLineAwareDyckParser.OTHER, // b
      ).inOrder()
  }

  @Test
  fun testFabricatedNewlineIsMarkedFabricated() {
    val tokens = brace.tokenizeString("a\nb")
    val newline = tokens.single { it.type == PnfLineAwareDyckParser.FABRICATED_NEWLINE }
    assertThat(AbstractParserFacade.isFabricatedToken(newline)).isTrue()
  }

  @Test
  fun testFabricatedNewlineIsAbsentFromSparTree() {
    val source = "a b\nc d\n{e}\nf g"
    // The token stream really does carry FABRICATED_NEWLINE, so the tree
    // assertion below is testing an actual drop rather than a vacuous case.
    assertThat(brace.tokenizeString(source).map { it.type })
      .contains(PnfLineAwareDyckParser.FABRICATED_NEWLINE)

    val tokenTypesInTree = collectLeafTokenTypes(source, brace)
    assertThat(tokenTypesInTree).doesNotContain(PnfLineAwareDyckParser.FABRICATED_NEWLINE)
    // The real content tokens still survive, so the drop is targeted.
    assertThat(tokenTypesInTree).contains(PnfLineAwareDyckParser.OTHER)
  }

  @Test
  fun testBlockBodyStartingOnNextLineParsesViaBareNewlineLine() {
    // The newline right after '{' has no node before it, so it exercises the
    // grammar's bare-FABRICATED_NEWLINE `line` alternative. Building the tree
    // proves the parse succeeds, and the newline is still dropped from the tree.
    val source = "x\n{\ny\n}"
    assertThat(brace.tokenizeString(source).map { it.type })
      .containsAtLeast(PnfLineAwareDyckParser.OPEN_BRACE, PnfLineAwareDyckParser.FABRICATED_NEWLINE)
      .inOrder()

    val tokenTypesInTree = collectLeafTokenTypes(source, brace)
    assertThat(tokenTypesInTree).doesNotContain(PnfLineAwareDyckParser.FABRICATED_NEWLINE)
    assertThat(tokenTypesInTree)
      .containsExactly(
        PnfLineAwareDyckParser.OTHER, // x
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

  @Test
  fun deeplyNestedInputParsesViaLargeStackRetry() {
    // A deeply nested input overflows the recursive-descent parse on the default thread stack;
    // parseString retries it on a large stack (see Util.callWithLargeStackOnStackOverflow), so the
    // parse completes instead of throwing StackOverflowError. 10000 levels is well past the ~3000-deep
    // SMT-LIB inputs that motivated the retry, and past any default stack, so this exercises the retry.
    val depth = 10000
    val source = "(".repeat(depth) + "x" + ")".repeat(depth)
    val result = braceParenthesisBracket.parseString(source, errorMode = ParseErrorHandling.STRICT)
    // Reaching here means no StackOverflowError escaped. A clean strict parse also leaves no syntax
    // errors and yields a non-empty tree. (childCount on the root is O(1); deep-traversing the tree,
    // e.g. via getText(), would itself recurse and overflow -- which is beside the point being tested.)
    assertThat(result.syntaxErrors).isEmpty()
    assertThat(result.tree.childCount).isGreaterThan(0)
  }

  @Test
  fun testTokenizeWithBraceParenthesisFacade() {
    val tokens = braceParenthesis.tokenizeString("int f() {return 0;}")
    val tokenTypes = tokens.map { it.type }
    assertThat(tokenTypes)
      .containsExactly(
        PnfLineAwareDyckParser.OTHER,
        PnfLineAwareDyckParser.OTHER,
        PnfLineAwareDyckParser.OPEN_PARENTHESIS,
        PnfLineAwareDyckParser.CLOSE_PARENTHESIS,
        PnfLineAwareDyckParser.OPEN_BRACE,
        PnfLineAwareDyckParser.OTHER,
        PnfLineAwareDyckParser.OTHER,
        PnfLineAwareDyckParser.OTHER,
        PnfLineAwareDyckParser.CLOSE_BRACE,
      ).inOrder()
  }
}
