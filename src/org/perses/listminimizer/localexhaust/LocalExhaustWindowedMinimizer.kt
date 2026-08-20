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
package org.perses.listminimizer.localexhaust

import org.perses.listminimizer.AbstractCursorDrivenMinimizer
import org.perses.listminimizer.DeletionCandidateCursor
import org.perses.listminimizer.ListMinimizerArguments

class LocalExhaustWindowedMinimizer<T : Any, PropertyPayload>(
  arguments: ListMinimizerArguments<T, PropertyPayload>,
) : AbstractCursorDrivenMinimizer<T, PropertyPayload>(arguments) {
  val extraArguments =
    arguments.localExhaustMinimizerArguments
      ?: error("Arguments must be non-null in ${this::class}")

  val windowSize: Int
    get() = extraArguments.windowSize

  override fun createCursor(): DeletionCandidateCursor<T> =
    LocalExhaustCursor(windowSize = windowSize, initialBest = best, currentBest = { best })
}
