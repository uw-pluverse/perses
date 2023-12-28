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
class YamlUtilTest {

  private val tempDir = Files.createTempDirectory(this::class.java.simpleName)

  @After
  fun teardown() {
    tempDir.deleteRecursively()
  }

  val data = TestData("a", 1)

  @Test
  fun testYamlString() {
    val yaml = YamlUtil.toYamlString(data)
    val copy = YamlUtil.fromYamlString(yaml, TestData::class.java)
    assertThat(data).isEqualTo(copy)
  }

  @Test
  fun testYamlFile() {
    val file = tempDir.resolve("test.yaml")
    YamlUtil.toYamlFile(data, file)
    val copy = YamlUtil.fromYamlFile(file, TestData::class.java)
    assertThat(data).isEqualTo(copy)
  }

  data class TestData(val a: String, val b: Int)
}
