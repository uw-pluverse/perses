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

import kotlin.math.max
import kotlin.math.min

/**
 * The `minimize` strategy of Lithium (MozillaSecurity/lithium, `Minimize.reduce` in
 * `src/lithium/strategies.py`, as of commit 8b567a5), with its defaults: `--repeat last`,
 * `--min 1`, and no `--max`.
 *
 * Each round removes fixed-size chunks walking from the end of the list to the front, keeping every
 * deletion and never restarting mid-round. The chunk size starts at the largest power of two below
 * the list size and halves after each round; a round at size 1 repeats until it deletes nothing,
 * so the result is 1-minimal. Two details differ from a plain halving schedule and are kept on
 * purpose, since they are what Lithium runs:
 * - at chunk sizes 1 and 2, a failed chunk moves the window by one element, so size-2 chunks
 *   overlap;
 * - a round ends once a full chunk no longer fits, so the partial chunk at the front is left to the
 *   finer rounds.
 *
 * Lithium de-duplicates attempts by content, which the config cache enabled here reproduces.
 *
 * One deviation: a chunk spanning the whole list is not tried (see [tryDeletingBlock]).
 */
class LithiumMinimizer<T : Any, PropertyPayload>(
  arguments: ListMinimizerArguments<T, PropertyPayload>,
) : AbstractListMinimizer<T, PropertyPayload>(arguments, enableCache = true) {
  override fun reduceNonEmptyInput() {
    var chunkSize = largestPowerOfTwoSmallerThan(best.size)
    var chunkEnd = best.size
    var removedChunks = false
    while (true) {
      if (chunkEnd - chunkSize < 0) {
        if (chunkSize == 1) {
          if (!removedChunks) {
            return
          }
        } else {
          do {
            chunkSize = chunkSize shr 1
          } while (chunkSize > 1 && chunkSize >= best.size)
        }
        chunkEnd = best.size
        removedChunks = false
        arguments.log { "Round with chunk size $chunkSize over ${best.size} elements" }
      }
      val chunkStart = max(0, chunkEnd - chunkSize)
      if (tryDeletingBlock(best.subList(chunkStart, chunkEnd))) {
        removedChunks = true
        // An element deleted elsewhere also leaves [best], so the index may have run past its end.
        chunkEnd = min(chunkStart, best.size)
      } else {
        chunkEnd -= if (chunkSize <= 2) 1 else chunkSize
      }
    }
  }

  companion object {
    /** Lithium's `largest_power_of_two_smaller_than`: strictly smaller, except that 1 maps to 1. */
    fun largestPowerOfTwoSmallerThan(value: Int): Int {
      require(value > 0) { "value must be positive: $value" }
      val result = Integer.highestOneBit(value)
      return if (result == value && value > 1) result shr 1 else result
    }
  }
}
