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
package org.perses.reduction.crossfile

import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableMap
import org.perses.program.AbstractReductionFile
import org.perses.reduction.AbstractReducerNameAndDesc
import org.perses.reduction.TestScriptExecutorService
import org.perses.reduction.io.AbstractOutputManagerFactory

/**
 * A multi-file reducer driven by an ordered list of [CrossFileProgramTransformation]s. Each
 * transformation is asked for whole-set variants of the current best, the smallest
 * property-preserving improvement is committed, and the process repeats.
 *
 * The schedule mirrors the astra MAIN phase: every transformation is run to its own local fixpoint,
 * and the whole sweep is repeated to a global fixpoint, so transformations that re-enable one
 * another are driven to completion within a single reducer invocation.
 *
 * Progress -- and therefore termination -- is by **non-blank character count** over the set: a
 * variant is accepted only when it is strictly smaller than the current best, so the size decreases
 * monotonically and is bounded below by zero. Non-blank character count is the framework's cheap,
 * formatting-robust stand-in for token count (it is also what the query cache evicts on), so the
 * reducer's notion of "smaller" matches the rest of the pipeline. (Canonical token count would be
 * more principled but needs a parser facade, which this language-agnostic layer avoids.)
 */
class CrossFileTransformationReducer(
  nameAndDesc: AbstractReducerNameAndDesc,
  ioManager: CrossFileReductionIOManager,
  testScriptExecutorService: TestScriptExecutorService,
  outputManagerFactory: AbstractOutputManagerFactory<CrossFileProgram>,
  private val transformations: ImmutableList<out CrossFileProgramTransformation>,
) : AbstractCrossFileReducer(
    nameAndDesc,
    ioManager,
    testScriptExecutorService,
    outputManagerFactory,
  ) {
  override fun reduce(state: CrossFileReductionState) {
    while (true) {
      var changedInSweep = false
      for (transformation in transformations) {
        changedInSweep = runToLocalFixpoint(transformation, state) || changedInSweep
      }
      if (!changedInSweep) break
    }
  }

  private fun runToLocalFixpoint(
    transformation: CrossFileProgramTransformation,
    state: CrossFileReductionState,
  ): Boolean {
    var changed = false
    while (true) {
      val current = state.bestProgram.fileContents
      val improvement =
        smallestInterestingSmallerThan(current, transformation.transform(current)) ?: break
      state.updateBest(improvement)
      changed = true
    }
    return changed
  }

  /**
   * Tests the variants strictly smaller than [current] smallest-first and returns the first (hence
   * smallest) one that still passes the property test, or null if none improves on [current].
   */
  private fun smallestInterestingSmallerThan(
    current: ImmutableMap<AbstractReductionFile<*, *>, String>,
    variants: ImmutableList<ImmutableMap<AbstractReductionFile<*, *>, String>>,
  ): CrossFileProgram? {
    val currentSize = nonBlankCharacterCount(current)
    return variants
      .asSequence()
      .filter { nonBlankCharacterCount(it) < currentSize }
      .sortedBy { nonBlankCharacterCount(it) }
      .map { CrossFileProgram(it) }
      .firstOrNull { testProgram(it) }
  }

  private fun nonBlankCharacterCount(
    fileContents: Map<AbstractReductionFile<*, *>, String>,
  ): Int = fileContents.values.sumOf { content -> content.count { !Character.isWhitespace(it) } }
}
