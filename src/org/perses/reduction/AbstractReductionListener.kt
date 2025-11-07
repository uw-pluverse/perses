/*
 * Copyright (C) 2018-2025 University of Waterloo.
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

import org.perses.reduction.event.AbstractTestScriptExecutionEvent
import org.perses.reduction.event.AdHocMessageEvent
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
import org.perses.reduction.event.SanityCheckEvent
import org.perses.reduction.event.TestScriptExecutionCacheEntryEvictionEvent
import org.perses.reduction.event.TokenSlicingEndEvent
import org.perses.reduction.event.TokenSlicingStartEvent

/** The listener to access the internal reduction state.  */
abstract class AbstractReductionListener : AutoCloseable {
  /** Called on the start of the reduction.  */
  open fun onReductionStart(event: ReductionStartEvent) {}

  /** Called on the end of the reduction.  */
  open fun onReductionEnd(event: ReductionEndEvent) {}

  /** Called on the start of a fixpoint iteration.  */
  open fun onFixpointIterationStart(event: FixpointIterationStartEvent) {}

  /** Called on the end of a fixpoint iteration  */
  open fun onFixpointIterationEnd(event: FixpointIterationEndEvent) {}

  open fun onLevelReductionStart(event: LevelReductionStartEvent) {}

  open fun onLevelReductionEnd(event: LevelReductionEndEvent) {}

  open fun onLevelGranularityReductionStart(event: LevelGranularityReductionStartEvent) {}

  open fun onLevelGranularityReductionEnd(event: LevelGranularityReductionEndEvent) {}

  open fun onNodeReductionStart(event: NodeReductionStartEvent) {}

  open fun onNodeReductionEnd(event: NodeReductionEndEvent) {}

  open fun onCriticalException(exception: Exception) {}

  open fun onTestScriptExecutionCacheEntryEviction(
    event: TestScriptExecutionCacheEntryEvictionEvent,
  ) {}

  open fun onNodeActionSetCacheClearance(event: NodeEditActionSetCacheClearanceEvent) {}

  open fun onTestScriptExecution(
    event: AbstractTestScriptExecutionEvent.TestScriptExecutionEvent,
  ) {}

  open fun onTestResultCacheHit(event: AbstractTestScriptExecutionEvent.TestResultCacheHitEvent) {}

  open fun onNodeEditActionSetCacheHit(event: NodeEditActionSetCacheHitEvent) {}

  open fun onTestScriptExecutionCancelled(
    event: AbstractTestScriptExecutionEvent.TestScriptExecutionCanceledEvent,
  ) {}

  open fun onSlicingTokensStart(event: TokenSlicingStartEvent) {}

  open fun onSlicingTokensEnd(event: TokenSlicingEndEvent) {}

  open fun onBestProgramUpdated(event: BestProgramUpdateEvent) {}

  open fun onReductionSkipped(event: ReductionSkippedEvent) {}

  open fun onSanityCheck(event: SanityCheckEvent) {}

  open fun onAdHocMessageEvent(event: AdHocMessageEvent) {}

  open fun notifyCacheSettings(
    queryCacheEnabled: Boolean,
    editCacheEnabled: Boolean,
    queryCacheType: String,
  ) {}

  open fun notifyNumOfLexemesInPersesTokenFactory(numOfLexemes: Int) {}
}
