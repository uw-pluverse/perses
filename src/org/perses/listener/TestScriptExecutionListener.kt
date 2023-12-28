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

import com.google.common.base.Preconditions
import com.google.common.base.Strings
import org.perses.reduction.event.ReductionEndEvent
import org.perses.reduction.event.TestScriptExecutionEvent
import java.io.IOException
import java.io.PrintStream
import java.nio.file.Files
import java.nio.file.Path
import java.util.concurrent.ConcurrentLinkedQueue
import kotlin.io.path.absolute

/** Records the test script executions.  */
class TestScriptExecutionListener(summaryFile: Path) : DefaultReductionListener() {
  private val statisticsList = ConcurrentLinkedQueue<ExecutionStatistics>()
  private val summaryFile: Path = summaryFile.absolute()
  override fun onTestScriptExecution(event: TestScriptExecutionEvent) {
    val result = event.result
    val program = event.program
    statisticsList.add(
      ExecutionStatistics(
        result.elapsedMilliseconds,
        result.isInteresting,
        program.tokenCount(),
      ),
    )
  }

  override fun onReductionEnd(event: ReductionEndEvent) {
    try {
      var passCount = 0
      var passTime = 0
      var failCount = 0
      var failTime = 0
      for (executionStatistics in statisticsList) {
        if (executionStatistics.result) {
          ++passCount
          passTime += executionStatistics.milliSeconds.toInt()
        } else {
          ++failCount
          failTime += executionStatistics.milliSeconds.toInt()
        }
      }
      PrintStream(summaryFile.toFile()).use { stream ->
        stream.print("# summary of test script executions.\n")
        stream.printf("pass_count=%d\n", passCount)
        stream.printf("pass_total_time=%d\n", passTime)
        stream.printf("fail_count=%d\n", failCount)
        stream.printf("fail_total_time=%d\n", failTime)
        stream.print("\n\n\n===Details===\n")
        printStatistics(stream, "Time", "Result", "Size")
        statisticsList.stream()
          .filter { e: ExecutionStatistics -> e.result }
          .forEach { statistics: ExecutionStatistics ->
            printStatistics(
              stream,
              statistics.milliSeconds,
              statistics.result,
              statistics.programSize,
            )
          }
        statisticsList.stream()
          .filter { e: ExecutionStatistics -> !e.result }
          .forEach { statistics: ExecutionStatistics ->
            printStatistics(
              stream,
              statistics.milliSeconds,
              statistics.result,
              statistics.programSize,
            )
          }
      }
    } catch (e: IOException) {
      throw RuntimeException(e)
    }
  }

  private class ExecutionStatistics(
    val milliSeconds: Long,
    val result: Boolean,
    val programSize: Int,
  )

  companion object {
    private fun printStatistics(stream: PrintStream, vararg values: Any) {
      var isFirst = true
      for (value in values) {
        if (isFirst) {
          isFirst = false
        } else {
          stream.printf(" \t ")
        }
        stream.print(Strings.padStart(value.toString(), 15, ' '))
      }
      stream.print('\n')
    }
  }

  init {
    Preconditions.checkArgument(
      Files.exists(this.summaryFile.parent),
      "The folder of the file %s does not exist.",
      summaryFile,
    )
  }
}
