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

import com.google.common.flogger.FluentLogger
import org.perses.reduction.event.AbstractEndEvent
import org.perses.reduction.event.AbstractStartEvent
import org.perses.reduction.event.BestProgramUpdateEvent
import org.perses.reduction.event.FixpointIterationEndEvent
import org.perses.reduction.event.FixpointIterationStartEvent
import org.perses.reduction.event.LevelGranularityReductionEndEvent
import org.perses.reduction.event.LevelGranularityReductionStartEvent
import org.perses.reduction.event.LevelReductionEndEvent
import org.perses.reduction.event.LevelReductionStartEvent
import org.perses.reduction.event.NodeReductionEndEvent
import org.perses.reduction.event.NodeReductionStartEvent
import org.perses.reduction.event.ReductionEndEvent
import org.perses.reduction.event.ReductionSkippedEvent
import org.perses.reduction.event.ReductionStartEvent
import org.perses.reduction.event.TokenSlicingEndEvent
import org.perses.reduction.event.TokenSlicingStartEvent
import org.perses.util.TimeSpan.Builder.Companion.start
import org.perses.util.TimeUtil.formatDateForDisplay
import org.perses.util.Util.computePercentage
import org.perses.util.ktInfo

/** A logging listener to print the progress of reduction.  */
class LoggingListener : DefaultReductionListener() {
  override fun onReductionStart(event: ReductionStartEvent) {
    logger.ktInfo {
      "Reduction Started at ${formatDateForDisplay(event.currentTimeMillis)}"
    }
  }

  override fun onReductionEnd(event: ReductionEndEvent) {
    val timeSpan = start(event.startEvent.currentTimeMillis)
      .end(event.currentTimeMillis)
    val finalProgramSize = event.programSize
    logger.ktInfo {
      "Reduction ended at ${formatDateForDisplay(timeSpan.endTimeMillis)}"
    }
    logger.ktInfo { "Elapsed time is ${timeSpan.formattedElaspedTime}" }
    val initialProgramSize = event.startEvent.programSize
    logger.ktInfo {
      "Removed ${initialProgramSize - finalProgramSize} token(s). Reduction ratio is " +
        "$finalProgramSize/$initialProgramSize=${
          computePercentage(
            finalProgramSize,
            initialProgramSize,
          )
        }"
    }
    logger.ktInfo {
      "Test script execution count: " +
        event.testScriptExecutorServiceStatistics.scriptExecutionNumber
    }
  }

  override fun onFixpointIterationStart(event: FixpointIterationStartEvent) {
    val info = logger.atInfo()
    if (!info.isEnabled) {
      return
    }
    val builder = createStingBuilderWithPrefix(event.reducerClass.shortName, event.iteration)
    builder.append(": New fixpoint iteration started. #Tokens=").append(event.programSize)
    info.log(builder.toString())
  }

  override fun onFixpointIterationEnd(event: FixpointIterationEndEvent) {
    val info = logger.atInfo()
    if (!info.isEnabled) {
      return
    }
    val builder = createStingBuilderWithPrefix(
      event.startEvent.reducerClass.shortName,
      event.startEvent.iteration,
    )
    builder.append(": Fixpoint iteration finished, ")
    printNumOfDeletedTokens(builder, event)
    builder.append(", ")
    printReductionSizeRatio(builder, event)
    info.log(builder.toString())
  }

  override fun onLevelReductionStart(event: LevelReductionStartEvent) {
    val info = logger.atInfo()
    if (!info.isEnabled) {
      return
    }
    val builder = createStingBuilderWithPrefix(
      event.currentFixpointIteration.reducerClass.shortName,
      event.currentFixpointIteration.iteration,
    )
    builder
      .append("Reduction at level ")
      .append(event.level)
      .append(", #nodes=")
      .append(event.nodeCountOnLevel)
  }

  override fun onLevelReductionEnd(event: LevelReductionEndEvent) {
    val info = logger.atInfo()
    if (!info.isEnabled) {
      return
    }
    val builder = createStingBuilderWithPrefix(
      event.startEvent.currentFixpointIteration.reducerClass.shortName,
      event.iteration,
    )
    builder.append(":Reduction on level ").append(event.level)
    builder.append(": ")
    printNumOfDeletedTokens(builder, event)
    builder.append(", ")
    printReductionSizeRatio(builder, event)
    info.log(builder.toString())
  }

  override fun onLevelGranularityReductionStart(event: LevelGranularityReductionStartEvent) {}
  override fun onLevelGranularityReductionEnd(event: LevelGranularityReductionEndEvent) {
    val info = logger.atInfo()
    if (!info.isEnabled) {
      return
    }
    val builder = createStingBuilderWithPrefix(
      event
        .startEvent
        .levelReductionStartEvent
        .currentFixpointIteration
        .reducerClass
        .shortName,
      event.iteration,
    )
    builder.append(": Delta with granularity ").append(event.maxNumOfNodesPerPartition)
    builder.append(": ")
    printNumOfDeletedTokens(builder, event)
    builder.append(", ")
    printReductionSizeRatio(builder, event)
    info.log(builder.toString())
  }

  override fun onSlicingTokensStart(event: TokenSlicingStartEvent) {}
  override fun onSlicingTokensEnd(event: TokenSlicingEndEvent) {
    if (!logger.atInfo().isEnabled) {
      return
    }
    val builder = createStingBuilderWithPrefix(event.reducerName, event.iteration)
    builder.append(": granularity=").append(event.startEvent.tokenSliceGranularity)
    builder.append(", ")
    printNumOfDeletedTokens(builder, event)
    builder.append(", ")
    printReductionSizeRatio(builder, event)
    logger.atInfo().log("%s", builder)
  }

  override fun onNodeReductionStart(event: NodeReductionStartEvent) {
    val info = logger.atInfo()
    if (!info.isEnabled) {
      return
    }
    val builder = createStingBuilderWithPrefix(event.getReducerName(), event.iteration)
    builder
      .append(": Reduce node (#leaves=")
      .append(event.node.leafTokenCount)
      .append(")")
    info.log(builder.toString())
  }

  override fun onNodeReductionEnd(event: NodeReductionEndEvent) {
    val info = logger.atInfo()
    if (!info.isEnabled) {
      return
    }
    val fixpointIteration = event.startEvent.currentFixpointIteration
    val builder = createStingBuilderWithPrefix(
      fixpointIteration.reducerClass.shortName,
      fixpointIteration.iteration,
    )
    builder
      .append(": Reduce node (#leaves=")
      .append(event.node.leafTokenCount)
      .append(")")
    builder.append(": queue=").append(event.remainingQueueSize)
    builder.append(", ")
    printNumOfDeletedTokens(builder, event)
    builder.append(", ")
    printReductionSizeRatio(builder, event)
    info.log(builder.toString())
  }

  override fun onReductionSkipped(event: ReductionSkippedEvent) {
    val info = logger.atInfo()
    if (!info.isEnabled) {
      return
    }
    val fixpointIteration = event.currentFixpointIteration
    val builder = createStingBuilderWithPrefix(
      fixpointIteration.reducerClass.shortName,
      fixpointIteration.iteration,
    )
    builder.append(": Reduction is skipped. Cause:  ").append(event.message)
    info.log(builder.toString())
  }

  override fun onBestProgramUpdated(event: BestProgramUpdateEvent) {
    val info = logger.atInfo()
    if (!info.isEnabled) {
      return
    }
    val fixpointIteration = event.currentFixpointIteration
    val builder = createStingBuilderWithPrefix(
      fixpointIteration.reducerClass.shortName,
      fixpointIteration.iteration,
    )
    builder.append(": New minimal, ")
    printNumOfDeletedTokens(builder, event.programSizeBefore, event.programSize)
    builder.append(", ")
    printReductionSizeRatio(builder, event.initialProgramSize(), event.programSize)
    info.log(builder.toString())
  }

  private fun createStingBuilderWithPrefix(
    reducerName: String,
    fixpointIteration: Int,
  ): StringBuilder {
    val builder = StringBuilder(150)
    builder.append("Fixpoint[").append(fixpointIteration).append("]")
    builder.append(":Reducer[").append(reducerName).append("]")
    return builder
  }

  private fun printNumOfDeletedTokens(
    builder: StringBuilder,
    endEvent: AbstractEndEvent<out AbstractStartEvent>,
  ): StringBuilder {
    val programSizeBefore = endEvent.startEvent.programSize
    val programSizeAfter = endEvent.programSize
    return printNumOfDeletedTokens(builder, programSizeBefore, programSizeAfter)
  }

  private fun printNumOfDeletedTokens(
    builder: StringBuilder,
    programSizeBefore: Int,
    programSizeAfter: Int,
  ): StringBuilder {
    return builder.append("delete ").append(programSizeBefore - programSizeAfter).append(" tokens")
  }

  private fun printReductionSizeRatio(
    builder: StringBuilder,
    endEvent: AbstractEndEvent<out AbstractStartEvent>,
  ): StringBuilder {
    val newProgramSize = endEvent.programSize
    val initialProgramSize = endEvent.initialProgramSize()
    return printReductionSizeRatio(builder, initialProgramSize, newProgramSize)
  }

  private fun printReductionSizeRatio(
    builder: StringBuilder,
    initialProgramSize: Int,
    newProgramSize: Int,
  ): StringBuilder {
    return builder
      .append("ratio=")
      .append(newProgramSize)
      .append("/")
      .append(initialProgramSize)
      .append("=")
      .append(computePercentage(newProgramSize, initialProgramSize))
  }

  companion object {
    private val logger = FluentLogger.forEnclosingClass()
  }
}
