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

import com.github.benmanes.caffeine.cache.Caffeine
import org.perses.reduction.PropertyTestResult
import org.perses.reduction.io.AbstractOutputManager
import org.perses.util.ImmutableIntArray
import org.perses.util.hashing.ShaHashCode
import java.util.concurrent.TimeUnit
import kotlin.system.measureNanoTime

/**
 * A query cache of the content hashes of programs already found uninteresting. The key is the
 * content identity ([ShaHashCode]); the value is the program's per-file sizes (non-blank character
 * counts), kept only as metadata for [evictEntriesNotSmallerThan]. A hit therefore needs only the
 * SHA hash.
 */
class ContentShaHashBasedFormatQueryCache(
  private val profiler: AbstractQueryCacheProfiler,
) : AbstractQueryCache() {
  private val cache =
    Caffeine
      .newBuilder()
      .expireAfterAccess(2, TimeUnit.HOURS)
      .build<ShaHashCode, ImmutableIntArray>()

  override fun cacheSize(): Int {
    cache.cleanUp()
    return cache.estimatedSize().toInt()
  }

  override fun constructObjectsForMemoryMeasurement(): Any =
    cache.asMap().entries.map {
      it.key to it.value
    }

  @Synchronized
  override fun lookUp(outputManager: AbstractOutputManager): CacheLookupResult {
    val result: CacheLookupResult
    val nanoDuration =
      measureNanoTime {
        val isHit = cache.getIfPresent(outputManager.shaHashCode) != null
        result = if (isHit) CacheLookupResult.HIT else CacheLookupResult.MISS
      }
    profiler.afterGetCachedResult(cache = this, nanoDuration = nanoDuration)
    return result
  }

  @Synchronized
  override fun recordUninteresting(
    outputManager: AbstractOutputManager,
    perFileNonBlankCharacterCounts: ImmutableIntArray,
    result: PropertyTestResult,
  ) {
    val nanoDuration =
      measureNanoTime {
        check(result.isNotInteresting)
        val shaHashCode = outputManager.shaHashCode
        check(cache.getIfPresent(shaHashCode) == null) {
          "The key is already in the cache $shaHashCode"
        }
        cache.put(shaHashCode, perFileNonBlankCharacterCounts)
      }
    profiler.afterCacheProgramAndResult(cache = this, nanoDuration = nanoDuration)
  }

  /**
   * The size-based refresh (Section 6.2 of the caching paper -- see
   * [org.perses.listminimizer.RccConfigCache] for the flagship RCC scheme on the list minimizer)
   * applied to this content-hash cache: when a new
   * minimum is found, evict every entry no smaller than it, since a deletion-based reducer can never
   * regenerate a variant that is not smaller than the current minimum. This is a sound, conservative
   * refresh -- it removes only entries that are provably unreachable, so it loses no cache hits.
   */
  @Synchronized
  override fun evictEntriesNotSmallerThan(perFileNonBlankCharacterCounts: ImmutableIntArray) {
    profiler.beforeCacheEviction(cache = this)
    val nanoDuration =
      measureNanoTime {
        val keysToRemove =
          cache
            .asMap()
            .entries
            .filter { (_, entryNonBlankCharacterCounts) ->
              // Partial order: evict an entry only when its size is >= the threshold in every file,
              // so a vector that is larger in one file but smaller in another is kept.
              entryNonBlankCharacterCounts.isComponentwiseGreaterThanOrEqualTo(
                perFileNonBlankCharacterCounts,
              )
            }.map { it.key }
        cache.invalidateAll(keysToRemove)
      }
    profiler.afterCacheEviction(cache = this, nanoDuration = nanoDuration)
  }

  override fun triggerHeartBeat() {
    profiler.onHeartBeat(this)
  }

  override fun clearCache() {
    cache.invalidateAll()
  }
}
