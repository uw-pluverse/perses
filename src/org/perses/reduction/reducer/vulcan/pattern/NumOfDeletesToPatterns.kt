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
package org.perses.reduction.reducer.vulcan.pattern

import com.google.common.collect.Collections2
import com.google.common.collect.ImmutableList
import org.perses.util.toImmutableList

data class NumOfDeletesToPatterns(
  private val patterns: ImmutableList<ImmutableList<TokenEditPattern>>,
) {
  init {
    require(patterns.isNotEmpty())
    patterns.forEachIndexed { numOfDeletes, patterns ->
      patterns.forEach { pattern ->
        require(numOfDeletes == pattern.numOfDeletes) {
          "$numOfDeletes, ${pattern.numOfDeletes}"
        }
      }
      assert(patterns.distinct().count() == patterns.size)
    }
    patterns.asSequence()
      .flatMap { it.asSequence() }
      .zipWithNext { a, b -> require(a.patternLength == b.patternLength) }
  }

  val patternLength = patterns.first().first().patternLength
  val patternCount = patterns.sumOf { it.size }

  val patternsInUseDescending = ImmutableList.builder<TokenEditPattern>().apply {
    for (numOfDeletes in patterns.size - 1 downTo 2) {
      addAll(getPatternsWithGivenNumOfDeletes(numOfDeletes))
    }
  }.build()

  fun getPatternsWithGivenNumOfDeletes(numOfDeletes: Int): ImmutableList<TokenEditPattern> {
    return patterns[numOfDeletes].also {
      assert(it.first().numOfDeletes == numOfDeletes)
    }
  }

  companion object {

    fun createDeletionPatterns(totalNumberOfOperations: Int): NumOfDeletesToPatterns {
      val result =
        ImmutableList.builderWithExpectedSize<
          ImmutableList<TokenEditPattern>,
          >(totalNumberOfOperations + 1)
      for (numOfDeletes in 0..totalNumberOfOperations) {
        result.add(
          createPatternsWithGivenNumOfDeletes(
            totalNumberOfOperations,
            numOfDeletes,
          ),
        )
      }
      return NumOfDeletesToPatterns(result.build())
    }

    internal fun createPatternsWithGivenNumOfDeletes(
      totalNumberOfOperations: Int,
      numOfDeletes: Int,
    ): ImmutableList<TokenEditPattern> {
      val seedPattern = createOperationListWithGivenNumOfDeletes(
        totalNumberOfOperations,
        numOfDeletes,
      )
      return Collections2.orderedPermutations(seedPattern)
        .asSequence()
        .map { TokenEditPattern(it.toImmutableList()) }
        .toImmutableList()
    }

    internal fun createOperationListWithGivenNumOfDeletes(
      totalNumberOfOperations: Int,
      numOfDeletes: Int,
    ): ImmutableList<EnumOperation> {
      assert(totalNumberOfOperations >= numOfDeletes)
      val result = ImmutableList.builderWithExpectedSize<EnumOperation>(totalNumberOfOperations)
      var i = 0
      while (i < numOfDeletes) {
        result.add(EnumOperation.DELETE)
        ++i
      }
      while (i < totalNumberOfOperations) {
        result.add(EnumOperation.KEEP)
        ++i
      }
      return result.build().also { assert(it.size == totalNumberOfOperations) }
    }
  }
}
