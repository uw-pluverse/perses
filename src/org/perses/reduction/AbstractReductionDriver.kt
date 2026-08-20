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

import com.google.common.flogger.FluentLogger
import com.google.common.io.Closer
import org.perses.reduction.io.AbstractOutputManager
import org.perses.reduction.io.AbstractReductionIOManager
import org.perses.util.TimeUtil.formatDateForDisplay
import org.perses.util.ktInfo
import java.io.Closeable

abstract class AbstractReductionDriver<
  Program,
  IOManager : AbstractReductionIOManager<Program, IOManager>,
>(
  protected val globalContext: GlobalContext,
  protected val ioManager: IOManager,
  // Created once and shared by every driver of a reduction, owned and closed by AbstractMain (so its
  // thread pools are reused across per-file sweeps / cross-file passes, and its statistics are the
  // whole-reduction total). This driver therefore does NOT register it with [closer].
  protected val executorService: TestScriptExecutorService,
  protected val hideTimestampsInLog: Boolean,
) : IReductionDriver {
  private val closer = Closer.create()

  override fun close() {
    try {
      closer.close()
    } catch (e: Throwable) {
      // ignore.
      e.printStackTrace()
    }
  }

  protected fun <T : Closeable> registerToClose(toBeClosed: T): T = closer.register(toBeClosed)

  protected fun printStartTime() {
    logger.ktInfo {
      val time =
        if (hideTimestampsInLog) {
          ""
        } else {
          formatDateForDisplay(System.currentTimeMillis())
        }
      "The reduction process started at $time"
    }
  }

  /**
   * The Layer-2 sanity check, run before each reducer starts: verify that the program reconstructed
   * from the reducer's current input representation -- already rendered into [outputManager] by the
   * caller -- still passes the property test. A reducer cannot reduce a program that is already
   * uninteresting (every candidate it produces is a subset and would also fail), so on failure this
   * throws [SanityCheckFailedException] to stop the reducer immediately. The caller is responsible
   * for reporting the exception to its listener manager before letting it propagate.
   *
   * This complements the Layer-1 check ([org.perses.AbstractMain.runInitialSanityCheck]),
   * which tests the populated result folder once before reduction begins. Layer 1 catches a broken
   * test script or a mis-populated folder; Layer 2 catches a representation that no longer preserves
   * the property (e.g. an Antlr parse/unparse round-trip that corrupts the program).
   */
  protected fun checkRepresentationPreservesPropertyOrThrow(
    outputManager: AbstractOutputManager,
    reducerName: String,
  ) {
    val result =
      executorService
        .testProgramAsyncWithoutPayload(
          preCheck = TestScriptExecutorService.ALWAYS_TRUE_PRECHECK,
          postCheck = TestScriptExecutorService.IDENTITY_POST_CHECK,
          outputManager,
        ).getWithTimeoutWarnings()
    if (result.isNotInteresting) {
      throw SanityCheckFailedException(
        "The per-reducer sanity check failed before running '$reducerName': the program " +
          "reconstructed from the current input representation no longer passes the property " +
          "test. A reducer cannot reduce an already-uninteresting program, so the reduction is " +
          "stopped.",
      )
    }
  }

  companion object {
    private val logger = FluentLogger.forEnclosingClass()
  }
}
