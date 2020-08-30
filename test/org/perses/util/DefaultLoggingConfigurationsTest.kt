/*
 * Copyright (C) 2018-2020 University of Waterloo.
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

import com.google.common.truth.Truth.assertThat
import org.junit.Assert
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import java.io.File
import java.nio.charset.StandardCharsets

@RunWith(JUnit4::class)
class DefaultLoggingConfigurationsTest {

  @Test
  fun testInfoProperties() {
    val p = DefaultLoggingConfigurations.createLoggingProperties("INFO")
    assertThat(p[".level"]).isEqualTo("INFO")
    assertThat(p["java.util.logging.ConsoleHandler.level"]).isEqualTo("INFO")
    assertThat(p["handlers"]).isEqualTo("java.util.logging.ConsoleHandler")
    assertThat(p["java.util.logging.ConsoleHandler.formatter"]).isEqualTo(
      "java.util.logging.SimpleFormatter"
    )
    val goldenFormatString = File("test/org/perses/util/golden_SimpleFormatter.format.txt")
      .readText(StandardCharsets.UTF_8).trim()
    assertThat(p["java.util.logging.SimpleFormatter.format"]).isEqualTo(goldenFormatString)
  }

  @Test
  fun testInvalidLoggingLevel() {
    Assert.assertThrows(IllegalArgumentException::class.java) {
      DefaultLoggingConfigurations.configureLogManager("invalid_level")
    }
  }
}
