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
package org.perses

import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.util.FileStreamPool
import org.perses.util.Util
import java.nio.file.Files
import java.nio.file.Path
import kotlin.io.path.ExperimentalPathApi
import kotlin.io.path.deleteRecursively
import kotlin.io.path.exists

@RunWith(JUnit4::class)
class PersesListenerManagerCreatorTest {
  private val tempDir: Path = Files.createTempDirectory(this::class.qualifiedName)

  @OptIn(ExperimentalPathApi::class)
  @After
  fun teardown() {
    tempDir.deleteRecursively()
  }

  @Test
  fun testCreateAsyncReductionListenerManager_DefaultProgramSizeTrendPath() {
    val cmd = PersesCommandOptions()
    val outputDir = tempDir.resolve("output")
    Util.useResources(
      creatorA = { FileStreamPool() },
      creatorB = { pool ->
        Files.createDirectories(outputDir)
        PersesListenerManagerCreator.createAsyncReductionListenerManager(
          cmd,
          pool,
          outputDir,
        )
      },
    ) { _, _ ->
      val expectedPath = outputDir.resolve("perses_reduction_result_size_trend.csv")
      assertThat(expectedPath.exists()).isTrue()
    }
  }

  @Test
  fun testCreateAsyncReductionListenerManager_UserSpecifiedProgramSizeTrendPath() {
    val outputDir = tempDir.resolve("output")
    Files.createDirectories(outputDir)
    val userPath = tempDir.resolve("custom_trend.csv")
    val cmd = PersesCommandOptions()
    cmd.profilingFlags.profileProgramSizeTrend = userPath

    Util.useResources(
      creatorA = { FileStreamPool() },
      creatorB = { pool ->
        PersesListenerManagerCreator.createAsyncReductionListenerManager(
          cmd,
          pool,
          outputDir,
        )
      },
    ) { _, _ ->
      assertThat(userPath.exists()).isTrue()
      val defaultPath = outputDir.resolve("perses_reduction_result_size_trend.csv")
      assertThat(defaultPath.exists()).isFalse()
    }
  }
}
