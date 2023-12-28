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
package org.perses.reduction.reducer.vulcan.pattern

import com.google.common.collect.ImmutableList
import org.perses.reduction.AbstractTokenReducer
import org.perses.reduction.ReducerContext
import org.perses.reduction.reducer.token.AbstractConcurrentTokenSlicer

class LocalExhaustivePatternReducerAnnotation internal constructor(patternSize: Int) :
  AbstractConcurrentTokenSlicer.AbstractTokenSlicerAnnotation(
    namePrefix = LocalExhaustivePatternReducer.NAME_PREFIX,
    granularity = patternSize,
    description = "local exhaustive pattern reducer",
  ) {

  val patternSize: Int
    get() = granularity

  override fun create(reducerContext: ReducerContext): ImmutableList<AbstractTokenReducer> {
    return ImmutableList.of(LocalExhaustivePatternReducer(this, reducerContext))
  }
}
