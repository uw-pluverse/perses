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

import kotlin.random.Random

/**
 * [CounterBasedDeltaDebugger] with a 1-minimal result.
 *
 * CDD stops visiting an element once deleting it alone fails, but that failure was observed against
 * the best at that moment; a later deletion can make the element removable, and CDD never retries
 * it. This minimizer runs CDD's search unchanged and then WDD's final pass,
 * [AbstractListMinimizer.ensureOneMinimal], so every survivor has failed alone against the final
 * best.
 */
class OneMinimalCounterBasedDeltaDebugger<T : Any, PropertyPayload>(
  arguments: ListMinimizerArguments<T, PropertyPayload>,
  random: Random? = null,
  initialProbability: Double = 0.25,
) : CounterBasedDeltaDebugger<T, PropertyPayload>(arguments, random, initialProbability) {
  override fun reduceNonEmptyInput() {
    super.reduceNonEmptyInput()
    ensureOneMinimal()
  }
}
