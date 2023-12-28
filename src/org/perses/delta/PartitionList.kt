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
import org.perses.util.Util.lazyAssert
import org.perses.util.toImmutableList

class PartitionList<T>(
  val partitions: ImmutableList<Partition<T>>,
) {

  val input: ImmutableList<T> by lazy {
    partitions.asSequence().flatMap { it.elements.asSequence() }.toImmutableList()
  }

  fun computeComplementFor(partitionToExclude: Partition<T>): PartitionList<T> {
    val result = ImmutableList.builder<Partition<T>>()
    var found = false
    for (partition in partitions) {
      if (partition === partitionToExclude) {
        found = true
        continue
      }
      result.add(partition)
    }
    check(found) { "The partition is not found in the partition list." }
    return PartitionList(result.build())
  }

  fun isEquivalentTo(other: PartitionList<T>?): Boolean {
    if (other == null) {
      return false
    }
    // Do not consider the `input` property. We care about the partitions.
    return partitions == other.partitions
  }

  data class Partition<T> internal constructor(
    val elements: ImmutableList<T>,
  )

  class Builder<T>(private val input: ImmutableList<T>) {
    private var used = false
    private var intervalBuilder = ImmutableList.builder<Partition<T>>()

    fun createPartition(leftInclusive: Int, rightExclusive: Int): Builder<T> {
      intervalBuilder.add(Partition(input.subList(leftInclusive, rightExclusive)))
      return this
    }

    fun build(): PartitionList<T> {
      check(!used)
      used = true
      val partitions = intervalBuilder.build()
      val result = PartitionList(partitions)
      lazyAssert { result.input == input }
      return result
    }
  }
}
