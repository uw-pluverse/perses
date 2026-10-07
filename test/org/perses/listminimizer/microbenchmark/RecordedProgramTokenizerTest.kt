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
import org.perses.TestUtility
import org.perses.grammar.c.PnfCLexer
import org.perses.listminimizer.microbenchmark.RecordedProgramTokenizer.exclusiveEndOffsetOf
import org.perses.listminimizer.microbenchmark.RecordedProgramTokenizer.inclusiveStartOffsetOf
import org.perses.program.EnumFormatControl
import org.perses.program.printer.PrinterRegistry
import org.perses.spartree.LexerRuleSparTreeNode
import org.perses.spartree.NodeDeletionActionSet
import org.perses.spartree.SparTree
import org.perses.util.Interval
import kotlin.io.path.readText

@RunWith(JUnit4::class)
class RecordedProgramTokenizerTest {
  private fun tokenize(sourceCode: String) =
    RecordedProgramTokenizer.buildFlatTokenListTree(sourceCode, PnfCLexer::class.java)

  private fun texts(nodes: List<LexerRuleSparTreeNode>) = nodes.map { it.token.lexemeText }

  private fun SparTree.resolveOne(vararg ranges: Interval) =
    RecordedProgramTokenizer.resolveElements(this, listOf(ranges.toList())).single()

  private fun spanOf(
    sourceCode: String,
    substring: String,
  ): Interval {
    val start = sourceCode.indexOf(substring)
    check(start >= 0) { "'$substring' is not in the source" }
    return Interval(start, start + substring.length)
  }

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
  fun testTheRoundTripHoldsOverRealCProgramsPrintedByPerses() {
    val files = TestUtility.gccTestFiles.take(REAL_PROGRAM_SAMPLE_SIZE)
    assertThat(files).isNotEmpty()

    files.forEach { file ->
      val recorded = printTokensOf(file.readText())
      assertThat(
        printAtRecordedPositions(tree(recorded, spansOfTokens(recorded))),
      ).isEqualTo(recorded)
    }
  }

  /** The spans of [sourceCode]'s C tokens, as a recording would hold them. */
  private fun spansOfTokens(sourceCode: String) =
    tokenize(sourceCode).remainingLexerRuleNodes.map {
      Interval(inclusiveStartOffsetOf(it), exclusiveEndOffsetOf(it))
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

  // ---- buildFlatTokenListTree: the lexer-based path the existing corpora still use ----

  @Test
  fun testOneTokenNodePerRealToken() {
    val tokenization = tokenize("int x = 1;")

    assertThat(texts(tokenization.remainingLexerRuleNodes))
      .containsExactly("int", "x", "=", "1", ";")
      .inOrder()
    assertThat(tokenization.remainingLexerRuleNodes).hasSize(5)
  }

  /**
   * The lexing fixpoint the whole evaluation side rests on: a recorded program, re-parsed and
   * printed back, must reproduce the file byte for byte. If this fails for a language, its problems
   * cannot be evaluated -- candidates would differ from what the recording described.
   */
  @Test
  fun testPrintingTheReparsedProgramReproducesTheSource() {
    val sourceCode =
      """
      |int main(void) {
      |  int x = 1;
      |  return x;
      |}
      |
      """.trimMargin()

    assertThat(printTokensOf(sourceCode)).isEqualTo(sourceCode)
  }

  @Test
  fun testTokenOffsetsIndexTheSourceDirectly() {
    val sourceCode = "int x = 1;"

    assertOffsetsIndexTheSource(sourceCode)
  }

  @Test
  fun testRangeResolvesToTheTokensItCovers() {
    val sourceCode = "int x = 1; int y = 2;"
    val tokenization = tokenize(sourceCode)

    assertThat(texts(tokenization.resolveOne(spanOf(sourceCode, "int x = 1;"))))
      .containsExactly("int", "x", "=", "1", ";")
      .inOrder()
    assertThat(texts(tokenization.resolveOne(spanOf(sourceCode, "y"))))
      .containsExactly("y")
  }

  /** An element may own several non-contiguous ranges; the result is their union, in source order. */
  @Test
  fun testSeveralRangesResolveToTheUnionInSourceOrder() {
    val sourceCode = "int x = 1; int y = 2;"
    val tokenization = tokenize(sourceCode)

    val resolved =
      // Deliberately given out of order, to show ordering comes from the source.
      tokenization.resolveOne(spanOf(sourceCode, "y = 2;"), spanOf(sourceCode, "x"))

    assertThat(texts(resolved)).containsExactly("x", "y", "=", "2", ";").inOrder()
  }

  /** Overlapping elements are recorded on purpose, so a shared token must be yielded once. */
  @Test
  fun testOverlappingRangesYieldEachTokenOnce() {
    val sourceCode = "int x = 1;"
    val tokenization = tokenize(sourceCode)

    val resolved =
      tokenization.resolveOne(spanOf(sourceCode, "int x"), spanOf(sourceCode, "x = 1"))

    assertThat(texts(resolved)).containsExactly("int", "x", "=", "1").inOrder()
  }

  @Test
  fun testRangeStartingMidTokenIsRejected() {
    val sourceCode = "int x = 1;"
    val tokenization = tokenize(sourceCode)

    val failure =
      runCatching {
        tokenization.resolveOne(Interval(1, 3))
      }.exceptionOrNull()

    assertThat(failure).isInstanceOf(IllegalArgumentException::class.java)
    assertThat(failure).hasMessageThat().contains("does not begin at a token boundary")
  }

  @Test
  fun testRangeEndingInWhitespaceIsRejected() {
    val sourceCode = "int x = 1;"
    val tokenization = tokenize(sourceCode)

    // "int " -- starts on a token boundary but runs one character past the token's end.
    val failure =
      runCatching {
        tokenization.resolveOne(Interval(0, 4))
      }.exceptionOrNull()

    assertThat(failure).isInstanceOf(IllegalArgumentException::class.java)
    assertThat(failure).hasMessageThat().contains("does not end at a token boundary")
  }

  /**
   * Characters the real C lexer cannot tokenize survive as their own tokens, so their ranges resolve
   * like any other. Losing them would silently rejoin `st\<newline>atic` into something the
   * preprocessor treats differently.
   */
  @Test
  fun testUnlexableBackslashSpliceIsAddressableLikeAnyOtherToken() {
    // A `\`-newline line splice, written out so the splice is visible rather than encoded.
    val sourceCode =
      """
      |st\
      |atic
      """.trimMargin()
    val tokenization = tokenize(sourceCode)

    assertThat(texts(tokenization.remainingLexerRuleNodes))
      .containsExactly("st", "\\", "atic")
      .inOrder()
    assertThat(texts(tokenization.resolveOne(Interval(2, 3))))
      .containsExactly("\\")
  }

  /**
   * The fixpoint over real-world C, not just a toy. A recorded base source is itself the printed
   * form of a token list, so the property that matters is idempotence after one normalizing pass:
   * printing a raw source file drops what the lexer does not emit on the default channel (comments,
   * for one), and it is that normalized text a recording actually contains.
   *
   * Bounded to a sample: the assumption is about the printer and lexer, not about any particular
   * file, and the whole GCC suite would dominate this target's runtime.
   */
  @Test
  fun testFixpointHoldsOverRealCPrograms() {
    val files = TestUtility.gccTestFiles.take(REAL_PROGRAM_SAMPLE_SIZE)
    assertThat(files).isNotEmpty()

    files.forEach { file ->
      val normalized = printTokensOf(file.readText())

      assertThat(printTokensOf(normalized)).isEqualTo(normalized)
      assertOffsetsIndexTheSource(normalized)
    }
  }

  private fun printTokensOf(sourceCode: String) =
    PrinterRegistry.printToString(
      tokenize(sourceCode).programSnapshot.payload,
      EnumFormatControl.ORIG_FORMAT,
    )

  private fun assertOffsetsIndexTheSource(sourceCode: String) {
    tokenize(sourceCode).remainingLexerRuleNodes.forEach { node ->
      assertThat(
        sourceCode.substring(inclusiveStartOffsetOf(node), exclusiveEndOffsetOf(node)),
      ).isEqualTo(node.token.lexemeText)
    }
  }

  /** A program that does not parse under the real C grammar still tokenizes here. */
  @Test
  fun testSyntacticallyBrokenProgramStillTokenizes() {
    val tokenization = tokenize("int f( { ; ) } unbalanced")

    assertThat(tokenization.remainingLexerRuleNodes).isNotEmpty()
    assertThat(texts(tokenization.remainingLexerRuleNodes)).contains("unbalanced")
  }

  /** Elements are resolved together, so their order in the result must follow the input order. */
  @Test
  fun testElementsAreResolvedInTheOrderGiven() {
    val sourceCode = "int x = 1; int y = 2;"
    val tokenization = tokenize(sourceCode)

    val resolved =
      RecordedProgramTokenizer.resolveElements(
        tokenization,
        listOf(
          listOf(spanOf(sourceCode, "y")),
          listOf(spanOf(sourceCode, "x")),
        ),
      )

    assertThat(resolved).hasSize(2)
    assertThat(texts(resolved[0])).containsExactly("y")
    assertThat(texts(resolved[1])).containsExactly("x")
  }

  @Test
  fun testEmptyRangeIsRejected() {
    val tokenization = tokenize("int x = 1;")

    assertThat(
      runCatching { tokenization.resolveOne(Interval(3, 3)) }.exceptionOrNull(),
    ).isInstanceOf(IllegalArgumentException::class.java)
  }

  private companion object {
    const val REAL_PROGRAM_SAMPLE_SIZE = 25
  }
}
