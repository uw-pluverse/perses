package org.perses.antlr.pnf;

import com.google.common.annotations.VisibleForTesting;
import com.google.common.collect.ImmutableList;
import org.perses.antlr.RuleType;
import org.perses.antlr.ast.*;

import java.util.Comparator;
import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;

public class AlternativeBlockOutliningPass extends AbstractPnfPass {

  @Override
  public ImmutableRuleDefMap process(ImmutableRuleDefMap grammar) {
    MutableRuleDefMap mutable = grammar.createMutable();
    final List<RuleNameRegistry.RuleNameHandle> ruleNameList = getSortedRuleNames(mutable);
    for (RuleNameRegistry.RuleNameHandle ruleName : ruleNameList) {
      while (true) {
        final Optional<Candidate> candidate = searchForCandidate(mutable, ruleName);
        if (!candidate.isPresent()) {
          break;
        }
        mergeTwoSeqs(ruleName, mutable, candidate.get());
      }
    }
    return grammar.createWithParserDefs(mutable);
  }

  private void mergeTwoSeqs(
      RuleNameRegistry.RuleNameHandle ruleName, MutableRuleDefMap mutable, Candidate candidate) {
    mutable.remove(ruleName, candidate.s1);
    mutable.remove(ruleName, candidate.s2);

    RuleNameRegistry.RuleNameHandle altBlockName =
        ruleName.createAuxiliaryRuleName(RuleType.ALT_BLOCKS);
    List<AbstractPersesRuleElement> alternatives =
        constructAlternativeBlocksIfNecessary(candidate.extractedGaps);
    alternatives.forEach(alt -> mutable.put(altBlockName, alt));
    final PersesRuleReferenceAst ruleRef = new PersesRuleReferenceAst(altBlockName);
    final AbstractPersesRuleElement newSeq1 =
        replaceGapWithRuleReference(candidate.s1, candidate.gapInS1, altBlockName);
    final AbstractPersesRuleElement newSeq2 =
        replaceGapWithRuleReference(candidate.s2, candidate.gapInS2, altBlockName);
    assert newSeq1.isEquivalent(newSeq2);
    mutable.put(ruleName, newSeq1);
  }

  static Optional<Candidate> searchForCandidate(
      MutableRuleDefMap defMap, RuleNameRegistry.RuleNameHandle ruleName) {
    List<PersesSequenceAst> sortedSequenceDefs =
        defMap.get(ruleName).stream()
            .filter(e -> e.getTag() == AstTag.SEQUENCE)
            .sorted(Comparator.comparing(AbstractPersesAst::getSourceCode))
            .map(e -> (PersesSequenceAst) e)
            .collect(Collectors.toList());
    final int size = sortedSequenceDefs.size();
    for (int i = 0; i < size - 1; ++i) {
      final PersesSequenceAst first = sortedSequenceDefs.get(i);
      for (int j = i + 1; j < size; ++j) {
        final PersesSequenceAst second = sortedSequenceDefs.get(j);
        final Optional<Candidate> candidate = searchForCandidate(first, second);
        if (candidate.isPresent()) {
          return candidate;
        }
      }
    }
    return Optional.empty();
  }

  @VisibleForTesting
  static Optional<Candidate> searchForCandidate(PersesSequenceAst s1, PersesSequenceAst s2) {
    final Optional<Candidate> left = searchAssumingCommonPrefix(s1, s2);
    final Optional<Candidate> right = searchAssumingCommonPostfix(s1, s2);
    final Optional<Candidate> infix = searchAssummingCommonPrefixAndPostfix(left, right);
    if (infix.isPresent()) {
      return infix;
    }
    if (left.isPresent()) {
      assert !right.isPresent();
      return left;
    }
    if (right.isPresent()) {
      assert !left.isPresent();
      return right;
    }
    return Optional.empty();
  }

  private static Optional<Candidate> searchAssumingCommonPrefix(
      PersesSequenceAst s1, PersesSequenceAst s2) {
    final int size1 = s1.getChildCount();
    final int size2 = s2.getChildCount();
    int i = 0;
    while (i < size1 && i < size2 && s1.getChild(i).isEquivalent(s2.getChild(i))) {
      ++i;
    }
    if (i == 0) {
      // No common prefix
      return Optional.empty();
    }
    if (i == size1 || i == size2) {
      // a subsequence, no interest
      return Optional.empty();
    }
    return Optional.of(new Candidate(s1, s2, new Interval(i, size1), new Interval(i, size2)));
  }

  private static Optional<Candidate> searchAssumingCommonPostfix(
      PersesSequenceAst s1, PersesSequenceAst s2) {
    final int size1 = s1.getChildCount();
    final int size2 = s2.getChildCount();
    int i = 1;
    while (size1 - i >= 0
        && size2 - i >= 0
        && s1.getChild(size1 - i).isEquivalent(s2.getChild(size2 - i))) {
      ++i;
    }
    if (i == 1) {
      // No common postfix;
      return Optional.empty();
    }
    if (size1 - i < 0 || size2 - i < 0) {
      // a subsequence, no interest.
      return Optional.empty();
    }
    return Optional.of(
        new Candidate(s1, s2, new Interval(0, size1 - i + 1), new Interval(0, size2 - i + 1)));
  }

  private static Optional<Candidate> searchAssummingCommonPrefixAndPostfix(
      Optional<Candidate> left, Optional<Candidate> right) {
    if (!left.isPresent()) {
      return Optional.empty();
    }
    if (!right.isPresent()) {
      return Optional.empty();
    }
    final Candidate leftCandidate = left.get();
    final Candidate rightCandidate = right.get();
    assert leftCandidate.s1 == rightCandidate.s1;
    assert leftCandidate.s2 == rightCandidate.s2;
    return Optional.of(
        new Candidate(
            leftCandidate.s1,
            leftCandidate.s2,
            new Interval(
                leftCandidate.gapInS1.leftInclusive, rightCandidate.gapInS1.rightExclusive),
            new Interval(
                leftCandidate.gapInS2.leftInclusive, rightCandidate.gapInS2.rightExclusive)));
  }

  @VisibleForTesting
  static final class Candidate {
    final PersesSequenceAst s1;
    final PersesSequenceAst s2;
    final Interval gapInS1;
    final Interval gapInS2;
    final ImmutableList<AbstractPersesRuleElement> extractedGaps;

    Candidate(PersesSequenceAst s1, PersesSequenceAst s2, Interval gapInS1, Interval gapInS2) {
      this.s1 = s1;
      this.s2 = s2;
      this.gapInS1 = gapInS1;
      this.gapInS2 = gapInS2;

      assert checkValidity();

      extractedGaps = extractGaps();
    }

    private ImmutableList<AbstractPersesRuleElement> extractGaps() {
      final ImmutableList.Builder<AbstractPersesRuleElement> builder =
          ImmutableList.builderWithExpectedSize(2);
      builder.add(s1.subsequence(gapInS1.leftInclusive, gapInS1.rightExclusive));
      builder.add(s2.subsequence(gapInS2.leftInclusive, gapInS2.rightExclusive));
      return builder.build();
    }

    private boolean checkValidity() {
      int i = 0, j = 0;
      final int size1 = s1.getChildCount();
      final int size2 = s2.getChildCount();
      while (i < size1 || j < size2) {
        if (gapInS1.contains(i)) {
          i = gapInS1.rightExclusive;
          continue;
        }
        if (gapInS2.contains(j)) {
          j = gapInS2.rightExclusive;
          continue;
        }
        assert s1.getChild(i).isEquivalent(s2.getChild(j));
        ++i;
        ++j;
      }
      assert i == size1 : String.format("%d, %d", i, size1);
      assert j == size2 : String.format("%d, %d", j, size2);
      return true;
    }
  }
}
