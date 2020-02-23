package org.perses.antlr.ast;

import com.google.common.collect.ImmutableList;

import java.io.PrintStream;

public final class PersesGrammarOptionsAst extends AbstractPersesAst {

  public static final PersesGrammarOptionsAst EMPTY =
      new PersesGrammarOptionsAst(ImmutableList.of());

  public static final class Option {
    public final String name;
    public final String value;

    public Option(String name, String value) {
      this.name = name;
      this.value = value;
    }
  }

  private final ImmutableList<Option> options;

  public PersesGrammarOptionsAst(ImmutableList<Option> options) {
    this.options = options;
  }

  @Override
  public void toSourceCode(PrintStream stream, int indent, boolean multiLineMode) {
    if (options.isEmpty()) {
      return;
    }
    stream.print("options {\n");
    final int newIndent = indent + INDENT_INCREAMENT;
    for (Option option : options) {
      printIndent(stream, newIndent);
      stream.printf("%s=%s;\n", option.name, option.value);
    }
    printIndent(stream, indent);
    stream.print("}\n");
  }

  @Override
  public int getChildCount() {
    return 0;
  }

  @Deprecated
  @Override
  public AbstractPersesAst getChild(int index) {
    throw new UnsupportedOperationException();
  }

  @Override
  public AstTag getTag() {
    return null;
  }
}
