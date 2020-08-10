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

package org.perses.listener;

import com.google.common.flogger.FluentLogger;
import org.perses.reduction.AbstractReductionEvent;
import org.perses.reduction.AbstractReductionEvent.ReductionStartEvent;
import org.perses.util.TimeSpan;
import org.perses.util.TimeUtil;
import org.perses.util.Util;

import static com.google.common.base.Preconditions.checkState;

/**
 * FIXME: the listeners need refactoring. The listeners now store states, which are not friendly to
 * concurrency.
 *
 * <p>A logging listener to print the progress of reduction.
 */
public class LoggingListener extends DefaultReductionListener {

  private static final int UNINITIALIZED_VALUE = Integer.MIN_VALUE;

  private static final String FIXPOINT_REDUCER_MSG_PREFIX = "Fixpoint[%s]:Reducer[%s]: ";
  private static final FluentLogger logger = FluentLogger.forEnclosingClass();
  private TimeSpan.Builder timeSpanBuilder;
  private int initialProgramSize = UNINITIALIZED_VALUE;
  private int finalProgramSize = UNINITIALIZED_VALUE;
  private int fixpointSize = UNINITIALIZED_VALUE;
  private int fixpointIteration = UNINITIALIZED_VALUE;
  private int levelSize = UNINITIALIZED_VALUE;
  private int granularitySize = UNINITIALIZED_VALUE;
  private int nodeSize = UNINITIALIZED_VALUE;
  private String reducerName;

  @Override
  public void onReductionStart(ReductionStartEvent event) {
    checkState(timeSpanBuilder == null);
    timeSpanBuilder = TimeSpan.Builder.start(event.getCurrentTimeMillis());
    checkState(this.initialProgramSize == UNINITIALIZED_VALUE);
    this.initialProgramSize = event.getProgramSize();

    if (logger.atInfo().isEnabled()) {
      logger.atInfo().log(
          "Reduction Started at %s", TimeUtil.formatDateForDisplay(timeSpanBuilder.getStartMillis()));
    }
  }

  @Override
  public void onReductionEnd(AbstractReductionEvent.ReductionEndEvent event) {
    final TimeSpan timeSpan = timeSpanBuilder.end(event.getCurrentTimeMillis());
    timeSpanBuilder = null;
    checkState(this.finalProgramSize == UNINITIALIZED_VALUE);
    this.finalProgramSize = event.getProgramSize();

    if (logger.atInfo().isEnabled()) {
      logger.atInfo().log(
          "Reduction ended at %s", TimeUtil.formatDateForDisplay(timeSpan.getEndTimeMillis()));
    }
    logger.atInfo().log("Elapsed time is %s", timeSpan.getFormattedElaspedTime());
    final int delta = this.initialProgramSize - this.finalProgramSize;
    logger.atInfo().log(
        "Removed %s tokens. reduction ratio is %s/%s=%s",
        delta,
        this.finalProgramSize,
        this.initialProgramSize,
        Util.computePercentage(this.finalProgramSize, this.initialProgramSize));
    logger.atInfo().log("Test script execution count: %s", event.getCountOfTestScriptExecutions());
  }

  @Override
  public void onFixpointIterationStart(AbstractReductionEvent.FixpointIterationStartEvent event) {
    this.fixpointIteration = event.getIteration();
    this.fixpointSize = event.getProgramSize();
    reducerName = event.getReducerClass().shortName();
    logger.atInfo().log(
        FIXPOINT_REDUCER_MSG_PREFIX + "New fixpoint iteration started. #Token=%s",
        fixpointIteration,
        reducerName,
        event.getProgramSize());
  }

  @Override
  public void onFixpointIterationEnd(AbstractReductionEvent.FixpointIterationEndEvent event) {
    final int programSize = event.getProgramSize();
    if (logger.atInfo().isEnabled()) {
      logger.atInfo().log(
          FIXPOINT_REDUCER_MSG_PREFIX
              + "Fixpoint iteration finished. Delete %s tokens, "
              + "ratio=%s/%s=%s",
          fixpointIteration,
          reducerName,
          (this.fixpointSize - programSize),
          programSize,
          this.initialProgramSize,
          Util.computePercentage(programSize, this.initialProgramSize));
    }
  }

  @Override
  public void onLevelReductionStart(AbstractReductionEvent.LevelReductionStartEvent event) {
    levelSize = event.getProgramSize();
    logger.atInfo().log(
        FIXPOINT_REDUCER_MSG_PREFIX + "Reduction at level %s, #nodes = %s,",
        fixpointIteration,
        reducerName,
        event.getLevel(),
        event.getNodeCountOnLevel());
  }

  @Override
  public void onLevelReductionEnd(AbstractReductionEvent.LevelReductionEndEvent event) {
    final int programSize = event.getProgramSize();
    if (logger.atInfo().isEnabled()) {
      logger.atInfo().log(
          FIXPOINT_REDUCER_MSG_PREFIX
              + "Reduction on level %s: delete %s tokens, "
              + "ratio=%s/%s=%s",
          fixpointIteration,
          reducerName,
          event.getLevel(),
          (this.levelSize - programSize),
          programSize,
          this.initialProgramSize,
          Util.computePercentage(programSize, this.initialProgramSize));
    }
  }

  @Override
  public void onLevelGranularityReductionStart(
      AbstractReductionEvent.LevelGranularityReductionStartEvent event) {
    granularitySize = event.getProgramSize();
  }

  @Override
  public void onLevelGranularityReductionEnd(
      AbstractReductionEvent.LevelGranularityReductionEndEvent event) {
    final int programSize = event.getProgramSize();
    if (logger.atInfo().isEnabled()) {
      logger.atInfo().log(
          FIXPOINT_REDUCER_MSG_PREFIX
              + "Delta with granularity %s: delete %s tokens, "
              + "ratio=%s/%s=%s",
          fixpointIteration,
          reducerName,
          event.getMaxNumOfNodesPerPartition(),
          (this.granularitySize - programSize),
          programSize,
          this.initialProgramSize,
          Util.computePercentage(programSize, this.initialProgramSize));
    }
  }

  @Override
  public void onSlicingTokensStart(AbstractReductionEvent.TokenSlicingStartEvent event) {}

  @Override
  public void onSlicingTokensEnd(AbstractReductionEvent.TokenSlicingEndEvent event) {
    if (!logger.atInfo().isEnabled()) {
      return;
    }
    final StringBuilder builder = new StringBuilder(300);
    printPrefix(builder);
    final int initialProgramSize = event.getStartEvent().getProgramSize();
    final int newProgramSize = event.getProgramSize();
    builder
        .append(": TokenSlicer@")
        .append(event.getStartEvent().getTokenSliceGranularity())
        .append(", ratio=")
        .append(event.getProgramSize())
        .append("/")
        .append(initialProgramSize)
        .append("=")
        .append(Util.computePercentage(newProgramSize, initialProgramSize))
        .append("tokens");
    logger.atInfo().log("%s", builder);
  }

  @Override
  public void onNodeReductionStart(AbstractReductionEvent.NodeReductionStartEvent event) {
    nodeSize = event.getProgramSize();
    if (logger.atConfig().isEnabled()) {
      logger.atConfig().log(FIXPOINT_REDUCER_MSG_PREFIX + "Reducing node %s", event.getNode());
    }
  }

  @Override
  public void onNodeReductionEnd(AbstractReductionEvent.NodeReductionEndEvent event) {
    if (!logger.atInfo().isEnabled()) {
      return;
    }
    final int programSize = event.getProgramSize();

    final StringBuilder builder = new StringBuilder(300);
    printPrefix(builder);
    builder
        .append(": Delta node (#leaves=")
        .append(event.getNode().getLeafTokenCount())
        .append(")");
    builder.append(": queue=").append(event.getRemainingQueueSize());
    builder.append(", delete ").append(nodeSize - programSize).append(" tokens");
    builder
        .append(", ratio=")
        .append(programSize)
        .append("/")
        .append(initialProgramSize)
        .append("=")
        .append(Util.computePercentage(programSize, initialProgramSize));
    logger.atInfo().log(builder.toString());
  }

  private StringBuilder printPrefix(StringBuilder builder) {
    builder.append("Fixpoint[").append(fixpointIteration).append("]");
    builder.append(":Reducer[").append(reducerName).append("]");
    return builder;
  }
}
