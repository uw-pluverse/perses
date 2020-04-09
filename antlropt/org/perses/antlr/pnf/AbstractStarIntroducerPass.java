package org.perses.antlr.pnf;

import com.google.common.annotations.VisibleForTesting;
import com.google.common.collect.ImmutableList;
import com.google.common.collect.Iterables;
import org.perses.antlr.RuleType;
import org.perses.antlr.ast.*;

import java.util.ArrayList;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.stream.Collectors;

import static com.google.common.base.Preconditions.checkState;

public abstract class AbstractStarIntroducerPass extends AbstractPnfPass {

  @VisibleForTesting
  protected final void introduceStars(
      MutableRuleDefMap rules, RuleNameRegistry.RuleNameHandle ruleName) {

    final ArrayList<AbstractPersesRuleElement> nonRecursivePartsInRecursiveDef = new ArrayList<>();
    final LinkedHashSet<AbstractPersesRuleElement> nonRecursiveDefs = new LinkedHashSet<>();

    final Iterable<AbstractPersesRuleElement> definitions = rules.get(ruleName);
    classifyDefsAndExtractNonrecursiveParts(
        ruleName, definitions, nonRecursivePartsInRecursiveDef, nonRecursiveDefs);
    inPlaceFlatternAltBlocks(nonRecursivePartsInRecursiveDef);
    for (AbstractPersesRuleElement nonRecursivePart : nonRecursivePartsInRecursiveDef) {
      checkState(!(nonRecursivePart instanceof PersesAlternativeBlockAst), nonRecursivePart);
    }

    if (nonRecursivePartsInRecursiveDef.isEmpty()) {
      return;
    }

    checkState(nonRecursiveDefs.size() > 0);
    rules.removeAll(ruleName);

    final RuleNameRegistry.RuleNameHandle starRuleName =
        ruleName.createAuxiliaryRuleName(RuleType.KLEENE_STAR);
    final RuleNameRegistry.RuleNameHandle quantifiedRuleName =
        ruleName.createAuxiliaryRuleName(RuleType.OTHER_RULE);

    final List<AbstractPersesRuleElement> quantifiedBodyRule =
        constructAlternativeBlocksIfNecessary(nonRecursivePartsInRecursiveDef);
    rules.putAll(quantifiedRuleName, quantifiedBodyRule);
    final PersesStarAst starRule =
        PersesStarAst.createGreedy(new PersesRuleReferenceAst(quantifiedRuleName));
    rules.put(starRuleName, starRule);

    final PersesRuleReferenceAst starRuleRef = new PersesRuleReferenceAst(starRuleName);
    if (nonRecursiveDefs.size() == 1) {
      final AbstractPersesRuleElement nonRecursiveDef = Iterables.getOnlyElement(nonRecursiveDefs);
      rules.put(
          ruleName,
          PersesAstBuilder.combineIntoSequence(
              constructNewSequenceDef(nonRecursiveDef, starRuleRef)));
    } else {
      List<AbstractPersesRuleElement> altBlock =
          constructAlternativeBlocksIfNecessary(nonRecursiveDefs);
      assert altBlock.size() > 1;
      RuleNameRegistry.RuleNameHandle altBlockRuleName =
          ruleName.createAuxiliaryRuleName(RuleType.OTHER_RULE);
      rules.putAll(altBlockRuleName, altBlock);
      rules.put(
          ruleName,
          PersesAstBuilder.combineIntoSequence(
              constructNewSequenceDef(new PersesRuleReferenceAst(altBlockRuleName), starRuleRef)));
    }
  }

  private final void classifyDefsAndExtractNonrecursiveParts(
      RuleNameRegistry.RuleNameHandle ruleName,
      Iterable<AbstractPersesRuleElement> definitions,
      ArrayList<AbstractPersesRuleElement> nonRecursivePartsInRecursiveDef,
      LinkedHashSet<AbstractPersesRuleElement> nonRecursiveDefs) {
    for (AbstractPersesRuleElement def : definitions) {
      final AstTag tag = def.getTag();
      checkState(tag != AstTag.ALTERNATIVE_BLOCK, tag);
      checkState(
          tag != AstTag.RULE_REF
              || !ruleName.get().equals(((PersesRuleReferenceAst) def).getRuleNameHandle().get()));
      if (tag == AstTag.SEQUENCE) {
        final PersesSequenceAst seq = (PersesSequenceAst) def;
        classifyAndExtractPartsFromSequenceDef(
            ruleName, seq, nonRecursivePartsInRecursiveDef, nonRecursiveDefs);
      } else {
        nonRecursiveDefs.add(def);
      }
    }
  }

  protected abstract ImmutableList<AbstractPersesRuleElement> constructNewSequenceDef(
      AbstractPersesRuleElement nonRecursiveDef, PersesRuleReferenceAst starRuleRef);

  protected abstract void classifyAndExtractPartsFromSequenceDef(
      RuleNameRegistry.RuleNameHandle ruleName,
      PersesSequenceAst sequenceDef,
      final ArrayList<AbstractPersesRuleElement> nonRecursivePartsInRecursiveDef,
      final LinkedHashSet<AbstractPersesRuleElement> nonRecursiveDefs);

  @Override
  public final ImmutableRuleDefMap process(ImmutableRuleDefMap grammar) {
    MutableRuleDefMap mutable = grammar.createMutable();
    List<RuleNameRegistry.RuleNameHandle> sortedRuleNames =
        mutable.keySet().stream().sorted().collect(Collectors.toList());
    for (RuleNameRegistry.RuleNameHandle ruleName : sortedRuleNames) {
      introduceStars(mutable, ruleName);
    }
    return grammar.createWithParserDefs(mutable);
  }
}
