package org.perses.antlr.pnf;

import org.perses.antlr.ast.AbstractPersesRuleElement;
import org.perses.antlr.ast.RuleNameRegistry;

import java.util.Set;

@Deprecated
public class QuantifiedRuleExtractorFromAltBlockPass extends AbstractPnfPass {

  @Override
  public ImmutableRuleDefMap process(ImmutableRuleDefMap grammar) {
    MutableRuleDefMap mutable = grammar.createMutable();
    for (RuleNameRegistry.RuleNameHandle name : mutable.keySet()) {
      final Set<AbstractPersesRuleElement> defs = mutable.get(name);
    }
    return null;
  }
}
