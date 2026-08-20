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
