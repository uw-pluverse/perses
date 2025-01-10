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
package org.perses.fuzzer

import org.perses.fuzzer.languagemodel.AbstractLanguageModel
import kotlin.math.log2

class MutationFrequencyController(
  private val languageModel: AbstractLanguageModel,
  private val numOfTreeLevelMutationPerSeed: Int = 3,
  private val minNumOfTokenLevelMutationPerSeed: Int = 1,
  private val maxNumOfTokenLevelMutationPerSeed: Int = 9,
) {

  private var maxScore = Double.MIN_VALUE
  private var minScore = Double.MAX_VALUE

  fun computeTreeLevelMutationTimes(
    @Suppress("UNUSED_PARAMETER") fuzzer: SparTreeFuzzer,
  ): Int = numOfTreeLevelMutationPerSeed

  fun computeTokenLevelMutationTimes(fuzzer: SparTreeFuzzer): Int {
    val score = calculateScore(fuzzer)
    if (score > maxScore) {
      maxScore = score
    }
    if (score < minScore) {
      minScore = score
    }
    return if (maxScore < minScore) {
      (minNumOfTokenLevelMutationPerSeed + maxNumOfTokenLevelMutationPerSeed) / 2
    } else {
      (maxNumOfTokenLevelMutationPerSeed - minNumOfTokenLevelMutationPerSeed) *
        ((score - minScore) / (maxScore - minScore)).toInt() + minNumOfTokenLevelMutationPerSeed
    }
  }

  private fun calculateScore(fuzzer: SparTreeFuzzer): Double {
    return log2(languageModel.getRarenessOfMostRareFeature(fuzzer.featureOfTheSparTree!!))
  }
}
