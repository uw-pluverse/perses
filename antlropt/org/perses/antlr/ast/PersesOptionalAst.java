package org.perses.antlr.ast;

import com.google.common.base.Preconditions;

import java.util.List;

public final class PersesOptionalAst extends AbstractPersesQuantifiedAst {

  public static PersesOptionalAst createGreedy(AbstractPersesRuleElement body) {
    return new PersesOptionalAst(body, true);
  }

  public static PersesOptionalAst createNonGreedy(AbstractPersesRuleElement body) {
    return new PersesOptionalAst(body, false);
  }

  private PersesOptionalAst(AbstractPersesRuleElement body, boolean isGreedy) {
    super(body, isGreedy);
  }

  @Override
  protected String getOperator() {
    return "?";
  }

  @Override
  public AstTag getTag() {
    return AstTag.OPTIONAL;
  }

  @Override
  public AbstractPersesRuleElement createWithNewChildren(
      List<AbstractPersesRuleElement> newChildren) {
    Preconditions.checkArgument(newChildren.size() == 1);
    return new PersesOptionalAst(newChildren.get(0), isGreedy);
  }
}
