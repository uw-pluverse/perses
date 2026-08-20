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
package org.perses.reduction.event

import com.google.common.collect.ImmutableList
import org.perses.program.ProgramSize
import org.perses.program.TokenizedProgram
import org.perses.reduction.AbstractReducerNameAndDesc
import org.perses.reduction.io.PerFileSizeMetrics
import org.perses.spartree.AbstractSparTreeEdit
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.AbstractUnmodifiableSparTree
import org.perses.util.FileNameContentPair

class FixpointIterationStartEvent internal constructor(
  val reductionStartEvent: ReductionStartEvent,
  currentTimeMillis: Long,
  perFileSizeMetrics: PerFileSizeMetrics,
  val iteration: Int,
  val reducerClass: AbstractReducerNameAndDesc,
  private val treeStructureDumper: () -> String,
  val testScriptStatistics: TestScriptExecutorServiceStatisticsSnapshot,
  /** Optional per-iteration context for progress reporting, e.g. the parser facade this iteration's
   * driver is using. The whole-reduction [reductionStartEvent] cannot carry it (one reduction spans
   * many files/facades); a fixpoint iteration belongs to a single driver, so the facade is known here. */
  val extraData: String? = null,
) : AbstractStartEvent(currentTimeMillis, perFileSizeMetrics) {
  /**
   * The tree dump might be outdated, because the spartree
   * here might have been modified by certain reducer, and the tree
   * dump does not reflect the actual tree when this event was
   * created.
   */
  val oudatedTreeDump: String by lazy {
    treeStructureDumper()
  }

  override val prefixLabelFromRootToHere: String
    get() =
      reductionStartEvent.prefixLabelFromRootToHere +
        "FixPt[$iteration][${reducerClass.shortName}]"

  fun createEndEvent(
    currentTimeMillis: Long,
    perFileSizeMetrics: PerFileSizeMetrics,
    testScriptStatistics: TestScriptExecutorServiceStatisticsSnapshot,
  ): FixpointIterationEndEvent {
    check(!ended)
    ended = true
    return FixpointIterationEndEvent(
      startEvent = this,
      currentTimeMillis = currentTimeMillis,
      perFileSizeMetrics = perFileSizeMetrics,
      testScriptStatistics = testScriptStatistics,
    )
  }

  fun createAdHocMessageEvent(
    perFileSizeMetrics: PerFileSizeMetrics,
    messageComputer: () -> Any,
    newPrefixLabelFromRootToHere: String? = null,
  ): AdHocMessageEvent =
    reductionStartEvent.createAdHocMessageEvent(
      perFileSizeMetrics = perFileSizeMetrics,
      prefixLabelFromRootToHere = newPrefixLabelFromRootToHere ?: prefixLabelFromRootToHere,
      messageComputer = messageComputer,
    )

  fun createBestProgramUpdatedEvent(
    currentTimeMillis: Long,
    perFileSizeMetrics: PerFileSizeMetrics,
    programSizeBefore: ProgramSize<*>,
    programSizeAfter: ProgramSize<*>,
    appliedEdit: AbstractSparTreeEdit<*>,
  ): BestProgramUpdateEvent {
    check(!ended)
    return BestProgramUpdateEvent(
      currentFixpointIteration = this,
      currentTimeMillis = currentTimeMillis,
      perFileSizeMetrics = perFileSizeMetrics,
      programSizeBefore = programSizeBefore,
      programSizeAfter = programSizeAfter,
      appliedEdit = appliedEdit,
    )
  }

  fun createLevelReductionStartEvent(
    currentTimeMillis: Long,
    perFileSizeMetrics: PerFileSizeMetrics,
    level: Int,
    nodeCountOnLevel: Int,
  ): LevelReductionStartEvent {
    check(!ended)

    return LevelReductionStartEvent(
      currentFixpointIteration = this,
      currentTimeMillis = currentTimeMillis,
      perFileSizeMetrics = perFileSizeMetrics,
      level = level,
      nodeCountOnLevel = nodeCountOnLevel,
    )
  }

  fun createNodeReductionStartEvent(
    currentTimeMillis: Long,
    perFileSizeMetrics: PerFileSizeMetrics,
    program: ProgramSize<TokenizedProgram>,
    node: AbstractSparTreeNode,
    outputCreator: (TokenizedProgram) -> ImmutableList<FileNameContentPair<String>>,
  ): NodeReductionStartEvent {
    check(!ended)
    return NodeReductionStartEvent(
      currentFixpointIteration = this,
      currentTimeMillis = currentTimeMillis,
      perFileSizeMetrics = perFileSizeMetrics,
      program = program,
      node = node,
      outputCreator,
    )
  }

  fun createReductionSkippedEvent(
    currentTimeMillis: Long,
    perFileSizeMetrics: PerFileSizeMetrics,
    tree: AbstractUnmodifiableSparTree,
    message: String,
  ): ReductionSkippedEvent {
    check(!ended)
    return ReductionSkippedEvent(
      currentFixpointIteration = this,
      currentTimeMillis = currentTimeMillis,
      perFileSizeMetrics = perFileSizeMetrics,
      tree = tree,
      message = message,
    )
  }

  override fun initialPerFileSizeMetrics(): PerFileSizeMetrics =
    reductionStartEvent.initialPerFileSizeMetrics()

  fun createTokenSlicingStartEvent(
    currentTimeMillis: Long,
    perFileSizeMetrics: PerFileSizeMetrics,
    tokenSlicingGranularity: Int,
  ): TokenSlicingStartEvent {
    check(!ended)
    return TokenSlicingStartEvent(
      fixpointIterationStartEvent = this,
      currentTimeMillis = currentTimeMillis,
      perFileSizeMetrics = perFileSizeMetrics,
      tokenSliceGranularity = tokenSlicingGranularity,
    )
  }
}
