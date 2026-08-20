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

import com.google.common.collect.ImmutableList

/**
 * Enumerates whole-window deletions: it slides a window backwards over the non-deleted elements for
 * each window size from [maxWindowSize] down to [minWindowSize], yielding each window once as a
 * single candidate deletion. The [visited] set is shared across window sizes, matching the original
 * [WindowedSlicer] loop.
 */
class WindowedSliceCursor<T : Any>(
  private val minWindowSize: Int,
  private val maxWindowSize: Int,
  private val currentBest: () -> ImmutableList<ElementWrapper<T>>,
  private val onWindowSizeStarted: (Int) -> Unit = {},
) : DeletionCandidateCursor<T> {
  private val visited = mutableSetOf<ImmutableList<ElementWrapper<T>>>()
  private var windowSize = maxWindowSize
  private var slider: BackwardWindowSlider<ElementWrapper<T>>? = null

  override fun next(): Candidate<T>? {
    while (true) {
      val currentSlider =
        slider ?: run {
          if (windowSize < minWindowSize) {
            return null
          }
          onWindowSizeStarted(windowSize)
          BackwardWindowSlider(expectedWindowSize = windowSize, list = currentBest()) {
            it.deleted
          }.also { slider = it }
        }
      val window = currentSlider.slideBackByOnePosition()
      if (window.isEmpty()) {
        slider = null
        --windowSize
        continue
      }
      if (!visited.add(window)) {
        continue
      }
      return Candidate.DeletionsFromOriginal(original = currentBest(), deleted_ = window)
    }
  }

  override fun onCommitted() {
    visited.clear()
  }
}
