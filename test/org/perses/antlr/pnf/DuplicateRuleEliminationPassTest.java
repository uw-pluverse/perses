package org.perses.antlr.pnf;

import com.google.common.collect.Iterables;
import com.google.common.truth.Truth;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.antlr.GrammarTestingUtility;
import org.perses.antlr.ast.PersesGrammar;

@RunWith(JUnit4.class)
public class DuplicateRuleEliminationPassTest {

  @Test
  public void testWithStartRuleName() {
    PersesGrammar persesGrammar =
        GrammarTestingUtility.createPersesGrammarFromString(
            new StringBuilder()
                .append("start: b;")
                .append("c: d;")
                .append("b: 'e';")
                .append("d: 'e';")
                .toString());
    ImmutableRuleDefMap defMap = ImmutableRuleDefMap.create(persesGrammar);
    {
      DuplicateRuleEliminationPass pass = new DuplicateRuleEliminationPass("start");
      ImmutableRuleDefMap processed = pass.process(defMap);
      Truth.assertThat(processed.size()).isEqualTo(2);
      Truth.assertThat(
              Iterables.getOnlyElement(processed.getRuleDefinition("start")).getSourceCode())
          .isEqualTo("b");
      Truth.assertThat(Iterables.getOnlyElement(processed.getRuleDefinition("b")).getSourceCode())
          .isEqualTo("'e'");
    }
    {
      DuplicateRuleEliminationPass pass = new DuplicateRuleEliminationPass("c");
      ImmutableRuleDefMap processed = pass.process(defMap);
      Truth.assertThat(processed.size()).isEqualTo(2);
      Truth.assertThat(
          Iterables.getOnlyElement(processed.getRuleDefinition("c")).getSourceCode())
          .isEqualTo("b");
      Truth.assertThat(Iterables.getOnlyElement(processed.getRuleDefinition("b")).getSourceCode())
          .isEqualTo("'e'");
    }
  }
}
