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
  var appendToProgressDumpFile = true

  @Parameter(
    names = ["--stat-dump-file"],
    description = "The file to save the statistics collected during reduction.",
    order = 10,
  )
  var statDumpFile: Path? = null

  @Parameter(
    names = ["--profile-query-cache-time"],
    description = "The file to save the profiling data of the query cache.",
    order = 20,
  )
  var profileQueryCacheTime: Path? = null

  @Parameter(
    names = ["--profile-query-cache-time-csv"],
    description = "The file to save the profiling data of the query cache in the CSV format.",
    order = 25,
  )
  var profileQueryCacheTimeCSV: Path? = null

  @Parameter(
    names = ["--profile-query-cache-memory"],
    description = "The file to save the profiling data of the query cache.",
    order = 30,
  )
  var profileQueryCacheMemory: Path? = null

  @Parameter(
    names = ["--profile-actionset"],
    description = "The file to save information of all the created edit action sets.",
    order = 40,
  )
  var actionSetProfiler: Path? = null

  @Parameter(
    names = ["--profile-delta-debugger"],
    description = "The file to save the reduction process of the delta debugger.",
    order = 55,
  )
  var profileDeltaDebugger: Path? = null

  override fun validate() {
    val flags = listOf(
      ::profileQueryCacheMemory,
      ::profileQueryCacheTime,
      ::profileQueryCacheTimeCSV,
    )
    val countOfNonNulls = flags
      .count { it.get() != null }
    check(countOfNonNulls <= 1) {
      "Only at most one flag can be enabled. $flags"
    }
  }
}
