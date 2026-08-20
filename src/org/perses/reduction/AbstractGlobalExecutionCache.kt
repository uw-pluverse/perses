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
package org.perses.reduction

import org.perses.reduction.io.AbstractOutputManager
import org.perses.util.hashing.EnumShaAlgorithm
import java.nio.file.Path

abstract class AbstractGlobalExecutionCache {
  abstract fun getCachedResultOrNull(outputManager: AbstractOutputManager): PropertyTestResult?

  abstract fun cacheTestScriptResult(
    outputManager: AbstractOutputManager,
    result: PropertyTestResult,
  )

  abstract fun saveCacheEntriesToCsvFile(csvFileToSaveHistory: Path)

  class GlobalExecutionCache private constructor(
    private val history: TestScriptHistory,
  ) : AbstractGlobalExecutionCache() {
    override fun getCachedResultOrNull(outputManager: AbstractOutputManager): PropertyTestResult? {
      val key = outputManager.shaHashCode.digest
      return history.getExecutionHistoryFor(key)
    }

    override fun cacheTestScriptResult(
      outputManager: AbstractOutputManager,
      result: PropertyTestResult,
    ) {
      history.cacheExecutionHistory(
        key = outputManager.shaHashCode.digest,
        result,
      )
    }

    override fun saveCacheEntriesToCsvFile(csvFileToSaveHistory: Path) {
      history.saveToCSV(csvFileToSaveHistory)
    }

    companion object {
      fun createFromHistoryCvsFile(
        shaAlgorithm: EnumShaAlgorithm,
        csvFileToSaveHistory: Path,
      ): GlobalExecutionCache =
        GlobalExecutionCache(
          history = TestScriptHistory.loadFromCSV(shaAlgorithm, csvFileToSaveHistory),
        )

      fun createEmpty(shaAlgorithm: EnumShaAlgorithm): GlobalExecutionCache =
        GlobalExecutionCache(
          history = TestScriptHistory(shaAlgorithm),
        )
    }
  }

  class NullCache : AbstractGlobalExecutionCache() {
    override fun getCachedResultOrNull(outputManager: AbstractOutputManager): PropertyTestResult? =
      null

    override fun cacheTestScriptResult(
      outputManager: AbstractOutputManager,
      result: PropertyTestResult,
    ) {
      // Do nothing.
    }

    override fun saveCacheEntriesToCsvFile(csvFileToSaveHistory: Path) {
      // Do nothing.
    }
  }
}
