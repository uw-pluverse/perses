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

import com.google.common.annotations.VisibleForTesting
import com.google.common.collect.ImmutableList
import com.google.common.flogger.FluentLogger
import org.perses.util.ktInfo
import org.perses.util.shell.ShellCommandOnPath
import org.perses.util.shell.Shells
import java.nio.file.Path
import java.util.concurrent.ExecutorService
import java.util.concurrent.Executors
import java.util.concurrent.TimeUnit
import kotlin.io.path.appendText
import kotlin.io.path.writeText

class LcovCoverageCollector(
  val sourcePath: Path,
  val infoPath: Path,
  val monitorInterval: Long,
  val resultFile: Path,
) : ICoverageCollector {

  override fun launch(): ExecutorService? {
    resultFile.writeText("line coverage: 0\nbranch coverage: 0\n\n")
    val scheduledExecutor = Executors.newScheduledThreadPool(1)
    scheduledExecutor.scheduleAtFixedRate(
      {
        val coverageReport = getCoverageReport()
        val lineCoverage = coverageReport.getLineCoverage()
        val branchCoverage = coverageReport.getBranchCoverage()
        logger.ktInfo { "Current line coverage: $lineCoverage" }
        resultFile.appendText("line coverage: %s\n".format(lineCoverage))
        logger.ktInfo { "Current branch coverage: $branchCoverage" }
        resultFile.appendText("branch coverage: %s\n\n".format(branchCoverage))
      },
      0,
      monitorInterval,
      TimeUnit.SECONDS,
    )
    return scheduledExecutor
  }

  @VisibleForTesting
  override fun getCoverageReport(): ICoverageCollector.CoverageReport {
    val cmdOutput = ShellCommandOnPath("lcov")
      .runWith(
        extraArguments = ImmutableList.of(
          "-d",
          sourcePath.toString(),
          "-c",
          "--rc",
          "lcov_branch_coverage=1",
        ),
        captureOutput = true,
        workingDirectory = infoPath,
        environment = Shells.CURRENT_ENV,
      )
    if (cmdOutput.exitCode.isNonZero()) {
      throw RuntimeException("get coverage failed. $cmdOutput")
    } else {
      var cmdOutputLines = cmdOutput.stdout.combinedLines.lines()
      // drop first two lines as they contain the test name and path and may contain information
      // that misleads our results
      cmdOutputLines = cmdOutputLines.drop(2)
      var lineTotal = 0
      var lineCovered = 0
      var branchTotal = 0
      var branchCovered = 0

      for (line in cmdOutputLines) {
        val trimmedLine = line.trim()
        if (trimmedLine.length <= 2) {
          continue
        }
        if (trimmedLine.startsWith(LINE_INDICATOR)) {
          lineTotal += 1
          val lastComma = trimmedLine.lastIndexOf(",")
          val newCoveredLines = trimmedLine.subSequence(lastComma + 1, trimmedLine.length)
            .toString().toIntOrNull()
          if (newCoveredLines != null && newCoveredLines > 0) {
            lineCovered += 1
          }
        } else if (trimmedLine.startsWith(BRANCH_INDICATOR)) {
          branchTotal += 1
          val lastComma = trimmedLine.lastIndexOf(",")
          val newCoveredLines = trimmedLine.subSequence(lastComma + 1, trimmedLine.length)
            .toString().toIntOrNull()
          if (newCoveredLines != null && newCoveredLines > 0) {
            branchCovered += 1
          }
        }
      }
      return ICoverageCollector.CoverageReport(
        branchCovered,
        branchTotal,
        lineCovered,
        lineTotal,
        aflMapDensity = 0.0,
        aflHitCount = 0,
      )
    }
  }

  companion object {
    private val logger = FluentLogger.forEnclosingClass()
    const val LINE_INDICATOR = "DA"
    const val BRANCH_INDICATOR = "BRDA"
  }
}
