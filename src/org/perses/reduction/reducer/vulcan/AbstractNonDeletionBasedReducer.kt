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
package org.perses.reduction.reducer.vulcan

import com.google.common.collect.ImmutableList
import org.perses.program.TokenizedProgram
import org.perses.program.printer.PrinterRegistry
import org.perses.reduction.AbstractTokenReducer
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.spartree.AbstractSparTreeEdit
import org.perses.util.Util

abstract class AbstractNonDeletionBasedReducer(
  reducerAnnotation: ReducerAnnotation,
  reducerContext: ReducerContext,
) : AbstractTokenReducer(
  reducerAnnotation,
  reducerContext,
) {

  protected val mutationHistory = reducerContext.computePiggybackPayloadIfAbsent(
    PiggybackPayloadKey(this::class.java, "mutated_program_history"),
  ) { MutatedProgramHistory() } as MutatedProgramHistory

  protected class MutatedProgramHistory {
    private val history = HashSet<Util.SHA512HashCode>()

    fun add(program: TokenizedProgram): Boolean {
      val sourceCode = PrinterRegistry.printToStringInSingleLineFormat(program)
      val hashcode = Util.SHA512HashCode.createFromString(sourceCode)
      return history.add(hashcode)
    }
  }

  protected fun testAndCacheUnseenResultedProgram(
    edit: AbstractSparTreeEdit<*>,
  ): AbstractSparTreeEdit<*>? {
    if (!mutationHistory.add(edit.program)) {
      return null
    }
    return testAllTreeEditsAndReturnTheBest(
      listOf(edit),
    )?.edit
  }

  protected data class PiggybackPayloadKey(
    val owningClass: Class<*>,
    val payloadName: String,
    val extraData: ImmutableList<Any> = ImmutableList.of(),
  )
}
