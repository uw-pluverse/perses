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
package org.perses.reduction.reducer.token

import com.google.common.base.Objects
import com.google.common.collect.ImmutableList
import org.perses.reduction.FixpointReductionState
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.spartree.SparTree

abstract class AbstractConcurrentTokenSlicer(
  val slicerAnnotation: AbstractTokenSlicerAnnotation,
  reducerContext: ReducerContext,
) : AbstractTokenSlicerReducer(slicerAnnotation, reducerContext) {

  init {
    require(slicerAnnotation.granularity > 0) {
      "$slicerAnnotation"
    }
  }

  // TODO: This algorithm need to be parallelized.
  override fun internalReduce(fixpointReductionState: FixpointReductionState) {
    sliceTreeForGivenGranularity(fixpointReductionState, slicerAnnotation.granularity)
  }

  private fun sliceTreeForGivenGranularity(
    fixpointReductionState: FixpointReductionState,
    tokenSlicingGranularity: Int,
  ) {
    val tree = fixpointReductionState.sparTree.getTreeRegardlessOfParsability()
    val slicingStartEvent = fixpointReductionState
      .fixpointIterationStartEvent
      .createTokenSlicingStartEvent(
        currentTimeMillis = System.currentTimeMillis(),
        programSize = tree.programSnapshot.tokenCount(),
        tokenSlicingGranularity = tokenSlicingGranularity,
      )
    listenerManager.onSlicingTokensStart(slicingStartEvent)
    createSequenceOfIndependentSlicingTasks(tokenSlicingGranularity, tree)
      .forEach {
        SlicingTaskConcurrentExecutor(
          it.tasks,
          workingDequeExpectedSize = executorService.specifiedNumOfThreads + 2,
        ).run()
      }
    val slicingEndEvent = slicingStartEvent.createEndEvent(
      currentTimeMillis = System.currentTimeMillis(),
      programSize = tree.programSnapshot.tokenCount(),
    )
    listenerManager.onSlicingTokensEnd(slicingEndEvent)
  }

  abstract fun createSequenceOfIndependentSlicingTasks(
    tokenSlicingGranularity: Int,
    tree: SparTree,
  ): Sequence<IndependentSlicingTasks>

  data class IndependentSlicingTasks(
    val tasks: ImmutableList<AbstractSlicingTask>,
  )

  // TODO: testing
  abstract class AbstractTokenSlicerAnnotation(
    val namePrefix: String,
    val granularity: Int,
    description: String,
  ) : ReducerAnnotation(
    shortName = "$namePrefix@$granularity",
    description = description,
    deterministic = true,
    reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE,
  ) {

    init {
      require(granularity > 0)
    }

    final override fun hashCode(): Int {
      return Objects.hashCode(this::class.java, namePrefix, granularity)
    }

    final override fun equals(other: Any?): Boolean {
      if (other == null) {
        return false
      }
      if (other::class.java != this::class.java) {
        return false
      }
      val o = other as AbstractTokenSlicerAnnotation
      if (namePrefix != o.namePrefix) {
        return false
      }
      return granularity == o.granularity
    }
  }
}
