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
 * drdd with the paper's schedule: the partition size S halves from the original list size. Each
 * round cuts the current list into ceil(|list| / S) balanced blocks, as ddmin does, instead of the
 * paper's fixed-stride blocks of exactly S with a short remainder; block shape only steers which
 * 1-minimal result is reached, not the guarantee.
 */
class DeferredRestartDeltaDebugger<T : Any, PropertyPayload>(
  arguments: ListMinimizerArguments<T, PropertyPayload>,
) : AbstractDeferredRestartDeltaDebugger<T, PropertyPayload>(arguments) {
  private var partitionSize: Int? = null

  override fun computeNextCoarseRound(): CoarseRound<T>? {
    val size = (partitionSize ?: best.size) / 2
    partitionSize = size
    if (size == 0) {
      return null
    }
    val countOfBlocks = (best.size + size - 1) / size
    return CoarseRound(
      granularity = size,
      blocks = PristineDeltaDebugger.countBasedPartition(best, countOfBlocks).partitions,
    )
  }
}
