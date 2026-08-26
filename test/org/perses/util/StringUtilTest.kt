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
import org.perses.util.StringUtil.computePercentage

@RunWith(JUnit4::class)
class StringUtilTest {
  @Test
  fun testComputePercentage() {
    assertThat(computePercentage(100, 100, prefix = "")).isEqualTo("100.00%")
    assertThat(computePercentage(50, 100, prefix = "")).isEqualTo("50.00%")
    assertThat(computePercentage(2525, 10000, prefix = "")).isEqualTo("25.25%")
    assertThat(computePercentage(1, 100, prefix = "")).isEqualTo("1.00%")
    assertThat(computePercentage(1, 1000, prefix = "")).isEqualTo("0.10%")
    assertThat(computePercentage(1, 10000, prefix = "")).isEqualTo("0.01%")
    assertThat(computePercentage(1, 100000, prefix = "")).isEqualTo("0.0010%")
    assertThat(computePercentage(1, 1000000)).isEqualTo("1/1000000=0.00010%")
  }

  @Test
  fun testFindUtfChars() {
    val input = "，"
    StringUtil.findUtf16Chars(input).let {
      assertThat(it).hasSize(1)
      assertThat(it.first().char).isEqualTo('，')
      assertThat(it.first().indexInString).isEqualTo(0)
    }
  }

  @Test
  fun testHasWhitespaceInString() {
    assertThat(StringUtil.hasWhitespace("")).isFalse()
    assertThat(StringUtil.hasWhitespace(" ")).isTrue()
    assertThat(StringUtil.hasWhitespace("ab \nc")).isTrue()
    assertThat(StringUtil.hasWhitespace("ab")).isFalse()
  }
}
