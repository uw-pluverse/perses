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

import java.util.concurrent.atomic.AtomicReference

object ThreadUtil {
  /**
   * Named-parameter factory for a **daemon** worker [Thread] (the [Thread] constructor is Java
   * and so cannot take Kotlin named arguments). Daemon is baked in rather than offered as an
   * opt-in flag so a stray or wedged worker can never hold up JVM shutdown -- the safe default
   * every ad-hoc worker should use, matching the codebase's pooled threads (see
   * [DaemonThreadPool]). [stackSizeBytes] is the requested native stack size; 0 (the default)
   * lets the JVM pick, matching `Thread(group, target, name, 0)`. The thread is created but not
   * started.
   */
  fun createDaemonThread(
    name: String,
    stackSizeBytes: Long = 0L,
    threadGroup: ThreadGroup? = null,
    task: () -> Unit,
  ): Thread =
    Thread(threadGroup, Runnable { task() }, name, stackSizeBytes).apply {
      isDaemon = true
    }

  // Native stack for the parse retry thread (the default for
  // [callWithLargeStackOnStackOverflow]). Off-heap and lazily committed, so this generous
  // ceiling costs only the nesting depth actually used (a few MB) and does not draw from -Xmx.
  // 512 MB clears any realistic center-embedded nesting; a deeper input still overflows and is
  // reported by the caller as unparsable.
  val DEFAULT_LARGE_RETRY_STACK_SIZE: SpaceSize = SpaceSize.megaBytes(512)

  /**
   * Runs [supplier] on the calling thread; if it overflows the stack, retries it exactly once on
   * a dedicated thread whose native stack is [largeStackSize]. A deeply nested input (e.g. an
   * s-expression nested thousands deep) makes a recursive-descent parse -- and the recursive
   * tree walk that follows -- exhaust the default thread stack; the retry raises the ceiling
   * only for the one thread that needs it, instead of enlarging every thread's stack via a
   * global -Xss. The large stack is native, off-heap memory committed lazily page by page, so a
   * generous size costs only the depth actually used and never draws from -Xmx.
   *
   * [supplier] MUST be re-runnable from scratch: a StackOverflowError can unwind mid-computation
   * with the partial result already discarded, so the retry rebuilds a fresh result rather than
   * resuming. The retry only raises the ceiling -- a pathologically deeper input can still
   * overflow [largeStackSize], and that StackOverflowError propagates to the caller as the
   * honest "too deep" signal. Only [StackOverflowError] triggers the retry; every other
   * throwable from the first attempt propagates unchanged.
   */
  fun <T> callWithLargeStackOnStackOverflow(
    largeStackSize: SpaceSize = DEFAULT_LARGE_RETRY_STACK_SIZE,
    supplier: () -> T,
  ): T =
    try {
      supplier()
    } catch (_: StackOverflowError) {
      val resultHolder = AtomicReference<T>()
      val throwableHolder = AtomicReference<Throwable>()
      // A one-off worker for a rare retry, not pooled: a pool would pin the large stack
      // reservation for its whole lifetime, whereas this thread releases it on exit.
      // createDaemonThread makes it a daemon so a wedged retry can never hold up JVM shutdown;
      // we still join() it on the normal path.
      val thread =
        createDaemonThread(
          name = "large-stack-retry",
          stackSizeBytes = largeStackSize.bytes,
        ) {
          try {
            resultHolder.set(supplier())
          } catch (t: Throwable) {
            throwableHolder.set(t)
          }
        }
      thread.start()
      try {
        thread.join()
      } catch (e: InterruptedException) {
        thread.interrupt()
        Thread.currentThread().interrupt()
        throw e
      }
      throwableHolder.get()?.let { throw it }
      resultHolder.get()
    }
}
