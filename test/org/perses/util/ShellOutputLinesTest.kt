package org.perses.util

import com.google.common.truth.Truth
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import java.io.File
import java.nio.charset.StandardCharsets

@RunWith(JUnit4::class)
class ShellOutputLinesTest {

  val list: ShellOutputLines

  init {
    val content =
      """0
        |a
        |b
        |c""".trimMargin()
    val stream = ShellOutputStream()
    content.forEach { stream.write(it.toInt()) }
    stream.close()
    list = stream.toOutputStringList()
  }

  @Test
  fun `contains a string`() {
    Truth.assertThat(list.anyLineContains("a")).isTrue()
    Truth.assertThat(list.anyLineContains("A")).isFalse()
  }

  @Test
  fun test_hasFourLines() {
    Truth.assertThat(list.content).hasSize(4)
  }

  @Test
  fun test_writeToFile() {
    val file = File.createTempFile("test_shell_output_lines_test", ".txt")
    list.writeToFile(file)
    val readText = file.readText(StandardCharsets.UTF_8)
    Truth.assertThat(readText.trim()).isEqualTo(list.combineLines().trim())
  }
}
