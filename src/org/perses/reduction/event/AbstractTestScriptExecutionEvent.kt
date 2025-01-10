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
package org.perses.reduction.event

import com.google.common.collect.ImmutableList
import org.perses.program.TokenizedProgram
import org.perses.reduction.PropertyTestResult
import org.perses.spartree.AbstractSparTreeEdit
import org.perses.util.FileNameContentPair

sealed class AbstractTestScriptExecutionEvent(
  currentTimeMillis: Long,
  val program: TokenizedProgram,
  val edit: AbstractSparTreeEdit<*>,
  outputCreator: (TokenizedProgram) -> ImmutableList<FileNameContentPair>,
) : AbstractReductionEvent(currentTimeMillis) {

  val textualProgram = LazyProgramOutputer(
    program,
    outputCreator,
  )

  class TestScriptExecutionEvent(
    currentTimeMillis: Long,
    val result: PropertyTestResult,
    program: TokenizedProgram,
    edit: AbstractSparTreeEdit<*>,
    outputCreator: (TokenizedProgram) -> ImmutableList<FileNameContentPair>,
  ) : AbstractTestScriptExecutionEvent(currentTimeMillis, program, edit, outputCreator)

  class TestResultCacheHitEvent(
    currentTimeMillis: Long,
    val result: PropertyTestResult,
    program: TokenizedProgram,
    edit: AbstractSparTreeEdit<*>,
    outputCreator: (TokenizedProgram) -> ImmutableList<FileNameContentPair>,
  ) : AbstractTestScriptExecutionEvent(currentTimeMillis, program, edit, outputCreator)

  class TestScriptExecutionCanceledEvent(
    currentTimeMillis: Long,
    val millisToCancelTheTask: Int,
    program: TokenizedProgram,
    edit: AbstractSparTreeEdit<*>,
    outputCreator: (TokenizedProgram) -> ImmutableList<FileNameContentPair>,
  ) : AbstractTestScriptExecutionEvent(currentTimeMillis, program, edit, outputCreator)
}
