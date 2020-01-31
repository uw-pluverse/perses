package org.perses.antlr.ast;

import com.google.common.collect.ImmutableSet;

public final class EpsilonInfo {

  private final ImmutableSet<AbstractPersesRuleDefAst> epsilonableRules;
  private final ImmutableSet<AbstractPersesRuleElement> epsilonableElements;

  public EpsilonInfo(
      ImmutableSet<AbstractPersesRuleDefAst> epsilonableRules,
      ImmutableSet<AbstractPersesRuleElement> epsilonableElements) {
    this.epsilonableRules = epsilonableRules;
    this.epsilonableElements = epsilonableElements;
  }

  public ImmutableSet<AbstractPersesRuleDefAst> getEpsilonableRules() {
    return epsilonableRules;
  }

  public boolean canBeEpsilon(AbstractPersesRuleDefAst ruleDef) {
    return epsilonableRules.contains(ruleDef);
  }

  public boolean canBeEpsilon(AbstractPersesRuleElement element) {
    return epsilonableElements.contains(element);
  }
}
