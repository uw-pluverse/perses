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

import java.io.ByteArrayInputStream
import java.io.ByteArrayOutputStream
import java.io.IOException
import java.io.UncheckedIOException
import java.util.Properties
import java.util.logging.Level
import java.util.logging.LogManager

object DefaultLoggingConfigurations {

  @JvmStatic
  val ALLOWED_LOGGING_LEVELS = listOf(
    Level.SEVERE,
    Level.WARNING,
    Level.INFO,
    Level.CONFIG,
    Level.FINE,
    Level.FINER,
    Level.FINEST,
  ).asSequence().map { it.name }.toList()

  @JvmStatic
  fun configureLogManager(loggingLevel: String) {
    require(ALLOWED_LOGGING_LEVELS.contains(loggingLevel)) { loggingLevel }
    val properties = createLoggingProperties(loggingLevel)
    val stream = ByteArrayOutputStream()
    try {
      properties.store(stream, "")
      LogManager.getLogManager()
        .readConfiguration(ByteArrayInputStream(stream.toByteArray()))
    } catch (e: IOException) {
      throw UncheckedIOException(e)
    }
  }

  fun createLoggingProperties(loggingLevel: String): Properties {
    require(ALLOWED_LOGGING_LEVELS.contains(loggingLevel)) { loggingLevel }
    val properties = createLoggingPropertiesTemplate()
    properties[".level"] = loggingLevel
    properties["java.util.logging.ConsoleHandler.level"] = loggingLevel
    return properties
  }

  private fun createLoggingPropertiesTemplate(): Properties {
    val result = Properties()
    result["handlers"] = "java.util.logging.ConsoleHandler"
    result["java.util.logging.ConsoleHandler.formatter"] = "java.util.logging.SimpleFormatter"
    result["java.util.logging.SimpleFormatter.format"] = "[%1${'$'}tT] [%4${'$'}-7s] %5${'$'}s %n"
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
