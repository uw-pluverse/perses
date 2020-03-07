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
