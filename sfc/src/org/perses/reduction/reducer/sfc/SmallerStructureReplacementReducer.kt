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
package org.perses.reduction.reducer.sfc

import com.google.common.collect.ImmutableList
import org.perses.reduction.AbstractSparTreeReducer
import org.perses.reduction.ReducerContext
import org.perses.spartree.AbstractSparTreeNode
import org.perses.util.toImmutableList

/**
 * Smaller Structure Replacement (Algorithm 3 of the SFC paper): replace a subtree with the
 * smallest structure form conversion of it that is strictly smaller and that the property test
 * accepts.
 */
class SmallerStructureReplacementReducer(
  reducerContext: ReducerContext,
) : AbstractStructureFormConversionReducer(META, reducerContext) {
  /** The conversions of [node] that are strictly smaller than it, smallest first. */
  internal override fun candidatesFor(
    node: AbstractSparTreeNode,
  ): ImmutableList<StructureFormConverter.Candidate> =
    conversionsOf(node, shrinkOversizedCandidates = true)
      .filter { it.leafTokenCount < node.leafTokenCount }
      .take(sfcConfig.candidateLimit)
      .sortedBy { it.leafTokenCount }
      .toImmutableList()

  object META : NonDeletionBasedReducerAnnotation(
    shortName = NAME,
    description =
      "Replace a subtree with a smaller subtree of another alternative of the same rule, " +
        "spelling again the content of the subtrees under the original one.",
    reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE,
  ) {
    override fun create(reducerContext: ReducerContext): ImmutableList<AbstractSparTreeReducer> =
      ImmutableList.of(SmallerStructureReplacementReducer(reducerContext))
  }

  companion object {
    const val NAME = "sfc_smaller_structure_replacement"
  }
}
