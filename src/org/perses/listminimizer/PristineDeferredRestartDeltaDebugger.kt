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
 * drdd exactly as the paper's pseudocode cuts blocks: fixed-stride blocks of S elements, the last
 * one holding the remainder. Kept beside [DeferredRestartDeltaDebugger], which balances the blocks
 * instead, to measure whether the block shape matters.
 */
class PristineDeferredRestartDeltaDebugger<T : Any, PropertyPayload>(
  arguments: ListMinimizerArguments<T, PropertyPayload>,
) : AbstractHalvingScheduleDeferredRestartDeltaDebugger<T, PropertyPayload>(arguments) {
  override fun computeInitialGranularity(): Int = best.size

  override fun partitionIntoBlocks(granularity: Int): List<List<ElementWrapper<T>>> =
    best.chunked(granularity)
}
