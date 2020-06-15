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
package org.perses.listener;

import org.perses.reduction.AbstractReductionEvent;
import org.perses.reduction.AbstractReductionEvent.FixpointIterationStartEvent;
import org.perses.reduction.AbstractReductionListener;

/** A default reduction listener that does nothing. */
public class DefaultReductionListener extends AbstractReductionListener {

  @Override
  public void onReductionStart(AbstractReductionEvent.ReductionStartEvent event) {}

  @Override
  public void onReductionEnd(AbstractReductionEvent.ReductionEndEvent event) {}

  @Override
  public void onFixpointIterationStart(FixpointIterationStartEvent event) {}

  @Override
  public void onFixpointIterationEnd(AbstractReductionEvent.FixpointIterationEndEvent event) {}

  @Override
  public void onLevelReductionStart(AbstractReductionEvent.LevelReductionStartEvent event) {}

  @Override
  public void onLevelReductionEnd(AbstractReductionEvent.LevelReductionEndEvent event) {}

  @Override
  public void onLevelGranularityReductionStart(
      AbstractReductionEvent.LevelGranularityReductionStartEvent event) {}

  @Override
  public void onLevelGranularityReductionEnd(
      AbstractReductionEvent.LevelGranularityReductionEndEvent event) {}

  @Override
  public void onSlicingTokensStart(AbstractReductionEvent.TokenSlicingStartEvent event) {}

  @Override
  public void onSlicingTokensEnd(AbstractReductionEvent.TokenSlicingEndEvent event) {}

  @Override
  public void onNodeReductionStart(AbstractReductionEvent.NodeReductionStartEvent event) {}

  @Override
  public void onNodeReductionEnd(AbstractReductionEvent.NodeReductionEndEvent event) {}

  @Override
  public void onTestScriptExecution(AbstractReductionEvent.TestScriptExecutionEvent event) {}

  @Override
  public void onTestResultCacheHit(AbstractReductionEvent.TestResultCacheHitEvent event) {}

  @Override
  public void onNodeEditActionSetCacheHit(
      AbstractReductionEvent.NodeEditActionSetCacheHitEvent event) {}

  @Override
  public void onNodeActionSetCacheClearance(
      AbstractReductionEvent.NodeEditActionSetCacheClearanceEvent event) {}

  @Override
  public void onTestScriptExecutionCacheEntryEviction(
      AbstractReductionEvent.TestScriptExecutionCacheEntryEvictionEvent event) {}

  @Override
  public void onTestScriptExecutionCancelled(
      AbstractReductionEvent.TestScriptExecutionCanceledEvent event) {}
}
