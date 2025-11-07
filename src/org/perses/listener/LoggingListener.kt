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
package org.perses.listener

import com.google.common.flogger.FluentLogger
import org.perses.reduction.AbstractReductionListener
import org.perses.reduction.event.AbstractEndEvent
import org.perses.reduction.event.AbstractStartEvent
import org.perses.reduction.event.AdHocMessageEvent
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
import org.perses.reduction.event.SanityCheckEvent
import org.perses.reduction.event.TokenSlicingEndEvent
import org.perses.reduction.event.TokenSlicingStartEvent
import org.perses.util.TimeSpan.Builder.Companion.start
import org.perses.util.TimeUtil.formatDateForDisplay
import org.perses.util.Util.computePercentage
import org.perses.util.ktInfo

/** A logging listener to print the progress of reduction.  */
class LoggingListener(
  val hideTimestamps: Boolean,
) : AbstractReductionListener() {
  override fun onReductionStart(event: ReductionStartEvent) {
    logger.ktInfo {
      "Reduction Started. #tokens=${event.programSize} extraData=${event.extraData}"
    }
  }

  override fun onReductionEnd(event: ReductionEndEvent) {
    val finalProgramSize = event.programSize
    if (!hideTimestamps) {
      val timeSpan =
        start(event.startEvent.currentTimeMillis)
          .end(event.currentTimeMillis)
      logger.ktInfo {
        "Reduction ended at ${formatDateForDisplay(timeSpan.endTimeMillis)}"
      }
      logger.ktInfo { "Elapsed time is ${timeSpan.formattedElapsedTime}" }
    }
    val initialProgramSize = event.startEvent.programSize
    logger.ktInfo {
      "Removed ${initialProgramSize - finalProgramSize} token(s). Reduction ratio is " +
        computePercentage(
          finalProgramSize,
          initialProgramSize,
        )
    }
    logger.ktInfo {
      "Test script execution count: " +
        event.testScriptExecutorServiceStatistics.scriptExecutionNumber
    }
  }

  override fun notifyNumOfLexemesInPersesTokenFactory(numOfLexemes: Int) {
    logger.ktInfo { "The number of lexemes in PersesTokenFactory is $numOfLexemes" }
  }

  override fun onSanityCheck(event: SanityCheckEvent) {
    logger.ktInfo {
      "The sanity check result is: ${event.sanityCheckResult}"
    }
  }

  override fun onAdHocMessageEvent(event: AdHocMessageEvent) {
    logger.ktInfo {
      buildString {
        event.prefixLabelFromRootToHere.let { prefix ->
          if (prefix.isNotBlank()) {
            append(event.prefixLabelFromRootToHere).append(' ')
          }
        }
        append(event.message)
      }
    }
  }

  override fun onFixpointIterationStart(event: FixpointIterationStartEvent) {
    val info = logger.atInfo()
    if (!info.isEnabled) {
      return
    }
    val builder = StringBuilder().append(event.prefixLabelFromRootToHere)
    builder.append(" New fixpoint iteration started. #Tokens=").append(event.programSize)
    info.log(builder.toString())
  }

  override fun onFixpointIterationEnd(event: FixpointIterationEndEvent) {
    val info = logger.atInfo()
    if (!info.isEnabled) {
      return
    }
    val builder = StringBuilder().append(event.prefixLabelFromRootToHere)
    builder.append(" Fixpoint iteration finished, ")
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
    val builder = StringBuilder().append(event.prefixLabelFromRootToHere)
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
    val builder = StringBuilder().append(event.prefixLabelFromRootToHere)
    builder.append(" Reduction on level ").append(event.level)
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
    val builder = StringBuilder().append(event.prefixLabelFromRootToHere)
    builder.append(" Delta with granularity ").append(event.maxNumOfNodesPerPartition)
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
    val builder = StringBuilder().append(event.prefixLabelFromRootToHere)
    builder.append(" granularity=").append(event.startEvent.tokenSliceGranularity)
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
    val builder = StringBuilder().append(event.prefixLabelFromRootToHere)
    with(builder) {
      append(" Reduce ").append(event.nodeInfo)
    }
    info.log(builder.toString())
  }

  override fun onNodeReductionEnd(event: NodeReductionEndEvent) {
    val info = logger.atInfo()
    if (!info.isEnabled) {
      return
    }
    val builder = StringBuilder().append(event.prefixLabelFromRootToHere)
    builder.append(" Finished node ").append(event.nodeInfo.nodeId)
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
    val builder = StringBuilder().append(event.prefixLabelFromRootToHere)
    builder.append(" Reduction is skipped. Cause:  ").append(event.message)
    info.log(builder.toString())
  }

  override fun onBestProgramUpdated(event: BestProgramUpdateEvent) {
    val info = logger.atInfo()
    if (!info.isEnabled) {
      return
    }
    val builder = StringBuilder().append(event.prefixLabelFromRootToHere)
    builder.append(" New minimal, ")
    printNumOfDeletedTokens(builder, event.programSizeBefore, event.programSize)
    builder.append(", ")
    printReductionSizeRatio(builder, event.initialProgramSize(), event.programSize)
    info.log(builder.toString())
  }

  override fun notifyCacheSettings(
    queryCacheEnabled: Boolean,
    editCacheEnabled: Boolean,
    queryCacheType: String,
  ) {
    logger.ktInfo {
      val queryCacheStatus = boolToString(queryCacheEnabled)
      val editCacheStatus = boolToString(editCacheEnabled)
      val queryCacheType = queryCacheType
      "Cache setting: query-caching=$queryCacheStatus, " +
        "edit-caching=$editCacheStatus, query-cache-type=$queryCacheType"
    }
  }

  fun boolToString(value: Boolean) = if (value) "enabled" else "disabled"

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
  ): StringBuilder =
    builder.append("delete ").append(programSizeBefore - programSizeAfter).append(" tokens")

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
  ): StringBuilder =
    builder
      .append("ratio=")
      .append(computePercentage(newProgramSize, initialProgramSize))

  override fun close() {
    // Do nothing.
  }

  companion object {
    private val logger = FluentLogger.forEnclosingClass()
  }
}
