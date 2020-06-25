/*
 * Copyright (C) 2018-2020 University of Waterloo.
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
package org.perses.util;

import com.google.common.truth.Truth;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;

@RunWith(JUnit4.class)
public class PercentageTest {

  @Test
  public void test_one() {
    Fraction p = new Fraction(1, 100);
    Truth.assertThat(p.getNumerator()).isEqualTo(1);
    Truth.assertThat(p.multiply(1000)).isEqualTo(10);
  }

  @Test
  public void test_zero() {
    Fraction p = new Fraction(0, 100);
    Truth.assertThat(p.getNumerator()).isEqualTo(0);
    Truth.assertThat(p.multiply(100)).isEqualTo(0);
  }

  @Test
  public void test_100() {
    Fraction p = new Fraction(100, 100);
    Truth.assertThat(p.getNumerator()).isEqualTo(100);
    Truth.assertThat(p.multiply(100)).isEqualTo(100);
  }

  @Test
  public void test_parsePercentage() {
    Fraction p = Fraction.parse("1 / 100");
    Truth.assertThat(p.getNumerator()).isEqualTo(1);
    Truth.assertThat(p.getDenominator()).isEqualTo(100);
  }
}
