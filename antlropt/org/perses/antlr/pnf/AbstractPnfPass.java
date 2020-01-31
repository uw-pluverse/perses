package org.perses.antlr.pnf;

import com.google.common.base.Preconditions;
import com.google.common.collect.ImmutableList;
import com.google.common.collect.Iterables;
import org.perses.antlr.ast.AbstractPersesRuleElement;
import org.perses.antlr.ast.PersesRuleReferenceAst;
import org.perses.antlr.ast.PersesSequenceAst;
import org.perses.antlr.ast.RuleNameRegistry;

import java.util.Collection;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public abstract class AbstractPnfPass {

  public abstract ImmutableRuleDefMap process(ImmutableRuleDefMap grammar);

  protected static List<RuleNameRegistry.RuleNameHandle> getSortedRuleNames(MutableRuleDefMap map) {
    return map.keySet().stream().sorted().collect(Collectors.toList());
  }

  protected static AbstractPersesRuleElement replaceGapWithRuleReference(
      PersesSequenceAst seq, Interval gap, RuleNameRegistry.RuleNameHandle gapReplacement) {
    final ImmutableList.Builder<AbstractPersesRuleElement> builder = ImmutableList.builder();
    for (int i = 0, size = seq.getChildCount(); i < size; ++i) {
      if (i == gap.leftInclusive) {
        builder.add(new PersesRuleReferenceAst(gapReplacement));
      }
      if (gap.leftInclusive <= i && i < gap.rightExclusive) {
        continue;
      }
      builder.add(seq.getChild(i));
    }
    return new PersesSequenceAst(builder.build());
  }

  protected static List<AbstractPersesRuleElement> constructAlternativeBlocksIfNecessary(
      Collection<AbstractPersesRuleElement> alternatives) {
    final int size = alternatives.size();
    Preconditions.checkArgument(size > 0);
    if (size == 1) {
      return ImmutableList.of(Iterables.getOnlyElement(alternatives));
    }
    final HashMap<String, AbstractPersesRuleElement> map = new HashMap<>();
    alternatives.forEach(alt -> map.put(alt.getSourceCode(), alt));
    return map.entrySet().stream()
        .map(Map.Entry::getValue)
        .collect(ImmutableList.toImmutableList());
  }

  protected static int countRulesThatCallsRuleOfName(
      MutableRuleDefMap grammar, RuleNameRegistry.RuleNameHandle ruleName) {
    RuleRefCounterAstVisitor counter = new RuleRefCounterAstVisitor(ruleName);
    counter.preorderGrammar(grammar.entries());
    return counter.getCount();
  }
}
