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

import com.google.common.collect.ImmutableList
import it.unimi.dsi.fastutil.ints.IntArrayList
import org.perses.program.PersesTokenFactory.PersesToken
import org.perses.program.TokenizedProgram
import org.perses.util.Util
import org.perses.util.Util.lazyAssert
import org.perses.util.Util.nextOrNull

class RccFormatSensitiveEncoder(
  baseProgram: TokenizedProgram,
  profiler: AbstractQueryCacheProfiler,
  enableCompression: Boolean,
) : AbstractRccLinearScanEncoder(baseProgram, profiler, enableCompression) {

  private var indicesOfTokensThatStartLines =
    LogicalSizedArray.createWithSize(baseProgram.tokenCount())

  init {
    fillLineStartIndexArray(baseProgram.tokens, indicesOfTokensThatStartLines)
  }

  override fun updateEncoderMore(encoderBaseProgram: TokenizedProgram) {
    super.updateEncoderMore(encoderBaseProgram)
    indicesOfTokensThatStartLines = shrinkLogicalArrayIfNecessary(
      indicesOfTokensThatStartLines,
      encoderBaseProgram,
      refreshThreshold,
    )
    fillLineStartIndexArray(encoderBaseProgram.tokens, indicesOfTokensThatStartLines)
    lazyAssert { encoderBaseProgram.tokenCount() >= indicesOfTokensThatStartLines.logicalSize }
  }

  override fun encodeUncompressed(
    tokenIterator: Iterator<PersesToken>,
    tokenCount: Int,
  ): IntArrayList? {
    val intervalsResult = IntArrayList(20) // specify the initial capacity

    val persesLexemeIdInBaseProgram = persesLexemeIdArray
    val tokenCountInBase = persesLexemeIdInBaseProgram.logicalSize
    val persesLineStartInBase = indicesOfTokensThatStartLines
    val totalLineCountInBase = persesLineStartInBase.logicalSize

    lazyAssert { persesLexemeIdArray.maxLogicalSize >= baseProgram.tokens.size }
    lazyAssert { persesLexemeIdArray.logicalSize == baseProgram.tokens.size }
    var currentVariantToken = tokenIterator.nextOrNull()
    var currentLineNoInBase = 0
    val lineOfTokensInVariant = IntArrayList(100)
    val tempEncodingForVariantLine = IntArrayList(20)
    var isLastVariantLineEncodedSuccesfully = true
    tokenLoop@ while (currentVariantToken != null && currentLineNoInBase < totalLineCountInBase) {
      // get a full variant line.
      currentVariantToken =
        getLineOfTokensInVariant(currentVariantToken, tokenIterator, result = lineOfTokensInVariant)
      // search for the applicable line in baseProgram.
      val tokenCountInVariantLine = lineOfTokensInVariant.size
      lazyAssert { tokenCountInVariantLine > 0 }
      isLastVariantLineEncodedSuccesfully = false
      lineLoop@ for (lineNo in currentLineNoInBase until totalLineCountInBase) {
        val indexOfBaseTokenThatEndsTheLineExclusive =
          computeIndexOfBaseTokenThatEndsTheLineExclusive(
            lineNo,
            totalLineCountInBase,
            persesLineStartInBase,
            tokenCountInBase,
          )
        var indexOfBaseToken = persesLineStartInBase[lineNo]
        if (isLineInBaseShorterThanLineInVariant(
            indexOfBaseTokenThatStartsTheLine = indexOfBaseToken,
            indexOfBaseTokenThatEndsTheLineExclusive,
            tokenCountInVariantLine,
          )
        ) {
          ++currentLineNoInBase
          continue@lineLoop // skip checking because the line in the base program is too short.
        }
        tempEncodingForVariantLine.clear()
        var indexOfVariantToken = 0

        encodingAttemptLoop@ while (indexOfBaseToken < indexOfBaseTokenThatEndsTheLineExclusive &&
          indexOfVariantToken < tokenCountInVariantLine
        ) {
          indexOfBaseToken = searchForLexemeId(
            startIndexInclusive = indexOfBaseToken,
            stopIndexExclusive = indexOfBaseTokenThatEndsTheLineExclusive,
            targetLexemeId = lineOfTokensInVariant.getInt(indexOfVariantToken),
            persesLexemeIdInBaseProgram,
          )
          if (indexOfBaseToken == NOT_FOUND) {
            ++currentLineNoInBase
            continue@lineLoop
          } // no encoding with lineNo-th baseProgram line; try next line.
          tempEncodingForVariantLine.add(indexOfBaseToken)
          do {
            ++indexOfVariantToken
            ++indexOfBaseToken
          } while (
            indexOfBaseToken < indexOfBaseTokenThatEndsTheLineExclusive &&
            indexOfVariantToken < tokenCountInVariantLine &&
            persesLexemeIdInBaseProgram[indexOfBaseToken] ==
            lineOfTokensInVariant.getInt(indexOfVariantToken)
          )
          if (
            indexOfBaseToken >= indexOfBaseTokenThatEndsTheLineExclusive &&
            indexOfVariantToken < tokenCountInVariantLine
          ) {
            // no encoding with lineNo-th baseProgram line.
            ++currentLineNoInBase
            continue@lineLoop
          }
          tempEncodingForVariantLine.add(indexOfBaseToken)
        } // end of encodingAttemptLoop

        if (indexOfVariantToken >= tokenCountInVariantLine) {
          // The variant line has been exhausted, and we have found an encoding for it.
          if (!intervalsResult.isEmpty &&
            intervalsResult.topInt() == tempEncodingForVariantLine.getInt(0)
          ) {
            // case1: remove repeated index then add
            intervalsResult.popInt()
            val tempEncodingSize = tempEncodingForVariantLine.size
            intervalsResult.ensureCapacity(intervalsResult.size + tempEncodingSize)
            for (j in 1 until tempEncodingSize) {
              intervalsResult.add(tempEncodingForVariantLine.getInt(j))
            }
          } else {
            // case2: add directly
            intervalsResult.addAll(tempEncodingForVariantLine)
          }
          currentLineNoInBase = lineNo + 1
          lineOfTokensInVariant.clear()
          isLastVariantLineEncodedSuccesfully = true
          break@lineLoop // variant line encoded successfully.
        }
      } // end of lineLoop@
    } // end of tokenLoop@
    return if (!isLastVariantLineEncodedSuccesfully || currentVariantToken != null) {
      // !variantLine.isEmpty()  ->  current variant line cannot be encoded
      // tokenCursor.has()      ->  variant has more lines than the base
      null // encoding not applicable; entry evicted.
    } else {
      intervalsResult
    }
  }

  private fun computeIndexOfBaseTokenThatEndsTheLineExclusive(
    lineNo: Int,
    totalLineCountInBase: Int,
    persesLineStartInBase: LogicalSizedArray,
    tokenCountInBase: Int,
  ) = if (lineNo + 1 < totalLineCountInBase) {
    persesLineStartInBase[lineNo + 1]
  } else {
    tokenCountInBase
  }

  @Suppress("NOTHING_TO_INLINE")
  private inline fun getLineOfTokensInVariant(
    firstTokenInVariantLine: PersesToken,
    tokenCursor: Iterator<PersesToken>,
    result: IntArrayList,
  ): PersesToken? {
    lazyAssert { result.isEmpty }
    val lineNumberOfCurrentTokenInVariant = firstTokenInVariantLine.position.line
    var currentVariantToken: PersesToken? = firstTokenInVariantLine
    do {
      result.add(currentVariantToken!!.persesLexemeId)
      currentVariantToken = tokenCursor.nextOrNull()
    } while (currentVariantToken != null &&
      lineNumberOfCurrentTokenInVariant == currentVariantToken.position.line
    )
    return currentVariantToken
  }

  companion object {

    @Suppress("NOTHING_TO_INLINE")
    inline fun isLineInBaseShorterThanLineInVariant(
      indexOfBaseTokenThatStartsTheLine: Int,
      indexOfBaseTokenThatEndsTheLine: Int,
      tokenCountInVariantLine: Int,
    ): Boolean {
      return Util.countElementsInList(
        endIndexExclusive = indexOfBaseTokenThatEndsTheLine,
        startIndexInclusive = indexOfBaseTokenThatStartsTheLine,
      ) < tokenCountInVariantLine
    }

    private fun fillLineStartIndexArray(
      tokens: ImmutableList<PersesToken>,
      lineStartIndexArray: LogicalSizedArray,
    ) {
      val tokenCount = tokens.size
      lazyAssert { lineStartIndexArray.maxLogicalSize >= tokenCount }
      // temporarily increase the size of the logical array.
      lineStartIndexArray.logicalSize = lineStartIndexArray.maxLogicalSize
      var currentLine = 0
      var lengthOfLineStartIndexArray = 0
      for (i in 0 until tokenCount) {
        val lineNoOfToken = tokens[i].position.line
        if (currentLine != lineNoOfToken) {
          lineStartIndexArray[lengthOfLineStartIndexArray++] = i
          currentLine = lineNoOfToken
        }
      }
      lazyAssert { lengthOfLineStartIndexArray <= lineStartIndexArray.logicalSize }
      lineStartIndexArray.logicalSize = lengthOfLineStartIndexArray
    }
  }
}
