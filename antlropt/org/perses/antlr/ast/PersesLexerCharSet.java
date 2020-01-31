package org.perses.antlr.ast;

import com.google.common.base.Preconditions;
import org.antlr.v4.parse.ANTLRLexer;
import org.antlr.v4.tool.ast.GrammarAST;

import java.io.PrintStream;
import java.util.List;

public final class PersesLexerCharSet extends AbstractPersesTerminalAst {

  public PersesLexerCharSet(String text) {
    super(text);
  }

  @Override
  public void toSourceCode(PrintStream stream, int indent, boolean multiLineMode) {
    stream.print(text);
  }


  public static boolean isLexerCharSet(GrammarAST ast) {
    return ast.getToken().getType() == ANTLRLexer.LEXER_CHAR_SET;
  }

  @Override
  public AstTag getTag() {
    return AstTag.LEXER_CHAR_SET;
  }

  @Override
  public AbstractPersesRuleElement createWithNewChildren(
      List<AbstractPersesRuleElement> newChildren) {
    Preconditions.checkArgument(newChildren.isEmpty());
    return new PersesLexerCharSet(text);
  }

  @Override
  public boolean extraEquivalenceTest(AbstractPersesRuleElement other) {
    PersesLexerCharSet charSet = (PersesLexerCharSet) other;
    return text.equals(charSet.text);
  }
}
