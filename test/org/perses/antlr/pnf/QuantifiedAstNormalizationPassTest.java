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
import com.google.common.collect.Streams;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.antlr.GrammarTestingUtility;
import org.perses.antlr.ast.*;

import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.stream.Collectors;
import java.util.stream.Stream;

import static com.google.common.truth.Truth.assertThat;

@RunWith(JUnit4.class)
public class QuantifiedAstNormalizationPassTest {

  private PersesGrammar starGrammar;
  private ImmutableRuleDefMap starDefMap;

  @Before
  public void setup() {
    starGrammar = GrammarTestingUtility.loadGrammarFromFile("star.g4");
    starDefMap = ImmutableRuleDefMap.create(starGrammar);
  }

  @Test
  public void testFactorQuantifiedEdit_starGrammar_ruleStar() {
    Map.Entry<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement> rule =
        find(starDefMap, "rule*");
    QuantifiedAstNormalizationPass.FactorQuantifiedEdit edit =
        new QuantifiedAstNormalizationPass.FactorQuantifiedEdit(rule.getKey());
    Optional<AbstractPersesRuleElement> edited =
        edit.internalApply(rule.getValue(), /*isRoot=*/ true);
    assertThat(edited.isPresent()).isTrue();
    assertThat(edited.get().getSourceCode()).isEqualTo("kleene_star__start_1");
    Map.Entry<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement> newRule =
        Iterables.getOnlyElement(edit.getNewRules());
    assertThat(newRule.getKey().get()).isEqualTo("kleene_star__start_1");
    assertThat(newRule.getValue().getSourceCode()).isEqualTo("rule*");
  }

  @Test
  public void testFactorQuantifiedEdit_starGrammar_FGAnotherStar() {
    Map.Entry<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement> rule =
        find(starDefMap, "('F' | 'G' | another)*");
    QuantifiedAstNormalizationPass.FactorQuantifiedEdit edit =
        new QuantifiedAstNormalizationPass.FactorQuantifiedEdit(rule.getKey());
    Optional<AbstractPersesRuleElement> edited = edit.apply(rule.getValue());
    assertThat(edited.isPresent()).isTrue();
    assertThat(edited.get().getSourceCode()).isEqualTo("kleene_star__start_2");

    Map.Entry<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement> kleene_star__start_2 =
        Iterables.getOnlyElement(
            Iterables.filter(
                edit.getNewRules(), entry -> entry.getKey().get().equals("kleene_star__start_2")));

    assertThat(kleene_star__start_2.getValue()).isInstanceOf(PersesStarAst.class);
    PersesStarAst start = (PersesStarAst) kleene_star__start_2.getValue();
    assertThat(start.getBody()).isInstanceOf(PersesRuleReferenceAst.class);
    assertThat(start.getSourceCode()).isEqualTo("start_1*");

    assertThat(
            getEntryStreamFromEdit(edit, "start_1")
                .map(Map.Entry::getValue)
                .map(AbstractPersesAst::getSourceCode)
                .collect(Collectors.toList()))
        .containsExactly("'F'", "'G'", "another");
  }

  private Map.Entry<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement> find(
      ImmutableRuleDefMap ruleDefMap, String sourceCode) {
    List<Map.Entry<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement>> candidates =
        ruleDefMap
            .entryStream()
            .filter(entry -> entry.getValue().getSourceCode().equals(sourceCode))
            .collect(Collectors.toList());
    assertThat(candidates).hasSize(1);
    return candidates.get(0);
  }

  @Test
  public void testFactorQuantifiedEdit_starGrammar_nested_quantified() {
    PersesGrammar persesGrammar = GrammarTestingUtility.loadGrammarFromFile("nested_quantified.g4");
    ImmutableRuleDefMap defMap = ImmutableRuleDefMap.create(persesGrammar);
    assertThat(defMap.getParserRuleNames()).hasSize(1);
    RuleNameRegistry.RuleNameHandle ruleName =
        Iterables.getOnlyElement(defMap.getParserRuleNames());
    final AbstractPersesRuleElement body =
        Iterables.getOnlyElement(defMap.getRuleDefinition(ruleName));
    QuantifiedAstNormalizationPass.FactorQuantifiedEdit edit =
        new QuantifiedAstNormalizationPass.FactorQuantifiedEdit(ruleName);

    Optional<AbstractPersesRuleElement> newBody = edit.apply(body);
    assertThat(newBody.isPresent()).isTrue();
    assertThat(newBody.get().getSourceCode()).isEqualTo("kleene_star__start_5 optional__start_6");

    Map.Entry<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement> kleene_star__start_5 =
        getEntryFromEdit(edit, "kleene_star__start_5");
    assertThat(kleene_star__start_5.getValue().getSourceCode()).isEqualTo("start_4*");

    Map.Entry<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement> start_4 =
        getEntryFromEdit(edit, "start_4");
    assertThat(start_4.getValue().getSourceCode())
        .isEqualTo("'A' kleene_plus__start_2 optional__start_3");

    Map.Entry<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement> kleene_plus__start_2 =
        getEntryFromEdit(edit, "kleene_plus__start_2");
    assertThat(kleene_plus__start_2.getValue().getSourceCode()).isEqualTo("start_1+");

    assertThat(
            getEntryStreamFromEdit(edit, "start_1")
                .map(Map.Entry::getValue)
                .map(AbstractPersesRuleElement::getSourceCode)
                .collect(Collectors.toList()))
        .containsExactly("'C'", "'D'");

    Map.Entry<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement> optional__start_3 =
        getEntryFromEdit(edit, "optional__start_3");
    assertThat(optional__start_3.getValue().getSourceCode()).isEqualTo("'B'?");
  }

  @Test
  public void testQuantifiedAstNormalizationPass_nested_quantified() {
    PersesGrammar persesGrammar = GrammarTestingUtility.loadGrammarFromFile("nested_quantified.g4");
    ImmutableRuleDefMap defMap = ImmutableRuleDefMap.create(persesGrammar);
    QuantifiedAstNormalizationPass pass = new QuantifiedAstNormalizationPass();
    ImmutableRuleDefMap firstRound = pass.process(defMap);
    PersesGrammar grammar = firstRound.getPersesGrammar();

    AbstractPersesRuleElement startRule = grammar.getRuleDefinition("start").get().getBody();
    assertThat(startRule.getSourceCode()).isEqualTo("kleene_star__start_5 optional__start_6");

    AbstractPersesRuleElement start_1_rule = grammar.getRuleDefinition("start_1").get().getBody();
    assertThat(start_1_rule.getChildCount()).isEqualTo(2);
    assertThat(start_1_rule.getChild(0).getSourceCode()).isEqualTo("'C'");
    assertThat(start_1_rule.getChild(1).getSourceCode()).isEqualTo("'D'");

    AbstractPersesRuleElement kleene_plus__start_2 =
        grammar.getRuleDefinition("kleene_plus__start_2").get().getBody();
    assertThat(kleene_plus__start_2.getSourceCode()).isEqualTo("start_1+");

    AbstractPersesRuleElement optional__start_3 =
        grammar.getRuleDefinition("optional__start_3").get().getBody();
    assertThat(optional__start_3.getSourceCode()).isEqualTo("'B'?");

    AbstractPersesRuleElement start_4 = grammar.getRuleDefinition("start_4").get().getBody();
    assertThat(start_4.getSourceCode()).isEqualTo("'A' kleene_plus__start_2 optional__start_3");

    AbstractPersesRuleElement kleene_star__start_5 =
        grammar.getRuleDefinition("kleene_star__start_5").get().getBody();
    assertThat(kleene_star__start_5.getSourceCode()).isEqualTo("start_4*");

    AbstractPersesRuleElement optional__start_6 =
        grammar.getRuleDefinition("optional__start_6").get().getBody();
    assertThat(optional__start_6.getSourceCode()).isEqualTo("'E'?");
  }

  @Test
  public void testQuantifiedAstNormalizationPass_idempotency_nested_quantified() {
    PersesGrammar persesGrammar = GrammarTestingUtility.loadGrammarFromFile("nested_quantified.g4");
    ImmutableRuleDefMap defMap = ImmutableRuleDefMap.create(persesGrammar);
    QuantifiedAstNormalizationPass pass = new QuantifiedAstNormalizationPass();
    ImmutableRuleDefMap firstRound = pass.process(defMap);
    ImmutableRuleDefMap secondRound = pass.process(firstRound);
    assertThat(firstRound.getParserRuleNames())
        .containsExactlyElementsIn(secondRound.getParserRuleNames());
    for (RuleNameRegistry.RuleNameHandle ruleName : firstRound.getParserRuleNames()) {
      assertThat(firstRound.getRuleDefinition(ruleName))
          .containsExactlyElementsIn(secondRound.getRuleDefinition(ruleName));
    }
  }

  private static Map.Entry<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement>
      getEntryFromEdit(QuantifiedAstNormalizationPass.FactorQuantifiedEdit edit, String ruleName) {
    return Iterables.getOnlyElement(
        Iterables.filter(edit.getNewRules(), entry -> entry.getKey().get().equals(ruleName)));
  }

  private static Stream<Map.Entry<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement>>
      getEntryStreamFromEdit(
          QuantifiedAstNormalizationPass.FactorQuantifiedEdit edit, String ruleName) {
    return Streams.stream(
        Iterables.filter(edit.getNewRules(), entry -> entry.getKey().get().equals(ruleName)));
  }

  @Test
  public void testNormalizingStar() {

    QuantifiedAstNormalizationPass pass = new QuantifiedAstNormalizationPass();
    ImmutableRuleDefMap newMap = pass.process(starDefMap);
    String sourceCode = newMap.getPersesGrammar().getSourceCode();
    System.out.println(sourceCode);
    new PnfCheckPass().process(newMap);
  }
}
