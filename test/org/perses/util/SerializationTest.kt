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

import com.fasterxml.jackson.core.type.TypeReference
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import java.nio.file.Files
import kotlin.io.path.ExperimentalPathApi
import kotlin.io.path.deleteRecursively

@RunWith(JUnit4::class)
class SerializationTest {
  private val tempDir = Files.createTempDirectory(this::class.java.simpleName)

  @OptIn(ExperimentalPathApi::class)
  @After
  fun teardown() {
    tempDir.deleteRecursively()
  }

  val data = TestData("a", 1)

  @Test
  fun testDeepCopy() {
    val list = ParentTestData(data)
    val copy = Serialization.deepCopy(list, ParentTestData::class.java)
    assertThat(list).isEqualTo(copy)
    assertThat(list.data).isNotSameInstanceAs(copy.data)
  }

  private val typeReference = object : TypeReference<TestData>() {}

  @Test
  fun testYamlString() {
    val yaml = Serialization.toYamlString(data)
    val copy = Serialization.fromYamlString(yaml, typeReference)
    assertThat(data).isEqualTo(copy)
  }

  @Test
  fun testYamlFile() {
    val file = tempDir.resolve("test.yaml")
    Serialization.toYamlFile(data, file)
    val copy = Serialization.fromYamlFile(file, typeReference)
    assertThat(data).isEqualTo(copy)
  }

  @Test
  fun testJsonString() {
    val json = Serialization.toJsonString(data)
    val copy = Serialization.fromJsonString(json, typeReference)
    assertThat(data).isEqualTo(copy)
  }

  @Test
  fun testJsonStringWithTypeReference() {
    val expected = listOf("a", "b", "c")
    val json = Serialization.toJsonString(expected)
    val copy =
      Serialization.fromJsonString(
        json,
        Serialization.TYPE_REFERENCE_LIST_OF_STRINGS,
      )
    assertThat(copy).isEqualTo(expected)
  }

  @Test
  fun testJsonFile() {
    val file = tempDir.resolve("test.json")
    Serialization.toJsonFile(data, file)
    val copy = Serialization.fromJsonFile(file, typeReference)
    assertThat(data).isEqualTo(copy)
  }

  data class TestData(
    val a: String,
    val b: Int,
  )

  data class ParentTestData(
    val data: TestData,
  )
}
