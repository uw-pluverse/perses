/*
 * Copyright (C) 2018-2024 University of Waterloo.
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

class LevelGranularityReductionStartEvent(
  val levelReductionStartEvent: LevelReductionStartEvent,
  currentTimeMillis: Long,
  programSize: Int,
  val maxNumOfNodesPerPartition: Int,
) :
  AbstractStartEvent(currentTimeMillis, programSize) {

  val iteration = levelReductionStartEvent.iteration

  fun createEndEvent(
    currentTimeMillis: Long,
    programSize: Int,
    maxNumOfNodesPerPartition: Int,
  ): LevelGranularityReductionEndEvent {
    check(!ended)
    ended = true
    return LevelGranularityReductionEndEvent(
      startEvent = this,
      currentTimeMillis = currentTimeMillis,
      programSize = programSize,
      maxNumOfNodesPerPartition = maxNumOfNodesPerPartition,
    )
  }

  override fun initialProgramSize(): Int {
    return levelReductionStartEvent.initialProgramSize()
  }
}
