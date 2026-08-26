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
package org.perses.listminimizer

import com.google.common.collect.ImmutableList
import org.perses.reduction.CandidateOutcome
import org.perses.util.lazyAssert
import org.perses.util.toImmutableList

class WeightedDeltaDebugger<T : Any, PropertyPayload>(
  args: ListMinimizerArguments<T, PropertyPayload>,
  enableCache: Boolean = false,
  enableCacheRefresh: Boolean = false,
) : PristineDeltaDebugger<T, PropertyPayload>(
    args,
    enableCache,
    enableCacheRefresh,
  ) {
  override fun createElementWrapperFor(
    index: Int,
    element: T,
  ): ElementWrapper<T> {
    val weight = arguments.weightProvider.weight(element)
    return ElementWrapper(index, element, weight)
  }

  private fun weightedPartition(
    list: PartitionList<ElementWrapper<T>>,
  ): PartitionList<ElementWrapper<T>> {
    val partitions = mutableListOf<Partition<ElementWrapper<T>>>()
    for (partition in list.partitions) {
      partitions += partition.weightedSplit { element -> getWeight(element) }
    }
    return PartitionList(partitions.toImmutableList())
  }

  override fun reduceNonEmptyInput() {
    var partitionList = PartitionList(ImmutableList.of(Partition(best)))
    while (best.size > 1 && best.size > partitionList.partitions.size) {
      partitionList = weightedPartition(partitionList)
      if (partitionList.partitions.size < 2) {
        lazyAssert { partitionList.partitions.size == 0 }
        break
      }
      logPartitionList(partitionList)

      if (arguments.partitionComplementControl.enableReducingPartitions) {
        if (reducePartitions(partitionList)) {
          partitionList = PartitionList(ImmutableList.of(Partition(best)))
          continue
        }
      }

      if (arguments.partitionComplementControl.enableReducingComplements) {
        val partitionsLeft = reduceComplementsForWdd(partitionList)
        if (partitionsLeft.partitions.size < partitionList.partitions.size) {
          partitionList = partitionsLeft
          continue
        }
      }

      if (best.size <= partitionList.partitions.size) {
        break
      }
    }
    ensureOneMinimal()
  }

  private fun reduceComplementsForWdd(
    originalPartitionList: PartitionList<ElementWrapper<T>>,
  ): PartitionList<ElementWrapper<T>> {
    arguments.log {
      val idList =
        originalPartitionList.partitions
          .map {
            AbstractListMinimizerListener.convertElementListToCompactString(it)
          }.toString()
      "Reducing complements: $idList"
    }
    var currentPartitionList = originalPartitionList
    var countOfDeletedPartitions = 0
    var restart = true
    while (restart) {
      restart = false
      for (partition in currentPartitionList.partitions) {
        val complement = computeComplement(partition)
        val outcome = testComplement(complement)
        if (outcome !is CandidateOutcome.Interesting<PropertyPayload>) {
          continue
        }
        ++countOfDeletedPartitions
        updateBest(complement, outcome.payload)
        val partitions = currentPartitionList.partitions.toMutableList()
        partitions.remove(partition)
        currentPartitionList = PartitionList(partitions.toImmutableList())
        restart = true
        break
      }
    }
    return currentPartitionList
  }

  private fun ensureOneMinimal() {
    var restart = true
    while (restart) {
      restart = false
      for (element in best) {
        val complement = best.filter { it != element }.toImmutableList()
        val outcome = testComplement(complement)
        // A NotTested complement is skipped like a rejected one, which means the one-minimality
        // this function is named for is not actually established for that element: nothing ran to
        // establish it. Pre-existing, and left alone here because closing it changes behaviour --
        // but it is only expressible at all because the result type reaches this call site.
        if (outcome !is CandidateOutcome.Interesting<PropertyPayload>) {
          continue
        }
        updateBest(complement, outcome.payload)
        restart = true
        break
      }
    }
  }

  companion object {
    fun <T : Any> computeSum(list: ImmutableList<ElementWrapper<T>>): Int =
      list.sumOf { getWeight(it) }

    fun <T : Any> getWeight(
      list: ImmutableList<ElementWrapper<T>>,
      index: Int,
    ): Int = getWeight(list[index])

    fun <T : Any> getWeight(element: ElementWrapper<T>) = element.elementPayload as Int
  }
}
