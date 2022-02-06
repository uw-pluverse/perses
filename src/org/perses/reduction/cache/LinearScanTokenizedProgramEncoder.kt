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
import org.perses.program.PersesTokenFactory.PersesToken
import org.perses.program.TokenizedProgram

class LinearScanTokenizedProgramEncoder(
  baseProgram: TokenizedProgram,
  profiler: AbstractQueryCacheProfiler,
  enableCompression: Boolean
) : AbstractLinearScanEncoder(baseProgram, profiler, enableCompression) {

  override fun encodeUncompressed(
    tokenCursor: IteratorCursor<PersesToken>,
    tokenCount: Int
  ): IntArrayList? {
    val intervals = IntArrayList(DEFAULT_INTERVAL_CAPACITY)
    val origTokenCount = persesLexemeIdArray.logicalSize
    val persesLexemeIdInOrigin = persesLexemeIdArray
    assert(persesLexemeIdArray.maxLogicalSize >= baseProgram.tokens.size)
    assert(persesLexemeIdArray.logicalSize == baseProgram.tokens.size)
    tokenCursor.move()
    var origIndex = 0
    while (tokenCursor.has()) {
      val currentPersesLexemeId = tokenCursor.get()!!.persesLexemeId
      // Search for start of the internal.
      origIndex = searchForLexemeId(
        origIndex, origTokenCount, currentPersesLexemeId, persesLexemeIdInOrigin
      )
      if (origIndex == NOT_FOUND) {
        return null
      }
      assert(currentPersesLexemeId == persesLexemeIdInOrigin[origIndex])
      intervals.add(origIndex)
      // Search for the end of the interval.
      do {
        tokenCursor.move()
        ++origIndex
      } while (tokenCursor.has() &&
        origIndex < origTokenCount &&
        tokenCursor.get()!!.persesLexemeId == persesLexemeIdInOrigin[origIndex]
      )
      if (origIndex == origTokenCount && tokenCursor.has()) {
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
    private const val DEFAULT_INTERVAL_CAPACITY = 8
  }
}
