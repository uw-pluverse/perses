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

import com.google.common.collect.ImmutableList
import org.perses.reduction.AbstractReducerNameAndDesc
import org.perses.reduction.TestScriptExecutorService
import org.perses.reduction.io.AbstractOutputManagerFactory
import org.perses.util.toImmutableList

/**
 * A multi-file reducer that **drops a whole file** from the set whenever the property still holds
 * without it. True multi-file reduction only ever rewrites file *content*; a file that turns out to
 * be entirely unnecessary can only be removed by a file-set change, which is this reducer's job.
 *
 * Every live file is a candidate, regardless of its content. A multi-file reduction has only a
 * handful of files (`AbstractOriginalReductionInputs` caps the set at < 8), so trying to drop each one costs
 * at most a few tests -- and dropping a *whole* file is strictly more powerful than dropping only
 * emptied ones: a file the content reducers could not drive to empty (e.g. one left as a
 * non-removable stub the grammar keeps) is still removed here when the test passes without it.
 *
 * It must run as a strictly-terminal phase -- its own driver, placed last (see `Main`) -- because
 * dropping a file leaves the result folder with fewer files than `originalReductionInputs.mutableFiles`.
 *
 * Strategy (drop-empties-then-greedy-to-fixpoint, mirroring a list minimizer): first try dropping
 * every *empty* file in one test -- emptied dependency files are the common case and usually all
 * unnecessary, so this clears them in a single test instead of one each. (Dropping *all* files would
 * include the file that reproduces the bug and so essentially never passes; it is not attempted.)
 * Then sweep the remaining files, dropping each one the property survives without; removing one file
 * can make another -- needed only by it -- removable, so the sweep repeats until a full pass drops
 * nothing. Each accepted removal is committed through `state.updateBest`, which `saveBestProgram`
 * reconciles so the dropped file is physically removed from the result folder.
 */
class CrossFileFileDeletionReducer(
  nameAndDesc: AbstractReducerNameAndDesc,
  ioManager: CrossFileReductionIOManager,
  testScriptExecutorService: TestScriptExecutorService,
  outputManagerFactory: AbstractOutputManagerFactory<CrossFileProgram>,
) : AbstractCrossFileReducer(
    nameAndDesc,
    ioManager,
    testScriptExecutorService,
    outputManagerFactory,
  ) {
  override fun reduce(state: CrossFileReductionState) {
    // Fast path: drop every *empty* file in one test. Emptied dependency files are the common case
    // and are usually all unnecessary, so this clears them in a single test instead of one each.
    // (Dropping *all* files -- including the one that reproduces the bug -- would essentially never
    // pass, so it is not attempted; the greedy sweep below removes any non-empty unnecessary file.)
    val emptyFiles =
      state.bestProgram.fileContents
        .filterValues { it.isBlank() }
        .keys
        .toImmutableList()
    if (emptyFiles.size > 1) {
      val candidate = state.bestProgram.without(emptyFiles)
      if (testProgram(candidate)) {
        state.updateBest(candidate)
      }
    }

    // Greedy over every remaining file (empty or not), to a fixpoint.
    dropRemovableFilesToFixpoint(state)
  }

  /**
   * Repeatedly sweeps the currently-live files, dropping each one the property survives without,
   * until a full sweep drops nothing -- removing one file can make another (needed only by it)
   * removable, so a single sweep is not enough.
   */
  private fun dropRemovableFilesToFixpoint(state: CrossFileReductionState) {
    var changed = true
    while (changed) {
      changed = false
      for (file in state.bestProgram.fileContents.keys
        .toImmutableList()) {
        val current = state.bestProgram
        if (!current.fileContents.containsKey(file)) {
          continue
        }
        val candidate = current.without(ImmutableList.of(file))
        if (testProgram(candidate)) {
          state.updateBest(candidate)
          changed = true
        }
      }
    }
  }
}
