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
import org.perses.util.Util.lazyAssert

abstract class AbstractDefaultDeltaDebugger<T : Any, PropertyPayload, ElementPayload>(
  arguments: Arguments<T, PropertyPayload>,
  enableCache: Boolean = false,
  enableCacheRefresh: Boolean = false,
) : AbstractListInputMinimizer<T, PropertyPayload>(arguments) {
  protected val cache: AbstractConfigCache<T> = if (enableCache) {
    ConfigCache(enableCacheRefresh)
  } else {
    NullConfigCache()
  }

  override fun reduceNonEmptyInput() {
    var numOfPartitions = 2
    var prevPartitionList: PartitionList<ElementWrapper<T>>? = null
    while (best.size > 1 && best.size >= numOfPartitions) {
      lazyAssert({ best.size >= numOfPartitions }) { "$best, $numOfPartitions" }
      check(numOfPartitions > 1) {
        "The number of partitions should be >1. #best=${best.size}"
      }
      log { "Number of partitions: n=$numOfPartitions" }
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
          numOfPartitions = 2
          continue
        }
      }
      if (arguments.partitionComplementControl.enableReducingComplements) {
        val countOfDeletedPartitions = reduceComplements(partitionList)
        if (countOfDeletedPartitions > 0) {
          numOfPartitions = (2 * (numOfPartitions - countOfDeletedPartitions))
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

  protected fun reducePartitions(partitionList: PartitionList<ElementWrapper<T>>): Boolean {
    log {
      "Reducing partitions: ${
        partitionList.partitions.map {
          it.map { it.index }.toString()
        }
      }"
    }
    for (partition in partitionList.partitions) {
      val elements = partition.asImmutableList()
      lazyAssert { elements.isNotEmpty() }
      val config = ConfigurationBasedOnElementSystemIdentity(elements)
      if (cache.contains(config)) {
        continue
      }
      cache.add(config)
      val propertyTestResult = testProperty(
        Configuration(currentBest = best, candidate_ = elements, deleted_ = null),
      )

      // TODO: this needs test.
      if (propertyTestResult !is PropertyTestResultWithPayload<PropertyPayload>) {
        continue
      }
      if (propertyTestResult.result.isInteresting) {
        cache.deleteStaleConfigs(elements.size)
        updateBest(partition.asImmutableList(), propertyTestResult.payload)
        return true
      }
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
  ): PropertyTestResultWithPayload<PropertyPayload>? {
    val config = ConfigurationBasedOnElementSystemIdentity(complement)
    if (cache.contains(config)) { return null }
    cache.add(config)
    val propertyTestResult = testProperty(
      Configuration(currentBest = best, candidate_ = complement, deleted_ = null),
    )
    if (propertyTestResult !is PropertyTestResultWithPayload<PropertyPayload>) { return null }
    return propertyTestResult
  }

  private fun reduceComplements(originalPartitionList: PartitionList<ElementWrapper<T>>): Int {
    log {
      "Reducing complements: ${
        originalPartitionList.partitions.map {
          it.map { it.index }.toString()
        }
      }"
    }
    var currentPartitionList = originalPartitionList
    var countOfDeletedPartitions = 0
    complementLoop@ for (partition in currentPartitionList.partitions) {
      val complement = computeComplement(partition)
      val propertyTestResult = testComplement(complement) ?: continue
      if (propertyTestResult.result.isInteresting) {
        ++countOfDeletedPartitions
        cache.deleteStaleConfigs(complement.size)
        updateBest(complement, propertyTestResult.payload)
        currentPartitionList = currentPartitionList.duplicateByRemovePartition(partition)
        continue@complementLoop
      }
    }
    return countOfDeletedPartitions
  }

  abstract fun partition(
    list: ImmutableList<ElementWrapper<T>>,
    numberOfPartitions: Int,
  ): PartitionList<ElementWrapper<T>>
}
