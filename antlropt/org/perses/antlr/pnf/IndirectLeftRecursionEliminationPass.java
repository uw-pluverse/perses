package org.perses.antlr.pnf;

import com.google.common.annotations.VisibleForTesting;
import com.google.common.base.Preconditions;
import com.google.common.collect.ImmutableList;
import org.perses.antlr.ast.AbstractPersesRuleElement;
import org.perses.antlr.ast.AstTag;
import org.perses.antlr.ast.PersesSequenceAst;
import org.perses.antlr.ast.RuleNameRegistry;

import java.util.Optional;

public class IndirectLeftRecursionEliminationPass extends AbstractIndirectRecursionEliminationPass {

  @Override
  protected RuleTransitionGraph createRuleTransitionGraph(ImmutableRuleDefMap grammar) {
    return RuleTransitionGraph.createForLeftmostTransition(grammar);
  }

  @VisibleForTesting
  protected Optional<RuleNameRegistry.RuleNameHandle> getRuleRefToInline(
      AbstractPersesRuleElement def) {
    Preconditions.checkArgument(def.getTag() != AstTag.ALTERNATIVE_BLOCK);
    return getFirstOrLastRuleRef(def, /*seekingFirst=*/ true);
  }

  protected final void inlineRuleRefIntoSequence(
      PersesSequenceAst originalSequence,
      AbstractPersesRuleElement toInline,
      ImmutableList.Builder<AbstractPersesRuleElement> newSeqBuilder) {
    Preconditions.checkState(originalSequence.getFirstChild().getTag() == AstTag.RULE_REF);
    if (toInline.getTag() == AstTag.SEQUENCE) {
      toInline.foreachChildRuleElement(newSeqBuilder::add);
    } else if (toInline.getTag() == AstTag.EPSILON) {
      // Do not inline epsilon, as it is empty.
    } else {
      newSeqBuilder.add(toInline);
    }
    for (int i = 1, size = originalSequence.getChildCount(); i < size; ++i) {
      newSeqBuilder.add(originalSequence.getChild(i));
    }
  }
}
