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
package org.perses.reduction.reducer.token

import com.google.common.collect.ImmutableList

class ConcurrentTokenSlicerTaskDesc<T>(
  private val tokens: ImmutableList<T>,
  val startIndex: Int,
  val slicingGranularity: Int,
) {

  init {
    val size = tokens.size
    require(size > 0)
    require(startIndex in 0 until size) {
      "$startIndex vs. $size"
    }
    require(slicingGranularity > 0)
    require(startIndex + slicingGranularity - 1 < size)
  }

  fun next(): ConcurrentTokenSlicerTaskDesc<T>? {
    val size = tokens.size
    val newStartIndex = startIndex + 1
    if (newStartIndex + slicingGranularity - 1 < size) {
      return ConcurrentTokenSlicerTaskDesc(
        tokens,
        startIndex = newStartIndex,
        slicingGranularity = slicingGranularity,
      )
    }
    val newGranularity = slicingGranularity - 1
    if (newGranularity == 0) {
      return null
    }
    return ConcurrentTokenSlicerTaskDesc(
      tokens,
      startIndex = 0,
      slicingGranularity = newGranularity,
    )
  }
}
