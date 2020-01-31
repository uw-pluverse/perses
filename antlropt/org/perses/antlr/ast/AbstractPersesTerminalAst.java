package org.perses.antlr.ast;

public abstract class AbstractPersesTerminalAst extends AbstractPersesRuleElement {

  protected final String text;

  protected AbstractPersesTerminalAst(String text) {
    this.text = text;
  }

  public final String getText() {
    return text;
  }

  @Override
  public final int getChildCount() {
    return 0;
  }

  @Deprecated
  @Override
  public final AbstractPersesRuleElement getChild(int index) {
    throw new UnsupportedOperationException();
  }
}
