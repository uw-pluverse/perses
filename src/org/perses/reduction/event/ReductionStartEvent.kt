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

import org.perses.reduction.AbstractReducerNameAndDesc
import org.perses.spartree.AbstractUnmodifiableSparTree
import java.lang.ref.WeakReference

class ReductionStartEvent(
  currentTimeMillis: Long,
  val tree: WeakReference<AbstractUnmodifiableSparTree>,
  programSize: Int,
) : AbstractStartEvent(
  currentTimeMillis,
  programSize,
) {

  private var currentIteration = 0

  override fun initialProgramSize() = programSize

  fun nextFixpointIteration(
    programSize: Int,
    reducerClass: AbstractReducerNameAndDesc,
    sparTree: AbstractUnmodifiableSparTree,
    testScriptStatistics: TestScriptExecutorServiceStatisticsSnapshot,
  ): FixpointIterationStartEvent {
    check(!ended)
    return FixpointIterationStartEvent(
      reductionStartEvent = this,
      currentTimeMillis = System.currentTimeMillis(),
      programSize = programSize,
      iteration = ++currentIteration,
      reducerClass = reducerClass,
      outdatedTree = WeakReference(sparTree),
      testScriptStatistics = testScriptStatistics,
    )
  }

  fun createEndEvent(
    programSize: Int,
    testScriptStatistics: TestScriptExecutorServiceStatisticsSnapshot,
  ): ReductionEndEvent {
    check(!ended)
    ended = true
    return ReductionEndEvent(
      startEvent = this,
      currentTimeMillis = System.currentTimeMillis(),
      programSize = programSize,
      testScriptExecutorServiceStatistics = testScriptStatistics,
    )
  }
}
