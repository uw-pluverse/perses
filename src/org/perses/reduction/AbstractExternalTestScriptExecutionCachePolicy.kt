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
package org.perses.reduction

import org.perses.reduction.io.AbstractOutputManager
import java.nio.file.Path

abstract class AbstractExternalTestScriptExecutionCachePolicy : AutoCloseable {

  abstract fun getCachedResultOrCompute(
    outputManager: AbstractOutputManager,
  ): TestScriptHistory.Result?

  abstract fun cacheTestScriptResult(
    outputManager: AbstractOutputManager,
    result: PropertyTestResult,
  )

  class ExternalTestScriptExecutionCachePolicy(
    private val historyCsvFile: Path,
    private val csvFileToSaveHistory: Path?,
  ) : AbstractExternalTestScriptExecutionCachePolicy() {

    private val history = TestScriptHistory.loadFromCSV(historyCsvFile)

    override fun getCachedResultOrCompute(
      outputManager: AbstractOutputManager,
    ): TestScriptHistory.Result? {
      val key = outputManager.shA512HashCode.digest
      return history.getExecutionHistoryFor(key)
    }

    override fun cacheTestScriptResult(
      outputManager: AbstractOutputManager,
      result: PropertyTestResult,
    ) {
      history.cacheExecutionHistory(
        key = outputManager.shA512HashCode.digest,
        TestScriptHistory.Result(result.exitCode, result.elapsedMilliseconds.toInt()),
      )
    }

    override fun close() {
      csvFileToSaveHistory?.let {
        history.saveToCSV(it)
      }
    }
  }

  class NullExternalTestScriptExecutionCachePolicy :
    AbstractExternalTestScriptExecutionCachePolicy() {
    override fun getCachedResultOrCompute(
      outputManager: AbstractOutputManager,
    ): TestScriptHistory.Result? {
      return null
    }

    override fun cacheTestScriptResult(
      outputManager: AbstractOutputManager,
      result: PropertyTestResult,
    ) {
      // Do nothing.
    }

    override fun close() {
      // Do nothing.
    }
  }
}
