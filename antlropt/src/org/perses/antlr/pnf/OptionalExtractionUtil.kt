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
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.AstTag
import org.perses.antlr.ast.PersesSequenceAst
import org.perses.antlr.ast.SmartAstConstructor
import org.perses.antlr.pnf.AstUtil.fixpoint
import org.perses.antlr.pnf.AstUtil.isSeqOrRuleRefOrTerminal
import org.perses.util.Interval

object OptionalExtractionUtil {

  class Candidate(
    val longSeq: CandidateElement<PersesSequenceAst>,
    val shortSeq: CandidateElement<AbstractPersesRuleElement>,
    val gapInLongSequence: Interval,
  ) {

    fun getGapAst(): AbstractPersesRuleElement {
      return longSeq.ast.subsequence(
        gapInLongSequence.leftInclusive,
        gapInLongSequence.rightExclusive,
      )
    }
  }

  class CandidateElement<T : AbstractPersesRuleElement>(
    val ast: T,
    val listRepresentation: ImmutableList<AbstractPersesRuleElement>,
  ) {

    fun size(): Int {
      return listRepresentation.size
    }

    fun getChild(index: Int): AbstractPersesRuleElement {
      return listRepresentation[index]
    }

    fun asSequence(): CandidateElement<PersesSequenceAst> {
      assert(ast is PersesSequenceAst)
      return CandidateElement(ast as PersesSequenceAst, listRepresentation)
    }

    companion object {
      fun create(
        e: AbstractPersesRuleElement,
      ): CandidateElement<AbstractPersesRuleElement> {
        assert(isSeqOrRuleRefOrTerminal(e))
        return when (e.tag) {
          AstTag.RULE_REF,
          AstTag.TERMINAL,
          AstTag.UNKNOWN_TERMINAL_WITH_UNIT_PRECEDENCE,
          -> CandidateElement(e, ImmutableList.of(e))
          AstTag.SEQUENCE -> CandidateElement(e, (e as PersesSequenceAst).children)
          else -> error("Cannot reach here")
        }
      }
    }
  }

  fun rewriteAltBlockByExtractingOptionals(
    alternatives: List<AbstractPersesRuleElement>,
  ): AbstractPersesRuleElement {
    val mutableAltBlock = MutableAltBlock()
    alternatives.forEach {
      mutableAltBlock.decomposeAltBlockAndAddIfInequivalent(it)
    }
    return fixpoint(mutableAltBlock) { block ->
      val candidate = searchForCandidate(block.asIterable()) ?: return@fixpoint block
      val newBlock = block.copy()
      newBlock.removeAlt(candidate.shortSeq.ast)
      val gapAst = candidate.getGapAst()
      val replacement = SmartAstConstructor.createForOptional(gapAst, isGreedy = true)
      assert(replacement.tag == AstTag.OPTIONAL || replacement.tag == AstTag.STAR)
      val newAlt = AstUtil.replaceGapInSequence(
        candidate.longSeq.ast,
        candidate.gapInLongSequence,
        replacement,
      )
      if (!newAlt.isEquivalent(candidate.longSeq.ast)) {
        newBlock.replace(candidate.longSeq.ast, newAlt)
      }
      newBlock
    }.asRuleBody()
  }

  fun searchForCandidate(
    alternatives: Iterable<AbstractPersesRuleElement>,
  ): Candidate? {
    val sortedSequenceDefs = alternatives
      .asSequence()
      .filter { isSeqOrRuleRefOrTerminal(it) }
      .sortedBy { it.sourceCode }
      .toList()
    val size = sortedSequenceDefs.size
    for (i in 0 until size - 1) {
      val first = CandidateElement.create(sortedSequenceDefs[i])
      for (j in i + 1 until size) {
        val second = CandidateElement.create(sortedSequenceDefs[j])
        if (first.size() == second.size()) {
          continue
        }
        val longSeq = getLongSequence(first, second)
        val shortSeq = getShortSequence(first, second)
        assert(longSeq.ast !== shortSeq.ast)
        val gapInLongSequence = findGapInLongSequence(longSeq, shortSeq) ?: continue
        return Candidate(longSeq, shortSeq, gapInLongSequence)
      }
    }
    return null
  }

  private fun getLongSequence(
    a: CandidateElement<AbstractPersesRuleElement>,
    b: CandidateElement<AbstractPersesRuleElement>,
  ): CandidateElement<PersesSequenceAst> {
    assert(a.size() != b.size())
    return (if (a.size() > b.size()) a else b).asSequence()
  }

  private fun getShortSequence(
    a: CandidateElement<AbstractPersesRuleElement>,
    b: CandidateElement<AbstractPersesRuleElement>,
  ): CandidateElement<AbstractPersesRuleElement> {
    assert(a.size() != b.size())
    return if (a.size() < b.size()) a else b
  }

  fun findGapInLongSequence(
    longSeq: CandidateElement<PersesSequenceAst>,
    shortSeq: CandidateElement<AbstractPersesRuleElement>,
  ): Interval? {
    val longSize = longSeq.size()
    val shortSize = shortSeq.size()
    require(longSize > shortSize)
    var longIndex = 0
    var shortIndex = 0
    while (longIndex < longSize &&
      shortIndex < shortSize &&
      longSeq.getChild(longIndex).isEquivalent(shortSeq.getChild(shortIndex))
    ) {
      ++longIndex
      ++shortIndex
    }
    val intervalStart = longIndex
    val intervalEnd = shortIndex + longSize - shortSize
    while (shortIndex < shortSize) {
      if (!longSeq.getChild(shortIndex + longSize - shortSize)
          .isEquivalent(shortSeq.getChild(shortIndex))
      ) {
        return null
      }
      ++shortIndex
    }
    return Interval(intervalStart, intervalEnd)
  }
}
