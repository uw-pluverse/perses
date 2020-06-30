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

import org.perses.antlr.ast.*;
import com.google.common.collect.ImmutableSet;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.antlr.GrammarTestingUtility;

import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

import static com.google.common.truth.Truth.assertThat;

@RunWith(JUnit4.class)
public class RuleDefMapTest {

  @Test
  public void test_project() {
    PersesGrammar persesGrammar = GrammarTestingUtility.loadGrammarFromFile("pnf_test.g4");
    ImmutableRuleDefMap ruleDefMap = ImmutableRuleDefMap.create(persesGrammar);
    RuleNameRegistry.RuleNameHandle ruleNameA =
        persesGrammar.getSymbolTable().getRuleNameRegistry().getOrThrow("a");
    ImmutableRuleDefMap projected = ruleDefMap.project(ImmutableSet.of(ruleNameA));
    assertThat(projected.getParserRuleNames()).containsExactly(ruleNameA);
    assertThat(projected.getRuleDefinition(ruleNameA))
        .containsExactlyElementsIn(
            ((PersesAlternativeBlockAst) persesGrammar.getRuleDefinition(ruleNameA).get().getBody())
                .getAlternatives());
  }

  @Test
  public void test_toPersesGrammar_terminal() {
    test_toPersesGrammar("terminal.g4");
  }

  @Test
  public void test_toPersesGrammar_alternative() {
    test_toPersesGrammar("alternative.g4");
  }

  @Test
  public void test_toPersesGrammar_pnf_test() {
    test_toPersesGrammar("pnf_test.g4");
  }

  @Test
  public void test_toPersesGrammar_postfix_expression_in_c() {
    test_toPersesGrammar("postfix_expression_in_c.g4");
  }

  private static void test_toPersesGrammar(String antlrFileName) {
    PersesGrammar persesGrammar = GrammarTestingUtility.loadGrammarFromFile(antlrFileName);
    ImmutableRuleDefMap ruleDefMap = ImmutableRuleDefMap.create(persesGrammar);
    PersesGrammar grammarRoundback = ruleDefMap.getPersesGrammar();

    List<AbstractPersesRuleDefAst> originalDefs =
        persesGrammar.getRules().stream()
            .sorted(Comparator.comparing(AbstractPersesRuleDefAst::getRuleNameHandle))
            .collect(Collectors.toList());
    List<AbstractPersesRuleDefAst> afterDefs =
        grammarRoundback.getRules().stream()
            .sorted(Comparator.comparing(AbstractPersesRuleDefAst::getRuleNameHandle))
            .collect(Collectors.toList());

    assertThat(
            originalDefs.stream()
                .map(AbstractPersesRuleDefAst::getRuleNameHandle)
                .collect(Collectors.toList()))
        .containsExactlyElementsIn(
            afterDefs.stream()
                .map(AbstractPersesRuleDefAst::getRuleNameHandle)
                .collect(Collectors.toList()))
        .inOrder();

    for (int i = 0, size = originalDefs.size(); i < size; ++i) {
      AbstractPersesRuleElement orig = originalDefs.get(i).getBody();
      AbstractPersesRuleElement after = afterDefs.get(i).getBody();
      assertThat(orig.getClass()).isEqualTo(after.getClass());
      if (orig.getTag() == AstTag.ALTERNATIVE_BLOCK) {
        List<String> origAlternatives =
            ((PersesAlternativeBlockAst) orig)
                .getAlternatives().stream()
                    .map(AbstractPersesRuleElement::getSourceCode)
                    .sorted()
                    .collect(Collectors.toList());
        List<String> afterAlternatives =
            ((PersesAlternativeBlockAst) after)
                .getAlternatives().stream()
                    .map(AbstractPersesRuleElement::getSourceCode)
                    .sorted()
                    .collect(Collectors.toList());
        assertThat(origAlternatives).containsExactlyElementsIn(afterAlternatives);
      } else {
        assertThat(orig).isSameInstanceAs(after);
      }
    }
  }

  List<String> toSortedRuleNames(PersesGrammar persesGrammar) {
    return persesGrammar.getRules().stream()
        .map(AbstractPersesRuleDefAst::getRuleNameHandle)
        .map(RuleNameRegistry.RuleNameHandle::get)
        .sorted()
        .collect(Collectors.toList());
  }
}
