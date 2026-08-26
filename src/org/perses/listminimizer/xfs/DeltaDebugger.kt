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

import org.perses.listminimizer.AbstractListMinimizer
import org.perses.listminimizer.Candidate.DeletionsFromOriginal
import org.perses.listminimizer.ElementWrapper
import org.perses.listminimizer.ListMinimizerArguments
import org.perses.listminimizer.Partition
import org.perses.reduction.CandidateOutcome
import org.perses.util.CollectionUtil
import org.perses.util.lazyAssert
import org.perses.util.toImmutableList
import java.util.LinkedList

class DeltaDebugger<T : Any, PropertyPayload>(
  arguments: ListMinimizerArguments<T, PropertyPayload>,
) : AbstractListMinimizer<T, PropertyPayload>(arguments) {
  override fun reduceNonEmptyInput() {
    val initialPartition = Partition(best)
    var worklist =
      LinkedList<Partition<ElementWrapper<T>>>().apply {
        addAll(initialPartition.splitEvently())
      }
    while (worklist.isNotEmpty()) {
      var shouldContinue: Boolean
      do {
        shouldContinue = false
        val iterator = worklist.iterator()
        while (iterator.hasNext()) {
          val partition = iterator.next()
          val deletedInThisIteration = partition.asSequence().toImmutableList()
          val testResult =
            testProperty(
              DeletionsFromOriginal(original = best, deleted_ = deletedInThisIteration),
            ).get()
          if (testResult !is CandidateOutcome.Interesting) {
            continue
          }
          val newBest = CollectionUtil.computeDifference(best, deletedInThisIteration)
          updateBest(newBest, testResult.payload)
          iterator.remove()
          shouldContinue = true
        }
      } while (shouldContinue)
      val copy = worklist
      worklist = LinkedList()
      lazyAssert { worklist !== copy }
      for (partition in copy) {
        val splits = partition.splitEvently()
        for (split in splits) {
          worklist.add(split)
        }
      }
    }
  }
}
