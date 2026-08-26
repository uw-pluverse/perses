/*
 * Copyright (C) 2018-2026 University of Waterloo.
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

import org.perses.reduction.CandidateOutcome
import org.perses.util.CollectionUtil
import org.perses.util.lazyAssert
import org.perses.util.toImmutableList
import kotlin.random.Random

abstract class AbstractProbabilisticDeltaDebugger<T : Any, PropertyPayload, PayloadType : Any>(
  arguments: ListMinimizerArguments<T, PropertyPayload>,
  protected val random: Random? = null,
) : AbstractListMinimizer<T, PropertyPayload>(arguments) {
  private var hasTriedDeleteAll: Boolean = false

  private fun shouldTerminate(): Boolean = best.all { shouldExcludeElementFromReduction(it) }

  protected abstract val elementComparator: Comparator<ElementWrapper<T>>

  protected abstract fun shouldExcludeElementFromReduction(element: ElementWrapper<T>): Boolean

  override fun reduceNonEmptyInput() {
    while (!shouldTerminate()) {
      val copyBest =
        best
          .asSequence()
          .filter { !shouldExcludeElementFromReduction(it) }
          .toMutableList()
      check(copyBest.isNotEmpty()) {
        "The list cannot be empty."
      }
      sortElements(copyBest)
      lazyAssert { copyBest.none { shouldExcludeElementFromReduction(it) } }
      val toBeDeleted = findNextTest(copyBest)

      // avoid deleting all elements multiple times
      if (toBeDeleted.size == best.size) {
        if (hasTriedDeleteAll) {
          updatePayload(toBeDeleted)
          continue
        }
        hasTriedDeleteAll = true
      }

      val config =
        Candidate.DeletionsFromOriginal(
          original = best,
          deleted_ = toBeDeleted.toImmutableList(),
        )

      val outcome = testProperty(config).get()
      if (outcome is CandidateOutcome.Interesting<PropertyPayload>) {
        val newBest = CollectionUtil.computeDifference(best, toBeDeleted)
        updateBest(newBest, outcome.payload)
      } else {
        updatePayload(toBeDeleted)
      }
    }
  }

  private fun sortElements(copyBest: MutableList<ElementWrapper<T>>) {
    if (random != null) {
      copyBest.shuffle(random)
    }
    copyBest.sortWith(elementComparator)
  }

  protected abstract fun findNextTest(
    copyBest: List<ElementWrapper<T>>,
  ): MutableList<ElementWrapper<T>>

  protected abstract fun updatePayload(toBeDeleted: List<ElementWrapper<T>>)

  protected abstract fun createInitialPayload(): PayloadType

  override fun createElementWrapperFor(
    index: Int,
    element: T,
  ): ElementWrapper<T> = ElementWrapper(index, element, createInitialPayload())
}
