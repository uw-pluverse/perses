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

import java.io.Serializable

interface IProfileEvent : Serializable {
  val timeInMilliseconds: Long

  abstract class AbstractProfileEvent protected constructor(
    val programSize: Int,
    val isStartEvent: Boolean,
  ) :
    IProfileEvent {
    val eventId: Int = ++EVENT_ID_SEQ
    override val timeInMilliseconds: Long = System.currentTimeMillis()
    override fun toString(): String {
      val klassName = this::class.java.simpleName
      return buildString {
        append(klassName).append('\t')
        append(if (isStartEvent) "[Start]" else "[End]").append('\t')
        append("time=").append(timeInMilliseconds).append('\t')
        append("tokenCount=").append(programSize).append('\t')
        specificPropertiesToString(this)
      }
    }

    protected abstract fun specificPropertiesToString(builder: StringBuilder)

    companion object {
      private var EVENT_ID_SEQ = -1
    }
  }

  class FixpointIterationEvent(programSize: Int, isStartEvent: Boolean) :
    AbstractProfileEvent(programSize, isStartEvent) {
    override fun specificPropertiesToString(builder: StringBuilder) {}
  }

  class LevelReductionEvent(programSize: Int, isStartEvent: Boolean, val level: Int) :
    AbstractProfileEvent(programSize, isStartEvent) {
    override fun specificPropertiesToString(builder: StringBuilder) {
      builder.append("level=").append(level).append('\t')
    }
  }

  class GranularityEvent(programSize: Int, isStartEvent: Boolean, val granularity: Int) :
    AbstractProfileEvent(programSize, isStartEvent) {
    override fun specificPropertiesToString(builder: StringBuilder) {
      builder.append("granularity=").append(granularity).append('\t')
    }
  }
}
