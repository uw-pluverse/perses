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

import java.io.ByteArrayInputStream
import java.io.ByteArrayOutputStream
import java.util.Properties
import java.util.logging.Level
import java.util.logging.LogManager

object DefaultLoggingConfigurations {
  @JvmStatic
  val ALLOWED_LOGGING_LEVELS =
    listOf(
      Level.SEVERE,
      Level.WARNING,
      Level.INFO,
      Level.CONFIG,
      Level.FINE,
      Level.FINER,
      Level.FINEST,
    ).transformToImmutableList { it.name }

  @JvmStatic
  fun configureLogManager(
    loggingLevel: String,
    hideTimestamps: Boolean,
  ) {
    require(ALLOWED_LOGGING_LEVELS.contains(loggingLevel)) { loggingLevel }
    val properties = createLoggingProperties(loggingLevel, hideTimestamps)
    val stream = ByteArrayOutputStream()
    properties.store(stream, "")
    LogManager
      .getLogManager()
      .readConfiguration(ByteArrayInputStream(stream.toByteArray()))
  }

  fun createLoggingProperties(
    loggingLevel: String,
    hideTimestamps: Boolean,
  ): Properties {
    require(ALLOWED_LOGGING_LEVELS.contains(loggingLevel)) { loggingLevel }
    val properties = createLoggingPropertiesTemplate(loggingLevel, hideTimestamps)
    return properties
  }

  private fun createLoggingPropertiesTemplate(
    loggingLevel: String,
    hideTimestamps: Boolean,
  ): Properties {
    val result = Properties()
    // The order of the entries matters here. Change them with caution if you want to change.
    result[".level"] = loggingLevel
    result["handlers"] = "java.util.logging.ConsoleHandler"
    result["java.util.logging.ConsoleHandler.level"] = loggingLevel
    val formatterQualifiedName = RelativeTimeFormatter::class.qualifiedName!!
    result["java.util.logging.ConsoleHandler.formatter"] = formatterQualifiedName
    result["$formatterQualifiedName.hideTimestamps"] = hideTimestamps.toString()
    return result
  }

  @JvmStatic
  fun printAllAllowedLoggingLevels() {
    println("Available verbosity levels are:")
    for (level in ALLOWED_LOGGING_LEVELS) {
      println("    $level")
    }
  }
}
