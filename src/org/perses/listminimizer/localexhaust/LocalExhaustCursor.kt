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
package org.perses.listminimizer.localexhaust

import com.google.common.collect.ImmutableList
import org.perses.listminimizer.BackwardWindowSlider
import org.perses.listminimizer.Candidate
import org.perses.listminimizer.Candidate.DeletionsFromOriginal
import org.perses.listminimizer.DeletionCandidateCursor
import org.perses.listminimizer.ElementWrapper

/**
 * Slides a window backwards over the non-deleted elements of the input and, for each window, yields
 * every deletion pattern in descending order of the number of deleted elements.
 *
 * The slider is created once over [initialBest] and reads each element's live deletion flag, so a
 * single cursor tracks the shrinking result across commits. Candidates are built against
 * [currentBest] because that is what a deletion is relative to at the moment it is applied.
 */
class LocalExhaustCursor<T : Any>(
  windowSize: Int,
  initialBest: ImmutableList<ElementWrapper<T>>,
  private val currentBest: () -> ImmutableList<ElementWrapper<T>>,
) : DeletionCandidateCursor<T> {
  private val slider =
    BackwardWindowSlider(expectedWindowSize = windowSize, list = initialBest) { it.deleted }
  private val visited = mutableSetOf<ImmutableList<ElementWrapper<T>>>()
  private var window: ImmutableList<ElementWrapper<T>> = ImmutableList.of()
  private var patterns: Iterator<ElementEditPattern> = emptyList<ElementEditPattern>().iterator()

  override fun next(): Candidate<T>? {
    while (true) {
      if (patterns.hasNext()) {
        val deletedElements = patterns.next().getDeletedElements(input = window)
        return DeletionsFromOriginal(original = currentBest(), deleted_ = deletedElements)
      }
      window = slider.slideBackByOnePosition()
      if (window.isEmpty()) {
        return null
      }
      if (!visited.add(window)) {
        continue
      }
      patterns =
        CachedUniformLengthDeletionPatternSets
          .getDeletionPatternSet(window.size)
          .interestingPatternsInDescendingOfNumOfDeletes
          .iterator()
    }
  }

  // A commit ends the current window early (the sequential search stopped at the first interesting
  // pattern) and re-enables re-sliding over windows that have now shifted.
  override fun onCommitted() {
    visited.clear()
    patterns = emptyList<ElementEditPattern>().iterator()
  }
}
