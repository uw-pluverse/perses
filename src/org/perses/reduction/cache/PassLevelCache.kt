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
package org.perses.reduction.cache

import org.perses.reduction.ReducerAnnotation
import org.perses.util.Util

class PassLevelCache {

  enum class PassLevelCacheResult {
    NEW, EXISTING_ALREADY
  }

  @PublishedApi
  internal data class PassLevelCacheKey(
    val reducer: ReducerAnnotation,
    val contentsOfFiles: Util.SHA512HashCode,
  ) {
    init {
      require(contentsOfFiles.numOfStrings != 0) { "Cannot be empty." }
    }
  }

  @PublishedApi
  internal val cache = HashSet<PassLevelCacheKey>()

  // Might need to get rid of the stale keys if the memory consumption is a problem.
  inline fun update(
    reducer: ReducerAnnotation,
    contentsOfFilesProvider: () -> Util.SHA512HashCode,
  ): PassLevelCacheResult {
    val hashcodeOfAllInputs = contentsOfFilesProvider()
    val passLevelCacheKey = PassLevelCacheKey(reducer, hashcodeOfAllInputs)
    synchronized(cache) {
      return if (cache.add(passLevelCacheKey)) {
        PassLevelCacheResult.NEW
      } else {
        PassLevelCacheResult.EXISTING_ALREADY
      }
    }
  }
}
