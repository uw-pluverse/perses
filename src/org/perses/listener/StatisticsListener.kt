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

import com.google.common.annotations.VisibleForTesting
import com.google.common.collect.ImmutableList
import org.perses.reduction.event.FixpointIterationEndEvent
import org.perses.reduction.event.FixpointIterationStartEvent
import org.perses.reduction.event.ReductionEndEvent
import org.perses.util.FileStreamPool
import org.perses.util.Util.lazyAssert

/** Collects the statistics of reduction.  */
class StatisticsListener(
  private val fileStream: FileStreamPool.ManagedPrintStream,
) : DefaultReductionListener() {
  private val iterations = ArrayList<ReductionIterationStatistics>()

  override fun onFixpointIterationStart(event: FixpointIterationStartEvent) {
    val newStat = ReductionIterationStatistics(
      event.iteration.toString(),
      event.programSize,
      event.currentTimeMillis,
    )
    iterations.add(newStat)
  }

  override fun onFixpointIterationEnd(event: FixpointIterationEndEvent) {
    lazyAssert({ iterations.isNotEmpty() }) { "The iterations list is empty." }
    val currentStat = iterations.last()
    lazyAssert({ currentStat.iteration == event.startEvent.iteration.toString() }) {
      "The current iteration statistics does not match the current iteration: iteration in stat=" +
        currentStat.iteration +
        ", current iteration=" +
        event.startEvent.iteration
    }
    currentStat.endTimeMillis = event.currentTimeMillis
    currentStat.afterProgramSize = event.programSize
    currentStat.countOfTestScriptExecutions = event.countOfTestScriptExecutions
  }

  override fun onReductionEnd(event: ReductionEndEvent) {
    printHumanReadableResult(fileStream)
    fileStream.println()
    fileStream.printf("iterations=%d\n", iterations.size)
    for (iteration in iterations) {
      writeProperty(
        fileStream,
        "program_size_before",
        iteration.iteration,
        iteration.beforeProgramSize.toLong(),
      )
      writeProperty(
        fileStream,
        "program_size_after",
        iteration.iteration,
        iteration.afterProgramSize.toLong(),
      )
      writeProperty(
        fileStream,
        "elapsed_time_millis",
        iteration.iteration,
        iteration.elapsedTimeMillis(),
      )
      writeProperty(
        fileStream,
        "count_test_script_executions",
        iteration.iteration,
        iteration.countOfTestScriptExecutions.toLong(),
      )
      fileStream.println()
    }
  }

  override fun close() {
    fileStream.close()
  }

  private fun printHumanReadableResult(writer: FileStreamPool.ManagedPrintStream) {
    printHeader(writer)
    for (iteration in iterations) {
      printRow(
        writer,
        iteration.iteration,
        iteration.beforeProgramSize,
        iteration.afterProgramSize,
        iteration.elapsedTimeMillis(),
        iteration.countOfTestScriptExecutions,
      )
    }
    val totalStatistics = computeTotal()
    totalStatistics?.let {
      printRow(
        writer,
        "total",
        it.beforeProgramSize,
        it.afterProgramSize,
        it.elapsedTimeMillis(),
        it.countOfTestScriptExecutions,
      )
    }
  }

  private fun computeTotal(): ReductionIterationStatistics? {
    if (iterations.isEmpty()) {
      return null
    }
    val first = iterations[0]
    val last = iterations[iterations.size - 1]
    val result =
      ReductionIterationStatistics("total", first.beforeProgramSize, first.startTimeMillis)
    result.afterProgramSize = last.afterProgramSize
    result.countOfTestScriptExecutions =
      iterations.stream()
        .mapToInt { stat: ReductionIterationStatistics -> stat.countOfTestScriptExecutions }
        .sum()
    result.endTimeMillis = last.endTimeMillis
    return result
  }

  @VisibleForTesting
  class ReductionIterationStatistics(
    val iteration: String,
    val beforeProgramSize: Int,
    val startTimeMillis: Long,
  ) {
    var endTimeMillis: Long = 0
    var afterProgramSize = Int.MIN_VALUE
      set(value) {
        lazyAssert({ field == Int.MIN_VALUE }) { "can only set once" }
        field = value
      }
    var countOfTestScriptExecutions = Int.MIN_VALUE
      set(value) {
        lazyAssert({ field == Int.MIN_VALUE }) { "can only set once." }
        field = value
      }

    fun elapsedTimeMillis(): Long {
      return endTimeMillis - startTimeMillis
    }
  }

  companion object {
    private val COLUMN_NAMES = ImmutableList.of(
      "iteration",
      "before_size",
      "after_size",
      "removed_tokens",
      "time(ms)",
      "queries",
    )
    private val COLUMN_FORMAT = buildColumnFormat(
      COLUMN_NAMES.stream().mapToInt { obj: String -> obj.length }
        .max().asInt,
      COLUMN_NAMES.size,
    )

    private fun writeProperty(
      writer: FileStreamPool.ManagedPrintStream,
      name: String,
      iterationName: String,
      value: Long,
    ) {
      writer.printf("%s.%s=%d\n", name, iterationName, value)
    }

    private fun printHeader(writer: FileStreamPool.ManagedPrintStream) {
      writer.printf(
        COLUMN_FORMAT,
        COLUMN_NAMES[0],
        COLUMN_NAMES[1],
        COLUMN_NAMES[2],
        COLUMN_NAMES[3],
        COLUMN_NAMES[4],
        COLUMN_NAMES[5],
      )
    }

    private fun printRow(
      writer: FileStreamPool.ManagedPrintStream,
      iteration: String,
      beforeSize: Int,
      afterSize: Int,
      timeMillis: Long,
      queries: Int,
    ) {
      writer.printf(
        COLUMN_FORMAT,
        iteration,
        beforeSize.toString(),
        afterSize.toString(),
        (beforeSize - afterSize).toString(),
        timeMillis.toString(),
        queries.toString(),
      )
    }

    private fun buildColumnFormat(columnWidth: Int, columnCount: Int): String {
      lazyAssert { columnWidth > 0 }
      lazyAssert { columnCount > 0 }
      val builder = StringBuilder()
      builder.append("# ")
      var isFirst = true
      for (i in 0 until columnCount) {
        if (!isFirst) {
          builder.append("   ")
        } else {
          isFirst = false
        }
        builder.append("%" + columnWidth + "s")
      }
      builder.append("\n")
      return builder.toString()
    }
  }
}
