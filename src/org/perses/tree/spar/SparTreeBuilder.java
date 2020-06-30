/*
 * Copyright (C) 2018-2020 University of Waterloo.
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

package org.perses.tree.spar;

import com.google.common.base.Strings;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.tree.ParseTree;
import org.antlr.v4.runtime.tree.RuleNode;
import org.antlr.v4.runtime.tree.TerminalNode;
import org.perses.antlr.GrammarHierarchy;
import org.perses.antlr.RuleHierarchyInfo;
import org.perses.antlr.RuleType;
import org.perses.program.PersesToken;
import org.perses.program.TokenizedProgramFactory;

import java.util.ArrayDeque;
import java.util.HashMap;
import java.util.HashSet;

/** Build a spar-tree from an Antlr {@link ParseTree} node. */
public class SparTreeBuilder {

  private final GrammarHierarchy antlrRuleHierarchy;
  private int nodeIdGenerator;
  private final TokenizedProgramFactory tokenizedProgramFactory;

  public SparTreeBuilder(
      final GrammarHierarchy antlrRuleHierarchy, TokenizedProgramFactory tokenizedProgramFactory) {
    this.antlrRuleHierarchy = antlrRuleHierarchy;
    this.tokenizedProgramFactory = tokenizedProgramFactory;
  }

  private static final boolean areNodeIdsUnique(AbstractSparTreeNode root) {
    final HashSet<Integer> visited = new HashSet<>();
    root.preOrderVisit(
        node -> {
          assert !visited.contains(node.getNodeId()) : "Duplicate node ids: " + node.getNodeId();
          visited.add(node.getNodeId());
          return node.getImmutableChildView();
        });
    return true;
  }

  private static final boolean isEmptyRuleNode(ParseTree node) {
    return isRuleNode(node) && node.getChildCount() == 0;
  }

  private static final boolean isRuleNode(ParseTree node) {
    assert (node instanceof RuleNode) != (node instanceof TerminalNode);
    return node instanceof RuleNode;
  }

  private static final boolean isTokenNode(ParseTree node) {
    assert (node instanceof RuleNode) != (node instanceof TerminalNode);
    return node instanceof TerminalNode;
  }

  public final SparTree build(ParseTree rootParseTree) {
    final HashMap<AbstractSparTreeNode, ParseTree> spar2antlrMap = new HashMap<>();
    final ArrayDeque<AbstractSparTreeNode> stack = new ArrayDeque<>();
    final AbstractSparTreeNode root = createSparTreeNode(rootParseTree);
    assert !spar2antlrMap.containsKey(root);
    spar2antlrMap.put(root, rootParseTree);
    stack.push(root);

    while (stack.size() > 0) {
      final AbstractSparTreeNode node = stack.pop();
      final ParseTree parseTree = spar2antlrMap.get(node);
      assert parseTree != null;
      final int childCount = parseTree.getChildCount();
      for (int i = 0; i < childCount; ++i) {
        final ParseTree child = parseTree.getChild(i);
        if (isEmptyRuleNode(child) || isEOFToken(child)) {
          continue;
        }
        AbstractSparTreeNode sparChild = createSparTreeNode(child);
        assert !spar2antlrMap.containsKey(sparChild);
        spar2antlrMap.put(sparChild, child);
        node.addChild(sparChild);
        stack.push(sparChild);
      }
    }
    assert areNodeIdsUnique(root);
    SparTreeSimplifier.simplify(root);
    return new SparTree(root, tokenizedProgramFactory);
  }

  private final boolean isEOFToken(ParseTree node) {
    return isTokenNode(node) && ((TerminalNode) node).getSymbol().getType() == Token.EOF;
  }

  private AbstractSparTreeNode createSparTreeNode(ParseTree parseTree) {
    final int nodeId = nextNodeId();
    if (isTokenNode(parseTree)) {
      TerminalNode node = (TerminalNode) parseTree;
      final Token symbol = node.getSymbol();
      final int tokenType = symbol.getType();
      final PersesToken persesToken =
          tokenizedProgramFactory.getTokenFactory().getPersesToken(symbol);
      return new LexerRuleSparTreeNode(
          nodeId,
          persesToken,
          RuleType.TOKEN,
          antlrRuleHierarchy.getTokenRule(tokenType));
    }
    final RuleHierarchyInfo rule = antlrRuleHierarchy.getRuleHierarchyInfoForRuleNode(parseTree);
    final RuleType nodeType = computeNodeType(parseTree, rule.getRuleName());
    return new ParserRuleSparTreeNode(nodeId, nodeType, rule);
  }

  private int nextNodeId() {
    return ++nodeIdGenerator;
  }

  private RuleType computeNodeType(ParseTree parseTree, String ruleName) {
    assert !isTokenNode(parseTree);
    assert parseTree instanceof RuleNode : "The class is " + parseTree.getClass();
    assert !Strings.isNullOrEmpty(ruleName) : "The rule name is empty: " + ruleName;

    if (RuleType.isKleeneStar(ruleName)) {
      return RuleType.KLEENE_STAR;
    } else if (RuleType.isKleenePlus(ruleName)) {
      return RuleType.KLEENE_PLUS;
    } else if (RuleType.isOptional(ruleName)) {
      return RuleType.OPTIONAL;
    } else {
      return RuleType.OTHER_RULE;
    }
  }
}
