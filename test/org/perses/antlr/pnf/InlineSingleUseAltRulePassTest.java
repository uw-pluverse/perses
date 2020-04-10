package org.perses.antlr.pnf;

import com.google.common.collect.ImmutableList;
import com.google.common.collect.Iterables;
import com.google.common.truth.Truth;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.antlr.GrammarTestingUtility;
import org.perses.antlr.ast.AbstractPersesRuleElement;
import org.perses.antlr.ast.PersesGrammar;

@RunWith(JUnit4.class)
public class InlineSingleUseAltRulePassTest {

  @Test
  public void testWithStartRuleName() {
    PersesGrammar persesGrammar =
        GrammarTestingUtility.createPersesGrammarFromString(
            new StringBuilder()
                .append("start: b | c | d | f;")
                .append("c: e | d;")
                .append("e: 'e';")
                .append("d: 'e';")
                .append("f: 'm' | 'n';")
                .append("g: f;")
                .toString());
    ImmutableRuleDefMap defMap = ImmutableRuleDefMap.create(persesGrammar);
    {
      InlineSingleUseAltRulePass pass = new InlineSingleUseAltRulePass();
      ImmutableRuleDefMap processed = pass.process(defMap);
      final ImmutableList<AbstractPersesRuleElement> startAlts = processed.getRuleDefinition("start");
      Truth.assertThat(startAlts).hasSize(4);
      Truth.assertThat(startAlts.get(0).getSourceCode()).isEqualTo("b");
      Truth.assertThat(startAlts.get(1).getSourceCode()).isEqualTo("e");
      Truth.assertThat(startAlts.get(2).getSourceCode()).isEqualTo("d");
      Truth.assertThat(startAlts.get(3).getSourceCode()).isEqualTo("f");
    }

  }
}
