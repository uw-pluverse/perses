/*
 * Copyright (C) 2018-2022 University of Waterloo.
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
package org.perses.delta

import com.google.common.collect.ImmutableList
import org.perses.util.Util.lazyAssert

class PristineDeltaDebugger<T, PropertyPayload>(
  input: ImmutableList<T>,
  propertyTester: IPropertyTester<T, PropertyPayload>,
  onBestUpdateHandler: (ImmutableList<T>, PropertyPayload) -> Unit,
  enableCache: Boolean = false,
  enableCacheRefresh: Boolean = false,
) : AbstractDeltaDebugger<T, PropertyPayload>(input, propertyTester, onBestUpdateHandler) {

  private val cache: AbstractConfigCache<T> = if (enableCache) {
    ConfigCache(enableCacheRefresh)
  } else {
    NullConfigCache()
  }

  override fun reduceNonEmptyInput() {
    var numOfPartitions = 2
    outerLoop@ while (best.size > 1 && best.size >= numOfPartitions) {
      lazyAssert({ best.size >= numOfPartitions }) { "$best, $numOfPartitions" }
      lazyAssert { numOfPartitions > 1 }
      val partitionList = partition(best, numOfPartitions)

      lazyAssert {
        partitionList.partitions.size != 1 || partitionList.partitions.single().elements == best
      }

      for (partition in partitionList.partitions) {
        val elements = partition.elements
        lazyAssert { elements.isNotEmpty() }
        val config = ConfigurationBasedOnElementSystemIdentity(elements)
        if (cache.contains(config)) {
          continue
        }
        cache.add(config)
        val propertyTestResult = propertyTester.testProperty(best, candidate = elements)

        // TODO: this needs test.
        if (propertyTestResult.needsSkip()) {
          continue
        }
        if (propertyTestResult.result.isInteresting) {
          cache.deleteStaleConfigs(elements.size)
          updateBest(elements, propertyTestResult.payload)
          numOfPartitions = 2.coerceAtMost(best.size)
          continue@outerLoop
        }
      }

      for (partition in partitionList.partitions) {
        val complement = partitionList.computeComplementFor(partition)
        val config = ConfigurationBasedOnElementSystemIdentity(complement)
        if (cache.contains(config)) {
          continue
        }
        cache.add(config)
        val propertyTestResult = propertyTester.testProperty(best, candidate = complement)

        if (propertyTestResult.needsSkip()) {
          continue
        }
        if (propertyTestResult.result.isInteresting) {
          cache.deleteStaleConfigs(complement.size)
          updateBest(complement, propertyTestResult.payload)
          numOfPartitions = (numOfPartitions - 1).coerceAtMost(best.size)
          continue@outerLoop
        }
      }
      if (best.size == numOfPartitions) {
        break
      } else {
        numOfPartitions = (2 * numOfPartitions).coerceAtMost(best.size)
      }
    }
  }
}
