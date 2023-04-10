/*
 * Copyright (C) 2018-2022 University of Waterloo.
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

interface IPropertyTester<T, Payload> {
  fun testProperty(
    currentBest: ImmutableList<T>,
    candidate: ImmutableList<T>,
  ): AbstractPropertyTestResultWithPayload<Payload>
}

abstract class AbstractPropertyTestResultWithPayload<Payload> {

  abstract fun needsSkip(): Boolean

  abstract val result: PropertyTestResult

  abstract val payload: Payload
}

class SkipPropertyTestResult<Payload> : AbstractPropertyTestResultWithPayload<Payload>() {
  override fun needsSkip() = true

  override val result: PropertyTestResult
    get() = TODO("Not yet implemented")

  override val payload: Payload
    get() = TODO("Not yet implemented")
}

data class PropertyTestResultWithPayload<Payload>(
  override val result: PropertyTestResult,
  override val payload: Payload,
) : AbstractPropertyTestResultWithPayload<Payload>() {

  override fun needsSkip() = false
}
