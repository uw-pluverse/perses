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
package org.perses.delta

import com.google.common.collect.ImmutableList
import org.perses.reduction.PropertyTestResult
import org.perses.util.Util
import org.perses.util.Util.lazyAssert
import org.perses.util.isSortedAscendinglyBy
import org.perses.util.transformToImmutableList

class Configuration<T>(
  val currentBest: ImmutableList<AbstractDeltaDebugger.ElementWrapper<T>>?,
  private val candidate_: ImmutableList<AbstractDeltaDebugger.ElementWrapper<T>>?,
  private val deleted_: ImmutableList<AbstractDeltaDebugger.ElementWrapper<T>>?,
) {
  init {
    require(currentBest != null || candidate_ != null || deleted_ != null) {
      "The three fields cannot be null at the same time."
    }
    require(candidate_ != null || deleted_ != null)
    lazyAssert {
      currentBest == null || currentBest.isSortedAscendinglyBy { it.index }
    }
    lazyAssert {
      candidate_ == null || candidate_.isSortedAscendinglyBy { it.index }
    }
    lazyAssert {
      deleted_ == null || deleted_.isSortedAscendinglyBy { it.index }
    }
  }

  val deletedWrappers: ImmutableList<AbstractDeltaDebugger.ElementWrapper<T>> by lazy {
    deleted_ ?: Util.computeDifference(currentBest!!, candidate_!!)
  }

  val deleted: ImmutableList<T> by lazy {
    deletedWrappers.transformToImmutableList { it.element }
  }

  val candidate: ImmutableList<T> by lazy {
    candidate_?.transformToImmutableList { it.element }
      ?: Util.computeDifference(currentBest!!, deleted_!!).transformToImmutableList { it.element }
  }
}

fun interface IPropertyTester<T, Payload> {
  fun testProperty(
    configuration: Configuration<T>,
  ): AbstractPropertyTestResultWithPayload<Payload>
}

// TODO(cnsun): make it sealed.
sealed class AbstractPropertyTestResultWithPayload<Payload>

class SkipPropertyTestResult<Payload> : AbstractPropertyTestResultWithPayload<Payload>()

data class PropertyTestResultWithPayload<Payload>(
  val result: PropertyTestResult,
  val payload: Payload,
) : AbstractPropertyTestResultWithPayload<Payload>()
