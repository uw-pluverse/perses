package org.perses.antlr.pnf;

import com.google.common.collect.Iterables;
import org.perses.antlr.ast.AbstractPersesRuleElement;
import org.perses.antlr.ast.AstTag;
import org.perses.antlr.ast.PersesRuleReferenceAst;
import org.perses.antlr.ast.RuleNameRegistry;

import java.util.Set;

/**
 * start : a ;
 *
 * <p>a: kleene_star__test;
 *
 * <p>kleene_star__test: ID*;
 *
 * <p>The rule "a" is redundant, and can be removed. So the refactored grammar becomes
 *
 * <p>start : kleene_star__test;
 *
 * <p>kleene_star__test: ID*;
 */
@Deprecated
public class QuantifiedRuleInlinerPass extends AbstractPnfPass {
  @Override
  public ImmutableRuleDefMap process(ImmutableRuleDefMap grammar) {
    MutableRuleDefMap mutable = grammar.createMutable();
    for (RuleNameRegistry.RuleNameHandle ruleName : mutable.keySet()) {
      final Set<AbstractPersesRuleElement> defs = mutable.get(ruleName);
      if (defs.size() != 1) {
        continue;
      }
      final AbstractPersesRuleElement body = Iterables.getOnlyElement(defs);
      if (body.getTag() != AstTag.RULE_REF) {
        continue;
      }
      RuleNameRegistry.RuleNameHandle calledRuleName =
          ((PersesRuleReferenceAst) body).getRuleNameHandle();
      switch (calledRuleName.getType()) {
        case KLEENE_PLUS:
        case KLEENE_STAR:
        case OPTIONAL:
        case TOKEN:
        case OTHER_RULE:
      }
    }
    return null;
  }
}
