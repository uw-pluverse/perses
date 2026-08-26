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
import org.perses.util.lazyAssert
import org.perses.util.toImmutableList

class BackwardWindowSlider<T : Any>(
  val expectedWindowSize: Int,
  val list: List<T>,
  val isDeleted: (element: T) -> Boolean,
) {
  init {
    require(expectedWindowSize > 0) {
      "Invalid expected window size: $expectedWindowSize. Should be positive"
    }
    lazyAssert({
      list.toSet().size == list.size
    }) {
      "The objects in the list should be distinct. $list"
    }
  }

  private var currentStartIndex = list.size - 1

  fun slideBackByOnePosition(): ImmutableList<T> {
    val result = mutableListOf<T>()
    while (currentStartIndex >= 0 && isDeleted(list[currentStartIndex])) {
      --currentStartIndex
    }
    var index = currentStartIndex
    while (index >= 0 && result.size < expectedWindowSize) {
      val element = list[index]
      --index
      if (isDeleted(element)) {
        continue
      }
      result.add(element)
    }
    if (index < 0) {
      currentStartIndex = -1
    } else {
      --currentStartIndex
    }
    return result.asReversed().toImmutableList()
  }
}
