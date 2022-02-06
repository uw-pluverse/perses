/*
 * Copyright (C) 2018-2022 University of Waterloo.
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
import org.perses.antlr.reducer.Util
import java.io.Closeable
import java.io.File.pathSeparator
import java.lang.RuntimeException
import java.nio.charset.StandardCharsets
import java.nio.file.Path
import javax.tools.DiagnosticCollector
import javax.tools.JavaFileObject
import javax.tools.ToolProvider

class JavacWrapper(val sourceFiles: ImmutableList<Path>) : Closeable {

  val compiler = ToolProvider.getSystemJavaCompiler()
  val diagnostics = DiagnosticCollector<JavaFileObject>()
  val manager = compiler.getStandardFileManager(
    diagnostics,
    /*local*/null,
    StandardCharsets.UTF_8
  )

  val sources = manager.getJavaFileObjectsFromFiles(
    sourceFiles.map { it.toFile() }
  )

  val options = ImmutableList
    .builder<String>()
    .add("-classpath")
    .add(Util.getJarsOnClasspath().joinToString(pathSeparator))
    .add("-target")
    .add("1.8")
    .add("-source")
    .add("1.8")
    .build()

  fun compile() {
    val task = compiler.getTask(
      /*out*/null,
      manager,
      diagnostics,
      options,
      /*classes*/null,
      sources
    )
    if (!task.call()) {
      throw RuntimeException(
        "compilation fail for $sourceFiles: \n" +
          diagnostics.diagnostics.joinToString("\n")
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
}
