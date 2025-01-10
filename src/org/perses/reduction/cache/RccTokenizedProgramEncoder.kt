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
import org.perses.util.Util.lazyAssert
import org.perses.util.Util.nextOrNull

class RccTokenizedProgramEncoder(
  baseProgram: TokenizedProgram,
  profiler: AbstractQueryCacheProfiler,
  enableCompression: Boolean,
) : AbstractRccLinearScanEncoder(baseProgram, profiler, enableCompression) {

  public override fun encodeUncompressed(
    tokenIterator: Iterator<PersesToken>,
    tokenCount: Int,
  ): IntArrayList? {
    val intervals = IntArrayList(DEFAULT_INTERVAL_CAPACITY)
    val origTokenCount = persesLexemeIdArray.logicalSize
    val persesLexemeIdInOrigin = persesLexemeIdArray
    lazyAssert { persesLexemeIdArray.maxLogicalSize >= baseProgram.tokens.size }
    lazyAssert { persesLexemeIdArray.logicalSize == baseProgram.tokens.size }

    var currentTokenHolder: PersesToken?
    currentTokenHolder = tokenIterator.nextOrNull()
    var origIndex = 0
    while (currentTokenHolder != null) {
      val currentPersesLexemeId = currentTokenHolder.persesLexemeId
      // Search for start of the internal.
      origIndex = searchForLexemeId(
        origIndex,
        origTokenCount,
        currentPersesLexemeId,
        persesLexemeIdInOrigin,
      )
      if (origIndex == NOT_FOUND) {
        return null
      }
      lazyAssert { currentPersesLexemeId == persesLexemeIdInOrigin[origIndex] }
      intervals.add(origIndex)
      // Search for the end of the interval.
      do {
        currentTokenHolder = tokenIterator.nextOrNull()
        ++origIndex
      } while (currentTokenHolder != null &&
        origIndex < origTokenCount &&
        currentTokenHolder.persesLexemeId == persesLexemeIdInOrigin[origIndex]
      )
      if (origIndex == origTokenCount && currentTokenHolder != null) {
        return null
      }
      intervals.add(origIndex)
    }
    return intervals
  }

  companion object {
    /**
     * I believe ideally most of the encodings only have 4 elements if RCC refreshes on every new best
     * program.
     *
     *
     * Pre-allocating a large array is costly.
     */
    const val DEFAULT_INTERVAL_CAPACITY = 8
  }
}
