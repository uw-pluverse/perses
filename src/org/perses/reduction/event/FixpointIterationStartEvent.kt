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
import org.perses.reduction.AbstractReducerNameAndDesc
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.AbstractUnmodifiableSparTree
import java.lang.ref.WeakReference

class FixpointIterationStartEvent internal constructor(
  val reductionStartEvent: ReductionStartEvent,
  currentTimeMillis: Long,
  programSize: Int,
  val iteration: Int,
  val reducerClass: AbstractReducerNameAndDesc,
  private val outdatedTree: WeakReference<AbstractUnmodifiableSparTree>,
  val testScriptStatistics: TestScriptExecutorServiceStatisticsSnapshot,
) : AbstractStartEvent(currentTimeMillis, programSize) {

  /**
   * The tree dump might be outdated, because the spartree
   * here might have been modified by certain reducer, and the tree
   * dump does not reflect the actual tree when this event was
   * created.
   */
  val oudatedTreeDump: String by lazy {
    val tree = outdatedTree.get()
    tree?.printTreeStructure() ?: ""
  }

  fun createEndEvent(
    currentTimeMillis: Long,
    programSize: Int,
    testScriptStatistics: TestScriptExecutorServiceStatisticsSnapshot,
  ): FixpointIterationEndEvent {
    check(!ended)
    ended = true
    return FixpointIterationEndEvent(
      startEvent = this,
      currentTimeMillis = currentTimeMillis,
      programSize = programSize,
      testScriptStatistics = testScriptStatistics,
    )
  }

  fun createBestProgramUpdatedEvent(
    currentTimeMillis: Long,
    programSizeBefore: Int,
    programSizeAfter: Int,
  ): BestProgramUpdateEvent {
    check(!ended)
    return BestProgramUpdateEvent(
      currentFixpointIteration = this,
      currentTimeMillis = currentTimeMillis,
      programSizeBefore = programSizeBefore,
      programSizeAfter = programSizeAfter,
    )
  }

  fun createLevelReductionStartEvent(
    currentTimeMillis: Long,
    programSize: Int,
    level: Int,
    nodeCountOnLevel: Int,
  ): LevelReductionStartEvent {
    check(!ended)

    return LevelReductionStartEvent(
      currentFixpointIteration = this,
      currentTimeMillis = currentTimeMillis,
      programSize = programSize,
      level = level,
      nodeCountOnLevel = nodeCountOnLevel,
    )
  }

  fun createNodeReductionStartEvent(
    currentTimeMillis: Long,
    program: TokenizedProgram,
    node: AbstractSparTreeNode,
  ): NodeReductionStartEvent {
    check(!ended)
    return NodeReductionStartEvent(
      currentFixpointIteration = this,
      currentTimeMillis = currentTimeMillis,
      program = program,
      node = node,
    )
  }

  fun createReductionSkippedEvent(
    currentTimeMillis: Long,
    programSize: Int,
    tree: AbstractUnmodifiableSparTree,
    message: String,
  ): ReductionSkippedEvent {
    check(!ended)
    return ReductionSkippedEvent(
      currentFixpointIteration = this,
      currentTimeMillis = currentTimeMillis,
      programSize = programSize,
      tree = tree,
      message = message,
    )
  }

  override fun initialProgramSize(): Int {
    return reductionStartEvent.initialProgramSize()
  }

  fun createTokenSlicingStartEvent(
    currentTimeMillis: Long,
    programSize: Int,
    tokenSlicingGranularity: Int,
  ): TokenSlicingStartEvent {
    check(!ended)
    return TokenSlicingStartEvent(
      fixpointIterationStartEvent = this,
      currentTimeMillis = currentTimeMillis,
      programSize = programSize,
      tokenSliceGranularity = tokenSlicingGranularity,
    )
  }
}
