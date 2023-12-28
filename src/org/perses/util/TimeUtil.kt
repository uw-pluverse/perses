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

import com.google.common.annotations.VisibleForTesting
import java.time.Instant
import java.time.LocalDateTime
import java.time.ZoneId
import java.time.format.DateTimeFormatter

object TimeUtil {

  @JvmStatic
  fun formatDateForFileName(datetime: LocalDateTime): String {
    return DATE_FORMAT_FOR_FILE_NAME.format(datetime)
  }

  @JvmStatic
  fun formatDateForFileName(epochMillis: Long): String {
    return formatDateForFileName(converToLocalDateTime(epochMillis, ZoneId.systemDefault()))
  }

  @JvmStatic
  @VisibleForTesting
  fun converToLocalDateTime(epochMillis: Long, zone: ZoneId): LocalDateTime {
    val instant = Instant.ofEpochMilli(epochMillis)
    return instant.atZone(zone).toLocalDateTime()
  }

  @JvmStatic
  fun formatDateForDisplay(epochMillis: Long): String {
    return formatDateForDisplay(converToLocalDateTime(epochMillis, ZoneId.systemDefault()))
  }

  @JvmStatic
  fun formatDateForDisplay(datetime: LocalDateTime): String {
    return DATE_FORMAT_FOR_DISPLAY.format(datetime)
  }

  @JvmStatic
  fun toMillisFromSeconds(seconds: Int): Int {
    require(seconds >= 0)
    return seconds * 1000
  }

  @JvmStatic
  fun toMillisFromMinutes(minutes: Int): Int {
    require(minutes >= 0)
    return toMillisFromSeconds(60 * minutes)
  }

  private val DATE_FORMAT_FOR_DISPLAY = DateTimeFormatter.ofPattern("HH:mm:ss yyyy/MM/dd")
  private val DATE_FORMAT_FOR_FILE_NAME = DateTimeFormatter.ofPattern("yyyyMMdd_HHmmss")
}
