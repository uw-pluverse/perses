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

import com.google.common.base.Strings
import org.perses.reduction.event.AbstractTestScriptExecutionEvent
import org.perses.reduction.event.ReductionEndEvent
import org.perses.util.FileStreamPool
import java.util.concurrent.ConcurrentLinkedQueue

/** Records the test script executions.  */
class TestScriptExecutionListener(
  private val printStream: FileStreamPool.ManagedPrintStream,
) : DefaultReductionListener() {
  private val statisticsList = ConcurrentLinkedQueue<ExecutionStatistics>()
  override fun onTestScriptExecution(
    event: AbstractTestScriptExecutionEvent.TestScriptExecutionEvent,
  ) {
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

  override fun close() {
    printStream.close()
  }

  override fun onReductionEnd(event: ReductionEndEvent) {
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
    val stream = printStream
    stream.println("# summary of test script executions.")
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

  private class ExecutionStatistics(
    val milliSeconds: Long,
    val result: Boolean,
    val programSize: Int,
  )

  companion object {
    private fun printStatistics(stream: FileStreamPool.ManagedPrintStream, vararg values: Any) {
      var isFirst = true
      for (value in values) {
        if (isFirst) {
          isFirst = false
        } else {
          stream.printf(" \t ")
        }
        stream.print(Strings.padStart(value.toString(), 15, ' '))
      }
      stream.println()
    }
  }
}
