package org.perses.antlr.ast;

import com.google.common.base.Preconditions;

import java.util.List;

public class PersesStarAst extends AbstractPersesQuantifiedAst {

  public static PersesStarAst createGreedy(AbstractPersesRuleElement body) {
    return new PersesStarAst(body, true);
  }

  public static PersesStarAst createNonGreedy(AbstractPersesRuleElement body) {
    return new PersesStarAst(body, false);
  }

  private PersesStarAst(AbstractPersesRuleElement body, boolean isGreedy) {
    super(body, isGreedy);
  }

  @Override
  protected String getOperator() {
    return "*";
  }

  @Override
  public AstTag getTag() {
    return AstTag.STAR;
  }

  @Override
  public AbstractPersesRuleElement createWithNewChildren(
      List<AbstractPersesRuleElement> newChildren) {
    Preconditions.checkState(newChildren.size() == 1);
    return new PersesStarAst(newChildren.get(0), isGreedy);
  }
}
