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
import org.junit.Assert.assertThrows
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4

// TODO(cnsun): more tests.
@RunWith(JUnit4::class)
class SortedIntArrayReferenceTest {

  @Test
  fun test_empty_single_integer() {
    val i = SortedIntArrayReference.SingleInteger()
    assertThat(i.isFull()).isFalse()
    assertThat(i.size()).isEqualTo(0)
    assertThat(i.toList()).isEmpty()

    assertThrows(RuntimeException::class.java) {
      i.binarySearch(1, 1)
    }
    assertThrows(RuntimeException::class.java) {
      i.getInt(0)
    }
  }

  @Test
  fun test_full_single_integer() {
    val i = SortedIntArrayReference.SingleInteger()
    i.add(1)
    assertThat(i.toList()).containsExactly(1)
    assertThat(i.size()).isEqualTo(1)
    assertThat(i.isFull()).isTrue()
    assertThat(i.getInt(0)).isEqualTo(1)

    assertThat(i.binarySearch(0, 1)).isEqualTo(0)
    assertThat(i.binarySearch(1, 1)).isEqualTo(-2)
    assertThat(i.binarySearch(0, 0)).isEqualTo(-1)
    assertThat(i.binarySearch(0, 2)).isEqualTo(-2)

    assertThrows(RuntimeException::class.java) {
      i.add(1)
    }

    assertThrows(RuntimeException::class.java) {
      i.reset(0)
    }
    assertThrows(RuntimeException::class.java) {
      i.reset(3)
    }
    i.reset(1)
    assertThat(i.toList()).isEmpty()
  }

  @Test
  fun test_empty_multiple_integers() {
    val i = SortedIntArrayReference.MultipleIntegers(2)
    assertThat(i.isFull()).isFalse()
    assertThat(i.size()).isEqualTo(0)
  }
}
