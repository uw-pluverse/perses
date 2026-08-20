/*
 * Copyright (C) 2018-2026 University of Waterloo.
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
package org.perses.listminimizer.localexhaust

import com.google.common.collect.Collections2
import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableListMultimap
import org.perses.util.toImmutableList

@JvmInline
value class NumOfDeletes(
  val value: Int,
)

fun Int.asNumOfDeletes(): NumOfDeletes = NumOfDeletes(this)

class UniformLengthDeletionPatternSet(
  val patternLength: Int,
) {
  init {
    require(patternLength >= 0) { "Pattern length cannot be negative." }
  }

  val numOfDeletes2PatternMultiMap = createUniformLengthDeletionPatternSet(patternLength)

  val minNumOfDeletes = numOfDeletes2PatternMultiMap.keySet().minBy { it.value }
  val maxNumOfDeletes = numOfDeletes2PatternMultiMap.keySet().maxBy { it.value }
  val totalPatternCount = numOfDeletes2PatternMultiMap.values().size

  val interestingPatternsInDescendingOfNumOfDeletes =
    (patternLength downTo 2)
      .asSequence()
      .flatMap { getPatternsWithGivenNumOfDeletes(it) }
      .toImmutableList()

  fun getPatternsWithGivenNumOfDeletes(numOfDeletes: Int) =
    numOfDeletes2PatternMultiMap.get(numOfDeletes.asNumOfDeletes())

  companion object {
    internal fun createUniformLengthDeletionPatternSet(
      totalNumberOfOperations: Int,
    ): ImmutableListMultimap<NumOfDeletes, ElementEditPattern> {
      val result = ImmutableListMultimap.builder<NumOfDeletes, ElementEditPattern>()
      for (numOfDeletes in 0..totalNumberOfOperations) {
        result.putAll(
          numOfDeletes.asNumOfDeletes(),
          createPatternsWithGivenNumOfDeletes(
            totalNumberOfOperations,
            numOfDeletes,
          ),
        )
      }
      return result.build()
    }

    internal fun createPatternsWithGivenNumOfDeletes(
      totalNumberOfOperations: Int,
      numOfDeletes: Int,
    ): ImmutableList<ElementEditPattern> {
      val seedPattern =
        createOperationListWithGivenNumOfDeletes(
          totalNumberOfOperations,
          numOfDeletes,
        )
      return Collections2
        .orderedPermutations(seedPattern)
        .asSequence()
        .map { ElementEditPattern(it.toImmutableList()) }
        .toImmutableList()
    }

    fun createOperationListWithGivenNumOfDeletes(
      totalNumberOfOperations: Int,
      numOfDeletes: Int,
    ): ImmutableList<EnumOperation> {
      check(totalNumberOfOperations >= numOfDeletes)
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
      return result.build().also { check(it.size == totalNumberOfOperations) }
    }
  }
}
