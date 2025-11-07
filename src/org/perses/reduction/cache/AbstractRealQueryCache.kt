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

import com.github.benmanes.caffeine.cache.Caffeine
import com.google.common.collect.ImmutableList
import org.perses.program.PersesTokenFactory
import org.perses.program.TokenizedProgram
import org.perses.reduction.PropertyTestResult
import org.perses.reduction.io.AbstractOutputManager
import java.util.ArrayList
import java.util.concurrent.TimeUnit
import kotlin.system.measureNanoTime

abstract class AbstractRealQueryCache<
  Encoding : AbstractProgramEncoding<Encoding>,
  Encoder : AbstractTokenizedProgramEncoder<Encoding>,
> protected constructor(
  tokenizedProgram: TokenizedProgram,
  private val profiler: AbstractQueryCacheProfiler,
  protected val configuration: QueryCacheConfiguration,
) : AbstractQueryCache() {
  private val cache =
    Caffeine
      .newBuilder()
      .expireAfterAccess(2, TimeUnit.HOURS)
      .build<Encoding, Encoding>()
  private val encoder: Encoder
  private val refreshStep: Int

  final override fun cacheSize(): Int {
    cache.cleanUp()
    return cache.estimatedSize().toInt()
  }

  override fun constructObjectsForMemoryMeasurement(): Any =
    cache.asMap().entries.map {
      it.key to it.value
    }

  @Synchronized
  final override fun getCachedResult(
    program: TokenizedProgram,
    outputManager: AbstractOutputManager,
  ): AbstractCacheRetrievalResult {
    val result: AbstractCacheRetrievalResult
    val nanoDuration =
      measureNanoTime {
        val encoding = encoder.encode(program, outputManager)
        result =
          AbstractCacheRetrievalResult.create(
            owner = this,
            program = program,
            encoding = encoding,
            isCacheHit = doesCacheContains(encoding),
          )
      }
    profiler.afterGetCachedResult(cache = this, nanoDuration = nanoDuration)
    return result
  }

  private fun doesCacheContains(encoding: Encoding?): Boolean {
    if (encoding == null) {
      return false
    }
    return cache.getIfPresent(encoding) != null
  }

  @Synchronized
  final override fun cacheProgramAndResult(
    program: AbstractCacheRetrievalResult.CacheMiss,
    result: PropertyTestResult,
  ) {
    val nanoDuration =
      measureNanoTime {
        check(program.owner === this)
        check(result.isNotInteresting)
        @Suppress("UNCHECKED_CAST")
        val key = program.getEncodingOrFail() as Encoding
        check(!doesCacheContains(key)) {
          "The key is already in the cache $key"
        }
        cache.put(key, key)
      }
    profiler.afterCacheProgramAndResult(cache = this, nanoDuration = nanoDuration)
  }

  private fun canTriggerHeavyweightCleanup(
    programInEncoder: ImmutableList<out PersesTokenFactory.AbstractPersesToken>,
    currentBestProgram: TokenizedProgram,
  ): Boolean {
    val oldSize = programInEncoder.size
    val newSize = currentBestProgram.tokenCount
    return oldSize - newSize >= refreshStep
  }

  @Synchronized
  final override fun evictEntriesLargerThan(best: TokenizedProgram) {
    profiler.beforeCacheEviction(cache = this)
    val nanoDuration =
      measureNanoTime {
        if (encoder.supportsRccReEncoding &&
          canTriggerHeavyweightCleanup(encoder.tokensInBaseProgram, best)
        ) {
          heavyweightCleanup(best)
        } else if (configuration.enableLightweightRefreshing) {
          lightweightCleanup(best)
        }
      }
    profiler.afterCacheEviction(cache = this, nanoDuration = nanoDuration)
  }

  final override fun triggerHeartBeat() {
    profiler.onHeartBeat(this)
  }

  protected abstract fun createEncoder(
    baseProgram: TokenizedProgram,
    profiler: AbstractQueryCacheProfiler,
  ): Encoder

  private fun heavyweightCleanup(best: TokenizedProgram) {
    val startNanoTime = System.nanoTime()
    val newKeys = ArrayList<Encoding>()
    val bestTokenCount = best.tokenCount
    val cacheSizeBefore = cacheSize()
    val oldTokensInOrigin = encoder.tokensInBaseProgram
    encoder.updateEncoder(best)
    val iter = cache.asMap().keys.iterator()
    while (iter.hasNext()) {
      val oldEncoding = iter.next()
      if (oldEncoding.tokenCount >= bestTokenCount) {
        // The cache program is ge the best program, and will not be used.
        iter.remove()
        continue
      }
      val optionalNewEncoding = encoder.reEncode(oldEncoding)
      if (optionalNewEncoding == null) {
        // This program will no longer be generated in the future.
        iter.remove()
        continue
      }
      if (optionalNewEncoding == oldEncoding) {
        // Keep the old encoding, as it is the same as the new one.
        continue
      } else {
        // The old encoding becomes stale. Remove it, and the new one will be added.
        iter.remove()
        newKeys.add(optionalNewEncoding)
      }
    }
    val newKeySize = newKeys.size
    for (i in 0 until newKeySize) {
      cache.put(newKeys[i], newKeys[i])
    }
    val endNanoTime = System.nanoTime()
    profiler.afterHeavyweightCacheRefreshing(
      oldTokensInOrigin,
      best.tokens,
      cacheSizeBefore,
      cacheSize(),
      nanoDuration = endNanoTime - startNanoTime,
    )
  }

  override fun clearCache() {
    cache.invalidateAll()
  }

  private fun lightweightCleanup(best: TokenizedProgram) {
    val tokenCount = best.tokenCount
    val keysToRemove =
      cache.asMap().keys.filter { key ->
        key.tokenCount >= tokenCount
      }
    cache.invalidateAll(keysToRemove)
  }

  init {
    val nanoDuration =
      measureNanoTime {
        encoder = createEncoder(tokenizedProgram, profiler)
      }
    profiler.onCreatingEncoder(
      tokensInOrigin = tokenizedProgram.tokens,
      nanoDuration = nanoDuration,
    )
    refreshStep = configuration.refreshStepFraction.multiply(tokenizedProgram.tokenCount)
  }
}
