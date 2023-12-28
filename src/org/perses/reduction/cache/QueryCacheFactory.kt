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
import org.perses.reduction.cache.QueryCacheType.COMPACT_QUERY_CACHE
import org.perses.reduction.cache.QueryCacheType.COMPACT_QUERY_CACHE_FORMAT_SENSITIVE
import org.perses.reduction.cache.QueryCacheType.CONFIG_BASED
import org.perses.reduction.cache.QueryCacheType.CONTENT_LEXEME_LIST_BASE
import org.perses.reduction.cache.QueryCacheType.CONTENT_SHA512
import org.perses.reduction.cache.QueryCacheType.CONTENT_SHA512_FORMAT
import org.perses.reduction.cache.QueryCacheType.CONTENT_ZIP
import org.perses.reduction.cache.QueryCacheType.ORIG_CONTENT_STRING_BASED
import org.perses.reduction.cache.QueryCacheType.PERSES_FAST_LINEAR_SCAN_NO_COMPRESSION
import org.perses.reduction.cache.QueryCacheType.PERSES_LEXEME_ID
import org.perses.reduction.cache.QueryCacheType.RCC_MEM_LIT

object QueryCacheFactory {

  @JvmStatic
  fun createQueryCache(
    cacheType: QueryCacheType,
    tokenizedProgram: TokenizedProgram,
    profiler: AbstractQueryCacheProfiler,
    configuration: QueryCacheConfiguration,
  ): AbstractQueryCache {
    return when (cacheType) {
      ORIG_CONTENT_STRING_BASED ->
        ContentStringBasedQueryCache(
          tokenizedProgram,
          profiler,
          configuration,
        )
      CONTENT_LEXEME_LIST_BASE ->
        ContentLexemeListQueryCache(
          tokenizedProgram,
          profiler,
          configuration,
        )
      CONFIG_BASED ->
        ConfigBasedQueryCache()
      PERSES_LEXEME_ID ->
        ContentLexemeIdQueryCache(
          tokenizedProgram,
          profiler,
          configuration,
        )
      COMPACT_QUERY_CACHE -> {
        CompactQueryCache(
          tokenizedProgram,
          profiler,
          configuration,
        )
      }
      COMPACT_QUERY_CACHE_FORMAT_SENSITIVE -> {
        CompactQueryCacheFormatSensitive(
          tokenizedProgram,
          profiler,
          configuration,
        )
      }
      PERSES_FAST_LINEAR_SCAN_NO_COMPRESSION -> {
        QueryCacheWithFastLinearScanWithoutCompression(
          tokenizedProgram,
          profiler,
          configuration,
        )
      }
      CONTENT_SHA512 -> {
        ContentSHA512BasedQueryCache(
          tokenizedProgram,
          profiler,
          configuration,
        )
      }
      CONTENT_SHA512_FORMAT -> {
        ContentSHA512BasedFormatQueryCache(
          tokenizedProgram,
          profiler,
          configuration,
        )
      }
      CONTENT_ZIP -> {
        ContentZipBasedQueryCache(
          tokenizedProgram,
          profiler,
          configuration,
        )
      }
      RCC_MEM_LIT -> {
        RccMemLitQueryCache(
          tokenizedProgram,
          profiler,
          configuration,
        )
      }
      else -> {
        TODO("Unhandled $cacheType")
      }
    }
  }
}
