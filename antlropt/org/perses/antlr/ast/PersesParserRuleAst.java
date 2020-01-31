package org.perses.antlr.ast;

public final class PersesParserRuleAst extends AbstractPersesRuleDefAst {

  public PersesParserRuleAst(
      RuleNameRegistry.RuleNameHandle ruleNameHandle, AbstractPersesRuleElement body) {
    super(ruleNameHandle, body);
  }

  @Override
  public AstTag getTag() {
    return AstTag.RULE_DEFINITION_PARSER;
  }

  @Override
  public boolean isLexerRule() {
    return false;
  }

}
