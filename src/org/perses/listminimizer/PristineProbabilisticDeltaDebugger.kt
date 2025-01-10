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

import kotlin.random.Random

open class PristineProbabilisticDeltaDebugger<T : Any, PropertyPayload>(
  arguments: Arguments<T, PropertyPayload>,
  random: Random? = null,
  private val terminationThreshold: Double = 0.8,
  protected val initialProbability: Double = 0.25,
) : AbstractProbabilisticDeltaDebugger<
  T,
  PropertyPayload,
  PristineProbabilisticDeltaDebugger.ProbabilityPayload,
  >(
  arguments,
  random,
) {

  override fun shouldExcludeElementFromReduction(element: ElementWrapper<T>): Boolean {
    return getProbability(element) >= terminationThreshold
  }

  override val elementComparator =
    compareBy<ElementWrapper<T>>({ getProbability(it) }, { it.index })

  // uses the sorted copyBest and generates new deleteForNextTest
  override fun findNextTest(
    copyBest: List<ElementWrapper<T>>,
  ): MutableList<ElementWrapper<T>> {
    var lastGain = 0.0
    val toBeDeleted = mutableListOf<ElementWrapper<T>>()
    var product = 1.0
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

  protected fun getProbability(element: ElementWrapper<T>): Double {
    return (element.elementPayload as ProbabilityPayload).probability
  }

  override fun updatePayload(toBeDeleted: List<ElementWrapper<T>>) {
    var product = 1.0
    for (element in toBeDeleted) {
      product *= (1.0 - getProbability(element))
    }
    for (element in toBeDeleted) {
      val payload = element.elementPayload as ProbabilityPayload
      val newProbability = getProbability(element) / (1 - product)
      element.elementPayload = payload.duplicateWithNewProbability(newProbability)
    }
  }

  override fun createInitialPayload(): ProbabilityPayload {
    return ProbabilityPayload(initialProbability)
  }

  open class ProbabilityPayload(
    val probability: Double,
  ) {
    open fun duplicateWithNewProbability(newProbability: Double) = ProbabilityPayload(
      probability = newProbability,
    )
  }
}
