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

import com.google.common.collect.ImmutableList
import org.perses.reduction.ReducerAnnotation
import org.perses.util.FileNameContentPair
import org.perses.util.Util.lazyAssert

class PassLevelCache {

  enum class PassLevelCacheResult {
    NEW, EXISTING_ALREADY
  }

  @PublishedApi
  internal data class Key(
    val reducer: ReducerAnnotation,
    val contentsOfFiles: ImmutableList<FileNameContentPair>,
  ) {
    init {
      require(contentsOfFiles.isNotEmpty()) { "Cannot be empty." }
    }
  }

  @PublishedApi
  internal val cache = HashSet<Key>()

  // Might need to get rid of the stale keys if the memory consumption is a problem.
  inline fun update(
    reducer: ReducerAnnotation,
    contentsOfFilesProvider: () -> ImmutableList<FileNameContentPair>,
  ): PassLevelCacheResult {
    val files = contentsOfFilesProvider()
    val key = Key(reducer, files)
    lazyAssert(
      {
        cache.isEmpty() ||
          cache.first().contentsOfFiles.map { it.fileName } == files.map { it.fileName }
      },
    ) {
      "The order of files should be the same."
    }
    return if (cache.add(key)) {
      PassLevelCacheResult.NEW
    } else {
      PassLevelCacheResult.EXISTING_ALREADY
    }
  }
}
