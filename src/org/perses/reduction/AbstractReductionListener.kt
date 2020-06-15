/*
 * Copyright (C) 2003-2017 Chengnian Sun.
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

/** The listener to access the internal reduction state.  */
abstract class AbstractReductionListener {
  /** Called on the start of the reduction.  */
  abstract fun onReductionStart(event: AbstractReductionEvent.ReductionStartEvent?)

  /** Called on the end of the reduction.  */
  abstract fun onReductionEnd(event: AbstractReductionEvent.ReductionEndEvent?)

  /** Called on the start of a fixpoint iteration.  */
  abstract fun onFixpointIterationStart(event: AbstractReductionEvent.FixpointIterationStartEvent?)

  /** Called on the end of a fixpoint iteration  */
  abstract fun onFixpointIterationEnd(
    event: AbstractReductionEvent.FixpointIterationEndEvent?
  )

  abstract fun onLevelReductionStart(event: AbstractReductionEvent.LevelReductionStartEvent?)
  abstract fun onLevelReductionEnd(event: AbstractReductionEvent.LevelReductionEndEvent?)
  abstract fun onLevelGranularityReductionStart(
    event: AbstractReductionEvent.LevelGranularityReductionStartEvent?
  )

  abstract fun onLevelGranularityReductionEnd(
    event: AbstractReductionEvent.LevelGranularityReductionEndEvent?
  )

  abstract fun onNodeReductionStart(event: AbstractReductionEvent.NodeReductionStartEvent?)
  abstract fun onNodeReductionEnd(event: AbstractReductionEvent.NodeReductionEndEvent?)
  abstract fun onTestScriptExecutionCacheEntryEviction(
    event: AbstractReductionEvent.TestScriptExecutionCacheEntryEvictionEvent?
  )

  abstract fun onNodeActionSetCacheClearance(
    event: AbstractReductionEvent.NodeEditActionSetCacheClearanceEvent?
  )
  abstract fun onTestScriptExecution(event: AbstractReductionEvent.TestScriptExecutionEvent?)
  abstract fun onTestResultCacheHit(event: AbstractReductionEvent.TestResultCacheHitEvent?)
  abstract fun onNodeEditActionSetCacheHit(
    event: AbstractReductionEvent.NodeEditActionSetCacheHitEvent?
  )

  abstract fun onTestScriptExecutionCancelled(
    event: AbstractReductionEvent.TestScriptExecutionCanceledEvent?
  )

  abstract fun onSlicingTokensStart(event: AbstractReductionEvent.TokenSlicingStartEvent)
  abstract fun onSlicingTokensEnd(event: AbstractReductionEvent.TokenSlicingEndEvent)
}
