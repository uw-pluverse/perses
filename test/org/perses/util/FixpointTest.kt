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
package org.perses.util

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4

@RunWith(JUnit4::class)
class FixpointTest {
  @Test
  fun testFixpoint() {
    val initial = 0
    val max = 2
    val history = mutableListOf<Int>()
    val result =
      fixpoint(
        initial = initial,
      ) { value ->
        history.add(value)
        if (value == max) {
          max
        } else {
          value + 1
        }
      }
    assertThat(result).isEqualTo(max)
    assertThat(history).isEqualTo(
      (0..max).toList(),
    )
  }

  @Test
  fun testFixpointStopCriterion() {
    assertThat(EnumStopCriterion.stopIfTrue(true)).isEqualTo(EnumStopCriterion.STOP)
    assertThat(EnumStopCriterion.stopIfTrue(false)).isEqualTo(EnumStopCriterion.CONTINUE)
    assertThat(EnumStopCriterion.continueIfTrue(true)).isEqualTo(EnumStopCriterion.CONTINUE)
    assertThat(EnumStopCriterion.continueIfTrue(false)).isEqualTo(EnumStopCriterion.STOP)
  }
}
