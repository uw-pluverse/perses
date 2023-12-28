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

import org.antlr.v4.runtime.RecognitionException
import org.perses.grammar.AntlrFailureException
import java.lang.reflect.InvocationTargetException
import java.net.URLClassLoader
import java.nio.charset.Charset
import java.nio.charset.StandardCharsets
import java.nio.file.Files
import java.nio.file.Path
import java.nio.file.StandardCopyOption
import java.util.zip.ZipEntry
import java.util.zip.ZipFile

class JarFile(
  val path: Path,
  val mainClassFullName: String,
) : AutoCloseable {

  private val lazyClassLoader = lazy {
    URLClassLoader(arrayOf(path.toUri().toURL()))
  }
  private val classLoader by lazyClassLoader

  fun copyTo(destination: Path): JarFile {
    check(Files.isRegularFile(path))
    Files.copy(path, destination, StandardCopyOption.REPLACE_EXISTING)
    return JarFile(destination, mainClassFullName)
  }

  fun moveTo(destination: Path, replaceExisting: Boolean = true): JarFile {
    check(Files.isRegularFile(path))
    if (replaceExisting) {
      Files.move(path, destination, StandardCopyOption.REPLACE_EXISTING)
    } else {
      Files.move(path, destination)
    }
    return JarFile(destination, mainClassFullName)
  }

  fun readTextFile(
    pathInZip: String,
    charset: Charset = StandardCharsets.UTF_8,
  ): String {
    return readTextFileInZipFile(
      path,
      pathInZip,
      charset,
    )
  }

  override fun close() {
    if (lazyClassLoader.isInitialized()) {
      classLoader.close()
    }
  }

  fun loadMainClass(): Class<*> {
    return classLoader.loadClass(mainClassFullName)
  }

  fun expensiveRunMain() {
    val mainClass = loadMainClass()
    val mainMethod = mainClass.getMethod("main", Array<String>::class.java)
    mainMethod.invoke(null, arrayOf<String>())
  }

  fun expensiveTestParsable(file: Path): Boolean {
    URLClassLoader(arrayOf(path.toUri().toURL())).use { classLoader ->
      val mainClass = classLoader.loadClass(mainClassFullName)
      val tryToParseMethod = mainClass.getMethod("tryToParse", Path::class.java)

      return try {
        tryToParseMethod.invoke(null, file)
        true
      } catch (e: InvocationTargetException) {
        val targetException = e.targetException
        if (targetException is RecognitionException || targetException is AntlrFailureException) {
          false
        } else {
          throw e
        }
      }
    }
  }

  companion object {

    fun readTextFileInZipFile(
      zipFilePath: Path,
      pathInZip: String,
      charset: Charset = StandardCharsets.UTF_8,
    ): String {
      ZipFile(zipFilePath.toFile()).use { zipFile ->
        val entry: ZipEntry = zipFile.getEntry(pathInZip)
        return zipFile.getInputStream(entry).reader(charset).use {
          it.readText()
        }
      }
    }
  }
}
