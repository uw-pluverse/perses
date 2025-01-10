/*
 * Copyright (C) 2018-2025 University of Waterloo.
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

import java.io.Closeable
import java.io.PrintStream
import java.nio.file.Files
import java.nio.file.Path

class FileStreamPool : Closeable {

  private val map = mutableMapOf<Path, ManagedPrintStream>()

  private var used = false

  override fun close() {
    used = true
    map.values.forEach {
      check(it.currentRenter == null) {
        """The stream has not been returned.
          |The rentingObject is 
          |${it.currentRenter}
        """.trimMargin()
      }
      it.stream.close()
    }
    map.clear()
  }

  fun rentStream(path: Path, description: String?): ManagedPrintStream {
    val normalizedPath = path.toAbsolutePath().normalize()
    require(!Files.isSymbolicLink(normalizedPath)) {
      "Should not be a symbolic link. $normalizedPath"
    }
    val stream = map.computeIfAbsent(normalizedPath) {
      ManagedPrintStream(Util.createNonAppendablePrintStream(it))
    }
    val rentingObject = "Description: " + (description ?: "") + "\n" +
      Thread.currentThread().stackTrace.joinToString(separator = "\n")
    if (stream.currentRenter == null) {
      stream.currentRenter = rentingObject
    } else {
      error("The stream has been rented. ${stream.currentRenter}, $rentingObject")
    }
    return stream
  }

  inner class ManagedPrintStream(internal val stream: PrintStream) : AutoCloseable {

    internal var currentRenter: Any? = null

    fun println(content: String) {
      stream.println(content)
    }

    fun append(content: String): ManagedPrintStream {
      stream.append(content)
      return this
    }

    fun append(char: Char): ManagedPrintStream {
      stream.append(char)
      return this
    }

    fun print(content: String) {
      stream.print(content)
    }

    fun println() {
      stream.println()
    }

    fun printf(format: String, vararg args: Any) {
      stream.printf(format, *args)
    }

    fun flush() {
      stream.flush()
    }

    override fun close() {
      currentRenter = null
    }
  }
}
