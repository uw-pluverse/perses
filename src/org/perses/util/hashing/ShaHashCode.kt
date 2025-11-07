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
package org.perses.util.hashing

import com.google.common.hash.HashCode
import com.google.common.primitives.ImmutableIntArray

// TODO(cnsun): unit tests.
sealed class ShaHashCode(
  val digest: HashCode,
) {
  abstract val numOfStrings: Int

  abstract fun getLengthOfString(indexOfString: Int): Int

  abstract override fun equals(other: Any?): Boolean

  abstract override fun hashCode(): Int

  class ShaHashCodeForMultiStrings(
    private val stringLengths: ImmutableIntArray,
    digest: HashCode,
  ) : ShaHashCode(digest) {
    init {
      require(stringLengths.length() > 1) {
        "There should be at least two strings. $stringLengths"
      }
    }

    override val numOfStrings: Int
      get() = stringLengths.length()

    override fun getLengthOfString(indexOfString: Int) = stringLengths[indexOfString]

    override fun equals(other: Any?): Boolean {
      if (other == null) {
        return false
      }
      if (this === other) {
        return true
      }
      if (other !is ShaHashCodeForMultiStrings) {
        return false
      }
      return stringLengths == other.stringLengths && digest == other.digest
    }

    override fun hashCode(): Int = stringLengths.hashCode() * 31 + digest.hashCode()
  }

  class ShaHashCodeForSingleString(
    val stringLength: Int,
    digest: HashCode,
  ) : ShaHashCode(digest) {
    override val numOfStrings: Int
      get() = 1

    override fun getLengthOfString(indexOfString: Int): Int {
      require(indexOfString == 0) {
        "Invalid index $indexOfString"
      }
      return stringLength
    }

    override fun equals(other: Any?): Boolean {
      if (other == null) {
        return false
      }
      if (this === other) {
        return true
      }
      if (other !is ShaHashCodeForSingleString) {
        return false
      }
      return stringLength == other.stringLength && digest == other.digest
    }

    override fun hashCode(): Int = stringLength * 31 + digest.hashCode()
  }
}
