package org.perses.antlr.ast;

public class PersesLexerRuleAst extends AbstractPersesLexerRuleAst {

  public PersesLexerRuleAst(
      RuleNameRegistry.RuleNameHandle ruleNameHandle, AbstractPersesRuleElement body) {
    super(ruleNameHandle, body);
  }

  @Override
  public AstTag getTag() {
    return AstTag.RULE_DEFINITION_LEXER;
  }

}
