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

import org.perses.antlr.util.AntlrToolWrapper
import org.perses.reduction.io.AbstractOutputManagerFactory
import org.perses.reduction.io.AbstractReductionIOManager

/**
 * The base for a reducer that reduces by producing and testing **whole candidate programs** -- the
 * entire [Program] at once -- rather than tree edits (contrast [AbstractSparTreeReducer]). The list-diff
 * reducer (whose program is a diff op-list) and the multi-file reducer (whose program is the whole
 * mutable-file set) are both of this kind.
 *
 * It drives reduction over a [State] and tests candidate programs with [testProgram]; subclasses
 * supply the language-/representation-specific [reduce] strategy.
 */
abstract class AbstractWholeProgramReducer<
  Program,
  IOManager : AbstractReductionIOManager<Program, IOManager>,
  State,
>(
  nameAndDesc: AbstractReducerNameAndDesc,
  ioManager: IOManager,
  testScriptExecutorService: TestScriptExecutorService,
  /**
   * The renderer (carries the code format) this reducer tests candidates through. Owned by the
   * reducer (supplied by the driver), not the IO manager, so rendering is decoupled from file IO.
   * `protected` so a subclass that renders candidates itself (e.g. [ListDiffDdmin]'s delta debugger)
   * can reuse it instead of holding its own copy.
   */
  protected val outputManagerFactory: AbstractOutputManagerFactory<Program>,
) : AbstractReducer<Program, IOManager>(
    nameAndDesc,
    ioManager,
    testScriptExecutorService,
  ) {
  /** Reduces the program tracked by [state], committing accepted improvements through it. */
  abstract fun reduce(state: State)

  /**
   * Whether [program] -- a complete candidate -- still passes the property test. The IO manager
   * renders the whole program into a folder and the test runs against it.
   *
   * Rendering or re-lexing a malformed candidate can throw an antlr error (e.g. a list-diff variant
   * reconstructed from the diff, or any program a grammar rejects); such a candidate is treated as
   * simply uninteresting rather than crashing the reduction.
   */
  protected fun testProgram(program: Program): Boolean =
    try {
      executorService
        .testProgramAsync(
          TestScriptExecutorService.ALWAYS_TRUE_PRECHECK,
          TestScriptExecutorService.IDENTITY_POST_CHECK,
          outputManagerFactory.createManagerFor(program),
          payload = DUMMY_PAYLOAD,
        ).getWithTimeoutWarnings()
        .isInteresting
    } catch (e: Throwable) {
      var exception: Throwable? = e
      while (exception != null && exception !is AntlrToolWrapper.AntlrException) {
        exception = exception.cause
      }
      if (exception is AntlrToolWrapper.AntlrException) {
        false
      } else {
        throw e
      }
    }

  companion object {
    private const val DUMMY_PAYLOAD = "candidate program"
  }
}
