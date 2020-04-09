package org.perses.antlr.pnf;

import com.google.common.collect.ImmutableList;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.antlr.GrammarTestingUtility;
import org.perses.antlr.ast.AbstractPersesAst;
import org.perses.antlr.ast.AbstractPersesRuleElement;
import org.perses.antlr.ast.PersesGrammar;

import java.util.stream.Collectors;

import static com.google.common.truth.Truth.assertThat;

@RunWith(JUnit4.class)
public class AltRulesInlinePassTest {

  private InlineSingleUseAltRulePass pass;

  @Before
  public void setup() {
    pass = new InlineSingleUseAltRulePass();
  }

  @Test
  public void test() {
    PersesGrammar grammar =
        GrammarTestingUtility.createPersesGrammarFromString("a : b | c;", "b : d | e;");
    ImmutableRuleDefMap defMap = ImmutableRuleDefMap.create(grammar);
    ImmutableRuleDefMap processed = pass.process(defMap);
    ImmutableList<AbstractPersesRuleElement> a = processed.getRuleDefinition("a");
    assertThat(a).hasSize(3);
    assertThat(a.stream().map(AbstractPersesAst::getSourceCode).collect(Collectors.toList()))
        .containsExactly("d", "e", "c");
  }
}
