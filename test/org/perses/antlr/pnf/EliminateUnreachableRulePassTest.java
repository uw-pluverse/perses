package org.perses.antlr.pnf;

import com.google.common.truth.Truth;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.antlr.GrammarTestingUtility;
import org.perses.antlr.ast.PersesGrammar;
import org.perses.antlr.ast.RuleNameRegistry;

import java.util.stream.Collectors;

@RunWith(JUnit4.class)
public class EliminateUnreachableRulePassTest {

  @Test
  public void test() {
    PersesGrammar grammar =
        GrammarTestingUtility.createPersesGrammarFromString("start:a;", "a:ID;", "b:ID;");
    ImmutableRuleDefMap defMap = ImmutableRuleDefMap.create(grammar);
    Truth.assertThat(
            defMap.getParserRuleNames().stream()
                .map(RuleNameRegistry.RuleNameHandle::get)
                .collect(Collectors.toList()))
        .containsExactly("start", "a", "b");
    EliminateUnreachableRulePass pass = new EliminateUnreachableRulePass("start");
    ImmutableRuleDefMap processedMap = pass.process(defMap);
    Truth.assertThat(
            processedMap.getParserRuleNames().stream()
                .map(RuleNameRegistry.RuleNameHandle::get)
                .collect(Collectors.toList()))
        .containsExactly("start", "a");
  }
}
