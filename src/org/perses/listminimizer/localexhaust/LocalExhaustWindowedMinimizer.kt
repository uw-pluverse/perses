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
package org.perses.listminimizer.localexhaust

import com.google.common.collect.ImmutableList
import org.perses.listminimizer.AbstractListMinimizer
import org.perses.listminimizer.BackwardWindowSlider
import org.perses.listminimizer.Candidate.DeletionsFromOriginal
import org.perses.listminimizer.ElementWrapper
import org.perses.listminimizer.LMPropertyTestResult
import org.perses.listminimizer.ListMinimizerArguments
import org.perses.util.Util

// TODO(cnsun): needs tests.
class LocalExhaustWindowedMinimizer<T : Any, PropertyPayload>(
  arguments: ListMinimizerArguments<T, PropertyPayload>,
) : AbstractListMinimizer<T, PropertyPayload>(arguments) {
  val extraArguments =
    arguments.localExhaustMinimizerArguments
      ?: error("Arguments must be non-null in ${this::class}")

  val windowSize: Int
    get() = extraArguments.windowSize

  override fun reduceNonEmptyInput() {
    val slider =
      BackwardWindowSlider(expectedWindowSize = windowSize, list = best) {
        it.deleted
      }
    val visited = mutableSetOf<ImmutableList<ElementWrapper<T>>>()
    while (true) {
      val window = slider.slideBackByOnePosition()
      if (window.isEmpty()) {
        break
      }
      if (!visited.add(window)) {
        // The window has been processed before, thus skipping this window.
        continue
      }
      val actualWindowSize = window.size
      val patternSet =
        CachedUniformLengthDeletionPatternSets
          .getDeletionPatternSet(actualWindowSize)
          .interestingPatternsInDescendingOfNumOfDeletes
      for (patternSet in patternSet) {
        val deletedElements = patternSet.getDeletedElements(input = window)
        Util.lazyAssert({ best.containsAll(deletedElements) }) {
          """$best
            |$deletedElements
          """.trimMargin()
        }
        val configuration =
          DeletionsFromOriginal(
            original = best,
            deleted_ = deletedElements,
          )
        val testResult = testProperty(configuration)
        if (testResult !is LMPropertyTestResult.Completed) {
          continue
        }
        if (testResult.result.isInteresting) {
          visited.clear()
          configuration.deletedWrappers.forEach { it.markAsDeleted() }
          updateBest(configuration.candidateWrappers, testResult.payload)
          break
        }
      }
    }
  }
}
