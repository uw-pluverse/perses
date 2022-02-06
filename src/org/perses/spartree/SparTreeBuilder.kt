/*
 * Copyright (C) 2018-2022 University of Waterloo.
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

import org.antlr.v4.runtime.Token
import org.antlr.v4.runtime.tree.ParseTree
import org.antlr.v4.runtime.tree.RuleNode
import org.antlr.v4.runtime.tree.TerminalNode
import org.perses.antlr.GrammarHierarchy
import org.perses.antlr.ParseTreeUtil.getRuleName
import org.perses.antlr.ParseTreeUtil.getTokenName
import org.perses.antlr.ParseTreeWithParser
import org.perses.program.TokenizedProgramFactory
import org.perses.util.SimpleStack

/** Build a spar-tree from an Antlr [ParseTree] node.  */
class SparTreeBuilder(
  private val antlrRuleHierarchy: GrammarHierarchy,
  private val tokenizedProgramFactory: TokenizedProgramFactory,
  private val parseTreeWithParser: ParseTreeWithParser,
  val simplifyTree: Boolean = true,
) {

  private var nodeIdGenerator = 0

  val result = build()

  private fun build(): SparTree {
    val rootParseTree = parseTreeWithParser.tree
    val spar2antlrMap = HashMap<AbstractSparTreeNode, ParseTree>()
    val stack = SimpleStack<AbstractSparTreeNode>()
    val root = createSparTreeNode(rootParseTree)
    assert(!spar2antlrMap.containsKey(root))
    spar2antlrMap[root] = rootParseTree
    stack.add(root)
    while (stack.isNotEmpty()) {
      val node = stack.remove()
      val parseTree = spar2antlrMap[node]!!
      val childCount = parseTree.childCount
      for (i in 0 until childCount) {
        val child = parseTree.getChild(i)
        if (isEmptyRuleNode(child) || isEOFToken(child)) {
          continue
        }
        val sparChild = createSparTreeNode(child)
        assert(!spar2antlrMap.containsKey(sparChild))
        spar2antlrMap[sparChild] = child
        node.addChild(sparChild, AbstractNodePayload.SinglePayload(sparChild.antlrRule))
        stack.add(sparChild)
      }
    }
    assert(areNodeIdsUnique(root))
    if (simplifyTree) {
      SparTreeSimplifier.simplify(root)
    }
    return SparTree(root, antlrRuleHierarchy, tokenizedProgramFactory)
  }

  private fun isEOFToken(node: ParseTree): Boolean {
    return isTokenNode(node) && (node as TerminalNode).symbol.type == Token.EOF
  }

  private fun createSparTreeNode(parseTree: ParseTree): AbstractSparTreeNode {
    val nodeId = nextNodeId()
    if (isTokenNode(parseTree)) {
      val node = parseTree as TerminalNode
      val symbol = node.symbol
      val tokenRuleName = getTokenName(node, parseTreeWithParser.lexer)
      val persesToken = tokenizedProgramFactory.tokenFactory.getPersesTokenOrThrow(symbol)
      return LexerRuleSparTreeNode(
        nodeId,
        persesToken,
        tokenRuleName?.let { antlrRuleHierarchy.getTokenRule(tokenRuleName) }
      )
    }
    val rule = antlrRuleHierarchy.getRuleHierarchyInfoWithName(
      getRuleName((parseTree as RuleNode), parseTreeWithParser.parser)
    )
    return ParserRuleSparTreeNode(nodeId, rule)
  }

  private fun nextNodeId(): Int {
    return ++nodeIdGenerator
  }

  companion object {
    private fun isEmptyRuleNode(node: ParseTree): Boolean {
      return isRuleNode(node) && node.childCount == 0
    }

    private fun isRuleNode(node: ParseTree): Boolean {
      assert(node is RuleNode != node is TerminalNode)
      return node is RuleNode
    }

    private fun isTokenNode(node: ParseTree): Boolean {
      assert(node is RuleNode != node is TerminalNode)
      return node is TerminalNode
    }

    private fun areNodeIdsUnique(root: AbstractSparTreeNode): Boolean {
      val visited = HashSet<Int>()
      root.preOrderVisit { node: AbstractSparTreeNode ->
        assert(!visited.contains(node.nodeId)) { "Duplicate node ids: " + node.nodeId }
        visited.add(node.nodeId)
        node.immutableChildView
      }
      return true
    }
  }
}
