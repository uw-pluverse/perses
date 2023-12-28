/*
 * Copyright (C) 2018-2024 University of Waterloo.
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

open class PristineDeltaDebugger<T, PropertyPayload>(
  arguments: AbstractDeltaDebugger.Arguments<T, PropertyPayload>,
  enableCache: Boolean = false,
  enableCacheRefresh: Boolean = false,
) : AbstractDefaultDeltaDebugger<T, PropertyPayload, Any>(
  arguments,
  enableCache,
  enableCacheRefresh,
) {

  override fun partition(
    list: ImmutableList<ElementWrapper<T>>,
    numberOfPartitions: Int,
  ): PartitionList<ElementWrapper<T>> {
    return countBasedPartition(list, numberOfPartitions)
  }

  companion object {

    @JvmStatic
    fun <T> countBasedPartition(
      list: ImmutableList<T>,
      numOfPartitions: Int,
    ): PartitionList<T> {
      val length = list.size
      require(length >= numOfPartitions)
      val partitionSize: Int = computePartitionSize(length, numOfPartitions)
      var remainder = length % numOfPartitions
      val builder = PartitionList.Builder(list)
      var start = 0
      while (start < length) {
        var end = start + partitionSize
        if (remainder > 0) {
          ++end
          --remainder
        }
        if (end > length) {
          end = length
        }
        builder.createPartition(start, end)
        start = end
      }
      return builder.build()
    }

    @JvmStatic
    fun computePartitionSize(listSize: Int, numberOfPartitions: Int): Int {
      require(listSize > 0)
      require(numberOfPartitions > 0)
      return listSize / numberOfPartitions
    }
  }
}
