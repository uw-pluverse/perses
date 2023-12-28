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

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.antlr.GrammarTestingUtility.createPersesGrammarFromString
import org.perses.antlr.GrammarTestingUtility.createSeqOfTerminals
import org.perses.antlr.GrammarTestingUtility.createTerminal
import org.perses.antlr.ast.PersesGrammar
import org.perses.antlr.pnf.OptionalExtractionUtil.findGapInLongSequence
import org.perses.util.Interval
import org.perses.antlr.pnf.OptionalExtractionUtil.CandidateElement.Companion.create as createCandidateElement

@RunWith(JUnit4::class)
class OptionalIntroducerPassTest {
  private var pass = OptionalIntroducerPass()

  @Test
  fun testOptionalIntroducerPass_simple_optional() {
    val newMap = processGrammar("s: a b c | a c ;")
    val s = newMap.getRuleDefinition("s")!!.body
    assertThat(s.sourceCode).isEqualTo("a optional__s_1 c")
    val optional__s_1 = newMap.getRuleDefinition("optional__s_1")!!.body
    assertThat(optional__s_1.sourceCode).isEqualTo("b?")
    assertThat(newMap.parserRuleNameList).hasSize(2)
  }

  @Test
  fun testOptionalIntroducerPass_optional_star() {
    val newMap = processGrammar("s: a b* c | a c ;")
    val s = newMap.getRuleDefinition("s")!!.body
    assertThat(s.sourceCode).isEqualTo("a b* c")
    assertThat(newMap.parserRuleNameList).hasSize(1)
  }

  @Test
  fun testOptionalIntroducerPass_optional_plus() {
    val newMap = processGrammar("s: a b+ c | a c ;")
    val s = newMap.getRuleDefinition("s")!!.body
    assertThat(s.sourceCode).isEqualTo("a kleene_star__s_1 c")
    val kleene_star__s_1 = newMap.getRuleDefinition("kleene_star__s_1")!!.body
    assertThat(kleene_star__s_1.sourceCode).isEqualTo("b*")
    assertThat(newMap.parserRuleNameList).hasSize(2)
  }

  @Test
  fun testOptionalIntroducerPass_optional_optional() {
    val newMap = processGrammar("s: a b? c | a c ;")
    val s = newMap.getRuleDefinition("s")!!.body
    assertThat(s.sourceCode).isEqualTo("a b? c")
    assertThat(newMap.parserRuleNameList).hasSize(1)
  }

  fun processGrammar(vararg lines: String): PersesGrammar {
    val grammar = createPersesGrammarFromString(*lines)
    return pass.processGrammar(GrammarPair(grammar, lexerGrammar = null)).parserGrammar!!
  }

  @Test
  fun testFindGapInLongSequence_gap_in_the_front() {
    val longSeq = arrayOf("a", "b", "c", "b", "c", "b", "c")
    val shortSeq = arrayOf("b", "c")
    val gapInLongSequence = findGapInSequences(longSeq, shortSeq)!!
    assertThat(gapInLongSequence).isNotNull()
    assertThat(gapInLongSequence.leftInclusive).isEqualTo(0)
    assertThat(gapInLongSequence.rightExclusive).isEqualTo(5)
  }

  @Test
  fun testFindGapInLongSequence_gap_in_the_back() {
    val longSeq = arrayOf("a", "b", "c", "a", "b")
    val shortSeq = arrayOf("a", "b")
    val gapInLongSequence = findGapInSequences(longSeq, shortSeq)!!
    assertThat(gapInLongSequence).isNotNull()
    assertThat(gapInLongSequence.leftInclusive).isEqualTo(2)
    assertThat(gapInLongSequence.rightExclusive).isEqualTo(5)
  }

  @Test
  fun testFindGapInLongSequence_gap_in_the_middle() {
    val longSeq = arrayOf("a", "b", "a", "c", "a", "c")
    val shortSeq = arrayOf("a", "c")
    val gapInLongSequence = findGapInSequences(longSeq, shortSeq)!!
    assertThat(gapInLongSequence.leftInclusive).isEqualTo(1)
    assertThat(gapInLongSequence.rightExclusive).isEqualTo(5)
  }

  @Test
  fun testFindGapInLongSequence_multiple_gaps_in_the_front() {
    val longSeq = arrayOf("a", "b", "c", "d")
    val shortSeq = arrayOf("b", "d")
    val gapInLongSequence = findGapInSequences(longSeq, shortSeq)
    assertThat(gapInLongSequence).isNull()
  }

  @Test
  fun testFindGapInLongSequence_multiple_gaps_in_the_middle() {
    val longSeq = arrayOf("a", "b", "c", "d", "e")
    val shortSeq = arrayOf("a", "c", "e")
    val gapInLongSequence = findGapInSequences(longSeq, shortSeq)
    assertThat(gapInLongSequence).isNull()
  }

  @Test
  fun testFindGapInLongSequence_multiple_gaps_in_the_back() {
    val gapInLongSequence = findGapInSequences(
      arrayOf("a", "b", "c", "d", "e"),
      arrayOf("a", "c", "d"),
    )
    assertThat(gapInLongSequence).isNull()
  }

  @Test
  fun testFindGapBetweenSeqAndTerminal_front() {
    val gapInLongSequence = findGapBetweenSequenceAndTerminal(arrayOf("a", "b"), "a")!!
    assertThat(gapInLongSequence).isNotNull()
    assertThat(gapInLongSequence.leftInclusive).isEqualTo(1)
    assertThat(gapInLongSequence.rightExclusive).isEqualTo(2)
  }

  @Test
  fun testFindGapBetweenSeqAndTerminal_back() {
    val gapInLongSequence = findGapBetweenSequenceAndTerminal(arrayOf("a", "b"), "b")!!
    assertThat(gapInLongSequence).isNotNull()
    assertThat(gapInLongSequence.leftInclusive).isEqualTo(0)
    assertThat(gapInLongSequence.rightExclusive).isEqualTo(1)
  }

  @Test
  fun testFindGapBetweenSeqAndTerminal_none() {
    val gapInLongSequence = findGapBetweenSequenceAndTerminal(arrayOf("a", "b"), "c")
    assertThat(gapInLongSequence).isNull()
  }

  companion object {
    private fun findGapBetweenSequenceAndTerminal(
      longSeqOfTerminals: Array<String>,
      terminal: String,
    ): Interval? {
      val longSeq = createCandidateElement(
        createSeqOfTerminals(*longSeqOfTerminals),
      )
        .asSequence()
      val shortSeq = createCandidateElement(
        createTerminal(terminal),
      )
      return findGapInLongSequence(longSeq, shortSeq)
    }

    private fun findGapInSequences(
      longSeqOfTerminals: Array<String>,
      shortSeqOfTerminals: Array<String>,
    ): Interval? {
      val longSeq = createCandidateElement(
        createSeqOfTerminals(*longSeqOfTerminals),
      ).asSequence()
      val shortSeq = createCandidateElement(
        createSeqOfTerminals(*shortSeqOfTerminals),
      )
      return findGapInLongSequence(longSeq, shortSeq)
    }
  }
}
