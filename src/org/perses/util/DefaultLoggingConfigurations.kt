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
    Level.FINEST
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
    result["java.util.logging.SimpleFormatter.format"] = "[%1${'$'}tT] [%4\${'\$'}-7s] %5${'$'}s %n"
    return result
  }
}
