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
import it.unimi.dsi.fastutil.ints.IntArrayList
import org.perses.program.PersesTokenFactory.PersesToken
import org.perses.program.TokenizedProgram
import org.perses.util.Util.lazyAssert

class LinearScanFormatSensitiveEncoder(
  baseProgram: TokenizedProgram,
  profiler: AbstractQueryCacheProfiler,
  enableCompression: Boolean,
) : AbstractLinearScanEncoder(baseProgram, profiler, enableCompression) {

  private var lineStartIndices = LogicalSizedArray.createWithSize(baseProgram.tokenCount())

  init {
    fillLineStartIndexArray(baseProgram.tokens, lineStartIndices)
  }

  override fun updateEncoderMore(encoderBaseProgram: TokenizedProgram) {
    super.updateEncoderMore(encoderBaseProgram)
    lineStartIndices = shrinkLogicalArrayIfNecessary(
      lineStartIndices,
      encoderBaseProgram,
      refreshThreshold,
    )
    fillLineStartIndexArray(encoderBaseProgram.tokens, lineStartIndices)
    lazyAssert { encoderBaseProgram.tokenCount() >= lineStartIndices.logicalSize }
  }

  override fun encodeUncompressed(
    tokenIterator: Iterator<PersesToken>,
    tokenCount: Int,
  ): IntArrayList? {
    var currentValueHolder: PersesToken? = null
    val tokenCursor = IteratorCursor(tokenIterator)
    val intervals = IntArrayList()
    val origTokenCount = persesLexemeIdArray.logicalSize
    val lineCount = lineStartIndices.logicalSize
    val persesLexemeIdInOrigin = persesLexemeIdArray
    val persesLineStartInOrigin = lineStartIndices
    lazyAssert { persesLexemeIdArray.maxLogicalSize >= baseProgram.tokens.size }
    lazyAssert { persesLexemeIdArray.logicalSize == baseProgram.tokens.size }
    tokenCursor.move { currentValueHolder = it }
    var currentLineInBase = 0
    val variantLine = IntArrayList()
    val tempEncoding = IntArrayList()
    while (tokenCursor.has(currentValueHolder) && currentLineInBase < lineCount) {
      // get a full variant line.
      val lineNumber = tokenCursor.get(currentValueHolder).position.line
      do {
        variantLine.add(tokenCursor.get(currentValueHolder).persesLexemeId)
        tokenCursor.move { currentValueHolder = it }
      } while (tokenCursor.has(currentValueHolder) && lineNumber == tokenCursor.get(
          currentValueHolder,
        ).position.line
      )
      val variantLineCount = variantLine.size

      // search for the applicable line in baseProgram.
      for (i in currentLineInBase until lineCount) {
        var baseTokenPointer = persesLineStartInOrigin[i]
        var variantTokenPointer = 0
        val lineStopExclusive =
          if (i + 1 < lineCount) persesLineStartInOrigin[i + 1] else origTokenCount
        if (lineStopExclusive - baseTokenPointer + 1 < variantLineCount) {
          ++currentLineInBase
          continue
        } // skip checking due to line too short.
        tempEncoding.clear()
        while (baseTokenPointer < lineStopExclusive && variantTokenPointer < variantLineCount) {
          baseTokenPointer = searchForLexemeId(
            baseTokenPointer,
            lineStopExclusive,
            variantLine.getInt(variantTokenPointer),
            persesLexemeIdInOrigin,
          )
          if (baseTokenPointer == NOT_FOUND) {
            ++currentLineInBase
            break
          } // no encoding with i-th baseProgram line; try next line.
          tempEncoding.add(baseTokenPointer)
          do {
            ++variantTokenPointer
            ++baseTokenPointer
          } while (baseTokenPointer < lineStopExclusive &&
            variantTokenPointer < variantLineCount &&
            (persesLexemeIdInOrigin[baseTokenPointer] == variantLine.getInt(variantTokenPointer))
          )
          if (baseTokenPointer >= lineStopExclusive && variantTokenPointer < variantLineCount) {
            ++currentLineInBase
            break
          } // no encoding with i-th baseProgram line.
          tempEncoding.add(baseTokenPointer)
        }
        if (variantTokenPointer >= variantLineCount) {
          if (!intervals.isEmpty && intervals.topInt() == tempEncoding.getInt(0)) {
            // case1: remove repeated index then add
            intervals.popInt()
            intervals.addAll(tempEncoding.subList(1, tempEncoding.size))
          } else {
            // case2: add directly
            intervals.addAll(tempEncoding)
          }
          currentLineInBase = i + 1
          variantLine.clear()
          break // variant line encoded successfully.
        }
      }
    }
    return if (!variantLine.isEmpty || tokenCursor.has(currentValueHolder)) {
      // !variantLine.isEmpty()  ->  current variant line cannot be encoded
      // tokenCursor.has()      ->  variant has more lines than the base
      null // encoding not applicable; entry evicted.
    } else {
      intervals
    }
  }

  companion object {
    private fun fillLineStartIndexArray(
      tokens: ImmutableList<PersesToken>,
      lineStartIndexArray: LogicalSizedArray,
    ) {
      val tokenCount = tokens.size
      lazyAssert { lineStartIndexArray.maxLogicalSize >= tokenCount }
      // temporarily increase the size of the logical array.
      lineStartIndexArray.logicalSize = lineStartIndexArray.maxLogicalSize
      var currentLine = 0
      var index = 0
      for (i in 0 until tokenCount) {
        val tokenLine = tokens[i].position.line
        if (currentLine != tokenLine) {
          lineStartIndexArray[index++] = i
          currentLine = tokenLine
        }
      }
      lazyAssert { index <= lineStartIndexArray.logicalSize }
      lineStartIndexArray.logicalSize = index
    }
  }
}
