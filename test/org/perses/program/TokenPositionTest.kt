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
package org.perses.program

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4

@RunWith(JUnit4::class)
class TokenPositionTest {
  @Test
  fun testCompareTo() {
    val p1 = TokenPosition(1, 10)
    val p2 = TokenPosition(1, 20)
    val p3 = TokenPosition(2, 5)
    val p4 = TokenPosition(2, 5)

    // Same line, different char position
    assertThat(p1).isLessThan(p2)
    assertThat(p2).isGreaterThan(p1)

    // Different line
    assertThat(p1).isLessThan(p3)
    assertThat(p3).isGreaterThan(p1)
    assertThat(p2).isLessThan(p3)
    assertThat(p3).isGreaterThan(p2)

    // Same position
    assertThat(p3).isEquivalentAccordingToCompareTo(p4)
    assertThat(p3.compareTo(p4)).isEqualTo(0)
  }

  @Test
  fun testCompareToSameLine() {
    val p1 = TokenPosition(10, 5)
    val p2 = TokenPosition(10, 10)
    assertThat(p1.compareTo(p2)).isLessThan(0)
    assertThat(p2.compareTo(p1)).isGreaterThan(0)
  }

  @Test
  fun testCompareToDifferentLine() {
    val p1 = TokenPosition(10, 100)
    val p2 = TokenPosition(11, 0)
    assertThat(p1.compareTo(p2)).isLessThan(0)
    assertThat(p2.compareTo(p1)).isGreaterThan(0)
  }
}
