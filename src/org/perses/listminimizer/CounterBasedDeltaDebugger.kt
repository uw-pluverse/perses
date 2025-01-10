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

import kotlin.math.max
import kotlin.math.min
import kotlin.random.Random

class CounterBasedDeltaDebugger<T : Any, PropertyPayload>(
  arguments: Arguments<T, PropertyPayload>,
  random: Random? = null,
  private val initialProbability: Double = 0.25,
) : AbstractProbabilisticDeltaDebugger<
  T,
  PropertyPayload,
  CounterBasedDeltaDebugger.CounterPayload,
  >(
  arguments,
  random,
) {

  override fun shouldExcludeElementFromReduction(element: ElementWrapper<T>): Boolean {
    return getCounter(element) == NO_NEED_TO_VISIT
  }

  override val elementComparator =
    compareBy<ElementWrapper<T>>({ getCounter(it) }, { it.index })

  override fun findNextTest(
    copyBest: List<ElementWrapper<T>>,
  ): MutableList<ElementWrapper<T>> {
    copyBest.sortedBy { getCounter(it) }
    val counterMin = copyBest.minOf { getCounter(it) }
    val currentSize = computeSize(counterMin)
    val toBeDeleted = copyBest.take(currentSize).toMutableList()
    toBeDeleted.sort()
    return toBeDeleted
  }

  private fun computeSize(counter: Int): Int {
    // Compute the current probability based on the initial probability and the counter
    var currentProbability = initialProbability
    val factor = 1 - (1 / Math.E)

    for (i in 0 until counter) {
      currentProbability /= factor
    }

    // Loop to find the size that maximizes the formula: size * (1 - currentProbability)^size
    val epsilon = 1e-6
    var maxSize = 1
    var maxGain = 0.0
    var size = 1

    while (size <= best.size) {
      val gain = size * Math.pow(1 - currentProbability, size.toDouble())

      if (gain > maxGain + epsilon) {
        maxGain = gain
        maxSize = size
      } else if (Math.abs(gain - maxGain) <= epsilon) {
        // If the gain is equal, prefer the larger size
        maxSize = size
      } else {
        break
      }

      size += 1
    }

    // Ensure the size is within bounds
    maxSize = min(maxSize, best.size)
    maxSize = max(maxSize, 1)

    return maxSize
  }

  private fun getCounter(element: ElementWrapper<T>): Int {
    return (element.elementPayload as CounterPayload).counter
  }

  override fun updatePayload(toBeDeleted: List<ElementWrapper<T>>) {
    val size = toBeDeleted.count()
    for (element in toBeDeleted) {
      check(!shouldExcludeElementFromReduction(element))
      val payload = element.elementPayload as CounterPayload
      val newCounter = if (size != 1) {
        payload.counter + 1
      } else {
        NO_NEED_TO_VISIT
      }
      element.elementPayload = payload.duplicateWithNewCounter(newCounter)
    }
  }

  override fun createInitialPayload(): CounterPayload {
    return CounterPayload(counter = 0)
  }

  open class CounterPayload(
    val counter: Int,
  ) {
    open fun duplicateWithNewCounter(newCounter: Int) = CounterPayload(
      counter = newCounter,
    )
  }

  companion object {
    const val NO_NEED_TO_VISIT = Int.MIN_VALUE
  }
}
