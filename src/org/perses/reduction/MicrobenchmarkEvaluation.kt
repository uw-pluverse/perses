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
import org.perses.grammar.AbstractParserFacade
import org.perses.listminimizer.AbstractListMinimizerListener
import org.perses.listminimizer.EnumListMinimizerType
import org.perses.listminimizer.ListMinimizerProgressListener
import org.perses.listminimizer.NullListMinimizerListener
import org.perses.listminimizer.microbenchmark.ListMinimizationMicrobenchmark
import org.perses.listminimizer.microbenchmark.ListMinimizerEvaluationRunLog
import org.perses.program.AbstractReductionFile
import org.perses.util.FileSystemUtil
import java.nio.file.Path

/**
 * One recorded microbenchmark's worth of measurement: each of `--list-minimizers-to-evaluate`
 * against that one problem, in this process, one [ListMinimizerEvaluationDriver] apiece.
 *
 * A class rather than methods on the main, because none of this is something every perses binary
 * does: `AbstractMain` is the base of the ppr mains too, and they can neither run an evaluation nor
 * honour its flags. What the main still owns is the wiring it is positioned to do -- reading the
 * recording, locating the file its ranges index into, building the driver params and the facade --
 * and it hands the result here.
 *
 * A process measures several minimizers because setup is what a process per measurement was paying
 * for: constructing the language's parser facade re-parses a whole PNF grammar, and the recorded
 * program is read, lexed twice, parsed and simplified. None of that is per-minimizer work. What
 * *is* per-minimizer is kept per-minimizer, and that is what makes a measurement here equal to one
 * in a process of its own -- see the acceptance test in
 * `//test/org/perses/benchmark_toys/list_minimizer_evaluation`:
 *
 * - a private tree, copied from the first measurement's, because a minimizer commits its accepted
 *   bests into the tree it is given;
 * - an emptied query cache, cleared by the driver, so one minimizer cannot inherit another's
 *   rejected candidates;
 * - the result folder restored, since a committed best is written there and a driver reads the
 *   target's siblings from it;
 * - its own output directory and its own reducer name, so the metrics files and the statistics
 *   tables stay separate.
 */
class MicrobenchmarkEvaluation(
  private val params: ReductionDriverParams,
  private val mainFile: AbstractReductionFile<*, *>,
  private val parserFacade: AbstractParserFacade,
  private val microbenchmark: ListMinimizationMicrobenchmark,
  /**
   * Puts the recorded inputs back into the result folder, called before every measurement.
   *
   * A callback because the result folder and the inputs belong to the main, and reaching back for
   * them would hand this class the whole main to get at two fields.
   */
  private val restoreResultFolder: () -> Unit,
) {
  private val flags = params.cmd.listMinimizerMicrobenchmarkingFlags

  fun run() {
    val outputRoot = FileSystemUtil.ensureDirExists(flags.evaluationOutputDirectory!!)
    var failureCount = 0
    // Built by the first measurement and copied by the rest: parsing the recorded program is the
    // last per-measurement cost of any size, and a copy inherits everything a parse would recompute.
    var prototypeInputRepresentation: InputRepresentation? = null
    createProgressListener().use { progressListener ->
      ListMinimizerEvaluationRunLog(
        file = outputRoot.resolve(ListMinimizerEvaluationRunLog.RUN_LOG_FILE_NAME),
        hideTimings = params.cmd.verbosityFlags.hideTimestamps,
      ).use { runLog ->
        for (minimizerType in flags.listMinimizersToEvaluate) {
          val measurement =
            measureOneMinimizer(
              minimizerType = minimizerType,
              outputRoot = outputRoot,
              progressListener = progressListener,
              runLog = runLog,
              prototypeInputRepresentation = prototypeInputRepresentation,
            )
          prototypeInputRepresentation = prototypeInputRepresentation ?: measurement.prototype
          if (!measurement.succeeded) {
            ++failureCount
          }
        }
      }
    }
    // One bad minimizer must not cost the others their measurement, but a process where nothing
    // could be measured is a broken invocation rather than a result, and should not exit zero.
    check(failureCount < flags.listMinimizersToEvaluate.size) {
      "Every one of the $failureCount requested measurement(s) failed; see the log above and " +
        "${ListMinimizerEvaluationRunLog.RUN_LOG_FILE_NAME} in $outputRoot."
    }
  }

  /**
   * One measurement, and what it leaves behind.
   *
   * A failure is contained rather than propagated: the minimizers after this one are independent
   * measurements of the same recorded problem, and there is no reason a sweep should lose them.
   * What can arrive here is narrower than it looks -- `callReducer` already catches and reports
   * what a reducer throws -- so this is the sanity check on the rendered tree, the driver's own
   * "ran exactly once" assertion, and anything thrown while the driver is being built.
   */
  private fun measureOneMinimizer(
    minimizerType: EnumListMinimizerType,
    outputRoot: Path,
    progressListener: AbstractListMinimizerListener,
    runLog: ListMinimizerEvaluationRunLog,
    prototypeInputRepresentation: InputRepresentation?,
  ): Measurement {
    val startMillis = System.currentTimeMillis()
    var prototype: InputRepresentation? = null
    var oneMinimality: ListMinimizerEvaluationReducer.OneMinimalityReport? = null
    var programTokensBefore: Int? = null
    var programTokensAfter: Int? = null
    try {
      restoreResultFolder()
      ListMinimizerEvaluationDriver
        .create(
          params = params,
          mainFile = mainFile,
          resolvedParserFacade = parserFacade,
          microbenchmark = microbenchmark,
          minimizerType = minimizerType,
          // A directory per minimizer under --evaluation-output, rather than the output root
          // itself: the metrics file names are fixed and their streams truncate, so two
          // measurements sharing a directory would leave only the second one's numbers.
          outputDirectory = FileSystemUtil.ensureDirExists(outputRoot.resolve(minimizerType.name)),
          sharedProgressListener = progressListener,
          prototypeInputRepresentation = prototypeInputRepresentation,
        ).use { driver ->
          // Copied before the run, not after: this measurement is about to commit its accepted
          // bests into that very tree, and what the next one needs is the program as recorded.
          if (prototypeInputRepresentation == null) {
            prototype = driver.inputRepresentation.withPrivateTreeCopy()
          }
          driver.reduce()
          oneMinimality = driver.oneMinimality
          programTokensBefore = driver.programTokensBefore
          programTokensAfter = driver.programTokensAfter
        }
    } catch (failure: Exception) {
      // Logged rather than reported through listenerManager.onCriticalException: that channel
      // means the reduction hit something it cannot continue past, and the pipeline rethrows what
      // it is given once the run ends -- which would undo the containment this method exists for.
      // A measurement that failed is a result, recorded in the run log like any other.
      // withCause, so the stack reaches the log: runs.jsonl deliberately records only the type
      // and the message, and this is now the only place the whole trace appears.
      logger.atWarning().withCause(failure).log(
        "Measuring %s failed; the remaining minimizers are unaffected.",
        minimizerType,
      )
      runLog.recordFailure(minimizerType, System.currentTimeMillis() - startMillis, failure)
      return Measurement(succeeded = false, prototype = prototype)
    }
    val measured = checkNotNull(oneMinimality) { "$minimizerType produced no result to assess." }
    runLog.recordSuccess(
      minimizerType,
      System.currentTimeMillis() - startMillis,
      oneMinimalityViolationCount = measured.violationCount,
      programTokensBefore = checkNotNull(programTokensBefore),
      programTokensAfter = checkNotNull(programTokensAfter),
    )
    return Measurement(succeeded = true, prototype = prototype)
  }

  /**
   * The `--profile-list-minimizer` trace, one for the whole process.
   *
   * Shared rather than built per driver, because [ListMinimizerProgressListener] truncates the file
   * it opens: one per measurement would leave only the last one's trace at the path the user named.
   * One file loses nothing -- each run's block opens with its algorithm and a description prefix
   * carrying the minimizer's name.
   */
  private fun createProgressListener(): AbstractListMinimizerListener =
    params.cmd.profilingFlags.profileListMinimizer
      ?.let { ListMinimizerProgressListener(it) }
      ?: NullListMinimizerListener

  /**
   * Whether a measurement succeeded, and -- for the first one only -- the pristine representation
   * the measurements after it copy instead of parsing. Carried out even from a failed measurement,
   * since what failed to be reused is the parse, not the program.
   */
  private class Measurement(
    val succeeded: Boolean,
    val prototype: InputRepresentation?,
  )

  companion object {
    private val logger = FluentLogger.forEnclosingClass()
  }
}
