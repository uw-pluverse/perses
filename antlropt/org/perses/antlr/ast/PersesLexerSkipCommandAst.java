package org.perses.antlr.ast;

import com.google.common.base.Preconditions;

import java.io.PrintStream;
import java.util.List;

public class PersesLexerSkipCommandAst extends AbstractPersesRuleElement {

  private final AbstractPersesRuleElement body;

  public PersesLexerSkipCommandAst(AbstractPersesRuleElement body) {
    this.body = body;
  }

  @Override
  public void toSourceCode(PrintStream stream, int indent, boolean multiLineMode) {
    if (body.getPrecedence().lt(getPrecedence())) {
      stream.print('(');
      body.toSourceCode(stream, indent, multiLineMode);
      stream.println(')');
    } else {
      body.toSourceCode(stream, indent, multiLineMode);
    }
    stream.println(" -> skip");
  }

  @Override
  public int getChildCount() {
    return 1;
  }

  @Override
  public AbstractPersesRuleElement getChild(int index) {
    Preconditions.checkArgument(index == 0);
    return body;
  }

  public AbstractPersesRuleElement getBody() {
    return body;
  }

  @Override
  public AstTag getTag() {
    return AstTag.LEXER_SKIP_COMMAND;
  }

  @Override
  public AbstractPersesRuleElement createWithNewChildren(
      List<AbstractPersesRuleElement> newChildren) {
    Preconditions.checkArgument(newChildren.size() == 1);
    return new PersesLexerSkipCommandAst(newChildren.get(0));
  }
}
