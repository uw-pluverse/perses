/*
 * Copyright (C) 2018-2022 University of Waterloo.
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
import org.perses.program.printer.PrinterRegistry.printToString
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
import java.io.IOException
import java.io.PrintStream
import java.nio.charset.StandardCharsets
import java.nio.file.Path

/** Note that this listener will NOT close the stream. The client needs to close it manually.  */
class ProgressMonitorForNodeReducer private constructor(
  private val resultFile: Path?
) : DefaultReductionListener() {
  private var beforeSize = 0
  private var stream: PrintStream? = null
  private var testSuccessCount = 0
  private var testFailureCount = 0
  private var testResultCacheHitCount = 0
  private var testExcecutionCancelled = 0
  private var nodeEditActionSetCacheHitCount = 0
  override fun onReductionStart(event: ReductionStartEvent) {
    stream = if (resultFile != null) {
      try {
        PrintStream(resultFile.toFile(), StandardCharsets.UTF_8.name())
      } catch (e: IOException) {
        throw RuntimeException(e)
      }
    } else {
      System.out
    }
    printBegin("Reduction starts")
    stream!!.println("The spar tree is the following.")
    val treeOrNull = event.tree.get()
    requireNotNull(treeOrNull)
    stream!!.println(treeOrNull.printTreeStructure().trim())
    printEnd()
  }

  override fun onReductionEnd(event: ReductionEndEvent) {
    stream!!.printf("#test success = %d\n", testSuccessCount)
    stream!!.printf("#test failure = %d\n", testFailureCount)
    stream!!.printf("#test result cache hits = %d\n", testResultCacheHitCount)
    stream!!.printf("#test execution cancelled = %d\n", testExcecutionCancelled)
    stream!!.printf("#node edit action set cache hits = %d\n", nodeEditActionSetCacheHitCount)
    if (stream !== System.out) {
      stream!!.close()
      stream = null
    }
  }

  override fun onTestScriptExecution(event: TestScriptExecutionEvent) {
    val result = event.result
    val edit = event.edit
    printBegin("Testing the following program: " + if (result.isInteresting) "pass" else "fail")
    stream!!.printf(
      "// edit action set type: %s\n", event.edit.actionSet.actionsDescription
    )
    printCode(
      printToString(
        edit.program,
        edit.program.factory.languageKind.origCodeFormatControl
      ).trim()
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
      stream!!.printf("    %s\n", action.description)
    }
    printEnd()
    ++nodeEditActionSetCacheHitCount
  }

  override fun onNodeActionSetCacheClearance(event: NodeEditActionSetCacheClearanceEvent) {
    printBegin("Node edit action set cache is cleared.")
    stream!!.printf("    size before clearance = %d\n", event.originalEntrySize)
    printEnd()
  }

  override fun onTestResultCacheHit(event: TestResultCacheHitEvent) {
    val result = event.result
    printBegin(
      "Cache hit for the following program: " + if (result.isInteresting) "pass" else "fail"
    )
    printCode(
      printToString(
        event.edit.program,
        event
          .edit
          .program
          .factory
          .languageKind
          .origCodeFormatControl
      ).trim()
    )
    printEnd()
    ++testResultCacheHitCount
  }

  override fun onTestScriptExecutionCancelled(event: TestScriptExecutionCanceledEvent) {
    printBegin("Test script execution is cancelled.")
    stream!!.printf(
      "It took %s than 1 second to cancel the task.\n\n",
      if (event.millisToCancelTheTask <= 1000) "less" else "more"
    )
    printCode(
      printToString(
        event.program,
        event.program.factory.languageKind.origCodeFormatControl
      ).trim()
    )
    printEnd()
    ++testExcecutionCancelled
  }

  override fun onNodeReductionStart(event: NodeReductionStartEvent) {
    val node = event.node
    val programSize = event.programSize
    val tree = event.tree
    printBegin(String.format("Reducing node %d, size=%d", node.nodeId, programSize))
    beforeSize = programSize
    stream!!.println("The current best program is the following\n")
    printCode(
      printToString(
        tree.programSnapshot,
        tree.programSnapshot.factory.languageKind.origCodeFormatControl
      ).trim()
    )
    printEnd()
  }

  override fun onNodeReductionEnd(event: NodeReductionEndEvent) {
    printBegin("Node reduction is done")
    val programSize = event.programSize
    val node = event.node
    if (beforeSize > programSize) {
      stream!!.printf(
        "Succeeded to reduce node %d from %d to %d\n",
        node.nodeId, beforeSize, programSize
      )
    } else {
      stream!!.printf("Failed to reduce node %d\n", node.nodeId)
    }
    printEnd()
  }

  override fun onTestScriptExecutionCacheEntryEviction(
    event: TestScriptExecutionCacheEntryEvictionEvent
  ) {
    printBegin("TestScriptExecutionCacheEntryEviction")
    stream!!.printf(
      "%d entries are removed: %d --> %d.\n",
      event.sizeBefore - event.sizeAfter, event.sizeBefore, event.sizeAfter
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
    stream!!.println(builder.toString())
    stream!!.println()
  }

  private fun printEnd() {
    stream!!.println(PROGRAM_END_MARKER)
    stream!!.println("\n")
  }

  private fun printCode(code: String) {
    Splitter.on('\n').omitEmptyStrings().split(code).forEach {
      if (it.isNotBlank()) {
        stream!!.println("    $it")
      }
    }
  }

  companion object {
    fun createForFile(resultFile: Path): ProgressMonitorForNodeReducer {
      return ProgressMonitorForNodeReducer(resultFile)
    }

    fun createForSystemOut(): ProgressMonitorForNodeReducer {
      return ProgressMonitorForNodeReducer(null)
    }

    private val PROGRAM_END_MARKER = Strings.padEnd("", 60, '-')
  }
}
