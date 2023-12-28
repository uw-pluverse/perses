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
package org.perses.reduction

import com.google.common.collect.ImmutableList
import org.perses.reduction.AbstractProgramReductionDriver.StatsOfFilesBeingReduced
import org.perses.reduction.ReducerAnnotation.ReductionResultSizeTrend.BEST_RESULT_SIZE_INCREASE
import org.perses.reduction.ReducerScheduler.FixpointDecision.CONTINUE_CHANGE_IN_RESULT_BUT_NOT_SMALLER
import org.perses.reduction.ReducerScheduler.FixpointDecision.CONTINUE_SMALLER_RESULT
import org.perses.reduction.ReducerScheduler.FixpointDecision.STOP_NON_DELETION_ITERATION_LIMIT_REACHED
import org.perses.reduction.ReducerScheduler.FixpointDecision.STOP_NO_CHANGE_IN_RESULT
import org.perses.util.Util.lazyAssert

class ReducerScheduler(
  private val fixpointMode: Boolean,
  private val reducerContext: ReducerContext,
  private val mainReducerCreator: ITokenReducerCreator,
  private val auxiliaryReducerCreators: ImmutableList<ITokenReducerCreator>,
  computeStatistics: () -> StatsOfFilesBeingReduced,
  reducerRunner: (AbstractTokenReducer) -> Unit,
  private val actionBeforeNonFirstRunOfMainReducers: () -> Unit,
) {

  private val schedulerEvents = SchedulerEventHistory()

  fun run() {
    run {
      // Always run the main reducers first, continuously if fixpoint is enabled.
      var fixpointDecision = callMainReducersOnce()
      while (fixpointMode && fixpointDecision.continueFixpoint) {
        actionBeforeNonFirstRunOfMainReducers()
        fixpointDecision = callMainReducersOnce()
      }
    }

    val vulcanFixpointMode = reducerContext.configuration.vulcanConfig.vulcanFixpoint
    var auxiliaryReducerMadeProgress: Boolean
    do { // vulcan fixpoint
      auxiliaryReducerMadeProgress = false
      auxiliaryReducerCreators.forEach { creator ->
        while (true) {
          val statsBeforeAuxReducers = recordStatsSnapshotIfNotYet()
          creator.create(reducerContext).forEach { callReducer(it) }
          val auxFixpointDecision = computeFixpointDecision(statsBeforeAuxReducers)
          if (!auxFixpointDecision.continueFixpoint) {
            break
          }
          if (auxFixpointDecision == CONTINUE_SMALLER_RESULT) {
            auxiliaryReducerMadeProgress = true
          }
          actionBeforeNonFirstRunOfMainReducers()
          val mainDecision = callMainReducersOnce()
          if (mainDecision.continueFixpoint) {
            /* If the aux reducer does not make progress but the main reducer does,
             * then the progress of the main reducer is still attributed to the aux reducer.
             */
            auxiliaryReducerMadeProgress = true
          }
        }
      }
    } while (vulcanFixpointMode && auxiliaryReducerMadeProgress)
  }

  private fun callMainReducersOnce(): FixpointDecision {
    val initialStatistics = recordStatsSnapshotIfNotYet()
    mainReducerCreator.create(reducerContext).forEach {
      callReducer(it)
    }
    return computeFixpointDecision(initialStatistics)
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

  private fun computeFixpointDecision(
    initialStatsEvent: StatsSnapshotEvent,
  ): FixpointDecision {
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
      return STOP_NO_CHANGE_IN_RESULT
    }
    if (initialStatistics.tokenCount == currentStatistics.tokenCount) {
      ++numOfNonDeletionIteration
    } else {
      numOfNonDeletionIteration = 0
      return CONTINUE_SMALLER_RESULT
    }
    if (numOfNonDeletionIteration
      >= reducerContext.configuration.vulcanConfig.nonDeletionIterationLimit
    ) {
      return STOP_NON_DELETION_ITERATION_LIMIT_REACHED
    }
    return CONTINUE_CHANGE_IN_RESULT_BUT_NOT_SMALLER
  }

  private enum class FixpointDecision(
    val continueFixpoint: Boolean,
    val reason: String,
  ) {
    STOP_NO_CHANGE_IN_RESULT(
      continueFixpoint = false,
      reason = "No change in the program.",
    ),
    STOP_NON_DELETION_ITERATION_LIMIT_REACHED(
      continueFixpoint = false,
      reason = "The limit of non-deletion iterations has been reached. The program" +
        "has been changed multiple times but the size always remains.",
    ),
    CONTINUE_SMALLER_RESULT(
      continueFixpoint = true,
      reason = "The source file is smaller.",
    ),
    CONTINUE_CHANGE_IN_RESULT_BUT_NOT_SMALLER(
      continueFixpoint = true,
      reason = "The program is changed, but its size remains the same.",
    ),
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
