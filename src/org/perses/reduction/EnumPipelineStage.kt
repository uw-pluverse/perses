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

/**
 * The built-in stages of the default reduction pipeline, in their natural (coarse-to-fine) order, as
 * offered to [LanguageProfile.customizeReductionPipeline]. Each label identifies one step in the
 * sequence the framework assembles; a profile reorders/drops the pipeline by referring to these labels.
 */
enum class EnumPipelineStage {
  /** Coarse-grit latra, run before the main tree reducer. */
  COARSE_GRIT_LATRA,

  /** The main tree reducer (and cleanup), the core of the reduction. */
  MAIN,

  /** Coarse-grit token/line/tree slicers and t-rec canonicalization. */
  COARSE_GRIT,

  /** Medium-grit LPR (LLM-based) transformative reducers. */
  MEDIUM_GRIT_LPR,

  /** Medium-grit fine latra transformative reducer. */
  MEDIUM_GRIT_LATRA,

  /** Fine-grit vulcan reducers. */
  FINE_GRIT_VULCAN,

  /**
   * Fine-grit reducers based on structure form conversion.
   *
   * TODO: consolidate these with the reducers of [FINE_GRIT_VULCAN]. Both stages hold fine-grit
   *   auxiliary reducers that run after the main reducer, and one stage would list them once.
   *   What stands in the way is that each stage is repeated to a fixpoint under a flag of its
   *   own, --vulcan-fixpoint and --sfc-fixpoint, so a single stage needs one answer for both.
   */
  FINE_GRIT_SFC,
}
