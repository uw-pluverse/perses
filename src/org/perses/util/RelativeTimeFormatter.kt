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
package org.perses.util

import java.util.logging.Formatter
import java.util.logging.LogManager
import java.util.logging.LogRecord

// TODO(cnsun): needs tests.
class RelativeTimeFormatter : Formatter() {
  private val booleanHideTimestamps by lazy {
    val propertyName = "${this::class.qualifiedName}.hideTimestamps"
    val value: String? = LogManager.getLogManager().getProperty(propertyName)
    value?.toBooleanStrict() ?: true
  }

  override fun format(record: LogRecord): String =
    if (booleanHideTimestamps) {
      String.format(
        "%4s %s%n",
        record.level,
        formatMessage(record),
      )
    } else {
      val relativeTimeSpan = formatTimeDurationFromStart(System.currentTimeMillis())

      // Build the final log message string
      String.format(
        "%s %4s %s%n",
        relativeTimeSpan,
        record.level,
        formatMessage(record),
      )
    }

  // Store the application start time in a companion object
  companion object {
    private val startTimeMillis = System.currentTimeMillis()

    private fun formatTimeDurationFromStart(endTimeMillis: Long): String =
      TimeSpan(
        startTimeMillis = startTimeMillis,
        endTimeMillis = endTimeMillis,
      ).breakdown.computeConciseFormattedString(includeSeconds = false)
  }
}
