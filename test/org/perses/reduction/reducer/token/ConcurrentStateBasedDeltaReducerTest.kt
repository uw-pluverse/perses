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

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.reduction.AbstractReducerFunctionalTest

@RunWith(JUnit4::class)
class ConcurrentStateBasedDeltaReducerTest : AbstractReducerFunctionalTest() {

  @Test
  fun testReduceDelta() {
    runCTestSubject(
      "test_data/delta_3",
      ConcurrentStateBasedDeltaReducer.META,
      """
        |int main() {
        |  int a = 99;
        |  return a;
        |}
      """.trimMargin(),
    )
  }

  @Test
  fun testBinaryStateAdvance() {
    // Given sequence = "abcd"
    // testing "____"
    val state0 = ConcurrentDeltaDebuggingState.create(4)
    verifyBinaryState(state0!!, 0, 4, 4)

    // testing "__cd", "ab__"
    val state1 = state0.advance()
    verifyBinaryState(state1!!, 0, 2, 2)
    val state2 = state1.advance()
    verifyBinaryState(state2!!, 2, 4, 2)

    // testing "_bcd", "a_cd", "ab_d", "abc_"
    val state3 = state2.advance()
    verifyBinaryState(state3!!, 0, 1, 1)
    val state4 = state3.advance()
    verifyBinaryState(state4!!, 1, 2, 1)
    val state5 = state4.advance()
    verifyBinaryState(state5!!, 2, 3, 1)
    val state6 = state5.advance()
    verifyBinaryState(state6!!, 3, 4, 1)

    val state7 = state6.advance()
    assertThat(state7).isNull()
  }

  @Test
  fun testBinaryStateAdvanceOnSuccess() {
    // Given sequence = "abcd"
    val state0 = ConcurrentDeltaDebuggingState.create(4)

    // testing "__cd", "ab__"
    val state1 = state0!!.advance()
    verifyBinaryState(state1!!, 0, 2, 2)
    val state2 = state1.advance()
    verifyBinaryState(state2!!, 2, 4, 2)

    // say "ab__" interesting; testing "_b"
    val state3 = state2.advanceOnSuccess(2)
    verifyBinaryState(state3!!, 0, 1, 1)

    // say "_b" interesting; testing "b" (repeated by chance)
    val state4 = state3.advanceOnSuccess(1)
    verifyBinaryState(state4!!, 0, 1, 1)
    // advance to null state
    assertThat(state4.advance()).isNull()

    // test advance on null state
    assertThat(state0.advanceOnSuccess(0)).isNull()
  }

  private fun verifyBinaryState(
    state: ConcurrentDeltaDebuggingState,
    index: Int,
    end: Int,
    chunkSize: Int,
  ) {
    assertThat(state.index).isEqualTo(index)
    assertThat(state.end).isEqualTo(end)
    assertThat(state.chunkSize).isEqualTo(chunkSize)
  }
}
