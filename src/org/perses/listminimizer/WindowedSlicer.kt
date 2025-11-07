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

open class WindowedSlicer<T : Any, PropertyPayload>(
  arguments: ListMinimizerArguments<T, PropertyPayload>,
) : AbstractWindowedSlicer<T, PropertyPayload>(arguments) {
  override fun reduceNonEmptyInput() {
    val minWindowSize = extraArguments.minSlidingWindowSize
    val maxWindowSize = extraArguments.maxSlidingWindowSize

    val visited = mutableSetOf<ImmutableList<ElementWrapper<T>>>()
    for (windowSize in maxWindowSize downTo minWindowSize) {
      arguments.log { "Window size: $windowSize" }

      val slider =
        BackwardWindowSlider(expectedWindowSize = windowSize, list = best) {
          it.deleted
        }
      while (true) {
        val window = slider.slideBackByOnePosition()
        if (window.isEmpty()) {
          break
        }
        if (!visited.add(window)) {
          // The window has been processed before, then skip to the next window.
          continue
        }
        val configuration =
          Candidate.DeletionsFromOriginal(
            original = best,
            deleted_ = window,
          )
        val testResult = testProperty(configuration)
        if (testResult !is LMPropertyTestResult.Completed) {
          continue
        }
        if (testResult.result.isInteresting) {
          // A new best is found, and reset the visited cache.
          visited.clear()
          configuration.deletedWrappers.forEach { it.markAsDeleted() }
          updateBest(configuration.candidateWrappers, testResult.payload)
        }
      }
    }
  }
}
