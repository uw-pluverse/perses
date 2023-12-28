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
import org.perses.program.PersesTokenFactory
import org.perses.program.TokenizedProgram

class ContentLexemeListQueryCache(
  tokenizedProgram: TokenizedProgram,
  profiler: AbstractQueryCacheProfiler,
  configuration: QueryCacheConfiguration,
) : AbstractRealQueryCache<
  ContentLexemeListQueryCache.ContentLexemeListEncoding,
  ContentLexemeListQueryCache.ContentLexemeListEncoder,
  >(
  tokenizedProgram,
  profiler,
  configuration,
) {

  override fun createEncoder(
    baseProgram: TokenizedProgram,
    profiler: AbstractQueryCacheProfiler,
  ): ContentLexemeListEncoder {
    return ContentLexemeListEncoder(baseProgram, profiler)
  }

  class ContentLexemeListEncoder(
    tokenizedProgram: TokenizedProgram,
    profiler: AbstractQueryCacheProfiler,
  ) : AbstractTokenizedProgramEncoder<ContentLexemeListEncoding>(tokenizedProgram, profiler) {

    override fun encode(program: TokenizedProgram): ContentLexemeListEncoding? {
      return encode(
        program.tokens.stream().map { obj: PersesTokenFactory.PersesToken -> obj.text }
          .iterator(),
        program.tokenCount(),
      )
    }

    private fun encode(
      lexemeIterator: Iterator<String>,
      tokenCount: Int,
    ): ContentLexemeListEncoding? {
      val baseTokens: ImmutableList<PersesTokenFactory.PersesToken> = tokensInBaseProgram
      val baseSize = baseTokens.size
      if (tokenCount > baseSize) {
        return null
      }
      val builder = ImmutableList.builderWithExpectedSize<String>(tokenCount)
      var baseIndex = 0
      while (lexemeIterator.hasNext()) {
        val lexeme = lexemeIterator.next()
        while (true) {
          if (baseIndex >= baseSize) {
            return null
          }
          val baseToken = baseTokens[baseIndex]
          ++baseIndex
          if (baseToken.text == lexeme) {
            builder.add(lexeme)
            break
          }
        }
      }
      return ContentLexemeListEncoding(builder.build())
    }

    override fun reEncode(
      previousEncoding: ContentLexemeListEncoding,
    ): ContentLexemeListEncoding? {
      return encode(previousEncoding.tokens.iterator(), previousEncoding.tokenCount)
    }

    override fun updateEncoderMore(encoderBaseProgram: TokenizedProgram) {}
  }

  class ContentLexemeListEncoding(val tokens: ImmutableList<String>) :
    AbstractProgramEncoding<ContentLexemeListEncoding>(tokens.hashCode(), tokens.size) {

    override fun extraEquals(other: ContentLexemeListEncoding): Boolean {
      return tokens == other.tokens
    }
  }
}
