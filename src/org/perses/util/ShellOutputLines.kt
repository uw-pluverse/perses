package org.perses.util

import com.google.common.collect.ImmutableList
import com.google.common.io.Files
import java.io.File
import java.nio.charset.StandardCharsets

data class ShellOutputLines(val content: ImmutableList<String>) {

  /**
   * Returns true if there is a line contains the string.
   */
  fun anyLineContains(needle: String) = content.asSequence().any {
    it.contains(needle)
  }

  fun hasLines() = !content.isEmpty()

  fun combineLines(): String {
    val builder = StringBuilder()
    content.forEach { builder.append(it).append('\n') }
    return builder.toString()
  }

  fun writeToFile(file: File) {
    Files.asCharSink(file, StandardCharsets.UTF_8).writeLines(content, "\n")
  }

  companion object {
    val EMPTY = ShellOutputLines(ImmutableList.of())
  }
}
