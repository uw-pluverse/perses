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

/**
 * Deferred Restart Delta Debugging (drdd), from Kumbhakern et al., "Dr. DD: 1-Minimal Isolation of
 * Failure Causes via Deferred Restarts", ISSRE 2026.
 *
 * ddmin restarts from the coarsest granularity after every successful deletion, but restarts are
 * only needed at the single-element level to resolve causal chains and hence to guarantee
 * 1-minimality. drdd therefore sweeps every halving granularity exactly once, deleting every
 * removable block in a single pass without restarting, and then repeats single-element sweeps until
 * a fixpoint or until [DeferredRestartDeltaDebuggerArguments.restartBudget] sweeps have run.
 * With the default (unbounded) budget the result is 1-minimal.
 *
 * Subclasses define the coarse rounds: how blocks are cut, and what a granularity measures -- a
 * count of elements, or a total weight -- which the partition size bounds in
 * [DeferredRestartDeltaDebuggerArguments] are compared against.
 */
abstract class AbstractDeferredRestartDeltaDebugger<T : Any, PropertyPayload>(
  arguments: ListMinimizerArguments<T, PropertyPayload>,
) : AbstractListMinimizer<T, PropertyPayload>(arguments) {
  private val extraArguments = arguments.deferredRestartDeltaDebuggerArguments

  /**
   * Returns the next, finer coarse round cut from the current [best], or null once there is none.
   * Every block must be contiguous in [best].
   */
  protected abstract fun computeNextCoarseRound(): CoarseRound<T>?

  protected class CoarseRound<T : Any>(
    val granularity: Int,
    val blocks: List<List<ElementWrapper<T>>>,
  )

  final override fun reduceNonEmptyInput() {
    var previousBlocks: List<List<ElementWrapper<T>>>? = null
    while (true) {
      val round = computeNextCoarseRound() ?: break
      if (round.granularity <= extraArguments.minPartitionSize) {
        break
      }
      // Singleton blocks are the causal chain scan's job, and no later round can cut coarser.
      if (round.blocks.all { it.size == 1 }) {
        break
      }
      if (round.granularity > extraArguments.maxPartitionSize) {
        continue
      }
      // Re-scanning the same blocks of an unchanged list would repeat every test verbatim.
      if (round.blocks == previousBlocks) {
        continue
      }
      previousBlocks = round.blocks
      fullComplementScan(round.blocks, description = "granularity ${round.granularity}")
    }
    causalChainScan()
  }

  private fun causalChainScan() {
    var remainingSweeps = extraArguments.restartBudget
    while (remainingSweeps > 0 && best.isNotEmpty()) {
      if (!fullComplementScan(best.map { listOf(it) }, description = "single elements")) {
        break
      }
      --remainingSweeps
    }
  }

  /** Returns whether any block was deleted. */
  private fun fullComplementScan(
    blocks: List<List<ElementWrapper<T>>>,
    description: String,
  ): Boolean {
    arguments.log { "Complement scan with $description over ${best.size} elements" }
    return deleteRemovableBlocksInOnePass(blocks) > 0
  }
}
