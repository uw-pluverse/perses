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

import com.fasterxml.jackson.annotation.JsonIgnoreProperties
import org.perses.fuzzer.compilers.ActionResult
import org.perses.fuzzer.compilers.ICompilationAction
import java.io.File
import java.util.concurrent.ExecutorService

interface ICoverageCollector {
  fun launch(): ExecutorService?

  fun registerForThread() {}

  fun closeForThread() {}

  fun getCoverageReport(): CoverageReport

  fun executeActionWithCoverageCollection(
    action: ICompilationAction,
    file: File,
    threadId: Long,
  ): ActionResult {
    return action.compile(file)
  }

  @JsonIgnoreProperties(ignoreUnknown = true)
  data class CoverageReport(
    val branch_covered: Int,
    val branch_total: Int,
    val line_covered: Int,
    val line_total: Int,
    val aflMapDensity: Double,
    val aflHitCount: Int,
  ) {
    fun getBranchCoverage(): Double {
      return branch_covered.toDouble() / branch_total.toDouble()
    }

    fun getLineCoverage(): Double {
      return line_covered.toDouble() / line_total.toDouble()
    }
  }
}
