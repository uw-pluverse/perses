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
import org.perses.program.PersesTokenFactory.PersesToken
import org.perses.program.TokenizedProgram
import org.perses.reduction.cache.AbstractRccLinearScanEncoder.Companion.NOT_FOUND
import org.perses.util.Util.lazyAssert
import org.perses.util.Util.nextOrNull

class RccMemoryLitProgramEncoder internal constructor(
  baseProgram: TokenizedProgram,
  profiler: AbstractQueryCacheProfiler,
  enableCompression: Boolean,
) : AbstractRccProgramEncoder(baseProgram, profiler, enableCompression) {

  init {
    profiler.onCreatingEncoder(baseProgram.tokens, nanoDuration = 0)
  }

  private fun searchForLexemeId(
    startIndexInclusive: Int,
    stopIndexExclusive: Int,
    targetLexemeId: Int,
  ): Int {
    val tokens = baseProgram.tokens
    for (i in startIndexInclusive until stopIndexExclusive) {
      if (tokens[i].persesLexemeId == targetLexemeId) {
        return i
      }
    }
    return NOT_FOUND
  }

  override fun encodeUncompressed(
    tokenIterator: Iterator<PersesToken>,
    tokenCount: Int,
  ): IntArrayList? {
    var currentValueHolder: PersesToken?
    val intervals = IntArrayList(RccTokenizedProgramEncoder.DEFAULT_INTERVAL_CAPACITY)
    val baseTokens = baseProgram.tokens
    val origTokenCount = baseTokens.size
    currentValueHolder = tokenIterator.nextOrNull()
    var baseTokenIndex = 0
    while (currentValueHolder != null) {
      val currentPersesLexemeId = currentValueHolder.persesLexemeId
      // Search for start of the internal.
      baseTokenIndex = searchForLexemeId(
        baseTokenIndex,
        origTokenCount,
        currentPersesLexemeId,
      )
      if (baseTokenIndex == NOT_FOUND) {
        return null
      }
      lazyAssert { currentPersesLexemeId == baseTokens[baseTokenIndex].persesLexemeId }
      intervals.add(baseTokenIndex)
      // Search for the end of the interval.
      do {
        currentValueHolder = tokenIterator.nextOrNull()
        ++baseTokenIndex
      } while (currentValueHolder != null &&
        baseTokenIndex < origTokenCount &&
        currentValueHolder.persesLexemeId == baseTokens[baseTokenIndex].persesLexemeId
      )
      if (baseTokenIndex == origTokenCount && currentValueHolder != null) {
        return null
      }
      intervals.add(baseTokenIndex)
    }
    return intervals
  }

  override fun updateEncoderMore(encoderBaseProgram: TokenizedProgram) {
  }
}
