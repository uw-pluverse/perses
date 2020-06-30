/*
 * Copyright (C) 2018-2020 University of Waterloo.
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
package org.perses.antlr.pnf;

import com.google.common.collect.Iterables;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.antlr.GrammarTestingUtility;
import org.perses.antlr.ast.AbstractPersesRuleElement;
import org.perses.antlr.ast.PersesGrammar;
import org.perses.antlr.ast.PersesSequenceAst;

import java.util.Optional;

import static com.google.common.truth.Truth.assertThat;

@RunWith(JUnit4.class)
public class OptionalIntroducerPassTest {

  private OptionalIntroducerPass pass;

  @Before
  public void setup() {
    pass = new OptionalIntroducerPass();
  }

  @Test
  public void testOptionalIntroducerParss_c_enumerator() {
    ImmutableRuleDefMap newMap =
        processGrammar("enumerator: typedefName | typedefName '=' constantExpression ;");
    AbstractPersesRuleElement def =
        Iterables.getOnlyElement(newMap.getRuleDefinition("enumerator"));
    assertThat(def.getSourceCode()).isEqualTo("typedefName optional__enumerator_2");
    assertThat(
            Iterables.getOnlyElement(newMap.getRuleDefinition("optional__enumerator_2"))
                .getSourceCode())
        .isEqualTo("enumerator_1?");
    assertThat(Iterables.getOnlyElement(newMap.getRuleDefinition("enumerator_1")).getSourceCode())
        .isEqualTo("'=' constantExpression");
  }

  @Test
  public void testOptionalIntroducerPass_simple_optional() {
    ImmutableRuleDefMap newMap = processGrammar("s: a b c | a c ;");
    AbstractPersesRuleElement s = Iterables.getOnlyElement(newMap.getRuleDefinition("s"));
    assertThat(s.getSourceCode()).isEqualTo("a optional__s_1 c");
    AbstractPersesRuleElement optional__s_1 =
        Iterables.getOnlyElement(newMap.getRuleDefinition("optional__s_1"));
    assertThat(optional__s_1.getSourceCode()).isEqualTo("b?");
    assertThat(newMap.getParserRuleNames()).hasSize(2);
  }

  @Test
  public void testOptionalIntroducerPass_optional_star() {
    ImmutableRuleDefMap newMap = processGrammar("s: a b* c | a c ;");
    AbstractPersesRuleElement s = Iterables.getOnlyElement(newMap.getRuleDefinition("s"));
    assertThat(s.getSourceCode()).isEqualTo("a b* c");
    assertThat(newMap.getParserRuleNames()).hasSize(1);
  }

  @Test
  public void testOptionalIntroducerPass_optional_plus() {
    ImmutableRuleDefMap newMap = processGrammar("s: a b+ c | a c ;");
    AbstractPersesRuleElement s = Iterables.getOnlyElement(newMap.getRuleDefinition("s"));
    assertThat(s.getSourceCode()).isEqualTo("a kleene_star__s_1 c");
    AbstractPersesRuleElement kleene_star__s_1 =
        Iterables.getOnlyElement(newMap.getRuleDefinition("kleene_star__s_1"));
    assertThat(kleene_star__s_1.getSourceCode()).isEqualTo("b*");
    assertThat(newMap.getParserRuleNames()).hasSize(2);
  }

  @Test
  public void testOptionalIntroducerPass_optional_optional() {
    ImmutableRuleDefMap newMap = processGrammar("s: a b? c | a c ;");
    AbstractPersesRuleElement s = Iterables.getOnlyElement(newMap.getRuleDefinition("s"));
    assertThat(s.getSourceCode()).isEqualTo("a b? c");
    assertThat(newMap.getParserRuleNames()).hasSize(1);
  }

  ImmutableRuleDefMap processGrammar(String... lines) {
    PersesGrammar grammar = GrammarTestingUtility.createPersesGrammarFromString(lines);
    ImmutableRuleDefMap defMap = ImmutableRuleDefMap.create(grammar);
    return pass.process(defMap);
  }

  @Test
  public void testFindGapInLongSequence_gap_in_the_front() {
    String[] longSeq = new String[] {"a", "b", "c", "b", "c", "b", "c"};
    String[] shortSeq = new String[] {"b", "c"};
    Optional<Interval> gapInLongSequence = findGapInSequences(longSeq, shortSeq);
    assertThat(gapInLongSequence.isPresent()).isTrue();
    assertThat(gapInLongSequence.get().leftInclusive).isEqualTo(0);
    assertThat(gapInLongSequence.get().rightExclusive).isEqualTo(5);
  }

  @Test
  public void testFindGapInLongSequence_gap_in_the_back() {
    String[] longSeq = new String[] {"a", "b", "c", "a", "b"};
    String[] shortSeq = new String[] {"a", "b"};
    Optional<Interval> gapInLongSequence = findGapInSequences(longSeq, shortSeq);
    assertThat(gapInLongSequence.isPresent()).isTrue();
    assertThat(gapInLongSequence.get().leftInclusive).isEqualTo(2);
    assertThat(gapInLongSequence.get().rightExclusive).isEqualTo(5);
  }

  @Test
  public void testFindGapInLongSequence_gap_in_the_middle() {
    String[] longSeq = new String[] {"a", "b", "a", "c", "a", "c"};
    String[] shortSeq = new String[] {"a", "c"};
    Optional<Interval> gapInLongSequence = findGapInSequences(longSeq, shortSeq);
    assertThat(gapInLongSequence.isPresent()).isTrue();
    assertThat(gapInLongSequence.get().leftInclusive).isEqualTo(1);
    assertThat(gapInLongSequence.get().rightExclusive).isEqualTo(5);
  }

  @Test
  public void testFindGapInLongSequence_multiple_gaps_in_the_front() {
    String[] longSeq = new String[] {"a", "b", "c", "d"};
    String[] shortSeq = new String[] {"b", "d"};
    Optional<Interval> gapInLongSequence = findGapInSequences(longSeq, shortSeq);
    assertThat(gapInLongSequence.isPresent()).isFalse();
  }

  @Test
  public void testFindGapInLongSequence_multiple_gaps_in_the_middle() {
    String[] longSeq = new String[] {"a", "b", "c", "d", "e"};
    String[] shortSeq = new String[] {"a", "c", "e"};
    Optional<Interval> gapInLongSequence = findGapInSequences(longSeq, shortSeq);
    assertThat(gapInLongSequence.isPresent()).isFalse();
  }

  @Test
  public void testFindGapInLongSequence_multiple_gaps_in_the_back() {
    Optional<Interval> gapInLongSequence =
        findGapInSequences(new String[] {"a", "b", "c", "d", "e"}, new String[] {"a", "c", "d"});
    assertThat(gapInLongSequence.isPresent()).isFalse();
  }

  @Test
  public void testFindGapBetweenSeqAndTerminal_front() {
    Optional<Interval> gapInLongSequence =
        findGapBetweenSequenceAndTerminal(new String[] {"a", "b"}, "a");
    assertThat(gapInLongSequence.isPresent()).isTrue();
    assertThat(gapInLongSequence.get().leftInclusive).isEqualTo(1);
    assertThat(gapInLongSequence.get().rightExclusive).isEqualTo(2);
  }

  @Test
  public void testFindGapBetweenSeqAndTerminal_back() {
    Optional<Interval> gapInLongSequence =
        findGapBetweenSequenceAndTerminal(new String[] {"a", "b"}, "b");
    assertThat(gapInLongSequence.isPresent()).isTrue();
    assertThat(gapInLongSequence.get().leftInclusive).isEqualTo(0);
    assertThat(gapInLongSequence.get().rightExclusive).isEqualTo(1);
  }

  @Test
  public void testFindGapBetweenSeqAndTerminal_none() {
    Optional<Interval> gapInLongSequence =
        findGapBetweenSequenceAndTerminal(new String[] {"a", "b"}, "c");
    assertThat(gapInLongSequence.isPresent()).isFalse();
  }

  private static Optional<Interval> findGapBetweenSequenceAndTerminal(
      String[] longSeqOfTerminals, String terminal) {
    OptionalIntroducerPass.CandidateElement<PersesSequenceAst> longSeq =
        OptionalIntroducerPass.Candidate.toCandidateElement(
                GrammarTestingUtility.createSeqOfTerminals(longSeqOfTerminals))
            .asSequence();
    OptionalIntroducerPass.CandidateElement<AbstractPersesRuleElement> shortSeq =
        OptionalIntroducerPass.Candidate.toCandidateElement(
            GrammarTestingUtility.createTerminal(terminal));
    return OptionalIntroducerPass.findGapInLongSequence(longSeq, shortSeq);
  }

  private static Optional<Interval> findGapInSequences(
      String[] longSeqOfTerminals, String[] shortSeqOfTerminals) {
    OptionalIntroducerPass.CandidateElement<PersesSequenceAst> longSeq =
        OptionalIntroducerPass.Candidate.toCandidateElement(
                GrammarTestingUtility.createSeqOfTerminals(longSeqOfTerminals))
            .asSequence();
    OptionalIntroducerPass.CandidateElement<AbstractPersesRuleElement> shortSeq =
        OptionalIntroducerPass.Candidate.toCandidateElement(
            GrammarTestingUtility.createSeqOfTerminals(shortSeqOfTerminals));
    return OptionalIntroducerPass.findGapInLongSequence(longSeq, shortSeq);
  }
}
