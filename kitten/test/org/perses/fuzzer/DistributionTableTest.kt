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
package org.perses.fuzzer

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.Assert
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.fuzzer.DistributionTable.Entry

@RunWith(JUnit4::class)
class DistributionTableTest {

  val table = DistributionTable(
    ImmutableList.of(
      Entry(1, "1"),
      Entry(2, "2"),
      Entry(3, "3"),
    ),
  )

  @Test
  fun test_totalWeight() {
    assertThat(table.totalWeight).isEqualTo(6)
  }

  @Test
  fun test_exceptions() {
    Assert.assertThrows(Exception::class.java) {
      table.selectEntry(0)
    }
    Assert.assertThrows(Exception::class.java) {
      table.selectEntry(table.totalWeight + 1)
    }
    table.selectEntry(1) // does not crash
    table.selectEntry(table.totalWeight) // does not crash
  }

  @Test
  fun test_pick_first_entry() {
    assertThat(table.selectEntry(1)).isEqualTo("1")
  }

  @Test
  fun test_pick_second_entry() {
    assertThat(table.selectEntry(2)).isEqualTo("2")
    assertThat(table.selectEntry(3)).isEqualTo("2")
  }

  @Test
  fun test_pick_third_entry() {
    assertThat(table.selectEntry(4)).isEqualTo("3")
    assertThat(table.selectEntry(5)).isEqualTo("3")
    assertThat(table.selectEntry(6)).isEqualTo("3")
  }
}
