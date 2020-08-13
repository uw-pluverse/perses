package org.perses.util

import com.google.common.truth.Truth
import org.junit.Assert
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4

@RunWith(JUnit4::class)
class ShellOutputStreamTest {

  @Test
  fun `new stream should return empty string`() {
    val stream = ShellOutputStream()
    stream.close()
    val content = stream.toOutputStringList().content
    Truth.assertThat(content).isEmpty()
  }

  @Test
  fun `test stream should be closed before used`() {
    Assert.assertThrows(
      IllegalStateException::class.java
    ) { ShellOutputStream().toOutputStringList() }
  }

  @Test
  fun `test output a string list`() {
    val string =
      """0
                   |1
                   |2
                   |3
                   |4
                   |5
                   |""".trimMargin()
    val stream = ShellOutputStream()
    for (c in string) {
      stream.write(c.toInt())
    }
    stream.close()
    val content = stream.toOutputStringList().content
    Truth.assertThat(content).hasSize(6)
    Truth.assertThat(content.joinToString(separator = "")).isEqualTo(string)
  }
}
