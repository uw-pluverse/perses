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
package org.perses.listminimizer.xfs

import com.google.common.collect.ImmutableList
import org.perses.listminimizer.AbstractListInputMinimizer
import org.perses.listminimizer.Configuration
import org.perses.listminimizer.Partition
import org.perses.listminimizer.PropertyTestResultWithPayload
import org.perses.util.Util
import org.perses.util.toImmutableList
import java.util.ArrayDeque

abstract class AbstractSpecialDeltaDebugger<T : Any, PropertyPayload>(
  arguments: AbstractListInputMinimizer.Arguments<T, PropertyPayload>,
) : AbstractListInputMinimizer<T, PropertyPayload>(arguments) {

  override fun reduceNonEmptyInput() {
    val initialPartition = Partition(best)
    val startPartitions = initialPartition.splitEvently()
    val worklist = ArrayDeque<Partition<ElementWrapper<T>>>()
    addToWorklist(worklist, startPartitions)
    while (worklist.isNotEmpty()) {
      val partition = pollFromWorklist(worklist)
      val deletedInThisIteration = partition.asSequence().toImmutableList()
      val testResult = testProperty(
        Configuration(
          currentBest = null,
          candidate_ = null,
          deleted_ = deletedInThisIteration,
        ),
      )
      if (testResult !is PropertyTestResultWithPayload || testResult.result.isNotInteresting) {
        addToWorklist(worklist, partition.splitEvently())
        continue
      } else {
        updateBest(Util.computeDifference(best, deletedInThisIteration), testResult.payload)
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
}
