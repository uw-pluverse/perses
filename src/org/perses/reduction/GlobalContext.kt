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
package org.perses.reduction

import com.google.common.flogger.FluentLogger
import com.google.common.io.Closer
import org.perses.reduction.AbstractGlobalExecutionCache.GlobalExecutionCache
import org.perses.util.AtomicSequenceGenerator
import org.perses.util.FileStreamPool
import org.perses.util.hashing.EnumShaAlgorithm
import org.perses.util.ktFine
import java.io.Closeable
import java.nio.file.Path

class GlobalContext(
  enableGlobalCache: Boolean,
  globalCacheFile: Path?,
  pathToSaveUpdatedGlobalCache: Path?,
  val shaAlgorithm: EnumShaAlgorithm,
) : Closeable {
  /**
   * Issues the ids of recorded list-minimization problems, shared by every driver. Only used in
   * RECORD mode, but held unconditionally because it is inert otherwise: a multi-file reduction runs
   * a driver per file, and a generator each would restart the sequence, collide folder names, and
   * turn the recording cap into a per-file limit.
   */
  val listMinimizationProblemIdGenerator =
    AtomicSequenceGenerator(start = 0, minLengthForPadding = PROBLEM_ID_WIDTH)

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
    val className: String = this::class.java.name
    logger.ktFine { "Closing the resources used in $className..." }
    closer.close()
  }

  companion object {
    private val logger = FluentLogger.forEnclosingClass()

    /** Wide enough that a lexical sort of the recorded problem folders is a chronological one. */
    private const val PROBLEM_ID_WIDTH = 6
  }
}
