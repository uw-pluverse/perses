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

import org.perses.reduction.event.FixpointIterationEndEvent
import org.perses.reduction.event.FixpointIterationStartEvent
import org.perses.reduction.event.LevelGranularityReductionEndEvent
import org.perses.reduction.event.LevelGranularityReductionStartEvent
import org.perses.reduction.event.LevelReductionEndEvent
import org.perses.reduction.event.LevelReductionStartEvent
import org.perses.reduction.event.NodeReductionEndEvent
import org.perses.reduction.event.NodeReductionStartEvent
import org.perses.reduction.event.ReductionEndEvent
import org.perses.reduction.event.ReductionStartEvent
import org.perses.util.TimeSpan
import org.perses.util.TimeSpan.Builder.Companion.start
import java.io.BufferedWriter
import java.io.IOException
import java.io.ObjectOutputStream
import java.io.Serializable
import java.io.UncheckedIOException
import java.nio.file.Files
import java.nio.file.Path
import java.util.Date
import kotlin.io.path.name
import kotlin.io.path.outputStream

class ReductionProfileListener(textualFile: Path) : DefaultReductionListener(), Serializable {
  private val comments: MutableMap<String, String>
  private var timeSpanBuilder: TimeSpan.Builder? = null
  private var textualWriter: BufferedWriter? = null
  private var eventStream: ObjectOutputStream? = null
  override fun onReductionStart(event: ReductionStartEvent) {
    timeSpanBuilder = start(event.currentTimeMillis)
  }

  override fun onReductionEnd(event: ReductionEndEvent) {
    val time = timeSpanBuilder!!.end(event.currentTimeMillis)
    timeSpanBuilder = null
    val textualWriter = this.textualWriter!!
    textualWriter.append("\n\n")
    textualWriter
      .append("reduction started at ")
      .append(Date(time.startTimeMillis).toString())
      .append('\n')
    textualWriter
      .append("          finished at ")
      .append(Date(time.endTimeMillis).toString())
      .append('\n')
    textualWriter.append("elapsed time is ").append(time.formattedElaspedTime).append('\n')
    textualWriter.append('\n')
    for ((key, value) in comments) {
      textualWriter
        .append("====================Comment (")
        .append(key)
        .append(")====================\n")
      textualWriter.append(value)
      textualWriter.append('\n').append('\n')
    }
    textualWriter.close()
    eventStream!!.close()
  }

  private fun saveEvent(event: IProfileEvent) {
    try {
      textualWriter!!.append(event.toString()).append('\n')
      eventStream!!.writeObject(event)
    } catch (e: IOException) {
      throw UncheckedIOException(e)
    }
  }

  override fun onFixpointIterationStart(event: FixpointIterationStartEvent) {
    val fixpointEvent = IProfileEvent.FixpointIterationEvent(
      event.programSize,
      true,
    )
    saveEvent(fixpointEvent)
  }

  override fun onFixpointIterationEnd(event: FixpointIterationEndEvent) {
    saveEvent(IProfileEvent.FixpointIterationEvent(event.programSize, false))
  }

  override fun onLevelReductionStart(event: LevelReductionStartEvent) {
    saveEvent(
      IProfileEvent.LevelReductionEvent(event.programSize, true, event.level),
    )
  }

  override fun onLevelReductionEnd(event: LevelReductionEndEvent) {
    saveEvent(
      IProfileEvent.LevelReductionEvent(event.programSize, false, event.level),
    )
  }

  override fun onLevelGranularityReductionStart(event: LevelGranularityReductionStartEvent) {
    saveEvent(
      IProfileEvent.GranularityEvent(
        event.programSize,
        true,
        event.maxNumOfNodesPerPartition,
      ),
    )
  }

  override fun onLevelGranularityReductionEnd(event: LevelGranularityReductionEndEvent) {
    saveEvent(
      IProfileEvent.GranularityEvent(
        event.programSize,
        false,
        event.maxNumOfNodesPerPartition,
      ),
    )
  }

  fun addComment(name: String, comment: String) {
    comments[name] = comment
  }

  override fun onNodeReductionStart(event: NodeReductionStartEvent) {
    throw UnsupportedOperationException()
  }

  override fun onNodeReductionEnd(event: NodeReductionEndEvent) {
    throw UnsupportedOperationException()
  }

  init {
    comments = HashMap()
    try {
      textualWriter = Files.newBufferedWriter(textualFile)
      eventStream = ObjectOutputStream(
        textualFile.parent.resolve(textualFile.name + ".event").outputStream(),
      )
    } catch (e: IOException) {
      throw UncheckedIOException(e)
    }
  }
}
