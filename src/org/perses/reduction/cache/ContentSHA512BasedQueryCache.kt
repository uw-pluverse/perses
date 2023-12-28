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
import org.perses.util.Util
import org.perses.util.Util.SHA512HashCode

class ContentSHA512BasedQueryCache(
  tokenizedProgram: TokenizedProgram,
  profiler: AbstractQueryCacheProfiler,
  configuration: QueryCacheConfiguration,
) : AbstractRealQueryCache<ContentSHA512Encoding, ContentSHA512Encoder>(
  tokenizedProgram,
  profiler,
  configuration,
) {

  override fun createEncoder(
    baseProgram: TokenizedProgram,
    profiler: AbstractQueryCacheProfiler,
  ): ContentSHA512Encoder {
    return ContentSHA512Encoder(baseProgram, profiler, enableFormat = false)
  }

  @Synchronized
  override fun evictEntriesLargerThan(best: TokenizedProgram) {
    /*
     * No eviction in content-string-based caching.
     */
  }
}

class ContentSHA512BasedFormatQueryCache(
  tokenizedProgram: TokenizedProgram,
  profiler: AbstractQueryCacheProfiler,
  configuration: QueryCacheConfiguration,
) : AbstractRealQueryCache<ContentSHA512Encoding, ContentSHA512Encoder>(
  tokenizedProgram,
  profiler,
  configuration,
) {

  override fun createEncoder(
    baseProgram: TokenizedProgram,
    profiler: AbstractQueryCacheProfiler,
  ): ContentSHA512Encoder {
    return ContentSHA512Encoder(baseProgram, profiler, enableFormat = true)
  }

  @Synchronized
  override fun evictEntriesLargerThan(best: TokenizedProgram) {}
}

class ContentSHA512Encoder(
  tokenizedProgram: TokenizedProgram,
  profiler: AbstractQueryCacheProfiler,
  private val enableFormat: Boolean,
) : AbstractTokenizedProgramEncoder<ContentSHA512Encoding>(tokenizedProgram, profiler) {

  override fun encode(program: TokenizedProgram): ContentSHA512Encoding {
    val rawContent = if (enableFormat) {
      convertProgramToRawStringWithFormat(program)
    } else {
      convertProgramToRawString(program)
    }
    val sha512 = Util.SHA512HashCode.createFromString(rawContent)
    return ContentSHA512Encoding(sha512, program.tokenCount())
  }

  internal fun convertProgramToRawString(program: TokenizedProgram): String {
    return program.tokens.asSequence()
      .map { it.text }
      .joinToString("\n")
  }

  internal fun convertProgramToRawStringWithFormat(program: TokenizedProgram): String {
    if (program.tokens.isEmpty()) { return "" }
    var curLine = program.tokens[0].position.line
    return program.tokens.asSequence().map {
      if (it.position.line == curLine) {
        it.text + " "
      } else {
        curLine = it.position.line
        "\n" + it.text + " "
      }
    }.joinToString("")
  }

  override fun reEncode(
    previousEncoding: ContentSHA512Encoding,
  ): ContentSHA512Encoding? {
    throw UnsupportedOperationException()
  }

  override fun updateEncoderMore(encoderBaseProgram: TokenizedProgram) {}
}

class ContentSHA512Encoding(private val sha512: SHA512HashCode, tokenCount: Int) :
  AbstractProgramEncoding<ContentSHA512Encoding>(sha512.hashCode(), tokenCount) {
  override fun extraEquals(other: ContentSHA512Encoding): Boolean {
    return sha512 == other.sha512
  }
}
