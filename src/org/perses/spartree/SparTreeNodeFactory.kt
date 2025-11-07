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
package org.perses.spartree

import com.google.common.collect.ImmutableList
import org.antlr.v4.runtime.Parser
import org.antlr.v4.runtime.Token
import org.antlr.v4.runtime.tree.RuleNode
import org.antlr.v4.runtime.tree.TerminalNode
import org.perses.antlr.GrammarHierarchy
import org.perses.antlr.MetaTokenInfoDB
import org.perses.antlr.ParseTreeUtil.getParserRuleName
import org.perses.antlr.RuleHierarchyEntry
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.AstTag
import org.perses.antlr.ast.PersesNotAst
import org.perses.antlr.ast.PersesTerminalAst
import org.perses.program.PersesTokenFactory
import org.perses.program.TokenizedProgramFactory
import org.perses.util.toImmutableList

class SparTreeNodeFactory(
  val metaTokenInfoDb: MetaTokenInfoDB,
  val tokenizedProgramFactory: TokenizedProgramFactory,
  val grammarHierarchy: GrammarHierarchy,
) : AbstractTreeNode.NodeIdCopyStrategy {
  private var nodeIdGenerator = 0

  private fun nextNodeId(): Int = ++nodeIdGenerator

  override fun computeNodeId(oldNodeId: Int): Int {
    // Ignore the oldNodeId
    return nextNodeId()
  }

  fun createSentinelRootNode(): SparTreeSentinelRootNode = SparTreeSentinelRootNode(nextNodeId())

  fun createLexerRuleSparTreeNode(node: TerminalNode): LexerRuleSparTreeNode {
    val antlrToken = node.symbol
    return createLexerRuleSparTreeNodeForAntlrToken(antlrToken)
  }

  fun createLexerRuleSparTreeNodeForText(text: String): LexerRuleSparTreeNode {
    val persesToken =
      tokenizedProgramFactory
        .tokenFactory
        .createPlainTextToken(text)
    return createLexerRuleSparTreeNode(persesToken)
  }

  fun createLexerRuleSparTreeNodeForAntlrToken(antlrToken: Token): LexerRuleSparTreeNode {
    val persesToken =
      tokenizedProgramFactory
        .tokenFactory
        .createPersesToken(antlrToken)
    return createLexerRuleSparTreeNode(persesToken)
  }

  fun copyWithNewToken(
    originalLexerTreeNode: LexerRuleSparTreeNode,
    newToken: PersesTokenFactory.PersesAntlrToken,
  ): LexerRuleSparTreeNode =
    LexerRuleSparTreeNode(nextNodeId(), newToken, originalLexerTreeNode.antlrRule)

  fun createLexerRuleSparTreeNode(
    persesToken: PersesTokenFactory.AbstractPersesToken,
  ): LexerRuleSparTreeNode {
    val tokenRuleName =
      when (persesToken) {
        is PersesTokenFactory.PersesAntlrToken ->
          metaTokenInfoDb
            .getTokenInfoWithType(
              persesToken.tokenType,
            )?.symbolicName
        is PersesTokenFactory.PersesTokenPlaceholder -> null
        is PersesTokenFactory.PersesPlainText -> null
        is PersesTokenFactory.InvalidToken -> null
      }
    val nodeId = nextNodeId()
    return LexerRuleSparTreeNode(
      nodeId,
      persesToken,
      tokenRuleName?.let { grammarHierarchy.getRuleHierarchyEntryOrNull(tokenRuleName) },
    )
  }

  fun createParserRuleSparTreeNode(
    ruleNode: RuleNode,
    parser: Parser,
  ): ParserRuleSparTreeNode {
    val ruleName = getParserRuleName(ruleNode, parser)
    return createParserRuleSparTreeNode(ruleName)
  }

  fun createGroupingSparTreeNodeForTokens(tokens: Iterable<Token>): GroupingSparTreeNode =
    createGroupingSparTreeNode(
      tokens.map {
        createLexerRuleSparTreeNodeForAntlrToken(it)
      },
    )

  fun createGroupingSparTreeNode(children: Iterable<AbstractSparTreeNode>): GroupingSparTreeNode {
    val result = GroupingSparTreeNode(nextNodeId())
    val payload = AbstractNodePayload.SinglePayload(expectedAntlrRuleType = null)
    children.forEach { result.addChild(it, payload) }
    return result
  }

  fun createParserRuleSparTreeNode(ruleName: String): ParserRuleSparTreeNode {
    val antlrRule =
      grammarHierarchy.getRuleHierarchyEntryWithNameOrThrow(
        ruleName,
      )
    val nodeId = nextNodeId()
    return ParserRuleSparTreeNode(
      nodeId,
      antlrRule,
    )
  }

  fun createPlaceholderSparTreeNode(antlrRule: RuleHierarchyEntry): PlaceholderSparTreeNode {
    val predicateForCompatibility = { node: AbstractSparTreeNode ->
      if (node.antlrRule == null) {
        false
      } else {
        antlrRule.isEqualToOrSuperOf(node.antlrRule)
      }
    }
    return PlaceholderSparTreeNode(
      nodeId = nextNodeId(),
      source = antlrRule.ruleName,
      predicateForCompatibility = predicateForCompatibility,
    )
  }

  fun createPlaceholderSparTreeNode(
    ruleElement: AbstractPersesRuleElement,
  ): PlaceholderSparTreeNode =
    PlaceholderSparTreeNode(
      nodeId = nextNodeId(),
      source = ruleElement.sourceCode,
      predicateForCompatibility = extractPredicateFromRuleElement(ruleElement),
    )

  private fun extractPredicateFromRuleElement(
    source: AbstractPersesRuleElement,
  ): (AbstractSparTreeNode) -> Boolean =
    { node: AbstractSparTreeNode ->
      when (source) {
        is PersesTerminalAst -> {
          check(source.text == ".") {
            "Unexpected source: $source"
          }
          node.isTokenNode()
        }
        is PersesNotAst -> {
          isCompatibleWithTheTokenSetNegation(source, node)
        }
        else -> {
          error("Unexpected source: $source")
        }
      }
    }

  private fun isCompatibleWithTheTokenSetNegation(
    tokenSetNegation: PersesNotAst,
    nodeToBeChecked: AbstractSparTreeNode,
  ): Boolean {
    if (nodeToBeChecked !is LexerRuleSparTreeNode) {
      return false
    }
    val includedTokenRules = extractTokenRulesFromTokenSetNegation(tokenSetNegation)
    return nodeToBeChecked.antlrRule!! !in includedTokenRules
  }

  private fun extractTokenRulesFromTokenSetNegation(
    tokenSetNegation: AbstractPersesRuleElement,
  ): ImmutableList<RuleHierarchyEntry> =
    tokenSetNegation
      .getChild(0)
      .childSequence()
      .map { tokenSource ->
        check(tokenSource.tag == AstTag.TERMINAL) {
          "Unexpected token set negation source: $tokenSource"
        }
        val tokenName = (tokenSource as PersesTerminalAst).text
        grammarHierarchy.getRuleHierarchyEntryWithNameOrThrow(tokenName)
      }.toImmutableList()
}
