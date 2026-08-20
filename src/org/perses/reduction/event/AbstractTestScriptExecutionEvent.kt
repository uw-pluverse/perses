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
package org.perses.reduction.event

import org.perses.program.TokenizedProgram
import org.perses.reduction.PropertyTestResult
import org.perses.reduction.io.AbstractOutputManager
import org.perses.spartree.AbstractSparTreeEdit

sealed class AbstractTestScriptExecutionEvent(
  currentTimeMillis: Long,
  val program: TokenizedProgram,
  val edit: AbstractSparTreeEdit<*>,
  val outputManager: AbstractOutputManager,
) : AbstractReductionEvent(currentTimeMillis) {
  val fileNameContentPairList by lazy {
    outputManager.fileContentList
  }

  class TestScriptExecutionEvent(
    currentTimeMillis: Long,
    val result: PropertyTestResult,
    program: TokenizedProgram,
    edit: AbstractSparTreeEdit<*>,
    outputManager: AbstractOutputManager,
  ) : AbstractTestScriptExecutionEvent(currentTimeMillis, program, edit, outputManager)

  class TestResultCacheHitEvent(
    currentTimeMillis: Long,
    program: TokenizedProgram,
    edit: AbstractSparTreeEdit<*>,
    outputManager: AbstractOutputManager,
  ) : AbstractTestScriptExecutionEvent(currentTimeMillis, program, edit, outputManager)

  class TestScriptExecutionCanceledEvent(
    currentTimeMillis: Long,
    val millisToCancelTheTask: Int,
    val program: TokenizedProgram,
    val edit: AbstractSparTreeEdit<*>,
  ) : AbstractReductionEvent(currentTimeMillis)
}
