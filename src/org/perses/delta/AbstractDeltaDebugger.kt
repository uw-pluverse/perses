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
import org.perses.reduction.PropertyTestResult
import java.util.IdentityHashMap

interface IPropertyTest<T, Payload> {
  fun testProperty(
    currentBest: ImmutableList<T>,
    candidate: ImmutableList<T>
  ): AbstractPropertyTestResultWithPayload<Payload>
}

abstract class AbstractPropertyTestResultWithPayload<Payload> {

  abstract fun needsSkip(): Boolean

  abstract val result: PropertyTestResult

  abstract val payload: Payload
}

class SkipPropertyTestResult<Payload> : AbstractPropertyTestResultWithPayload<Payload>() {
  override fun needsSkip() = true

  override val result: PropertyTestResult
    get() = TODO("Not yet implemented")

  override val payload: Payload
    get() = TODO("Not yet implemented")
}

data class PropertyTestResultWithPayload<Payload>(
  override val result: PropertyTestResult,
  override val payload: Payload
) : AbstractPropertyTestResultWithPayload<Payload>() {

  override fun needsSkip() = false
}

abstract class AbstractDeltaDebugger<T, PropertyPayload>(
  input: ImmutableList<T>,
  val propertyTest: IPropertyTest<T, PropertyPayload>,
  val onBestUpdateHandler: (ImmutableList<T>, PropertyPayload) -> Unit
) {

  var best: ImmutableList<T> = input
    private set

  protected fun updateBest(
    newBest: ImmutableList<T>,
    payload: PropertyPayload
  ) {
    best = newBest
    onBestUpdateHandler(newBest, payload)
  }

  abstract fun reduce()

  init {
    val uniqueObjects = input.fold(
      IdentityHashMap<T, T>(),
      { acc, element ->
        acc.put(element, element)
        acc
      }
    )
    require(uniqueObjects.size == input.size) {
      "The elements in input have to be distinct objects. $input"
    }
  }

  companion object {

    @JvmStatic
    fun <T> partition(
      list: ImmutableList<T>,
      numOfPartitions: Int
    ): ImmutableList<Partition<T>> {
      val length = list.size
      require(length >= numOfPartitions)
      val partitionSize: Int = computePartitionSize(length, numOfPartitions)
      var remainder = length % numOfPartitions
      val result = ImmutableList.builder<Partition<T>>()
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
        result.add(Partition(list, start, end))
        start = end
      }
      return result.build()
    }

    @JvmStatic
    fun computePartitionSize(listSize: Int, numberOfPartitions: Int): Int {
      require(listSize > 0)
      require(numberOfPartitions > 0)
      return listSize / numberOfPartitions
    }
  }
}
