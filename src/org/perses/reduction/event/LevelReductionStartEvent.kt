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
package org.perses.reduction.event

import org.perses.reduction.io.PerFileSizeMetrics

class LevelReductionStartEvent internal constructor(
  val currentFixpointIteration: FixpointIterationStartEvent,
  currentTimeMillis: Long,
  perFileSizeMetrics: PerFileSizeMetrics,
  val level: Int,
  val nodeCountOnLevel: Int,
) : AbstractStartEvent(currentTimeMillis, perFileSizeMetrics) {
  val iteration = currentFixpointIteration.iteration

  override val prefixLabelFromRootToHere: String
    get() = currentFixpointIteration.prefixLabelFromRootToHere

  fun createEndEvent(
    currentTimeMillis: Long,
    perFileSizeMetrics: PerFileSizeMetrics,
  ): LevelReductionEndEvent {
    check(!ended)
    ended = true
    return LevelReductionEndEvent(
      startEvent = this,
      currentTimeMillis = currentTimeMillis,
      perFileSizeMetrics = perFileSizeMetrics,
      level = level,
    )
  }

  fun createGranularityReductionStartEvent(
    currentTimeMillis: Long,
    perFileSizeMetrics: PerFileSizeMetrics,
    maxNumOfNodesPerPartition: Int,
  ): LevelGranularityReductionStartEvent =
    LevelGranularityReductionStartEvent(
      levelReductionStartEvent = this,
      currentTimeMillis = currentTimeMillis,
      perFileSizeMetrics = perFileSizeMetrics,
      maxNumOfNodesPerPartition = maxNumOfNodesPerPartition,
    )

  override fun initialPerFileSizeMetrics(): PerFileSizeMetrics =
    currentFixpointIteration.initialPerFileSizeMetrics()
}
