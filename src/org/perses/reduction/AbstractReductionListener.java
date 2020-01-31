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
package org.perses.reduction;

import org.perses.reduction.AbstractReductionEvent.FixpointIterationStartEvent;
import org.perses.reduction.AbstractReductionEvent.NodeEditActionSetCacheClearanceEvent;
import org.perses.reduction.AbstractReductionEvent.ReductionEndEvent;
import org.perses.reduction.AbstractReductionEvent.ReductionStartEvent;

/** The listener to access the internal reduction state. */
public abstract class AbstractReductionListener {

  /** Called on the start of the reduction. */
  public abstract void onReductionStart(ReductionStartEvent event);

  /** Called on the end of the reduction. */
  public abstract void onReductionEnd(ReductionEndEvent event);

  /** Called on the start of a fixpoint iteration. */
  public abstract void onFixpointIterationStart(FixpointIterationStartEvent event);

  /** Called on the end of a fixpoint iteration */
  public abstract void onFixpointIterationEnd(
      AbstractReductionEvent.FixpointIterationEndEvent event);

  public abstract void onLevelReductionStart(AbstractReductionEvent.LevelReductionStartEvent event);

  public abstract void onLevelReductionEnd(AbstractReductionEvent.LevelReductionEndEvent event);

  public abstract void onLevelGranularityReductionStart(
      AbstractReductionEvent.LevelGranularityReductionStartEvent event);

  public abstract void onLevelGranularityReductionEnd(
      AbstractReductionEvent.LevelGranularityReductionEndEvent event);

  public abstract void onNodeReductionStart(AbstractReductionEvent.NodeReductionStartEvent event);

  public abstract void onNodeReductionEnd(AbstractReductionEvent.NodeReductionEndEvent event);

  public abstract void onTestScriptExecutionCacheEntryEviction(
      AbstractReductionEvent.TestScriptExecutionCacheEntryEvictionEvent event);

  public abstract void onNodeActionSetCacheClearance(NodeEditActionSetCacheClearanceEvent event);

  public abstract void onTestScriptExecution(AbstractReductionEvent.TestScriptExecutionEvent event);

  public abstract void onTestResultCacheHit(AbstractReductionEvent.TestResultCacheHitEvent event);

  public abstract void onNodeEditActionSetCacheHit(
      AbstractReductionEvent.NodeEditActionSetCacheHitEvent event);

  public abstract void onTestScriptExecutionCancelled(
      AbstractReductionEvent.TestScriptExecutionCanceledEvent event);
}
