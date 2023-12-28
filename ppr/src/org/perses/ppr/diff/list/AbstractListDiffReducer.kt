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
package org.perses.ppr.diff.list

import com.google.common.collect.ImmutableList
import com.google.common.flogger.FluentLogger
import org.perses.antlr.util.AntlrToolWrapper
import org.perses.program.LanguageKind
import org.perses.program.PersesTokenFactory.PersesToken
import org.perses.reduction.AbstractReducer
import org.perses.reduction.TestScriptExecutorService
import org.perses.util.AbstractEditOperation

abstract class AbstractListDiffReducer(
  ioManager: ListDiffReductionIOManager,
  testScriptExecutorService: TestScriptExecutorService,
) : AbstractReducer<
  ImmutableList<AbstractEditOperation<PersesToken>>,
  LanguageKind,
  ListDiffReductionIOManager,
  >(
  ioManager,
  testScriptExecutorService,
) {

  abstract fun reduce(state: ListDiffReductionState)

  // TODO(cnsun): check to eliminate this.
  fun testProgram(
    program: ImmutableList<AbstractEditOperation<PersesToken>>,
  ): Boolean {
    try {
      return executorService.testProgramAsync(
        TestScriptExecutorService.ALWAYS_TRUE_PRECHECK,
        TestScriptExecutorService.IDENTITY_POST_CHECK,
        ioManager.createOutputManager(program),
        payload = "dummy payload",
      ).getWithTimeoutWarnings().isInteresting
    } catch (e: Throwable) {
      var exception: Throwable? = e
      while (exception != null && exception !is AntlrToolWrapper.AntlrException) {
        exception = exception.cause
      }
      if (exception is AntlrToolWrapper.AntlrException) {
        return false
      } else {
        throw e
      }
    }
  }

  companion object {
    val logger = FluentLogger.forEnclosingClass()
  }
}
