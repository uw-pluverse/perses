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
 * A resumable, priority-ordered enumeration of candidate deletions to try against the current
 * minimization result. This is the algorithm half of a greedy list minimizer, deliberately kept
 * free of any testing or concurrency concern so that [SpeculativeGreedyDriver] can drive the same
 * enumeration either sequentially or concurrently.
 */
interface DeletionCandidateCursor<T : Any> {
  /** The next candidate deletion to try, in the order it should be tried, or null when exhausted. */
  fun next(): Candidate<T>?

  /** Notifies the cursor that the candidate it last handed out was applied (the best has shrunk). */
  fun onCommitted()
}
