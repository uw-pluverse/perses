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

import org.perses.util.Util
import org.perses.util.toImmutableList
import kotlin.comparisons.compareBy
import kotlin.random.Random

class PristineProbabilisticDeltaDebugger<T, PropertyPayload>(
  arguments: AbstractDeltaDebugger.Arguments<T, PropertyPayload>,
  private val random: Random? = null,
  private val terminationThreshold: Double = 0.8,
  private val initialProbability: Double = 0.25,
) : AbstractDeltaDebugger<T, PropertyPayload> (
  arguments,
) {
  fun shouldTerminate(): Boolean {
    // checks if all probability models reach the threshold
    return best.all { getProbability(it) >= terminationThreshold }
  }

  // change the elementPayload in every element in deleted

  fun updateProbability(toBeDeleted: Iterable<ElementWrapper<T>>) {
    var product = 1.0

    for (element in toBeDeleted) {
      product *= (1.0 - getProbability(element))
    }

    for (element in toBeDeleted) {
      val newProbability = getProbability(element) / (1 - product)
      element.elementPayload = newProbability
    }
  }

  // sort copyBest according to elementPayload
  fun sortProbability(copyBest: MutableList<ElementWrapper<T>>) {
    if (random != null) {
      copyBest.shuffle(random)
    }
    copyBest.sortWith(compareBy({ getProbability(it) }, { it.index }))
  }

  // uses the sorted copyBest and generates new deleteForNextTest
  fun findNextTest(
    copyBest: Iterable<ElementWrapper<T>>,
  ): MutableList<ElementWrapper<T>> {
    var lastGain: Double = 0.0
    val toBeDeleted = mutableListOf<ElementWrapper<T>>()
    var product: Double = 1.0
    for (element in copyBest) {
      toBeDeleted.add(element)
      product *= (1.0 - getProbability(element))
      val currentGain: Double = toBeDeleted.size * product

      if (lastGain > currentGain) {
        toBeDeleted.removeAt(toBeDeleted.size - 1)
        break
      }
      lastGain = currentGain
    }
    toBeDeleted.sort()
    return toBeDeleted
  }

  override fun createElementWrapperFor(index: Int, element: T): ElementWrapper<T> {
    return ElementWrapper(index, element, initialProbability)
  }

  override fun reduceNonEmptyInput() {
    while (!shouldTerminate()) {
      val copyBest = best.toMutableList()
      sortProbability(copyBest)
      val toBeDeleted = findNextTest(copyBest)
      val config = Configuration<T>(
        currentBest = best,
        candidate_ = null,
        deleted_ = toBeDeleted.toImmutableList(),
      )

      val propertyTestResult = testProperty(config)
      if (propertyTestResult is PropertyTestResultWithPayload<PropertyPayload> &&
        propertyTestResult.result.isInteresting
      ) {
        val newBest = Util.computeDifference(best, toBeDeleted)
        updateBest(newBest, propertyTestResult.payload)
      } else {
        updateProbability(toBeDeleted)
      }
    }
  }

  companion object {
    @JvmStatic
    fun <T> getProbability(element: ElementWrapper<T>) = element.elementPayload as Double
  }
}
