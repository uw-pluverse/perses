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
package org.perses.listminimizer

import org.perses.reduction.CandidateOutcome
import org.perses.util.StringUtil
import kotlin.reflect.KClass

class ListMinimizerListenerAdaptor(
  private val logger: (String) -> Unit,
) : AbstractListMinimizerListener() {
  override fun startReduction(
    originalInput: List<ElementWrapper<*>>,
    listMinimizerClass: KClass<out AbstractListMinimizer<*, *>>,
    descriptionPrefix: String,
  ) {
    val algName = listMinimizerClass.simpleName
    val elements = convertElementListToCompactString(originalInput)
    logger(
      "Minimizer $algName starts. Input=$elements.",
    )
  }

  override fun endReduction(
    minimizationResult: List<ElementWrapper<*>>,
    listMinimizerClass: KClass<out AbstractListMinimizer<*, *>>,
    sizeOfOriginalInput: Int,
  ) {
    val algName = listMinimizerClass.simpleName
    val elements = convertElementListToCompactString(minimizationResult)
    val localRatio =
      StringUtil.computePercentage(
        numerator = minimizationResult.size,
        denominator = sizeOfOriginalInput,
      )
    logger("Minimizer $algName ends. Result=$elements. Local ratio: $localRatio.")
  }

  override fun onBestUpdate(newBest: List<ElementWrapper<*>>) {
    // Do nothing. This is handled by the reduction listeners.
  }

  override fun onPropertyTest(
    configuration: Candidate<*>,
    result: CandidateOutcome<*>,
    sizeOfOriginalList: Int,
    sizeOfCurrentMinimizationResult: Int,
  ) {
    val deleted = convertElementListToCompactString(configuration.deletedWrappers)
    val localReductionRate =
      StringUtil.computePercentage(
        numerator = sizeOfCurrentMinimizationResult,
        denominator = sizeOfOriginalList,
      )
    logger("Try deleting $deleted: ${result.toShortString()}. Local ratio: $localReductionRate.")
  }

  override fun log(msg: () -> String) {
    logger(msg())
  }

  override fun close() {
    // Do nothing.
  }
}
