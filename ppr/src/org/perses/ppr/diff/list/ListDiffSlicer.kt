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
package org.perses.ppr.diff.list

import com.google.common.collect.ImmutableList
import org.perses.program.PersesTokenFactory.PersesToken
import org.perses.reduction.TestScriptExecutorService
import org.perses.util.AbstractEditOperation
import org.perses.util.excludesRegion
import org.perses.util.ktInfo

class ListDiffSlicer(
  ioManagerList: ListDiffReductionIOManager,
  testScriptExecutorService: TestScriptExecutorService,
) : AbstractListDiffReducer(
  ioManagerList,
  testScriptExecutorService,
) {

  override fun reduce(state: ListDiffReductionState) {
    logger.ktInfo { "Start ${this::class}" }

    // try empty diff first
    val emptyDiff: ImmutableList<AbstractEditOperation<PersesToken>> = ImmutableList.of()
    if (testProgram(emptyDiff)) {
      state.updateBestDiff(emptyDiff)
      return
    }

    var best = state.bestDiff
    var granularity = 5
    while (granularity > 0) {
      var start = 0
      var end = start + granularity
      while (end <= best.size) {
        val candidate = best.subList(start, end)
        if (testProgram(candidate)) {
          state.updateBestDiff(candidate)
          best = state.bestDiff
          break
        }

        val candidateComplement = best.excludesRegion(start, end)
        if (testProgram(candidateComplement)) {
          state.updateBestDiff(candidateComplement)
          best = state.bestDiff
        } else {
          start += 1
          end = start + granularity
        }
      }
      granularity -= 1
    }
  }
}
