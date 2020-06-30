/*
 * Copyright (C) 2018-2020 University of Waterloo.
 *
 * This file is part of Perses.
 *
 * Perses is free software; you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 3, or (at your option) any later version.
 *
 * Perses is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * Perses; see the file LICENSE.  If not see <http://www.gnu.org/licenses/>.
 */
package org.perses.antlr.pnf;

import com.google.common.annotations.VisibleForTesting;
import com.google.common.collect.ImmutableList;
import org.perses.antlr.RuleType;
import org.perses.antlr.ast.*;

import java.util.Comparator;
import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;

import static com.google.common.base.Preconditions.checkArgument;

public class OptionalIntroducerPass extends AbstractPnfPass {

  @Override
  public ImmutableRuleDefMap process(ImmutableRuleDefMap grammar) {
    MutableRuleDefMap mutable = grammar.createMutable();
    // To make the process deterministic.
    List<RuleNameRegistry.RuleNameHandle> ruleNameList = getSortedRuleNames(mutable);
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

  static Optional<Candidate> searchForCandidate(
      MutableRuleDefMap defMap, RuleNameRegistry.RuleNameHandle ruleName) {
    final List<AbstractPersesRuleElement> sortedSequenceDefs =
        defMap.get(ruleName).stream()
            .filter(Candidate::isSeqOrRuleRefOrTerminal)
            .sorted(Comparator.comparing(AbstractPersesAst::getSourceCode))
            .collect(Collectors.toList());
    final int size = sortedSequenceDefs.size();
    for (int i = 0; i < size - 1; ++i) {
      final CandidateElement<AbstractPersesRuleElement> first =
          Candidate.toCandidateElement(sortedSequenceDefs.get(i));
      for (int j = i + 1; j < size; ++j) {
        final CandidateElement<AbstractPersesRuleElement> second =
            Candidate.toCandidateElement(sortedSequenceDefs.get(j));
        if (first.size() == second.size()) {
          continue;
        }
        final CandidateElement<PersesSequenceAst> longSeq = getLongSequence(first, second);
        final CandidateElement<AbstractPersesRuleElement> shortSeq =
            getShortSequence(first, second);
        Optional<Interval> gapInLongSequence = findGapInLongSequence(longSeq, shortSeq);
        if (!gapInLongSequence.isPresent()) {
          continue;
        }
        return Optional.of(new Candidate(longSeq, shortSeq, gapInLongSequence.get()));
      }
    }
    return Optional.empty();
  }

  @VisibleForTesting
  static final class CandidateElement<T extends AbstractPersesRuleElement> {
    final T ast;
    final ImmutableList<AbstractPersesRuleElement> listRepresentation;

    private CandidateElement(T ast, ImmutableList<AbstractPersesRuleElement> listRepresentation) {
      this.ast = ast;
      this.listRepresentation = listRepresentation;
    }

    public int size() {
      return listRepresentation.size();
    }

    public AbstractPersesRuleElement getChild(int index) {
      return listRepresentation.get(index);
    }

    public CandidateElement<PersesSequenceAst> asSequence() {
      assert ast instanceof PersesSequenceAst;
      return new CandidateElement<>((PersesSequenceAst) ast, listRepresentation);
    }
  }

  @VisibleForTesting
  static final class Candidate {
    final CandidateElement<PersesSequenceAst> longSeq;
    final CandidateElement<AbstractPersesRuleElement> shortSeq;
    final Interval gapInLongSequence;

    private static boolean isSeqOrRuleRefOrTerminal(AbstractPersesRuleElement e) {
      switch (e.getTag()) {
        case SEQUENCE:
        case RULE_REF:
        case TERMINAL:
          return true;
        default:
          return false;
      }
    }

    @VisibleForTesting
    static CandidateElement<AbstractPersesRuleElement> toCandidateElement(
        AbstractPersesRuleElement e) {
      assert isSeqOrRuleRefOrTerminal(e);
      switch (e.getTag()) {
        case RULE_REF:
        case TERMINAL:
          return new CandidateElement<>(e, ImmutableList.of(e));
        case SEQUENCE:
          return new CandidateElement<>(e, ((PersesSequenceAst) e).getChildren());
      }
      throw new RuntimeException("Cannot reach here");
    }

    private Candidate(
        CandidateElement<PersesSequenceAst> longSeq,
        CandidateElement<AbstractPersesRuleElement> shortSeq,
        Interval gapInLongSequence) {
      this.longSeq = longSeq;
      this.shortSeq = shortSeq;
      this.gapInLongSequence = gapInLongSequence;
    }
  }

  private void mergeTwoSeqs(
      RuleNameRegistry.RuleNameHandle ruleName, MutableRuleDefMap mutable, Candidate candidate) {
    final AbstractPersesRuleElement gapAst =
        candidate.longSeq.ast.subsequence(
            candidate.gapInLongSequence.leftInclusive, candidate.gapInLongSequence.rightExclusive);
    mutable.remove(ruleName, candidate.shortSeq.ast);
    mutable.remove(ruleName, candidate.longSeq.ast);
    switch (gapAst.getTag()) {
      case STAR:
      case OPTIONAL:
        mutable.put(ruleName, candidate.longSeq.ast);
        break;
      case PLUS:
        {
          final RuleNameRegistry.RuleNameHandle starRuleName =
              ruleName.createAuxiliaryRuleName(RuleType.KLEENE_STAR);
          PersesStarAst starRuleDef =
              PersesStarAst.createGreedy(((PersesPlusAst) gapAst).getBody());
          mutable.put(starRuleName, starRuleDef);
          mutable.put(
              ruleName,
              replaceGapWithRuleReference(
                  candidate.longSeq.ast, candidate.gapInLongSequence, starRuleName));
          break;
        }
      case TERMINAL:
      case RULE_REF:
        {
          final RuleNameRegistry.RuleNameHandle optionalRuleName =
              ruleName.createAuxiliaryRuleName(RuleType.OPTIONAL);
          mutable.put(optionalRuleName, PersesOptionalAst.createGreedy(gapAst));
          mutable.put(
              ruleName,
              replaceGapWithRuleReference(
                  candidate.longSeq.ast, candidate.gapInLongSequence, optionalRuleName));
          break;
        }
      default:
        {
          final RuleNameRegistry.RuleNameHandle wrapperRuleName =
              ruleName.createAuxiliaryRuleName(RuleType.OTHER_RULE);
          mutable.put(wrapperRuleName, gapAst);
          final RuleNameRegistry.RuleNameHandle optionalRuleName =
              ruleName.createAuxiliaryRuleName(RuleType.OPTIONAL);
          mutable.put(
              optionalRuleName,
              PersesOptionalAst.createGreedy(new PersesRuleReferenceAst(wrapperRuleName)));
          mutable.put(
              ruleName,
              replaceGapWithRuleReference(
                  candidate.longSeq.ast, candidate.gapInLongSequence, optionalRuleName));
          break;
        }
    }
  }



  private static CandidateElement<PersesSequenceAst> getLongSequence(
      CandidateElement<AbstractPersesRuleElement> a,
      CandidateElement<AbstractPersesRuleElement> b) {
    return (a.size() > b.size() ? a : b).asSequence();
  }

  private static CandidateElement<AbstractPersesRuleElement> getShortSequence(
      CandidateElement<AbstractPersesRuleElement> a,
      CandidateElement<AbstractPersesRuleElement> b) {
    return a.size() < b.size() ? a : b;
  }

  @VisibleForTesting
  static Optional<Interval> findGapInLongSequence(
      CandidateElement<PersesSequenceAst> longSeq,
      CandidateElement<AbstractPersesRuleElement> shortSeq) {
    final int longSize = longSeq.size();
    final int shortSize = shortSeq.size();
    checkArgument(longSize > shortSize);

    int longIndex = 0;
    int shortIndex = 0;
    while (longIndex < longSize
        && shortIndex < shortSize
        && longSeq.getChild(longIndex).isEquivalent(shortSeq.getChild(shortIndex))) {
      ++longIndex;
      ++shortIndex;
    }
    final int intervalStart = longIndex;
    final int intervalEnd = shortIndex + longSize - shortSize;
    while (shortIndex < shortSize) {
      if (!longSeq
          .getChild(shortIndex + longSize - shortSize)
          .isEquivalent(shortSeq.getChild(shortIndex))) {
        return Optional.empty();
      }
      ++shortIndex;
    }
    return Optional.of(new Interval(intervalStart, intervalEnd));
  }
}
