package org.perses.antlr.pnf;

import com.google.common.collect.ImmutableList;
import org.perses.antlr.ast.AbstractPersesRuleElement;
import org.perses.antlr.ast.AstTag;
import org.perses.antlr.ast.PersesRuleReferenceAst;
import org.perses.antlr.ast.RuleNameRegistry;

import java.util.ArrayList;
import java.util.List;
import java.util.Set;

public class InlineSingleUseAltRulePass extends AbstractPnfPass {

  @Override
  public ImmutableRuleDefMap process(ImmutableRuleDefMap grammar) {
    MutableRuleDefMap mutable = grammar.createMutable();
    final List<RuleNameRegistry.RuleNameHandle> ruleNameList = getSortedRuleNames(mutable);
    for (RuleNameRegistry.RuleNameHandle ruleName : ruleNameList) {
      ArrayList<AbstractPersesRuleElement> defCopy = new ArrayList<>(mutable.get(ruleName));
      if (defCopy.size() == 1) {
        continue;
      }
      for (AbstractPersesRuleElement def : defCopy) {
        assert def.getTag() != AstTag.ALTERNATIVE_BLOCK;

        if (def.getTag() != AstTag.RULE_REF) {
          continue;
        }
        assert def.getTag() == AstTag.RULE_REF;
        PersesRuleReferenceAst ruleRef = (PersesRuleReferenceAst) def;
        if (countRulesThatCallsRuleOfName(mutable, ruleRef.getRuleNameHandle()) > 1) {
          // This rule is also used in other rules, and we do not inline it.
          continue;
        }
        Set<AbstractPersesRuleElement> calledRules = mutable.get(ruleRef.getRuleNameHandle());
        if (calledRules.size() < 2) {
          // Not a rule with multiple alternatives.
          continue;
        }
        mutable.remove(ruleName, def);
        final ImmutableList<AbstractPersesRuleElement> remainingAlternatives =
            ImmutableList.copyOf(mutable.get(ruleName));
        for (AbstractPersesRuleElement calledRuleAlt : calledRules) {
          if (isEquivalentToAny(calledRuleAlt, remainingAlternatives)) {
            continue;
          }
          mutable.put(ruleName, calledRuleAlt);
        }
      }
    }
    return grammar.createWithParserDefs(mutable);
  }

  private static boolean isEquivalentToAny(
      AbstractPersesRuleElement element, ImmutableList<AbstractPersesRuleElement> list) {
    for (AbstractPersesRuleElement listEle : list) {
      if (listEle.isEquivalent(element)) {
        return true;
      }
    }
    return false;
  }
}
