/*
 * Copyright (C) 2018-2022 University of Waterloo.
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
import org.perses.util.cmd.CommonCmdOptionGroupOrder
import org.perses.util.cmd.ICommandLineFlags

class ProfilingFlags : ICommandLineFlags {
  @Parameter(
    names = ["--progress-dump-file"],
    description = "The file to record the reduction process. The dump file can be large..",
    order = CommonCmdOptionGroupOrder.PROFILING_CONTROL + 0,
  )
  var progressDumpFile: String? = null

  @Parameter(
    names = ["--stat-dump-file"],
    description = "The file to save the statistics collected during reduction.",
    order = CommonCmdOptionGroupOrder.PROFILING_CONTROL + 10,
  )
  var statDumpFile: String? = null

  @Parameter(
    names = ["--profile-query-cache"],
    description = "The file to save the profiling data of the query cache.",
    order = CommonCmdOptionGroupOrder.PROFILING_CONTROL + 20,
  )
  var profileQueryCacheTime: String? = null

  @Parameter(
    names = ["--profile-query-cache-memory"],
    description = "The file to save the profiling data of the query cache.",
    order = CommonCmdOptionGroupOrder.PROFILING_CONTROL + 30,
  )
  var profileQueryCacheMemory: String? = null

  @Parameter(
    names = ["--profile-actionset"],
    description = "The file to save information of all the created edit action sets.",
    order = CommonCmdOptionGroupOrder.PROFILING_CONTROL + 40,
  )
  var actionSetProfiler: String? = null

  @Parameter(
    names = ["--profile"],
    description = "profile the reduction process for analysis",
    arity = 1,
    order = CommonCmdOptionGroupOrder.PROFILING_CONTROL + 50,
  )
  var profile = false

  @Parameter(
    names = ["--script-execution-timeout-in-seconds"],
    description = "the interval in seconds to timeout " +
      "the test script executions. the default timeout is 600 seconds.",
    order = CommonCmdOptionGroupOrder.PROFILING_CONTROL + 60,
  )
  var testScriptExecutionTimeoutInSeconds: Long = 600L

  @Parameter(
    names = ["--script-execution-keep-waiting-after-timeout"],
    description = "keep trying even after " +
      "the script execution timeouts.",
    arity = 1,
    order = CommonCmdOptionGroupOrder.PROFILING_CONTROL + 70,
  )
  var testScriptExecutionKeepWaitingAfterTimeout: Boolean = true

  override fun validate() {
    check(testScriptExecutionTimeoutInSeconds > 0)
    check(profileQueryCacheMemory == null || profileQueryCacheTime == null) {
      "Only at most one flag can be enabled."
    }
  }
}
