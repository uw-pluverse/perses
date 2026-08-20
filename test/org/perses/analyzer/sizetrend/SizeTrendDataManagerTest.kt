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
package org.perses.analyzer.sizetrend

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import java.nio.file.Files

class SizeTrendDataManagerTest {
  private val dataManager = SizeTrendDataManager()

  @Test
  fun testLoadSnapshots() {
    val tempFile = Files.createTempFile("test_size_trend", ".csv")
    try {
      Files.write(
        tempFile,
        listOf(
          "elapsed_seconds,current_program_size,action_description",
          "10,1000,Initial",
          "20,800,Fixpoint Iteration End",
          "30,600,Final Action",
        ),
      )

      val snapshots = dataManager.loadSnapshots(tempFile)
      assertThat(snapshots).hasSize(3)

      assertThat(snapshots[0].elapsedSeconds).isEqualTo(10)
      assertThat(snapshots[0].currentProgramSize).isEqualTo(1000)
      assertThat(snapshots[0].actionDescription).isEqualTo("Initial")

      assertThat(snapshots[1].elapsedSeconds).isEqualTo(20)
      assertThat(snapshots[1].currentProgramSize).isEqualTo(800)
      assertThat(snapshots[1].actionDescription).isEqualTo("Fixpoint Iteration End")
    } finally {
      Files.deleteIfExists(tempFile)
    }
  }

  @Test
  fun testIsFixpointIterationEnd() {
    val s1 = Snapshot(10, 100, "Some Action")
    val s2 = Snapshot(20, 80, "Fixpoint Iteration End")
    val s3 = Snapshot(30, 50, "Fixpoint Iteration End (2)")

    assertThat(s1.isFixpointIterationEnd()).isFalse()
    assertThat(s2.isFixpointIterationEnd()).isTrue()
    assertThat(s3.isFixpointIterationEnd()).isTrue()
  }
}
