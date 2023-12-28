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
package org.perses.reduction.reducer.token

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4

@RunWith(JUnit4::class)
class ConcurrentTokenSlicerTaskDescTest {

  @Test
  fun test_one_element_list() {
    val tokens = ImmutableList.of("")
    val desc = ConcurrentTokenSlicerTaskDesc(tokens, startIndex = 0, slicingGranularity = 1)
    assertThat(desc.next()).isNull()
  }

  @Test
  fun test_two_element_list_with_granularity_one() {
    val tokens = ImmutableList.of("a", "b")
    val desc = ConcurrentTokenSlicerTaskDesc(tokens, startIndex = 0, slicingGranularity = 1)
    val next = desc.next()
    assertThat(next).isNotNull()
    assertThat(next!!.startIndex).isEqualTo(1)
    assertThat(next.slicingGranularity).isEqualTo(1)
    assertThat(next.next()).isNull()
  }

  @Test
  fun test_two_element_list_with_granularity_two() {
    val tokens = ImmutableList.of("a", "b")
    val desc = ConcurrentTokenSlicerTaskDesc(tokens, startIndex = 0, slicingGranularity = 2)
    val next = desc.next()
    assertThat(next).isNotNull()
    assertThat(next!!.startIndex).isEqualTo(0)
    assertThat(next.slicingGranularity).isEqualTo(1)
  }
}
