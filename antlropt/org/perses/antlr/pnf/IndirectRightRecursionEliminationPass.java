package org.perses.antlr.pnf;

import com.google.common.annotations.VisibleForTesting;
import com.google.common.base.Preconditions;
import com.google.common.collect.ImmutableList;
import org.perses.antlr.ast.AbstractPersesRuleElement;
import org.perses.antlr.ast.AstTag;
import org.perses.antlr.ast.PersesSequenceAst;
import org.perses.antlr.ast.RuleNameRegistry;

import java.util.Optional;

public class IndirectRightRecursionEliminationPass
    extends AbstractIndirectRecursionEliminationPass {

  @Override
  protected RuleTransitionGraph createRuleTransitionGraph(ImmutableRuleDefMap grammar) {
    return RuleTransitionGraph.createForRightmostTransition(grammar);
  }

  @VisibleForTesting
  protected Optional<RuleNameRegistry.RuleNameHandle> getRuleRefToInline(
      AbstractPersesRuleElement def) {
    return getFirstOrLastRuleRef(def, /*seekingFirst=*/ false);
  }

  @Override
  protected final void inlineRuleRefIntoSequence(
      PersesSequenceAst originalSequence,
      AbstractPersesRuleElement toInline,
      ImmutableList.Builder<AbstractPersesRuleElement> newSeqBuilder) {
    Preconditions.checkState(originalSequence.getLastChild().getTag() == AstTag.RULE_REF);
    final int size = originalSequence.getChildCount();
    for (int i = 0; i < size - 1; ++i) {
      newSeqBuilder.add(originalSequence.getChild(i));
    }
    if (toInline.getTag() == AstTag.SEQUENCE) {
      toInline.foreachChildRuleElement(newSeqBuilder::add);
    } else if (toInline.getTag() == AstTag.EPSILON) {
      // Do not inline epsilon, as it is empty.
    } else {
      newSeqBuilder.add(toInline);
    }
  }
}
