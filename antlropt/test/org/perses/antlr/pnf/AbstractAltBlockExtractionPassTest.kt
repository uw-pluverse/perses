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
import org.perses.antlr.GrammarTestingUtility.createSeqOfTerminalsFromChars
import org.perses.antlr.ast.PersesSequenceAst
import org.perses.antlr.pnf.AbstractAltBlockExtractionPass.Companion.computeCandidateInfix
import org.perses.antlr.pnf.AbstractAltBlockExtractionPass.Companion.computeCandidatesClosedPostfix
import org.perses.antlr.pnf.AbstractAltBlockExtractionPass.Companion.computeCandidatesClosedPrefix
import org.perses.antlr.pnf.AbstractAltBlockExtractionPass.Companion.selectBestCandidate
import org.perses.antlr.pnf.AltBlockExtractionPass.Companion.searchAssumingCommonPostfix
import org.perses.antlr.pnf.AltBlockExtractionPass.Companion.searchAssumingCommonPrefix
import org.perses.antlr.pnf.AltBlockExtractionPass.Companion.searchAssummingCommonPrefixAndPostfix

@RunWith(JUnit4::class)
class AbstractAltBlockExtractionPassTest {

  val s1 = createSeqOfTerminalsFromChars("abc")
  val s2 = createSeqOfTerminalsFromChars("aec")

  val s3 = createSeqOfTerminalsFromChars("abcXef")
  val s4 = createSeqOfTerminalsFromChars("abcYef")

  val s5 = createSeqOfTerminalsFromChars("abc")
  val s6 = createSeqOfTerminalsFromChars("abcd")

  @Test
  fun testOrder() {
    val originalSequences = listOf(s1, s2)
    val prefix = searchAssumingCommonPrefix(s1, s2)!!
    val postfix = searchAssumingCommonPostfix(s1, s2)!!
    val infix = searchAssummingCommonPrefixAndPostfix(
      prefix,
      postfix,
      originalSequences,
    )!!

    val result = selectBestCandidate(
      listOf(prefix, postfix, infix),
      originalSequences,
    )
    assertThat(result).isSameInstanceAs(infix)
  }

  private fun test_computeCandidatesClosedPrefix(
    s1: PersesSequenceAst,
    s2: PersesSequenceAst,
    expectedLength: Int,
  ): AbstractAltBlockExtractionPass.CommonPrefixCandidate {
    val candidates = computeCandidatesClosedPrefix(listOf(s1, s2))
    assertThat(candidates).hasSize(1)
    val candidate = candidates.first()
    assertThat(candidate.sequences).containsExactly(s1, s2)
    assertThat(candidate.prefixLength).isEqualTo(expectedLength)
    return candidate
  }

  private fun test_computeCandidatesClosedPostfix(
    s1: PersesSequenceAst,
    s2: PersesSequenceAst,
    expectedLength: Int,
  ): AbstractAltBlockExtractionPass.CommonPostfixCandidate {
    val candidates = computeCandidatesClosedPostfix(listOf(s1, s2))
    assertThat(candidates).hasSize(1)
    val candidate = candidates.first()
    assertThat(candidate.sequences).containsExactly(s1, s2)
    assertThat(candidate.postfixLength).isEqualTo(expectedLength)
    return candidate
  }

  @Test
  fun test_computeCandidates_s1_s2() {
    val left = test_computeCandidatesClosedPrefix(s1, s2, expectedLength = 1)
    val right = test_computeCandidatesClosedPostfix(s1, s2, expectedLength = 1)
    val infix = computeCandidateInfix(listOf(left), listOf(right), listOf(s1, s2))!!
    assertThat(infix.sequences).containsExactly(s1, s2).inOrder()
    assertThat(infix.prefixLength).isEqualTo(1)
    assertThat(infix.postfixLength).isEqualTo(1)
  }

  @Test
  fun test_computeCandidates_s3_s4() {
    val left = test_computeCandidatesClosedPrefix(s3, s4, expectedLength = 3)
    val right = test_computeCandidatesClosedPostfix(s3, s4, expectedLength = 2)
    val infix = computeCandidateInfix(listOf(left), listOf(right), listOf(s3, s4))!!
    assertThat(infix.sequences).containsExactly(s3, s4).inOrder()
    assertThat(infix.prefixLength).isEqualTo(3)
    assertThat(infix.postfixLength).isEqualTo(2)
  }

  @Test
  fun test_computeCandidatesClosed_s5_s6() {
    val left = listOf(test_computeCandidatesClosedPrefix(s5, s6, expectedLength = 3))
    val right = computeCandidatesClosedPostfix(listOf(s5, s6))
    assertThat(right).isEmpty()
    val infix = computeCandidateInfix(left, right, listOf(s5, s6))
    assertThat(infix).isNull()
  }
}
