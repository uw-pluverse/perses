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
package org.perses.reduction

import com.google.common.io.Closer
import org.perses.reduction.AbstractGlobalExecutionCache.GlobalExecutionCache
import org.perses.util.FileStreamPool
import org.perses.util.hashing.EnumShaAlgorithm
import java.io.Closeable
import java.nio.file.Path

class GlobalContext(
  enableGlobalCache: Boolean,
  globalCacheFile: Path?,
  pathToSaveUpdatedGlobalCache: Path?,
  shaAlgorithm: EnumShaAlgorithm,
) : Closeable {
  private val closer = Closer.create()

  val fileStreamPool: FileStreamPool = closer.register(FileStreamPool())

  val globalExecutionCache =
    if (enableGlobalCache) {
      val cache =
        if (globalCacheFile != null) {
          GlobalExecutionCache.createFromHistoryCvsFile(shaAlgorithm, globalCacheFile)
        } else {
          GlobalExecutionCache.createEmpty(shaAlgorithm)
        }
      if (pathToSaveUpdatedGlobalCache != null) {
        closer.register(
          object : Closeable {
            override fun close() {
              cache.saveCacheEntriesToCsvFile(pathToSaveUpdatedGlobalCache)
            }
          },
        )
      }
      cache
    } else {
      AbstractGlobalExecutionCache.NullCache()
    }

  override fun close() {
    closer.close()
  }
}
