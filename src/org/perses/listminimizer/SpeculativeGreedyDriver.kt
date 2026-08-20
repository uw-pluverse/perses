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
package org.perses.listminimizer

import com.google.common.collect.ImmutableList

/**
 * Drives a [DeletionCandidateCursor]: it keeps up to [concurrency] candidates in flight and commits
 * the first interesting one in enumeration order, then lets the cursor re-enumerate against the
 * shrunk best.
 *
 * Determinism: candidates are always consumed in submission order (via [ArrayDeque.removeFirst], not
 * completion order), and when one commits, the speculated candidates that follow it are cancelled
 * and retried — reconstructed against the new best, in their original order, ahead of anything the
 * cursor produces next. The committed sequence, and therefore the result, is thus independent of how
 * the individual tests happen to finish or of [concurrency]. With [concurrency] == 1 this degenerates
 * to a plain sequential greedy search that never cancels or retries anything.
 */
class SpeculativeGreedyDriver<T : Any, PropertyPayload>(
  private val concurrency: Int,
  private val currentBest: () -> ImmutableList<ElementWrapper<T>>,
  private val submit: (Candidate<T>) -> PropertyTestHandle<T, PropertyPayload>,
  private val commit: (Candidate<T>, PropertyPayload) -> Unit,
) {
  init {
    require(concurrency >= 1) { "concurrency must be positive: $concurrency" }
  }

  fun run(cursor: DeletionCandidateCursor<T>) {
    val inFlight = ArrayDeque<Submission<T, PropertyPayload>>()
    // The deletions to retry (cancelled followers of a committed candidate), drained before the
    // cursor and reconstructed against the current best.
    val toRetry = ArrayDeque<ImmutableList<ElementWrapper<T>>>()

    fun nextCandidate(): Candidate<T>? {
      while (toRetry.isNotEmpty()) {
        val deleted = toRetry.removeFirst()
        // Drop deletions that now overlap an applied deletion; the rest are still valid.
        if (deleted.none { it.deleted }) {
          return Candidate.DeletionsFromOriginal(original = currentBest(), deleted_ = deleted)
        }
      }
      return cursor.next()
    }

    fun fill() {
      while (inFlight.size < concurrency) {
        val candidate = nextCandidate() ?: break
        inFlight.addLast(Submission(candidate, submit(candidate)))
      }
    }

    fill()
    while (inFlight.isNotEmpty()) {
      val head = inFlight.removeFirst()
      val result = head.handle.get()
      if (result is ListMinimizerPropertyTestResult.Completed &&
        result.result.isInteresting &&
        head.candidate.deletedWrappers.none { it.deleted }
      ) {
        val followers = ArrayDeque<ImmutableList<ElementWrapper<T>>>()
        while (inFlight.isNotEmpty()) {
          val follower = inFlight.removeFirst()
          follower.handle.requestToCancel()
          followers.addLast(follower.candidate.deletedWrappers)
        }
        while (toRetry.isNotEmpty()) {
          followers.addLast(toRetry.removeFirst())
        }
        toRetry.addAll(followers)
        commit(head.candidate, result.payload)
        cursor.onCommitted()
      }
      fill()
    }
  }

  private class Submission<T : Any, PropertyPayload>(
    val candidate: Candidate<T>,
    val handle: PropertyTestHandle<T, PropertyPayload>,
  )
}
