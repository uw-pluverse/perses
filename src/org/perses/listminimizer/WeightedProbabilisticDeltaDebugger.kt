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

class WeightedProbabilisticDeltaDebugger<T : Any, PropertyPayload>(
  arguments: Arguments<T, PropertyPayload>,
  terminationThreshold: Double = 0.8,
  initialProbability: Double = 0.25,
) : PristineProbabilisticDeltaDebugger<
  T,
  PropertyPayload,
  >(
  arguments,
  random = null, // no random shuffling.
  terminationThreshold,
  initialProbability,
) {
  override fun createElementWrapperFor(index: Int, element: T): ElementWrapper<T> {
    val weight = arguments.weightProvider.weight(element)
    val payload = WProbDDElementPayload(initialProbability, weight)
    return ElementWrapper(index, element, payload)
  }

  override val elementComparator = compareBy<ElementWrapper<T>>(
    { getProbability(it) >= terminationThreshold },
    { (getProbability(it) - 1) * getWeight(it) },
    { getProbability(it) },
    { it.index },
  )

  override fun updatePayload(toBeDeleted: List<ElementWrapper<T>>) {
    var product = 1.0
    for (element in toBeDeleted) {
      product *= (1.0 - getProbability(element))
    }
    for (element in toBeDeleted) {
      val payload = element.elementPayload as WProbDDElementPayload
      val newProbability = getProbability(element) / (1 - product)
      element.elementPayload = payload.duplicateWithNewProbability(newProbability)
    }
  }

  override fun findNextTest(
    copyBest: List<ElementWrapper<T>>,
  ): MutableList<ElementWrapper<T>> {
    val toBeDeleted = mutableListOf<ElementWrapper<T>>()
    val finalToBeDeleted = mutableListOf<ElementWrapper<T>>()
    var product = 1.0
    var currentWeight = 0
    var maxGain = 0.0
    for (element in copyBest) {
      toBeDeleted.add(element)
      product *= (1.0 - getProbability(element))
      currentWeight += getWeight(element)
      val currentGain: Double = currentWeight * product
      if (currentGain > maxGain) {
        maxGain = currentGain
        finalToBeDeleted.clear()
        finalToBeDeleted.addAll(toBeDeleted)
      }
    }
    finalToBeDeleted.sort()
    return finalToBeDeleted
  }

  private fun getWeight(element: ElementWrapper<T>): Int {
    return (element.elementPayload as WProbDDElementPayload).weight
  }

  open class WProbDDElementPayload(
    probability: Double,
    val weight: Int,
  ) : ProbabilityPayload(probability) {
    override fun duplicateWithNewProbability(newProbability: Double) = WProbDDElementPayload(
      probability = newProbability,
      weight = weight,
    )
  }
}
