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
package org.perses.reduction.crossfile

import com.google.common.flogger.FluentLogger
import org.perses.util.ktInfo

/**
 * The running state of a true multi-file reduction: the current best whole-set program, plus a hook
 * fired whenever it improves. Mirrors `ListDiffReductionState`.
 *
 * The driver wires [listenerOnUpdate] to `ioManager.saveBestProgram`, so every accepted improvement
 * is atomically written to the result folder -- keeping the folder the single source of truth. The
 * `init` block fires the listener once for the initial program so the folder mirrors [bestProgram]
 * from the start.
 *
 * Not thread-safe: [updateBest] is called sequentially on the reduction thread after the concurrent
 * candidate tests of a reducer pass resolve, as in the list-diff reducer.
 */
class CrossFileReductionState(
  initialProgram: CrossFileProgram,
  private val listenerOnUpdate: (CrossFileProgram) -> Unit,
) {
  var bestProgram: CrossFileProgram = initialProgram
    private set

  fun updateBest(newBest: CrossFileProgram) {
    logger.ktInfo {
      "New best multi-file program: ${newBest.fileContents.size} files, " +
        "${newBest.fileContents.values.sumOf { it.length }} characters total."
    }
    bestProgram = newBest
    listenerOnUpdate(newBest)
  }

  init {
    updateBest(bestProgram)
  }

  companion object {
    private val logger = FluentLogger.forEnclosingClass()
  }
}
