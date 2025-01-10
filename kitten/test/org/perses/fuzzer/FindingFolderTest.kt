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

import com.google.common.collect.Iterables
import com.google.common.io.Files
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4

@RunWith(JUnit4::class)
class FindingFolderTest {

  private val util = RustTestUtil()
  private val root = java.nio.file.Files.createTempDirectory(javaClass.simpleName).toFile()

  @After
  fun teardown() {
    check(root.deleteRecursively())
    util.close()
  }

  @Test
  fun test() {
    val folder = FindingFolder(root)
    val bugFolder = folder.createBugFolder("crash_")
    assertThat(bugFolder.name).startsWith("crash_")
    assertThat(bugFolder.name).endsWith("_0000")
  }

  @Test
  fun testBuildCrashClusters() {
    util.populateFindingFolder(2)
    val findingFolder = util.getFindingFolder()
    val clusters = findingFolder.clusterCrashesOnCrashSignatures()
    assertThat(clusters.numberOfClusters).isEqualTo(2)
  }

  @Test
  fun test_getInstanceWithLargestMutantFile() {
    util.populateFindingFolder(0)
    val findingFolder = util.getFindingFolder()

    val allCrashInstances = findingFolder.getAllCrashInstances()
    assertThat(allCrashInstances).hasSize(2)
    val firstInstance = Iterables.get(allCrashInstances, 0)
    val secondInstance = Iterables.get(allCrashInstances, 1)
    val firstSize = firstInstance.getMutantFile().length()
    val secondSize = secondInstance.getMutantFile().length()

    val max = findingFolder.getInstanceWithLargestMutantFile()
    assertThat(max).isNotNull()
    assertThat(max!!.getMutantFile().length()).isEqualTo(Math.max(firstSize, secondSize))
  }
}
