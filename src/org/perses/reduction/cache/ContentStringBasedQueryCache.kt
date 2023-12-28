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

import org.perses.program.PersesTokenFactory
import org.perses.program.TokenizedProgram
import java.lang.UnsupportedOperationException
import java.util.stream.Collectors

/**
 * The content-based caching used in the following paper.
 *
 *
 * enata Hodovan, Akos Kiss, and Tibor Gyimothy. Tree Preprocessing and Test Outcome Caching for
 * Efficient Hierarchical Delta Debugging. In Proceedings of the 12th IEEE/ACM International
 * Workshop on Automation of Software Testing (AST 2017), pages 23-29, Buenos Aires, Argentina, May
 * 2017. IEEE.
 */
class ContentStringBasedQueryCache(
  tokenizedProgram: TokenizedProgram,
  profiler: AbstractQueryCacheProfiler,
  configuration: QueryCacheConfiguration,
) : AbstractRealQueryCache<
  ContentStringBasedQueryCache.ContentStringEncoding,
  ContentStringBasedQueryCache.ContentStringEncoder,
  >(
  tokenizedProgram,
  profiler,
  configuration,
) {
  override fun createEncoder(
    baseProgram: TokenizedProgram,
    profiler: AbstractQueryCacheProfiler,
  ): ContentStringEncoder {
    return ContentStringEncoder(baseProgram, profiler)
  }

  @Synchronized
  override fun evictEntriesLargerThan(best: TokenizedProgram) {
    // No eviction in content-string-based caching.
  }

  class ContentStringEncoder(
    tokenizedProgram: TokenizedProgram,
    profiler: AbstractQueryCacheProfiler,
  ) : AbstractTokenizedProgramEncoder<ContentStringEncoding>(tokenizedProgram, profiler) {

    override fun encode(program: TokenizedProgram): ContentStringEncoding {
      return ContentStringEncoding(
        program.tokens.stream()
          .map { obj: PersesTokenFactory.PersesToken -> obj.text }
          .collect(Collectors.joining("\n")),
        program.tokenCount(),
      )
    }

    override fun reEncode(
      previousEncoding: ContentStringEncoding,
    ): ContentStringEncoding? {
      throw UnsupportedOperationException()
    }

    override fun updateEncoderMore(encoderBaseProgram: TokenizedProgram) {}
  }

  class ContentStringEncoding(private val content: String, tokenCount: Int) :
    AbstractProgramEncoding<ContentStringEncoding>(
      content.hashCode(),
      tokenCount,
    ) {
    override fun extraEquals(other: ContentStringEncoding): Boolean {
      return content == other.content
    }
  }
}
