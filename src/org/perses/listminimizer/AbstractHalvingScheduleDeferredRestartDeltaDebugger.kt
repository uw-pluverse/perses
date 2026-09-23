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
 * drdd with the paper's schedule: the granularity halves from its initial value every round, and
 * each round re-cuts the whole current list at that granularity -- unlike
 * [WeightedDeferredRestartDeltaDebugger], which splits the blocks that survived the previous round.
 */
abstract class AbstractHalvingScheduleDeferredRestartDeltaDebugger<T : Any, PropertyPayload>(
  arguments: ListMinimizerArguments<T, PropertyPayload>,
) : AbstractDeferredRestartDeltaDebugger<T, PropertyPayload>(arguments) {
  private var granularity: Int? = null

  protected abstract fun computeInitialGranularity(): Int

  /** Cuts [best] into contiguous, non-empty blocks of at most about [granularity] each. */
  protected abstract fun partitionIntoBlocks(granularity: Int): List<List<ElementWrapper<T>>>

  final override fun computeNextCoarseRound(): CoarseRound<T>? {
    val next = (granularity ?: computeInitialGranularity()) / 2
    granularity = next
    if (next == 0) {
      return null
    }
    return CoarseRound(granularity = next, blocks = partitionIntoBlocks(next))
  }
}
