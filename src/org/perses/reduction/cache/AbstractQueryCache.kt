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
package org.perses.reduction.cache

import org.perses.reduction.TestScriptVerdict
import org.perses.reduction.io.AbstractOutputManager
import org.perses.util.ImmutableIntArray

abstract class AbstractQueryCache {
  abstract fun lookUp(outputManager: AbstractOutputManager): CacheLookupResult

  abstract fun recordUninteresting(
    outputManager: AbstractOutputManager,
    perFileNonBlankCharacterCounts: ImmutableIntArray,
    result: TestScriptVerdict,
  )

  abstract fun cacheSize(): Int

  abstract fun evictEntriesNotSmallerThan(perFileNonBlankCharacterCounts: ImmutableIntArray)

  abstract fun triggerHeartBeat()

  abstract fun clearCache()

  abstract fun constructObjectsForMemoryMeasurement(): Any
}
