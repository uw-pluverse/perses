/*
 * Copyright (C) 2018-2024 University of Waterloo.
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
package org.perses.reduction.cache

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import it.unimi.dsi.fastutil.ints.IntArrayList
import org.antlr.v4.runtime.Token
import org.junit.Before
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.grammar.c.LanguageC
import org.perses.program.TokenizedProgram
import org.perses.program.TokenizedProgramFactory
import org.perses.program.printer.PrinterRegistry
import org.perses.spartree.SparTree
import org.perses.util.toImmutableList
import java.nio.file.Path
import java.nio.file.Paths

@RunWith(JUnit4::class)
class TokenizedProgramEncoderTest {
  private var factory: TokenizedProgramFactory? = null
  private var encoder: LinearScanTokenizedProgramEncoder? = null
  private var encoder2: LinearScanTokenizedProgramEncoder? = null

  @Before
  fun setup() {
    val tokens: ImmutableList<Token> = TestUtility.createAntlrTokens("a", "b", "c", "d", "e")
    factory = TokenizedProgramFactory.createFactory(tokens, LanguageC)
    encoder = LinearScanTokenizedProgramEncoder(
      factory!!.create(tokens), AbstractQueryCacheProfiler.NULL_PROFILER, true,
    )
    encoder2 = LinearScanTokenizedProgramEncoder(
      factory!!.create(tokens), AbstractQueryCacheProfiler.NULL_PROFILER, true,
    )
  }

  @Test
  fun test() {
    test(ImmutableList.of("a", "b", "c", "d", "e"), ImmutableList.of(0, 5))
    test(ImmutableList.of("a", "b", "c", "d"), ImmutableList.of(0, 4))
    test(ImmutableList.of("a", "b", "c"), ImmutableList.of(0, 3))
    test(ImmutableList.of("a", "b"), ImmutableList.of(0, 2))
    test(ImmutableList.of("a"), ImmutableList.of(0, 1))
    test(ImmutableList.of(), ImmutableList.of())
    test(ImmutableList.of("b", "c", "d", "e"), ImmutableList.of(1, 5))
    test(ImmutableList.of("c", "d", "e"), ImmutableList.of(2, 5))
    test(ImmutableList.of("d", "e"), ImmutableList.of(3, 5))
    test(ImmutableList.of("e"), ImmutableList.of(4, 5))
    test(ImmutableList.of("a", "c", "d", "e"), ImmutableList.of(0, 1, 2, 5))
    test(ImmutableList.of("a", "c", "e"), ImmutableList.of(0, 1, 2, 3, 4, 5))
    test(ImmutableList.of("a", "b", "e"), ImmutableList.of(0, 2, 4, 5))
  }

  @Test
  fun test_getCompressedTokenIdSequence_delta_1() {
    testTokenCompression("test_data/delta_1/t.c", 56, 2)
  }

  @Test
  fun test_getCompressedTokenIdSequence_clang_22704() {
    testTokenCompression("test/org/perses/reduction/cache/clang-22704.c", 184444, 2)
  }

  private fun testTokenCompression(filepath: String, originalTokenCount: Int, encodingSize: Int) {
    val file: Path = Paths.get(filepath)
    val sparTreeFromFile: SparTree = TestUtility.createSparTreeFromFile(file)
    val p: TokenizedProgram = sparTreeFromFile.programSnapshot
    val encoder =
      LinearScanTokenizedProgramEncoder(p, AbstractQueryCacheProfiler.NULL_PROFILER, true)
    assertThat(p.tokens).hasSize(originalTokenCount)
    val encoding = encoder.encode(p)!!
    assertThat(encoding.tokenCount).isEqualTo(originalTokenCount)
    assertThat(encoding.encodingSize()).isEqualTo(encodingSize)
    run {
      val other = encoder.encode(p)
      assertThat(encoding).isNotSameInstanceAs(other)
      assertThat(encoding).isEqualTo(other)
      assert(other != null)
      assertThat(encoding.hashCode()).isEqualTo(other.hashCode())
    }
  }

  @Test
  fun test_getCompressedTokenIdSequence_hashcode_equal() {
    val p1 = encode("test_data/delta_1/t.c")
    val p2 = encode("test/org/perses/reduction/cache/clang-22704.c")
    assertThat(p1.hashCode()).isNotEqualTo(p2.hashCode())
    assertThat(p1).isNotEqualTo(p2)
  }

  private fun test(lexemes: ImmutableList<String>, expectedIntervals: ImmutableList<Int>) {
    val p: TokenizedProgram = createProgram(*lexemes.toTypedArray<String>())
    val intervals: IntArrayList? = getIntervalsInOrigin(p)
    assertThat(intervals).containsExactlyElementsIn(expectedIntervals)
    val restored: TokenizedProgram = restore(intervals)
    assertThat(lexemes).containsExactlyElementsIn(toLexemes(restored))
    run {
      val encoding = encoder!!.encode(p)!!
      val encoding2 = encoder2!!.reEncode(encoding)
      assertThat(encoding).isEqualTo(encoding2)
    }
  }

  private fun createProgram(vararg lexemes: String): TokenizedProgram {
    return factory!!.create(TestUtility.createAntlrTokens(*lexemes))
  }

  private fun getIntervalsInOrigin(p: TokenizedProgram): IntArrayList? {
    return encoder!!.encodeUncompressed(p.tokens.iterator(), p.tokenCount())
  }

  private fun restore(intervals: IntArrayList?): TokenizedProgram {
    val program1: TokenizedProgram = CompactProgramEncoding.createCompressedEncoding(
      TokenizedProgram(factory!!.tokensInOrigin, factory!!),
      IntArrayList(intervals),
      Int.MIN_VALUE,
    ).restoreProgram()
    val program2: TokenizedProgram = CompactProgramEncoding.createIntervalEncoding(
      TokenizedProgram(factory!!.tokensInOrigin, factory!!),
      IntArrayList(intervals),
      Int.MIN_VALUE,
    ).restoreProgram()
    assertThat(PrinterRegistry.printToStringInSingleLineFormat(program1))
      .isEqualTo(PrinterRegistry.printToStringInSingleLineFormat(program2))
    return program1
  }

  private fun toLexemes(p: TokenizedProgram): ImmutableList<String> {
    return p.tokens.asSequence().map { it.getText() }.toImmutableList()
  }

  companion object {
    private fun encode(filepath: String): CompactProgramEncoding? {
      val file: Path = Paths.get(filepath)
      val sparTreeFromFile: SparTree = TestUtility.createSparTreeFromFile(file)
      val program: TokenizedProgram = sparTreeFromFile.programSnapshot
      val encoder = LinearScanTokenizedProgramEncoder(
        program,
        AbstractQueryCacheProfiler.NULL_PROFILER,
        true,
      )
      return encoder.encode(program)
    }
  }
}
