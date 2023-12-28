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
package org.perses.util

import com.google.common.base.MoreObjects
import java.io.Serializable

/** Representation of a time span.  */
class TimeSpan private constructor(startMillis: Long, endMillis: Long) : Serializable {
  val startTimeMillis: Long
  val endTimeMillis: Long
  val elapsedTimeInSeconds: Long
    get() = elapsedTimeInMillis / 1000
  val elapsedTimeInMillis: Long
    get() = endTimeMillis - startTimeMillis

  override fun toString(): String {
    return MoreObjects.toStringHelper(this)
      .add("startMillis", startTimeMillis)
      .add("endMillis", endTimeMillis)
      .add("formatted", formattedElaspedTime)
      .toString()
  }

  val formattedElaspedTime: String
    get() {
      val time = elapsedTimeInSeconds
      return formatSeconds(time)
    }

  class Builder internal constructor(val startMillis: Long) {
    fun end(nowInMillis: Long): TimeSpan {
      return createTimeSpan(nowInMillis)
    }

    fun createTimeSpan(endMillis: Long): TimeSpan {
      return TimeSpan(startMillis, endMillis)
    }

    companion object {
      @JvmStatic
      fun start(nowInMillis: Long): Builder {
        return Builder(nowInMillis)
      }
    }
  }

  companion object {
    private fun formatTimeComponent(value: Long, component: String): String {
      require(value > 0)
      return if (value == 1L) {
        "1 $component"
      } else {
        value.toString() + " " + component + "s"
      }
    }

    private fun formatSeconds(seconds: Long): String {
      if (seconds == 1L) {
        return "1 second"
      }
      if (seconds <= 60) {
        return "$seconds seconds"
      }
      val builder = StringBuilder()
      builder.append(seconds).append(" seconds (")
      val components = ArrayList<String>(5) // initialCopacity
      val days = seconds / (24 * 3600)
      if (days > 0) {
        components.add(formatTimeComponent(days, "day"))
      }
      var mutableSeconds = seconds
      mutableSeconds %= (24 * 3600).toLong()
      val hours = mutableSeconds / 3600
      if (hours > 0) {
        components.add(formatTimeComponent(hours, "hour"))
      }
      mutableSeconds %= 3600
      val minutes = mutableSeconds / 60
      if (minutes > 0) {
        components.add(formatTimeComponent(minutes, "minute"))
      }
      mutableSeconds %= 60
      if (mutableSeconds > 0) {
        components.add(formatTimeComponent(mutableSeconds, "second"))
      }
      components.joinTo(builder, separator = " ")
      builder.append(")")
      return builder.toString()
    }
  }

  init {
    require(startMillis <= endMillis)
    require(startMillis > 0)
    require(endMillis > 0)
    startTimeMillis = startMillis
    endTimeMillis = endMillis
  }
}
