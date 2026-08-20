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

import com.google.common.flogger.FluentLogger
import com.google.common.truth.Truth.assertThat
import org.junit.Assert
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4

@RunWith(JUnit4::class)
class DefaultLoggingConfigurationsTest {
  @Test
  fun testInfoProperties() {
    val p =
      DefaultLoggingConfigurations.createLoggingProperties(
        loggingLevel = "INFO",
        hideTimestamps = false,
      )
    assertThat(p[".level"]).isEqualTo("INFO")
    assertThat(p["java.util.logging.ConsoleHandler.level"]).isEqualTo("INFO")
    assertThat(p["handlers"]).isEqualTo("java.util.logging.ConsoleHandler")
    assertThat(p["java.util.logging.ConsoleHandler.formatter"]).isEqualTo(
      RelativeTimeFormatter::class.qualifiedName,
    )
  }

  @Test
  fun testInvalidLoggingLevel() {
    Assert.assertThrows(IllegalArgumentException::class.java) {
      DefaultLoggingConfigurations.configureLogManager(
        loggingLevel = "invalid_level",
        hideTimestamps = false,
      )
    }
  }

  @Test
  fun testConfigureLogManager() {
    DefaultLoggingConfigurations.configureLogManager(
      loggingLevel = "INFO",
      hideTimestamps = false,
    )
    DefaultLoggingConfigurations.configureLogManager(
      loggingLevel = "INFO",
      hideTimestamps = true,
    )
    val logger = FluentLogger.forEnclosingClass()
    logger.atSevere().log("hello")
  }
}
