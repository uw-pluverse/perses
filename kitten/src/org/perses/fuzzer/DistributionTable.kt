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

import com.google.common.annotations.VisibleForTesting
import com.google.common.collect.ImmutableList
import java.lang.RuntimeException
import java.util.Random

class DistributionTable<T>(val entries: ImmutableList<Entry<T>>) {

  val totalWeight = entries
    .asSequence()
    .map { it.weight }
    .sum()

  fun sample(random: Random): T {
    val probability = random.nextInt(totalWeight) + 1
    return selectEntry(probability)
  }

  @VisibleForTesting
  fun selectEntry(probability: Int): T {
    require(probability <= totalWeight)
    require(probability > 0)
    var mutableProbability = probability
    for (entry in entries) {
      if (mutableProbability <= entry.weight) {
        return entry.value
      } else {
        mutableProbability -= entry.weight
      }
    }
    throw RuntimeException("Unreachable: $mutableProbability, $totalWeight")
  }

  data class Entry<T>(
    val weight: Int,
    val value: T,
  ) {
    init {
      require(weight > 0) { "weight has to be positive $weight" }
    }
  }

  init {
    require(entries.isNotEmpty())
    require(totalWeight > 0)
  }
}
