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
import org.perses.util.Fraction.Companion.parse

@RunWith(JUnit4::class)
class PercentageTest {
  @Test
  fun testOne() {
    val p = Fraction(1, 100)
    assertThat(p.numerator).isEqualTo(1)
    assertThat(p.multiply(1000)).isEqualTo(10)
  }

  @Test
  fun testZero() {
    val p = Fraction(0, 100)
    assertThat(p.numerator).isEqualTo(0)
    assertThat(p.multiply(100)).isEqualTo(0)
  }

  @Test
  fun test100() {
    val p = Fraction(100, 100)
    assertThat(p.numerator).isEqualTo(100)
    assertThat(p.multiply(100)).isEqualTo(100)
  }

  @Test
  fun testParsePercentage() {
    val (numerator, denominator) = parse("1 / 100")
    assertThat(numerator).isEqualTo(1)
    assertThat(denominator).isEqualTo(100)
  }
}
