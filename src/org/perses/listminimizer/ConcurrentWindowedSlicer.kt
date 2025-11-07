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
package org.perses.listminimizer

import com.google.common.collect.ImmutableList
import org.perses.util.Util
import org.perses.util.Util.NonEmptySublist
import org.perses.util.toImmutableList

// TODO(cnsun): need to finish this.
class ConcurrentWindowedSlicer<T : Any, PropertyPayload>(
  arguments: ListMinimizerArguments<T, PropertyPayload>,
) : AbstractWindowedSlicer<T, PropertyPayload>(arguments) {
  override fun reduceNonEmptyInput() {
    val minWindowSize = extraArguments.minSlidingWindowSize
    val maxWindowSize = extraArguments.maxSlidingWindowSize
    for (windowSize in minWindowSize..maxWindowSize) {
      arguments.log { "Window size: $windowSize" }
      val elements = best
      val deletedElements = mutableSetOf<ElementWrapper<T>>()
      val windows =
        Util
          .slideReverseIfSlideable(
            list = best,
            slidingWindowSize = windowSize,
          ).toImmutableList()
      val executor = ConcurrentExecutor(windows)
      executor.run()
    }
  }

  private inner class ConcurrentExecutor(
    windows: ImmutableList<NonEmptySublist<ElementWrapper<T>>>,
  ) {
    private val workingDeque = ArrayDeque<NonEmptySublist<ElementWrapper<T>>>()
    private val respawnDeque = ArrayDeque<NonEmptySublist<ElementWrapper<T>>>()
    private val pendingDeque = ArrayDeque<NonEmptySublist<ElementWrapper<T>>>(windows)

    fun run() {
    }
  }
}
