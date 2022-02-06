/*
 * Copyright (C) 2018-2022 University of Waterloo.
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

abstract class AbstractCompactProgramEncoder protected constructor(
  program: TokenizedProgram,
  profiler: AbstractQueryCacheProfiler,
  private val enableCompression: Boolean
) : AbstractTokenizedProgramEncoder<CompactProgramEncoding>(program, profiler) {

  override fun encode(program: TokenizedProgram): CompactProgramEncoding? {
    val startTime = AbstractQueryCacheProfiler.now()
    val tokens = program.tokens
    val tokenCount = tokens.size
    val optionalEncoding = encode(tokens.iterator(), tokenCount) ?: return null
    val endTime = AbstractQueryCacheProfiler.now()
    profiler.onEncodingProgram(baseProgram.tokens, program, startTime, endTime)
    assert(assertEncodingIsCorrect(program, optionalEncoding))
    return optionalEncoding
  }

  protected fun encode(
    tokenIterator: Iterator<PersesTokenFactory.PersesToken>,
    tokenCount: Int
  ): CompactProgramEncoding? {
    val interval = encodeUncompressed(IteratorCursor(tokenIterator), tokenCount) ?: return null
    assert(interval.size % 2 == 0)
    return if (enableCompression) CompactProgramEncoding.createCompressedEncoding(
      baseProgram, interval, tokenCount
    ) else CompactProgramEncoding.createIntervalEncoding(
      baseProgram, interval, tokenCount
    )
  }

  override fun reEncode(
    previousEncoding: CompactProgramEncoding
  ): CompactProgramEncoding? {
    return encode(previousEncoding.tokenIterator(), previousEncoding.tokenCount)
  }

  protected abstract fun encodeUncompressed(
    persesTokenIteratorCursor: IteratorCursor<PersesTokenFactory.PersesToken>,
    tokenCount: Int
  ): IntArrayList?

  class IteratorCursor<T> internal constructor(private val iterator: Iterator<T>) {

    private var current: T? = null

    fun has(): Boolean {
      return current != null
    }

    fun get(): T? {
      assert(current != null)
      return current
    }

    fun move() {
      current = if (iterator.hasNext()) {
        iterator.next()
      } else {
        null
      }
    }
  }

  companion object {
    private fun assertEncodingIsCorrect(
      program: TokenizedProgram,
      encoding: CompactProgramEncoding
    ): Boolean {
      val restored = encoding.restoreProgram()
      val origList = program.tokens
      val afterList = restored.tokens
      check(origList.size == afterList.size)
      val size = restored.tokenCount()
      for (i in 0 until size) {
        check(origList[i].persesLexemeId == afterList[i].persesLexemeId)
      }
      return true
    }
  }
}
