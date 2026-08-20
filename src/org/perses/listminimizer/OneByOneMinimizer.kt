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

import com.google.common.collect.ImmutableList

// TODO(cnsun): needs testing.
class OneByOneMinimizer<T : Any, PropertyPayload>(
  arguments: ListMinimizerArguments<T, PropertyPayload>,
) : AbstractListMinimizer<T, PropertyPayload>(arguments) {
  private val extraArguments =
    arguments.oneByOneMinimizerArguments
      ?: OneByOneMinimizerArguments()

  override fun reduceNonEmptyInput() {
    var changed: Boolean
    do {
      changed = false
      val elements: List<ElementWrapper<T>> =
        if (extraArguments.deleteFromFrontToBack) {
          best
        } else {
          best.asReversed()
        }
      elements.forEach { element ->
        val configuration =
          Candidate.DeletionsFromOriginal(
            original = best,
            deleted_ = ImmutableList.of(element),
          )
        val testResult = testProperty(configuration)
        if (testResult !is ListMinimizerPropertyTestResult.Completed) {
          return@forEach
        }
        if (testResult.result.isInteresting) {
          configuration.deletedWrappers.forEach { it.markAsDeleted() }
          updateBest(configuration.candidateWrappers, payload = testResult.payload)
          changed = true
        }
      }
    } while (changed && extraArguments.repeatForFixpoint)
  }
}
