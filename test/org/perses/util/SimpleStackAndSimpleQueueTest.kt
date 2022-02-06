/*
 * Copyright (C) 2018-2022 University of Waterloo.
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
class SimpleStackAndSimpleQueueTest {

  @Test
  fun testStackIsEmpty() {
    val stack = SimpleStack<Int>()
    assertThat(stack.isEmpty()).isTrue()
    assertThat(stack.isNotEmpty()).isFalse()
    stack.add(1)
    assertThat(stack.isEmpty()).isFalse()
    assertThat(stack.isNotEmpty()).isTrue()
  }

  @Test
  fun testQueueIsEmpty() {
    val queue = SimpleQueue<Int>()
    assertThat(queue.isEmpty()).isTrue()
    assertThat(queue.isNotEmpty()).isFalse()
    queue.add(1)
    assertThat(queue.isEmpty()).isFalse()
    assertThat(queue.isNotEmpty()).isTrue()
  }

  @Test
  fun testStackPushPopPeek() {
    val stack = SimpleStack<Int>()
    stack.add(1).add(2).add(3)
    assertThat(stack.peek()).isEqualTo(3)
    assertThat(stack.remove()).isEqualTo(3)
    assertThat(stack.peek()).isEqualTo(2)
    assertThat(stack.remove()).isEqualTo(2)
    assertThat(stack.peek()).isEqualTo(1)
    assertThat(stack.remove()).isEqualTo(1)
    assertThat(stack.isEmpty()).isTrue()
  }

  @Test
  fun testQueueAddRemove() {
    val queue = SimpleQueue<Int>()
    queue.add(1).add(2).add(3)
    assertThat(queue.peek()).isEqualTo(1)
    assertThat(queue.remove()).isEqualTo(1)
    assertThat(queue.peek()).isEqualTo(2)
    assertThat(queue.remove()).isEqualTo(2)
    assertThat(queue.peek()).isEqualTo(3)
    assertThat(queue.remove()).isEqualTo(3)
    assertThat(queue.isEmpty()).isTrue()
  }
}
