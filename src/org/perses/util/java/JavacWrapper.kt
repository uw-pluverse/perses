/*
 * Copyright (C) 2018-2024 University of Waterloo.
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
package org.perses.util.java

import com.google.common.collect.ImmutableList
import org.perses.util.toImmutableList
import java.io.Closeable
import java.io.File.pathSeparator
import java.nio.charset.StandardCharsets
import java.nio.file.Files
import java.nio.file.Path
import java.nio.file.Paths
import javax.tools.DiagnosticCollector
import javax.tools.JavaFileObject
import javax.tools.ToolProvider

class JavacWrapper(val sourceFiles: ImmutableList<Path>) : Closeable {

  val compiler = ToolProvider.getSystemJavaCompiler()
  val diagnostics = DiagnosticCollector<JavaFileObject>()
  val manager = compiler.getStandardFileManager(
    diagnostics,
    null, // local
    StandardCharsets.UTF_8,
  )

  val sources = manager.getJavaFileObjectsFromFiles(
    sourceFiles.map { it.toFile() },
  )

  val options = ImmutableList
    .builder<String>()
    .add("-classpath")
    .add(getJarsOnClasspath().joinToString(pathSeparator))
    .add("-target")
    .add("1.8")
    .add("-source")
    .add("1.8")
    .build()

  fun compile() {
    val task = compiler.getTask(
      null, // out
      manager,
      diagnostics,
      options,
      null, // classes
      sources,
    )
    if (!task.call()) {
      throw RuntimeException(
        "compilation fail for $sourceFiles: \n" +
          diagnostics.diagnostics.joinToString("\n"),
      )
    }
  }

  fun isJava8Supported(): Boolean {
    return compiler.sourceVersions.firstOrNull { it.name == "RELEASE_8" } != null
  }

  override fun close() {
    manager.close()
  }

  init {
    require(isJava8Supported()) {
      "The current compiler does not support Java 8. " +
        "The supported versions are ${compiler.sourceVersions}"
    }
  }

  companion object {
    @JvmStatic
    fun getJarsOnClasspath(): ImmutableList<Path> {
      val pathSeparator = pathSeparator!!
      val classpath = System.getProperty("java.class.path")!!.trim()
      return classpath.splitToSequence(pathSeparator)
        .asSequence()
        .filter { it.endsWith(".jar") }
        .distinct()
        .map { Paths.get(it).toAbsolutePath() }
        .filter { Files.isRegularFile(it) }
        .toImmutableList()
    }
  }
}
