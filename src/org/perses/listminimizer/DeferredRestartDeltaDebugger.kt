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
import org.perses.util.toImmutableList

/**
 * Deferred Restart Delta Debugging (drdd), from Kumbhakern et al., "Dr. DD: 1-Minimal Isolation of
 * Failure Causes via Deferred Restarts", ISSRE 2026.
 *
 * ddmin restarts from the coarsest granularity after every successful deletion, but restarts are
 * only needed at the single-element level to resolve causal chains and hence to guarantee
 * 1-minimality. drdd therefore sweeps every halving partition size exactly once, deleting every
 * removable block in a single pass without restarting, and then repeats single-element sweeps until
 * a fixpoint or until [DeferredRestartDeltaDebuggerArguments.restartBudget] sweeps have run.
 * With the default (unbounded) budget the result is 1-minimal.
 */
class DeferredRestartDeltaDebugger<T : Any, PropertyPayload>(
  arguments: ListMinimizerArguments<T, PropertyPayload>,
) : AbstractListMinimizer<T, PropertyPayload>(arguments) {
  private val extraArguments = arguments.deferredRestartDeltaDebuggerArguments

  override fun reduceNonEmptyInput() {
    var partitionSize = best.size
    while (true) {
      partitionSize /= 2
      if (partitionSize <= extraArguments.minPartitionSize) {
        break
      }
      // The schedule halves from the original size while the list shrinks under it; a block
      // covering the whole list would only test the empty list, which reduce() owns.
      if (partitionSize <= extraArguments.maxPartitionSize && partitionSize < best.size) {
        fullComplementScan(partitionSize)
      }
    }
    causalChainScan()
  }

  private fun causalChainScan() {
    var remainingSweeps = extraArguments.restartBudget
    while (remainingSweeps > 0 && best.isNotEmpty()) {
      if (!fullComplementScan(partitionSize = 1)) {
        break
      }
      --remainingSweeps
    }
  }

  /** Returns whether any block was deleted. */
  private fun fullComplementScan(partitionSize: Int): Boolean {
    arguments.log {
      "Complement scan with partition size $partitionSize over ${best.size} elements"
    }
    var changed = false
    for (block in best.chunked(partitionSize)) {
      // [best] may have lost elements of this block to deletions elsewhere since the scan started.
      val liveBlock = block.filter { !it.deleted }.toImmutableList()
      if (liveBlock.isEmpty() || liveBlock.size == best.size) {
        continue
      }
      val candidate = Candidate.DeletionsFromOriginal(original = best, deleted_ = liveBlock)
      val outcome = testProperty(candidate).get()
      if (outcome !is CandidateOutcome.Interesting) {
        continue
      }
      candidate.deletedWrappers.forEach { it.markAsDeleted() }
      updateBest(candidate.candidateWrappers, outcome.payload)
      changed = true
    }
    return changed
  }
}
