package org.perses.reduction;

import com.google.common.collect.ImmutableList;
import com.google.common.primitives.Ints;
import org.antlr.v4.runtime.CommonToken;
import org.antlr.v4.runtime.Token;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.TestUtility;
import org.perses.program.PersesToken;
import org.perses.program.TokenizedProgram;
import org.perses.program.TokenizedProgramFactory;
import org.perses.tree.spar.SparTree;

import java.io.File;
import java.io.IOException;
import java.util.List;
import java.util.stream.Collectors;

import static com.google.common.truth.Truth.assertThat;

@RunWith(JUnit4.class)
public class TokenizedProgramEncoderTest {

  private TokenizedProgramFactory factory;
  private TokenizedProgramEncoder encoder;

  @Before
  public void setup() {
    ImmutableList<Token> tokens = createAntlrTokens(ImmutableList.of("a", "b", "c", "d", "e"));
    factory = TokenizedProgramFactory.createFactory(tokens);
    encoder =
        new TokenizedProgramEncoder(
            factory.getTokensInOrigin(), AbstractTestScriptExecutionCacheProfiler.NULL_PROFILER);
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
    testTokenCompression("test/org/perses/reduction/clang-22704.c", 184444, 2);
  }

  private void testTokenCompression(String filepath, int originalTokenCount, int encodingSize)
      throws IOException {
    File file = new File(filepath);
    final SparTree sparTreeFromFile = TestUtility.createSparTreeFromFile(file);
    TokenizedProgram p = sparTreeFromFile.getProgramSnapshot();
    TokenizedProgramFactory factory = sparTreeFromFile.getTokenizedProgramFactory();
    TokenizedProgramEncoder encoder =
        new TokenizedProgramEncoder(
            factory.getTokensInOrigin(), AbstractTestScriptExecutionCacheProfiler.NULL_PROFILER);
    assertThat(p.getTokens()).hasSize(originalTokenCount);
    final TokenizedProgramEncoder.CompactProgramEncoding encoding = encoder.encode(p).get();
    assertThat(encoding.getTokenCount()).isEqualTo(originalTokenCount);
    assertThat(encoding.encodingSize()).isEqualTo(encodingSize);
    {
      final TokenizedProgramEncoder.CompactProgramEncoding other = encoder.encode(p).get();
      assertThat(encoding).isSameInstanceAs(other);
      assertThat(encoding.hashCode()).isEqualTo(other.hashCode());
    }
    final TokenizedProgram decoded = encoder.decode(encoding);
    assertThat(
            decoded.getTokens().stream()
                .map(PersesToken::getPersesLexemeId)
                .collect(Collectors.toList()))
        .containsExactlyElementsIn(
            p.getTokens().stream()
                .map(PersesToken::getPersesLexemeId)
                .collect(ImmutableList.toImmutableList()));
  }

  @Test
  public void test_getCompressedTokenIdSequence_hashcode_equal() throws IOException {
    TokenizedProgramEncoder.CompactProgramEncoding p1 = encode("test_data/delta_1/t.c");
    TokenizedProgramEncoder.CompactProgramEncoding p2 =
        encode("test/org/perses/reduction/clang-22704.c");
    assertThat(p1.hashCode()).isNotEqualTo(p2.hashCode());
    assertThat(p1).isNotEqualTo(p2);
  }

  private static TokenizedProgramEncoder.CompactProgramEncoding encode(String filepath)
      throws IOException {
    File file = new File(filepath);
    final SparTree sparTreeFromFile = TestUtility.createSparTreeFromFile(file);
    TokenizedProgram program = sparTreeFromFile.getProgramSnapshot();

    TokenizedProgramEncoder encoder =
        new TokenizedProgramEncoder(
            sparTreeFromFile.getTokenizedProgramFactory().getTokensInOrigin(),
            AbstractTestScriptExecutionCacheProfiler.NULL_PROFILER);
    return encoder.encode(program).get();
  }

  private void test(List<String> lexemes, List<Integer> expectedIntervals) {
    TokenizedProgram p = createProgram(lexemes);
    final List<Integer> intervals = getIntervalsInOrigin(p);
    assertThat(intervals).containsExactlyElementsIn(expectedIntervals);

    final TokenizedProgram restored = restore(intervals);
    assertThat(lexemes).containsExactlyElementsIn(toLexemes(restored));
  }

  private ImmutableList<Token> createAntlrTokens(List<String> lexemes) {
    return lexemes.stream()
        .map(l -> new CommonToken(/*type=*/ 0, l))
        .collect(ImmutableList.toImmutableList());
  }

  private TokenizedProgram createProgram(List<String> lexemes) {
    return factory.create(createAntlrTokens(lexemes));
  }

  private List<Integer> getIntervalsInOrigin(TokenizedProgram p) {
    return Ints.asList(encoder.encodeUncompressed(p).get());
  }

  private TokenizedProgram restore(List<Integer> intervals) {
    return encoder.restoreProgram(Ints.toArray(intervals), Integer.MIN_VALUE);
  }

  private ImmutableList<String> toLexemes(TokenizedProgram p) {
    return p.getTokens().stream().map(Token::getText).collect(ImmutableList.toImmutableList());
  }
}
