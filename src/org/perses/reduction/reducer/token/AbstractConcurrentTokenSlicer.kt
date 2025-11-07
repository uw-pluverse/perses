/*
 * Copyright (C) 2018-2025 University of Waterloo.
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
import org.perses.reduction.AbstractTokenReducer
import org.perses.reduction.FixpointReductionState
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.spartree.SparTree

abstract class AbstractConcurrentTokenSlicer(
  val slicerAnnotation: AbstractTokenSlicerAnnotation,
  reducerContext: ReducerContext,
) : AbstractTokenReducer(slicerAnnotation, reducerContext) {
  init {
    require(slicerAnnotation.windowSize > 0) {
      "$slicerAnnotation"
    }
  }

  // TODO: This algorithm need to be parallelized.
  override fun internalReduce(fixpointReductionState: FixpointReductionState) {
    val tree = fixpointReductionState.sparTree.getTreeRegardlessOfParsability()
    reducerContext.listenerManager.onSlicingTokensStart(
      fixpointReductionState
        .fixpointIterationStartEvent
        .createTokenSlicingStartEvent(
          currentTimeMillis = System.currentTimeMillis(),
          programSize = tree.programSnapshot.tokenCount,
          tokenSlicingGranularity = slicerAnnotation.windowSize,
        ),
    )
    val independendSlicingTasks =
      createSequenceOfIndependentSlicingTasks(
        slicerAnnotation.windowSize,
        tree,
      )
    independendSlicingTasks.forEach {
      val taskExecutor =
        SlicingTaskConcurrentExecutor(
          it.tasks,
          workingDequeExpectedSize = executorService.specifiedNumOfThreads + 2,
        )
      taskExecutor.run()
    }
    reducerContext.listenerManager.onSlicingTokensEnd(
      fixpointReductionState
        .fixpointIterationStartEvent
        .createTokenSlicingStartEvent(
          currentTimeMillis = System.currentTimeMillis(),
          programSize = tree.programSnapshot.tokenCount,
          tokenSlicingGranularity = slicerAnnotation.windowSize,
        ).createEndEvent(
          currentTimeMillis = System.currentTimeMillis(),
          programSize = tree.programSnapshot.tokenCount,
        ),
    )
  }

  abstract fun createSequenceOfIndependentSlicingTasks(
    tokenSlicingGranularity: Int,
    tree: SparTree,
  ): Sequence<ListOfIndependentSlicingTasks>

  data class ListOfIndependentSlicingTasks(
    val tasks: ImmutableList<out AbstractSlicingTask>,
  )

  // TODO: testing
  abstract class AbstractTokenSlicerAnnotation(
    val namePrefix: String,
    val windowSize: Int,
    description: String,
  ) : ReducerAnnotation(
      shortName = "$namePrefix@$windowSize",
      description = description,
      deterministic = true,
      reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE,
    ) {
    init {
      require(windowSize > 0) {
        "Invalid window size $windowSize. Must be greater than 0."
      }
    }

    final override fun hashCode(): Int = Objects.hashCode(this::class.java, namePrefix, windowSize)

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
      return windowSize == o.windowSize
    }
  }
}
