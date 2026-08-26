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
package org.perses

import com.google.common.flogger.FluentLogger
import org.perses.cmd.CacheControlFlagGroup
import org.perses.cmd.EnumListMinimizerMicrobenchmarkingMode
import org.perses.cmd.EnumPassMode
import org.perses.cmd.ExperimentFlagGroup
import org.perses.cmd.InputFlagGroup
import org.perses.cmd.LPRFlagGroup
import org.perses.cmd.LanguageControlFlagGroup
import org.perses.cmd.LatraFlagGroup
import org.perses.cmd.ListMinimizerMicrobenchmarkingFlagGroup
import org.perses.cmd.MimirFlagGroup
import org.perses.cmd.OutputRefiningFlagGroup
import org.perses.cmd.PersesFlagGroup
import org.perses.cmd.ProfilingFlagGroup
import org.perses.cmd.ReductionAlgorithmControlFlagGroup
import org.perses.cmd.ReductionControlFlagGroup
import org.perses.cmd.SfcFlagGroup
import org.perses.cmd.TRecFlagGroup
import org.perses.cmd.VulcanFlagGroup
import org.perses.program.EnumFormatControl

/** Parser for command line arguments.  */
open class PersesCommandOptions : AbstractPersesCommandOptions() {
  val inputFlags = registerFlags(createInputFlags())

  val reductionControlFlags = registerFlags(ReductionControlFlagGroup())

  val outputRefiningFlags = registerFlags(OutputRefiningFlagGroup())

  val algorithmControlFlags =
    registerFlags(
      ReductionAlgorithmControlFlagGroup(),
    )

  val languageControlFlags = registerFlags(LanguageControlFlagGroup())

  open val persesFlags = registerFlags(PersesFlagGroup())

  val vulcanFlags = registerFlags(VulcanFlagGroup())

  open val trecFlags = registerFlags(TRecFlagGroup())

  val profilingFlags = registerFlags(ProfilingFlagGroup())

  val cacheControlFlags = registerFlags(CacheControlFlagGroup())

  val listMinimizerMicrobenchmarkingFlags = registerFlags(ListMinimizerMicrobenchmarkingFlagGroup())

  val experimentFlags = registerFlags(ExperimentFlagGroup())

  val lprFlags = registerFlags(LPRFlagGroup())

  open val latraFlags = registerFlags(LatraFlagGroup())

  open val sfcFlags = registerFlags(SfcFlagGroup())

  open val mimirFlags = registerFlags(MimirFlagGroup())

  open fun createInputFlags() = InputFlagGroup()

  override fun validateExtra() {
    // The line slicer needs the code format to keep each source line intact so that a line can be
    // sliced as a unit. With SINGLE_TOKEN_PER_LINE every token is printed on its own line, so line
    // slicing would silently degenerate into token slicing. Reject this combination only when the
    // line slicer is unconditionally on: with auto, whether it runs is per-file (the driver
    // soft-disables it with a warning for this format), so a hard error would be wrong.
    require(
      !(
        algorithmControlFlags.lineSlicer == EnumPassMode.ON &&
          reductionControlFlags.codeFormat == EnumFormatControl.SINGLE_TOKEN_PER_LINE
      ),
    ) {
      "The line slicer (--line-slicer on) is incompatible with " +
        "--code-format ${EnumFormatControl.SINGLE_TOKEN_PER_LINE}: each token is printed on its " +
        "own line, so line slicing would degenerate into token slicing. Please pick a different " +
        "--code-format, e.g. ${EnumFormatControl.COMPACT_ORIG_FORMAT}."
    }
    forceGlobalFixpointOffUnderListMinimizerEvaluation()
  }

  /**
   * EVALUATE measures one minimizer on one recorded list, so it must run that minimizer exactly
   * once; a global fixpoint would re-run it against the program the first run already shrank and
   * report several measurements as if they were one.
   *
   * Overridden here rather than relied upon: the evaluation driver does bypass the fixpoint (it
   * overrides `createReducerExecutionPlan`), but that bypass is invisible from the command line, so
   * a run with `--global-fixpoint true` would otherwise report a value it did not honor. Doing it
   * during validation also means the value dumped into the progress log and into a recorded
   * microbenchmark's `commandLineOptions` is the one that actually ran.
   */
  private fun forceGlobalFixpointOffUnderListMinimizerEvaluation() {
    if (listMinimizerMicrobenchmarkingFlags.mode !=
      EnumListMinimizerMicrobenchmarkingMode.EVALUATE
    ) {
      return
    }
    if (!reductionControlFlags.globalFixpoint) {
      return
    }
    reductionControlFlags.globalFixpoint = false
    logger.atWarning().log(
      "--global-fixpoint was requested but is ignored under " +
        "--list-minimizer-microbenchmarking-mode EVALUATE, which runs the minimizer under " +
        "evaluation exactly once. Proceeding with --global-fixpoint false.",
    )
  }

  companion object {
    private val logger = FluentLogger.forEnclosingClass()
  }
}
