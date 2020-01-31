package org.perses.antlr.ast;

import com.google.common.base.Preconditions;

import java.util.List;

public class PersesPlusAst extends AbstractPersesQuantifiedAst {

  public static PersesPlusAst createGreedy(AbstractPersesRuleElement body) {
    return new PersesPlusAst(body, true);
  }

  public static PersesPlusAst createNonGreedy(AbstractPersesRuleElement body) {
    return new PersesPlusAst(body, false);
  }

  private PersesPlusAst(AbstractPersesRuleElement body, boolean isGreedy) {
    super(body, isGreedy);
  }

  @Override
  protected String getOperator() {
    return "+";
  }

  @Override
  public AstTag getTag() {
    return AstTag.PLUS;
  }

  @Override
  public AbstractPersesRuleElement createWithNewChildren(
      List<AbstractPersesRuleElement> newChildren) {
    Preconditions.checkState(newChildren.size() == 1);
    return new PersesPlusAst(newChildren.get(0), isGreedy);
  }
}
