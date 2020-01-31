package org.perses.antlr.pnf;

import com.google.common.annotations.VisibleForTesting;
import com.google.common.base.Preconditions;
import com.google.common.collect.ImmutableList;
import com.google.common.collect.ImmutableSet;
import org.jgrapht.Graph;
import org.perses.antlr.ast.*;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;
import java.util.Set;
import java.util.stream.Collectors;

import static com.google.common.base.Preconditions.checkState;

public abstract class AbstractIndirectRecursionEliminationPass extends AbstractPnfPass {

  @Override
  public final ImmutableRuleDefMap process(ImmutableRuleDefMap grammar) {
    final RuleTransitionGraph ruleTransitionGraph = createRuleTransitionGraph(grammar);
    List<Set<RuleNameRegistry.RuleNameHandle>> sccs =
        ruleTransitionGraph.computeSccSet().stream()
            .map(Graph::vertexSet)
            .map(ImmutableSet::copyOf)
            .collect(Collectors.toList());
    final MutableRuleDefMap ruleMap = grammar.createMutable();
    for (Set<RuleNameRegistry.RuleNameHandle> scc : sccs) {
      ruleMap.validate();
      transformForScc(new ProjectedHashMultimap(ruleMap, scc));
      ruleMap.validate();
    }
    return grammar.createWithParserDefs(ruleMap);
  }

  @VisibleForTesting
  protected final void transformForScc(ProjectedHashMultimap grammar) {
    boolean changed = true;
    while (changed) {
      changed = false;
      for (RuleNameRegistry.RuleNameHandle ruleName : grammar.ketSet()) {
        for (AbstractPersesRuleElement def : grammar.get(ruleName)) {
          final Optional<RuleNameRegistry.RuleNameHandle> ruleref = getRuleRefToInline(def);
          if (!ruleref.isPresent()) {
            continue;
          }
          final RuleNameRegistry.RuleNameHandle target = ruleref.get();
          if (!grammar.containsKey(target)) {
            continue;
          }
          final RuleNameRegistry.RuleNameHandle source = ruleName;
          if (source.getId() <= target.getId()) {
            continue;
          }
          checkState(grammar.remove(ruleName, def), "key=%s, value=%s", ruleName, def);
          ArrayList<AbstractPersesRuleElement> toInlineList = new ArrayList<>(grammar.get(target));
          checkState(toInlineList.size() > 0);
          for (AbstractPersesRuleElement toInline : toInlineList) {
            AbstractPersesRuleElement inlined = inlineRuleRef(def, toInline);
            grammar.put(source, inlined);
          }
          changed = true;
          break;
        }
      }
    }
  }

  protected abstract Optional<RuleNameRegistry.RuleNameHandle> getRuleRefToInline(
      AbstractPersesRuleElement def);

  protected final AbstractPersesRuleElement inlineRuleRef(
      AbstractPersesRuleElement def, AbstractPersesRuleElement toInline) {
    switch (def.getTag()) {
      case RULE_REF:
        return toInline;
      case SEQUENCE:
        PersesSequenceAst seq = (PersesSequenceAst) def;
        checkState(seq.getChildCount() > 1);
        ImmutableList.Builder<AbstractPersesRuleElement> newDef =
            ImmutableList.builderWithExpectedSize(seq.getChildCount() + toInline.getChildCount());
        inlineRuleRefIntoSequence(seq, toInline, newDef);
        ImmutableList<AbstractPersesRuleElement> children = newDef.build();
        checkState(children.size() > 0);
        if (children.size() == 1) {
          return children.get(0);
        } else {
          return new PersesSequenceAst(children);
        }
      default:
        throw new RuntimeException("Unhandled tag " + def.getTag());
    }
  }

  protected abstract void inlineRuleRefIntoSequence(
      PersesSequenceAst originalSequence,
      AbstractPersesRuleElement toInline,
      ImmutableList.Builder<AbstractPersesRuleElement> newSeqBuilder);

  protected abstract RuleTransitionGraph createRuleTransitionGraph(ImmutableRuleDefMap grammar);

  static Optional<RuleNameRegistry.RuleNameHandle> getFirstOrLastRuleRef(
      AbstractPersesRuleElement def, final boolean seekingFirst) {
    switch (def.getTag()) {
      case RULE_REF:
        return Optional.of(((PersesRuleReferenceAst) def).getRuleNameHandle());
      case SEQUENCE:
        {
          PersesSequenceAst seq = (PersesSequenceAst) def;
          return seekingFirst
              ? getFirstOrLastRuleRef(seq.getChild(0), seekingFirst)
              : getFirstOrLastRuleRef(seq.getChild(seq.getChildCount() - 1), seekingFirst);
        }
      default:
        return Optional.empty();
    }
  }
}
