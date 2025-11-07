/*
 * Copyright (C) 2018-2025 University of Waterloo.
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

/** Test for [TimeSpan]  */
@RunWith(JUnit4::class)
class TimeSpanTest {
  @Test
  fun test() {
    val builder = TimeSpan.Builder(startMillis = 0)
    val span = builder.createTimeSpan(endMillis = Int.MAX_VALUE.toLong())
    assertThat(
      span.formattedElapsedTime,
    ).isEqualTo("2147483 seconds (24 days 20 hours 31 minutes 23 seconds)")
  }

  @Test
  fun testBuilder() {
    val builder = TimeSpan.Builder(2000)
    val span = builder.createTimeSpan(3000)
    assertThat(span.endTimeMillis).isEqualTo(3000)
    assertThat(span.startTimeMillis).isEqualTo(2000)
    assertThat(span.elapsedTimeInMillis).isEqualTo(1000)
    assertThat(span.formattedElapsedTime).isEqualTo("1 second")
    assertThat(span.elapsedTimeInSeconds).isEqualTo(1)
  }
}
