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

@RunWith(JUnit4::class)
class DoubleLinkedListTest {

  @Test
  fun testSingleELementList() {
    val list = DoubleLinkedList<Int>()
    val node = list.addFirst(1)
    assertThat(list.getPrev(node)).isNull()
    assertThat(list.getNext(node)).isNull()
  }

  @Test
  fun testTwoElementsList() {
    val list = DoubleLinkedList<Int>()
    val first = list.addFirst(1)
    val second = list.addLast(2)

    assertThat(list.getPrev(first)).isNull()
    assertThat(list.getPrev(second)).isSameInstanceAs(first)

    assertThat(list.getNext(first)).isSameInstanceAs(second)
    assertThat(list.getNext(second)).isNull()
  }

  @Test
  fun removeSingleElement() {
    val list = DoubleLinkedList<Int>()
    val node = list.addFirst(1)
    assertThat(list.isEmpty()).isFalse()
    list.remove(node)
    assertThat(list.isEmpty()).isTrue()
  }

  @Test
  fun removeFirstFromThree() {
    val list = DoubleLinkedList<Int>()
    val first = list.addFirst(1)
    val second = list.addLast(2)
    val third = list.addLast(3)

    val removed = list.remove(first)
    assertThat(list.getPrev(removed)).isNull()
    assertThat(list.getNext(removed)).isNull()

    assertThat(list.getPrev(second)).isNull()
    assertThat(list.getNext(second)).isSameInstanceAs(third)
  }

  @Test
  fun removeSecondFromThree() {
    val list = DoubleLinkedList<Int>()
    val first = list.addFirst(1)
    val second = list.addLast(2)
    val third = list.addLast(3)

    val removed = list.remove(second)
    assertThat(list.getPrev(removed)).isNull()
    assertThat(list.getNext(removed)).isNull()

    assertThat(list.getNext(first)).isEqualTo(third)
    assertThat(list.getPrev(third)).isEqualTo(first)
  }

  @Test
  fun removeThirdFromThree() {
    val list = DoubleLinkedList<Int>()
    val first = list.addFirst(1)
    val second = list.addLast(2)
    val third = list.addLast(3)

    val removed = list.remove(third)
    assertThat(list.getPrev(removed)).isNull()
    assertThat(list.getNext(removed)).isNull()

    assertThat(list.getNext(second)).isNull()
    assertThat(list.getPrev(second)).isEqualTo(first)
  }
}
