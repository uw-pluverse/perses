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

interface IReductionLevelSequence {
  fun reset()
  operator fun hasNext(): Boolean
  fun nextLevel(): Int
  class ContinuousLevelSequence : IReductionLevelSequence {
    private var current = 0
    override fun hasNext(): Boolean {
      return true
    }

    override fun reset() {
      current = 0
    }

    override fun nextLevel(): Int {
      return ++current
    }
  }

  class FixedLevelSequence(
    sequence: ImmutableList<Int>,
    continuousAfterFinish: Boolean,
  ) : IReductionLevelSequence {
    private val sequence: ImmutableList<Int>
    private val continuousAfterFinish: Boolean
    private var current = 0
    private var iterator: Iterator<Int>

    init {
      sequence.forEach { check(it > 0) }
      this.sequence = sequence
      iterator = this.sequence.iterator()
      this.continuousAfterFinish = continuousAfterFinish
    }

    override fun reset() {
      iterator = sequence.iterator()
    }

    override fun hasNext(): Boolean {
      return continuousAfterFinish || iterator.hasNext()
    }

    override fun nextLevel(): Int {
      if (iterator.hasNext()) {
        current = iterator.next()
        return current
      }
      return if (continuousAfterFinish) {
        ++current
      } else {
        throw RuntimeException("No more levels.")
      }
    }
  }
}
