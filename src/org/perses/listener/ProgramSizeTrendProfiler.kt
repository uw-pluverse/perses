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

import com.fasterxml.jackson.annotation.JsonProperty
import com.fasterxml.jackson.annotation.JsonPropertyOrder
import com.fasterxml.jackson.module.kotlin.kotlinModule
import org.perses.PersesConstants
import org.perses.reduction.AbstractReductionListener
import org.perses.reduction.event.AbstractReductionEvent
import org.perses.reduction.event.BestProgramUpdateEvent
import org.perses.reduction.event.FixpointIterationEndEvent
import org.perses.reduction.event.ReductionEndEvent
import org.perses.reduction.event.ReductionStartEvent
import org.perses.util.FileStreamPool

class ProgramSizeTrendProfiler(
  private val stream: FileStreamPool.ManagedPrintStream,
) : AbstractReductionListener() {
  private val snapshots = mutableListOf<Snapshot>()

  override fun onReductionStart(event: ReductionStartEvent) {
    val isFirst = snapshots.isEmpty()
    val elapsedSeconds =
      if (isFirst) {
        0
      } else {
        computeElapsedSeconds(event)
      }
    val contextDescription =
      if (isFirst) {
        "<START>"
      } else {
        ""
      }
    snapshots.add(
      Snapshot(
        elapsedSeconds = elapsedSeconds,
        currentProgramSize = event.perFileSizeMetrics.totalCanonicalTokenCount,
        contextDescription = contextDescription,
      ),
    )
  }

  override fun onFixpointIterationEnd(event: FixpointIterationEndEvent) {
    snapshots.add(
      Snapshot(
        elapsedSeconds = computeElapsedSeconds(event),
        currentProgramSize = event.perFileSizeMetrics.totalCanonicalTokenCount,
        contextDescription = "<Fixpoint Iteration End>",
      ),
    )
  }

  override fun onReductionEnd(event: ReductionEndEvent) {
    snapshots.add(
      Snapshot(
        elapsedSeconds = computeElapsedSeconds(event),
        currentProgramSize = event.perFileSizeMetrics.totalCanonicalTokenCount,
        contextDescription = "<END>",
      ),
    )
  }

  override fun onBestProgramUpdated(event: BestProgramUpdateEvent) {
    snapshots.add(
      Snapshot(
        elapsedSeconds = computeElapsedSeconds(event),
        currentProgramSize = event.perFileSizeMetrics.totalCanonicalTokenCount,
        contextDescription = event.appliedEdit.actionSet.contextDescription,
      ),
    )
  }

  private fun computeElapsedSeconds(event: AbstractReductionEvent): Int =
    PersesConstants.computeElapsedSeconds(event.currentTimeMillis)

  override fun close() {
    stream.use { stream ->
      val mapper =
        com.fasterxml.jackson.dataformat.csv.CsvMapper().apply {
          registerModule(kotlinModule())
        }
      val schema = mapper.schemaFor(Snapshot::class.java).withHeader()
      val content = mapper.writer(schema).writeValueAsBytes(snapshots).toString(Charsets.UTF_8)
      stream.print(content)
    }
  }

  @JsonPropertyOrder("elapsed_seconds", "current_program_size", "action_description")
  private data class Snapshot(
    @field:JsonProperty("elapsed_seconds")
    val elapsedSeconds: Int,
    @field:JsonProperty("current_program_size")
    val currentProgramSize: Int,
    @field:JsonProperty("action_description")
    val contextDescription: String,
  )
}
