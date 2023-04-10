/*
 * Copyright (C) 2018-2022 University of Waterloo.
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
package org.perses.reduction

import com.google.common.collect.ImmutableList
import org.perses.reduction.AbstractProgramReductionDriver.StatsOfFilesBeingReduced
import org.perses.reduction.ReducerAnnotation.ReductionResultSizeTrend.BEST_RESULT_SIZE_INCREASE
import org.perses.util.Util.lazyAssert

class ReducerScheduler(
  private val fixpointMode: Boolean,
  private val reducerContext: ReducerContext,
  private val mainReducerCreator: ITokenReducerCreator,
  private val auxiliaryReducerCreators: ImmutableList<ITokenReducerCreator>,
  computeStatistics: () -> StatsOfFilesBeingReduced,
  reducerRunner: (AbstractTokenReducer) -> Unit,
  private val nonDeletionIterationLimitThreshold: Int,
  private val updateAfterIteration: () -> Unit,
) {

  private val schedulerEvents = SchedulerEventHistory()

  fun run() {
    do {
      val initialStatistics = recordStatsSnapshotIfNotYet()
      mainReducerCreator.create(reducerContext).forEach {
        callReducer(it)
      }
      if (shouldExitFixpointIteration(initialStatistics)) {
        if (auxiliaryReducerCreators.isEmpty()) {
          break
        } else {
          val statsBeforeAuxReducers = recordStatsSnapshotIfNotYet()
          auxiliaryReducerCreators
            .asSequence()
            .flatMap { it.create(reducerContext) }
            .forEach { callReducer(it) }
          if (shouldExitFixpointIteration(statsBeforeAuxReducers)) {
            break
          }
        }
      }
      updateAfterIteration()
    } while (fixpointMode)
  }

  fun readSchedulerEvents(): Iterable<SchedulerEvent> = schedulerEvents.asIterable()

  private val recordStatsSnapshotIfNotYet: () -> StatsSnapshotEvent = {
    if (schedulerEvents.isLastEvent { it == null || it !is StatsSnapshotEvent }) {
      schedulerEvents.add(StatsSnapshotEvent(computeStatistics()))
    }
    val last = schedulerEvents.last()
    check(last is StatsSnapshotEvent) { "The last element is $last" }
    lazyAssert({ schedulerEvents.checkSchedulerEventsIntegrity() }) { schedulerEvents }
    last
  }

  private val callReducer = { reducer: AbstractTokenReducer ->
    reducerRunner(reducer)
    val reducerEvent = ReducerCallEvent(reducer.redcucerAnnotation)
    schedulerEvents.add(reducerEvent)
    recordStatsSnapshotIfNotYet()
    reducerEvent
  }

  private var numOfNonDeletionIteration = 0

  private fun shouldExitFixpointIteration(
    initialStatsEvent: StatsSnapshotEvent,
  ): Boolean {
    val initialStatistics = initialStatsEvent.stats
    val currentStatsSnapshotEvent = recordStatsSnapshotIfNotYet()
    val currentStatistics = currentStatsSnapshotEvent.stats
    // TODO(zhenyang): need to refactor the following code with ReducerScheduler.
    /*
      Every time the tokenCount is not reduced but the program is modified
      numOfNonDeletionTransformationAttempt will increment by 1. When the token
      number is not decreasing and the attempt times reach the pre-configured
      limit, the reduction process will be terminated. Every time the token
      number is reduced, numOfNonDeletionTransformationAttempt will be reset.
    */
    if (initialStatistics.fileContents == currentStatistics.fileContents) {
      return true
    }
    if (initialStatistics.tokenCount == currentStatistics.tokenCount) {
      ++numOfNonDeletionIteration
    } else {
      numOfNonDeletionIteration = 0
      return false
    }
    if (numOfNonDeletionIteration >= nonDeletionIterationLimitThreshold) {
      return true
    }
    return false
  }

  sealed class SchedulerEvent {
    final override fun hashCode(): Int {
      return super.hashCode()
    }

    final override fun equals(other: Any?): Boolean {
      return super.equals(other)
    }
  }

  data class ReducerCallEvent(val reducer: ReducerAnnotation) : SchedulerEvent()

  data class StatsSnapshotEvent(val stats: StatsOfFilesBeingReduced) : SchedulerEvent()

  internal class SchedulerEventHistory {

    private val history = mutableListOf<SchedulerEvent>()

    inline fun isLastEvent(predicate: (SchedulerEvent?) -> Boolean): Boolean {
      val last = history.lastOrNull()
      return predicate(last)
    }

    fun add(event: SchedulerEvent): SchedulerEvent {
      require(!history.contains(event)) { "The event $event is already in the history." }
      val last = history.lastOrNull()
      if (last == null) {
        require(event is StatsSnapshotEvent) { "The first event must be a stats event." }
      } else {
        require(last::class.java != event::class.java) {
          "$history, $event"
        }
        if (last is ReducerCallEvent) {
          require(event is StatsSnapshotEvent)
          val eventBeforeLast = history[history.size - 2]
          check(eventBeforeLast is StatsSnapshotEvent)
          if (last.reducer.reductionResultSizeTrend != BEST_RESULT_SIZE_INCREASE) {
            check(eventBeforeLast.stats.tokenCount >= event.stats.tokenCount) {
              "The reducer cannot increase the token count, but the token count increases."
            }
          }
        }
      }
      history.add(event)
      return event
    }

    fun getAllReducerEventsBetween(
      startStats: StatsSnapshotEvent,
      endStats: StatsSnapshotEvent,
    ): ImmutableList<ReducerCallEvent> {
      require(startStats !== endStats)
      val startIndex = history.indexOf(startStats)
      require(startIndex >= 0) {
        "$startIndex, $startStats, $history"
      }
      lazyAssert({ history.lastIndexOf(startStats) == startIndex }) {
        "$startIndex, $history, ${history.lastIndexOf(startStats)}"
      }
      val endIndex = history.lastIndexOf(endStats)
      require(endIndex >= 0)
      lazyAssert({ history.indexOf(endStats) == endIndex }) {
        "$endIndex, $history, ${history.indexOf(endStats)}"
      }
      require(startIndex < endIndex) { "$startIndex, $endIndex" }
      val builder = ImmutableList.builder<ReducerCallEvent>()
      for (i in startIndex + 1 until endIndex) {
        val event = history[i]
        if (event is ReducerCallEvent) {
          builder.add(event)
        }
      }
      return builder.build()
    }

    fun last() = history.lastOrNull()

    fun asIterable(): Iterable<SchedulerEvent> = history

    fun checkSchedulerEventsIntegrity(): Boolean {
      if (history.isEmpty()) {
        return true
      }
      if (history.toHashSet().size != history.size) {
        return false
      }
      return history.first() is StatsSnapshotEvent && history.zipWithNext().none { (prev, curr) ->
        prev::class.java == curr::class.java
      }
    }
  }
}
