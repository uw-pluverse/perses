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
package org.perses.reduction.reducer.token

import com.google.common.truth.Truth
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.reduction.AbstractReducerFunctionalTest

@RunWith(JUnit4::class)
class ConcurrentStateBasedTokenSlicerTest : AbstractReducerFunctionalTest() {

  @Test
  fun testDelta1GrepBased() {
    test(
      reductionFolder = "test/org/perses/benchmark_toys/delta_1",
      testScript = "grep_based_r.sh",
      sourceFile = "t.c",
      algorithmType = ConcurrentStateBasedTokenSlicer.COMPOSITE_REDUCER,
      cmdCustomizer = {},
      // It is not possible to get only the string literal, because our token slicer
      // checks syntactical validity before each property test.
      expected = """
      printf { ("world\n");}
    """.trim(),
    )
  }

  @Test
  fun testStateAdvance() {
    val stateNull = ConcurrentTokenSlicingState.create(granularity = 5, sequenceSize = 5)
    Truth.assertThat(stateNull).isNull()

    // slicing "int a" with granularity = 1
    val state0 = ConcurrentTokenSlicingState.create(granularity = 1, sequenceSize = 2)
    verifyState(state0!!, 0, 1)
    val state1 = state0.advance()
    verifyState(state1!!, 1, 2)
    val state2 = state1.advance()
    Truth.assertThat(state2).isNull()
  }

  @Test
  fun testStateAdvanceOnSuccess() {
    // given program "a b c d e"
    val state0 = ConcurrentTokenSlicingState.create(2, 5)
    // test "_ _ c d e", uninteresting
    verifyState(state0!!, 0, 2)
    val state1 = state0.advance()
    // test "a _ _ d e", interesting -> "a d e"
    verifyState(state1!!, 1, 3)
    val state2 = state1.advanceOnSuccess(newSequenceSize = 3)
    // test "a _ _", interesting -> "a"
    verifyState(state2!!, 1, 3)
    val state3 = state2.advanceOnSuccess(1)
    // no more state to explore
    Truth.assertThat(state3).isNull()
  }

  private fun verifyState(
    state: ConcurrentTokenSlicingState,
    startInclusive: Int,
    endExclusive: Int,
  ) {
    Truth.assertThat(state.startInclusive).isEqualTo(startInclusive)
    Truth.assertThat(state.endExclusive).isEqualTo(endExclusive)
  }
}
