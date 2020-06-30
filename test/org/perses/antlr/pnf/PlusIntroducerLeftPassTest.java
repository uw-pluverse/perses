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

import com.google.common.collect.ImmutableList;
import com.google.common.collect.Iterables;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.antlr.GrammarTestingUtility;
import org.perses.antlr.ast.*;
import org.perses.antlr.pnf.PlusIntroducerLeftPass.PlusIntroducerEdit;

import java.util.Optional;
import java.util.Set;

import static com.google.common.truth.Truth.assertThat;
import static org.perses.antlr.GrammarTestingUtility.createSeqOfTerminals;
import static org.perses.antlr.GrammarTestingUtility.createTerminalList;

@RunWith(JUnit4.class)
public class PlusIntroducerLeftPassTest extends PnfLeftTestGrammar {

  @Test
  public void testProcess() {
    {
      PersesGrammar grammar =
          GrammarTestingUtility.createPersesGrammarFromString("start:C D a;", "a:(C D)*;");
      ImmutableRuleDefMap defMap = ImmutableRuleDefMap.create(grammar);
      PlusIntroducerLeftPass pass = new PlusIntroducerLeftPass();
      ImmutableRuleDefMap newMap = pass.process(defMap);
      assertThat(Iterables.getOnlyElement(newMap.getRuleDefinition("start")).getSourceCode())
          .isEqualTo("kleene_plus__a_1");
      assertThat(
              Iterables.getOnlyElement(newMap.getRuleDefinition("kleene_plus__a_1")).getSourceCode())
          .isEqualTo("(C D)+");
    }
    {
      PersesGrammar grammar =
          GrammarTestingUtility.createPersesGrammarFromString("start:a C D f;", "a:(C D)*;");
      ImmutableRuleDefMap defMap = ImmutableRuleDefMap.create(grammar);
      PlusIntroducerLeftPass pass = new PlusIntroducerLeftPass();
      ImmutableRuleDefMap newMap = pass.process(defMap);
      assertThat(Iterables.getOnlyElement(newMap.getRuleDefinition("start")).getSourceCode())
          .isEqualTo("kleene_plus__a_1 f");
      assertThat(
          Iterables.getOnlyElement(newMap.getRuleDefinition("kleene_plus__a_1")).getSourceCode())
          .isEqualTo("(C D)+");
    }
  }

  @Test
  public void testMatch() {
    PersesSequenceAst seq = createSeqOfTerminals("a", "b");
    ImmutableList<AbstractPersesRuleElement> toMatch = createTerminalList("a", "b");
    assertThat(PlusIntroducerEdit.match(seq, -1, toMatch)).isFalse();
    assertThat(PlusIntroducerEdit.match(seq, 0, toMatch)).isTrue();
    assertThat(PlusIntroducerEdit.match(seq, 1, toMatch)).isFalse();

    toMatch = createTerminalList("a");
    assertThat(PlusIntroducerEdit.match(seq, 0, toMatch)).isTrue();
    assertThat(PlusIntroducerEdit.match(seq, 1, toMatch)).isFalse();

    toMatch = createTerminalList("b");
    assertThat(PlusIntroducerEdit.match(seq, 0, toMatch)).isFalse();
    assertThat(PlusIntroducerEdit.match(seq, 1, toMatch)).isTrue();

    toMatch = createTerminalList("a", "b", "c");
    assertThat(PlusIntroducerEdit.match(seq, -1, toMatch)).isFalse();
    assertThat(PlusIntroducerEdit.match(seq, 0, toMatch)).isFalse();
    assertThat(PlusIntroducerEdit.match(seq, 1, toMatch)).isFalse();
    assertThat(PlusIntroducerEdit.match(seq, 2, toMatch)).isFalse();
  }

  @Test
  public void testReverseMatch() {
    PersesSequenceAst seq = createSeqOfTerminals("a", "b");
    ImmutableList<AbstractPersesRuleElement> toMatch = createTerminalList("a", "b");
    assertThat(PlusIntroducerEdit.reverseMatch(seq, -1, toMatch)).isFalse();
    assertThat(PlusIntroducerEdit.reverseMatch(seq, 0, toMatch)).isFalse();
    assertThat(PlusIntroducerEdit.reverseMatch(seq, 1, toMatch)).isTrue();

    toMatch = createTerminalList("a");
    assertThat(PlusIntroducerEdit.reverseMatch(seq, 0, toMatch)).isTrue();
    assertThat(PlusIntroducerEdit.reverseMatch(seq, 1, toMatch)).isFalse();

    toMatch = createTerminalList("b");
    assertThat(PlusIntroducerEdit.reverseMatch(seq, 0, toMatch)).isFalse();
    assertThat(PlusIntroducerEdit.reverseMatch(seq, 1, toMatch)).isTrue();

    toMatch = createTerminalList("a", "b", "c");
    assertThat(PlusIntroducerEdit.reverseMatch(seq, -1, toMatch)).isFalse();
    assertThat(PlusIntroducerEdit.reverseMatch(seq, 0, toMatch)).isFalse();
    assertThat(PlusIntroducerEdit.reverseMatch(seq, 1, toMatch)).isFalse();
    assertThat(PlusIntroducerEdit.reverseMatch(seq, 2, toMatch)).isFalse();
  }

  @Test
  public void testTransformStarToPlus_for_sequence() {
    for (String startRuleDef : ImmutableList.of("start : C D a f;", "start : a C D f;")) {
      final PersesGrammar grammar =
          GrammarTestingUtility.createPersesGrammarFromString(startRuleDef, "a: (C  D)*;");
      final RuleNameRegistry registry = grammar.getSymbolTable().getRuleNameRegistry();
      ImmutableRuleDefMap defMap = ImmutableRuleDefMap.create(grammar);
      PlusIntroducerEdit edit = new PlusIntroducerEdit(defMap);

      Optional<AbstractPersesRuleElement> start =
          edit.internalApply(defMap.getRuleDefinition("start").iterator().next(), true);
      assertThat(start.isPresent()).isTrue();
      assertThat(start.get().getSourceCode()).isEqualTo("kleene_plus__a_1 f");

      Set<AbstractPersesRuleElement> kleene_plus__a_1 =
          edit.toAdd.get(registry.getOrThrow("kleene_plus__a_1"));
      assertThat(kleene_plus__a_1).hasSize(1);
      assertThat(Iterables.getOnlyElement(kleene_plus__a_1).getSourceCode()).isEqualTo("(C D)+");
    }
  }

  @Test
  public void testTransformStarToPlus_for_terminals() {
    for (String startRuleDef : ImmutableList.of("start : D a f;", "start : a D f;")) {
      final PersesGrammar grammar =
          GrammarTestingUtility.createPersesGrammarFromString(startRuleDef, "a: D*;");
      final RuleNameRegistry registry = grammar.getSymbolTable().getRuleNameRegistry();
      ImmutableRuleDefMap defMap = ImmutableRuleDefMap.create(grammar);
      PlusIntroducerEdit edit = new PlusIntroducerEdit(defMap);

      Optional<AbstractPersesRuleElement> start =
          edit.internalApply(defMap.getRuleDefinition("start").iterator().next(), true);
      assertThat(start.isPresent()).isTrue();
      assertThat(start.get().getSourceCode()).isEqualTo("kleene_plus__a_1 f");

      Set<AbstractPersesRuleElement> kleene_plus__a_1 =
          edit.toAdd.get(registry.getOrThrow("kleene_plus__a_1"));
      assertThat(kleene_plus__a_1).hasSize(1);
      assertThat(Iterables.getOnlyElement(kleene_plus__a_1).getSourceCode()).isEqualTo("D+");
    }
  }

  @Test
  public void testGetStarIfIsKlleneStarRule() {
    final PersesGrammar grammar =
        GrammarTestingUtility.createPersesGrammarFromString(
            "r1 : a | b;", "r2 : a*;", "r3: a* b;", "r4: a+;");
    ImmutableRuleDefMap defMap = ImmutableRuleDefMap.create(grammar);
    PlusIntroducerEdit edit = new PlusIntroducerEdit(defMap);

    RuleNameRegistry ruleNameRegistry = grammar.getSymbolTable().getRuleNameRegistry();

    Optional<PersesStarAst> r1 = edit.getStarIfIsKleeneStarRule(ruleNameRegistry.getOrThrow("r1"));
    assertThat(r1.isPresent()).isFalse();

    Optional<PersesStarAst> r2 = edit.getStarIfIsKleeneStarRule(ruleNameRegistry.getOrThrow("r2"));
    assertThat(r2.isPresent()).isTrue();
    assertThat(r2.get()).isInstanceOf(PersesStarAst.class);
    assertThat(r2.get().getBody().getSourceCode()).isEqualTo("a");

    Optional<PersesStarAst> r3 = edit.getStarIfIsKleeneStarRule(ruleNameRegistry.getOrThrow("r3"));
    assertThat(r3.isPresent()).isFalse();

    Optional<PersesStarAst> r4 = edit.getStarIfIsKleeneStarRule(ruleNameRegistry.getOrThrow("r4"));
    assertThat(r4.isPresent()).isFalse();
  }

}
