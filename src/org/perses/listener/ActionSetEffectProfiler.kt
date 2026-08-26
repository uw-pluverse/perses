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

import org.perses.program.ProgramSize
import org.perses.reduction.event.AbstractTestScriptExecutionEvent.TestScriptExecutionEvent
import org.perses.util.FileStreamPool
import org.perses.util.Serialization
import org.perses.util.StringUtil

class ActionSetEffectProfiler(
  stream: FileStreamPool.ManagedPrintStream,
) : AbstractProgressMonitor(stream) {
  private val snapshots = mutableListOf<Snapshot>()

  override fun onTestScriptExecution(event: TestScriptExecutionEvent) {
    val result = event.result
    val edit = event.edit
    val actionSet = edit.actionSet
    snapshots.add(
      Snapshot(
        interesting = result.isInteresting,
        contextDescription = actionSet.contextDescription,
        actions = actionSet.actions.map { it.conciseDescription },
        originalProgramSize = edit.tokenCountBeforeEdit.withoutPayload(),
        newProgramSize = edit.program.tokenCount,
      ),
    )
  }

  override fun close() {
    try {
      stream.println(Serialization.toYamlString(snapshots.filter { it.interesting }))

      snapshots
        .groupBy { it.contextDescription }
        .entries
        .map { entry ->
          entry.key to entry.value.partition { it.interesting }
        }.sortedByDescending { entry ->
          entry.second.first.size
        }.forEach { (contextDescription, snapshots) ->
          val interesting = snapshots.first
          val uninteresting = snapshots.second
          val interestingSize = interesting.size
          val uninterestingSize = uninteresting.size
          val total = interestingSize + uninterestingSize
          val percentage =
            StringUtil
              .computePercentage(
                interestingSize,
                total,
                prefix = "",
              ).padStart(7, ' ')
          val message =
            buildString {
              append("Interesting=").append(padNumber(interestingSize)).append(',')
              append("Uninteresting=").append(padNumber(uninterestingSize)).append(',')
              append("Total=").append(padNumber(total)).append(',')
              append(percentage).append(". ").append(contextDescription)
            }
          stream.println(message)
        }
    } finally {
      // Make sure the stream can be closed by the parent class.
      super.close()
    }
  }

  private fun padNumber(i: Int) = i.toString().padEnd(4, ' ')

  data class Snapshot(
    val interesting: Boolean,
    val contextDescription: String,
    val actions: List<String>,
    val newProgramSize: Int,
    val originalProgramSize: ProgramSize<Unit>,
  )
}
