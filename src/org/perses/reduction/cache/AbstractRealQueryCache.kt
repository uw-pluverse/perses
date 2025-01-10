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

import com.google.common.collect.ImmutableList
import com.google.common.flogger.FluentLogger
import org.perses.program.PersesTokenFactory
import org.perses.program.TokenizedProgram
import org.perses.reduction.PropertyTestResult
import org.perses.util.Util.lazyAssert
import org.perses.util.ktWarning
import java.util.ArrayList
import java.util.HashMap
import kotlin.system.measureNanoTime

abstract class AbstractRealQueryCache<
  Encoding : AbstractProgramEncoding<Encoding>,
  Encoder : AbstractTokenizedProgramEncoder<Encoding>,
  > protected constructor(
  tokenizedProgram: TokenizedProgram,
  private val profiler: AbstractQueryCacheProfiler,
  private val configuration: QueryCacheConfiguration,
) : AbstractQueryCache() {

  private val cache = HashMap<Encoding, PropertyTestResult>()
  private val encoder: Encoder
  private val refreshStep: Int

  final override fun size(): Int {
    return cache.size
  }

  @Synchronized
  final override fun getCachedResult(program: TokenizedProgram): AbstractCacheRetrievalResult {
    val result: AbstractCacheRetrievalResult
    val nanoDuration = measureNanoTime {
      val encoding = encoder.encode(program)
      result = AbstractCacheRetrievalResult.create(
        this,
        program,
        encoding,
        cache[encoding],
      )
    }
    profiler.afterGetCachedResult(cache = this, nanoDuration = nanoDuration)
    return result
  }

  @Synchronized
  final override fun cacheProgramAndResult(
    program: AbstractCacheRetrievalResult.CacheMiss,
    result: PropertyTestResult,
  ) {
    val nanoDuration = measureNanoTime {
      check(program.owner === this)
      check(result.isNotInteresting)
      @Suppress("UNCHECKED_CAST")
      val key = program.getEncodingOrFail() as Encoding
      val oldValue = cache.put(key, result)
      if (oldValue != null) {
        logger.ktWarning { "A query cache item was created before. This is unexpected." }
        lazyAssert { oldValue.isInteresting == result.isInteresting }
      }
    }
    profiler.afterCacheProgramAndResult(cache = this, nanoDuration = nanoDuration)
  }

  private fun canTriggerHeavyweightCleanup(
    programInEncoder: ImmutableList<PersesTokenFactory.PersesToken>,
    currentBestProgram: TokenizedProgram,
  ): Boolean {
    val oldSize = programInEncoder.size
    val newSize = currentBestProgram.tokenCount()
    return oldSize - newSize >= refreshStep
  }

  @Synchronized
  final override fun evictEntriesLargerThan(best: TokenizedProgram) {
    profiler.beforeCacheEviction(cache = this)
    val nanoDuration = measureNanoTime {
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
    val newValues = ArrayList<PropertyTestResult>()
    val bestTokenCount = best.tokenCount()
    val cacheSizeBefore = cache.size
    val oldTokensInOrigin: ImmutableList<PersesTokenFactory.PersesToken> =
      encoder.tokensInBaseProgram
    encoder.updateEncoder(best)
    val iter: MutableIterator<Map.Entry<Encoding, PropertyTestResult>> = cache.entries.iterator()
    while (iter.hasNext()) {
      val (oldEncoding, value) = iter.next()
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
        newValues.add(value)
      }
    }
    lazyAssert { newKeys.size == newValues.size }
    val newKeySize = newKeys.size
    for (i in 0 until newKeySize) {
      cache[newKeys[i]] = newValues[i]
    }
    val endNanoTime = System.nanoTime()
    profiler.afterHeavyweightCacheRefreshing(
      oldTokensInOrigin,
      best.tokens,
      cacheSizeBefore,
      cache.size,
      nanoDuration = endNanoTime - startNanoTime,
    )
  }

  private fun lightweightCleanup(best: TokenizedProgram) {
    val iter: MutableIterator<Map.Entry<Encoding, PropertyTestResult>> = cache.entries.iterator()
    val tokenCount = best.tokenCount()
    while (iter.hasNext()) {
      val (key) = iter.next()
      if (key.tokenCount >= tokenCount) {
        iter.remove()
      }
    }
  }

  companion object {
    private val logger = FluentLogger.forEnclosingClass()
  }

  init {
    val nanoDuration = measureNanoTime {
      encoder = createEncoder(tokenizedProgram, profiler)
    }
    profiler.onCreatingEncoder(
      tokensInOrigin = tokenizedProgram.tokens,
      nanoDuration = nanoDuration,
    )
    refreshStep = configuration.refreshStepFraction.multiply(tokenizedProgram.tokenCount())
  }
}
