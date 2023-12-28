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

import com.google.common.annotations.VisibleForTesting
import com.google.common.collect.ImmutableList
import it.unimi.dsi.fastutil.ints.IntArrayList
import org.perses.program.PersesTokenFactory.PersesToken
import org.perses.program.TokenizedProgram
import org.perses.reduction.cache.IntervalArrayExpander.expand

abstract class CompactProgramEncoding private constructor(
  private val baseProgram: TokenizedProgram,
  protected val encoding: IntArray,
  tokenCount: Int,
) : AbstractProgramEncoding<CompactProgramEncoding>(encoding.contentHashCode(), tokenCount) {

  fun encodingSize(): Int {
    return encoding.size
  }

  override fun extraEquals(other: CompactProgramEncoding): Boolean {
    return encoding.contentEquals(other.encoding)
  }

  @VisibleForTesting
  fun restoreProgram(): TokenizedProgram {
    val expectedTokenCount = tokenCount
    val builder =
      if (expectedTokenCount <= 0) {
        ImmutableList.builder()
      } else {
        ImmutableList.builderWithExpectedSize<PersesToken>(
          expectedTokenCount,
        )
      }
    val iter = tokenIterator()
    while (iter.hasNext()) {
      val value = iter.next()
      builder.add(value)
    }
    return TokenizedProgram(builder.build(), baseProgram.factory)
  }

  fun tokenIterator(): Iterator<PersesToken> {
    val intervals: IntArray = intervalsFromEncoding
    return expand(intervals, baseProgram.tokens)
  }

  abstract val intervalsFromEncoding: IntArray

  companion object {
    @JvmStatic
    @VisibleForTesting
    fun createCompressedEncoding(
      baseProgram: TokenizedProgram,
      intervals: IntArrayList,
      tokenCount: Int,
    ): CompactProgramEncoding {
      check(intervals.size % 2 == 0)
      return object : CompactProgramEncoding(
        baseProgram,
        COMPRESSOR.compress(intervals),
        tokenCount,
      ) {
        override val intervalsFromEncoding: IntArray
          get() = COMPRESSOR.uncompress(encoding)
      }
    }

    @JvmStatic
    fun createIntervalEncoding(
      baseProgram: TokenizedProgram,
      intervals: IntArrayList,
      tokenCount: Int,
    ): CompactProgramEncoding {
      check(intervals.size % 2 == 0)
      return object : CompactProgramEncoding(baseProgram, intervals.toIntArray(), tokenCount) {
        override val intervalsFromEncoding: IntArray
          get() = encoding
      }
    }

    private val COMPRESSOR = CompressorForIntArrayList()
  }
}
