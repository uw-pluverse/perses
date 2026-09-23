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

import org.perses.util.toImmutableList

/**
 * drdd with blocks balanced by weight, as [WeightedDeltaDebugger] cuts them: each round splits every
 * block that survived the previous round into two halves of about equal weight. The granularity of
 * a round is the weight of its heaviest block, so the partition size bounds in
 * [DeferredRestartDeltaDebuggerArguments] are weights here.
 */
class WeightedDeferredRestartDeltaDebugger<T : Any, PropertyPayload>(
  arguments: ListMinimizerArguments<T, PropertyPayload>,
) : AbstractDeferredRestartDeltaDebugger<T, PropertyPayload>(arguments) {
  private var blocks: List<Partition<ElementWrapper<T>>>? = null

  override fun createElementWrapperFor(
    index: Int,
    element: T,
  ): ElementWrapper<T> = ElementWrapper(index, element, arguments.weightProvider.weight(element))

  override fun computeNextCoarseRound(): CoarseRound<T> {
    val survivingBlocks =
      (blocks ?: listOf(Partition(best))).mapNotNull { block ->
        block
          .filter { !it.deleted }
          .takeIf { it.isNotEmpty() }
          ?.let { Partition(it.toImmutableList()) }
      }
    val nextBlocks =
      survivingBlocks.flatMap { block ->
        if (block.size == 1) {
          listOf(block)
        } else {
          block.weightedSplit { WeightedDeltaDebugger.getWeight(it) }
        }
      }
    blocks = nextBlocks
    return CoarseRound(
      granularity = nextBlocks.maxOf { WeightedDeltaDebugger.computeSum(it.asImmutableList()) },
      blocks = nextBlocks,
    )
  }
}
