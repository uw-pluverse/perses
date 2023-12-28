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
package org.perses.reduction

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.listener.IProfileEvent
import org.perses.listener.IProfileEvent.FixpointIterationEvent
import org.perses.listener.IProfileEvent.GranularityEvent
import org.perses.listener.IProfileEvent.LevelReductionEvent

/** Created by neo on 12/17/16.  */
@RunWith(JUnit4::class)
class ProfileTest {
  @Test
  fun testLabelReductionEventToString() {
    val startEvent: IProfileEvent = LevelReductionEvent(0, true, 2)
    assertThat(startEvent.toString().trim { it <= ' ' }).isEqualTo(
      "LevelReductionEvent\t[Start" +
        "]\ttime=" +
        startEvent.timeInMilliseconds +
        "\ttokenCount=0\tlevel=2",
    )
    val endEvent: IProfileEvent = LevelReductionEvent(0, false, 3)
    assertThat(endEvent.toString().trim { it <= ' ' }).isEqualTo(
      "LevelReductionEvent\t" +
        "[End]\ttime=" +
        endEvent.timeInMilliseconds +
        "\ttokenCount=0\tlevel=3",
    )
  }

  @Test
  fun testGranularityEvent() {
    val startEvent: IProfileEvent = GranularityEvent(1, true, 3)
    assertThat(startEvent.toString().trim { it <= ' ' }).isEqualTo(
      "GranularityEvent\t" +
        "[Start]\ttime=" +
        startEvent.timeInMilliseconds +
        "\ttokenCount=1\tgranularity=3",
    )
    val endEvent: IProfileEvent = GranularityEvent(1, false, 3)
    assertThat(endEvent.toString().trim { it <= ' ' }).isEqualTo(
      "GranularityEvent\t[End" +
        "]\ttime=" +
        endEvent.timeInMilliseconds +
        "\ttokenCount=1\tgranularity=3",
    )
  }

  @Test
  fun testFixpointIterationEvent() {
    val start: IProfileEvent = FixpointIterationEvent(1, true)
    assertThat(
      "FixpointIterationEvent\t[Start]\ttime=" + start.timeInMilliseconds + "\ttokenCount=1",
    ).isEqualTo(
      start.toString().trim {
        it <= ' '
      },
    )
    val end: IProfileEvent = FixpointIterationEvent(2, false)
    assertThat(
      "FixpointIterationEvent\t[End]\ttime=" + end.timeInMilliseconds + "\ttokenCount=2",
    ).isEqualTo(
      end.toString().trim {
        it <= ' '
      },
    )
  }
}
