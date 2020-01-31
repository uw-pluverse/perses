package org.perses.antlr.ast;

import java.io.PrintStream;

public final class PersesFragmentLexerRuleAst extends AbstractPersesLexerRuleAst {

  public PersesFragmentLexerRuleAst(
      RuleNameRegistry.RuleNameHandle ruleNameHandle, AbstractPersesRuleElement body) {
    super(ruleNameHandle, body);
  }

  @Override
  public void toSourceCode(PrintStream stream, int indent, boolean multiLineMode) {
    stream.println("fragment");
    super.toSourceCode(stream, indent, multiLineMode);
  }

  @Override
  public AstTag getTag() {
    return AstTag.LEXER_FRAGMENT_DEFINITION;
  }

}
