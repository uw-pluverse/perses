package org.perses.util

import com.google.common.truth.Truth.assertThat
import org.junit.Assert
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import java.lang.IllegalArgumentException

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
    assertThat(p["java.util.logging.SimpleFormatter.format"] as String).isNotEmpty()
  }

  @Test
  fun testInvalidLoggingLevel() {
    Assert.assertThrows(IllegalArgumentException::class.java) {
      DefaultLoggingConfigurations.configureLogManager("invalid_level")
    }
  }
}
