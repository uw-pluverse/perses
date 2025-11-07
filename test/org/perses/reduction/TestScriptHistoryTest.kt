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
package org.perses.reduction

import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.reduction.TestScriptHistory.Companion.NAME_COLUMN_ELLAPSED_MILLIES
import org.perses.reduction.TestScriptHistory.Companion.NAME_COLUMN_EXIT_CODE
import org.perses.util.hashing.EnumShaAlgorithm
import org.perses.util.shell.ExitCode
import java.nio.file.Files
import kotlin.io.path.ExperimentalPathApi
import kotlin.io.path.deleteRecursively
import kotlin.io.path.readText
import kotlin.io.path.writeText

@RunWith(JUnit4::class)
class TestScriptHistoryTest {
  private val shaAlgorithm = EnumShaAlgorithm.SHA512
  private val tempDir = Files.createTempDirectory(this::class.qualifiedName)
  private val file = tempDir.resolve("a.csv")

  private val history = TestScriptHistory(shaAlgorithm)

  @OptIn(ExperimentalPathApi::class)
  @After
  fun teardown() {
    tempDir.deleteRecursively()
  }

  @Test
  fun testSerializeHeader() {
    history.saveToCSV(file)
    val text = file.readText().trim()
    assertThat(
      text,
    ).isEqualTo("${shaAlgorithm.name},$NAME_COLUMN_EXIT_CODE,$NAME_COLUMN_ELLAPSED_MILLIES")
  }

  @Test
  fun testReadFromEmptyFile() {
    file.writeText("")
    TestScriptHistory.loadFromCSV(shaAlgorithm, file).let {
      assertThat(history.asReadOnlyMap()).isEmpty()
    }
  }

  @Test
  fun testSerializeDeserialize() {
    val result1 = PropertyTestResult(ExitCode.ZERO, 100)
    val result2 = PropertyTestResult(ExitCode.ZERO, 200)
    history.cacheExecutionHistory(hash("AA"), result1)
    history.cacheExecutionHistory(hash("BB"), result2)
    assertThat(history.getExecutionHistoryFor(hash("AA"))).isEqualTo(result1)
    assertThat(history.getExecutionHistoryFor(hash("BB"))).isEqualTo(result2)
    history.saveToCSV(file)

    TestScriptHistory.loadFromCSV(shaAlgorithm, file).let {
      assertThat(history.asReadOnlyMap()).isEqualTo(it.asReadOnlyMap())
      assertThat(it.asReadOnlyMap()).hasSize(2)
    }
  }

  private fun hash(s: String) = shaAlgorithm.createFromString(s).digest
}
