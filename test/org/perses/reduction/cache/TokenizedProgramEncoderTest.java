/*
 * Copyright (C) 2018-2022 University of Waterloo.
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
package org.perses.reduction.cache;

import static com.google.common.truth.Truth.assertThat;

import com.google.common.collect.ImmutableList;
import it.unimi.dsi.fastutil.ints.IntArrayList;
import java.io.IOException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;
import org.antlr.v4.runtime.Token;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.TestUtility;
import org.perses.grammar.c.LanguageC;
import org.perses.program.TokenizedProgram;
import org.perses.program.TokenizedProgramFactory;
import org.perses.program.printer.PrinterRegistry;
import org.perses.spartree.SparTree;

@RunWith(JUnit4.class)
public class TokenizedProgramEncoderTest {

  private TokenizedProgramFactory factory;
  private LinearScanTokenizedProgramEncoder encoder;
  private LinearScanTokenizedProgramEncoder encoder2;

  @Before
  public void setup() {
    ImmutableList<Token> tokens = TestUtility.createAntlrTokens("a", "b", "c", "d", "e");
    factory = TokenizedProgramFactory.createFactory(tokens, LanguageC.INSTANCE);
    encoder =
        new LinearScanTokenizedProgramEncoder(
            factory.create(tokens), AbstractQueryCacheProfiler.NULL_PROFILER, true);
    encoder2 =
        new LinearScanTokenizedProgramEncoder(
            factory.create(tokens), AbstractQueryCacheProfiler.NULL_PROFILER, true);
  }

  @Test
  public void test() {
    test(ImmutableList.of("a", "b", "c", "d", "e"), ImmutableList.of(0, 5));
    test(ImmutableList.of("a", "b", "c", "d"), ImmutableList.of(0, 4));
    test(ImmutableList.of("a", "b", "c"), ImmutableList.of(0, 3));
    test(ImmutableList.of("a", "b"), ImmutableList.of(0, 2));
    test(ImmutableList.of("a"), ImmutableList.of(0, 1));
    test(ImmutableList.of(), ImmutableList.of());

    test(ImmutableList.of("b", "c", "d", "e"), ImmutableList.of(1, 5));
    test(ImmutableList.of("c", "d", "e"), ImmutableList.of(2, 5));
    test(ImmutableList.of("d", "e"), ImmutableList.of(3, 5));
    test(ImmutableList.of("e"), ImmutableList.of(4, 5));

    test(ImmutableList.of("a", /*"b",*/ "c", "d", "e"), ImmutableList.of(0, 1, 2, 5));
    test(ImmutableList.of("a", /*"b",*/ "c", /*"d",*/ "e"), ImmutableList.of(0, 1, 2, 3, 4, 5));

    test(ImmutableList.of("a", "b", /*"c", "d",*/ "e"), ImmutableList.of(0, 2, 4, 5));
  }

  @Test
  public void test_getCompressedTokenIdSequence_delta_1() throws IOException {
    testTokenCompression("test_data/delta_1/t.c", 56, 2);
  }

  @Test
  public void test_getCompressedTokenIdSequence_clang_22704() throws IOException {
    testTokenCompression("test/org/perses/reduction/cache/clang-22704.c", 184444, 2);
  }

  private void testTokenCompression(String filepath, int originalTokenCount, int encodingSize)
      throws IOException {
    Path file = Paths.get(filepath);
    final SparTree sparTreeFromFile = TestUtility.createSparTreeFromFile(file);
    TokenizedProgram p = sparTreeFromFile.getProgramSnapshot();
    TokenizedProgramFactory factory = sparTreeFromFile.getTokenizedProgramFactory();
    LinearScanTokenizedProgramEncoder encoder =
        new LinearScanTokenizedProgramEncoder(p, AbstractQueryCacheProfiler.NULL_PROFILER, true);
    assertThat(p.getTokens()).hasSize(originalTokenCount);
    final CompactProgramEncoding encoding = encoder.encode(p);
    assert encoding != null;
    assertThat(encoding.getTokenCount()).isEqualTo(originalTokenCount);
    assertThat(encoding.encodingSize()).isEqualTo(encodingSize);
    {
      final CompactProgramEncoding other = encoder.encode(p);
      assertThat(encoding).isNotSameInstanceAs(other);
      assertThat(encoding).isEqualTo(other);
      assert other != null;
      assertThat(encoding.hashCode()).isEqualTo(other.hashCode());
    }
  }

  @Test
  public void test_getCompressedTokenIdSequence_hashcode_equal() throws IOException {
    CompactProgramEncoding p1 = encode("test_data/delta_1/t.c");
    CompactProgramEncoding p2 = encode("test/org/perses/reduction/cache/clang-22704.c");
    assertThat(p1.hashCode()).isNotEqualTo(p2.hashCode());
    assertThat(p1).isNotEqualTo(p2);
  }

  private static CompactProgramEncoding encode(String filepath) throws IOException {
    Path file = Paths.get(filepath);
    final SparTree sparTreeFromFile = TestUtility.createSparTreeFromFile(file);
    TokenizedProgram program = sparTreeFromFile.getProgramSnapshot();

    LinearScanTokenizedProgramEncoder encoder =
        new LinearScanTokenizedProgramEncoder(
            program, AbstractQueryCacheProfiler.NULL_PROFILER, true);
    return encoder.encode(program);
  }

  private void test(List<String> lexemes, List<Integer> expectedIntervals) {
    TokenizedProgram p = createProgram(lexemes.toArray(new String[0]));
    final List<Integer> intervals = getIntervalsInOrigin(p);
    assertThat(intervals).containsExactlyElementsIn(expectedIntervals);

    final TokenizedProgram restored = restore(intervals);
    assertThat(lexemes).containsExactlyElementsIn(toLexemes(restored));

    {
      CompactProgramEncoding encoding = encoder.encode(p);
      assert encoding != null;
      CompactProgramEncoding encoding2 = encoder2.reEncode(encoding);
      assertThat(encoding).isEqualTo(encoding2);
    }
  }

  private TokenizedProgram createProgram(String... lexemes) {
    return factory.create(TestUtility.createAntlrTokens(lexemes));
  }

  private IntArrayList getIntervalsInOrigin(TokenizedProgram p) {
    return encoder.encodeUncompressed(
        new LinearScanTokenizedProgramEncoder.IteratorCursor<>(p.getTokens().iterator()),
        p.tokenCount());
  }

  private TokenizedProgram restore(List<Integer> intervals) {

    TokenizedProgram program1 =
        CompactProgramEncoding.createCompressedEncoding(
                new TokenizedProgram(factory.getTokensInOrigin(), factory),
                new IntArrayList(intervals),
                Integer.MIN_VALUE)
            .restoreProgram();
    TokenizedProgram program2 =
        CompactProgramEncoding.createIntervalEncoding(
                new TokenizedProgram(factory.getTokensInOrigin(), factory),
                new IntArrayList(intervals),
                Integer.MIN_VALUE)
            .restoreProgram();
    assertThat(PrinterRegistry.INSTANCE.printToStringInSingleLineFormat(program1))
        .isEqualTo(PrinterRegistry.INSTANCE.printToStringInSingleLineFormat(program2));
    return program1;
  }

  private ImmutableList<String> toLexemes(TokenizedProgram p) {
    return p.getTokens().stream().map(Token::getText).collect(ImmutableList.toImmutableList());
  }
}
