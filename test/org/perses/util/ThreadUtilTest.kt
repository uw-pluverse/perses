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
package org.perses.util

import com.google.common.truth.Truth.assertThat
import org.junit.Assert.assertThrows
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import java.util.concurrent.atomic.AtomicBoolean
import java.util.concurrent.atomic.AtomicInteger
import java.util.concurrent.atomic.AtomicReference

@RunWith(JUnit4::class)
class ThreadUtilTest {
  @Test
  fun testCallWithLargeStackOnStackOverflow_noOverflowRunsOnCallingThreadWithoutRetry() {
    val invocationCount = AtomicInteger(0)
    val runThread = AtomicReference<Thread>()
    val result =
      ThreadUtil.callWithLargeStackOnStackOverflow(largeStackSize = RETRY_STACK_SIZE) {
        invocationCount.incrementAndGet()
        runThread.set(Thread.currentThread())
        42
      }
    assertThat(result).isEqualTo(42)
    assertThat(invocationCount.get()).isEqualTo(1)
    assertThat(runThread.get()).isSameInstanceAs(Thread.currentThread())
  }

  @Test
  fun testCallWithLargeStackOnStackOverflow_overflowThenSuccessRetriesOnDifferentThread() {
    val invocationCount = AtomicInteger(0)
    val firstThread = AtomicReference<Thread>()
    val retryThread = AtomicReference<Thread>()
    val result =
      ThreadUtil.callWithLargeStackOnStackOverflow(largeStackSize = RETRY_STACK_SIZE) {
        if (invocationCount.getAndIncrement() == 0) {
          firstThread.set(Thread.currentThread())
          throw StackOverflowError("simulated")
        }
        retryThread.set(Thread.currentThread())
        99
      }
    assertThat(result).isEqualTo(99)
    assertThat(invocationCount.get()).isEqualTo(2)
    assertThat(firstThread.get()).isSameInstanceAs(Thread.currentThread())
    assertThat(retryThread.get()).isNotSameInstanceAs(Thread.currentThread())
    assertThat(retryThread.get().name).isEqualTo("large-stack-retry")
  }

  @Test
  fun testCallWithLargeStackOnStackOverflow_nonStackOverflowPropagatesWithoutRetry() {
    val invocationCount = AtomicInteger(0)
    val thrown =
      assertThrows(IllegalStateException::class.java) {
        ThreadUtil.callWithLargeStackOnStackOverflow<Unit>(largeStackSize = RETRY_STACK_SIZE) {
          invocationCount.incrementAndGet()
          throw IllegalStateException("boom")
        }
      }
    assertThat(thrown).hasMessageThat().isEqualTo("boom")
    assertThat(invocationCount.get()).isEqualTo(1)
  }

  @Test
  fun testCreateDaemonThread() {
    val ran = AtomicBoolean(false)
    val thread = ThreadUtil.createDaemonThread(name = "test-daemon") { ran.set(true) }
    assertThat(thread.isDaemon).isTrue()
    assertThat(thread.name).isEqualTo("test-daemon")
    assertThat(thread.isAlive).isFalse()
    assertThat(ran.get()).isFalse()
    thread.start()
    thread.join()
    assertThat(ran.get()).isTrue()
  }

  @Test
  fun testCallWithLargeStackOnStackOverflow_realDeepRecursionCompletesOnLargeStack() {
    // Deep enough to overflow a default thread stack; the large-stack retry completes it. If the
    // ambient -Xss is already large enough that the first attempt does not overflow, the result is
    // still correct -- the test asserts the value either way.
    val depth = 200_000
    val result =
      ThreadUtil.callWithLargeStackOnStackOverflow(largeStackSize = RETRY_STACK_SIZE) {
        sumToDepth(depth)
      }
    assertThat(result).isEqualTo(depth)
  }

  // Non-tail recursion (the `1 +` runs after the call), so Kotlin cannot turn it into a loop -- it
  // genuinely consumes one stack frame per level.
  private fun sumToDepth(n: Int): Int = if (n == 0) 0 else 1 + sumToDepth(n - 1)

  companion object {
    // Comfortably holds the deepest test recursion (~200k trivial frames, ~20 MB) with margin,
    // while staying far below the production default so the test does not reserve a large virtual
    // stack in a constrained CI/sandbox.
    private val RETRY_STACK_SIZE = SpaceSize.megaBytes(64)
  }
}
