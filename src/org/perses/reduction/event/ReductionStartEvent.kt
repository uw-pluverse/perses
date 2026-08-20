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

import org.perses.reduction.AbstractReducerNameAndDesc
import org.perses.reduction.io.PerFileSizeMetrics

class ReductionStartEvent(
  currentTimeMillis: Long,
  perFileSizeMetrics: PerFileSizeMetrics,
  val commandLineOptions: String,
  val extraData: String? = null,
) : AbstractStartEvent(
    currentTimeMillis,
    perFileSizeMetrics,
  ) {
  private var currentIteration = 0

  override fun initialPerFileSizeMetrics(): PerFileSizeMetrics = perFileSizeMetrics

  override val prefixLabelFromRootToHere: String
    get() = ""

  fun nextFixpointIteration(
    perFileSizeMetrics: PerFileSizeMetrics,
    reducerClass: AbstractReducerNameAndDesc,
    treeStructureDumper: () -> String,
    testScriptStatistics: TestScriptExecutorServiceStatisticsSnapshot,
    extraData: String? = null,
  ): FixpointIterationStartEvent {
    check(!ended)
    return FixpointIterationStartEvent(
      reductionStartEvent = this,
      currentTimeMillis = System.currentTimeMillis(),
      perFileSizeMetrics = perFileSizeMetrics,
      iteration = ++currentIteration,
      reducerClass = reducerClass,
      treeStructureDumper = treeStructureDumper,
      testScriptStatistics = testScriptStatistics,
      extraData = extraData,
    )
  }

  fun createAdHocMessageEvent(
    perFileSizeMetrics: PerFileSizeMetrics,
    prefixLabelFromRootToHere: String,
    messageComputer: () -> Any,
  ): AdHocMessageEvent =
    AdHocMessageEvent(
      reductionStartEvent = this,
      currentTimeMillis = System.currentTimeMillis(),
      perFileSizeMetrics = perFileSizeMetrics,
      prefixLabelFromRootToHere = prefixLabelFromRootToHere,
      messageComputer = messageComputer,
    )

  fun createEndEvent(
    perFileSizeMetrics: PerFileSizeMetrics,
    testScriptStatistics: TestScriptExecutorServiceStatisticsSnapshot,
    extraData: String? = null,
  ): ReductionEndEvent {
    check(!ended)
    ended = true
    return ReductionEndEvent(
      startEvent = this,
      currentTimeMillis = System.currentTimeMillis(),
      perFileSizeMetrics = perFileSizeMetrics,
      testScriptExecutorServiceStatistics = testScriptStatistics,
      extraData = extraData,
    )
  }
}
