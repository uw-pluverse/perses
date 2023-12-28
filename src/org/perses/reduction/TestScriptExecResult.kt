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

import org.perses.reduction.TestScriptExecutorService.AbstractOutputManagerCreatorResult
import org.perses.reduction.TestScriptExecutorService.AbstractOutputManagerCreatorResult.EmptyResult
import org.perses.reduction.TestScriptExecutorService.AbstractOutputManagerCreatorResult.ProceedResult
import org.perses.reduction.TestScriptExecutorService.AbstractOutputManagerCreatorResult.StopResult
import org.perses.reduction.io.ReductionFolder
import java.util.concurrent.CancellationException

class TestScriptExecResult<Payload : Any>(
  val workingDirectory: ReductionFolder,
  val outputManagerCreatorFuture: RestrictedFuture<AbstractOutputManagerCreatorResult<Payload>>,
  val testScriptExecFuture: RestrictedFuture<PropertyTestResult?>,
) {

  private val outputManagerCreatorResult by lazy {
    try {
      outputManagerCreatorFuture.getWithTimeoutWarnings()
        ?: EmptyResult()
    } catch (e: CancellationException) {
      EmptyResult()
    }
  }

  val payload: Payload?
    get() = when (val t = outputManagerCreatorResult) {
      is EmptyResult -> null
      is ProceedResult -> t.payload
      is StopResult -> t.payload
    }

  fun cancelWithInterruption() {
    // First cancel the script execution, as it depends on the output manager creator, to avoid
    // exceptions.
    testScriptExecFuture.cancelWithInterruption()
    outputManagerCreatorFuture.cancelWithInterruption()
  }

  fun getWithTimeoutWarnings(): PropertyTestResult {
    return testScriptExecFuture.getWithTimeoutWarnings()
      ?: return PropertyTestResult.NON_INTERESTING_RESULT
  }

  fun isDone() = outputManagerCreatorFuture.isDone() && testScriptExecFuture.isDone()
}
