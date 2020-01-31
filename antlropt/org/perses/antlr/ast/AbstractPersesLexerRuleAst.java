package org.perses.antlr.ast;

public abstract class AbstractPersesLexerRuleAst extends AbstractPersesRuleDefAst {

  protected AbstractPersesLexerRuleAst(
      RuleNameRegistry.RuleNameHandle ruleNameHandle, AbstractPersesRuleElement body) {
    super(ruleNameHandle, body);
  }

  @Override
  public boolean isLexerRule() {
    return true;
  }
}
