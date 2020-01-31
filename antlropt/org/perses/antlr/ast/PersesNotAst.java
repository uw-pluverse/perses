package org.perses.antlr.ast;

import com.google.common.base.Preconditions;

import java.io.PrintStream;
import java.util.List;

public class PersesNotAst extends AbstractPersesRuleElement {

  private final AbstractPersesRuleElement tokens;

  public PersesNotAst(AbstractPersesRuleElement tokens) {
    this.tokens = tokens;
  }

  @Override
  public void toSourceCode(PrintStream stream, int indent, boolean multiLineMode) {
    stream.print("~");
    tokens.toSourceCode(stream, indent, false);
  }

  @Override
  public AbstractPersesRuleElement getChild(int index) {
    Preconditions.checkArgument(index == 0);
    return tokens;
  }

  @Override
  public int getChildCount() {
    return 1;
  }

  @Override
  public AstTag getTag() {
    return AstTag.NOT;
  }

  @Override
  public AbstractPersesRuleElement createWithNewChildren(
      List<AbstractPersesRuleElement> newChildren) {
    Preconditions.checkArgument(newChildren.size() == 1);
    return new PersesNotAst(newChildren.get(0));
  }
}
