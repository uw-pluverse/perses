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
 */
package org.perses.grammar

import com.google.common.truth.Truth.assertThat
import org.antlr.v4.runtime.Token
import org.antlr.v4.runtime.tree.ErrorNode
import org.antlr.v4.runtime.tree.ParseTree
import org.antlr.v4.runtime.tree.TerminalNode
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.antlr.ParseTreeWithParser
import org.perses.grammar.c.CParserFacade

/**
 * Spike for error-tolerant parsing under the real grammar. It documents, as executable assertions,
 * exactly where the invariant "collecting all leaf tokens reconstructs the program" holds after a
 * tolerant parse, and the two places it still leaks:
 *
 *  - GAP-LEXER: a character matching no lexer rule (`@` in C) is dropped by the lexer before the
 *    parser ever sees it, so it is absent from both the token stream and the tree.
 *  - GAP-EOF: the C start rule is not anchored to EOF, so trailing input after the first complete
 *    top-level construct is silently ignored and never enters the tree.
 *
 * Parser-level recovery itself is clean: missing tokens become fabricated leaves (filtered by
 * [AbstractParserFacade.isFabricatedToken]); unexpected token runs become real error-node leaves
 * that carry their original text.
 */
@RunWith(JUnit4::class)
class TolerantParserFacadeTest {
  private val cFacade = CParserFacade()

  @Test
  fun testValidProgramParsesCleanly() {
    val result = cFacade.parseString("int main() { return 0; }", errorMode = ParseErrorHandling.TOLERANT)
    assertThat(result.hasError).isFalse()
    assertThat(treeRealTokenTexts(result)).isEqualTo(lexerTokenTexts(result))
  }

  @Test
  fun testMissingSemicolonInsertsFabricatedToken() {
    // `return 0` with no `;`: single-token insertion recovery invents a `;`.
    val result = observe("missing-semicolon", cFacade.parseString("int main() { return 0 }", errorMode = ParseErrorHandling.TOLERANT))
    assertThat(fabricatedTokenCount(result)).isEqualTo(1)
    // After dropping the fabricated token, the leaves are exactly the input tokens.
    assertThat(treeRealTokenTexts(result)).isEqualTo(lexerTokenTexts(result))
  }

  @Test
  fun testUnbalancedBraceRecoversCleanly() {
    val result =
      observe("unbalanced-brace", cFacade.parseString("int main() { if (x) { return 0; }", errorMode = ParseErrorHandling.TOLERANT))
    assertThat(treeRealTokenTexts(result)).isEqualTo(lexerTokenTexts(result))
  }

  @Test
  fun testDeeplyBrokenProgramRecoversCleanly() {
    val src =
      """
      |int f(int a, {
      |  int b = ;
      |  for (;;) return 0;
      |  return a +
      |}
      """.trimMargin()
    val result = observe("deep-broken", cFacade.parseString(src, errorMode = ParseErrorHandling.TOLERANT))
    // Unexpected token runs are preserved verbatim as error-node leaves.
    assertThat(errorNodeLeafCount(result)).isGreaterThan(0)
    assertThat(treeRealTokenTexts(result)).isEqualTo(lexerTokenTexts(result))
  }

  @Test
  fun testGapLexerClosedUnknownCharacterBecomesLeaf() {
    // `@` matches no C lexer rule; GAP-LEXER re-materializes it as an error-node leaf.
    val src = "int main() { @ ; return 0; }"
    val result = observe("GAP-LEXER", cFacade.parseString(src, errorMode = ParseErrorHandling.TOLERANT))
    assertThat(treeRealTokenTexts(result)).contains("@")
    assertLeavesCoverNonWhitespace(src, result)
  }

  @Test
  fun testGapEofClosedTrailingInputBecomesLeaves() {
    // Trailing `%%% zzz` after a complete function is appended as error-node leaves, not dropped.
    val src = "int main() { return 0; } %%% zzz"
    val result = observe("GAP-EOF", cFacade.parseString(src, errorMode = ParseErrorHandling.TOLERANT))
    assertThat(result.hasError).isTrue()
    assertThat(treeRealTokenTexts(result)).containsAtLeast("%", "zzz")
    assertLeavesCoverNonWhitespace(src, result)
  }

  @Test
  fun testOnlyDroppedCharactersHasNoAnchorTerminals() {
    // All-garbage input: the lexer drops everything, so there are no anchor tokens; the dropped
    // characters must still land in the tree (hung off the root) without crashing.
    val src = "@ @ @"
    val result = observe("only-garbage", cFacade.parseString(src, errorMode = ParseErrorHandling.TOLERANT))
    assertThat(treeRealTokenTexts(result).count { it == "@" }).isEqualTo(3)
    assertLeavesCoverNonWhitespace(src, result)
  }

  @Test
  fun testGapsClosedTogether() {
    // A stray char AND trailing garbage in one program: every non-whitespace char lands in a leaf.
    val src = "int main() { int x = @ ; } ??? tail"
    val result = observe("both-gaps", cFacade.parseString(src, errorMode = ParseErrorHandling.TOLERANT))
    assertLeavesCoverNonWhitespace(src, result)
  }

  /**
   * The invariant the two gap fixes buy us: every non-whitespace input character is covered by some
   * tree leaf's [Token] interval, so collecting the leaves reconstructs the program. (The inputs here
   * contain no comments, which a real lexer would also drop from the default channel.)
   */
  private fun assertLeavesCoverNonWhitespace(
    input: String,
    result: ParseTreeWithParser,
  ) {
    val covered = BooleanArray(input.length)
    for (terminal in collectTerminals(result.tree)) {
      val token = terminal.symbol
      if (token.type == Token.EOF || token.startIndex < 0 || token.stopIndex < token.startIndex) {
        continue
      }
      for (i in token.startIndex..token.stopIndex) {
        covered[i] = true
      }
    }
    val uncovered =
      input.indices.filter { !covered[it] && !input[it].isWhitespace() }.map { "'${input[it]}'@$it" }
    assertThat(uncovered).isEmpty()
  }

  private fun observe(
    label: String,
    result: ParseTreeWithParser,
  ): ParseTreeWithParser {
    val terminals = collectTerminals(result.tree)
    System.err.println(
      "[tolerant-spike] $label: syntaxErrors=${result.syntaxErrors.size} " +
        "terminals=${terminals.size} errorNodeLeaves=${errorNodeLeafCount(result)} " +
        "fabricatedTokens=${fabricatedTokenCount(result)}",
    )
    return result
  }

  private fun treeRealTokenTexts(result: ParseTreeWithParser): List<String> =
    collectTerminals(result.tree)
      .map { it.symbol }
      .filter { it.type != Token.EOF && !AbstractParserFacade.isFabricatedToken(it) }
      .map { it.text }

  private fun lexerTokenTexts(result: ParseTreeWithParser): List<String> =
    result.lazyAllTokens.map { it.text }

  private fun errorNodeLeafCount(result: ParseTreeWithParser): Int =
    collectTerminals(result.tree).count { it is ErrorNode }

  private fun fabricatedTokenCount(result: ParseTreeWithParser): Int =
    collectTerminals(result.tree)
      .count { it.symbol.type != Token.EOF && AbstractParserFacade.isFabricatedToken(it.symbol) }

  private fun collectTerminals(tree: ParseTree): List<TerminalNode> {
    val result = ArrayList<TerminalNode>()
    val stack = ArrayDeque<ParseTree>()
    stack.addLast(tree)
    while (stack.isNotEmpty()) {
      val current = stack.removeLast()
      if (current is TerminalNode) {
        result.add(current)
      } else {
        for (i in current.childCount - 1 downTo 0) {
          stack.addLast(current.getChild(i))
        }
      }
    }
    return result
  }
}
