package org.perses.antlr.pnf;

import com.google.common.collect.ImmutableList;
import com.google.common.collect.ImmutableSet;
import com.google.common.collect.Iterables;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.antlr.GrammarTestingUtility;
import org.perses.antlr.ast.AbstractPersesAst;
import org.perses.antlr.ast.AbstractPersesRuleElement;
import org.perses.antlr.ast.PersesGrammar;
import org.perses.antlr.ast.PersesSequenceAst;
import org.perses.antlr.pnf.AlternativeBlockOutliningPass.Candidate;

import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;

import static com.google.common.truth.Truth.assertThat;
import static org.perses.antlr.GrammarTestingUtility.createSeqOfTerminals;
import static org.perses.antlr.pnf.AlternativeBlockOutliningPass.searchForCandidate;

@RunWith(JUnit4.class)
public class AlternativeBlockOutliningPassTest {

  private AlternativeBlockOutliningPass pass;

  @Before
  public void setup() {
    pass = new AlternativeBlockOutliningPass();
  }

  @Test
  public void testAlternativeBlockOutliningPass() {
    ImmutableRuleDefMap processed = process("a: a c d | a b d;");
    ImmutableList<AbstractPersesRuleElement> a = processed.getRuleDefinition("a");
    assertThat(a).hasSize(1);
    assertThat(Iterables.getOnlyElement(a).getSourceCode()).isEqualTo("a alternative__a_1 d");

    ImmutableList<AbstractPersesRuleElement> alternative__a_1 =
        processed.getRuleDefinition("alternative__a_1");
    assertThat(alternative__a_1).hasSize(2);
    assertThat(
            alternative__a_1.stream()
                .map(AbstractPersesAst::getSourceCode)
                .collect(Collectors.toList()))
        .containsExactly("b", "c");
    assertThat(processed.getPersesGrammar().getRules()).hasSize(2);
  }

  private ImmutableRuleDefMap process(String... grammarLines) {
    PersesGrammar grammar = GrammarTestingUtility.createPersesGrammarFromString(grammarLines);
    ImmutableRuleDefMap defMap = ImmutableRuleDefMap.create(grammar);
    ImmutableRuleDefMap processed = pass.process(defMap);
    return processed;
  }

  @Test
  public void testsearchAssumingCommonPrefix_equal_length() {
    Optional<Candidate> r = search("ab", "ac");
    assertThat(r.isPresent()).isTrue();
    Candidate c = r.get();
    assertThat(c.s1.getSourceCode()).isEqualTo("a b");
    assertThat(c.s2.getSourceCode()).isEqualTo("a c");
    assertThat(c.gapInS1.leftInclusive).isEqualTo(1);
    assertThat(c.gapInS1.rightExclusive).isEqualTo(2);
    assertThat(c.gapInS2.leftInclusive).isEqualTo(1);
    assertThat(c.gapInS2.rightExclusive).isEqualTo(2);

    assertThat(gapStrings(c)).containsExactly("b", "c");
  }

  @Test
  public void testsearchAssumingCommonPrefix_false() {
    assertThat(search("ab", "cd").isPresent()).isFalse();
    assertThat(search("cd", "ab").isPresent()).isFalse();
  }

  @Test
  public void testsearchAssumingCommonPrefix_different_lengths() {
    Optional<Candidate> r = search("abcd", "ae");
    assertThat(r.isPresent()).isTrue();
    Candidate c = r.get();
    assertThat(c.s1.getSourceCode()).isEqualTo("a b c d");
    assertThat(c.s2.getSourceCode()).isEqualTo("a e");
    assertThat(c.gapInS1.leftInclusive).isEqualTo(1);
    assertThat(c.gapInS1.rightExclusive).isEqualTo(4);
    assertThat(c.gapInS2.leftInclusive).isEqualTo(1);
    assertThat(c.gapInS2.rightExclusive).isEqualTo(2);

    assertThat(gapStrings(c)).containsExactly("b c d", "e");
  }

  @Test
  public void testsearchAssumingCommonPostfix_different_length() {
    Optional<Candidate> r = search("abcd", "gd");
    assertThat(r.isPresent()).isTrue();
    Candidate c = r.get();
    assertThat(c.s1.getSourceCode()).isEqualTo("a b c d");
    assertThat(c.s2.getSourceCode()).isEqualTo("g d");
    assertThat(c.gapInS1.leftInclusive).isEqualTo(0);
    assertThat(c.gapInS1.rightExclusive).isEqualTo(3);
    assertThat(c.gapInS2.leftInclusive).isEqualTo(0);
    assertThat(c.gapInS2.rightExclusive).isEqualTo(1);

    assertThat(gapStrings(c)).containsExactly("a b c", "g");
  }

  @Test
  public void testsearchAssumingCommonPostfix_equal_length() {
    Optional<Candidate> r = search("cd", "gd");
    assertThat(r.isPresent()).isTrue();
    Candidate c = r.get();
    assertThat(c.s1.getSourceCode()).isEqualTo("c d");
    assertThat(c.s2.getSourceCode()).isEqualTo("g d");
    assertThat(c.gapInS1.leftInclusive).isEqualTo(0);
    assertThat(c.gapInS1.rightExclusive).isEqualTo(1);
    assertThat(c.gapInS2.leftInclusive).isEqualTo(0);
    assertThat(c.gapInS2.rightExclusive).isEqualTo(1);

    assertThat(gapStrings(c)).containsExactly("c", "g");
  }

  @Test
  public void testSearchAssumingCommonPrefixAndPostfix_equal_length() {
    Optional<Candidate> r = search("abd", "acd");
    assertThat(r.isPresent()).isTrue();
    Candidate c = r.get();
    assertThat(c.s1.getSourceCode()).isEqualTo("a b d");
    assertThat(c.s2.getSourceCode()).isEqualTo("a c d");
    assertThat(c.gapInS1.leftInclusive).isEqualTo(1);
    assertThat(c.gapInS1.rightExclusive).isEqualTo(2);
    assertThat(c.gapInS2.leftInclusive).isEqualTo(1);
    assertThat(c.gapInS2.rightExclusive).isEqualTo(2);

    assertThat(gapStrings(c)).containsExactly("b", "c");
  }

  @Test
  public void testSearchAssumingCommonPrefixAndPostfix_different_length() {
    Optional<Candidate> r = search("abed", "acd");
    assertThat(r.isPresent()).isTrue();
    Candidate c = r.get();
    assertThat(c.s1.getSourceCode()).isEqualTo("a b e d");
    assertThat(c.s2.getSourceCode()).isEqualTo("a c d");
    assertThat(c.gapInS1.leftInclusive).isEqualTo(1);
    assertThat(c.gapInS1.rightExclusive).isEqualTo(3);
    assertThat(c.gapInS2.leftInclusive).isEqualTo(1);
    assertThat(c.gapInS2.rightExclusive).isEqualTo(2);

    assertThat(gapStrings(c)).containsExactly("b e", "c");
  }

  private static Optional<Candidate> search(String s1, String s2) {
    PersesSequenceAst seq1 = createSeqOfTerminals(split(s1));
    PersesSequenceAst seq2 = createSeqOfTerminals(split(s2));
    return searchForCandidate(seq1, seq2);
  }

  private static List<String> gapStrings(Candidate c) {
    return c.extractedGaps.stream()
        .map(AbstractPersesAst::getSourceCode)
        .collect(Collectors.toList());
  }

  private static ImmutableList<String> split(String s1) {
    ImmutableList.Builder<String> builder = ImmutableList.builder();
    for (char c : s1.toCharArray()) {
      builder.add(String.valueOf(c));
    }
    return builder.build();
  }
}
