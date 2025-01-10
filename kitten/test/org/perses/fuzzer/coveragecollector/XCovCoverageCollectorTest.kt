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

package org.perses.fuzzer.coveragecollector

import com.google.common.truth.Truth
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.util.Util
import org.perses.util.shell.Shells
import java.nio.file.Files
import java.nio.file.Path
import java.nio.file.Paths
import kotlin.io.path.ExperimentalPathApi
import kotlin.io.path.deleteRecursively
import kotlin.io.path.name
import kotlin.io.path.writeText

@RunWith(JUnit4::class)
class XCovCoverageCollectorTest {

  private val tempDir = Util.createTempDirFor(this)
  private val srcDir = Util.ensureDirExists(tempDir.resolve("src"))
  private val binaryFile = srcDir.resolve("t.out").also {
    check(Files.notExists(it))
  }
  private val sourceFile = srcDir.resolve("t.c").apply {
    writeText(
      """
      #include "stdio.h"

      int main() {
          int a = 0;
          if (a == 0) {
              printf("Hello, world!");
          } else {
              printf("Hi, world!");
          }
      }
      """.trimIndent(),
    )

    Shells.singleton.run(
      cmd = "gcc -fprofile-arcs -ftest-coverage -o ${binaryFile.name} ${this.name}",
      workingDirectory = srcDir,
      captureOutput = true,
      environment = Shells.CURRENT_ENV,
    ).let { cmdOutput ->
      check(cmdOutput.exitCode.isZero()) {}
    }
    Shells.singleton.run(
      cmd = "./${binaryFile.name}",
      workingDirectory = srcDir,
      captureOutput = true,
      environment = Shells.CURRENT_ENV,
    ).let { cmdOutput ->
      check(cmdOutput.exitCode.isZero())
    }
  }
  private val gcdaFile = Util.listFilesInFolder(srcDir).single { it.name.endsWith(".gcda") }
  private val gcnoFile = Util.listFilesInFolder(srcDir).single { it.name.endsWith("gcno") }

  @OptIn(ExperimentalPathApi::class)
  @After
  fun teardown() {
    tempDir.deleteRecursively()
  }

  @Test
  fun testLcovGetCoverage() {
    testGetCoverage {
      LcovCoverageCollector(
        sourcePath = Paths.get("."),
        infoPath = srcDir,
        monitorInterval = 600,
        resultFile = it,
      )
    }
  }

  @Test
  fun testGcovGetCoverage() {
    testGetCoverage {
      GcovCoverageCollector(
        sourcePath = Paths.get("."),
        infoPath = srcDir,
        monitorInterval = 600,
        resultFile = it,
      )
    }
  }

  private fun testGetCoverage(coverageCollectorCreator: (resultFile: Path) -> ICoverageCollector) {
    val resultFile = tempDir.resolve("result.txt")

    val coverageCollector = coverageCollectorCreator(resultFile)
    val coverageReport = coverageCollector.getCoverageReport()
    Truth.assertThat(coverageReport).isEqualTo(
      ICoverageCollector.CoverageReport(
        branch_covered = 1,
        branch_total = 2,
        line_covered = 4,
        line_total = 5,
        aflMapDensity = 0.0,
        aflHitCount = 0,
      ),
    )
    Truth.assertThat(coverageReport.getBranchCoverage()).isEqualTo(0.5)
    Truth.assertThat(coverageReport.getLineCoverage()).isEqualTo(0.8)
  }
}
