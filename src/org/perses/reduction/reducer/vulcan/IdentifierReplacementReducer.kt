/*
 * Copyright (C) 2018-2024 University of Waterloo.
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
import org.perses.program.PersesTokenFactory.PersesToken
import org.perses.reduction.AbstractTokenReducer
import org.perses.reduction.FixpointReductionState
import org.perses.reduction.ReducerAnnotation
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
    val candidates = Candidates.compute(tree) {
      configuration.parserFacade.identifierTokenTypes.contains(it.type)
    }
    val heuristicEdit = heuristicFindInterestingReplacementEdit(
      tree,
      candidates,
    )
    if (heuristicEdit != null) {
      tree.applyEdit(heuristicEdit)
      return
    }
    val singleTokenEdit = bruteForceFindInterestingReplacementEdit(
      tree,
      candidates,
    ) ?: return
    tree.applyEdit(singleTokenEdit)
  }

  /* The heuristic that can be applied here is to replace all the identifiers with same lexeme
  except its first appearance, which is likely to be the definition of the identifier. In this way,
  what the edits do is more likely to be removing all the usages of the identifier. If the program
  obtained after the edits still preserve the property, then the definition of the identifier is
  very likely to be deletable */
  private fun heuristicFindInterestingReplacementEdit(
    tree: SparTree,
    candidates: Candidates,
  ) = findInterestingReplacementEditSkeleton(tree, candidates) { clusterToBeReplaced ->
    val clusterSize = clusterToBeReplaced.lexerNodes.size
    if (clusterSize == 1) {
      // The only lexer node in this cluster is probably the definition node.
      sequenceOf()
    } else {
      sequenceOf(clusterToBeReplaced.lexerNodes.subList(1, clusterSize))
    }
  }

  private fun bruteForceFindInterestingReplacementEdit(
    tree: SparTree,
    candidates: Candidates,
  ) = findInterestingReplacementEditSkeleton(tree, candidates) { clusterToBeReplaced ->
    clusterToBeReplaced.lexerNodes.asSequence().map { listOf(it) }
  }

  private inline fun findInterestingReplacementEditSkeleton(
    tree: SparTree,
    candidates: Candidates,
    sequenceOfLexerNodesToBeReplaced: (LexerNodeClusterWithSameLexeme)
    -> Sequence<List<LexerRuleSparTreeNode>>,
  ): AbstractSparTreeEdit<*>? {
    for (clusterToBeReplaced in candidates.lexerNodeClusterWithSameLexemes) {
      val replacementLexemeCandidates = candidates
        .computeReplacementCandidates(clusterToBeReplaced)
        .map { it.lexeme }
      val edit = sequenceOfLexerNodesToBeReplaced(clusterToBeReplaced)
        .flatMap { lexerNodesToBeReplaced ->
          replacementLexemeCandidates.asSequence().map { replacementLexeme ->
            val edit = TokenEditUtility.createEditToReplaceMultiNodes(
              tree,
              replacementLexeme,
              lexerNodesToBeReplaced,
            )
            testAndCacheUnseenResultedProgram(edit)
          }
        }.firstOrNull {
          it != null
        }
      return edit ?: continue
    }
    return null
  }

  internal class Candidates(
    val lexerNodeClusterWithSameLexemes: ImmutableList<LexerNodeClusterWithSameLexeme>,
  ) {

    init {
      lazyAssert { lexerNodeClusterWithSameLexemes.isSortedAscendingly() }
    }

    fun getClusterWithName(name: String): LexerNodeClusterWithSameLexeme? {
      return lexerNodeClusterWithSameLexemes.find { it.lexeme == name }
    }

    fun computeReplacementCandidates(
      tokenToBeReplaced: LexerNodeClusterWithSameLexeme,
    ): ImmutableList<LexerNodeClusterWithSameLexeme> {
      lazyAssert { tokenToBeReplaced in lexerNodeClusterWithSameLexemes }
      return lexerNodeClusterWithSameLexemes.asSequence()
        .filter { it !== tokenToBeReplaced }
        .sortedWith(LexerNodeClusterWithSameLexeme.ascendingComparator.reversed())
        .toImmutableList()
    }

    companion object {

      inline fun compute(
        tree: SparTree,
        crossinline isIdentifier: (PersesToken) -> Boolean,
      ): Candidates {
        return compute(
          { tree.leafNodeSequence() },
          isIdentifier,
        )
      }

      inline fun compute(
        tokenSequenceProvider: () -> Sequence<LexerRuleSparTreeNode>,
        crossinline isIdentifier: (PersesToken) -> Boolean,
      ): Candidates {
        return Candidates(
          tokenSequenceProvider()
            .filter { isIdentifier(it.token) }
            .groupBy { it.token.text }
            .values
            .asSequence()
            .map { LexerNodeClusterWithSameLexeme(ImmutableList.copyOf(it)) }
            .sorted()
            .toImmutableList(),
        )
      }
    }
  }

  class LexerNodeClusterWithSameLexeme(
    val lexerNodes: ImmutableList<LexerRuleSparTreeNode>,
  ) : Comparable<LexerNodeClusterWithSameLexeme> {
    init {
      require(lexerNodes.isNotEmpty())
      lazyAssert { lexerNodes.asSequence().map { it.token.text }.distinct().count() == 1 }
      lazyAssert { lexerNodes.distinct().count() == lexerNodes.size }
    }

    val lexeme = lexerNodes.first().token.text

    override fun compareTo(other: LexerNodeClusterWithSameLexeme): Int {
      return ascendingComparator.compare(this, other)
    }

    companion object {

      val ascendingComparator = compareBy<LexerNodeClusterWithSameLexeme> {
        it.lexerNodes.size
      }.thenBy {
        it.lexeme
      }
    }
  }

  companion object {
    const val NAME = "token_replacer"

    val META = object : ReducerAnnotation(
      shortName = NAME,
      description = "Randomly pick up an identifier or a set of identifiers, " +
        "and replace it with another identifier.",
      // Given the same input, the algorithm might yield different results,
      // because this alg also depends on the cache in the reduction context.
      deterministic = false,
      reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_REMAIN,
    ) {
      override fun create(reducerContext: ReducerContext): ImmutableList<AbstractTokenReducer> {
        return ImmutableList.of(IdentifierReplacementReducer(reducerContext))
      }
    }
  }
}
