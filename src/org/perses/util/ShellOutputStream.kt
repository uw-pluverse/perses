package org.perses.util

import com.google.common.collect.ImmutableList
import java.io.ByteArrayOutputStream
import java.io.OutputStream
import java.nio.charset.StandardCharsets

class ShellOutputStream : OutputStream() {

  private var current: ByteArrayOutputStream? = ByteArrayOutputStream()
  private val builderList = ImmutableList.builder<String>()

  override fun write(b: Int) {
    current!!.write(b)
    if (b == '\n'.toInt()) {
      dumpCurrentToList()
      current!!.reset()
    }
  }

  override fun close() {
    if (current!!.size() > 0) {
      dumpCurrentToList()
    }
    current = null
    super.close()
  }

  fun toOutputStringList(): ShellOutputLines {
    check(current == null) {
      "Need to call close() before this function."
    }
    return ShellOutputLines(builderList.build())
  }

  private fun dumpCurrentToList() {
    builderList.add(current!!.toString(StandardCharsets.UTF_8))
  }
}
