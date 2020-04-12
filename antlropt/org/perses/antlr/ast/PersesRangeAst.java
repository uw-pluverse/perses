package org.perses.antlr.ast;

import com.google.common.base.Preconditions;

import java.io.PrintStream;
import java.util.List;

public class PersesRangeAst extends AbstractPersesRuleElement {

  private final PersesTerminalAst first;
  private final PersesTerminalAst second;

  public PersesRangeAst(PersesTerminalAst first, PersesTerminalAst second) {
    this.first = first;
    this.second = second;
  }

  @Override
  public void toSourceCode(PrintStream stream, int indent, boolean multiLineMode) {
    first.toSourceCode(stream, indent, multiLineMode);
    stream.append("..");
    second.toSourceCode(stream, indent, multiLineMode);
  }

  @Override
  public int getChildCount() {
    return 2;
  }

  @Override
  public AbstractPersesRuleElement getChild(int index) {
    switch (index) {
      case 0:
        return first;
      case 1:
        return second;
      default:
        throw new RuntimeException("Invalid index: " + index);
    }
  }

  @Override
  public AstTag getTag() {
    return AstTag.LEXER_RANGE_OPERATOR;
  }

  @Override
  public AbstractPersesRuleElement createWithNewChildren(
      List<AbstractPersesRuleElement> newChildren) {
    Preconditions.checkArgument(newChildren.size() == 2);
    final AbstractPersesRuleElement first = newChildren.get(0);
    final AbstractPersesRuleElement second = newChildren.get(1);
    Preconditions.checkArgument(first instanceof PersesTerminalAst);
    Preconditions.checkArgument(second instanceof PersesTerminalAst);
    return new PersesRangeAst((PersesTerminalAst) first, (PersesTerminalAst) second);
  }
}
