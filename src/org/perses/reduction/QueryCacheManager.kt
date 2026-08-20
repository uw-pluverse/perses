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

import org.perses.cmd.CacheControlFlagGroup
import org.perses.cmd.ProfilingFlagGroup
import org.perses.reduction.cache.AbstractQueryCache
import org.perses.reduction.cache.AbstractQueryCacheProfiler
import org.perses.reduction.cache.ContentShaHashBasedFormatQueryCache
import org.perses.reduction.cache.NullQueryCache
import org.perses.reduction.cache.QueryCacheMemoryProfiler
import org.perses.reduction.cache.QueryCacheTimeCsvProfiler
import org.perses.reduction.cache.QueryCacheTimeProfiler
import java.io.Closeable

/**
 * Owns a query [cache] and the [profiler] it writes to, and manages their joint lifecycle: it
 * builds the cache from the command-line flags and, on [close], returns the profiler's rented stream
 * to the file-stream pool.
 *
 * One manager backs a whole reduction so a single cache can outlive the individual drivers that use
 * it -- in [PerFileReductionDriver] one cache is shared across every per-file driver
 * (an uninteresting whole-set state recorded while reducing one file is reusable once a later file
 * reaches it, since the cache key is the whole mutable-file set's content hash). The owner decides
 * when to close it: [PerFileReductionDriver] does so explicitly, while single-driver
 * algorithms (e.g. PPR) register it with the driver's closer.
 */
class QueryCacheManager private constructor(
  val cache: AbstractQueryCache,
  private val profiler: AbstractQueryCacheProfiler,
) : Closeable {
  override fun close() {
    profiler.close()
  }

  companion object {
    fun create(
      profilingFlags: ProfilingFlagGroup,
      cacheControlFlags: CacheControlFlagGroup,
      globalContext: GlobalContext,
    ): QueryCacheManager =
      if (cacheControlFlags.queryCaching) {
        val profiler = createProfiler(profilingFlags, globalContext)
        QueryCacheManager(ContentShaHashBasedFormatQueryCache(profiler), profiler)
      } else {
        QueryCacheManager(NullQueryCache(), AbstractQueryCacheProfiler.NULL_PROFILER)
      }

    private fun createProfiler(
      profilingFlags: ProfilingFlagGroup,
      globalContext: GlobalContext,
    ): AbstractQueryCacheProfiler =
      if (profilingFlags.profileQueryCacheTimeCSV != null) {
        QueryCacheTimeCsvProfiler(
          globalContext.fileStreamPool.rentStream(
            profilingFlags.profileQueryCacheTimeCSV!!,
            description = QueryCacheTimeCsvProfiler::class.qualifiedName,
          ),
        )
      } else if (profilingFlags.profileQueryCacheTime != null) {
        QueryCacheTimeProfiler(
          globalContext.fileStreamPool.rentStream(
            profilingFlags.profileQueryCacheTime!!,
            description = QueryCacheTimeProfiler::class.qualifiedName,
          ),
        )
      } else if (profilingFlags.profileQueryCacheMemory != null) {
        QueryCacheMemoryProfiler(
          globalContext.fileStreamPool.rentStream(
            profilingFlags.profileQueryCacheMemory!!,
            description = QueryCacheMemoryProfiler::class.qualifiedName,
          ),
        )
      } else {
        AbstractQueryCacheProfiler.NULL_PROFILER
      }
  }
}
