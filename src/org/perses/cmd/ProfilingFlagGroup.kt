/*
 * Copyright (C) 2018-2026 University of Waterloo.
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
    names = ["--actionset-effect-profile"],
    description = "The file to profile the effect of edit action sets.",
    order = 8,
  )
  var actionsetEffectProfile: Path? = null

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
    names = ["--profile-list-minimizer"],
    description = "The file to save the reduction process of the list minimizer.",
    order = 55,
  )
  var profileListMinimizer: Path? = null

  @Parameter(
    names = ["--profile-program-size-trend"],
    description = "The file to save the the size of the program being reduced over time.",
    order = 1000,
  )
  var profileProgramSizeTrend: Path? = null

  @Parameter(
    names = ["--profile-for-reduction-progress-differential-analysis"],
    description = "The file to save the reduction process for offline differential analysis.",
    order = 2000,
  )
  var profileReductionProcessDifferentialAnalysis: Path? = null

  @Parameter(
    names = ["--enable-web-ui"],
    description = "Serve a live web dashboard of the reduction progress on localhost.",
    arity = 1,
    order = 3000,
  )
  var enableWebUi = false

  @Parameter(
    names = ["--web-ui-port"],
    description = "Preferred port for --enable-web-ui. Falls back to an ephemeral port if taken.",
    order = 3010,
  )
  var webUiPort = 9000

  override fun validate() {
    val flags =
      listOf(
        ::profileQueryCacheMemory,
        ::profileQueryCacheTime,
        ::profileQueryCacheTimeCSV,
      )
    val countOfNonNulls =
      flags
        .count { it.get() != null }
    check(countOfNonNulls <= 1) {
      "Only at most one flag can be enabled. $flags"
    }
  }
}
