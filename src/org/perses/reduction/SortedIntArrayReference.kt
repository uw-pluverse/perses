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
package org.perses.reduction

import com.google.common.collect.ImmutableList
import org.perses.util.Util.lazyAssert
import java.util.Arrays

class SortedIntArrayReference(expectedSize: Int) {

  private var array: AbstractSortedIntArray

  init {
    lazyAssert { expectedSize > 0 }
    array = if (expectedSize == 1) {
      SingleInteger()
    } else {
      lazyAssert { expectedSize > 1 }
      MultipleIntegers(expectedSize)
    }
  }

  fun size() = array.size()

  fun getInt(index: Int) = array.getInt(index)

  fun binarySearch(fromIndex: Int, key: Int) =
    array.binarySearch(fromIndex, key)

  fun resetWithNewExpectedSize(newExpectedSize: Int) {
    lazyAssert { newExpectedSize > 0 }
    if (newExpectedSize == 1) {
      if (array is SingleInteger) {
        array.reset(newExpectedSize)
      } else {
        lazyAssert { array is MultipleIntegers }
        array = SingleInteger()
      }
    } else {
      lazyAssert { newExpectedSize > 1 }
      array.reset(newExpectedSize)
    }
    lazyAssert { array.size() == 0 }
  }

  fun add(value: Int) {
    array.add(value)
  }

  fun toList() = array.toList()

  abstract class AbstractSortedIntArray {

    abstract fun size(): Int

    abstract fun add(value: Int)

    abstract fun isFull(): Boolean

    abstract fun reset(newExpectedSize: Int)

    abstract fun binarySearch(fromIndex: Int, key: Int): Int

    abstract fun getInt(index: Int): Int

    abstract fun toList(): ImmutableList<Int>
  }

  class SingleInteger : AbstractSortedIntArray() {

    private var value: Int = INVALID_INT

    override fun size(): Int {
      return if (value == INVALID_INT) {
        0
      } else {
        1
      }
    }

    override fun add(value: Int) {
      check(this.value == INVALID_INT)
      this.value = value
      lazyAssert { this.value != INVALID_INT }
    }

    override fun isFull() = size() == 1

    override fun reset(newExpectedSize: Int) {
      check(newExpectedSize == 1)
      value = INVALID_INT
    }

    override fun binarySearch(fromIndex: Int, key: Int): Int {
      check(isFull())
      if (fromIndex == 0) {
        val value = this.value
        if (key == value) {
          return 0
        } else if (key < value) {
          return -1
        } else {
          lazyAssert { key > value }
          return -1 - 1
        }
      } else {
        lazyAssert { fromIndex > 0 }
        return -1 - 1
      }
    }

    override fun getInt(index: Int): Int {
      require(index == 0)
      require(size() == 1)
      return value
    }

    override fun toList() =
      if (isFull()) {
        ImmutableList.of(value)
      } else {
        ImmutableList.of()
      }
  }

  class MultipleIntegers(private var expectedSize: Int) : AbstractSortedIntArray() {

    init {
      require(expectedSize > 1)
    }

    private var array = IntArray(expectedSize)
    private var size = 0

    override fun add(value: Int) {
      array[size++] = value
    }

    override fun size() = size

    override fun isFull() = size == expectedSize

    override fun reset(newExpectedSize: Int) {
      val oldExpectedSize = expectedSize
      expectedSize = newExpectedSize
      lazyAssert { newExpectedSize <= oldExpectedSize }
      lazyAssert { newExpectedSize > 1 }

      size = 0
      if (newExpectedSize + 3 < oldExpectedSize) {
        array = IntArray(newExpectedSize)
      } else {
        // Do nothing. Reuse the old array.
      }
      lazyAssert { expectedSize == newExpectedSize }
    }

    override fun binarySearch(fromIndex: Int, key: Int): Int {
      check(isFull())
      return Arrays.binarySearch(array, fromIndex, expectedSize, key)
    }

    override fun getInt(index: Int): Int {
      check(isFull())
      require(index < expectedSize)
      return array[index]
    }

    override fun toList(): ImmutableList<Int> {
      lazyAssert { isFull() }
      val builder = ImmutableList.builder<Int>()
      for (i in 0 until size) {
        builder.add(array[i])
      }
      return builder.build()
    }
  }

  companion object {

    private const val INVALID_INT = Integer.MIN_VALUE
  }
}
