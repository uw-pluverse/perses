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

import it.unimi.dsi.fastutil.ints.IntArrayList
import org.perses.program.PersesTokenFactory
import org.perses.program.TokenizedProgram
import org.perses.util.Util.lazyAssert

abstract class AbstractCompactProgramEncoder protected constructor(
  program: TokenizedProgram,
  profiler: AbstractQueryCacheProfiler,
  private val enableCompression: Boolean,
) : AbstractTokenizedProgramEncoder<CompactProgramEncoding>(program, profiler) {

  override fun encode(program: TokenizedProgram): CompactProgramEncoding? {
    val startTime = AbstractQueryCacheProfiler.now()
    val tokens = program.tokens
    val tokenCount = tokens.size
    val optionalEncoding = encode(tokens.iterator(), tokenCount) ?: return null
    val endTime = AbstractQueryCacheProfiler.now()
    profiler.onEncodingProgram(baseProgram.tokens, program, startTime, endTime)
    lazyAssert { assertEncodingIsCorrect(program, optionalEncoding) }
    return optionalEncoding
  }

  protected fun encode(
    tokenIterator: Iterator<PersesTokenFactory.PersesToken>,
    tokenCount: Int,
  ): CompactProgramEncoding? {
    val interval = encodeUncompressed(tokenIterator, tokenCount) ?: return null
    lazyAssert { interval.size % 2 == 0 }
    return if (enableCompression) {
      CompactProgramEncoding.createCompressedEncoding(
        baseProgram,
        interval,
        tokenCount,
      )
    } else {
      CompactProgramEncoding.createIntervalEncoding(
        baseProgram,
        interval,
        tokenCount,
      )
    }
  }

  override fun reEncode(
    previousEncoding: CompactProgramEncoding,
  ): CompactProgramEncoding? {
    return encode(previousEncoding.tokenIterator(), previousEncoding.tokenCount)
  }

  protected abstract fun encodeUncompressed(
    tokenIterator: Iterator<PersesTokenFactory.PersesToken>,
    tokenCount: Int,
  ): IntArrayList?

  @JvmInline
  value class IteratorCursor<T> (@PublishedApi internal val iterator: Iterator<T>) {

    @Suppress("NOTHING_TO_INLINE")
    inline fun has(currentValueHolder: T?): Boolean {
      return currentValueHolder != null
    }

    @Suppress("NOTHING_TO_INLINE")
    inline fun get(currentValueHolder: T?): T {
      lazyAssert { currentValueHolder != null }
      return currentValueHolder!!
    }

    inline fun move(currentValueHolderUpdate: (T?) -> Unit) {
      currentValueHolderUpdate(
        if (iterator.hasNext()) {
          iterator.next()
        } else {
          null
        },
      )
    }
  }

  companion object {
    private fun assertEncodingIsCorrect(
      program: TokenizedProgram,
      encoding: CompactProgramEncoding,
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
