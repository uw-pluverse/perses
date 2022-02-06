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

class PristineDeltaDebugger<T, PropertyPayload>(
  input: ImmutableList<T>,
  propertyTest: IPropertyTest<T, PropertyPayload>,
  onBestUpdateHandler: (ImmutableList<T>, PropertyPayload) -> Unit
) : AbstractDeltaDebugger<T, PropertyPayload>(input, propertyTest, onBestUpdateHandler) {

  override fun reduce() {
    // test whether the entire input can be deleted.
    run {
      val empty = ImmutableList.of<T>()
      propertyTest.testProperty(best, empty).let {
        if (!it.needsSkip() && it.result.isInteresting) {
          updateBest(empty, it.payload)
          return
        }
      }
    }

    var numOfPartitions = 2
    outerloop@ while (best.size > 1 && best.size >= numOfPartitions) {
      assert(best.size >= numOfPartitions) { "$best, $numOfPartitions" }
      assert(numOfPartitions > 1)
      val partitions = partition(best, numOfPartitions)

      assert(partitions.size != 1 || partitions.first().toList() == best)

      for (partition in partitions) {
        val asList = partition.toList()
        assert(asList.isNotEmpty())
        val propertyTestResult = propertyTest.testProperty(best, candidate = asList)
        // TODO: this needs test.
        if (propertyTestResult.needsSkip()) {
          continue
        }
        if (propertyTestResult.result.isInteresting) {
          updateBest(asList, propertyTestResult.payload)
          numOfPartitions = Math.min(2, best.size)
          continue@outerloop
        }
      }

      for (partition in partitions) {
        val complement = partition.computeComplement()
        val propertyTestResult = propertyTest.testProperty(best, candidate = complement)
        if (propertyTestResult.needsSkip()) {
          continue
        }
        if (propertyTestResult.result.isInteresting) {
          updateBest(complement, propertyTestResult.payload)
          numOfPartitions = Math.min(numOfPartitions - 1, best.size)
          continue@outerloop
        }
      }
      if (best.size == numOfPartitions) {
        break
      } else {
        numOfPartitions = Math.min(2 * numOfPartitions, best.size)
      }
    }
  }
}
