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
import org.perses.fuzzer.compilers.c.ClangCrashDetector
import org.perses.fuzzer.compilers.c.GccCrashDetector
import org.perses.fuzzer.compilers.rust.RustcCrashDetector
import org.perses.fuzzer.compilers.scala.ScalaCrashDetector
import org.perses.fuzzer.compilers.solidity.SolidityCrashDetector
import java.io.File

@RunWith(JUnit4::class)
class ReportedBugFolderTest {

  private val util = RustTestUtil()

  @After
  fun teardown() {
    util.close()
  }

  @Test
  fun testDuplicateDetectionForFixedBugs() {
    util.populateProcessingFolder(1)

    val clusters = util.getFindingFolder().clusterCrashesOnCrashSignatures()
    val firstCrash = clusters.getCluster(0).instances.get(0)
    RustTestUtil.markCrashAsReported(
      firstCrash,
      "first-bug",
      1,
      bugResolution = CrashInstanceFolder.BugResolution.FIXED,
    )
    val secondCrash = clusters.getCluster(1).instances.get(0)
    RustTestUtil.markCrashAsReported(
      secondCrash,
      "second-bug",
      2,
      CrashInstanceFolder.BugResolution.FIXED,
    )

    util.organizer.moveReportedBugReport()

    val reportedFolder = util.getReportedFolder()
    assertThat(reportedFolder.getAllCrashInstances()).hasSize(2)

    util.organizer.moveDuplicateBugReports()
    assertThat(util.getFindingFolder().getAllCrashInstances()).hasSize(2)
    assertThat(util.getDuplicateFolder().getAllCrashInstances()).hasSize(0)
  }

  @Test
  fun testDuplicateDetection() {
    util.populateProcessingFolder(1)
    val findingFolder = util.getFindingFolder()
    assertThat(findingFolder.getAllCrashInstances()).hasSize(4)

    val clusters = findingFolder.clusterCrashesOnCrashSignatures()
    assertThat(clusters.numberOfClusters).isEqualTo(2)

    val firstCrash = clusters.getCluster(0).instances.get(0)
    RustTestUtil.markCrashAsReported(
      firstCrash,
      "first-bug",
      1,
      bugResolution = CrashInstanceFolder.BugResolution.NEW,
    )
    val secondCrash = clusters.getCluster(1).instances.get(0)
    RustTestUtil.markCrashAsReported(
      secondCrash,
      "second-bug",
      2,
      CrashInstanceFolder.BugResolution.NEW,
    )

    util.organizer.moveReportedBugReport()
    assertThat(findingFolder.getAllCrashInstances()).hasSize(2)

    val reportedFolder = util.getReportedFolder()
    assertThat(reportedFolder.getAllCrashInstances()).hasSize(2)
    assertThat(
      reportedFolder
        .getAllCrashInstances()
        .asSequence()
        .map { it.folder.name }
        .toList(),
    ).containsExactly(
      "rust-1",
      "rust-2",
    )

    util.organizer.moveDuplicateBugReports()
    assertThat(reportedFolder.getAllCrashInstances()).hasSize(2)
    assertThat(util.getFindingFolder().getAllCrashInstances()).hasSize(0)
    assertThat(findingFolder.getAllCrashInstances()).hasSize(0)
    assertThat(util.getDuplicateFolder().getAllCrashInstances()).hasSize(2)
    assertThat(
      util.getDuplicateFolder()
        .getAllCrashInstances()
        .asSequence()
        .map { it.folder.name }
        .filter { it.startsWith("dup-") }.toList(),
    )
      .hasSize(2)
  }

  @Test
  fun test_load_reported_c_bugs() {
    test_load_reported_bugs(
      "kitten/reported_bugs/c",
      listOf(GccCrashDetector::class.java, ClangCrashDetector::class.java),
    )
  }

  @Test
  fun test_load_reported_rust_bugs() {
    test_load_reported_bugs(
      "kitten/reported_bugs/rust",
      listOf(RustcCrashDetector::class.java),
    )
  }

  @Test
  fun test_load_reported_scala_bugs() {
    test_load_reported_bugs(
      "kitten/reported_bugs/scala",
      listOf(ScalaCrashDetector::class.java),
    )
  }

  @Test
  fun test_load_reported_solidity_bugs() {
    test_load_reported_bugs(
      "kitten/reported_bugs/solidity",
      listOf(SolidityCrashDetector::class.java),
    )
  }

  private fun test_load_reported_bugs(path: String, detectorClasses: List<Class<*>>) {
    val folder = ReportedBugFolder(File(path))
    val instances = folder.getAllCrashInstances()
    instances.forEach {
      it.info() // should not crash.
      val detector = it.createCrashDetector()
      assertThat(detector.javaClass).isIn(detectorClasses)
    }
  }
}
