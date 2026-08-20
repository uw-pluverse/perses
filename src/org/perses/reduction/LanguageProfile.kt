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

import com.google.common.collect.ImmutableList
import org.perses.program.LanguageKind
import org.perses.reduction.crossfile.CrossFileProgramTransformation
import org.perses.reduction.scheduler.ReducerExecutionPlan.AbstractExecutionPlanStep

/**
 * A profile that customizes the perses reduction framework for a particular language-oriented binary
 * (e.g. `perses_cxx`). It is the configuration object through which a binary contributes
 * language-specific reducers without the core (`//src`) having to depend on them — the profile itself
 * lives in the contributing module (e.g. `//astra`), so it may freely reference that module's
 * reducers, while the framework only sees this interface.
 *
 * A binary selects its profile by overriding [org.perses.AbstractMain.languageProfile]; the default
 * is [DEFAULT] (an empty profile), so the plain `perses` binary is unaffected.
 */
interface LanguageProfile {
  /**
   * Reducers this profile registers on top of the built-ins, making them selectable by short name
   * (`--alg`) and visible in `--list-algs`. Registration is independent of execution: returning a
   * reducer here does not by itself run it (weaving into the pipeline is done by
   * [customizeReductionPipeline]); conversely a woven reducer need not be registered.
   */
  fun extraReducerAnnotations(): ImmutableList<ReducerAnnotation> = ImmutableList.of()

  /**
   * Cross-file (whole-set) transformations this profile contributes. They run as a post-pass after
   * the per-file reduction has finished, over the reduced result folder, where one transformation
   * may edit several files at once (e.g. removing an override family across files). The default is
   * none, so the plain `perses` binary does no cross-file reduction.
   */
  fun crossFileTransformations(): ImmutableList<out CrossFileProgramTransformation> =
    ImmutableList.of()

  /**
   * Customizes the reduction pipeline: reorders or drops the built-in stages, and weaves this
   * profile's own reducers in at any position(s). The framework hands over [defaultPipeline] — every
   * built-in stage in its default (coarse-to-fine) order, each labeled with its [EnumPipelineStage] (an
   * inactive stage, e.g. one disabled by a flag, is still present with a null [LabeledPipelineStep.step])
   * — and `createReductionStep`, a lambda that wraps a list of reducers into a single medium-grit
   * transformative step (or null when there is nothing to run, e.g. the only reducer is the one already
   * chosen as the main algorithm), so the profile never depends on the scheduler internals. The returned
   * list is the steps, in the exact order they should run; the profile builds it by passing through the
   * built-in steps it wants and splicing in `createReductionStep(myReducers)` wherever it wants them to
   * run — different reducers can go to different places.
   *
   * The list may contain nulls (an inactive built-in stage, or a `createReductionStep` that produced
   * nothing); the caller filters them out, so the profile does not have to. After filtering it must be
   * non-empty and should retain the [EnumPipelineStage.MAIN] step (dropping the main reducer disables the
   * core of the reduction). The default implementation keeps the framework's order unchanged (weaving
   * nothing), so the plain `perses` binary is unaffected.
   */
  fun customizeReductionPipeline(
    language: LanguageKind,
    defaultPipeline: ImmutableList<LabeledPipelineStep>,
    createReductionStep: (reducers: ImmutableList<ReducerAnnotation>) -> AbstractExecutionPlanStep?,
  ): List<AbstractExecutionPlanStep?> = defaultPipeline.map { it.step }

  companion object {
    /** The empty profile used by the core `perses` binary: no extra reducers, no pipeline changes. */
    val DEFAULT: LanguageProfile = object : LanguageProfile {}
  }
}
