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
package org.perses.listminimizer.xfs

import com.google.common.collect.ImmutableList
import org.perses.listminimizer.AbstractListMinimizer
import org.perses.listminimizer.Candidate
import org.perses.listminimizer.ElementWrapper
import org.perses.listminimizer.ListMinimizerArguments
import org.perses.listminimizer.Partition
import org.perses.reduction.CandidateOutcome
import org.perses.util.CollectionUtil
import java.util.ArrayDeque

abstract class AbstractTreeTraversalBasedListMinimizer<T : Any, PropertyPayload>(
  arguments: ListMinimizerArguments<T, PropertyPayload>,
  protected val splitPolicy: SplitPolicy,
) : AbstractListMinimizer<T, PropertyPayload>(arguments) {
  override fun reduceNonEmptyInput() {
    val initialPartition = Partition(best)
    val startPartitions = initialPartition.splitEvently()
    val worklist = ArrayDeque<Partition<ElementWrapper<T>>>()
    addToWorklist(worklist, startPartitions)
    while (worklist.isNotEmpty()) {
      val partition = pollFromWorklist(worklist)
      val deletedInThisIteration = partition.asImmutableList()
      val testResult =
        testProperty(
          Candidate.DeletionsFromOriginal(original = best, deleted_ = deletedInThisIteration),
        ).get()
      if (testResult !is CandidateOutcome.Interesting) {
        val splits =
          when (splitPolicy) {
            SplitPolicy.EVEN -> partition.splitEvently()
            SplitPolicy.WEIGHTED_EVEN ->
              partition.weightedSplit { elementWrapper ->
                arguments.weightProvider.weight(elementWrapper.element)
              }
          }
        addToWorklist(worklist, splits)
        continue
      } else {
        updateBest(CollectionUtil.computeDifference(best, deletedInThisIteration), testResult.payload)
      }
    }
  }

  protected abstract fun pollFromWorklist(
    worklist: ArrayDeque<Partition<ElementWrapper<T>>>,
  ): Partition<ElementWrapper<T>>

  protected abstract fun addToWorklist(
    worklist: ArrayDeque<Partition<ElementWrapper<T>>>,
    partitions: ImmutableList<Partition<ElementWrapper<T>>>,
  )

  enum class SplitPolicy {
    EVEN,
    WEIGHTED_EVEN,
  }
}
