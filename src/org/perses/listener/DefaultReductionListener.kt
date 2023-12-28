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
package org.perses.listener

import org.perses.reduction.AbstractReductionListener
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

/** A default reduction listener that does nothing.  */
open class DefaultReductionListener : AbstractReductionListener() {
  override fun onReductionStart(event: ReductionStartEvent) {}
  override fun onReductionEnd(event: ReductionEndEvent) {}
  override fun onFixpointIterationStart(event: FixpointIterationStartEvent) {}
  override fun onFixpointIterationEnd(event: FixpointIterationEndEvent) {}
  override fun onLevelReductionStart(event: LevelReductionStartEvent) {}
  override fun onLevelReductionEnd(event: LevelReductionEndEvent) {}
  override fun onLevelGranularityReductionStart(event: LevelGranularityReductionStartEvent) {}
  override fun onLevelGranularityReductionEnd(event: LevelGranularityReductionEndEvent) {}
  override fun onSlicingTokensStart(event: TokenSlicingStartEvent) {}
  override fun onSlicingTokensEnd(event: TokenSlicingEndEvent) {}
  override fun onNodeReductionStart(event: NodeReductionStartEvent) {}
  override fun onNodeReductionEnd(event: NodeReductionEndEvent) {}
  override fun onTestScriptExecution(event: TestScriptExecutionEvent) {}
  override fun onTestResultCacheHit(event: TestResultCacheHitEvent) {}
  override fun onNodeEditActionSetCacheHit(event: NodeEditActionSetCacheHitEvent) {}
  override fun onNodeActionSetCacheClearance(event: NodeEditActionSetCacheClearanceEvent) {}
  override fun onTestScriptExecutionCacheEntryEviction(
    event: TestScriptExecutionCacheEntryEvictionEvent,
  ) {
  }

  override fun onTestScriptExecutionCancelled(event: TestScriptExecutionCanceledEvent) {}
  override fun onBestProgramUpdated(event: BestProgramUpdateEvent) {}
  override fun onReductionSkipped(event: ReductionSkippedEvent) {}
}
