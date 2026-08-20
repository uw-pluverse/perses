/*
 * Copyright (C) 2018-2026 University of Waterloo.
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
import org.antlr.v4.runtime.atn.EpsilonTransition
import org.antlr.v4.runtime.atn.RuleStartState
import org.antlr.v4.runtime.atn.RuleStopState
import org.antlr.v4.runtime.atn.SetTransition
import org.antlr.v4.runtime.misc.IntervalSet
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4

@RunWith(JUnit4::class)
class ConcatenatedNfaViewTest {
  private val former = singleCharNfa(startId = 0, char = 'a'.code)
  private val latter = singleCharNfa(startId = 2, char = 'b'.code)
  private val view = ConcatenatedNfaView(former, latter)

  @Test
  fun testStartIsFormersAndAcceptingIsLatters() {
    assertThat(view.startState).isSameInstanceAs(former.startState)
    assertThat(view.acceptingState).isSameInstanceAs(latter.acceptingState)
  }

  @Test
  fun testContainsStateSpansBothOperandsAndRejectsForeign() {
    assertThat(view.containsState(former.startState)).isTrue()
    assertThat(view.containsState(former.acceptingState)).isTrue()
    assertThat(view.containsState(latter.startState)).isTrue()
    assertThat(view.containsState(latter.acceptingState)).isTrue()
    assertThat(view.containsState(PersesATNState(999))).isFalse()
  }

  @Test
  fun testStateSequenceIsTheUnionOfBothOperands() {
    assertThat(view.stateSequence().toList())
      .containsExactly(
        former.startState,
        former.acceptingState,
        latter.startState,
        latter.acceptingState,
      )
  }

  @Test
  fun testBridgeEpsilonEdgeLinksFormerAcceptToLatterStart() {
    val outEdges = view.getOutgoingEdgesOf(former.acceptingState)
    // Former's accepting state is a sink, so the only outgoing edge is the bridge.
    assertThat(former.getOutgoingEdgesOf(former.acceptingState)).isEmpty()
    assertThat(outEdges).hasSize(1)

    val bridge = outEdges.single()
    assertThat(bridge.isEpsilon).isTrue()
    assertThat(view.getSourceState(bridge)).isSameInstanceAs(former.acceptingState)
    assertThat(view.getTargetState(bridge)).isSameInstanceAs(latter.startState)
    assertThat(view.containsEdge(bridge)).isTrue()
    assertThat(view.outDegreeOf(former.acceptingState)).isEqualTo(1)
  }

  @Test
  fun testFormerEdgesAreDelegatedUnchanged() {
    val formerEdge = former.getOutgoingEdgesOf(former.startState).single()
    assertThat(view.getOutgoingEdgesOf(former.startState)).containsExactly(formerEdge)
    assertThat(view.getSourceState(formerEdge)).isSameInstanceAs(former.startState)
    assertThat(view.getTargetState(formerEdge)).isSameInstanceAs(former.acceptingState)
    assertThat(view.containsEdge(formerEdge)).isTrue()
    assertThat(view.outDegreeOf(former.startState)).isEqualTo(1)
  }

  @Test
  fun testLatterEdgesAreDelegatedUnchanged() {
    val latterEdge = latter.getOutgoingEdgesOf(latter.startState).single()
    assertThat(view.getOutgoingEdgesOf(latter.startState)).containsExactly(latterEdge)
    assertThat(view.getSourceState(latterEdge)).isSameInstanceAs(latter.startState)
    assertThat(view.getTargetState(latterEdge)).isSameInstanceAs(latter.acceptingState)
    assertThat(view.containsEdge(latterEdge)).isTrue()
    assertThat(view.getOutgoingEdgesOf(latter.acceptingState)).isEmpty()
    assertThat(view.outDegreeOf(latter.acceptingState)).isEqualTo(0)
  }

  @Test
  fun testEdgeSequenceIsBothOperandsPlusExactlyOneBridge() {
    val allEdges = view.edgeSequence().toList()
    assertThat(allEdges)
      .hasSize(former.edgeSequence().count() + latter.edgeSequence().count() + 1)

    val formerEdge = former.getOutgoingEdgesOf(former.startState).single()
    val latterEdge = latter.getOutgoingEdgesOf(latter.startState).single()
    assertThat(allEdges).containsAtLeast(formerEdge, latterEdge)

    // The operands are single non-epsilon transitions, so the bridge is the only
    // epsilon edge in the concatenation.
    val bridge = allEdges.single { it.isEpsilon }
    assertThat(view.getSourceState(bridge)).isSameInstanceAs(former.acceptingState)
    assertThat(view.getTargetState(bridge)).isSameInstanceAs(latter.startState)
  }

  @Test
  fun testContainsEdgeRejectsForeignEdge() {
    val foreign = singleCharNfa(startId = 4, char = 'c'.code)
    val foreignEdge = foreign.getOutgoingEdgesOf(foreign.startState).single()
    assertThat(view.containsEdge(foreignEdge)).isFalse()
  }

  @Test
  fun testBridgeIsSplicedAlongsideExistingAcceptingEdges() {
    // Former whose accepting state is NOT a sink: it has a back-edge to its start.
    val loopingFormer = plusNfa(startId = 10, char = 'a'.code)
    val loopingView = ConcatenatedNfaView(loopingFormer, latter)

    val backEdge = loopingFormer.getOutgoingEdgesOf(loopingFormer.acceptingState).single()
    val outEdges = loopingView.getOutgoingEdgesOf(loopingFormer.acceptingState)
    assertThat(outEdges).hasSize(2)
    assertThat(loopingView.outDegreeOf(loopingFormer.acceptingState)).isEqualTo(2)

    assertThat(loopingView.getTargetState(backEdge))
      .isSameInstanceAs(loopingFormer.startState)
    val bridge = (outEdges - backEdge).single()
    assertThat(bridge.isEpsilon).isTrue()
    assertThat(loopingView.getTargetState(bridge)).isSameInstanceAs(latter.startState)
  }

  private companion object {
    /** Two-state NFA: `start --char--> accept`. */
    fun singleCharNfa(
      startId: Int,
      char: Int,
    ): MutableNfa {
      val start = RuleStartState().apply { stateNumber = startId }
      val accept = RuleStopState().apply { stateNumber = startId + 1 }
      start.stopState = accept
      start.addTransition(SetTransition(accept, IntervalSet.of(char)))
      return MutableNfa.copyOf(start)
    }

    /** Two-state NFA for `char+`: `start --char--> accept --epsilon--> start`. */
    fun plusNfa(
      startId: Int,
      char: Int,
    ): MutableNfa {
      val start = RuleStartState().apply { stateNumber = startId }
      val accept = RuleStopState().apply { stateNumber = startId + 1 }
      start.stopState = accept
      start.addTransition(SetTransition(accept, IntervalSet.of(char)))
      accept.addTransition(EpsilonTransition(start))
      return MutableNfa.copyOf(start)
    }
  }
}
