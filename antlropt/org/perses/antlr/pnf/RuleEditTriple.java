package org.perses.antlr.pnf;

import org.perses.antlr.ast.AbstractPersesRuleElement;
import org.perses.antlr.ast.RuleNameRegistry;

final class RuleEditTriple {

  private final RuleNameRegistry.RuleNameHandle name;
  private final AbstractPersesRuleElement oldDef;
  private final AbstractPersesRuleElement newDef;

  RuleEditTriple(
      RuleNameRegistry.RuleNameHandle name,
      AbstractPersesRuleElement oldDef,
      AbstractPersesRuleElement newDef) {
    this.name = name;
    this.oldDef = oldDef;
    this.newDef = newDef;
  }

  public void applyTo(MutableRuleDefMap multimap) {
    multimap.remove(name, oldDef);
    multimap.put(name, newDef);
  }
}
