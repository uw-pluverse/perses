package org.perses.antlr.pnf;

import org.perses.antlr.ast.DefaultAstVisitor;
import org.perses.antlr.ast.PersesRuleReferenceAst;
import org.perses.antlr.ast.RuleNameRegistry;

public class RuleRefCounterAstVisitor extends DefaultAstVisitor {

  private int count;
  private final RuleNameRegistry.RuleNameHandle target;

  public RuleRefCounterAstVisitor(RuleNameRegistry.RuleNameHandle target) {
    this.target = target;
  }

  public int getCount() {
    return count;
  }

  protected void visit(PersesRuleReferenceAst ast) {
    if (ast.getRuleNameHandle().equals(target)) {
      ++count;
    }
  }
}
