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
package org.perses.listminimizer.microbenchmark

import com.google.common.truth.Truth.assertThat
import org.junit.Assert.assertThrows
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.program.EnumFormatControl
import org.perses.program.printer.PrinterRegistry
import org.perses.spartree.LexerRuleSparTreeNode
import org.perses.spartree.NodeDeletionActionSet
import org.perses.spartree.SparTree
import org.perses.util.Interval

@RunWith(JUnit4::class)
class RecordedProgramTokenizerTest {
  private fun texts(nodes: List<LexerRuleSparTreeNode>) = nodes.map { it.token.lexemeText }

  /** The spans of every whitespace-separated word of [sourceCode], as a printer's tokens are. */
  private fun wordSpans(sourceCode: String): List<Interval> =
    Regex("\\S+").findAll(sourceCode).map { Interval(it.range.first, it.range.last + 1) }.toList()

  private fun tree(
    sourceCode: String,
    tokenOffsets: List<Interval> = wordSpans(sourceCode),
  ) = RecordedProgramTokenizer.buildRecordedRangeTree(sourceCode, tokenOffsets)

  private fun printAtRecordedPositions(tree: SparTree) =
    PrinterRegistry
      .getPrinter(EnumFormatControl.ORIG_FORMAT)
      .print(tree.programSnapshot.payload)
      .sourceCode

  // ---- buildRecordedRangeTree: the text re-tokenized at the recorded offsets, no lexer ----

  @Test
  fun testEachRecordedTokenIsOneLeafWithExactlyItsText() {
    val sourceCode = "int x = 1 ;\n"

    assertThat(texts(tree(sourceCode).remainingLexerRuleNodes))
      .containsExactly("int", "x", "=", "1", ";")
      .inOrder()
  }

  /** Tokens need not be whitespace-separated: the offsets, not the text, say where one ends. */
  @Test
  fun testAdjacentTokensAreSplitWhereTheOffsetsSay() {
    val sourceCode = "<a>foo<b/>bar</a>"
    val leaves =
      tree(
        sourceCode,
        listOf(Interval(0, 3), Interval(3, 6), Interval(6, 10), Interval(10, 13), Interval(13, 17)),
      ).remainingLexerRuleNodes

    assertThat(texts(leaves)).containsExactly("<a>", "foo", "<b/>", "bar", "</a>").inOrder()
  }

  /**
   * What the evaluation relies on: a recorded file is printer output, so placing every token at
   * its recorded line and column prints the rebuilt tree back to the file.
   */
  @Test
  fun testPrintingTheRebuiltTreeAtItsPositionsReproducesTheText() {
    val sourceCode =
      """
      |int main(void) {
      |  int x = 1;
      |
      |    return x;
      |}
      |
      """.trimMargin()

    assertThat(printAtRecordedPositions(tree(sourceCode))).isEqualTo(sourceCode)
  }

  @Test
  fun testOffsetsAreCodePointsSoANonBmpCharacterBeforeATokenDoesNotShiftIt() {
    // The emoji is two UTF-16 units but one code point; the recorded offsets count code points.
    val sourceCode = "\uD83D\uDE00 x"

    assertThat(
      texts(tree(sourceCode, listOf(Interval(0, 1), Interval(2, 3))).remainingLexerRuleNodes),
    ).containsExactly("\uD83D\uDE00", "x")
      .inOrder()
  }

  @Test
  fun testLeavesCarryLineAndColumn() {
    val leaf =
      tree("a\nbc\n d")
        .remainingLexerRuleNodes
        .last()
        .token
        .asAntlrToken()

    assertThat(leaf.position.line).isEqualTo(3)
    assertThat(leaf.position.charPositionInLine).isEqualTo(1)
  }

  @Test
  fun testATokenOutsideTheTextIsRejected() {
    assertThrows(IllegalArgumentException::class.java) { tree("abc", listOf(Interval(2, 4))) }
  }

  @Test
  fun testOverlappingTokensAreRejected() {
    assertThrows(IllegalArgumentException::class.java) {
      tree("abcd", listOf(Interval(0, 2), Interval(1, 3)))
    }
  }

  @Test
  fun testTextOutsideTheTokensMustBeSpacesAndNewlines() {
    val failure = assertThrows(Exception::class.java) { tree("ab cd", listOf(Interval(0, 2))) }

    assertThat(
      failure,
    ).hasMessageThat().contains("Only spaces and newlines may separate recorded tokens")
  }

  /** A deleted token leaves its place blank and every other token where it was, as in a reduction. */
  @Test
  fun testDeletingATokenLeavesTheOthersInPlace() {
    val tree =
      tree(
        "int x = 1;\nint y;\n",
        listOf(
          Interval(0, 3),
          Interval(4, 5),
          Interval(6, 7),
          Interval(8, 9),
          Interval(9, 10),
          Interval(11, 14),
          Interval(15, 16),
          Interval(16, 17),
        ),
      )
    val builder = NodeDeletionActionSet.Builder("delete x")
    builder.deleteNode(tree.remainingLexerRuleNodes[1])
    tree.applyEdit(tree.createNodeDeletionEdit(builder.build()), canonicalTokenCount = null)

    assertThat(printAtRecordedPositions(tree)).isEqualTo("int   = 1;\nint y;\n")
  }
}
