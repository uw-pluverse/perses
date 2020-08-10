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
  fun formatDateForFileName(epochMillis: Long): String? {
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

  private val DATE_FORMAT_FOR_DISPLAY = DateTimeFormatter.ofPattern("HH:mm:ss yyyy/MM/dd")
  private val DATE_FORMAT_FOR_FILE_NAME = DateTimeFormatter.ofPattern("yyyyMMdd_HHmmss")
}
