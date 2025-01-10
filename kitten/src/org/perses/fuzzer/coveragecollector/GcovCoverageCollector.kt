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

import com.fasterxml.jackson.module.kotlin.jacksonObjectMapper
import com.google.common.annotations.VisibleForTesting
import com.google.common.collect.ImmutableList
import com.google.common.flogger.FluentLogger
import org.perses.fuzzer.coveragecollector.ICoverageCollector.CoverageReport
import org.perses.util.ktInfo
import org.perses.util.shell.ShellCommandOnPath
import org.perses.util.shell.Shells
import java.nio.file.Path
import java.util.concurrent.ExecutorService
import java.util.concurrent.Executors
import java.util.concurrent.TimeUnit
import kotlin.io.path.appendText
import kotlin.io.path.writeText

class GcovCoverageCollector(
  val sourcePath: Path,
  val infoPath: Path,
  val monitorInterval: Long,
  val resultFile: Path,
) : ICoverageCollector {

  private val gcovrCommand = ShellCommandOnPath("gcovr").also {
    val versionOutput = it.runWith(extraArguments = ImmutableList.of("--version"))
    require(versionOutput.exitCode.isZero()) {
      versionOutput
    }
  }

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
  override fun getCoverageReport(): CoverageReport {
    val cmdOutput = gcovrCommand
      .runWith(
        extraArguments = ImmutableList.of(
          "-r",
          sourcePath.toString(),
          "--json-summary-pretty",
          ".",
        ),
        captureOutput = true,
        workingDirectory = infoPath,
        environment = Shells.CURRENT_ENV,
      )
    if (cmdOutput.exitCode.isNonZero()) {
      throw RuntimeException(
        """
        |Get coverage failed. 
        |
        |Exit code: ${cmdOutput.exitCode}
        |
        |Stdout: ${cmdOutput.stdout.combinedLines}
        |
        |Stderr: ${cmdOutput.stderr.combinedLines}
        |
        """.trimMargin(),
      )
    } else {
      val mapper = jacksonObjectMapper()
      return mapper.readValue(cmdOutput.stdout.combinedLines, CoverageReport::class.java)
    }
  }

  companion object {
    private val logger = FluentLogger.forEnclosingClass()
  }
}
