package org.perses.antlr.ast;

import java.io.PrintStream;

public final class PersesNamedAction extends AbstractPersesAst {

  private final String name;
  private final String body;

  public PersesNamedAction(String name, String body) {
    this.name = name;
    this.body = body;
  }

  @Override
  public void toSourceCode(PrintStream stream, int indent, boolean multiLineMode) {
    stream.append('@').append(name).append(' ').append(body).append('\n');
  }

  @Override
  public int getChildCount() {
    return 0;
  }

  @Override
  public AbstractPersesAst getChild(int index) {
    throw new UnsupportedOperationException();
  }

  @Override
  public AstTag getTag() {
    return null;
  }
}
