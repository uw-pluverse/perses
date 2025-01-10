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
package org.perses.reduction.reducer.trec

import com.google.common.collect.ImmutableList
import org.perses.reduction.AbstractTokenReducer
import org.perses.reduction.FixpointReductionState
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.reduction.reducer.vulcan.TokenEditUtility
import org.perses.spartree.AbstractSparTreeEdit
import org.perses.spartree.AnyNodeReplacementTreeEdit
import org.perses.spartree.LexerRuleSparTreeNode
import org.perses.spartree.SparTree

class TokenCanonicalizer(
  reducerContext: ReducerContext,
) : AbstractTokenReducer(META, reducerContext) {

  private val atnWrapper = reducerContext.configuration.parserFacade.lexerAtnWrapper

  override fun internalReduce(fixpointReductionState: FixpointReductionState) {
    val tree = fixpointReductionState.sparTree.getTreeRegardlessOfParsability()
    val candidateCanonicalIds = mutableListOf<String>()
    for (i in 0 until tree.tokenCount) {
      var latestLeaf = tree.getLatestNthLeafNodeCostly(i)
      // Replacement-Based Canonicalization
      if (latestLeaf.token.type in reducerContext
          .configuration.parserFacade.identifierTokenTypes
      ) {
        canonicalizeIdentifier(tree, latestLeaf, candidateCanonicalIds)
        continue
      } else {
        latestLeaf = canonicalizeOtherToken(tree, latestLeaf)
      }
      // Deletion-Based Canonicalization
      latestLeaf = canonicalizeByDeletingFragment(tree, latestLeaf)
      canonicalizeCharByChar(tree, latestLeaf)
    }
  }

  private fun canonicalizeIdentifier(
    tree: SparTree,
    leaf: LexerRuleSparTreeNode,
    candidateCanonicalIds: MutableList<String>,
  ): LexerRuleSparTreeNode {
    val lexeme = leaf.token.text
    // candidateCanonicalIds contains all used canonicalized IDs so far
    // here adding a new candidate canonical ID because this identifier token may need to be unique
    candidateCanonicalIds.add(convertIndexToId(candidateCanonicalIds.size))
    val edits = candidateCanonicalIds.flatMap { uniqueId ->
      if (uniqueId == lexeme) {
        return@flatMap listOf()
      }
      listOf(
        TokenEditUtility.createEditToReplaceSingleLexerNode(tree, uniqueId, leaf),
        TokenEditUtility.createEditToReplaceAllLexerNodesHavingSameLexeme(tree, lexeme, uniqueId),
      )
    }
    val testResult = testAllTreeEditsAndReturnTheBest(edits) ?: run {
      candidateCanonicalIds.removeLast()
      return leaf
    }
    val newLeaf = getUpdatedLeafAfterEdit(leaf, testResult.edit)
    tree.applyEdit(testResult.edit)
    // only keep the added new candidate canonical ID when it is actually used
    if (newLeaf.token.text != candidateCanonicalIds.last()) {
      candidateCanonicalIds.removeLast()
    }
    return newLeaf
  }

  private fun canonicalizeOtherToken(
    tree: SparTree,
    leaf: LexerRuleSparTreeNode,
  ): LexerRuleSparTreeNode {
    val tokenType = leaf.token.type
    val lexeme = leaf.token.text
    val candidateCanonicalTokenTexts = atnWrapper
      .generateCandidateCanonicalTokenTextsGivenTokenType(tokenType, MAX_CANONICALIZATION_TRIAL)
    val editBuilder = ImmutableList.builder<AnyNodeReplacementTreeEdit>()
    for (tokenText in candidateCanonicalTokenTexts) {
      if (tokenText == lexeme) {
        break
      }
      editBuilder.add(
        TokenEditUtility.createEditToReplaceAllLexerNodesHavingSameLexeme(tree, lexeme, tokenText),
      )
      editBuilder.add(TokenEditUtility.createEditToReplaceSingleLexerNode(tree, tokenText, leaf))
    }
    val edits = editBuilder.build()
    val testResult = testAllTreeEditsAndReturnTheBest(edits) ?: return leaf
    val newLeaf = getUpdatedLeafAfterEdit(leaf, testResult.edit)
    tree.applyEdit(testResult.edit)
    return newLeaf
  }

  private fun canonicalizeByDeletingFragment(
    tree: SparTree,
    leaf: LexerRuleSparTreeNode,
  ): LexerRuleSparTreeNode {
    var currLeaf = leaf
    while (true) {
      val lexeme = currLeaf.token.text
      val tdTree = atnWrapper.createTDTree(lexeme, currLeaf.token.type)
      val edits = tdTree.deletableNodesFromTopToBottomSequence().flatMap { blanketedNodes ->
        val newLexeme = tdTree.root.toLexeme(blanketedNodes)
        if (newLexeme == lexeme) {
          return@flatMap listOf()
        }
        listOf(
          TokenEditUtility
            .createEditToReplaceAllLexerNodesHavingSameLexeme(tree, lexeme, newLexeme),
          TokenEditUtility.createEditToReplaceSingleLexerNode(tree, newLexeme, currLeaf),
        )
      }.toList()
      val testResult = testAllTreeEditsAndReturnTheBest(edits) ?: return currLeaf
      tree.applyEdit(testResult.edit)
      currLeaf = getUpdatedLeafAfterEdit(currLeaf, testResult.edit)
    }
  }

  private fun canonicalizeCharByChar(
    tree: SparTree,
    leaf: LexerRuleSparTreeNode,
  ) {
    var currLeaf = leaf
    while (true) {
      val lexeme = currLeaf.token.text
      val tdTree = atnWrapper.createTDTree(lexeme, currLeaf.token.type)
      val candidates = tdTree.root
        .getCanonicalLexemeList(countLimitPerChar = MAX_CANONICALIZATION_TRIAL)
      val edits = candidates.flatMap { candidate ->
        listOf(
          TokenEditUtility
            .createEditToReplaceAllLexerNodesHavingSameLexeme(tree, lexeme, candidate),
          TokenEditUtility.createEditToReplaceSingleLexerNode(tree, candidate, currLeaf),
        )
      }.toList()
      val testResult = testAllTreeEditsAndReturnTheBest(edits) ?: return
      tree.applyEdit(testResult.edit)
      currLeaf = getUpdatedLeafAfterEdit(currLeaf, testResult.edit)
    }
  }

  companion object {

    private const val MAX_CANONICALIZATION_TRIAL = 2

    const val NAME = "token_canonicalizer"

    @JvmField
    val META = object : ReducerAnnotation(
      shortName = NAME,
      description = "",
      deterministic = true,
      reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_REMAIN,
    ) {
      override fun create(reducerContext: ReducerContext): ImmutableList<AbstractTokenReducer> {
        return ImmutableList.of(TokenCanonicalizer(reducerContext))
      }
    }

    // Given an index i, the function returns the i-th
    // identifier in [a, b, ..., z, aa, ab, ..., zz, ...]
    internal fun convertIndexToId(index: Int): String {
      val builder = StringBuilder()
      var quotient = index
      var digit: Int
      do {
        digit = quotient % 26
        quotient /= 26
        builder.append('a' + digit)
      } while (quotient > 0)
      return builder.reverse().toString()
    }

    private fun getUpdatedLeafAfterEdit(
      leaf: LexerRuleSparTreeNode,
      edit: AbstractSparTreeEdit<*>,
    ): LexerRuleSparTreeNode {
      return edit.asAnyNodeReplacementEdit()
        .actionSet.actions.single { it.targetNode === leaf }!!.replacingNode.asLexerRule()
    }
  }
}
