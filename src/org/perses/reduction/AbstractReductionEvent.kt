/*
 * Copyright (C) 2018-2020 University of Waterloo.
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
package org.perses.reduction

import org.perses.program.TokenizedProgram
import org.perses.tree.spar.AbstractActionSet
import org.perses.tree.spar.AbstractSparTreeEdit
import org.perses.tree.spar.AbstractSparTreeNode
import org.perses.tree.spar.AbstractUnmodifiableSparTree

abstract class AbstractReductionEvent(val currentTimeMillis: Long) {

  abstract class AbstractReductionEventWithProgramSize(
    currentTimeMillis: Long,
    val programSize: Int
  ) :
    AbstractReductionEvent(currentTimeMillis)

  class ReductionStartEvent(
    currentTimeMillis: Long,
    val tree: AbstractUnmodifiableSparTree,
    programSize: Int
  ) :
    AbstractReductionEventWithProgramSize(currentTimeMillis, programSize)

  class ReductionEndEvent(
    currentTimeMillis: Long,
    programSize: Int,
    val countOfTestScriptExecutions: Int
  ) :
    AbstractReductionEventWithProgramSize(currentTimeMillis, programSize)

  class FixpointIterationStartEvent(
    currentTimeMillis: Long,
    programSize: Int,
    val iteration: Int,
    val reducerClass: ReducerAnnotation
  ) :
    AbstractReductionEventWithProgramSize(currentTimeMillis, programSize)

  class FixpointIterationEndEvent(
    currentTimeMillis: Long,
    programSize: Int,
    val iteration: Int,
    val countOfTestScriptExecutions: Int
  ) :
    AbstractReductionEventWithProgramSize(currentTimeMillis, programSize)

  class LevelReductionStartEvent(
    currentTimeMillis: Long,
    programSize: Int,
    val level: Int,
    val nodeCountOnLevel: Int
  ) :
    AbstractReductionEventWithProgramSize(currentTimeMillis, programSize)

  class LevelReductionEndEvent(
    currentTimeMillis: Long,
    programSize: Int,
    val level: Int
  ) :
    AbstractReductionEventWithProgramSize(currentTimeMillis, programSize)

  class LevelGranularityReductionStartEvent(
    currentTimeMillis: Long,
    programSize: Int,
    val maxNumOfNodesPerPartition: Int
  ) :
    AbstractReductionEventWithProgramSize(currentTimeMillis, programSize)

  class LevelGranularityReductionEndEvent(
    currentTimeMillis: Long,
    programSize: Int,
    val maxNumOfNodesPerPartition: Int
  ) :
    AbstractReductionEventWithProgramSize(currentTimeMillis, programSize)

  class TokenSlicingStartEvent(
    currentTimeMillis: Long,
    programSize: Int,
    val tokenSliceGranularity: Int
  ) :
    AbstractReductionEventWithProgramSize(currentTimeMillis, programSize)

  class TokenSlicingEndEvent(
    currentTimeMillis: Long,
    programSize: Int,
    val startEvent: TokenSlicingStartEvent
  ) :
    AbstractReductionEventWithProgramSize(currentTimeMillis, programSize)

  class NodeReductionStartEvent(
    currentTimeMillis: Long,
    programSize: Int,
    val tree: AbstractUnmodifiableSparTree,
    val node: AbstractSparTreeNode
  ) :
    AbstractReductionEventWithProgramSize(currentTimeMillis, programSize)

  class NodeReductionEndEvent(
    currentTimeMillis: Long,
    programSize: Int,
    val tree: AbstractUnmodifiableSparTree,
    val node: AbstractSparTreeNode,
    val remainingQueueSize: Int
  ) :
    AbstractReductionEventWithProgramSize(currentTimeMillis, programSize)

  class TestScriptExecutionCacheEntryEvictionEvent(
    currentTimeMillis: Long,
    val sizeBefore: Int,
    val sizeAfter: Int
  ) :
    AbstractReductionEvent(currentTimeMillis)

  class TestScriptExecutionEvent(
    currentTimeMillis: Long,
    val result: TestScript.TestResult,
    val program: TokenizedProgram,
    val edit: AbstractSparTreeEdit
  ) :
    AbstractReductionEvent(currentTimeMillis)

  class TestScriptExecutionCanceledEvent(
    currentTimeMillis: Long,
    val millisToCancelTheTask: Int,
    val program: TokenizedProgram,
    val edit: AbstractSparTreeEdit
  ) :
    AbstractReductionEvent(currentTimeMillis)

  class TestResultCacheHitEvent(
    currentTimeMillis: Long,
    val result: TestScript.TestResult,
    val program: TokenizedProgram,
    val edit: AbstractSparTreeEdit
  ) :
    AbstractReductionEvent(currentTimeMillis)

  class NodeEditActionSetCacheHitEvent(
    currentTimeMillis: Long,
    val query: AbstractActionSet<*>
  ) :
    AbstractReductionEvent(currentTimeMillis)

  class NodeEditActionSetCacheClearanceEvent(
    currentTimeMillis: Long,
    val originalEntrySize: Int
  ) :
    AbstractReductionEvent(currentTimeMillis)
}
