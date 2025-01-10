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
package org.perses.fuzzer

import com.google.common.io.Files
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4

@Suppress("DEPRECATION")
@RunWith(JUnit4::class)
class ProcessingFolderTest {

  private val util = RustTestUtil()

  private val workingDir = java.nio.file.Files.createTempDirectory(javaClass.simpleName)
    .toFile()

  @After
  fun teardown() {
    util.close()
    workingDir.deleteRecursively()
  }

  @Test
  fun testConstructClusterFolderName() {
    assertThat(ProcessingFolder.constructClusterFolderName(1))
      .isEqualTo("cluster-1")
  }

  @Test
  fun testGetClusterFolderIdFromName() {
    val id = 111
    val name = ProcessingFolder.constructClusterFolderName(id)
    assertThat(ProcessingFolder.getClusterFolderIdFromName(name)).isEqualTo(id)
  }

  @Test
  fun test_MoveNewCrashInstanceToThisFolder() {
    util.populateFindingFolder(1)
    val findingFolder = util.getFindingFolder()
    val crashes = findingFolder.getAllCrashInstances()
    assertThat(crashes).hasSize(4)

    val processingFolder = util.getProcessingFolder()

    for (i in 0 until crashes.size) {
      processingFolder.moveNewCrashInstanceToThisFolder(crashes[i])
    }
    assertThat(processingFolder.getAllClustersAndDeleteEmptyOnes()).hasSize(2)
    assertThat(processingFolder.getAllCrashInstances()).hasSize(4)
    assertThat(findingFolder.getAllCrashInstances()).hasSize(0)
  }

  @Test
  fun test_parseExistingCrashInstances() {
    test_MoveNewCrashInstanceToThisFolder() // populate the processing folder.
    // create a new processing folder, and re-parse all crashes.
    val processingFolder = ProcessingFolder(util.getProcessingFolder().folder)
    assertThat(processingFolder.getAllClustersAndDeleteEmptyOnes()).hasSize(2)
    assertThat(processingFolder.getAllCrashInstances()).hasSize(4)
  }

  @Test
  fun test_getReportedCrashInstances() {
//    test_MoveNewCrashInstanceToThisFolder()
    util.populateFindingFolder(0)
    val findingFolder = util.getFindingFolder()
    assertThat(findingFolder.getReportedCrashInstances()).isEmpty()
    val first = findingFolder.getAllCrashInstances().first()
    RustTestUtil.markCrashAsReported(
      first,
      "dummy-url",
      1000,
      CrashInstanceFolder.BugResolution.NEW,
    )
    assertThat(findingFolder.getReportedCrashInstances()).hasSize(1)
    assertThat(first.getReportedBugId()).isEqualTo(1000)
  }
}
