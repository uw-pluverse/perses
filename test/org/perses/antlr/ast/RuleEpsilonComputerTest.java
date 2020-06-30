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
package org.perses.antlr.ast;

import com.google.common.collect.ImmutableSet;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.antlr.GrammarTestingUtility;

import java.util.List;
import java.util.stream.Collectors;

import static com.google.common.truth.Truth.assertThat;

@RunWith(JUnit4.class)
public class RuleEpsilonComputerTest {

  @Test
  public void test_simple() {
    List<String> ruleNames = getEpsilonableRuleNames("a : D | ;");
    assertThat(ruleNames).containsExactly("a");

    ruleNames = getEpsilonableRuleNames("a : D;");
    assertThat(ruleNames).isEmpty();
  }

  @Test
  public void test_star() {
    List<String> ruleNames = getEpsilonableRuleNames("a : D*;");
    assertThat(ruleNames).containsExactly("a");
  }

  @Test
  public void test_optional() {
    List<String> ruleNames = getEpsilonableRuleNames("a : D?;");
    assertThat(ruleNames).containsExactly("a");
  }

  @Test
  public void test_plus() {
    List<String> ruleNames = getEpsilonableRuleNames("a : D+;");
    assertThat(ruleNames).isEmpty();
  }

  @Test
  public void test_ruleref() {
    assertThat(getEpsilonableRuleNames("a: b;", "b:;")).containsExactly("a", "b");
  }

  @Test
  public void test_cyclic_ruleref() {
    assertThat(getEpsilonableRuleNames("a:b;", "b:a;")).isEmpty();
  }

  @Test
  public void test_sequence() {
    assertThat(getEpsilonableRuleNames("a: b c ;", "b : A* ;", "c: A? ;"))
        .containsExactly("a", "b", "c");
    assertThat(getEpsilonableRuleNames("a: b c ;", "b : A* ;", "c: A+ ;")).containsExactly("b");
  }

  @Test
  public void test_plus_with_quantified_epsilon() {
    assertThat(getEpsilonableRuleNames("a : b +;", "b : ;")).containsExactly("a", "b");
  }

  @Test
  public void test_alt() {
    assertThat(getEpsilonableRuleNames("a : D | E;")).isEmpty();
    assertThat(getEpsilonableRuleNames("a : b | E ;", "b : C | ;")).containsExactly("a", "b");
  }

  private List<String> getEpsilonableRuleNames(String... lines) {
    PersesGrammar grammar = GrammarTestingUtility.createPersesGrammarFromString(lines);
    ImmutableSet<AbstractPersesRuleDefAst> rules =
        RuleEpsilonComputer.computeEpsilonableRules(grammar.getRules()).getEpsilonableRules();
    List<String> ruleNames =
        rules.stream()
            .map(AbstractPersesRuleDefAst::getRuleNameHandle)
            .map(RuleNameRegistry.RuleNameHandle::get)
            .collect(Collectors.toList());
    return ruleNames;
  }
}
