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
package org.perses.util

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import java.time.ZoneId

@RunWith(JUnit4::class)
class TimeUtilTest {

  @Test
  fun testFormatDateForFileName() {
    val epochMillis = 1569287074745L
    // BAZEL uses UTC as the system timezone.
    assertThat(TimeUtil.formatDateForFileName(epochMillis))
      .isEqualTo("20190924_010434")
  }

  @Test
  fun testFormatDateForDisplay() {
    val epochMillis = 1569287074745L
    // BAZEL uses UTC as the system timezone.
    assertThat(TimeUtil.formatDateForDisplay(epochMillis))
      .isEqualTo("01:04:34 2019/09/24")
  }

  @Test
  fun testConvertToLocalDateTime() {
    val epochMillis = 1569287074745L
    val time = TimeUtil.converToLocalDateTime(
      epochMillis,
      ZoneId.of("America/Indiana/Indianapolis"),
    )
    assertThat(time.toString()).isEqualTo("2019-09-23T21:04:34.745")
  }

  @Test
  fun test_toMillisFromSeconds() {
    assertThat(TimeUtil.toMillisFromSeconds(2)).isEqualTo(2000)
  }

  @Test
  fun test_toMillisFromMinutes() {
    assertThat(TimeUtil.toMillisFromMinutes(2)).isEqualTo(120000)
  }
}
