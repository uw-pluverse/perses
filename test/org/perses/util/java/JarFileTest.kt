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

import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import java.nio.charset.StandardCharsets
import java.nio.file.Files
import java.util.zip.ZipEntry
import java.util.zip.ZipOutputStream
import kotlin.io.path.deleteRecursively

@RunWith(JUnit4::class)
class JarFileTest {

  private val tempDir = Files.createTempDirectory(javaClass.simpleName)

  @After
  fun teardown() {
    tempDir.deleteRecursively()
  }

  @Test
  fun test() {
    val zipFile = tempDir.resolve("test.zip")
    val entryName = "dir/a.txt"
    val content = "hello"
    ZipOutputStream(Files.newOutputStream(zipFile)).use {
      val entry = ZipEntry(entryName)
      it.putNextEntry(entry)
      it.write(content.toByteArray(StandardCharsets.UTF_8))
      it.closeEntry()
    }
    val value = JarFile.readTextFileInZipFile(
      zipFile,
      entryName,
    )
    assertThat(value).isEqualTo(content)
  }

  @Test
  fun test_getJarsOnClasspath() {
    val jars = JavacWrapper.getJarsOnClasspath()
    assertThat(jars).isNotEmpty()
    for (path in jars) {
      assertThat(path.toString()).endsWith(".jar")
      assertThat(Files.exists(path)).isTrue()
      assertThat(Files.isDirectory(path)).isFalse()
    }
  }
}
