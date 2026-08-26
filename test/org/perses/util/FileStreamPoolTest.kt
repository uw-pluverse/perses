/*
 * Copyright (C) 2018-2026 University of Waterloo.
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

import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import java.nio.file.Files
import java.nio.file.Path
import kotlin.io.path.ExperimentalPathApi
import kotlin.io.path.deleteRecursively
import kotlin.io.path.readLines

@RunWith(JUnit4::class)
class FileStreamPoolTest {
  private var tempDir: Path = Files.createTempDirectory(this::class.qualifiedName)

  @OptIn(ExperimentalPathApi::class)
  @After
  fun teardown() {
    tempDir.deleteRecursively()
  }

  @Test
  fun testFileStreamPool() {
    val path = tempDir.resolve("a.txt")
    FileStreamPool().use { pool ->
      pool.rentStream(path, description = "a").use {
        it.printf(format = "%s %s %s\n", "1", "2", "3")
      }
      pool.rentStream(path, description = "b").use {
        it.println("second")
      }
    }
    val content = path.readLines()
    assertThat(content).hasSize(2)
    assertThat(content.first()).isEqualTo("1 2 3")
    assertThat(content.last()).isEqualTo("second")
  }
}
