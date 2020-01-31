package org.perses.antlr.pnf;

import org.perses.antlr.ast.*;
import com.google.common.annotations.VisibleForTesting;
import com.google.common.base.Preconditions;
import com.google.common.collect.HashMultimap;
import org.perses.antlr.ast.RuleNameRegistry.RuleNameHandle;

import java.util.*;
import java.util.stream.Collectors;

public class PnfBuilder {

  private final PersesGrammar grammar;

  public PnfBuilder(PersesGrammar grammar) {
    this.grammar = grammar;
  }

  public static PnfBuilder create(PersesGrammar grammar) {
    return new PnfBuilder(grammar);
  }

  public PersesGrammar build() {
    final ImmutableRuleDefMap ruleDefMap = ImmutableRuleDefMap.create(this.grammar);
    normalizeLeft(ruleDefMap);
    return null;
  }

  @VisibleForTesting
  static void normalizeLeft(ImmutableRuleDefMap ruleDefMap) {
    RuleTransitionGraph ruleTransitionGraph = RuleTransitionGraph.createForLeftmostTransition(ruleDefMap);
    List<ImmutableRuleDefMap> sccs =
        ruleTransitionGraph.computeSccSet().stream()
            .map(scc -> ruleDefMap.project(scc.vertexSet()))
            .collect(Collectors.toList());
//    for (RuleDefMap scc : sccs) {
//      RuleDefMap mapAfterTransformation = transformLeftForScc(scc);
//      introduceQuantifiersLeft(scc);
//    }
  }

  @VisibleForTesting
  static ImmutableRuleDefMap introduceQuantifiersLeft(ImmutableRuleDefMap ruleDefMap) {
    return null;
  }

  @VisibleForTesting
  static void introducePlusLeft(
      HashMultimap<RuleNameHandle, AbstractPersesRuleElement> ruleDefMap, RuleNameHandle ruleName) {
    for (AbstractPersesRuleElement def : ruleDefMap.get(ruleName)) {
      final AstTag tag = def.getTag();
      Preconditions.checkState(tag != AstTag.ALTERNATIVE_BLOCK);
      if (tag != AstTag.SEQUENCE) {
        continue;
      }
      final PersesSequenceAst seq = (PersesSequenceAst) def;
      for (int i = 0, size = seq.getChildCount(); i < size; ++i) {
        final AbstractPersesRuleElement child = seq.getChild(i);
        final AstTag childTag = child.getTag();
        Preconditions.checkState(childTag != AstTag.SEQUENCE);
        if (childTag == AstTag.STAR) {

        }
      }
    }
  }


}
