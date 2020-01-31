package org.perses.antlr.ast;

import com.google.common.base.MoreObjects;
import org.antlr.v4.parse.ANTLRParser;
import org.antlr.v4.tool.ast.GrammarAST;

import java.io.PrintStream;
import java.util.List;

public class PersesEpsilonAst extends AbstractPersesRuleElement {

  public static PersesEpsilonAst INSTANCE = new PersesEpsilonAst();

  private PersesEpsilonAst() {}

  public static boolean isEpsilonAst(GrammarAST ast) {
    return ast.getToken().getType() == ANTLRParser.EPSILON;
  }

  @Override
  public void toSourceCode(PrintStream stream, int indent, boolean multiLineMode) {
    stream.print("/* Epsilon. */");
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
    return AstTag.EPSILON;
  }

  @Override
  public String toString() {
    return MoreObjects.toStringHelper(this).add("code", getSourceCode()).toString();
  }

  @Override
  public AbstractPersesRuleElement createWithNewChildren(
      List<AbstractPersesRuleElement> newChildren) {
    return INSTANCE;
  }
}
