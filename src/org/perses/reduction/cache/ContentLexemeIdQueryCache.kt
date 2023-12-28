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

import com.google.common.collect.ImmutableList
import com.google.common.primitives.ImmutableIntArray
import org.perses.program.PersesTokenFactory
import org.perses.program.TokenizedProgram
import java.util.PrimitiveIterator

class ContentLexemeIdQueryCache(
  tokenizedProgram: TokenizedProgram,
  profiler: AbstractQueryCacheProfiler,
  configuration: QueryCacheConfiguration,
) : AbstractRealQueryCache<
  ContentLexemeIdQueryCache.ContentLexemeIdEncoding,
  ContentLexemeIdQueryCache.ContentLexemeIdEncoder,
  >(
  tokenizedProgram,
  profiler,
  configuration,
) {

  override fun createEncoder(
    baseProgram: TokenizedProgram,
    profiler: AbstractQueryCacheProfiler,
  ): ContentLexemeIdEncoder {
    return ContentLexemeIdEncoder(baseProgram, profiler)
  }

  class ContentLexemeIdEncoder(
    program: TokenizedProgram,
    profiler: AbstractQueryCacheProfiler,
  ) : AbstractTokenizedProgramEncoder<ContentLexemeIdEncoding>(program, profiler) {

    private var persesLexemeIdInOrigin: ImmutableIntArray

    override fun encode(program: TokenizedProgram): ContentLexemeIdEncoding? {
      return encode(
        program.tokens.stream().mapToInt(PersesTokenFactory.PersesToken::persesLexemeId).iterator(),
        program.tokenCount(),
      )
    }

    private fun encode(
      lexemeIterator: PrimitiveIterator.OfInt,
      tokenCount: Int,
    ): ContentLexemeIdEncoding? {
      val baseTokens = persesLexemeIdInOrigin
      val baseSize = baseTokens.length()
      if (tokenCount > baseSize) {
        return null
      }
      val builder = ImmutableIntArray.builder(tokenCount)
      var baseIndex = 0
      while (lexemeIterator.hasNext()) {
        val lexemeId = lexemeIterator.next()
        while (true) {
          if (baseIndex >= baseSize) {
            return null
          }
          val baseToken = baseTokens[baseIndex]
          ++baseIndex
          if (baseToken == lexemeId) {
            builder.add(lexemeId)
            break
          }
        }
      }
      return ContentLexemeIdEncoding(builder.build(), tokenCount)
    }

    override fun reEncode(
      previousEncoding: ContentLexemeIdEncoding,
    ): ContentLexemeIdEncoding? {
      return encode(
        previousEncoding.persesLexemeIdArray.stream().iterator(),
        previousEncoding.tokenCount,
      )
    }

    override fun updateEncoderMore(encoderBaseProgram: TokenizedProgram) {
      persesLexemeIdInOrigin = computeLexemeIdInOrig(encoderBaseProgram.tokens)
    }

    companion object {
      private fun computeLexemeIdInOrig(
        tokensInOrigin: ImmutableList<PersesTokenFactory.PersesToken>,
      ): ImmutableIntArray {
        val size = tokensInOrigin.size
        val builder = ImmutableIntArray.builder(size)
        for (i in 0 until size) {
          builder.add(tokensInOrigin[i].persesLexemeId)
        }
        return builder.build()
      }
    }

    init {
      persesLexemeIdInOrigin = computeLexemeIdInOrig(program.tokens)
    }
  }

  class ContentLexemeIdEncoding(val persesLexemeIdArray: ImmutableIntArray, tokenCount: Int) :
    AbstractProgramEncoding<ContentLexemeIdEncoding>(persesLexemeIdArray.hashCode(), tokenCount) {

    override fun extraEquals(other: ContentLexemeIdEncoding): Boolean {
      return persesLexemeIdArray == other.persesLexemeIdArray
    }
  }
}
