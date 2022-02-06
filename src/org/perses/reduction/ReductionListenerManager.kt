/*
 * Copyright (C) 2018-2022 University of Waterloo.
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

import com.google.common.collect.ImmutableList
import org.perses.program.TokenizedProgram
import org.perses.reduction.event.BestProgramUpdateEvent
import org.perses.reduction.event.FixpointIterationEndEvent
import org.perses.reduction.event.FixpointIterationStartEvent
import org.perses.reduction.event.LevelGranularityReductionEndEvent
import org.perses.reduction.event.LevelGranularityReductionStartEvent
import org.perses.reduction.event.LevelReductionEndEvent
import org.perses.reduction.event.LevelReductionStartEvent
import org.perses.reduction.event.NodeEditActionSetCacheClearanceEvent
import org.perses.reduction.event.NodeEditActionSetCacheHitEvent
import org.perses.reduction.event.NodeReductionEndEvent
import org.perses.reduction.event.NodeReductionStartEvent
import org.perses.reduction.event.ReductionEndEvent
import org.perses.reduction.event.ReductionSkippedEvent
import org.perses.reduction.event.ReductionStartEvent
import org.perses.reduction.event.TestResultCacheHitEvent
import org.perses.reduction.event.TestScriptExecutionCacheEntryEvictionEvent
import org.perses.reduction.event.TestScriptExecutionCanceledEvent
import org.perses.reduction.event.TestScriptExecutionEvent
import org.perses.reduction.event.TokenSlicingEndEvent
import org.perses.reduction.event.TokenSlicingStartEvent
import org.perses.spartree.AbstractActionSet
import org.perses.spartree.AbstractSparTreeEdit

class ReductionListenerManager(private val listeners: ImmutableList<AbstractReductionListener>) {

  fun onReductionStart(event: ReductionStartEvent) {
    for (listener in listeners) {
      listener.onReductionStart(event)
    }
  }

  fun onReductionEnd(endEvent: ReductionEndEvent) {
    for (listener in listeners) {
      listener.onReductionEnd(endEvent)
    }
  }

  fun onFixpointIterationStart(event: FixpointIterationStartEvent) {
    for (listener in listeners) {
      listener.onFixpointIterationStart(event)
    }
  }

  fun onFixpointIterationEnd(event: FixpointIterationEndEvent) {
    for (listener in listeners) {
      listener.onFixpointIterationEnd(event)
    }
  }

  fun onBestProgramUpdated(event: BestProgramUpdateEvent) {
    for (listener in listeners) {
      listener.onBestProgramUpdated(event)
    }
  }

  fun onLevelReductionStart(event: LevelReductionStartEvent) {
    for (listener in listeners) {
      listener.onLevelReductionStart(event)
    }
  }

  fun onLevelReductionEnd(event: LevelReductionEndEvent) {
    for (listener in listeners) {
      listener.onLevelReductionEnd(event)
    }
  }

  fun onLevelGranularityReductionStart(event: LevelGranularityReductionStartEvent) {
    for (listener in listeners) {
      listener.onLevelGranularityReductionStart(event)
    }
  }

  fun onLevelGranularityReductionEnd(event: LevelGranularityReductionEndEvent) {
    for (listener in listeners) {
      listener.onLevelGranularityReductionEnd(event)
    }
  }

  fun onSlicingTokensStart(
    event: TokenSlicingStartEvent
  ) {
    listeners.forEach { it.onSlicingTokensStart(event) }
  }

  fun onSlicingTokensEnd(
    event: TokenSlicingEndEvent
  ) {
    listeners.forEach { it.onSlicingTokensEnd(event) }
  }

  fun onNodeReductionStart(event: NodeReductionStartEvent) {
    for (listener in listeners) {
      listener.onNodeReductionStart(event)
    }
  }

  fun onNodeReductionEnd(
    event: NodeReductionEndEvent
  ) {
    for (listener in listeners) {
      listener.onNodeReductionEnd(event)
    }
  }

  fun onTestScriptExecution(
    result: PropertyTestResult,
    program: TokenizedProgram,
    edit: AbstractSparTreeEdit<*>
  ) {
    val event = TestScriptExecutionEvent(
      System.currentTimeMillis(), result, program, edit
    )
    for (listener in listeners) {
      listener.onTestScriptExecution(event)
    }
  }

  fun onTestScriptExecutionCancelled(
    program: TokenizedProgram,
    edit: AbstractSparTreeEdit<*>,
    millisToCancelTheTask: Int
  ) {
    val event = TestScriptExecutionCanceledEvent(
      System.currentTimeMillis(), millisToCancelTheTask, program, edit
    )
    for (listener in listeners) {
      listener.onTestScriptExecutionCancelled(event)
    }
  }

  @Synchronized
  fun onTestResultCacheHit(
    result: PropertyTestResult,
    program: TokenizedProgram,
    edit: AbstractSparTreeEdit<*>
  ) {
    val event = TestResultCacheHitEvent(
      System.currentTimeMillis(), result, program, edit
    )
    for (listener in listeners) {
      listener.onTestResultCacheHit(event)
    }
  }

  @Synchronized
  fun onNodeEditActionSetCacheHit(query: AbstractActionSet<*>) {
    val event = NodeEditActionSetCacheHitEvent(
      System.currentTimeMillis(), query
    )
    for (listener in listeners) {
      listener.onNodeEditActionSetCacheHit(event)
    }
  }

  fun onTestScriptExecutionCacheEntryEviction(sizeBefore: Int, sizeAfter: Int) {
    val event = TestScriptExecutionCacheEntryEvictionEvent(
      System.currentTimeMillis(), sizeBefore, sizeAfter
    )
    for (listener in listeners) {
      listener.onTestScriptExecutionCacheEntryEviction(event)
    }
  }

  fun onNodeActionSetClearance(cacheSizeBefore: Int) {
    val event = NodeEditActionSetCacheClearanceEvent(
      System.currentTimeMillis(), cacheSizeBefore
    )
    for (listener in listeners) {
      listener.onNodeActionSetCacheClearance(event)
    }
  }

  fun onReductionSkipped(event: ReductionSkippedEvent) {
    for (listener in listeners) {
      listener.onReductionSkipped(event)
    }
  }
}
