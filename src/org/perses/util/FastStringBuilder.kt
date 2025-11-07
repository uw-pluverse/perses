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
package org.perses.util

import java.io.Writer

class FastStringBuilder(
  capacity: Int,
) {
  private var size = 0

  private var data: CharArray

  var currentLineNo: Int = 1
    private set

  var charPositionInLine: Int = FIRST_CHAR_POSITION_IN_LINE
    private set

  fun append(s: String): FastStringBuilder {
    val stringLength = s.length
    if (stringLength == 0) {
      return this
    }
    val oldSize = size
    val newSize = oldSize + stringLength
    ensureCapacity(newSize)
    s.toCharArray(
      destination = data,
      destinationOffset = oldSize,
      startIndex = 0,
      endIndex = stringLength,
    )
    updatePosition(startIndexInclusive = oldSize, endIndexExclusive = oldSize + stringLength)
    size = newSize
    return this
  }

  // FIXME: use the subarray of data to update the position.
  private fun updatePosition(
    startIndexInclusive: Int,
    endIndexExclusive: Int,
  ) {
    val data = this.data
    for (i in startIndexInclusive until endIndexExclusive) {
      updatePosition(data[i])
    }
  }

  @Suppress("NOTHING_TO_INLINE")
  private inline fun updatePosition(c: Char) {
    if (c == '\n') {
      ++currentLineNo
      charPositionInLine = FIRST_CHAR_POSITION_IN_LINE
    } else {
      ++charPositionInLine
    }
  }

  fun length() = size

  fun isEmpty() = length() == 0

  fun isNotEmpty() = !isEmpty()

  fun append(c: Char): FastStringBuilder {
    val newSize = size + 1
    ensureCapacity(newSize)
    data[size] = c
    size = newSize
    updatePosition(c)
    return this
  }

  override fun toString() = String(data, 0, length())

  fun writeToWriter(writer: Writer) {
    writer.write(data, 0, length())
  }

  fun lastCharOrThrow() = data[length() - 1]

  fun capacity() = data.size

  private fun ensureCapacity(newLength: Int) {
    val currentDataSize = data.size
    if (newLength <= currentDataSize) {
      return
    }
    val newCapacity = (currentDataSize * 2 + 10).coerceAtLeast(newLength)
    data = data.copyOf(newCapacity)
  }

  init {
    require(capacity >= 0)
    data =
      if (capacity == 0) {
        EMPTY
      } else {
        CharArray(capacity)
      }
  }

  companion object {
    private val EMPTY = CharArray(0)
    private const val FIRST_CHAR_POSITION_IN_LINE = 0
  }
}
