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
import org.junit.Assert.assertThrows
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4

@RunWith(JUnit4::class)
class TinyListMapTest {

  val map = TinyListMap<String, Int>()

  @Test
  fun test_empty() {
    assertThat(map.get("")).isNull()
  }

  @Test
  fun test() {
    val key = "hello"
    assertThat(map.get(key)).isNull()
    val value = 1
    map.putOrThrowIfPresent(key, value)
    assertThat(map.get(key)).isEqualTo(value)
    assertThrows(Exception::class.java) {
      map.putOrThrowIfPresent(key, value)
    }
  }
}
