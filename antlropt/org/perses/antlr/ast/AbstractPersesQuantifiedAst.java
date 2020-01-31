package org.perses.antlr.ast;

import com.google.common.base.Preconditions;

import java.io.PrintStream;

public abstract class AbstractPersesQuantifiedAst extends AbstractPersesRuleElement {
  protected final AbstractPersesRuleElement body;
  protected final boolean isGreedy;

  public AbstractPersesQuantifiedAst(AbstractPersesRuleElement body, boolean isGreedy) {
    this.body = body;
    this.isGreedy = isGreedy;
  }

  public final boolean isGreedy() {
    return isGreedy;
  }

  @Override
  public void toSourceCode(PrintStream stream, int indent, boolean multiLineMode) {
    if (body.getPrecedence().lt(getPrecedence())) {
      stream.append('(');
      body.toSourceCode(stream, indent + 4, false);
      stream.append(')');
    } else {
      body.toSourceCode(stream, indent + 4, false);
    }
    stream.print(getOperator());
    if (!isGreedy) {
      stream.print('?');
    }
  }

  public AbstractPersesRuleElement getBody() {
    return body;
  }

  @Override
  public int getChildCount() {
    return 1;
  }

  @Override
  public AbstractPersesRuleElement getChild(int index) {
    Preconditions.checkArgument(index == 0);
    return getBody();
  }

  protected abstract String getOperator();
}
