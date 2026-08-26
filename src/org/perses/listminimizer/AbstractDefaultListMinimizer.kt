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

import org.perses.util.lazyAssert
import com.google.common.collect.ImmutableList
import org.perses.reduction.CandidateOutcome
import org.perses.util.lazyAssert

abstract class AbstractDefaultListMinimizer<T : Any, PropertyPayload, ElementPayload>(
  arguments: ListMinimizerArguments<T, PropertyPayload>,
  enableCache: Boolean = false,
  enableCacheRefresh: Boolean = false,
) : AbstractListMinimizer<T, PropertyPayload>(arguments, enableCache, enableCacheRefresh) {
  override fun reduceNonEmptyInput() {
    var numOfPartitions =
      arguments.partitionComplementControl
        .countOfInitialPartitions(
          best,
        ).coerceAtLeast(2)
    var prevPartitionList: PartitionList<ElementWrapper<T>>? = null
    while (best.size > 1 && best.size >= numOfPartitions) {
      lazyAssert({ best.size >= numOfPartitions }) { "$best, $numOfPartitions" }
      check(numOfPartitions > 1) {
        "The number of partitions should be >1. #best=${best.size}"
      }
      arguments.log { "Number of partitions: n=$numOfPartitions" }
      val partitionList = partition(best, numOfPartitions)

      lazyAssert {
        partitionList.partitions.size != 1 ||
          partitionList.partitions.single().asImmutableList() == best
      }
      if (partitionList.isEquivalentTo(prevPartitionList)) {
        break
      } else {
        prevPartitionList = partitionList
      }
      logPartitionList(partitionList)
      if (arguments.partitionComplementControl.enableReducingPartitions) {
        if (reducePartitions(partitionList)) {
          numOfPartitions = 2
          continue
        }
      }
      if (arguments.partitionComplementControl.enableReducingComplements) {
        val countOfDeletedPartitions = reduceComplements(partitionList)
        if (countOfDeletedPartitions > 0) {
          numOfPartitions =
            (2 * (numOfPartitions - countOfDeletedPartitions))
              .coerceAtMost(best.size)
          continue
        }
      }
      if (best.size == numOfPartitions) {
        break
      } else {
        numOfPartitions = (2 * numOfPartitions).coerceAtMost(best.size)
      }
    }
  }

  protected fun logPartitionList(partitionList: PartitionList<ElementWrapper<T>>) {
    arguments.log { toCompactString(partitionList) }
  }

  private fun toCompactString(partitionList: PartitionList<ElementWrapper<T>>): String =
    buildString {
      val partitions = partitionList.partitions
      append("Partition count: ${partitions.size}. ")
      append(
        partitions.map { AbstractListMinimizerListener.convertElementListToCompactString(it) },
      )
    }

  protected fun reducePartitions(partitionList: PartitionList<ElementWrapper<T>>): Boolean {
    arguments.log { "Reducing partitions:  ${toCompactString(partitionList)}" }
    for (partition in partitionList.partitions) {
      val elements = partition.asImmutableList()
      lazyAssert { elements.isNotEmpty() }
      val outcome =
        testProperty(
          Candidate.SublistFromOriginal(original = best, candidate_ = elements),
        ).get()

      if (outcome !is CandidateOutcome.Interesting<PropertyPayload>) {
        continue
      }
      updateBest(elements, outcome.payload)
      return true
    }
    return false
  }

  protected fun computeComplement(
    partitionToExclude: Partition<ElementWrapper<T>>,
  ): ImmutableList<ElementWrapper<T>> {
    val result = ImmutableList.builder<ElementWrapper<T>>()
    for (element in best) {
      if (element in partitionToExclude) {
        continue
      }
      result.add(element)
    }
    return result.build()
  }

  protected fun testComplement(
    complement: ImmutableList<ElementWrapper<T>>,
  ): CandidateOutcome<PropertyPayload> =
    testProperty(
      Candidate.SublistFromOriginal(original = best, candidate_ = complement),
    ).get()

  private fun reduceComplements(originalPartitionList: PartitionList<ElementWrapper<T>>): Int {
    arguments.log {
      "Reducing complements: ${toCompactString(originalPartitionList)}"
    }
    var currentPartitionList = originalPartitionList
    var countOfDeletedPartitions = 0
    for (partition in currentPartitionList.partitions) {
      val complement = computeComplement(partition)
      val outcome = testComplement(complement)
      if (outcome !is CandidateOutcome.Interesting<PropertyPayload>) {
        continue
      }
      ++countOfDeletedPartitions
      updateBest(complement, outcome.payload)
      currentPartitionList = currentPartitionList.duplicateByRemovePartition(partition)
    }
    return countOfDeletedPartitions
  }

  abstract fun partition(
    list: ImmutableList<ElementWrapper<T>>,
    numberOfPartitions: Int,
  ): PartitionList<ElementWrapper<T>>
}
