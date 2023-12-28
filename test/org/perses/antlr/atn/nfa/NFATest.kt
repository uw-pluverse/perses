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
package org.perses.antlr.atn.nfa

import com.google.common.truth.Truth.assertThat
import org.antlr.v4.runtime.atn.ATNState
import org.antlr.v4.runtime.atn.BasicState
import org.antlr.v4.runtime.atn.EpsilonTransition
import org.antlr.v4.runtime.atn.RuleStartState
import org.antlr.v4.runtime.atn.RuleStopState
import org.antlr.v4.runtime.atn.SetTransition
import org.antlr.v4.runtime.atn.Transition
import org.antlr.v4.runtime.misc.IntervalSet
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.antlr.TokenType
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.PersesEpsilonAst
import org.perses.antlr.atn.LexerAtnWrapper
import org.perses.antlr.atn.OrigCLexer
import org.perses.antlr.atn.TestLexer
import org.perses.antlr.atn.transitionSequence
import org.perses.antlr.toTokenType
import java.util.ArrayDeque

@RunWith(JUnit4::class)
class NFATest {

  val atn = LexerAtnWrapper(TestLexer::class.java)

  @Test
  fun testConvertingPlusOfSingleCharFormManuallyCreatedATN() {
    var id = 1
    val start = RuleStartState().apply { stateNumber = id++ }
    val end = RuleStopState().apply { stateNumber = id++ }
    start.stopState = end
    val transition = SetTransition(end, IntervalSet.of(97))
    start.addTransition(transition)
    val backTransition = EpsilonTransition(start)
    end.addTransition(backTransition)
    val regex = MutableNFA.copyOf(start).simplifyToRegex()
    assertThat(regex.sourceCode).isEqualTo("97+")
  }

  @Test
  fun testConvertingPlusOfSequenceFromManuallyCreatedATN() {
    val start = createAtnOfPlusOverTwoChars()

    val regex = MutableNFA.copyOf(start).simplifyToRegex()
    assertThat(regex.sourceCode).isEqualTo("(97 98)+")
  }

  @Test
  fun testConvertingPlusOfSequenceFollowedByTerminalFromManualATN() {
    val start = createAtnOfPlusOverTwoChars()
    val end = start.stopState
    val newEnd = RuleStopState().apply { stateNumber = 100 }
    start.stopState = newEnd
    val transition = SetTransition(newEnd, IntervalSet.of(100))
    end.addTransition(transition)
    val regex = MutableNFA.copyOf(start).simplifyToRegex()
    assertThat(regex.sourceCode).isEqualTo("(97 98)+ 100")
  }

  private fun createAtnOfPlusOverTwoChars(): RuleStartState {
    var id1 = 0
    val start = RuleStartState().apply { stateNumber = id1++ }
    val end = RuleStopState().apply { stateNumber = id1++ }
    val mid = BasicState().apply { stateNumber = id1++ }
    start.stopState = end

    val transitionA = SetTransition(mid, IntervalSet.of(97))
    start.addTransition(transitionA)

    val transitionB = SetTransition(end, IntervalSet.of(98))
    mid.addTransition(transitionB)

    val backTransition = EpsilonTransition(start)
    end.addTransition(backTransition)
    return start
  }

  @Test
  fun testConstructATNFromRegexForSingleChar() {
    testConstructATNFromTransition(TestLexer.SingleChar.toTokenType())
  }

  @Test
  fun testConstructATNFromRegexForTwoChars() {
    testConstructATNFromTransition(TestLexer.TwoChars.toTokenType())
  }

  @Test
  fun testConstructATNFromRegexForCharSet() {
    testConstructATNFromTransition(TestLexer.CharSet.toTokenType())
  }

  @Test
  fun testConstructATNFromRegexForNotADigit() {
    testConstructATNFromTransition(TestLexer.NotADigit.toTokenType())
  }

  @Test
  fun testConstructATNFromRegexForKleeneStar() {
    testConstructATNFromTransition(TestLexer.KleeneStar.toTokenType())
  }

  @Test
  fun testConstructATNFromRegexForOptionalOnly() {
    testConstructATNFromTransition(TestLexer.OptionalOnly.toTokenType())
  }

  @Test
  fun testConstructATNFromRegexForOptionalChar() {
    testConstructATNFromTransition(TestLexer.OptionalChar.toTokenType())
  }

  @Test
  fun testConstructATNFromRegexForOptionalSequence() {
    val regex = testConstructATNFromTransition(TestLexer.OptionalSequence.toTokenType())
    val a = 'a'.code
    val b = 'b'.code
    val c = 'c'.code
    val d = 'd'.code
    val e = 'e'.code
    assertThat(regex.sourceCode).isEqualTo("($a $b $c $d)? $e")
  }

  @Test
  fun testConstructATNFromRegexForAlt() {
    testConstructATNFromTransition(TestLexer.Alt.toTokenType())
  }

  @Test
  fun testConstructATNFromRegexForKleenePlusOnSingleChar() {
    testConstructATNFromTransition(TestLexer.KleenePlusOnSingleChar.toTokenType())
  }

  @Test
  fun testConstructATNFromRegexForNegationAndPlus() {
    testConstructATNFromTransition(TestLexer.NegationAndPlus.toTokenType())
  }

  @Test
  fun testConstructATNFromRegexForIncludeDirective() {
    testConstructATNFromTransition(TestLexer.IncludeDirective.toTokenType())
  }

  @Test
  fun testConstructATNFromRegexNaturalNumber() {
    testConstructATNFromTransition(TestLexer.NaturalNumber.toTokenType())
  }

  @Test
  fun testConstrctATNFromRegexLong() {
    testConstructATNFromTransition(TestLexer.Long.toTokenType())
  }

  fun testConstructATNFromTransition(ruleType: TokenType): AbstractPersesRuleElement {
    val origAtnStartState = atn.getOriginalStartState(ruleType)
    val regex = MutableNFA.copyOf(origAtnStartState)
      .removeStatesUnreachableFromAcceptingState().simplifyToRegex()
    val recoveredATN = ATNConstructorFromRegex().construct(regex)
    val recoveredRegex = MutableNFA.copyOf(recoveredATN)
      .removeStatesUnreachableFromAcceptingState().simplifyToRegex()
    assertThat(regex.isEquivalent(recoveredRegex)).isTrue()
    return regex
  }

  @Test
  fun testSimplifyToRegexForKleenePlusOnSingleChar() {
    val regex = createNFA(TestLexer.KleenePlusOnSingleChar.toTokenType()).simplifyToRegex()
    val a = 'a'.code.toString()
    assertThat(regex.sourceCode).isEqualTo("$a+")
  }

  @Test
  fun testSimplifyToRegexForNegationAndPlus() {
    assertThat(
      createNFA(TestLexer.NegationAndPlus.toTokenType()).simplifyToRegex().sourceCode,
    ).isEqualTo("~${'\n'.code}+")
  }

  @Test
  fun testSimplifyToRegexForLong() {
    val char0 = '0'.code.toString()
    val char9 = '9'.code.toString()
    val charL = 'L'.code.toString()
    assertThat(
      createNFA(TestLexer.Long.toTokenType()).simplifyToRegex().sourceCode,
    ).isEqualTo("{$char0..$char9}+ $charL")
  }

  @Test
  fun testSimplifyToRegexForOptionalChar() {
    val regex = createNFA(TestLexer.OptionalChar.toTokenType()).simplifyToRegex()
    assertThat(regex.sourceCode).isEqualTo("${'a'.code} ${'b'.code}?")
  }

  @Test
  fun testSimplifyToRegexForOptionalOnly() {
    val nfa = createNFA(TestLexer.OptionalOnly.toTokenType())
    val regex = nfa.simplifyToRegex()
    assertThat(regex.sourceCode).isEqualTo("${'b'.code}?")
  }

  @Test
  fun testSimplifyToRegexForKleeneStar() {
    val nfa = createNFA(TestLexer.KleeneStar.toTokenType())
    val regex = nfa.simplifyToRegex()
    assertThat(regex.sourceCode).isEqualTo("${'a'.code} ${'b'.code}*")
  }

  @Test
  fun testSimplifyToRegExForTwoChars() {
    val nfa = createNFA(TestLexer.TwoChars.toTokenType())
    val regex = nfa.simplifyToRegex()
    val sourceCode = regex.sourceCode
    assertThat(sourceCode).isEqualTo("${'A'.code} ${'B'.code}")
  }

  @Test
  fun testImmutableNFAAndMutableNFAHaveTheSameTopology() {
    val atn = LexerAtnWrapper(OrigCLexer::class.java)
    atn.metaTokenInfoDB.asSequence()
      .map { token ->
        val mutableNFA = MutableNFA.copyOf(atn.getOriginalStartState(token.tokenType))
        mutableNFA to mutableNFA.toImmutableNFA()
      }.forEach {
        assertThat(it.first.printTopology()).isEqualTo(it.second.printTopology())
      }
  }

  @Test
  fun testSimplifyToRegexForSingleChar() {
    val nfa = createNFA(TestLexer.SingleChar.toTokenType())
    val regex = nfa.simplifyToRegex()
    assertThat(regex.sourceCode).isEqualTo('A'.code.toString())
  }

  private fun createNFA(ruleType: TokenType): MutableNFA {
    return MutableNFA.copyOf(atn.getOriginalStartState(ruleType))
      .removeStatesUnreachableFromAcceptingState()
  }

  @Test
  fun testNfaAndAtnHaveTheSameTopology() {
    testNfaAndAtnHaveSameTopology(TestLexer.SingleChar.toTokenType())
    testNfaAndAtnHaveSameTopology(TestLexer.NaturalNumber.toTokenType())
    testNfaAndAtnHaveSameTopology(TestLexer.OptionalOnly.toTokenType())
    testNfaAndAtnHaveSameTopology(TestLexer.Long.toTokenType())
  }

  private fun testNfaAndAtnHaveSameTopology(ruleType: TokenType) {
    val startState = atn.getOriginalStartState(ruleType)
    val edgesInATN = getEdgesFromATN(startState)
    val nfa = MutableNFA.copyOf(startState)
    assertThat(nfa.edgeSequence().count()).isAtLeast(edgesInATN.size)
    assertThat(nfa.stateSequence().count())
      .isEqualTo(
        edgesInATN
          .keys.asSequence()
          .flatMap { sequenceOf(it.first, it.second) }
          .distinct()
          .count(),
      )

    nfa.edgeSequence()
      .map { edge ->
        val sourceNode = nfa.getSourceState(edge)
        val targetNode = nfa.getTargetState(edge)
        val sourceTargetNodePair = sourceNode to targetNode
        assertThat(edgesInATN).containsKey(sourceTargetNodePair)
        val transition = edgesInATN[sourceNode.stateNumber to targetNode.stateNumber]!!
        val label = edge.label
        when (label) {
          is PersesEpsilonAst -> {
            assertThat(transition.isEpsilon).isTrue()
          }
          is PersesTransitionAst -> {
            assertThat(label.atnTransition).isSameInstanceAs(transition)
          }
          else -> error("unreachable")
        }
      }
    assertThat(nfa.startState.stateNumber).isEqualTo(startState.stateNumber)
    assertThat(nfa.acceptingState.stateNumber).isEqualTo(startState.stopState.stateNumber)
  }

  private fun getEdgesFromATN(
    startState: RuleStartState,
  ): Map<Pair<Int, Int>, Transition> {
    val result = HashMap<Pair<Int, Int>, Transition>()
    val worklist = ArrayDeque<ATNState>().apply { add(startState) }
    val visited = HashSet<ATNState>()
    while (worklist.isNotEmpty()) {
      val current = worklist.remove()
      if (!visited.add(current)) {
        continue
      }
      current.transitionSequence().forEach { transition ->
        result[current.stateNumber to transition.target.stateNumber] = transition
        worklist.add(transition.target)
      }
    }
    return result
  }
}
