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
package org.perses.util

import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import java.nio.file.Files
import kotlin.io.path.deleteRecursively

@RunWith(JUnit4::class)
class AutoIncrementDirectoryTest {

  private val tempDir = Files.createTempDirectory(javaClass.simpleName)

  private val autoDir = AutoIncrementDirectory("perses_result")

  @After
  fun teardown() {
    tempDir.deleteRecursively()
  }

  @Test
  fun test_getResultDirectoryName() {
    autoDir.computeAndCreate(tempDir).let {
      assertThat(it.parent).isEqualTo(tempDir)
      assertThat(it.fileName.toString()).isEqualTo("perses_result")
    }
    autoDir.computeAndCreate(tempDir).let {
      assertThat(it.parent).isEqualTo(tempDir)
      assertThat(it.fileName.toString()).isEqualTo("perses_result_1")
    }
    autoDir.computeAndCreate(tempDir).let {
      assertThat(it.parent).isEqualTo(tempDir)
      assertThat(it.fileName.toString()).isEqualTo("perses_result_2")
    }
    Files.createFile(tempDir.resolve("perses_result_3"))
    autoDir.computeAndCreate(tempDir).let {
      assertThat(it.parent).isEqualTo(tempDir)
      assertThat(it.fileName.toString()).isEqualTo("perses_result_4")
    }
  }
}
