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
package org.perses.reduction

import java.util.concurrent.ConcurrentLinkedQueue

/**
 * Asks the whole reduction to wind down, for a reason other than having reached its fixpoint: in
 * RECORD mode, recording as many problems as requested, after which further queries only cost time.
 *
 * Cooperative: nothing is interrupted. The test-script executor refuses every query from then on, so
 * the reducer that is running finishes without running the test script, and the drivers and
 * `AbstractMain` start nothing new. A place that does not check the signal makes the reduction stop
 * later, never wrongly.
 *
 * Shared by every driver of a reduction, through `GlobalContext`. Thread-safe, because a reducer may
 * request the stop from any thread.
 */
class ReductionStopSignal {
  private val requests = ConcurrentLinkedQueue<StopRequest>()

  val isStopRequested: Boolean
    get() = requests.isNotEmpty()

  /** Every request, in the order they were made. Later ones still count: each names its requester. */
  val stopRequests: List<StopRequest>
    get() = requests.toList()

  fun requestStop(reason: String) {
    requests.add(
      StopRequest(
        reason = reason,
        threadName = Thread.currentThread().name,
        // Dropping this frame leaves the requester's as the first.
        stackTrace = Throwable().stackTrace.drop(1),
      ),
    )
  }

  /** A stop that was requested, with where it was requested from, since a reason alone may not say. */
  data class StopRequest(
    val reason: String,
    val threadName: String,
    val stackTrace: List<StackTraceElement>,
  ) {
    fun describe(): String =
      buildString {
        append(reason).append(" Requested on thread ").append(threadName).append(':')
        stackTrace.forEach { append("\n\tat ").append(it) }
      }
  }
}
