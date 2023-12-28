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
package org.perses.reduction.event

import org.perses.program.TokenizedProgram
import org.perses.spartree.AbstractSparTreeNode

class NodeReductionStartEvent internal constructor(
  val currentFixpointIteration: FixpointIterationStartEvent,
  currentTimeMillis: Long,
  val program: TokenizedProgram,
  val node: AbstractSparTreeNode,
) : AbstractStartEvent(currentTimeMillis, programSize = program.tokenCount()) {

  val iteration = currentFixpointIteration.iteration

  fun getReducerName() = currentFixpointIteration.reducerClass.shortName

  fun createEndEvent(
    currentTimeMillis: Long,
    program: TokenizedProgram,
    remainingQueueSize: Int,
  ): NodeReductionEndEvent {
    check(!ended)
    ended = true
    return NodeReductionEndEvent(
      startEvent = this,
      currentTimeMillis = currentTimeMillis,
      program = program,
      node = node,
      remainingQueueSize = remainingQueueSize,
    )
  }

  override fun initialProgramSize(): Int {
    return currentFixpointIteration.initialProgramSize()
  }
}
