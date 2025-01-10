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

data class Partition<T>(private val elements: ImmutableList<T>) : List<T> by elements {

  init {
    require(elements.size > 0) { "A partition cannot be empty." }
  }

  fun asImmutableList() = elements

  fun splitEvently(): ImmutableList<Partition<T>> {
    val elements = elements
    val size = elements.size
    check(size > 0)
    if (size <= 1) {
      return ImmutableList.of()
    }
    val halfIndex = (size + 1) / 2
    return ImmutableList.of(
      Partition(elements.subList(0, halfIndex)),
      Partition(elements.subList(halfIndex, size)),
    )
  }

  fun weightedSplit(
    weightOfElements: (T) -> Int,
  ): ImmutableList<Partition<T>> {
    val elements = elements
    val size = elements.size
    check(size > 0)
    if (size <= 1) {
      return ImmutableList.of()
    }
    val expectedWeightOfPartition = elements.sumOf { weightOfElements(it) } / 2
    var currentSum = weightOfElements(elements.first())
    var i = 1
    while (i < size) {
      val currentWeight = weightOfElements(elements[i])
      if (currentSum + currentWeight > expectedWeightOfPartition) {
        if (expectedWeightOfPartition - currentSum >=
          currentSum + currentWeight - expectedWeightOfPartition
        ) {
          currentSum += currentWeight
          ++i
        }
        break
      }
      currentSum += currentWeight
      ++i
    }
    return ImmutableList.of(
      Partition(elements.subList(0, i)),
      Partition(elements.subList(i, size)),
    )
  }

  /** A builder to build a Partition.  */
  class Builder<T : Any>(capacity: Int) {
    private var builder: ImmutableList.Builder<T> = ImmutableList.builderWithExpectedSize<T>(
      capacity,
    )
    var size: Int = 0
      private set

    fun addElement(element: T) {
      ++size
      builder.add(element)
    }

    /** This method builds a partition, and the current builder becomes invalid.  */
    fun build(): Partition<T> {
      return Partition(builder.build())
    }
  }
}
