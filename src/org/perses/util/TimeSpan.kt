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
package org.perses.util

import com.google.common.base.MoreObjects
import com.google.common.base.Strings
import java.io.Serializable

/** Representation of a time span.  */
class TimeSpan(
  val startTimeMillis: Long,
  val endTimeMillis: Long,
) : Serializable {
  init {
    require(startTimeMillis <= endTimeMillis)
    require(startTimeMillis >= 0)
    require(endTimeMillis > 0)
  }

  val endTimeInSeconds: Long
    get() = endTimeMillis / 1000

  val elapsedTimeInMillis: Long
    get() = endTimeMillis - startTimeMillis

  val elapsedTimeInSeconds: Int
    get() = (elapsedTimeInMillis / 1000).toInt()

  val breakdown: TimeSpanBreakdown by lazy {
    var seconds = elapsedTimeInSeconds
    val days = seconds / (24 * 3600)
    seconds %= 24 * 3600
    val hours = seconds / 3600
    seconds %= 3600
    val minutes = seconds / 60
    seconds %= 60
    TimeSpanBreakdown(days, hours, minutes, seconds)
  }

  override fun toString(): String =
    MoreObjects
      .toStringHelper(this)
      .add("startMillis", startTimeMillis)
      .add("endMillis", endTimeMillis)
      .add("formatted", formattedElapsedTime)
      .toString()

  val formattedElapsedTime: String by lazy {
    if (elapsedTimeInSeconds == 1) {
      "1 second"
    } else if (elapsedTimeInSeconds <= 60) {
      "$elapsedTimeInSeconds seconds"
    } else {
      "$elapsedTimeInSeconds seconds (${breakdown.formattedString})"
    }
  }

  class Builder internal constructor(
    val startMillis: Long,
  ) {
    fun end(nowInMillis: Long): TimeSpan = createTimeSpan(nowInMillis)

    fun createTimeSpan(endMillis: Long): TimeSpan = TimeSpan(startMillis, endMillis)

    companion object {
      @JvmStatic
      fun start(nowInMillis: Long): Builder = Builder(nowInMillis)
    }
  }

  data class TimeSpanBreakdown(
    val days: Int,
    val hours: Int,
    val minutes: Int,
    val seconds: Int,
  ) {
    val formattedString: String by lazy {
      val components = mutableListOf<String>()
      addTimeComponentToListIfNecessary(days, "day", components)
      addTimeComponentToListIfNecessary(hours, "hour", components)
      addTimeComponentToListIfNecessary(minutes, "minute", components)
      addTimeComponentToListIfNecessary(seconds, "second", components)
      components.joinToString(separator = " ")
    }

    fun computeConciseFormattedString(includeSeconds: Boolean): String {
      val builder = StringBuilder()
      if (days > 0) {
        builder.append(days).append('D')
      }
      if (builder.isNotEmpty()) {
        builder.append(':')
      }
      builder.append(Strings.padStart(hours.toString(), 2, '0'))
      builder.append(":").append(Strings.padStart(minutes.toString(), 2, '0'))
      if (includeSeconds) {
        builder.append(":").append(Strings.padStart(seconds.toString(), 2, '0'))
      }
      return builder.toString()
    }

    private fun addTimeComponentToListIfNecessary(
      value: Int,
      singularName: String,
      resultCollector: MutableList<String>,
    ) {
      if (value == 1) {
        resultCollector.add("1 $singularName")
      } else if (value > 1) {
        resultCollector.add("$value ${singularName}s")
      }
    }
  }
}
