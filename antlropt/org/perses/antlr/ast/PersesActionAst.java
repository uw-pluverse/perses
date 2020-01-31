package org.perses.antlr.ast;

import java.io.PrintStream;
import java.util.List;

public class PersesActionAst extends AbstractPersesRuleElement {
  public static final PersesActionAst INSTANCE = new PersesActionAst();

  private PersesActionAst() {}

  @Override
  public void toSourceCode(PrintStream stream, int indent, boolean multiLineMode) {
    stream.print("/*Action Deleted.*/");
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
    return INSTANCE;
  }
}
