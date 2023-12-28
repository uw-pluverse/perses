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
import org.perses.reduction.cache.ContentZipBasedQueryCache.ContentZipEncoder
import org.perses.reduction.cache.ContentZipBasedQueryCache.ContentZipEncoding
import org.perses.util.Util

class ContentZipBasedQueryCache(
  tokenizedProgram: TokenizedProgram,
  profiler: AbstractQueryCacheProfiler,
  configuration: QueryCacheConfiguration,
) : AbstractRealQueryCache<ContentZipEncoding, ContentZipEncoder>(
  tokenizedProgram,
  profiler,
  configuration,
) {

  override fun createEncoder(
    baseProgram: TokenizedProgram,
    profiler: AbstractQueryCacheProfiler,
  ): ContentZipEncoder {
    return ContentZipEncoder(baseProgram, profiler)
  }

  override fun evictEntriesLargerThan(best: TokenizedProgram) {}

  class ContentZipEncoder(
    tokenizedProgram: TokenizedProgram,
    profiler: AbstractQueryCacheProfiler,
  ) : AbstractTokenizedProgramEncoder<ContentZipEncoding>(tokenizedProgram, profiler) {
    override fun encode(program: TokenizedProgram): ContentZipEncoding {
      val rawContent = program.tokens.asSequence()
        .map { it.text }
        .joinToString("\n")
      val zip: ByteArray = Util.zipCompress(rawContent)
      return ContentZipEncoding(zip, program.tokenCount())
    }

    override fun reEncode(previousEncoding: ContentZipEncoding): ContentZipEncoding? {
      throw UnsupportedOperationException()
    }

    override fun updateEncoderMore(encoderBaseProgram: TokenizedProgram) {}
  }

  class ContentZipEncoding(
    private val zip: ByteArray,
    tokenCount: Int,
  ) : AbstractProgramEncoding<ContentZipEncoding>(zip.contentHashCode(), tokenCount) {
    override fun extraEquals(other: ContentZipEncoding): Boolean {
      return zip.contentEquals(other.zip) // kotlin function for Arrays.equal()
    }

    fun decompressProgram(): String {
      return String(Util.zipDecompress(zip), Charsets.UTF_8)
    }
  }
}
