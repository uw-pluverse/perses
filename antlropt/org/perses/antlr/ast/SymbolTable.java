package org.perses.antlr.ast;

public final class SymbolTable {

  private final RuleNameRegistry ruleNameRegistry = new RuleNameRegistry();

  public RuleNameRegistry getRuleNameRegistry() {
    return ruleNameRegistry;
  }
}
