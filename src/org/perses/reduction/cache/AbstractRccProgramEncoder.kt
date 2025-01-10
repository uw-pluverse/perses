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

import it.unimi.dsi.fastutil.ints.IntArrayList
import org.perses.program.PersesTokenFactory
import org.perses.program.TokenizedProgram
import org.perses.util.Util.lazyAssert
import kotlin.system.measureNanoTime

abstract class AbstractRccProgramEncoder protected constructor(
  program: TokenizedProgram,
  profiler: AbstractQueryCacheProfiler,
  private val enableCompression: Boolean,
) : AbstractTokenizedProgramEncoder<RccProgramEncoding>(
  program,
  profiler,
  supportsRccReEncoding = true,
) {

  override fun encode(program: TokenizedProgram): RccProgramEncoding? {
    var optionalEncoding: RccProgramEncoding?
    val nanoDuration = measureNanoTime {
      val tokens = program.tokens
      val tokenCount = tokens.size
      optionalEncoding = encode(tokens.iterator(), tokenCount)
    }
    profiler.afterEncodeProgram(baseProgram.tokens, program, nanoDuration)
    lazyAssert { optionalEncoding == null || assertEncodingIsCorrect(program, optionalEncoding!!) }
    return optionalEncoding
  }

  protected fun encode(
    tokenIterator: Iterator<PersesTokenFactory.PersesToken>,
    tokenCount: Int,
  ): RccProgramEncoding? {
    val interval = encodeUncompressed(tokenIterator, tokenCount) ?: return null
    lazyAssert { interval.size % 2 == 0 }
    return if (enableCompression) {
      RccProgramEncoding.createCompressedEncoding(
        baseProgram,
        interval,
        tokenCount,
      )
    } else {
      RccProgramEncoding.createIntervalEncoding(
        baseProgram,
        interval,
        tokenCount,
      )
    }
  }

  override fun reEncode(
    previousEncoding: RccProgramEncoding,
  ): RccProgramEncoding? {
    return encode(previousEncoding.tokenIterator(), previousEncoding.tokenCount)
  }

  protected abstract fun encodeUncompressed(
    tokenIterator: Iterator<PersesTokenFactory.PersesToken>,
    tokenCount: Int,
  ): IntArrayList?

  companion object {
    private fun assertEncodingIsCorrect(
      program: TokenizedProgram,
      encoding: RccProgramEncoding,
    ): Boolean {
      val restored = encoding.restoreProgram()
      val origList = program.tokens
      val afterList = restored.tokens
      check(origList.size == afterList.size) {
        """
        | origList  size = ${origList.size}
        | afterList size = ${afterList.size}
        """.trimMargin()
      }
      val size = restored.tokenCount()
      for (i in 0 until size) {
        check(origList[i].persesLexemeId == afterList[i].persesLexemeId)
      }
      return true
    }
  }
}
