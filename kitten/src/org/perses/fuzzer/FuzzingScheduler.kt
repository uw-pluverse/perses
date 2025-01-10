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
import org.perses.spartree.SparTree
import java.io.File

class FuzzingScheduler(
  val model: AbstractLanguageModel,
  val fuzzerInstances: SparTreeFuzzerQueue,
  private val maxSeedPoolSize: Int,
  private val mutationFrequencyController: MutationFrequencyController,
  private val interestingFolder: File,
) {

  var numberOfObsoletedInstances: Int = 0
    private set

  private var numberOfAddedInstances: Int = 0

  init {
    fuzzerInstances.content.forEach {
      updateOnNewSeed(it)
    }
  }

  fun updateOnNewSeed(treeFuzzer: SparTreeFuzzer) {
    assert(treeFuzzer.featureOfTheSparTree == null)
    treeFuzzer.featureOfTheSparTree = model.updateModelAndGetFeatureOfSparTree(treeFuzzer.sparTree)
  }

  fun next(): SparTreeFuzzer? {
    val nextInstance = fuzzerInstances.next()
    if (isObsoleted(nextInstance)) {
      fuzzerInstances.remove(nextInstance)
      return null
    }
    return nextInstance
  }

  @Synchronized fun update(tree: SparTree, program: File) {
    val featureOfSparTree = model.updateModelAndGetFeatureOfSparTree(tree)
    if (model.allowToEnableGuidance && fuzzerInstances.getSize() < maxSeedPoolSize) {
      if (model.isRare(featureOfSparTree)) {
        val newTreeFuzzer = SparTreeFuzzer
          .fromSparTree(model.parserFacade, program, tree)
        newTreeFuzzer.featureOfTheSparTree = featureOfSparTree
        fuzzerInstances.add(newTreeFuzzer)
        val interestingMutant = File(
          interestingFolder.path,
          "interesting_${numberOfAddedInstances++}." + program.extension,
        )
        newTreeFuzzer.moveSeedFile(interestingMutant)
      }
    }
  }

  fun getTokenLevelMutationTimes(treeFuzzer: SparTreeFuzzer): Int =
    mutationFrequencyController.computeTokenLevelMutationTimes(treeFuzzer)

  fun getTreeLevelMutationTimes(treeFuzzer: SparTreeFuzzer): Int =
    mutationFrequencyController.computeTreeLevelMutationTimes(treeFuzzer)

  private fun isObsoleted(treeFuzzer: SparTreeFuzzer): Boolean {
    return if (!treeFuzzer.isInitial &&
      model.isVeryCommon(treeFuzzer.featureOfTheSparTree!!)
    ) {
      numberOfObsoletedInstances++
      true
    } else {
      false
    }
  }
}
