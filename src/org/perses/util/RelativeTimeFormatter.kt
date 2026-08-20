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

import org.perses.PersesConstants
import java.util.logging.Formatter
import java.util.logging.Level
import java.util.logging.LogManager
import java.util.logging.LogRecord

// TODO(cnsun): needs tests.
class RelativeTimeFormatter : Formatter() {
  private val booleanHideTimestamps by lazy {
    val propertyName = "${this::class.qualifiedName}.hideTimestamps"
    val value: String? = LogManager.getLogManager().getProperty(propertyName)
    value?.toBooleanStrict() ?: true
  }

  override fun format(record: LogRecord): String {
    val message = formatMessage(record)
    val result = StringBuilder()
    // TODO(cnsun): needs testing. When printing time, we hide INFO if the level is INFO.
    if (!booleanHideTimestamps) {
      val relativeTimeSpan = formatTimeDurationFromStart(PersesConstants.elapsedTimeSpan())
      result.append(relativeTimeSpan).append(' ')

      if (record.level != Level.INFO) {
        result.append(record.level.toString()).append(' ')
      }
    } else {
      result.append(record.level.toString()).append(' ')
    }
    result.append(message).append('\n')
    // Without this, a cause attached to a log record -- FluentLogger's withCause(), or any JUL
    // logger's thrown -- is silently dropped, so a caller who attached one gets a message that
    // reads as though the exception were reported and no way to see what actually failed.
    record.thrown?.let { result.append(it.stackTraceToString()) }
    return result.toString()
  }

  // Store the application start time in a companion object
  companion object {
    private fun formatTimeDurationFromStart(timespan: TimeSpan): String =
      timespan.breakdown.computeConciseFormattedString(includeSeconds = false)
  }
}
