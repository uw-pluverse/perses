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
import org.perses.util.Util.lazyAssert

abstract class AbstractLinearScanEncoder protected constructor(
  baseProgram: TokenizedProgram,
  profiler: AbstractQueryCacheProfiler,
  enableCompression: Boolean,
) : AbstractCompactProgramEncoder(baseProgram, profiler, enableCompression) {

  internal var persesLexemeIdArray = LogicalSizedArray.createWithSize(baseProgram.tokenCount())
  protected val refreshThreshold = Math.max(1000, baseProgram.tokenCount() * 5 / 100)

  init {
    val startTime = AbstractQueryCacheProfiler.now()
    fillLexemeIdArray(baseProgram.tokens, persesLexemeIdArray)
    lazyAssert { persesLexemeIdArray.logicalSize == baseProgram.tokenCount() }
    val endTime = AbstractQueryCacheProfiler.now()
    profiler.onCreatingEncoder(baseProgram.tokens, startTime, endTime)
  }

  fun searchForLexemeId(
    startIndexInclusive: Int,
    stopIndexExclusive: Int,
    targetLexemeId: Int,
    persesLexemeIdInOrigin: LogicalSizedArray,
  ): Int {
    for (i in startIndexInclusive until stopIndexExclusive) {
      if (persesLexemeIdInOrigin[i] == targetLexemeId) {
        return i
      }
    }
    return NOT_FOUND
  }

  override fun updateEncoderMore(encoderBaseProgram: TokenizedProgram) {
    persesLexemeIdArray = shrinkLogicalArrayIfNecessary(
      persesLexemeIdArray,
      encoderBaseProgram,
      refreshThreshold,
    )
    fillLexemeIdArray(encoderBaseProgram.tokens, persesLexemeIdArray)
    lazyAssert { encoderBaseProgram.tokenCount() == persesLexemeIdArray.logicalSize }
  }

  companion object {
    const val NOT_FOUND = Int.MIN_VALUE

    private fun fillLexemeIdArray(
      tokens: ImmutableList<PersesTokenFactory.PersesToken>,
      persesLexemeIdArray: LogicalSizedArray,
    ) {
      val tokenCount = tokens.size
      lazyAssert { persesLexemeIdArray.maxLogicalSize >= tokenCount }
      persesLexemeIdArray.logicalSize = tokenCount
      for (i in 0 until tokenCount) {
        persesLexemeIdArray[i] = tokens[i].persesLexemeId
      }
    }

    @Suppress("NOTHING_TO_INLINE")
    @JvmStatic
    protected inline fun shrinkLogicalArrayIfNecessary(
      array: LogicalSizedArray,
      baseProgram: TokenizedProgram,
      refreshThreshold: Int,
    ): LogicalSizedArray {
      val tokenCount = baseProgram.tokenCount()
      return if (array.maxLogicalSize - tokenCount >= refreshThreshold) {
        LogicalSizedArray.createWithSize(tokenCount)
      } else {
        array.logicalSize = tokenCount
        array
      }
    }
  }
}
