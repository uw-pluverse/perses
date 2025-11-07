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
import org.perses.antlr.TokenType
import org.perses.antlr.atn.tdtree.TDTree
import org.perses.antlr.toTokenType
import org.perses.reduction.AbstractTokenReducer
import org.perses.reduction.FixpointReductionState
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.reduction.reducer.vulcan.TokenEditUtility
import org.perses.spartree.AbstractSparTreeEdit
import org.perses.spartree.AnyNodeReplacementTreeEdit
import org.perses.spartree.LexerRuleSparTreeNode
import org.perses.spartree.SparTree
import java.lang.RuntimeException

class TokenCanonicalizer(
  reducerContext: ReducerContext,
) : AbstractTokenReducer(META, reducerContext) {
  private val atnWrapper = reducerContext.configuration.parserFacade.lexerAtnWrapper

  override fun internalReduce(fixpointReductionState: FixpointReductionState) {
    val tree = fixpointReductionState.sparTree.getTreeRegardlessOfParsability()
    val candidateCanonicalIds = mutableListOf<String>()
    for (i in 0 until tree.tokenCount) {
      var latestLeaf = tree.getLatestNthLeafNodeCostly(i)
      val tokenType = latestLeaf.token.asAntlrToken().tokenType
      if (!atnWrapper.hasInformationForToken(tokenType)) {
        // The token is not defined in the lexer.
        continue
      }
      // Replacement-Based Canonicalization
      if (tokenType in reducerContext.configuration.parserFacade.identifierTokenTypes) {
        canonicalizeIdentifier(tree, latestLeaf, candidateCanonicalIds)
        continue
      }

      latestLeaf = canonicalizeOtherToken(tree, latestLeaf)

      if (!atnWrapper.hasInformationForToken(latestLeaf.token.asAntlrToken().tokenType)) {
        // The token is not defined in the lexer.
        continue
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
    val lexeme = leaf.token.lexemeText
    // candidateCanonicalIds contains all used canonicalized IDs so far
    // here adding a new candidate canonical ID because this identifier token may need to be unique
    candidateCanonicalIds.add(convertIndexToId(candidateCanonicalIds.size))
    val edits =
      candidateCanonicalIds.flatMap { uniqueId ->
        if (uniqueId == lexeme) {
          return@flatMap listOf()
        }
        listOf(
          TokenEditUtility.createEditToReplaceSingleLexerNode(tree, uniqueId, leaf),
          TokenEditUtility.createEditToReplaceAllLexerNodesHavingSameLexeme(tree, lexeme, uniqueId),
        )
      }
    val testResult =
      testAllTreeEditsAndReturnTheBest(edits) ?: run {
        candidateCanonicalIds.removeLast()
        return leaf
      }
    val newLeaf = getUpdatedLeafAfterEdit(leaf, testResult.edit)
    tree.applyEdit(testResult.edit)
    // only keep the added new candidate canonical ID when it is actually used
    if (newLeaf.token.lexemeText != candidateCanonicalIds.last()) {
      candidateCanonicalIds.removeLast()
    }
    return newLeaf
  }

  private fun canonicalizeOtherToken(
    tree: SparTree,
    lexerRuleNode: LexerRuleSparTreeNode,
  ): LexerRuleSparTreeNode {
    try {
      val tokenType = lexerRuleNode.token.asAntlrToken().tokenType
      val lexeme = lexerRuleNode.token.lexemeText
      val candidateCanonicalTokenTexts =
        atnWrapper
          .generateCandidateCanonicalTokenTextsGivenTokenType(tokenType, MAX_CANONICALIZATION_TRIAL)
      val editBuilder = ImmutableList.builder<AnyNodeReplacementTreeEdit>()
      for (tokenText in candidateCanonicalTokenTexts) {
        if (tokenText == lexeme) {
          break
        }
        editBuilder.add(
          TokenEditUtility.createEditToReplaceAllLexerNodesHavingSameLexeme(
            tree,
            lexeme,
            tokenText,
          ),
        )
        editBuilder.add(
          TokenEditUtility.createEditToReplaceSingleLexerNode(tree, tokenText, lexerRuleNode),
        )
      }
      val edits = editBuilder.build()
      val testResult = testAllTreeEditsAndReturnTheBest(edits) ?: return lexerRuleNode
      val newLeaf = getUpdatedLeafAfterEdit(lexerRuleNode, testResult.edit)
      tree.applyEdit(testResult.edit)
      return newLeaf
    } catch (e: Exception) {
      throw RuntimeException(
        """
        |Exception occurred for token ${lexerRuleNode.token}
        |
        |Full information about the token:
        |  type: ${lexerRuleNode.token.asAntlrToken().tokenType}
        |  text: ${lexerRuleNode.token.lexemeText}
        |  
        |tree structure: ${lexerRuleNode.printTreeStructure()}
        |
        |
        """.trimMargin(),
        e,
      )
    }
  }

  private fun canonicalizeByDeletingFragment(
    tree: SparTree,
    leaf: LexerRuleSparTreeNode,
  ): LexerRuleSparTreeNode {
    var currLeaf = leaf
    while (true) {
      val lexeme = currLeaf.token.lexemeText
      val tdTree = buildTDTree(currLeaf)
      val edits =
        tdTree
          .deletableNodesFromTopToBottomSequence()
          .flatMap { blanketedNodes ->
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

  internal fun buildTDTree(leaf: LexerRuleSparTreeNode): TDTree {
    val lexeme = leaf.token.lexemeText
    val currentTokenType: TokenType = leaf.token.asAntlrToken().tokenType
    val firstTry = atnWrapper.createTDTree(lexeme, currentTokenType)
    if (firstTry != null) {
      return firstTry
    }
    val computedTokenType =
      reducerContext.configuration.parserFacade
        .transformLiteralIntoSingleToken(
          lexeme,
        )
    if (computedTokenType.type == currentTokenType.antlrTokenType) {
      // The type
      error("Could not build a TDTree for $lexeme with type $currentTokenType")
    } else {
      return atnWrapper.createTDTree(lexeme, computedTokenType.type.toTokenType())
        ?: error("Could not build a TDTree for $lexeme with type $computedTokenType")
    }
  }

  private fun canonicalizeCharByChar(
    tree: SparTree,
    leaf: LexerRuleSparTreeNode,
  ) {
    var currLeaf = leaf
    while (true) {
      val lexeme = currLeaf.token.lexemeText
      val tdTree = buildTDTree(currLeaf)
      val candidates =
        tdTree.root
          .getCanonicalLexemeList(countLimitPerChar = MAX_CANONICALIZATION_TRIAL)
      val edits =
        candidates
          .flatMap { candidate ->
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

  object META : ReducerAnnotation(
    shortName = NAME,
    description = "",
    deterministic = true,
    reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_REMAIN,
  ) {
    override fun create(reducerContext: ReducerContext): ImmutableList<AbstractTokenReducer> =
      ImmutableList.of(TokenCanonicalizer(reducerContext))
  }

  companion object {
    private const val MAX_CANONICALIZATION_TRIAL = 2

    const val NAME = "token_canonicalizer"

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
    ): LexerRuleSparTreeNode =
      edit
        .asAnyNodeReplacementEdit()
        .actionSet.actions
        .single { it.targetNode === leaf }
        .replacingNode
        .asLexerRule()
  }
}
