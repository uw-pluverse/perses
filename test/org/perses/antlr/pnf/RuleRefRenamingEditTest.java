package org.perses.antlr.pnf;

import com.google.common.truth.Truth;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.antlr.ast.AbstractPersesRuleDefAst;
import org.perses.antlr.ast.AbstractPersesRuleElement;

import java.util.Optional;

@RunWith(JUnit4.class)
public class RuleRefRenamingEditTest extends PnfLeftTestGrammar {

  @Test
  public void test() {
    AbstractPersesRuleDefAst ruleA = grammar.getRuleDefinition("a").get();
    RuleRefRenamingEdit edit = new RuleRefRenamingEdit(this.b, this.c);
    RuleRefCounterAstVisitor counter = new RuleRefCounterAstVisitor(this.b);
    counter.preorder(ruleA);
    Truth.assertThat(counter.getCount()).isEqualTo(1);
    Optional<AbstractPersesRuleElement> applied = edit.apply(ruleA.getBody());
    Truth.assertThat(applied.isPresent()).isTrue();

    RuleRefCounterAstVisitor anotherCounter = new RuleRefCounterAstVisitor(this.b);
    counter.preorder(applied.get());
    Truth.assertThat(anotherCounter.getCount()).isEqualTo(0);
  }
}
