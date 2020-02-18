package org.perses.antlr.ast;

import com.google.common.base.Preconditions;

import java.io.PrintStream;
import java.util.List;

// TODO: merge with PersesLexerSkipCommandAst to remove duplicate code.
public class PersesLexerChannelCommandAst extends AbstractPersesRuleElement {

  private final String channelName;
  private final AbstractPersesRuleElement body;

  public PersesLexerChannelCommandAst(String channelName, AbstractPersesRuleElement body) {
    this.channelName = channelName;
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
    stream.printf(" -> channel(%s)\n", channelName);
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

  @Override
  public AstTag getTag() {
    return AstTag.LEXER_CHANNEL_COMMAND;
  }

  @Override
  public AbstractPersesRuleElement createWithNewChildren(
      List<AbstractPersesRuleElement> newChildren) {
    Preconditions.checkArgument(newChildren.size() == 1);
    return new PersesLexerChannelCommandAst(channelName, newChildren.get(0));
  }
}
