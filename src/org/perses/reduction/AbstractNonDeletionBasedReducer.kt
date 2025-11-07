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
package org.perses.reduction

import com.google.common.collect.ImmutableList
import org.perses.program.TokenizedProgram
import org.perses.program.printer.PrinterRegistry
import org.perses.spartree.AbstractSparTreeEdit
import org.perses.util.hashing.ShaHashCode

abstract class AbstractNonDeletionBasedReducer(
  reducerAnnotation: ReducerAnnotation,
  reducerContext: ReducerContext,
) : AbstractTokenReducer(
    reducerAnnotation,
    reducerContext,
  ) {
  protected val mutationHistory =
    reducerContext.computePiggybackPayloadIfAbsent(
      PiggybackPayloadKey(this::class.java, "mutated_program_history"),
    ) { MutatedProgramHistory() } as MutatedProgramHistory

  protected inner class MutatedProgramHistory {
    private val history = HashSet<ShaHashCode>()

    fun add(program: TokenizedProgram): Boolean {
      // TODO(cnsun): need to use the OutputManager-based hashing.
      val sourceCode = PrinterRegistry.printToStringInSingleLineFormat(program)
      val hashcode = reducerContext.configuration.shaHashAlgorithm.createFromString(sourceCode)
      return history.add(hashcode)
    }
  }

  protected fun ignoreCachedEditsThenFindBestWrtProperty(
    // TODO(cnsun): need to see whether we need to accept a single edit or a list of edits.
    edits: List<AbstractSparTreeEdit<*>>,
    fixpointReductionState: FixpointReductionState,
  ): AbstractSparTreeEdit<*>? {
    val filtered =
      edits.filter { edit ->
        if (mutationHistory.add(edit.program)) {
          true
        } else {
          reducerContext.listenerManager.onAdHocMessageEvent(
            fixpointReductionState.createAdHocMessageEvent {
              "An edit (description=${edit.actionSet.actionsDescription}) is skipped " +
                "in ${this::class.simpleName} because it was visited before."
            },
          )
          false
        }
      }
    return testAllTreeEditsAndReturnTheBest(filtered)?.edit
  }

  protected data class PiggybackPayloadKey(
    val owningClass: Class<*>,
    val payloadName: String,
    val extraData: ImmutableList<Any> = ImmutableList.of(),
  )

  abstract class NonDeletionBasedReducerAnnotation(
    shortName: String,
    description: String,
    reductionResultSizeTrend: ReductionResultSizeTrend,
  ) : ReducerAnnotation(
      shortName = shortName,
      description = description,
      // Given the same input, the algorithm might yield different results,
      // because this alg also depends on the cache in the reduction context.
      deterministic = false,
      reductionResultSizeTrend = reductionResultSizeTrend,
    )
}
