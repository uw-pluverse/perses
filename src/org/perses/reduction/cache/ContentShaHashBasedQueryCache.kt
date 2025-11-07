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

import org.perses.program.TokenizedProgram
import org.perses.reduction.io.AbstractOutputManager
import org.perses.util.hashing.EnumShaAlgorithm
import org.perses.util.hashing.ShaHashCode

class ContentShaHashBasedQueryCache(
  tokenizedProgram: TokenizedProgram,
  profiler: AbstractQueryCacheProfiler,
  configuration: QueryCacheConfiguration,
) : AbstractRealQueryCache<ContentShaHashEncoding, ContentShaHashEncoder>(
    tokenizedProgram,
    profiler,
    configuration,
  ) {
  override fun createEncoder(
    baseProgram: TokenizedProgram,
    profiler: AbstractQueryCacheProfiler,
  ): ContentShaHashEncoder =
    ContentShaHashEncoder(
      baseProgram,
      profiler,
      enableFormat = false,
      shaAlgorithm = configuration.shaAlgorithm,
    )
}

class ContentShaHashEncoder(
  tokenizedProgram: TokenizedProgram,
  profiler: AbstractQueryCacheProfiler,
  private val enableFormat: Boolean,
  private val shaAlgorithm: EnumShaAlgorithm,
) : AbstractTokenizedProgramEncoder<ContentShaHashEncoding>(
    tokenizedProgram,
    profiler,
    supportsRccReEncoding = false,
  ) {
  override fun encode(
    program: TokenizedProgram,
    outputManager: AbstractOutputManager,
  ): ContentShaHashEncoding {
    val rawContent =
      if (enableFormat) {
        convertProgramToRawStringWithFormat(program)
      } else {
        convertProgramToRawString(program)
      }
    val hashCode = shaAlgorithm.createFromString(rawContent)
    return ContentShaHashEncoding(hashCode, program.tokenCount)
  }

  internal fun convertProgramToRawString(program: TokenizedProgram): String =
    program.tokens
      .asSequence()
      .map { it.lexemeText }
      .joinToString("\n")

  internal fun convertProgramToRawStringWithFormat(program: TokenizedProgram): String {
    if (program.tokens.isEmpty()) {
      return ""
    }
    var curLine =
      program.tokens[0]
        .asAntlrToken()
        .position.line
    return program.tokens
      .asSequence()
      .map {
        val antlr = it.asAntlrToken()
        if (antlr.position.line == curLine) {
          it.lexemeText + " "
        } else {
          curLine = antlr.position.line
          "\n" + it.lexemeText + " "
        }
      }.joinToString("")
  }

  override fun reEncode(previousEncoding: ContentShaHashEncoding): ContentShaHashEncoding? =
    throw UnsupportedOperationException()

  override fun updateEncoderMore(encoderBaseProgram: TokenizedProgram) {}
}

class ContentShaHashEncoding(
  private val shaHashCode: ShaHashCode,
  tokenCount: Int,
) : AbstractProgramEncoding<ContentShaHashEncoding>(shaHashCode.hashCode(), tokenCount) {
  override fun extraEquals(other: ContentShaHashEncoding): Boolean =
    shaHashCode == other.shaHashCode

  companion object {
    const val BYTE_SIZE_OF_SHA256 = 112
    const val BYTE_SIZE_OF_SHA512 = 144
  }
}
