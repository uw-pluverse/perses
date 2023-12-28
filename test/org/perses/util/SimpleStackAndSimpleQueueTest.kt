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
class SimpleStackAndSimpleQueueTest {

  val stack = SimpleStack.of(1).add(2).add(3)
  val queue = SimpleQueue.of(1).add(2).add(3)

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
    assertThat(queue.peek()).isEqualTo(1)
    assertThat(queue.remove()).isEqualTo(1)
    assertThat(queue.peek()).isEqualTo(2)
    assertThat(queue.remove()).isEqualTo(2)
    assertThat(queue.peek()).isEqualTo(3)
    assertThat(queue.remove()).isEqualTo(3)
    assertThat(queue.isEmpty()).isTrue()
  }

  @Test
  fun testStackContains() {
    assertThat(stack.contains(1)).isTrue()
    assertThat(stack.contains(2)).isTrue()
    assertThat(stack.contains(3)).isTrue()
    assertThat(stack.contains(4)).isFalse()
  }

  @Test
  fun testStackAsSequence() {
    stack.sequenceFromTop().toList().let {
      assertThat(it).containsExactly(3, 2, 1).inOrder()
    }
    stack.sequenceFromBottom().toList().let {
      assertThat(it).containsExactly(1, 2, 3).inOrder()
    }
  }

  @Test
  fun testStackCounts() {
    assertThat(stack.count(1)).isEqualTo(1)
    assertThat(stack.count(2)).isEqualTo(1)
    assertThat(stack.count(3)).isEqualTo(1)
    assertThat(stack.count(4)).isEqualTo(0)

    stack.add(1)
    assertThat(stack.count(1)).isEqualTo(2)
  }

  @Test
  fun testStackPeek() {
    assertThat(stack.peekBottom()).isEqualTo(1)
    assertThat(stack.peek()).isEqualTo(3)
    assertThat(stack.size).isEqualTo(3)
  }

  @Test
  fun testEqualStack() {
    assertThat(stack).isEqualTo(stack)
    assertThat(stack).isNotEqualTo(Object())
    assertThat(stack).isNotEqualTo(SimpleStack.of(1).add(2).add(4))
    assertThat(stack).isNotEqualTo(SimpleStack.of(2).add(4))
    assertThat(stack).isEqualTo(SimpleStack.of(1).add(2).add(3))
    assertThat(stack).isNotEqualTo(queue)
  }

  @Test
  fun testEqualQueue() {
    assertThat(queue).isNotEqualTo(SimpleQueue<Int>())
    assertThat(queue).isEqualTo(queue)
    assertThat(queue).isNotEqualTo(stack)
    assertThat(queue).isNotEqualTo(SimpleQueue.of(1))
    assertThat(queue).isNotEqualTo(SimpleQueue.of(1).add(2))
    assertThat(queue).isEqualTo(SimpleQueue.of(1).add(2).add(3))
  }

  @Test
  fun testHashStack() {
    SimpleStack.of(1).add(2).add(3).let {
      assertThat(it.hashCode()).isEqualTo(stack.hashCode())
    }
  }

  @Test
  fun testHashQueue() {
    SimpleQueue.of(1).add(2).add(3).let {
      assertThat(it.hashCode()).isEqualTo(queue.hashCode())
    }
  }

  @Test
  fun testCopyStack() {
    val copy = stack.copy()
    assertThat(copy.size).isEqualTo(stack.size)
    assertThat(copy).isEqualTo(stack)
    assertThat(copy).isNotEqualTo(queue)
  }
}
