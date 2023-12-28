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

import com.google.common.base.Splitter
import com.google.common.base.Strings
import org.perses.program.printer.AbstractTokenizedProgramPrinter
import org.perses.reduction.event.FixpointIterationStartEvent
import org.perses.reduction.event.NodeEditActionSetCacheClearanceEvent
import org.perses.reduction.event.NodeEditActionSetCacheHitEvent
import org.perses.reduction.event.NodeReductionEndEvent
import org.perses.reduction.event.NodeReductionStartEvent
import org.perses.reduction.event.ReductionEndEvent
import org.perses.reduction.event.ReductionStartEvent
import org.perses.reduction.event.TestResultCacheHitEvent
import org.perses.reduction.event.TestScriptExecutionCacheEntryEvictionEvent
import org.perses.reduction.event.TestScriptExecutionCanceledEvent
import org.perses.reduction.event.TestScriptExecutionEvent
import org.perses.util.Util
import java.io.PrintStream
import java.nio.file.Path

/** Note that this listener will NOT close the stream. The client needs to close it manually.  */
class ProgressMonitorForNodeReducer private constructor(
  private val resultFile: Path?,
  private val appendMode: Boolean,
  private val printer: AbstractTokenizedProgramPrinter,
) : DefaultReductionListener() {
  private var beforeSize = 0
  private lateinit var stream: PrintStream
  private var testSuccessCount = 0
  private var testFailureCount = 0
  private var testResultCacheHitCount = 0
  private var testExcecutionCancelled = 0
  private var nodeEditActionSetCacheHitCount = 0
  override fun onReductionStart(event: ReductionStartEvent) {
    stream = if (resultFile != null) {
      if (appendMode) {
        Util.createAppendablePrintStream(resultFile)
      } else {
        Util.createNonAppendablePrintStream(resultFile)
      }
    } else {
      System.out
    }
    printBegin("Reduction starts.")
    stream.println("The initial program size is ${event.initialProgramSize()}")
    printEnd()
  }

  override fun onFixpointIterationStart(event: FixpointIterationStartEvent) {
    printBegin(
      "Fixpoint iteration ${event.iteration}. Reducer: ${event.reducerClass.shortName}",
    )
    stream.println("The spar-tree is the following.")
    stream.println(event.oudatedTreeDump.trim())
    printEnd()
  }

  override fun onReductionEnd(event: ReductionEndEvent) {
    stream.printf("#test success = %d\n", testSuccessCount)
    stream.printf("#test failure = %d\n", testFailureCount)
    stream.printf("#test result cache hits = %d\n", testResultCacheHitCount)
    stream.printf("#test execution cancelled = %d\n", testExcecutionCancelled)
    stream.printf("#node edit action set cache hits = %d\n", nodeEditActionSetCacheHitCount)
    stream.printf(
      "#external test execution cache hits = %d\n",
      event.testScriptExecutorServiceStatistics.externalCacheHitNumber,
    )
    if (stream !== System.out) {
      stream.close()
      stream = Util.ExceptionPrintStream
    }
  }

  override fun onTestScriptExecution(event: TestScriptExecutionEvent) {
    val result = event.result
    val edit = event.edit
    printBegin("Testing the following program: " + if (result.isInteresting) "pass" else "fail")
    stream.printf(
      "// edit action set type: %s\n",
      event.edit.actionSet.actionsDescription,
    )
    printCode(
      printer.print(
        edit.program,
      ).sourceCode.trim(),
    )
    printEnd()
    if (result.isInteresting) {
      ++testSuccessCount
    } else {
      ++testFailureCount
    }
  }

  override fun onNodeEditActionSetCacheHit(event: NodeEditActionSetCacheHitEvent) {
    printBegin("Node edit action set cache hit.")
    val query = event.query
    val actions = query.actions
    for (action in actions) {
      stream.printf("    %s\n", action.description)
    }
    printEnd()
    ++nodeEditActionSetCacheHitCount
  }

  override fun onNodeActionSetCacheClearance(event: NodeEditActionSetCacheClearanceEvent) {
    printBegin("Node edit action set cache is cleared.")
    stream.printf("    size before clearance = %d\n", event.originalEntrySize)
    printEnd()
  }

  override fun onTestResultCacheHit(event: TestResultCacheHitEvent) {
    val result = event.result
    printBegin(
      "Cache hit for the following program: " + if (result.isInteresting) "pass" else "fail",
    )
    printCode(
      printer.print(
        event.edit.program,
      ).sourceCode.trim(),
    )
    printEnd()
    ++testResultCacheHitCount
  }

  override fun onTestScriptExecutionCancelled(event: TestScriptExecutionCanceledEvent) {
    printBegin("Test script execution is cancelled.")
    stream.printf(
      "It took %s than 1 second to cancel the task.\n\n",
      if (event.millisToCancelTheTask <= 1000) "less" else "more",
    )
    printCode(
      printer.print(
        event.program,
      ).sourceCode.trim(),
    )
    printEnd()
    ++testExcecutionCancelled
  }

  override fun onNodeReductionStart(event: NodeReductionStartEvent) {
    val node = event.node
    val programSize = event.programSize
    val program = event.program
    printBegin(String.format("Reducing node %d, size=%d", node.nodeId, programSize))
    beforeSize = programSize
    stream.println("The current best program is the following\n")
    printCode(
      printer.print(
        program,
      ).sourceCode.trim(),
    )
    printEnd()
  }

  override fun onNodeReductionEnd(event: NodeReductionEndEvent) {
    printBegin("Node reduction is done")
    val programSize = event.programSize
    val node = event.node
    if (beforeSize > programSize) {
      stream.printf(
        "Succeeded to reduce node %d from %d to %d\n",
        node.nodeId,
        beforeSize,
        programSize,
      )
    } else {
      stream.printf("Failed to reduce node %d\n", node.nodeId)
    }
    printEnd()
  }

  override fun onTestScriptExecutionCacheEntryEviction(
    event: TestScriptExecutionCacheEntryEvictionEvent,
  ) {
    printBegin("TestScriptExecutionCacheEntryEviction")
    stream.printf(
      "%d entries are removed: %d --> %d.\n",
      event.sizeBefore - event.sizeAfter,
      event.sizeBefore,
      event.sizeAfter,
    )
    printEnd()
  }

  private fun printBegin(section: String) {
    val length = PROGRAM_END_MARKER.length
    val paddingLength = ((length - section.length) / 2).coerceAtLeast(1)
    val padding = Strings.padEnd("", paddingLength, '=')
    val builder = StringBuilder()
    builder.append(padding)
    builder.append(section)
    while (builder.length < length) {
      builder.append('=')
    }
    stream.println(builder.toString())
    stream.println()
  }

  private fun printEnd() {
    stream.println(PROGRAM_END_MARKER)
    stream.println("\n")
  }

  private fun printCode(code: String) {
    Splitter.on('\n').omitEmptyStrings().split(code).forEach {
      if (it.isNotBlank()) {
        stream.println("    $it")
      }
    }
  }

  companion object {
    fun createForFile(
      resultFile: Path,
      appendMode: Boolean,
      printer: AbstractTokenizedProgramPrinter,
    ): ProgressMonitorForNodeReducer {
      return ProgressMonitorForNodeReducer(resultFile, appendMode, printer)
    }

    fun createForSystemOut(
      printer: AbstractTokenizedProgramPrinter,
    ): ProgressMonitorForNodeReducer {
      return ProgressMonitorForNodeReducer(null, appendMode = true, printer)
    }

    private val PROGRAM_END_MARKER = Strings.padEnd("", 60, '-')
  }
}
