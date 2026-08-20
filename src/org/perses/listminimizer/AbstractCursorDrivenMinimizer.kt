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

/**
 * Base class for greedy list minimizers whose search is a priority-ordered enumeration of candidate
 * deletions: subclasses supply the enumeration as a [DeletionCandidateCursor] and inherit the
 * shared testing/committing loop, which currently runs sequentially.
 */
abstract class AbstractCursorDrivenMinimizer<T : Any, PropertyPayload>(
  arguments: ListMinimizerArguments<T, PropertyPayload>,
  enableCache: Boolean = false,
  enableCacheRefresh: Boolean = false,
) : AbstractListMinimizer<T, PropertyPayload>(arguments, enableCache, enableCacheRefresh) {
  protected abstract fun createCursor(): DeletionCandidateCursor<T>

  final override fun reduceNonEmptyInput() {
    val concurrency = arguments.concurrency
    SpeculativeGreedyDriver<T, PropertyPayload>(
      concurrency = concurrency,
      currentBest = { best },
      submit =
        if (concurrency > 1) {
          { candidate ->
            arguments.submitProperty(candidate, sizeOfCurrentMinimizationResult = best.size)
          }
        } else {
          // The plain sequential path, byte-for-byte the pre-concurrency behavior. The result is
          // its own handle, so no wrapping is needed.
          { candidate -> testProperty(candidate) }
        },
      commit = { candidate, payload ->
        candidate.deletedWrappers.forEach { it.markAsDeleted() }
        updateBest(candidate.candidateWrappers, payload)
      },
    ).run(createCursor())
  }
}
