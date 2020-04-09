package org.perses.antlr.pnf;

import com.google.common.collect.ImmutableList;
import org.perses.antlr.ast.AbstractPersesRuleElement;
import org.perses.antlr.ast.AstTag;
import org.perses.antlr.ast.PersesRuleReferenceAst;
import org.perses.antlr.ast.PersesSequenceAst;
import org.perses.antlr.ast.RuleNameRegistry.RuleNameHandle;

import java.util.ArrayList;
import java.util.LinkedHashSet;

public class StarLeftIntroducerPass extends AbstractStarIntroducerPass {

  protected void classifyAndExtractPartsFromSequenceDef(
      RuleNameHandle ruleName,
      PersesSequenceAst sequenceDef,
      final ArrayList<AbstractPersesRuleElement> nonRecursivePartsInRecursiveDef,
      final LinkedHashSet<AbstractPersesRuleElement> nonRecursiveDefs) {
    final AbstractPersesRuleElement first = sequenceDef.getFirstChild();
    final AbstractPersesRuleElement rest = sequenceDef.subsequence(1);
    if (first.getTag() == AstTag.RULE_REF
        && ((PersesRuleReferenceAst) first).getRuleNameHandle().equals(ruleName)) {
      nonRecursivePartsInRecursiveDef.add(rest);
    } else {
      nonRecursiveDefs.add(sequenceDef);
    }
  }

  @Override
  protected ImmutableList<AbstractPersesRuleElement> constructNewSequenceDef(
      AbstractPersesRuleElement nonRecursiveDef, PersesRuleReferenceAst starRuleRef) {
    return ImmutableList.of(nonRecursiveDef, starRuleRef);
  }
}
