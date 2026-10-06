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

import com.google.common.collect.ImmutableList
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

  private fun element(vararg ranges: RecordedRange) = RecordedElement(ImmutableList.copyOf(ranges))

  private fun range(
    sourceCode: String,
    substring: String,
    tokenCount: Int = 1,
  ): RecordedRange {
    val span = spanOf(sourceCode, substring)
    return RecordedRange(span.leftInclusive, span.rightExclusive, tokenCount)
  }

  private fun cutTexts(
    sourceCode: String,
    vararg elements: RecordedElement,
  ): List<String> =
    texts(
      RecordedProgramTokenizer
        .buildRecordedRangeTree(sourceCode, elements.toList())
        .remainingLexerRuleNodes,
    )

  // ---- buildRecordedRangeTree: the text cut at the ranges, no lexer ----

  @Test
  fun testTheTextIsCutAtTheRangesAndTheGapsAreLeavesToo() {
    val sourceCode = "int x = 1;\n"

    assertThat(
      cutTexts(sourceCode, element(range(sourceCode, "x")), element(range(sourceCode, "1"))),
    ).containsExactly("int ", "x", " = ", "1", ";\n")
      .inOrder()
  }

  @Test
  fun testTheLeavesReassembleTheTextAndEveryRangeResolves() {
    val sourceCode = "<a>foo<b/>bar</a>"
    val elements =
      listOf(
        element(range(sourceCode, "foo")),
        element(range(sourceCode, "<b/>")),
        element(range(sourceCode, "bar")),
      )
    val tree = RecordedProgramTokenizer.buildRecordedRangeTree(sourceCode, elements)

    assertThat(texts(tree.remainingLexerRuleNodes).joinToString("")).isEqualTo(sourceCode)
    val resolved =
      RecordedProgramTokenizer.resolveElements(
        tree,
        elements.map { element -> element.ranges.map { it.toInterval() } },
      )
    assertThat(resolved.map { texts(it) })
      .containsExactly(listOf("foo"), listOf("<b/>"), listOf("bar"))
      .inOrder()
  }

  /** A range of n tokens is n leaves, so the element's leaf count is its recorded weight. */
  @Test
  fun testARangeIsCutIntoAsManyLeavesAsItsTokenCount() {
    val sourceCode = "int x = 1;"
    val declaration = range(sourceCode, "int x =", tokenCount = 3)
    val tree =
      RecordedProgramTokenizer.buildRecordedRangeTree(
        sourceCode,
        listOf(element(declaration)),
      )

    val leaves = tree.resolveOne(declaration.toInterval())
    assertThat(leaves).hasSize(3)
    assertThat(texts(leaves).joinToString("")).isEqualTo("int x =")
    assertThat(leaves.sumOf { it.leafTokenCount }).isEqualTo(3)
  }

  @Test
  fun testAMultiRangeElementWeighsTheSumOfItsRanges() {
    val sourceCode = "a b c d e"
    val tree =
      RecordedProgramTokenizer.buildRecordedRangeTree(
        sourceCode,
        listOf(
          element(range(sourceCode, "a b", tokenCount = 2), range(sourceCode, "e", tokenCount = 1)),
        ),
      )

    val leaves = tree.resolveOne(Interval(0, 3), Interval(8, 9))
    assertThat(leaves.sumOf { it.leafTokenCount }).isEqualTo(3)
    assertThat(
      texts(tree.remainingLexerRuleNodes),
    ).containsExactly("a", " b", " c d ", "e").inOrder()
  }

  @Test
  fun testTouchingRangesAndRangesAtTheTextEndsNeedNoGaps() {
    assertThat(cutTexts("ab", element(RecordedRange(0, 1, 1)), element(RecordedRange(1, 2, 1))))
      .containsExactly("a", "b")
      .inOrder()
  }

  @Test
  fun testOffsetsAreCodePointsSoANonBmpCharacterBeforeARangeDoesNotShiftIt() {
    // The emoji is two UTF-16 units but one code point; the recorded offsets count code points.
    val sourceCode = "/* \uD83D\uDE00 */ x"
    val x =
      RecordedRange(
        sourceCode.codePointCount(0, sourceCode.indexOf("x")),
        sourceCode.codePointCount(0, sourceCode.length),
        tokenCount = 1,
      )
    val tree = RecordedProgramTokenizer.buildRecordedRangeTree(sourceCode, listOf(element(x)))

    assertThat(texts(tree.resolveOne(x.toInterval()))).containsExactly("x")
    assertThat(texts(tree.remainingLexerRuleNodes).joinToString("")).isEqualTo(sourceCode)
  }

  @Test
  fun testLeavesCarryLineAndColumn() {
    val sourceCode = "a\nbc\n d"
    val d = range(sourceCode, "d")
    val tree = RecordedProgramTokenizer.buildRecordedRangeTree(sourceCode, listOf(element(d)))

    val leaf =
      tree
        .resolveOne(d.toInterval())
        .single()
        .token
        .asAntlrToken()
    assertThat(leaf.position.line).isEqualTo(3)
    assertThat(leaf.position.charPositionInLine).isEqualTo(1)
  }

  @Test
  fun testARangeOutsideTheTextIsRejected() {
    val failure =
      assertThrows(IllegalArgumentException::class.java) {
        RecordedProgramTokenizer.buildRecordedRangeTree(
          "abc",
          listOf(element(RecordedRange(2, 9, 1))),
        )
      }
    assertThat(failure).hasMessageThat().contains("outside the text")
  }

  @Test
  fun testOverlappingRangesAreRejected() {
    val sourceCode = "f(g(1), 2)"
    val failure =
      assertThrows(IllegalArgumentException::class.java) {
        RecordedProgramTokenizer.buildRecordedRangeTree(
          sourceCode,
          listOf(element(range(sourceCode, "g(1), 2")), element(range(sourceCode, "1"))),
        )
      }
    assertThat(failure).hasMessageThat().contains("overlap")
  }

  /** The whole point of the text path: a deleted element leaves the text minus exactly its span. */
  @Test
  fun testDeletingAnElementAndPrintingVerbatimSplicesItsSpanOut() {
    val sourceCode = "<a>foo<b/>bar</a>"
    val b = range(sourceCode, "<b/>")
    val tree = RecordedProgramTokenizer.buildRecordedRangeTree(sourceCode, listOf(element(b)))
    val builder = NodeDeletionActionSet.Builder("delete b")
    tree.resolveOne(b.toInterval()).forEach { builder.deleteNode(it) }
    tree.applyEdit(tree.createNodeDeletionEdit(builder.build()), canonicalTokenCount = null)

    val printed =
      PrinterRegistry.getPrinter(EnumFormatControl.VERBATIM).print(tree.programSnapshot.payload)
    assertThat(printed.sourceCode).isEqualTo("<a>foobar</a>")
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
