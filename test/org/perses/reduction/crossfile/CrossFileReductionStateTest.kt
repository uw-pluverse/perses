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
package org.perses.reduction.crossfile

import com.google.common.collect.ImmutableMap
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.program.AbstractReductionFile

@RunWith(JUnit4::class)
class CrossFileReductionStateTest {
  // The state never inspects the program's keys, so empty whole-set programs (distinguished by
  // identity) are enough to test the best-tracking and listener behavior in isolation.
  private fun emptyProgram() =
    CrossFileProgram(ImmutableMap.of<AbstractReductionFile<*, *>, String>())

  @Test
  fun testInitFiresListenerWithInitialProgram() {
    val initial = emptyProgram()
    val updates = mutableListOf<CrossFileProgram>()
    val state = CrossFileReductionState(initial) { updates.add(it) }

    assertThat(state.bestProgram).isSameInstanceAs(initial)
    assertThat(updates).containsExactly(initial)
  }

  @Test
  fun testUpdateBestSwapsProgramAndFiresListener() {
    val initial = emptyProgram()
    val updates = mutableListOf<CrossFileProgram>()
    val state = CrossFileReductionState(initial) { updates.add(it) }

    val next = emptyProgram()
    state.updateBest(next)

    assertThat(state.bestProgram).isSameInstanceAs(next)
    assertThat(updates).containsExactly(initial, next).inOrder()
  }
}
