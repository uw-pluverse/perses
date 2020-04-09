package org.perses.antlr.pnf;

import com.google.common.annotations.VisibleForTesting;
import com.google.common.collect.HashMultimap;
import com.google.common.collect.ImmutableCollection;
import com.google.common.collect.ImmutableList;
import com.google.common.collect.ImmutableSet;
import com.google.common.collect.Iterables;
import org.perses.antlr.RuleType;
import org.perses.antlr.ast.AbstractPersesRuleElement;
import org.perses.antlr.ast.AstEdit;
import org.perses.antlr.ast.AstTag;
import org.perses.antlr.ast.PersesPlusAst;
import org.perses.antlr.ast.PersesRuleReferenceAst;
import org.perses.antlr.ast.PersesSequenceAst;
import org.perses.antlr.ast.PersesStarAst;
import org.perses.antlr.ast.RuleNameRegistry.RuleNameHandle;

import java.util.ArrayList;
import java.util.Map;
import java.util.Objects;
import java.util.Optional;

import static com.google.common.base.Preconditions.checkState;

public class PlusIntroducerLeftPass extends AbstractPnfPass {
  @Override
  public ImmutableRuleDefMap process(ImmutableRuleDefMap grammar) {
    MutableRuleDefMap mutable = grammar.createMutable();
    PlusIntroducerEdit edit = new PlusIntroducerEdit(grammar);
    ArrayList<RuleEditTriple> toUpdate = new ArrayList<>();
    for (Map.Entry<RuleNameHandle, AbstractPersesRuleElement> entry : mutable.entries()) {
      final RuleNameHandle name = entry.getKey();
      final AbstractPersesRuleElement oldDef = entry.getValue();
      checkState(oldDef.getTag() != AstTag.ALTERNATIVE_BLOCK);
      Optional<AbstractPersesRuleElement> newDef = edit.apply(oldDef);
      if (!newDef.isPresent()) {
        continue;
      }
      toUpdate.add(new RuleEditTriple(name, oldDef, newDef.get()));
    }
    toUpdate.forEach(triple -> triple.applyTo(mutable));
    edit.toAdd.forEach(mutable::put);
    return grammar.createWithParserDefs(mutable);
  }

  @VisibleForTesting
  static class PlusIntroducerEdit extends AstEdit {

    private final ImmutableRuleDefMap defMap;

    @VisibleForTesting
    final HashMultimap<RuleNameHandle, AbstractPersesRuleElement> toAdd = HashMultimap.create();

    PlusIntroducerEdit(ImmutableRuleDefMap defMap) {
      this.defMap = defMap;
    }

    @Override
    protected Optional<AbstractPersesRuleElement> internalApply(
        AbstractPersesRuleElement element, final boolean isRoot) {
      AstTag tag = element.getTag();
      if (tag != AstTag.SEQUENCE) {
        return Optional.empty();
      }
      final int childCount = element.getChildCount();
      checkState(childCount > 1);
      PersesSequenceAst sequence = (PersesSequenceAst) element;
      final ArrayList<AbstractPersesRuleElement> childrenCopy =
          new ArrayList<>(sequence.getChildren());
      for (int i = 0; i < childCount; ++i) {
        final AbstractPersesRuleElement child = sequence.getChild(i);
        final AstTag childTag = child.getTag();
        checkState(
            !childTag.isQuantifier(),
            "Quantified node is not expected here. "
                + "You can run a normalization pass before this pass to fix the problem.");
        if (childTag != AstTag.RULE_REF) {
          continue;
        }
        final RuleNameHandle ruleName = ((PersesRuleReferenceAst) child).getRuleNameHandle();
        Optional<PersesStarAst> starAst = getStarIfIsKleeneStarRule(ruleName);
        if (!starAst.isPresent()) {
          continue;
        }
        AbstractPersesRuleElement quantified = starAst.get().getBody();
        i = transformStarToPlus(sequence, i, childrenCopy, quantified, ruleName, starAst.get());
      }
      ImmutableList<AbstractPersesRuleElement> newChildren =
          childrenCopy.stream().filter(Objects::nonNull).collect(ImmutableList.toImmutableList());
      checkState(element.getTag() == AstTag.SEQUENCE);
      checkState(newChildren.size() > 0);
      if (newChildren.size() == 1) {
        return Optional.of(Iterables.getOnlyElement(newChildren));
      } else {
        return Optional.of(new PersesSequenceAst(newChildren));
      }
    }

    @VisibleForTesting
    int transformStarToPlus(
        final PersesSequenceAst element,
        int currentIndexOfStar,
        ArrayList<AbstractPersesRuleElement> newChildren,
        AbstractPersesRuleElement bodyToMatch,
        RuleNameHandle starRuleName,
        PersesStarAst starAst) {
      final ImmutableList<AbstractPersesRuleElement> bodySequence =
          bodyToMatch.getTag() == AstTag.SEQUENCE
              ? ((PersesSequenceAst) bodyToMatch).getChildren()
              : ImmutableList.of(bodyToMatch);

      if (reverseMatch(element, currentIndexOfStar - 1, bodySequence)) {
        newChildren.set(currentIndexOfStar, mergeStarIntoPlus(starRuleName, starAst));
        for (int i = 0, size = bodySequence.size(); i < size; ++i) {
          newChildren.set(currentIndexOfStar - i - 1, null);
        }
        return currentIndexOfStar;
      }
      if (match(element, currentIndexOfStar + 1, bodySequence)) {
        newChildren.set(currentIndexOfStar, mergeStarIntoPlus(starRuleName, starAst));
        for (int i = 0, size = bodySequence.size(); i < size; ++i) {
          newChildren.set(currentIndexOfStar + i + 1, null);
        }
        return currentIndexOfStar + bodySequence.size();
      }
      if (bodyToMatch.getTag() == AstTag.RULE_REF) {
        ImmutableList<AbstractPersesRuleElement> defs =
            defMap.getRuleDefinition(((PersesRuleReferenceAst) bodyToMatch).getRuleNameHandle());
        if (defs.size() != 1) {
          return currentIndexOfStar;
        }
        AbstractPersesRuleElement def = Iterables.getOnlyElement(defs);
        return transformStarToPlus(
            element, currentIndexOfStar, newChildren, def, starRuleName, starAst);
      }
      return currentIndexOfStar;
    }

    @VisibleForTesting
    static boolean reverseMatch(
        PersesSequenceAst sequence,
        int startIndex,
        ImmutableList<AbstractPersesRuleElement> toMatchList) {
      final int length = toMatchList.size();
      return match(sequence, startIndex - length + 1, toMatchList);
    }

    @VisibleForTesting
    static boolean match(
        PersesSequenceAst sequence,
        int startIndex,
        ImmutableList<AbstractPersesRuleElement> toMatchList) {
      if (startIndex < 0 | startIndex >= sequence.getChildCount()) {
        return false;
      }
      for (int i = 0, size = toMatchList.size(); i < size; ++i) {
        final AbstractPersesRuleElement toMatch = toMatchList.get(i);
        final int indexInSeq = startIndex + i;
        if (indexInSeq >= sequence.getChildCount()) {
          return false;
        }
        if (!toMatch.isEquivalent(sequence.getChild(indexInSeq))) {
          return false;
        }
      }
      return true;
    }

    private PersesRuleReferenceAst mergeStarIntoPlus(
        RuleNameHandle starRuleName, PersesStarAst starAst) {
      final RuleNameHandle plusRuleName =
          starRuleName.createAuxiliaryRuleName(RuleType.KLEENE_PLUS);
      //      toRemove.put(starRuleName, starAst);
      toAdd.put(
          plusRuleName,
          starAst.isGreedy()
              ? PersesPlusAst.createGreedy(starAst.getBody())
              : PersesPlusAst.createNonGreedy(starAst.getBody()));
      return new PersesRuleReferenceAst(plusRuleName);
    }

    @VisibleForTesting
    Optional<PersesStarAst> getStarIfIsKleeneStarRule(RuleNameHandle ruleName) {
      ImmutableList<AbstractPersesRuleElement> defs = defMap.getRuleDefinition(ruleName);
      if (defs.size() != 1) {
        return Optional.empty();
      }
      AbstractPersesRuleElement def = Iterables.getOnlyElement(defs);
      if (def.getTag() != AstTag.STAR) {
        return Optional.empty();
      }
      return Optional.of((PersesStarAst) Iterables.getOnlyElement(defs));
    }
  }
}
