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

import org.perses.reduction.scheduler.ReducerExecutionPlan.AbstractExecutionPlanStep

/**
 * One built-in stage of the reduction pipeline together with the [EnumPipelineStage] that identifies it.
 * Offered to [LanguageProfile.customizeReductionPipeline] so a profile can reorder/drop the pipeline by
 * [stage] and position its own woven steps relative to these, while passing the opaque [step] through to
 * the scheduler. [step] is null when the stage is inactive (e.g. its reducers are disabled by a flag),
 * so every stage is still represented for reference.
 */
data class LabeledPipelineStep(
  val stage: EnumPipelineStage,
  val step: AbstractExecutionPlanStep?,
)
