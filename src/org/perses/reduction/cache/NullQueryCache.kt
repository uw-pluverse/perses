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
package org.perses.reduction.cache

import org.perses.program.TokenizedProgram
import org.perses.reduction.PropertyTestResult
import org.perses.reduction.cache.AbstractCacheRetrievalResult.Companion.create

class NullQueryCache : AbstractQueryCache() {

  override fun getCachedResult(program: TokenizedProgram): AbstractCacheRetrievalResult {
    return create(owner = this, program = program, encoding = null, testResult = null)
  }

  override fun addResult(
    program: AbstractCacheRetrievalResult.CacheMiss,
    result: PropertyTestResult,
  ) {
    require(program.owner === this)
  }

  override fun size() = 0

  override fun evictEntriesLargerThan(best: TokenizedProgram) = Unit

  override fun triggerHeartBeat() = Unit
}
