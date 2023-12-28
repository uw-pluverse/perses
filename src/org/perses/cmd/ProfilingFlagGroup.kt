/*
 * Copyright (C) 2018-2024 University of Waterloo.
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
package org.perses.cmd

import com.beust.jcommander.Parameter
import org.perses.util.cmd.AbstractCommandLineFlagGroup
import java.nio.file.Path

class ProfilingFlagGroup : AbstractCommandLineFlagGroup(groupName = "Profiling") {
  @Parameter(
    names = ["--progress-dump-file"],
    description = "The file to record the reduction process. The dump file can be large..",
    order = 0,
  )
  var progressDumpFile: Path? = null

  @Parameter(
    names = ["--append-to-progress-dump-file"],
    description = "Whether to append the reduction progress to the progress dump file",
    order = 5,
    arity = 1,
  )
  var appendToProgressDumpFile = false

  @Parameter(
    names = ["--stat-dump-file"],
    description = "The file to save the statistics collected during reduction.",
    order = 10,
  )
  var statDumpFile: Path? = null

  @Parameter(
    names = ["--profile-query-cache"],
    description = "The file to save the profiling data of the query cache.",
    order = 20,
  )
  var profileQueryCacheTime: String? = null

  @Parameter(
    names = ["--profile-query-cache-memory"],
    description = "The file to save the profiling data of the query cache.",
    order = 30,
  )
  var profileQueryCacheMemory: String? = null

  @Parameter(
    names = ["--profile-actionset"],
    description = "The file to save information of all the created edit action sets.",
    order = 40,
  )
  var actionSetProfiler: Path? = null

  @Parameter(
    names = ["--profile"],
    description = "profile the reduction process for analysis",
    arity = 1,
    order = 50,
  )
  var profile = false

  @Parameter(
    names = ["--script-execution-timeout-in-seconds"],
    description = "the interval in seconds to timeout " +
      "the test script executions. the default timeout is 600 seconds.",
    order = 60,
  )
  var testScriptExecutionTimeoutInSeconds: Long = 600L

  @Parameter(
    names = ["--script-execution-keep-waiting-after-timeout"],
    description = "keep trying even after " +
      "the script execution timeouts.",
    arity = 1,
    order = 70,
  )
  var testScriptExecutionKeepWaitingAfterTimeout: Boolean = true

  override fun validate() {
    check(testScriptExecutionTimeoutInSeconds > 0)
    check(profileQueryCacheMemory == null || profileQueryCacheTime == null) {
      "Only at most one flag can be enabled."
    }
  }
}
