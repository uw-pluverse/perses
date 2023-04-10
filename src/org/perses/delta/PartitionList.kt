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
import org.perses.util.Interval
import org.perses.util.Util.lazyAssert

class PartitionList<T>(
  val input: ImmutableList<T>,
) {

  lateinit var partitions: ImmutableList<Partition<T>>
    private set

  private fun createPartitionForInterval(interval: Interval) = Partition<T>(input, interval)

  fun computeComplementFor(partitionToExclude: Partition<T>): ImmutableList<T> {
    val result = ImmutableList.builder<T>()
    var found = false
    for (partition in partitions) {
      if (partition === partitionToExclude) {
        found = true
        continue
      }
      result.addAll(partition.elements)
    }
    check(found) { "The partition is not found in the partition list." }
    return result.build()
  }

  data class Partition<T> internal constructor(
    val input: ImmutableList<T>,
    val interval: Interval,
  ) {

    val elements = input.subList(interval.leftInclusive, interval.rightExclusive)
  }

  class Builder<T>(input: ImmutableList<T>) {
    private var list: PartitionList<T>? = PartitionList(input)
    private var intervalBuilder = ImmutableList.builder<Partition<T>>()

    fun createPartition(leftInclusive: Int, rightExclusive: Int): Builder<T> {
      intervalBuilder.add(
        list!!.createPartitionForInterval(
          Interval(
            leftInclusive,
            rightExclusive,
          ),
        ),
      )
      return this
    }

    fun build(): PartitionList<T> {
      val result = list!!
      val partitions = intervalBuilder.build()
      result.partitions = partitions
      list = null

      require(
        partitions.zipWithNext().all { (prev, curr) ->
          prev.interval.rightExclusive <= curr.interval.leftInclusive
        },
      ) {
        "invalid partition intervals. $partitions"
      }
      require(
        partitions.isEmpty() || partitions.last().interval.rightExclusive <= result.input.size,
      )
      require(partitions.isEmpty() || partitions.first().interval.leftInclusive >= 0)
      lazyAssert {
        partitions.asSequence().flatMap { it.elements }.distinct().count() ==
          partitions.asSequence().flatMap { it.elements }.count()
      }

      return result
    }
  }
}
