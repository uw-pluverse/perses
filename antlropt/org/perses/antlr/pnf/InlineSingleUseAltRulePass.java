package org.perses.antlr.pnf;

import com.google.common.collect.ImmutableList;
import org.perses.antlr.ast.AbstractPersesRuleElement;
import org.perses.antlr.ast.AstTag;
import org.perses.antlr.ast.PersesRuleReferenceAst;
import org.perses.antlr.ast.RuleNameRegistry;

import java.util.ArrayList;
import java.util.Collection;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

public class InlineSingleUseAltRulePass extends AbstractPnfPass {

  /**
   * Note that this method is intentionally written in this way, to make sure the new def keeps the
   * original order of alternatives, to avoid ambiguity.
   *
   * @param grammar
   * @return
   */
  @Override
  public ImmutableRuleDefMap process(ImmutableRuleDefMap grammar) {
    MutableRuleDefMap mutableGrammar = grammar.createMutable();
    final List<RuleNameRegistry.RuleNameHandle> ruleNameList = getSortedRuleNames(mutableGrammar);
    for (RuleNameRegistry.RuleNameHandle ruleName : ruleNameList) {

      final ImmutableList<AbstractPersesRuleElement> origAlternatives =
          ImmutableList.copyOf(mutableGrammar.get(ruleName));

      final ImmutableList<Candidate> candidates =
          computeCandidates(mutableGrammar, origAlternatives);
      if (candidates.isEmpty()) {
        continue;
      }
      // Note: we remove the old rule def, to make the alternatives in the new def have the same
      // order.
      mutableGrammar.removeAll(ruleName);
      final LinkedHashMap<AbstractPersesRuleElement, ArrayList<AbstractPersesRuleElement>>
          oldAltToNewAlts = new LinkedHashMap<>();
      for (AbstractPersesRuleElement alternative : origAlternatives) {
        final ArrayList<AbstractPersesRuleElement> list = new ArrayList<>();
        list.add(alternative);
        oldAltToNewAlts.put(alternative, list);
      }

      for (Candidate candidate : candidates) {
        final AbstractPersesRuleElement orig = candidate.orig;
        final ArrayList<AbstractPersesRuleElement> newAlts = oldAltToNewAlts.get(orig);
        newAlts.clear();
        assert !candidate.replacements.isEmpty();
        newAlts.addAll(candidate.replacements);
      }
      final List<AbstractPersesRuleElement> newAlternatives =
          oldAltToNewAlts.entrySet().stream()
              .map(entry -> entry.getValue())
              .flatMap(ArrayList::stream)
              .collect(Collectors.toList());

      for (AbstractPersesRuleElement alt : newAlternatives) {
        if (isEquivalentToAny(alt, mutableGrammar.get(ruleName))) {
          continue;
        }
        mutableGrammar.put(ruleName, alt);
      }
    }
    return grammar.createWithParserDefs(mutableGrammar);
  }

  private static ImmutableList<Candidate> computeCandidates(
      MutableRuleDefMap mutable, Collection<AbstractPersesRuleElement> alternatives) {
    if (alternatives.isEmpty()) {
      return ImmutableList.of();
    }
    final ImmutableList.Builder<Candidate> builder = ImmutableList.builder();
    for (AbstractPersesRuleElement def : alternatives) {
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
        // TODO: maybe we can still inline it.
        // Not a rule with multiple alternatives.
        continue;
      }
      calledRules.forEach(
          rule -> builder.add(new Candidate(def, ImmutableList.copyOf(calledRules))));
    }
    return builder.build();
  }

  private static final class Candidate {
    public final AbstractPersesRuleElement orig;
    public final ImmutableList<AbstractPersesRuleElement> replacements;

    private Candidate(
        AbstractPersesRuleElement orig, ImmutableList<AbstractPersesRuleElement> replacements) {
      this.orig = orig;
      this.replacements = replacements;
    }
  }

  private static boolean isEquivalentToAny(
      AbstractPersesRuleElement element, Iterable<AbstractPersesRuleElement> list) {
    for (AbstractPersesRuleElement listEle : list) {
      if (listEle.isEquivalent(element)) {
        return true;
      }
    }
    return false;
  }
}
