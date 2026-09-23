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
 * The weighted counterpart of [PristineDeferredRestartDeltaDebugger]: the granularity W halves from
 * the total weight of the list, and each block is a maximal contiguous run whose weight stays within
 * W (an element heavier than W forms a block by itself), so with unit weights it performs exactly
 * the tests the pristine drdd performs. Kept beside [WeightedDeferredRestartDeltaDebugger], which
 * halves every surviving block by weight instead, to measure whether the block shape matters.
 */
class PristineWeightedDeferredRestartDeltaDebugger<T : Any, PropertyPayload>(
  arguments: ListMinimizerArguments<T, PropertyPayload>,
) : AbstractHalvingScheduleDeferredRestartDeltaDebugger<T, PropertyPayload>(arguments) {
  override fun createElementWrapperFor(
    index: Int,
    element: T,
  ): ElementWrapper<T> = ElementWrapper(index, element, arguments.weightProvider.weight(element))

  override fun computeInitialGranularity(): Int = WeightedDeltaDebugger.computeSum(best)

  override fun partitionIntoBlocks(granularity: Int): List<List<ElementWrapper<T>>> {
    val blocks = mutableListOf<List<ElementWrapper<T>>>()
    var currentBlock = mutableListOf<ElementWrapper<T>>()
    var currentWeight = 0
    for (element in best) {
      val weight = WeightedDeltaDebugger.getWeight(element)
      if (currentBlock.isNotEmpty() && currentWeight + weight > granularity) {
        blocks.add(currentBlock)
        currentBlock = mutableListOf()
        currentWeight = 0
      }
      currentBlock.add(element)
      currentWeight += weight
    }
    if (currentBlock.isNotEmpty()) {
      blocks.add(currentBlock)
    }
    return blocks
  }
}
