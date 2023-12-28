/*
 * Copyright (C) 2018-2024 University of Waterloo.
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
package org.perses.antlr.pnf

import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableMap
import org.perses.antlr.RuleType
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.AstTag
import org.perses.antlr.ast.PersesSequenceAst
import org.perses.antlr.ast.RuleNameRegistry
import org.perses.antlr.ast.RuleNameRegistry.RuleNameHandle
import org.perses.util.Interval

abstract class AbstractAltBlockExtractionPass : AbstractPnfPass() {

  final override fun processGrammar(
    grammar: GrammarPair,
  ): GrammarPair {
    val parserGrammar = grammar.parserGrammar ?: return grammar
    val mutable = MutableGrammar.createParserRulesFrom(parserGrammar)
    var changed: Boolean
    do {
      changed = false
      val ruleNameList = getSortedRuleNames(mutable)
      for (ruleName in ruleNameList) {
        while (true) {
          val sequences = getAllSequences(mutable, ruleName)
          if (sequences.size < 2) {
            break
          }
          val candidate = searchForCandidate(sequences) ?: break
          candidate.apply(ruleName, mutable)
          changed = true
        }
      }
    } while (changed)
    return grammar.withNewParserGrammar(
      parserGrammar.copyWithNewParserRuleDefs(mutable.toParserRuleAstList()),
    )
  }

  abstract fun searchForCandidate(sequences: List<PersesSequenceAst>): AbstractCandidate?

  abstract class AbstractCandidate(
    val sequences: List<PersesSequenceAst>,
  ) {

    init {
      require(sequences.size > 1) { sequences }
    }

    fun apply(ruleName: RuleNameHandle, grammar: MutableGrammar) {
      sequences.forEach { grammar.getAltBlock(ruleName).removeAlt(it) }
      val alternatives = AstUtil.flattenAndDeduplicateAlternatives(
        getGapsToDelete(),
      )
      check(alternatives.size > 1)
      val altBlockName = ruleName.createAuxiliaryRuleName(RuleType.ALT_BLOCKS)

      grammar.getAltBlock(altBlockName).addAllIfInequivalent(alternatives)
      val processedSequences = sequences
        .map { replaceGapWithRuleReference(it, getGapInterval(it), altBlockName) }
      check(processedSequences.size == sequences.size)
      processedSequences.forEach { processedSequences.first().isEquivalent(it) }
      grammar.getAltBlock(ruleName).addIfNotEquivalent(processedSequences.first())
    }

    abstract fun getGapInterval(sequence: PersesSequenceAst): Interval

    fun getGapsToDelete(): List<AbstractPersesRuleElement> {
      return sequences.map {
        val interval = getGapInterval(it)
        it.subsequence(interval.leftInclusive, interval.rightExclusive)
      }
    }
  }

  class CommonPrefixCandidate(
    sequences: List<PersesSequenceAst>,
    val prefixLength: Int,
  ) : AbstractCandidate(sequences) {

    init {
      require(prefixLength > 0)
    }

    override fun getGapInterval(sequence: PersesSequenceAst): Interval {
      return Interval(prefixLength, sequence.childCount)
    }
  }

  class CommonPostfixCandidate(
    sequences: List<PersesSequenceAst>,
    val postfixLength: Int,
  ) : AbstractCandidate(sequences) {

    init {
      require(postfixLength > 0)
    }

    override fun getGapInterval(sequence: PersesSequenceAst): Interval {
      return Interval(0, sequence.childCount - postfixLength)
    }
  }

  class InfixCandidate(
    sequences: List<PersesSequenceAst>,
    val prefixLength: Int,
    val postfixLength: Int,
  ) : AbstractCandidate(sequences) {
    init {
      require(prefixLength > 0)
      require(postfixLength > 0)
    }

    override fun getGapInterval(sequence: PersesSequenceAst): Interval {
      return Interval(prefixLength, sequence.childCount - postfixLength)
    }
  }

  companion object {

    fun getAllSequences(
      defMap: MutableGrammar,
      ruleName: RuleNameRegistry.RuleNameHandle,
    ): List<PersesSequenceAst> {
      return defMap.getAltBlock(ruleName)
        .asSequence()
        .filter { it.tag == AstTag.SEQUENCE }
        .map { it as PersesSequenceAst }
        .toList()
    }

    private val candidateTypePreferenceGreatestToLeast = ImmutableList.of(
      InfixCandidate::class.java,
      CommonPrefixCandidate::class.java,
      CommonPostfixCandidate::class.java,
    )

    private fun createCandidateComparator(
      tiebreaker: ImmutableMap<AbstractCandidate, TieBreaker>,
    ) = compareByDescending<AbstractCandidate> {
      it.sequences.size
    }.thenComparingInt {
      check(candidateTypePreferenceGreatestToLeast.contains(it::class.java))
      candidateTypePreferenceGreatestToLeast.indexOf(it::class.java)
    }.thenBy {
      tiebreaker[it]!!
    }

    fun <T : AbstractCandidate> selectBestCandidate(
      candidates: List<T>,
      originalSequences: List<PersesSequenceAst>,
    ): T? {
      if (candidates.isEmpty()) {
        return null
      }
      val maxSequenceCount = candidates.map { it.sequences.size }.maxOrNull()!!
      val tieBreakers = createTieBreakers(candidates, originalSequences)
      return candidates
        .filter { it.sequences.size == maxSequenceCount }
        .minWithOrNull(createCandidateComparator(tieBreakers))
    }

    private data class TieBreaker(
      val minIndex: Int,
      val continuity: Int,
    ) : Comparable<TieBreaker> {

      override fun compareTo(other: TieBreaker): Int {
        return compareBy<TieBreaker> { it.continuity }.thenBy { it.minIndex }.compare(this, other)
      }
    }

    private fun createTieBreakers(
      candidates: List<AbstractCandidate>,
      originalSequences: List<PersesSequenceAst>,
    ): ImmutableMap<AbstractCandidate, TieBreaker> {
      val builder = ImmutableMap.builder<AbstractCandidate, TieBreaker>()
      candidates.forEach { candidate ->
        val indices = candidate.sequences
          .asSequence()
          .map { originalSequences.indexOf(it).apply { check(this >= 0) } }
          .sorted()
          .toList()
        val continuity = indices
          .zipWithNext()
          .map { (first, second) -> second - first }
          .sum()
        builder.put(candidate, TieBreaker(minIndex = indices.first(), continuity))
      }
      return builder.build()
    }

    private abstract class AbstractDirection {
      abstract fun getElement(seq: PersesSequenceAst, index: Int): AbstractPersesRuleElement
    }

    private object ForwardDirection : AbstractDirection() {
      override fun getElement(seq: PersesSequenceAst, index: Int): AbstractPersesRuleElement {
        return seq.getChild(index)
      }
    }

    private object BackwardDirection : AbstractDirection() {
      override fun getElement(seq: PersesSequenceAst, index: Int): AbstractPersesRuleElement {
        return seq.getChild(seq.childCount - index - 1)
      }
    }

    private class PrefixSequenceEntry(
      prefix: AbstractPersesRuleElement,
      sequence: PersesSequenceAst,
      val direction: AbstractDirection,
    ) {

      private val prefix = ArrayList<AbstractPersesRuleElement>().apply {
        add(prefix)
      }
      private val sequences = ArrayList<PersesSequenceAst>().apply {
        add(sequence)
      }

      fun isEquivalentToPrefix(other: AbstractPersesRuleElement): Boolean {
        check(prefix.size == 1)
        return prefix.first().isEquivalent(other)
      }

      fun addSequence(s: PersesSequenceAst) {
        check(prefix.size == 1)
        check(prefix.first().isEquivalent(direction.getElement(s, 0))) {
          "${prefix.first().sourceCode}  ${s.sourceCode}"
        }
        sequences.add(s)
      }

      fun cloneSequences(): ImmutableList<PersesSequenceAst> = ImmutableList.copyOf(sequences)

      val prefixLength: Int
        get() = prefix.size

      val countOfSequences: Int
        get() = sequences.size

      fun maximizePrefix() {
        var i = prefix.size
        val minSequenceLength = sequences.map { it.childCount }.minOrNull()!!
        while (i < minSequenceLength) {
          val equivalentClasses = AstUtil.findEquivalenceAst(
            sequences.map { direction.getElement(it, i) }.toList(),
          )
          ++i
          if (equivalentClasses.size == 1) {
            prefix.add(equivalentClasses.first().representative)
          } else {
            break
          }
        }
      }
    }

    fun computeCandidatesClosedPrefix(
      sequences: List<PersesSequenceAst>,
    ): List<CommonPrefixCandidate> {
      return computeCandidatesClosedPrefixOrPostfix(
        sequences,
        ForwardDirection,
      ) { sequencesList, lengthOfPrefix ->
        CommonPrefixCandidate(sequencesList, lengthOfPrefix)
      }
    }

    fun computeCandidatesClosedPostfix(
      sequences: List<PersesSequenceAst>,
    ): List<CommonPostfixCandidate> {
      return computeCandidatesClosedPrefixOrPostfix(
        sequences,
        BackwardDirection,
      ) { sequencesList, lengthOfPrefix ->
        CommonPostfixCandidate(sequencesList, lengthOfPrefix)
      }
    }

    fun computeCandidateInfix(
      prefixCandidates: List<CommonPrefixCandidate>,
      postfixCandidates: List<CommonPostfixCandidate>,
      originalSequences: List<PersesSequenceAst>,
    ): InfixCandidate? {
      val bestPrefixCandidate =
        selectBestCandidate(prefixCandidates, originalSequences) ?: return null
      val bestPostfixCandidate =
        selectBestCandidate(postfixCandidates, originalSequences) ?: return null
      return if (bestPrefixCandidate.sequences == bestPostfixCandidate.sequences) {
        InfixCandidate(
          bestPrefixCandidate.sequences,
          prefixLength = bestPrefixCandidate.prefixLength,
          postfixLength = bestPostfixCandidate.postfixLength,
        )
      } else {
        null
      }
    }

    private fun <T : AbstractCandidate> computeCandidatesClosedPrefixOrPostfix(
      sequences: List<PersesSequenceAst>,
      direction: AbstractDirection,
      candidateCreator: (List<PersesSequenceAst>, Int) -> T,
    ): List<T> {
      val firstBatch = ArrayList<PrefixSequenceEntry>()
      sequences.forEach { s ->
        val prefix = direction.getElement(s, 0)
        val existing = firstBatch.find { it.isEquivalentToPrefix(prefix) }
        if (existing == null) {
          firstBatch.add(PrefixSequenceEntry(prefix, s, direction))
        } else {
          existing.addSequence(s)
        }
      }
      return firstBatch.onEach { it.maximizePrefix() }
        .filter { it.countOfSequences > 1 }
        .map { candidateCreator(it.cloneSequences(), it.prefixLength) }
        .toList()
    }
  }
}
