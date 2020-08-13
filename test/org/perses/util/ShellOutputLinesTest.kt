package org.perses.util

import com.google.common.truth.Truth
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4

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
}
