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
package org.perses.antlr.reducer.pass

import org.perses.antlr.ast.PersesGrammar
import org.perses.antlr.reducer.io.GrammarReductionIOManager
import org.perses.antlr.util.AntlrToolWrapper
import org.perses.program.LanguageKind
import org.perses.reduction.AbstractReducer
import org.perses.reduction.ListenableReductionState
import org.perses.reduction.TestScriptExecutorService
import org.perses.reduction.TestScriptExecutorService.Companion.IDENTITY_POST_CHECK

abstract class AbstractAntlrReducer(
  ioManager: GrammarReductionIOManager,
  testScriptExecutorService: TestScriptExecutorService,
) : AbstractReducer<PersesGrammar, LanguageKind, GrammarReductionIOManager>(
  ioManager,
  testScriptExecutorService,
) {

  abstract fun reduce(state: ListenableReductionState<PersesGrammar>)

  fun testProgram(program: PersesGrammar): Boolean {
    try {
      return executorService.testProgramAsync(
        TestScriptExecutorService.ALWAYS_TRUE_PRECHECK,
        IDENTITY_POST_CHECK,
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
}
