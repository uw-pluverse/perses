/*
 * Copyright (C) 2018-2026 University of Waterloo.
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

import org.perses.PersesConstants
import org.perses.listener.DifferentialEvents.NodeReductionEvent
import org.perses.reduction.AbstractReductionListener
import org.perses.reduction.TestScriptVerdict
import org.perses.reduction.event.AbstractTestScriptExecutionEvent.TestScriptExecutionEvent
import org.perses.reduction.event.NodeReductionEndEvent
import org.perses.util.FileStreamPool
import org.perses.util.Serialization
import org.perses.util.toImmutableList

class DifferentialAnalysisProfiler(
  private val stream: FileStreamPool.ManagedPrintStream,
  private val hideTimestamp: Boolean,
) : AbstractReductionListener() {
  private val events = mutableListOf<NodeReductionEvent>()

  private var editsTested = mutableListOf<DifferentialEvents.Edit>()

  override fun onNodeReductionEnd(event: NodeReductionEndEvent) {
    val startEvent = event.startEvent
    val before = startEvent.nodeInfo
    val after = event.nodeInfo
    val startPersesTimeSeconds: Int
    val endPersesTimeSeconds: Int
    if (hideTimestamp) {
      startPersesTimeSeconds = 0
      endPersesTimeSeconds = 0
    } else {
      startPersesTimeSeconds = PersesConstants.computeElapsedSeconds(startEvent.currentTimeMillis)
      endPersesTimeSeconds = PersesConstants.computeElapsedSeconds(event.currentTimeMillis)
    }
    events.add(
      NodeReductionEvent(
        fixpointIteration = event.startEvent.currentFixpointIteration.iteration,
        startPersesTimeSeconds = startPersesTimeSeconds,
        endPersesTimeSeconds = endPersesTimeSeconds,
        nodeId = before.nodeId,
        ruleName = before.antlrRuleName ?: "<null>",
        ruleType = before.ruleType,
        childrenBeforeReduction = before.childNodeIds,
        deletedTokenCount =
          startEvent.perFileSizeMetrics.totalCanonicalTokenCount -
            event.perFileSizeMetrics.totalCanonicalTokenCount,
        childrenAfterReduction = after.childNodeIds,
        editsTested = editsTested.toImmutableList(),
      ),
    )
    editsTested.clear()
  }

  override fun onTestScriptExecution(event: TestScriptExecutionEvent) {
    val edit = event.edit
    val propertyTestResult = event.result
    val deletedTokens =
      if (propertyTestResult.isInteresting) {
        edit.lazilyComputedDeletedTokens.sourceCode
      } else {
        "<uninteresting>"
      }
    val newPropertyTestResult =
      if (hideTimestamp) {
        if (propertyTestResult.isInteresting) {
          TestScriptVerdict.INTERESTING
        } else {
          TestScriptVerdict.NON_INTERESTING
        }
      } else {
        propertyTestResult
      }
    val startPersesTimeSeconds =
      if (hideTimestamp) {
        0
      } else {
        PersesConstants.computeElapsedSeconds(event.currentTimeMillis)
      }
    editsTested.add(
      DifferentialEvents.Edit(
        contextualDescription = edit.actionSet.contextDescription,
        structureDescription = edit.structureDescription,
        propertyTestResult = newPropertyTestResult,
        successfullyDeletedCode = deletedTokens,
        // TODO(cnsun): this is not accurate. We need to use canonical token count for the edit.
        deletedTokenCount = edit.tokenCountBeforeEdit.canonicalTokenCount - edit.program.tokenCount,
        startPersesTimeSeconds = startPersesTimeSeconds,
      ),
    )
  }

  override fun close() {
    stream.use { stream ->
      val content = Serialization.toYamlString(events)
      stream.print(content)
    }
  }

  companion object {
  }
}
