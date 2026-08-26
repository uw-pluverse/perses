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
 * Structure Canonicalization (Section 3.2 of the SFC paper): replace a subtree with a structure
 * form conversion of it that spells as many tokens but comes from alternatives the grammar
 * spells earlier, which is the more canonical of the two (Definition 3.1).
 *
 * The point is not to reduce, since the program keeps its size, but to make programs that differ
 * only in which alternative they were parsed with converge on one form. The reducers that follow
 * then see the same structures over and over, and their caches answer for them.
 *
 * Every replacement moves the subtree strictly earlier in that order, so the traversal cannot
 * replace a subtree back into a structure it already had.
 */
class StructureCanonicalizationReducer(
  reducerContext: ReducerContext,
) : AbstractStructureFormConversionReducer(META, reducerContext) {
  private val alternativePath =
    RuleAlternativePath(reducerContext.configuration.canonicalParserFacade.ruleHierarchy)

  /**
   * The conversions of [node] that spell as many tokens as it does and are more canonical than
   * [node] itself, the most canonical first.
   *
   * Both are measured from the rule the node's position expects, so that the paths are
   * comparable: the path to the rule the node was parsed as, and the path to the rule of a
   * candidate. A candidate whose path is smaller comes from alternatives the grammar spells
   * earlier (Definition 3.1).
   */
  internal override fun candidatesFor(
    node: AbstractSparTreeNode,
  ): ImmutableList<StructureFormConverter.Candidate> {
    val payload = node.payload ?: return ImmutableList.of()
    val expectedRule = payload.expectedAntlrRuleType ?: return ImmutableList.of()
    val ruleOfNode = payload.actualAntlrRuleType ?: return ImmutableList.of()
    val pathOfNode =
      alternativePath.findSmallestPath(expectedRule, ruleOfNode) ?: return ImmutableList.of()
    return conversionsOf(node)
      .filter { it.leafTokenCount == node.leafTokenCount }
      .mapNotNull { candidate ->
        val pathOfCandidate =
          alternativePath.findSmallestPath(expectedRule, candidate.template.rule)
            ?: return@mapNotNull null
        val pathOfAlternative = pathOfCandidate + candidate.template.alternativeIndex
        if (RuleAlternativePath.LEXICOGRAPHIC_ORDER.compare(pathOfAlternative, pathOfNode) < 0) {
          pathOfAlternative to candidate
        } else {
          null
        }
      }.take(sfcConfig.candidateLimit)
      .sortedWith { left, right ->
        RuleAlternativePath.LEXICOGRAPHIC_ORDER.compare(left.first, right.first)
      }.map { it.second }
      .toImmutableList()
  }

  object META : NonDeletionBasedReducerAnnotation(
    shortName = NAME,
    description =
      "Replace a subtree with a subtree of the same size that comes from an alternative the " +
        "grammar spells earlier, so that programs converge on the same structures.",
    reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_REMAIN,
  ) {
    override fun create(reducerContext: ReducerContext): ImmutableList<AbstractSparTreeReducer> =
      ImmutableList.of(StructureCanonicalizationReducer(reducerContext))
  }

  companion object {
    const val NAME = "sfc_structure_canonicalization"
  }
}
