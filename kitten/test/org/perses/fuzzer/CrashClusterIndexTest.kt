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

import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4

@RunWith(JUnit4::class)
class CrashClusterIndexTest {

  private val util = RustTestUtil()

  @After
  fun teardown() {
    util.close()
  }

  @Test
  fun testClustersWithoutDuplicates() {
    util.populateFindingFolder(numOfDuplicatesPerCrashSignature = 0)
    val findingFolder = util.getFindingFolder()
    val clusters = findingFolder.clusterCrashesOnCrashSignatures()
    assertThat(clusters.numberOfClusters).isEqualTo(2)
    assertThat(clusters.numberOfInstances).isEqualTo(2)
    assertThat(clusters.crashSignatures).hasSize(2)
    assertThat(clusters.getCluster(0)).isNotSameInstanceAs(clusters.getCluster(1))
  }

  @Test
  fun testClustersWithDuplicates() {
    util.populateFindingFolder(numOfDuplicatesPerCrashSignature = 1)
    val findingFolder = util.getFindingFolder()
    val clusters = findingFolder.clusterCrashesOnCrashSignatures()
    assertThat(clusters.numberOfClusters).isEqualTo(2)
    assertThat(clusters.numberOfInstances).isEqualTo(4)
    assertThat(clusters.crashSignatures).hasSize(2)
    assertThat(clusters.getCluster(0)).isNotSameInstanceAs(clusters.getCluster(1))
  }

  @Test
  fun testSaveClusters() {
    util.populateFindingFolder(numOfDuplicatesPerCrashSignature = 1)
    val clusters = util.getFindingFolder().clusterCrashesOnCrashSignatures()
    val string = clusters.saveToString()
    assertThat(string).contains("\n| Cluster 0\n")
    assertThat(string).contains("\n| Cluster 1\n")
    assertThat(string.split("\n---Crash Signature---\n")).hasSize(3)
    assertThat(string.split("\n---Instances---\n")).hasSize(3)
    assertThat(string.split(" bytes")).hasSize(5)
  }
}
