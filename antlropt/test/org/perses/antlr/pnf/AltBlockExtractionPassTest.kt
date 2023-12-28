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
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.antlr.GrammarTestingUtility
import org.perses.antlr.GrammarTestingUtility.computeAltblockRuleName
import org.perses.antlr.GrammarTestingUtility.createPersesGrammarFromString
import org.perses.antlr.ast.PersesAlternativeBlockAst
import org.perses.antlr.ast.PersesGrammar
import org.perses.antlr.pnf.AbstractAltBlockExtractionPass.AbstractCandidate
import org.perses.util.toImmutableList

@RunWith(JUnit4::class)
class AltBlockExtractionPassTest {

  private var pass = AltBlockExtractionPass()

  @Test
  fun e2eTest_2_alternatives() {
    val origGrammar = createPersesGrammarFromString(
      """
      s : a c d | a b d;
      """.trimIndent(),
    )
    val processedGrammar = pass.processGrammar(
      GrammarPair(parserGrammar = origGrammar, lexerGrammar = null),
    ).parserGrammar!!
    val auxRuleName = computeAltblockRuleName("s_1")
    /*
     * DO NOT MODIFY THE ORDER OF ALTERNATIVES.
     *
     * Note that the auxiliary rule should be exactly 'c | b'.
     * The order of the two alternatives should be exactly the
     * same as that in its original grammar.
     */
    val goldenGrammar = createPersesGrammarFromString(
      """
      s : a $auxRuleName d;
      $auxRuleName : c | b; 
      """.trimIndent(),
    )
    GrammarTestingUtility.checkWithGoldenGrammar(
      processedGrammar.sourceCode,
      goldenGrammar.sourceCode,
    )
  }

  @Test
  fun testAlternativeBlockOutliningPass() {
    val processed = process("a: a c d | a b d;")
    val a = processed.getRuleDefinition("a")!!.body
    assertThat(a).isNotInstanceOf(PersesAlternativeBlockAst::class.java)
    assertThat(a.sourceCode)
      .isEqualTo("a ${computeAltblockRuleName("a_1")} d")
    val alternative__a_1 = processed.getRuleDefinition(
      computeAltblockRuleName("a_1"),
    )!!.body
    check(alternative__a_1 is PersesAlternativeBlockAst) { alternative__a_1 }
    assertThat(alternative__a_1.alternatives).hasSize(2)
    assertThat(
      alternative__a_1.alternatives
        .asSequence()
        .map { it.sourceCode }
        .toImmutableList(),
    )
      .containsExactly("b", "c")
    assertThat(processed.flattenedAllRules).hasSize(2)
  }

  private fun process(vararg grammarLines: String): PersesGrammar {
    val grammar = createPersesGrammarFromString(*grammarLines)
    return pass.processGrammar(
      GrammarPair(parserGrammar = grammar, lexerGrammar = null),
    ).parserGrammar!!
  }

  @Test
  fun testsearchAssumingCommonPrefix_equal_length() {
    val r = search("ab", "ac")
    assertThat(r).isNotNull()
    val c = r!!

    val first = c.sequences.first()
    val second = c.sequences.last()
    assertThat(first.sourceCode).isEqualTo("a b")
    assertThat(second.sourceCode).isEqualTo("a c")

    val firstInterval = c.getGapInterval(first)
    assertThat(firstInterval.leftInclusive).isEqualTo(1)
    assertThat(firstInterval.rightExclusive).isEqualTo(2)

    val secondInterval = c.getGapInterval(second)
    assertThat(secondInterval.leftInclusive).isEqualTo(1)
    assertThat(secondInterval.rightExclusive).isEqualTo(2)
    assertThat(gapStrings(c)).containsExactly("b", "c")
  }

  @Test
  fun testsearchAssumingCommonPrefix_false() {
    assertThat(search("ab", "cd")).isNull()
    assertThat(search("cd", "ab")).isNull()
  }

  @Test
  fun testsearchAssumingCommonPrefix_different_lengths() {
    val r = search("abcd", "ae")
    assertThat(r).isNotNull()
    val c = r!!
    val first = c.sequences.first()
    val second = c.sequences.last()
    assertThat(first.sourceCode).isEqualTo("a b c d")
    assertThat(second.sourceCode).isEqualTo("a e")

    val firstInterval = c.getGapInterval(first)
    assertThat(firstInterval.leftInclusive).isEqualTo(1)
    assertThat(firstInterval.rightExclusive).isEqualTo(4)

    val secondInterval = c.getGapInterval(second)
    assertThat(secondInterval.leftInclusive).isEqualTo(1)
    assertThat(secondInterval.rightExclusive).isEqualTo(2)

    assertThat(gapStrings(c)).containsExactly("b c d", "e")
  }

  @Test
  fun testsearchAssumingCommonPostfix_different_length() {
    val r = search("abcd", "gd")
    assertThat(r).isNotNull()
    val c = r!!

    val first = c.sequences.first()
    val second = c.sequences.last()
    assertThat(first.sourceCode).isEqualTo("a b c d")
    assertThat(second.sourceCode).isEqualTo("g d")

    val firstInterval = c.getGapInterval(first)
    assertThat(firstInterval.leftInclusive).isEqualTo(0)
    assertThat(firstInterval.rightExclusive).isEqualTo(3)

    val secondInterval = c.getGapInterval(second)
    assertThat(secondInterval.leftInclusive).isEqualTo(0)
    assertThat(secondInterval.rightExclusive).isEqualTo(1)
    assertThat(gapStrings(c)).containsExactly("a b c", "g")
  }

  @Test
  fun testsearchAssumingCommonPostfix_equal_length() {
    val r = search("cd", "gd")
    assertThat(r).isNotNull()
    val c = r!!
    val first = c.sequences.first()
    val second = c.sequences.last()
    assertThat(first.sourceCode).isEqualTo("c d")
    assertThat(second.sourceCode).isEqualTo("g d")

    val firstInterval = c.getGapInterval(first)
    val secondInterval = c.getGapInterval(second)
    assertThat(firstInterval.leftInclusive).isEqualTo(0)
    assertThat(firstInterval.rightExclusive).isEqualTo(1)
    assertThat(secondInterval.leftInclusive).isEqualTo(0)
    assertThat(secondInterval.rightExclusive).isEqualTo(1)
    assertThat(gapStrings(c)).containsExactly("c", "g")
  }

  @Test
  fun testSearchAssumingCommonPrefixAndPostfix_equal_length() {
    val r = search("abd", "acd")
    assertThat(r).isNotNull()
    val c = r!!
    val first = c.sequences.first()
    val second = c.sequences.last()
    assertThat(first.sourceCode).isEqualTo("a b d")
    assertThat(second.sourceCode).isEqualTo("a c d")

    val firstInterval = c.getGapInterval(first)
    val secondInterval = c.getGapInterval(second)
    assertThat(firstInterval.leftInclusive).isEqualTo(1)
    assertThat(firstInterval.rightExclusive).isEqualTo(2)
    assertThat(secondInterval.leftInclusive).isEqualTo(1)
    assertThat(secondInterval.rightExclusive).isEqualTo(2)
    assertThat(gapStrings(c)).containsExactly("b", "c")
  }

  @Test
  fun testSearchAssumingCommonPrefixAndPostfix_different_length() {
    val r = search("abed", "acd")
    assertThat(r).isNotNull()
    val c = r!!
    val first = c.sequences.first()
    val second = c.sequences.last()
    assertThat(first.sourceCode).isEqualTo("a b e d")
    assertThat(second.sourceCode).isEqualTo("a c d")

    val firstInterval = c.getGapInterval(first)
    val secondInterval = c.getGapInterval(second)
    assertThat(firstInterval.leftInclusive).isEqualTo(1)
    assertThat(firstInterval.rightExclusive).isEqualTo(3)
    assertThat(secondInterval.leftInclusive).isEqualTo(1)
    assertThat(secondInterval.rightExclusive).isEqualTo(2)
    assertThat(gapStrings(c)).containsExactly("b e", "c")
  }

  companion object {
    private fun search(s1: String, s2: String): AbstractCandidate? {
      val seq1 = GrammarTestingUtility.createSeqOfTerminals(split(s1))
      val seq2 = GrammarTestingUtility.createSeqOfTerminals(split(s2))
      return AltBlockExtractionPass.searchForCandidate(seq1, seq2)
    }

    private fun gapStrings(c: AbstractCandidate): List<String> {
      return c.getGapsToDelete()
        .asSequence()
        .map { it.sourceCode }
        .toImmutableList()
    }

    private fun split(s1: String): ImmutableList<String> {
      val builder = ImmutableList.builder<String>()
      for (c in s1.toCharArray()) {
        builder.add(c.toString())
      }
      return builder.build()
    }
  }
}
