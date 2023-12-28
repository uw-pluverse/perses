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
package org.perses.util

import it.unimi.dsi.fastutil.chars.CharArrays
import java.io.Writer

class FastStringBuilder(capacity: Int) {

  private var size = 0

  private var data: CharArray

  var currentLineNo: Int = 1
    private set

  var charPositionInLine: Int = FIRST_CHAR_POSITION_IN_LINE
    private set

  fun append(s: String): FastStringBuilder {
    val stringLength = s.length
    val newSize = size + stringLength
    ensureCapacity(newSize)
    s.toCharArray(data, size, 0, stringLength)
    size = newSize
    updatePosition(s)
    return this
  }

  private fun updatePosition(s: String) {
    s.forEach { updatePosition(it) }
  }

  private fun updatePosition(c: Char) {
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

  fun lastChar() = data[length() - 1]

  fun capacity() = data.size

  private fun ensureCapacity(newLength: Int) {
    if (newLength > data.size) {
      val newCapacity = Math.max(data.size + data.size / 2, newLength)
      data = CharArrays.forceCapacity(data, newCapacity, data.size)
    }
  }

  init {
    require(capacity >= 0)
    data = if (capacity == 0) {
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
