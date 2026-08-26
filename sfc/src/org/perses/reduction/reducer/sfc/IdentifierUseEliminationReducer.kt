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
import com.google.common.collect.ImmutableListMultimap
import org.perses.reduction.AbstractNonDeletionBasedReducer
import org.perses.reduction.AbstractSparTreeReducer
import org.perses.reduction.FixpointReductionState
import org.perses.reduction.ReducerContext
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.LexerRuleSparTreeNode
import org.perses.spartree.NodeReplacementActionSet
import org.perses.spartree.SparTree
import org.perses.util.toImmutableList

/**
 * The last step of Algorithm 4 of the SFC paper: get rid of one use of an identifier by replacing
 * an ancestor of it with a smaller structure form conversion built without that use.
 *
 * The paper first tries to rename the uses of an identifier onto another name, which
 * `IdentifierReplacementReducer` of Vulcan already does, from the identifier token types the
 * parser facade declares. What is left to Structure Form Conversion is the case where no renaming
 * is accepted: walk up from the use and ask, of each ancestor in turn, for the structures of its
 * other alternatives that reuse none of the subtrees containing the use. A candidate is therefore
 * a version of that ancestor from which the use is gone.
 */
class IdentifierUseEliminationReducer(
  reducerContext: ReducerContext,
) : AbstractNonDeletionBasedReducer(META, reducerContext) {
  private val parserFacade = reducerContext.configuration.canonicalParserFacade
  private val converter = StructureFormConverter(parserFacade, reducerContext.sparTreeNodeFactory)
  private val sfcConfig = reducerContext.configuration.sfcConfig

  override fun internalReduce(fixpointReductionState: FixpointReductionState) {
    val tree = fixpointReductionState.inputRepresentation.tree
    mutationHistory.add(tree.programSnapshot.payload)
    for (use in identifierUsesOf(tree)) {
      // An accepted conversion takes whole subtrees away, including uses still to be visited.
      if (use.isPermanentlyDeleted) {
        continue
      }
      eliminate(use, tree, fixpointReductionState)
    }
  }

  /**
   * The identifier tokens of the tree, which are the uses to get rid of, one at a time, the last
   * occurrence of a name before the earlier ones.
   *
   * Which occurrence of a name defines it is a scoping rule of the language, not something a
   * grammar says, so nothing here classifies definitions: eliminating one simply fails the
   * property test, which is what the paper's algorithm tolerates. The order is a prior, not a
   * filter -- the first occurrence of a name is the likeliest to be its definition, so it is
   * tried last, and the work spent on failures is spent late.
   *
   * A language server or another source of real semantics could rule the definitions out
   * instead; the reduction driver has one in [org.perses.reduction.semantics.ISemanticsProvider]
   * when a language provides it. That is worth doing when the wasted property tests are shown to
   * matter, and it changes how long this reducer takes rather than what it can eliminate.
   */
  internal fun identifierUsesOf(tree: SparTree): ImmutableList<LexerRuleSparTreeNode> {
    val identifierTokenTypes = parserFacade.fusedIdentifierTokenTypes
    val occurrencesPerLexeme = ImmutableListMultimap.builder<String, LexerRuleSparTreeNode>()
    tree.realRoot
      .leafNodeSequence()
      .filter { it.token.asAntlrToken().tokenType in identifierTokenTypes }
      .forEach { occurrencesPerLexeme.put(it.token.lexemeText, it) }
    val occurrences = occurrencesPerLexeme.build()
    return occurrences
      .keySet()
      .flatMap { lexeme -> occurrences[lexeme].reversed() }
      .toImmutableList()
  }

  /**
   * Walks up from [use], and replaces the first ancestor for which the property test accepts a
   * structure built without the use. Nearest ancestor first, so that as little as possible of the
   * program is rebuilt.
   */
  private fun eliminate(
    use: LexerRuleSparTreeNode,
    tree: SparTree,
    fixpointReductionState: FixpointReductionState,
  ) {
    var ancestor = use.parent
    while (ancestor != null && !ancestor.isRootNode()) {
      for (candidate in candidatesWithoutTheUse(ancestor, use)) {
        val edit =
          tree.createAnyNodeReplacementEdit(
            NodeReplacementActionSet.createByReplacingSingleNode(
              targetNode = ancestor,
              replacingNode = candidate.tree,
              contextDescription =
                "replace a node ${ancestor.ruleName} with a smaller structure that " +
                  "does not use ${use.token.lexemeText}",
            ),
          )
        val payload =
          ignoreCachedEditsThenFindBestWrtProperty(listOf(edit), fixpointReductionState)
            ?: continue
        applyEditToTree(payload)
        return
      }
      ancestor = ancestor.parent
    }
  }

  /**
   * The conversions of [ancestor] that are smaller than it and reuse no subtree containing [use],
   * smallest first. A subtree contains the use exactly when the two overlap.
   */
  internal fun candidatesWithoutTheUse(
    ancestor: AbstractSparTreeNode,
    use: LexerRuleSparTreeNode,
  ): ImmutableList<StructureFormConverter.Candidate> {
    if (ancestor.leafTokenCount !in 2..sfcConfig.subtreeTokenCountLimit) {
      return ImmutableList.of()
    }
    return converter
      .convert(
        ancestor,
        isReuseAllowed = { subtreeRoot ->
          !StructureReuseFinder.doSubtreesOverlap(subtreeRoot, use)
        },
        shrinkOversizedCandidates = true,
      ).filter { it.leafTokenCount < ancestor.leafTokenCount }
      .take(sfcConfig.candidateLimit)
      .sortedBy { it.leafTokenCount }
      .toImmutableList()
  }

  object META : NonDeletionBasedReducerAnnotation(
    shortName = NAME,
    description =
      "Get rid of one use of an identifier by replacing an ancestor of it with a smaller " +
        "subtree of another alternative, built without the subtrees that contain the use.",
    reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE,
  ) {
    override fun create(reducerContext: ReducerContext): ImmutableList<AbstractSparTreeReducer> =
      ImmutableList.of(IdentifierUseEliminationReducer(reducerContext))
  }

  companion object {
    const val NAME = "sfc_identifier_use_elimination"
  }
}
