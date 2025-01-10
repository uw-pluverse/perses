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
package org.perses.listminimizer

import com.google.common.collect.ImmutableList
import org.perses.util.Util
import org.perses.util.toImmutableList

class WeightedDeltaDebugger<T : Any, PropertyPayload>(
  args: Arguments<T, PropertyPayload>,
  enableCache: Boolean = false,
  enableCacheRefresh: Boolean = false,
) : PristineDeltaDebugger<T, PropertyPayload>(
  args,
  enableCache,
  enableCacheRefresh,
) {
  override fun createElementWrapperFor(index: Int, element: T): ElementWrapper<T> {
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
        Util.lazyAssert { partitionList.partitions.size == 0 }
        break
      }
      log {
        buildString {
          val partitions = partitionList.partitions
          val size = partitions.size
          appendLine("Partition size: $size")
          for (i in 0 until size) {
            val partition = partitions[i].map { it.index }
            appendLine("----Partition $i: $partition")
          }
        }
      }

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
    log {
      "Reducing complements: ${
        originalPartitionList.partitions.map {
          it.map { it.index }.toString()
        }
      }"
    }
    var currentPartitionList = originalPartitionList
    var countOfDeletedPartitions = 0
    var restart = true
    while (restart) {
      restart = false
      complementLoop@ for (partition in currentPartitionList.partitions) {
        val complement = computeComplement(partition)
        val propertyTestResult = testComplement(complement) ?: continue
        if (propertyTestResult.result.isInteresting) {
          ++countOfDeletedPartitions
          cache.deleteStaleConfigs(complement.size)
          updateBest(complement, propertyTestResult.payload)
          val partitions = currentPartitionList.partitions.toMutableList()
          partitions.remove(partition)
          currentPartitionList = PartitionList(partitions.toImmutableList())
          restart = true
          break
        }
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
        val propertyTestResult = testComplement(complement) ?: continue
        if (propertyTestResult.result.isInteresting) {
          cache.deleteStaleConfigs(complement.size)
          updateBest(complement, propertyTestResult.payload)
          restart = true
          break
        }
      }
    }
  }

  companion object {
    fun <T> computeSum(list: ImmutableList<ElementWrapper<T>>): Int {
      return list.sumOf { getWeight(it) }
    }

    fun <T> getWeight(list: ImmutableList<ElementWrapper<T>>, index: Int): Int {
      return getWeight(list[index])
    }

    fun <T> getWeight(element: ElementWrapper<T>) = element.elementPayload as Int
  }
}
