/*
 * Copyright (C) 2018-2025 University of Waterloo.
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
package org.perses.reduction.reducer.vulcan

import com.google.common.collect.ImmutableList
import org.perses.program.PersesTokenFactory.PersesAntlrToken
import org.perses.reduction.AbstractNonDeletionBasedReducer
import org.perses.reduction.AbstractTokenReducer
import org.perses.reduction.FixpointReductionState
import org.perses.reduction.ReducerContext
import org.perses.spartree.AbstractSparTreeEdit
import org.perses.spartree.LexerRuleSparTreeNode
import org.perses.spartree.SparTree
import org.perses.util.Util.lazyAssert
import org.perses.util.isSortedAscendingly
import org.perses.util.toImmutableList

class IdentifierReplacementReducer(
  reducerContext: ReducerContext,
) : AbstractNonDeletionBasedReducer(META, reducerContext) {
  override fun internalReduce(fixpointReductionState: FixpointReductionState) {
    val tree = fixpointReductionState.sparTree.getTreeRegardlessOfParsability()
    val candidates =
      Candidates.compute(
        tokenSequence = tree.leafNodeSequence(),
        isIdentifier = { token: PersesAntlrToken ->
          reducerContext.configuration.parserFacade.identifierTokenTypes
            .contains(token.tokenType)
        },
      )
    val heuristicEdit =
      heuristicFindInterestingReplacementEdit(
        tree,
        candidates,
        fixpointReductionState,
      )
    if (heuristicEdit != null) {
      reducerContext.listenerManager.onAdHocMessageEvent(
        fixpointReductionState.createAdHocMessageEvent {
          "A heuristic edit is found in ${this::class.simpleName}"
        },
      )
      tree.applyEdit(heuristicEdit)
      return
    }
    val singleTokenEdit =
      bruteForceFindInterestingReplacementEdit(
        tree,
        candidates,
        fixpointReductionState,
      ) ?: return

    reducerContext.listenerManager.onAdHocMessageEvent(
      fixpointReductionState.createAdHocMessageEvent {
        "A heuristic single-token edit is found in ${this::class.simpleName}"
      },
    )
    tree.applyEdit(singleTokenEdit)
  }

  /**
   * The heuristic that can be applied here is to replace all the identifiers with same lexeme
   * except its first appearance, which is likely to be the definition of the identifier. In this
   * way, what the edits do is more likely to be removing all the usages of the identifier. If the
   * program obtained after the edits still preserve the property, then the definition of the
   * identifier is very likely to be deletable
   */
  private fun heuristicFindInterestingReplacementEdit(
    tree: SparTree,
    candidates: Candidates,
    fixpointReductionState: FixpointReductionState,
  ) = findInterestingReplacementEditSkeleton(
    tree,
    candidates,
    fixpointReductionState,
    sequenceOfLexerNodesToBeReplaced = { clusterToBeReplaced ->
      val clusterSize = clusterToBeReplaced.lexerNodes.size
      if (clusterSize == 1) {
        // The only lexer node in this cluster is probably the definition node.
        sequenceOf()
      } else {
        sequenceOf(clusterToBeReplaced.lexerNodes.subList(1, clusterSize))
      }
    },
  )

  private fun bruteForceFindInterestingReplacementEdit(
    tree: SparTree,
    candidates: Candidates,
    fixpointReductionState: FixpointReductionState,
  ) = findInterestingReplacementEditSkeleton(
    tree,
    candidates,
    fixpointReductionState,
    sequenceOfLexerNodesToBeReplaced = { clusterToBeReplaced ->
      clusterToBeReplaced.lexerNodes.asSequence().map { listOf(it) }
    },
  )

  private inline fun findInterestingReplacementEditSkeleton(
    tree: SparTree,
    candidates: Candidates,
    fixpointReductionState: FixpointReductionState,
    sequenceOfLexerNodesToBeReplaced: (LexerNodeClusterWithSameLexeme)
    -> Sequence<List<LexerRuleSparTreeNode>>,
  ): AbstractSparTreeEdit<*>? {
    for (clusterToBeReplaced in candidates.tokenClusterWithSameLexemes) {
      val replacementLexemeCandidates =
        candidates
          .computeReplacementCandidates(clusterToBeReplaced)
          .map { it.lexeme }
      val edit =
        sequenceOfLexerNodesToBeReplaced(clusterToBeReplaced)
          .flatMap { lexerNodesToBeReplaced ->
            replacementLexemeCandidates.asSequence().map { replacementLexeme ->
              val edit =
                TokenEditUtility.createEditToReplaceMultiNodes(
                  tree,
                  replacementLexeme,
                  lexerNodesToBeReplaced,
                )
              ignoreCachedEditsThenFindBestWrtProperty(listOf(edit), fixpointReductionState)
            }
          }.firstOrNull {
            it != null
          }
      return edit ?: continue
    }
    return null
  }

  internal class Candidates(
    val tokenClusterWithSameLexemes: ImmutableList<LexerNodeClusterWithSameLexeme>,
  ) {
    init {
      lazyAssert { tokenClusterWithSameLexemes.isSortedAscendingly() }
    }

    fun getClusterWithName(name: String): LexerNodeClusterWithSameLexeme? =
      tokenClusterWithSameLexemes.find {
        it.lexeme == name
      }

    fun computeReplacementCandidates(
      tokenToBeReplaced: LexerNodeClusterWithSameLexeme,
    ): ImmutableList<LexerNodeClusterWithSameLexeme> {
      lazyAssert { tokenToBeReplaced in tokenClusterWithSameLexemes }
      return tokenClusterWithSameLexemes
        .asSequence()
        .filter { it !== tokenToBeReplaced }
        .sortedWith(LexerNodeClusterWithSameLexeme.ascendingComparator.reversed())
        .toImmutableList()
    }

    companion object {
      inline fun compute(
        tokenSequence: Sequence<LexerRuleSparTreeNode>,
        crossinline isIdentifier: (PersesAntlrToken) -> Boolean,
      ): Candidates =
        Candidates(
          tokenSequence
            .filter { isIdentifier(it.token.asAntlrToken()) }
            .groupBy { it.token.lexemeText }
            .values
            .asSequence()
            .map { LexerNodeClusterWithSameLexeme(ImmutableList.copyOf(it)) }
            .sorted()
            .toImmutableList(),
        )
    }
  }

  class LexerNodeClusterWithSameLexeme(
    val lexerNodes: ImmutableList<LexerRuleSparTreeNode>,
  ) : Comparable<LexerNodeClusterWithSameLexeme> {
    init {
      require(lexerNodes.isNotEmpty())
      lazyAssert { lexerNodes.map { it.token.lexemeText }.distinct().count() == 1 }
      lazyAssert { lexerNodes.distinct().count() == lexerNodes.size }
    }

    val lexeme = lexerNodes.first().token.lexemeText

    override fun compareTo(other: LexerNodeClusterWithSameLexeme): Int =
      ascendingComparator.compare(this, other)

    companion object {
      val ascendingComparator =
        compareBy<LexerNodeClusterWithSameLexeme> {
          it.lexerNodes.size
        }.thenBy {
          it.lexeme
        }
    }
  }

  object META : NonDeletionBasedReducerAnnotation(
    shortName = NAME,
    description =
      "Randomly pick up an identifier or a set of identifiers, " +
        "and replace it with another identifier.",
    reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_REMAIN,
  ) {
    override fun create(reducerContext: ReducerContext): ImmutableList<AbstractTokenReducer> =
      ImmutableList.of(IdentifierReplacementReducer(reducerContext))
  }

  companion object {
    const val NAME = "token_replacer"
  }
}
