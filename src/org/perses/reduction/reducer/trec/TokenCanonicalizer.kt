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
package org.perses.reduction.reducer.trec

import com.google.common.collect.ImmutableList
import org.perses.antlr.TokenType
import org.perses.antlr.atn.tdtree.TDTree
import org.perses.antlr.toTokenType
import org.perses.reduction.AbstractSparTreeReducer
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
) : AbstractSparTreeReducer(META, reducerContext) {
  private val atnWrapper = reducerContext.configuration.canonicalParserFacade.lexerAtnWrapper

  override fun internalReduce(fixpointReductionState: FixpointReductionState) {
    val tree = fixpointReductionState.inputRepresentation.tree
    val canonicalIdPoolManager = CanonicalIdPoolManager()
    for (i in 0 until tree.programSnapshot.surrogateTokenCount) {
      var latestLeaf = tree.getLatestNthLeafNodeCostly(i)
      val tokenType = latestLeaf.token.asAntlrToken().tokenType
      if (!atnWrapper.hasInformationForToken(tokenType)) {
        // The token is not defined in the lexer.
        continue
      }
      // Replacement-Based Canonicalization
      val identifierTokenTypes =
        reducerContext.configuration.canonicalParserFacade.fusedIdentifierTokenTypes
      if (tokenType in identifierTokenTypes) {
        canonicalizeIdentifier(tree, latestLeaf, canonicalIdPoolManager)
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
    canonicalIdPoolManager: CanonicalIdPoolManager,
  ): LexerRuleSparTreeNode {
    val lexeme = leaf.token.lexemeText
    val pool = canonicalIdPoolManager.getPoolFor(lexeme)
    val edits =
      pool.candidates().flatMap { uniqueId ->
        if (uniqueId == lexeme) {
          return@flatMap listOf()
        }
        listOf(
          TokenEditUtility.createEditToReplaceSingleLexerNode(tree, uniqueId, leaf),
          TokenEditUtility.createEditToReplaceAllLexerNodesHavingSameLexeme(tree, lexeme, uniqueId),
        )
      }
    val testResult = testAllTreeEditsAndReturnTheBest(edits) ?: return leaf
    val newLeaf = getUpdatedLeafAfterEdit(leaf, testResult.edit)
    applyEditToTree(testResult)
    pool.commit(newLeaf.token.lexemeText)
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
      applyEditToTree(testResult)
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
      applyEditToTree(testResult)
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
      reducerContext.configuration.canonicalParserFacade
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
      applyEditToTree(testResult)
      currLeaf = getUpdatedLeafAfterEdit(currLeaf, testResult.edit)
    }
  }

  /**
   * Keeps the case of an identifier's first letter when canonicalizing it. In
   * Java this matters: type names start with an uppercase letter while variables
   * start with a lowercase one, so an identifier such as `Foo` is renamed to `A`
   * rather than `a`. Uppercase and lowercase identifiers draw from separate
   * [CanonicalIdPool]s.
   */
  internal class CanonicalIdPoolManager {
    private val lowerCase = CanonicalIdPool(baseChar = 'a')
    private val upperCase = CanonicalIdPool(baseChar = 'A')

    fun getPoolFor(lexeme: String): CanonicalIdPool =
      if (lexeme.isNotEmpty() && lexeme.first().isUpperCase()) upperCase else lowerCase
  }

  /**
   * A pool of canonical identifier names of a single case. The names already
   * assigned to identifiers are remembered so that later identifiers can be
   * merged onto them; [candidates] additionally offers one fresh, never-used
   * name, and [commit] records that name as assigned only when it actually wins.
   */
  internal class CanonicalIdPool(
    private val baseChar: Char,
  ) {
    private val assignedIds = mutableListOf<String>()

    /** The already-assigned names plus one fresh, never-used candidate. */
    fun candidates(): List<String> = assignedIds + freshId()

    /** Records [chosenId] as assigned when it is the fresh name from [candidates]. */
    fun commit(chosenId: String) {
      if (chosenId == freshId()) {
        assignedIds.add(chosenId)
      } else {
        // A non-fresh winner must be a name already in the pool (a merge); the
        // reducer only ever picks from candidates(), so anything else is a bug.
        check(chosenId in assignedIds) { "Unexpected canonical id: $chosenId" }
      }
    }

    private fun freshId(): String = convertIndexToId(assignedIds.size, baseChar)
  }

  object META : ReducerAnnotation(
    shortName = NAME,
    description = "",
    deterministic = true,
    // Canonicalization edits token TEXT, and that can grow the best result. Deleting a fragment of a
    // structured multi-character token can make it re-lex into MORE tokens -- e.g. dropping the ')' of
    // a Makefile `$(VAR)` leaves `$(VAR`, which re-lexes as two tokens -- raising the canonical token
    // count; renaming an identifier to a canonical-pool id can also raise the character count. So this
    // is INCREASE, not REMAIN. The scheduler treats the two identically except that the
    // token-count-non-increase assertion exempts INCREASE -- correct here, as the increase is a
    // legitimate consequence of canonicalization, not a reducer bug. (Languages with strict tests,
    // e.g. C, rarely hit it because such an edit fails the interestingness test before it is committed;
    // a loose test, e.g. a Makefile grep, commits it, which is what first exposed the misclassification.)
    reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_INCREASE,
  ) {
    override fun create(reducerContext: ReducerContext): ImmutableList<AbstractSparTreeReducer> =
      ImmutableList.of(TokenCanonicalizer(reducerContext))
  }

  companion object {
    private const val MAX_CANONICALIZATION_TRIAL = 2

    const val NAME = "token_canonicalizer"

    // Given an index i, the function returns the i-th
    // identifier in [a, b, ..., z, aa, ab, ..., zz, ...]. When [baseChar] is 'A'
    // the uppercase sequence [A, B, ..., Z, AA, AB, ..., ZZ, ...] is produced
    // instead, so the canonical name can match the case of the original
    // identifier's first letter.
    internal fun convertIndexToId(
      index: Int,
      baseChar: Char,
    ): String {
      val builder = StringBuilder()
      var quotient = index
      var digit: Int
      do {
        digit = quotient % 26
        quotient /= 26
        builder.append(baseChar + digit)
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
