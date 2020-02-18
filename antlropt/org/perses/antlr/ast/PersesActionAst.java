package org.perses.antlr.ast;

import java.io.PrintStream;
import java.util.List;

public class PersesActionAst extends AbstractPersesRuleElement {

  private final String body;

  PersesActionAst(String body) {
    this.body = body;
  }

  @Override
  public void toSourceCode(PrintStream stream, int indent, boolean multiLineMode) {
    stream.print(body);
  }

  @Deprecated
  @Override
  public AbstractPersesRuleElement getChild(int index) {
    throw new UnsupportedOperationException();
  }

  @Override
  public int getChildCount() {
    return 0;
  }

  @Override
  public AstTag getTag() {
    return AstTag.ACTION;
  }

  @Override
  public AbstractPersesRuleElement createWithNewChildren(
      List<AbstractPersesRuleElement> newChildren) {
    return new PersesActionAst(body);
  }

  @Override
  protected boolean extraEquivalenceTest(AbstractPersesRuleElement other) {
    final PersesActionAst otherAction = (PersesActionAst) other;
    return body.equals(otherAction.body);
  }
}
