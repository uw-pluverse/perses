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
package org.perses.reduction.scheduler

import com.google.common.annotations.VisibleForTesting
import com.google.common.collect.ImmutableList
import org.perses.program.ProgramSize
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerAnnotation.ReductionResultSizeTrend.BEST_RESULT_SIZE_INCREASE
import org.perses.reduction.ReducerResult
import org.perses.reduction.StatsOfFilesBeingReduced
import org.perses.reduction.scheduler.AbstractSchedulerEvent.ReducerCallEvent
import org.perses.reduction.scheduler.AbstractSchedulerEvent.StatsSnapshotEvent
import org.perses.reduction.scheduler.ReducerExecutionPlan.AbstractCondition.ContinueOnChange
import org.perses.reduction.scheduler.ReducerExecutionPlan.AbstractCondition.ContinueOnSmallSize
import org.perses.spartree.SparTree
import org.perses.util.Util

/**
 * Generic over the reducer, because the scheduler never reduces anything itself: it hands a reducer
 * to [reducerRunner] and reads its annotation for the event history, so the concrete type is
 * incidental. Production instantiates it with `AbstractSparTreeReducer`, whose construction needs a
 * whole `ReducerContext`; a test instantiates it with a stand-in and drives the loops through
 * [computeStatistics] alone.
 */
class ReducerScheduler<ReducerType : Any>(
  private val reducerExecutionPlan: ReducerExecutionPlan,
  private val createReducers: (ReducerAnnotation) -> ImmutableList<ReducerType>,
  private val reducerAnnotationOf: (ReducerType) -> ReducerAnnotation,
  private val computeStatistics: () -> StatsOfFilesBeingReduced,
  reducerRunner: (ReducerType) -> ReducerResult,
) {
  private val schedulerEvents = SchedulerEventHistory()

  /**
   * @return the minimal program size if the minimal tree is smaller than the current best tree
   *          that is being reduced.
   */
  fun runAndGetGlobalMinimalProgramSize(): ProgramSize<SparTree>? {
    // Always run the main reducers first, continuously if fixpoint is enabled.
    executePlan(reducerExecutionPlan.steps)

    val minProgramSize = schedulerEvents.findTreeWithMinimalProgramSizeFromHistory()
    return minProgramSize
  }

  private data class PlanExecutionBeforeAndAfterStats(
    val before: StatsSnapshotEvent,
    val after: StatsSnapshotEvent,
  )

  private fun executePlan(
    planElement: ReducerExecutionPlan.AbstractExecutionPlanStep,
  ): PlanExecutionBeforeAndAfterStats =
    when (planElement) {
      is ReducerExecutionPlan.FixpointLoopStep -> {
        executeFixpointLoop(planElement)
      }

      is ReducerExecutionPlan.UnconditionalSequentialSteps -> {
        executeUnconditionalSequence(planElement)
      }

      is ReducerExecutionPlan.AtomicReducerStep -> {
        executeAtomicReducer(planElement)
      }

      is ReducerExecutionPlan.IfProgressedThenStep -> {
        executeIfReducedThenStep(planElement)
      }
    }

  private fun executeFixpointLoop(
    fixpointLoop: ReducerExecutionPlan.FixpointLoopStep,
  ): PlanExecutionBeforeAndAfterStats {
    val before = recordStatsSnapshotIfNotYet()
    var countOfNonDeletions = 0

    while (true) {
      val result = executePlan(fixpointLoop.body)
      val decision = computeFixpointDecision(result.before, result.after)
      if (!decision.continueFixpoint) {
        break
      }
      if (decision.refreshesNonDeletionBudget) {
        countOfNonDeletions = 0
        continue
      }
      ++countOfNonDeletions
      when (val continueCondition = fixpointLoop.continueCondition) {
        is ContinueOnSmallSize -> {
          if (!decision.isSmaller) {
            break
          }
        }

        is ContinueOnChange -> {
          if (countOfNonDeletions >= continueCondition.maxCountOfAllowedChanges) {
            break
          }
        }
      }
    }
    val after = recordStatsSnapshotIfNotYet()
    return PlanExecutionBeforeAndAfterStats(before = before, after = after)
  }

  private fun executeUnconditionalSequence(
    sequence: ReducerExecutionPlan.UnconditionalSequentialSteps,
  ): PlanExecutionBeforeAndAfterStats {
    val before = recordStatsSnapshotIfNotYet()
    sequence.reducers.forEach { executePlan(it) }
    val after = recordStatsSnapshotIfNotYet()
    return PlanExecutionBeforeAndAfterStats(before = before, after = after)
  }

  private fun executeAtomicReducer(
    atomicReducer: ReducerExecutionPlan.AtomicReducerStep,
  ): PlanExecutionBeforeAndAfterStats {
    val before = recordStatsSnapshotIfNotYet()
    createReducers(atomicReducer.reducer).forEach { callReducer(it) }
    val after = recordStatsSnapshotIfNotYet()
    return PlanExecutionBeforeAndAfterStats(before = before, after = after)
  }

  private fun executeIfReducedThenStep(
    step: ReducerExecutionPlan.IfProgressedThenStep,
  ): PlanExecutionBeforeAndAfterStats {
    val before = recordStatsSnapshotIfNotYet()
    val conditionResult = computeFixpointDecision(executePlan(step.condition))
    if (conditionResult.continueFixpoint) {
      executePlan(step.then)
    }
    val after = recordStatsSnapshotIfNotYet()
    return PlanExecutionBeforeAndAfterStats(before = before, after = after)
  }

  private fun recordStatsSnapshotIfNotYet(): StatsSnapshotEvent {
    if (schedulerEvents.isLastEvent { it == null || it !is StatsSnapshotEvent }) {
      val currentStats = computeStatistics()
      val (numberOfNonDeletionIterations, fileContentChangedWrtPrevious) =
        schedulerEvents.lastStatsSnapshotEvent().let { lastStats ->
          if (lastStats == null) {
            check(schedulerEvents.lastEvent() == null) { "This event should be the first." }
            Pair(0, false)
          } else {
            val beforeStats = lastStats.stats
            when {
              beforeStats.size.canonicalTokenCount > currentStats.size.canonicalTokenCount -> {
                Pair(0, true)
              }

              beforeStats.fileContents == currentStats.fileContents -> {
                Pair(lastStats.numberOfNonDeletionIterations, false)
              }

              else -> {
                check(beforeStats.fileContents != currentStats.fileContents) {
                  "The file contents should be different: $beforeStats, $currentStats"
                }
                Pair(lastStats.numberOfNonDeletionIterations + 1, true)
              }
            }
          }
        }
      schedulerEvents.addStatsEvent(
        StatsSnapshotEvent(
          stats = currentStats,
          numberOfNonDeletionIterations = numberOfNonDeletionIterations,
          fileContentChangedWrtPrevious = fileContentChangedWrtPrevious,
        ),
      )
    }
    val last = schedulerEvents.lastEvent()
    check(last is StatsSnapshotEvent) { "The last element is $last" }
    Util.lazyAssert({ schedulerEvents.checkSchedulerEventsIntegrity() }) { schedulerEvents }
    return last
  }

  private val callReducer: (ReducerType) -> Unit = { reducer: ReducerType ->
    var thrownException: Exception? = null
    val result: ReducerResult? =
      try {
        reducerRunner(reducer)
      } catch (e: Exception) {
        // TODO(cnsun): need to write the exception to a file so that we get notified of the error.
        e.printStackTrace()
        thrownException = e
        null
      }
    val (exceptionStackTrace, programSizeAfterReduction) =
      when (result) {
        is ReducerResult.Reduced -> result.exception?.stackTraceToString() to result.tree
        is ReducerResult.Skipped -> null to null
        null -> thrownException?.stackTraceToString() to null
      }
    schedulerEvents.addReducerCallEvent(
      ReducerCallEvent(reducerAnnotationOf(reducer), exceptionStackTrace),
      programSizeAfterReduction = programSizeAfterReduction,
    )
    recordStatsSnapshotIfNotYet()
  }

  private fun computeFixpointDecision(
    statsBeforeAndAfter: PlanExecutionBeforeAndAfterStats,
  ): FixpointDecision =
    computeFixpointDecision(
      before = statsBeforeAndAfter.before,
      after = statsBeforeAndAfter.after,
    )

  private fun computeFixpointDecision(
    before: StatsSnapshotEvent,
    after: StatsSnapshotEvent,
  ): FixpointDecision = computeFixpointDecision(before.stats, after.stats)

  enum class FixpointDecision(
    val continueFixpoint: Boolean,
    /**
     * Whether the program shrank. Both a token decrease and a character-only decrease count, so a
     * [ContinueOnSmallSize] loop keeps running on either.
     */
    val isSmaller: Boolean,
    /**
     * Whether this iteration refreshes the budget a [ContinueOnChange] loop terminates on, i.e.
     * `--non-deletion-iteration-limit`.
     *
     * Only a token decrease does. That budget is the *only* thing that stops a loop over reducers
     * annotated `BEST_RESULT_SIZE_REMAIN` -- Vulcan's identifier and subtree replacement, which by
     * definition never shrink the token count -- so whatever refreshes it has to be a quantity that
     * cannot come back up, or the loop has no termination argument left.
     *
     * The character count is not such a quantity. Those reducers rewrite the program at a fixed
     * token count, and the program they rewrite is free to grow again: the reduction result is
     * tracked separately, as a running minimum in [SchedulerEventHistory], precisely because the
     * program being reduced is not monotone. Refreshing on a character decrease therefore let an
     * iteration that shortens an identifier cancel the budget spent by every iteration before it,
     * and a loop bounded at ten non-deletion iterations ran unbounded.
     */
    val refreshesNonDeletionBudget: Boolean,
    val reason: String,
  ) {
    STOP_NO_CHANGE_IN_RESULT(
      continueFixpoint = false,
      isSmaller = false,
      refreshesNonDeletionBudget = false,
      reason = "No change in the program.",
    ),
    CONTINUE_FEWER_TOKENS(
      continueFixpoint = true,
      isSmaller = true,
      refreshesNonDeletionBudget = true,
      reason = "The source file has fewer tokens.",
    ),
    CONTINUE_FEWER_CHARACTERS_ONLY(
      continueFixpoint = true,
      isSmaller = true,
      refreshesNonDeletionBudget = false,
      reason = "The source file has the same number of tokens, but fewer characters.",
    ),
    CONTINUE_CHANGE_IN_RESULT_BUT_NOT_SMALLER(
      continueFixpoint = true,
      isSmaller = false,
      refreshesNonDeletionBudget = false,
      reason = "The program is changed, but its size remains the same.",
    ),
  }

  class SchedulerEventHistory {
    private var minimalProgramSize: ProgramSize<SparTree>? = null

    private val history = mutableListOf<AbstractSchedulerEvent>()

    fun isLastEvent(predicate: (AbstractSchedulerEvent?) -> Boolean): Boolean {
      val last = history.lastOrNull()
      return predicate(last)
    }

    /**
     * TODO(cnsun): need to be unit-tested.
     */
    fun findTreeWithMinimalProgramSizeFromHistory(): ProgramSize<SparTree>? = minimalProgramSize

    private fun updateMinimalProgramSize(newProgramSize: ProgramSize<SparTree>?) {
      if (newProgramSize == null) {
        return
      }
      val localMin = minimalProgramSize
      if (localMin == null || newProgramSize < localMin) {
        minimalProgramSize = newProgramSize
      }
    }

    fun addStatsEvent(event: StatsSnapshotEvent) {
      add(event)
    }

    fun addReducerCallEvent(
      event: ReducerCallEvent,
      programSizeAfterReduction: ProgramSize<SparTree>?,
    ) {
      add(event)
      updateMinimalProgramSize(programSizeAfterReduction)
    }

    private fun add(event: AbstractSchedulerEvent): AbstractSchedulerEvent {
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
            check(
              eventBeforeLast.stats.size.canonicalTokenCount >=
                event.stats.size.canonicalTokenCount,
            ) {
              """The reducer cannot increase the token count, but the token count increases.
                |last: $last
                |event: $event
              """.trimMargin()
            }
          }
        }
      }
      history.add(event)
      return event
    }

    fun findAllReducerEventsBetween(
      startStats: StatsSnapshotEvent,
      endStats: StatsSnapshotEvent,
    ): ImmutableList<ReducerCallEvent> {
      require(startStats !== endStats)
      val startIndex = history.indexOf(startStats)
      require(startIndex >= 0) {
        "$startIndex, $startStats, $history"
      }
      Util.lazyAssert({ history.lastIndexOf(startStats) == startIndex }) {
        "$startIndex, $history, ${history.lastIndexOf(startStats)}"
      }
      val endIndex = history.lastIndexOf(endStats)
      require(endIndex >= 0)
      Util.lazyAssert({ history.indexOf(endStats) == endIndex }) {
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

    fun lastStatsSnapshotEvent(): StatsSnapshotEvent? =
      history.lastOrNull {
        it is StatsSnapshotEvent
      } as StatsSnapshotEvent?

    fun lastEvent() = history.lastOrNull()

    fun asList(): List<AbstractSchedulerEvent> = history

    fun checkSchedulerEventsIntegrity(): Boolean {
      if (history.isEmpty()) {
        return true
      }
      if (history.toHashSet().size != history.size) {
        return false
      }
      return history.first() is StatsSnapshotEvent &&
        history.zipWithNext().none { (prev, curr) ->
          prev::class.java == curr::class.java
        }
    }
  }

  companion object {
    @VisibleForTesting
    fun computeFixpointDecision(
      before: StatsOfFilesBeingReduced,
      after: StatsOfFilesBeingReduced,
    ): FixpointDecision =
      when {
        before.fileContents == after.fileContents -> FixpointDecision.STOP_NO_CHANGE_IN_RESULT
        after.size.canonicalTokenCount < before.size.canonicalTokenCount ->
          FixpointDecision.CONTINUE_FEWER_TOKENS
        // The reducers' own ordering, so "smaller" here means what it means when the reduction
        // result is chosen. The token counts are known equal or larger by now, so this can only
        // fire on the character counts.
        after.size < before.size -> FixpointDecision.CONTINUE_FEWER_CHARACTERS_ONLY
        else -> FixpointDecision.CONTINUE_CHANGE_IN_RESULT_BUT_NOT_SMALLER
      }
  }
}
