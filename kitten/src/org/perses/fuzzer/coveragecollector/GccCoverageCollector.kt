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

import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableMap
import org.perses.fuzzer.compilers.ActionResult
import org.perses.fuzzer.compilers.ICompilationAction
import org.perses.util.shell.ShellCommandOnPath
import java.io.File
import java.nio.file.Path
import java.util.*
import java.util.concurrent.ExecutorService
import java.util.concurrent.Executors
import java.util.concurrent.TimeUnit

class GccCoverageCollector(
  val gccBuildDir: Path,
  val coverageDir: Path,
  val monitorInterval: Long,
  val timeout: Long,
) : ICoverageCollector {

  private val lcovCommand = ShellCommandOnPath("lcov").also {
    val versionOutput = it.runWith(extraArguments = ImmutableList.of("--version"))
    require(versionOutput.exitCode.isZero()) {
      versionOutput
    }
  }

  private val buildDirHistory = mutableListOf<Path>()

  private val emptyCoverageReport = ICoverageCollector.CoverageReport(
    branch_covered = 0,
    branch_total = 0,
    line_covered = 0,
    line_total = 0,
    aflMapDensity = 0.0,
    aflHitCount = 0,
  )
  private var executedCount = 0
  private var collectCount = 0
  private var numDirs: Long = 0
  private val uuid = UUID.randomUUID().toString().substring(0, 4)

  override fun launch(): ExecutorService? {
    val scheduledExecutor = Executors.newScheduledThreadPool(1)
    numDirs = kotlin.math.ceil(timeout.toDouble() / monitorInterval).toLong()
    repeat(numDirs.toInt()) {
      createBuildDir()
    }
    scheduledExecutor.scheduleAtFixedRate(
      {
        if (executedCount < numDirs) {
          val buildDir = buildDirHistory[executedCount]
          val pathParts = buildDir.toString().trim(File.separatorChar).split(File.separator)
          System.setProperty("GCOV_PREFIX", buildDir.toString())
          System.setProperty("GCOV_PREFIX_STRIP", (pathParts.size - 1).toString())
          getCoverageReport()
          executedCount++
        }
      },
      0,
      monitorInterval,
      TimeUnit.SECONDS,
    )
    return scheduledExecutor
  }

  fun createBuildDir(): Path {
    val tempDir = System.getenv("TMPDIR") ?: "/tmp"
    val gccBuildCopyDir = File(tempDir, "kitten/gcc")
    gccBuildCopyDir.mkdirs()
    val newBuildDir = File(gccBuildCopyDir, "gcc-build-$uuid-${buildDirHistory.size}")
    gccBuildDir.toFile().copyRecursively(newBuildDir, overwrite = true)
    buildDirHistory.add(newBuildDir.toPath())
    return newBuildDir.toPath()
  }

  override fun getCoverageReport(): ICoverageCollector.CoverageReport {
    if (executedCount == 0) {
      return emptyCoverageReport
    }
    val oldBuildDir = buildDirHistory[collectCount++]
    // create coverage result file, but do not generate report here
    ShellCommandOnPath("lcov")
      .runWith(
        extraArguments = ImmutableList.of(
          "-c",
          "-d",
          oldBuildDir.toString(),
          "-o",
          "$coverageDir/cov_$collectCount.info",
        ),
      )
    return emptyCoverageReport
  }

  override fun executeActionWithCoverageCollection(
    action: ICompilationAction,
    file: File,
    threadId: Long,
  ): ActionResult {
    val gcovPrefix = System.getProperty("GCOV_PREFIX")
    val gcovPrefixStrip = System.getProperty("GCOV_PREFIX_STRIP")
    val env = ImmutableMap.of(
      "GCOV_PREFIX",
      gcovPrefix,
      "GCOV_PREFIX_STRIP",
      gcovPrefixStrip,
    )
    return action.compileWithExtraEnvironment(file, env)
  }

  override fun closeForThread() {
    while (collectCount < numDirs) {
      getCoverageReport()
    }
  }
}
