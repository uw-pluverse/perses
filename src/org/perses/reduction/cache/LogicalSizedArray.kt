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
package org.perses.reduction.cache

import org.perses.util.Util.lazyAssert

/**
 * Note that the entire class will be inlined. If you need to add new methods, you need to
 * mark them 'inline' too.
 */
@JvmInline
value class LogicalSizedArray @PublishedApi internal constructor(
  @PublishedApi internal val array: IntArray,
) {

  inline var logicalSize: Int
    get() = array[indexOfLogicalSize]
    set(value) {
      lazyAssert { value <= maxLogicalSize }
      array[indexOfLogicalSize] = value
    }

  inline val maxLogicalSize: Int
    get() = array.size - 1

  @PublishedApi
  internal inline val indexOfLogicalSize: Int
    get() = array.size - 1

  @Suppress("NOTHING_TO_INLINE")
  inline operator fun get(index: Int): Int {
    lazyAssert { index < logicalSize }
    return array[index]
  }

  @Suppress("NOTHING_TO_INLINE")
  inline operator fun set(index: Int, value: Int) {
    lazyAssert { index < logicalSize }
    array[index] = value
  }

  init {
    require(array.isNotEmpty())
    logicalSize = maxLogicalSize
  }

  companion object {
    @Suppress("NOTHING_TO_INLINE")
    inline fun createWithSize(size: Int): LogicalSizedArray {
      require(size >= 0)
      return LogicalSizedArray(IntArray(size + 1))
    }
  }
}
