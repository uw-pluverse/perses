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
package org.perses.analyzer.differential

import org.perses.listener.DifferentialEvents

data class EditTimeStats(
  val minTimeMs: Long,
  val maxTimeMs: Long,
  val avgTimeMs: Long,
  val medianTimeMs: Long,
  val stdDevMs: Double,
)

data class IterationStats(
  val iteration: Int,
  val totalEvents: Int,
  val totalTokensDeleted: Int,
  val totalEdits: Int,
  val interestingEdits: Int,
  val totalTimeSeconds: Int,
  val reductionSpeed: Double,
  val editTimeStats: EditTimeStats,
  val successRate: Double,
  val tokensPerInterestedEdit: Double,
  val timePerInterestingEdit: Double,
  val timePerUninterestingEdit: Double,
)

data class EventDiffStatistics(
  val totalTokensDeleted: Int,
  val totalTimeSeconds: Int,
  val totalEvents: Int,
  val totalEdits: Int,
  val interestingEdits: Int,
  val iterationStats: List<IterationStats>,
  val totalReductionSpeed: Double,
  val totalEditTimeStats: EditTimeStats,
  val totalSuccessRate: Double,
  val totalTokensPerInterestedEdit: Double,
  val totalTimePerInterestingEdit: Double,
  val totalTimePerUninterestingEdit: Double,
) {
  companion object {
    fun calculate(events: List<DifferentialEvents.NodeReductionEvent>): EventDiffStatistics {
      val totalTokensDeleted = events.sumOf { it.deletedTokenCount }
      val totalTimeSeconds =
        if (events.isNotEmpty()) {
          events.last().endPersesTimeSeconds - events.first().startPersesTimeSeconds
        } else {
          0
        }
      val totalEdits = events.sumOf { it.editsTested.size }
      val interestingEdits =
        events.sumOf {
          it.editsTested.count { edit ->
            edit.propertyTestResult.isInteresting
          }
        }

      val totalReductionSpeed =
        if (totalTimeSeconds > 0) {
          totalTokensDeleted.toDouble() / totalTimeSeconds
        } else {
          0.0
        }

      val allEdits = events.flatMap { it.editsTested }
      val allEditTimes = allEdits.map { it.propertyTestResult.elapsedMillis.toLong() }
      val totalEditTimeStats = calculateEditTimeStats(allEditTimes)

      val totalSuccessRate = if (totalEdits > 0) interestingEdits.toDouble() / totalEdits else 0.0
      val totalTokensPerInterestedEdit =
        if (interestingEdits >
          0
        ) {
          totalTokensDeleted.toDouble() / interestingEdits
        } else {
          0.0
        }

      val totalInterestingTime =
        allEdits
          .filter {
            it.propertyTestResult.isInteresting
          }.sumOf { it.propertyTestResult.elapsedMillis.toLong() }
      val totalUninterestingTime =
        allEdits
          .filter {
            it.propertyTestResult.isNotInteresting
          }.sumOf { it.propertyTestResult.elapsedMillis.toLong() }

      val totalTimePerInteresting =
        if (interestingEdits >
          0
        ) {
          totalInterestingTime.toDouble() / interestingEdits
        } else {
          0.0
        }
      val totalTimePerUninteresting =
        if (totalEdits - interestingEdits >
          0
        ) {
          totalUninterestingTime.toDouble() / (totalEdits - interestingEdits)
        } else {
          0.0
        }

      val iterationStats =
        events.groupBy { it.fixpointIteration }.map { (iteration, iterEvents) ->
          val iterAllEdits = iterEvents.flatMap { it.editsTested }
          val iterInteresting =
            iterAllEdits.count { it.propertyTestResult.isInteresting }
          val iterTokens = iterEvents.sumOf { it.deletedTokenCount }
          val iterTime =
            if (iterEvents.isNotEmpty()) {
              iterEvents.last().endPersesTimeSeconds - iterEvents.first().startPersesTimeSeconds
            } else {
              0
            }
          val iterSpeed =
            if (iterTime > 0) {
              iterTokens.toDouble() / iterTime
            } else {
              0.0
            }

          val iterEditTimes = iterAllEdits.map { it.propertyTestResult.elapsedMillis.toLong() }
          val iterEditTimeStats = calculateEditTimeStats(iterEditTimes)

          val iterEdits = iterAllEdits.size
          val iterSuccessRate = if (iterEdits > 0) iterInteresting.toDouble() / iterEdits else 0.0
          val iterTokensPerEdit =
            if (iterInteresting >
              0
            ) {
              iterTokens.toDouble() / iterInteresting
            } else {
              0.0
            }

          val iterInterestingTime =
            iterAllEdits
              .filter {
                it.propertyTestResult.isInteresting
              }.sumOf { it.propertyTestResult.elapsedMillis.toLong() }
          val iterUninterestingTime =
            iterAllEdits
              .filter {
                it.propertyTestResult.isNotInteresting
              }.sumOf { it.propertyTestResult.elapsedMillis.toLong() }

          val iterTimePerInteresting =
            if (iterInteresting >
              0
            ) {
              iterInterestingTime.toDouble() / iterInteresting
            } else {
              0.0
            }
          val iterTimePerUninteresting =
            if (iterEdits - iterInteresting >
              0
            ) {
              iterUninterestingTime.toDouble() / (iterEdits - iterInteresting)
            } else {
              0.0
            }

          IterationStats(
            iteration = iteration,
            totalEvents = iterEvents.size,
            totalTokensDeleted = iterTokens,
            totalEdits = iterEdits,
            interestingEdits = iterInteresting,
            totalTimeSeconds = iterTime,
            reductionSpeed = iterSpeed,
            editTimeStats = iterEditTimeStats,
            successRate = iterSuccessRate,
            tokensPerInterestedEdit = iterTokensPerEdit,
            timePerInterestingEdit = iterTimePerInteresting,
            timePerUninterestingEdit = iterTimePerUninteresting,
          )
        }

      return EventDiffStatistics(
        totalTokensDeleted = totalTokensDeleted,
        totalTimeSeconds = totalTimeSeconds,
        totalEvents = events.size,
        totalEdits = totalEdits,
        interestingEdits = interestingEdits,
        iterationStats = iterationStats,
        totalReductionSpeed = totalReductionSpeed,
        totalEditTimeStats = totalEditTimeStats,
        totalSuccessRate = totalSuccessRate,
        totalTokensPerInterestedEdit = totalTokensPerInterestedEdit,
        totalTimePerInterestingEdit = totalTimePerInteresting,
        totalTimePerUninterestingEdit = totalTimePerUninteresting,
      )
    }

    private fun calculateEditTimeStats(times: List<Long>): EditTimeStats {
      if (times.isEmpty()) return EditTimeStats(0, 0, 0, 0, 0.0)
      val min = times.minOrNull() ?: 0
      val max = times.maxOrNull() ?: 0
      val avg = times.average()
      val sorted = times.sorted()
      val median =
        if (times.size % 2 == 0) {
          (sorted[times.size / 2 - 1] + sorted[times.size / 2]) / 2
        } else {
          sorted[times.size / 2]
        }
      val stdDev = Math.sqrt(times.map { Math.pow(it.toDouble() - avg, 2.0) }.average())
      return EditTimeStats(min, max, avg.toLong(), median, stdDev)
    }
  }
}
