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

package org.perses.antlr;

import com.google.common.collect.ImmutableList;
import com.google.common.collect.ImmutableMap;
import org.antlr.runtime.RecognitionException;
import org.antlr.v4.runtime.tree.ParseTree;
import org.antlr.v4.runtime.tree.RuleNode;
import org.antlr.v4.tool.Grammar;
import org.antlr.v4.tool.ast.GrammarRootAST;
import org.perses.antlr.ast.PersesAstBuilder;
import org.perses.antlr.ast.PersesGrammar;

import java.util.Map;
import java.util.Optional;

/** This is the rule hierarchy, which can be used as an approximation of the class hierarchy. */
public final class GrammarHierarchy {

  public static GrammarHierarchy createFromString(String content) throws RecognitionException {
    final GrammarRootAST rawAst = AntlrGrammarParser.parseRawGrammarASTFromString(content);
    final PersesGrammar persesGrammar = new PersesAstBuilder().buildFromAntlrRootAst(rawAst);
    return createFromCombinedAntlrGrammar(
        new AbstractAntlrGrammar.CombinedAntlrGrammar(persesGrammar));
  }

  public static GrammarHierarchy createFromAntlrGrammar(AbstractAntlrGrammar grammar) {
    if (grammar.isCombined()) {
      return createFromCombinedAntlrGrammar(grammar.asCombined());
    } else {
      return createFromSeparateAntlrGrammar(grammar.asSeparate());
    }
  }

  private static GrammarHierarchy createFromCombinedAntlrGrammar(
      AbstractAntlrGrammar.CombinedAntlrGrammar grammar) {
    final PersesGrammar lexerGrammar = grammar.getGrammar();
    final String antlrGrammarContent = lexerGrammar.getSourceCode();
    final Grammar antlrToolGrammar =
        AntlrGrammarParser.loadAntlrGrammarFromString(antlrGrammarContent);
    return new GrammarHierarchyBuilder(grammar, computeTypeToTokenNameMap(antlrToolGrammar))
        .build();
  }

  private static GrammarHierarchy createFromSeparateAntlrGrammar(
      AbstractAntlrGrammar.SeparateAntlrGrammar grammar) {
    final PersesGrammar lexerGrammar = grammar.getLexerGrammar();
    final String antlrGrammarContent = lexerGrammar.getSourceCode();
    final Grammar antlrToolGrammar =
        AntlrGrammarParser.loadAntlrGrammarFromString(antlrGrammarContent);
    return new GrammarHierarchyBuilder(grammar, computeTypeToTokenNameMap(antlrToolGrammar))
        .build();
  }

  private static ImmutableMap<Integer, String> computeTypeToTokenNameMap(Grammar grammar) {
    return grammar.tokenNameToTypeMap.entrySet().stream()
        .collect(ImmutableMap.toImmutableMap(Map.Entry::getValue, Map.Entry::getKey));
  }

  private final ImmutableList<RuleHierarchyInfo> indexToRuleMap;
  private final ImmutableMap<String, RuleHierarchyInfo> nameToRuleMap;
  private final ImmutableList<Optional<RuleHierarchyInfo>> indexToTokenMap;

  GrammarHierarchy(
      ImmutableList<RuleHierarchyInfo> indexToRuleMap,
      ImmutableMap<String, RuleHierarchyInfo> nameToRuleMap,
      ImmutableList<Optional<RuleHierarchyInfo>> indexToTokenMap) {
    this.indexToRuleMap = indexToRuleMap;
    this.nameToRuleMap = nameToRuleMap;
    this.indexToTokenMap = indexToTokenMap;
  }

  public Optional<RuleHierarchyInfo> getTokenRule(int tokenType) {
    assert tokenType >= 0 : "The token type must be non-negative: " + tokenType;
    return indexToTokenMap.get(tokenType);
  }

  public RuleHierarchyInfo getRuleHierarchyInfoWithIndex(int ruleIndex) {
    return indexToRuleMap.get(ruleIndex);
  }

  public RuleHierarchyInfo getRuleHierarchyInfoWithName(String ruleName) {
    final RuleHierarchyInfo rule = nameToRuleMap.get(ruleName);
    assert rule != null : "Does not exist a rule for the name " + ruleName;
    return rule;
  }

  public RuleHierarchyInfo getRuleHierarchyInfoForRuleNode(ParseTree tree) {
    assert tree instanceof RuleNode : "Unexpected tree type: " + tree.getClass();
    final int index = ((RuleNode) tree).getRuleContext().getRuleIndex();
    return getRuleHierarchyInfoWithIndex(index);
  }

  public ImmutableList<RuleHierarchyInfo> getRuleList() {
    return indexToRuleMap;
  }
}
