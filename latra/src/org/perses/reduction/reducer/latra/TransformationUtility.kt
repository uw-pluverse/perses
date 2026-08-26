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
package org.perses.reduction.reducer.latra

import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableListMultimap
import com.google.common.collect.ImmutableMap
import com.google.common.collect.ImmutableSet
import org.perses.antlr.RuleHierarchyEntry
import org.perses.grammar.ParseErrorHandling
import org.perses.reduction.reducer.latra.language.AbstractLatraPattern
import org.perses.reduction.reducer.latra.language.AbstractPatternElement.ConcreteToken
import org.perses.reduction.reducer.latra.language.AbstractPatternElement.Hole
import org.perses.reduction.reducer.latra.language.AbstractPatternElement.Hole.HoleName
import org.perses.reduction.reducer.latra.language.AbstractPatternElementBindings
import org.perses.reduction.reducer.latra.language.AbstractPatternElementBindings.NonScopedBindings
import org.perses.reduction.reducer.latra.language.SuchAsClause
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.AbstractTreeNode.Companion.findLowestAncestor
import org.perses.spartree.LexerRuleSparTreeNode
import org.perses.spartree.SparTree
import org.perses.spartree.SparTreeBuilder
import org.perses.util.SimpleStack
import org.perses.util.lazyAssert
import org.perses.util.toImmutableList
import org.perses.util.toImmutableMap

object TransformationUtility {
  /**
   * Parser rules applicable to a code snippet.
   *
   * @property allAvailableParserRules All rules that can be used to parse the code.
   * @property subtreeRootParserRules A minimal subset of [allAvailableParserRules] that produces a parse tree
   * without single-node non-root layers.
   */
  data class ParserRuleSet(
    val allAvailableParserRules: ImmutableSet<RuleHierarchyEntry>,
    val subtreeRootParserRules: ImmutableSet<RuleHierarchyEntry>,
  )

  sealed class AbstractSourceForParserRuleInference

  class SourceWithoutRangeMarkers(
    val source: String,
  ) : AbstractSourceForParserRuleInference()

  class SourceWithRangeMarkers(
    val entireSourceWithoutMarks: String,
    val sourceRangeWithinMarks: IntRange,
    val preferMostGeneralRule: Boolean,
  ) : AbstractSourceForParserRuleInference() {
    init {
      require(!sourceRangeWithinMarks.isEmpty())
    }

    fun computeSourceWithinMarks() = entireSourceWithoutMarks.substring(sourceRangeWithinMarks)
  }

  fun processSourceWithRangeMarkers(source: String): AbstractSourceForParserRuleInference {
    val specificMarkupRegex = Regex("(\\{:)(.*?)(:})", RegexOption.DOT_MATCHES_ALL)
    val generalMarkupRegex = Regex("(\\{g:)(.*?)(:})", RegexOption.DOT_MATCHES_ALL)

    val specificMatch = specificMarkupRegex.findAll(source)
    val generalMatch = generalMarkupRegex.findAll(source)
    val combined = (specificMatch + generalMatch).toList()
    val matchResult =
      when (combined.size) {
        0 -> null
        1 -> combined.single()
        else -> error("TODO(cnsun): Currently, cannot have two matches in one code example.")
      }

    return if (matchResult != null) {
      val entireSourceWithoutMarks =
        source.toCharArray().let { chars ->
          replaceWithSpaces(chars, matchResult.groups[1]!!.range)
          replaceWithSpaces(chars, matchResult.groups[3]!!.range)
          String(chars)
        }
      SourceWithRangeMarkers(
        entireSourceWithoutMarks = entireSourceWithoutMarks,
        sourceRangeWithinMarks = matchResult.groups[2]!!.range,
        preferMostGeneralRule = generalMatch.any(),
      )
    } else {
      SourceWithoutRangeMarkers(source = source)
    }
  }

  private fun replaceWithSpaces(
    chars: CharArray,
    range: IntRange,
  ) {
    range.forEach { chars[it] = ' ' }
  }

  /**
   * Identify the most appropriate parsing rule that best matches the given source input
   */
  fun inferParserRule(
    source: String,
    parsingRelatedArguments: LatraArguments,
  ): ImmutableList<RuleHierarchyEntry> {
    val sourceWithRangeMarkers = processSourceWithRangeMarkers(source)
    if (sourceWithRangeMarkers is SourceWithoutRangeMarkers) {
      val possibleRules = findPossibleRules(source, parsingRelatedArguments)
      if (possibleRules.allAvailableParserRules.isEmpty()) {
        return ImmutableList.of()
      }
      val numOfIncomingPathsPerNode =
        parsingRelatedArguments
          .sparTreeNodeFactory
          .grammarHierarchy
          .reachabilityGraph
          .numOfIncomingPathsPerNode
      return rankTargetNodesIncomingPaths(possibleRules, numOfIncomingPathsPerNode)
    }
    check(sourceWithRangeMarkers is SourceWithRangeMarkers)
    return extractRootRuleForSourceCodeWithinMarkers(
      sourceWithRangeMarkers,
      parsingRelatedArguments,
    )
  }

  private fun extractRootRuleForSourceCodeWithinMarkers(
    sourceWithRangeMarkers: SourceWithRangeMarkers,
    parsingRelatedArguments: LatraArguments,
  ): ImmutableList<RuleHierarchyEntry> {
    val completeTree =
      getParseTree(
        sourceWithRangeMarkers.entireSourceWithoutMarks,
        parsingRelatedArguments,
      ) ?: return ImmutableList.of()

    val rangeStart = sourceWithRangeMarkers.sourceRangeWithinMarks.first
    val rangeEnd = sourceWithRangeMarkers.sourceRangeWithinMarks.last

    val matchingLeaves =
      completeTree.realRoot
        .leafNodeSequence()
        .filter { node ->
          val token = node.token.asAntlrToken()
          token.startIndex >= rangeStart && token.stopIndex <= rangeEnd
        }.toList()

    if (matchingLeaves.isEmpty()) {
      return ImmutableList.of()
    }

    val minimalSubtreeRoot =
      findMinimalSubtreeRootForTokens(matchingLeaves) ?: return ImmutableList.of()
    val payload = minimalSubtreeRoot.payload ?: return ImmutableList.of()

    return if (sourceWithRangeMarkers.preferMostGeneralRule) {
      payload.expectedAntlrRuleType!!.let { ImmutableList.of(it) }
    } else {
      payload.actualAntlrRuleType!!.let { ImmutableList.of(it) }
    }
  }

  private fun getParseTree(
    code: String,
    parsingRelatedArguments: LatraArguments,
  ): SparTree? {
    val ruleList =
      parsingRelatedArguments.sparTreeNodeFactory.grammarHierarchy.ruleList
        .reverse()

    for (rule in ruleList) {
      if (rule.ruleDef.isLexerRule) {
        continue
      }

      val sparTree = tryToParserCode(code, rule.ruleName, parsingRelatedArguments)

      if (sparTree != null && !sparTree.realRoot.isQuantifierNode) {
        return sparTree
      }
    }

    return null
  }

  // TODO: This prints error messages to stdout stderr
  private fun tryToParserCode(
    code: String,
    ruleName: String,
    parsingRelatedArguments: LatraArguments,
  ): SparTree? {
    val sparTreeNodeFactory = parsingRelatedArguments.sparTreeNodeFactory
    val canonicalParserFacade = parsingRelatedArguments.canonicalParserFacade
    check(sparTreeNodeFactory.parserFacade::class == canonicalParserFacade::class) {
      "They are expected to be the same parser facade class."
    }
    return try {
      val parseTree =
        canonicalParserFacade.parseString(
          code,
          filename = "empty",
          startRuleName = ruleName,
          errorMode = ParseErrorHandling.STRICT,
        )
      if (parseTree.isInputCompletelyConsumed()) {
        SparTreeBuilder(
          sparTreeNodeFactory = sparTreeNodeFactory,
          parseTreeWithParser = parseTree,
          simplifyTree = true,
          canonicalTokenCountComputer = {
            // Assume the used parser facade is the canonical one.
            null
          },
        ).result
      } else {
        // The parseString() function could return a non-null result but for an incomplete tree
        // for example, the code could be struct Person { int age; }; int main() { return 0; }
        // but it returns a tree for only struct Person { int age; };
        // hence, a check is added to determine whether the returned result is complete
        null
      }
    } catch (e: Exception) {
      null
    }
  }

  private fun findPossibleRules(
    code: String,
    parsingRelatedArguments: LatraArguments,
  ): ParserRuleSet {
    val rules = mutableSetOf<RuleHierarchyEntry>()
    val minimalRules = mutableSetOf<RuleHierarchyEntry>()

    val ruleList = parsingRelatedArguments.sparTreeNodeFactory.grammarHierarchy.ruleList

    for (rule in ruleList) {
      if (rule.ruleDef.isLexerRule) {
        continue
      }

      val sparTree = tryToParserCode(code, rule.ruleName, parsingRelatedArguments)

      if (sparTree != null && !sparTree.realRoot.isQuantifierNode) {
        rules.add(rule)

        if (sparTree.realRoot.childCount > 1) {
          minimalRules.add(rule)
        }
      }
    }

    return ParserRuleSet(
      allAvailableParserRules = ImmutableSet.copyOf(rules),
      subtreeRootParserRules = ImmutableSet.copyOf(minimalRules),
    )
  }

  /**
   * Rank the parsing rules from the highest number of distinct paths leading to it
   */
  private fun rankTargetNodesIncomingPaths(
    possibleRules: ParserRuleSet,
    numOfIncomingPathsPerNode: ImmutableMap<RuleHierarchyEntry, Int>,
  ): ImmutableList<RuleHierarchyEntry> {
    val targetNodesIncomingPaths =
      possibleRules.allAvailableParserRules.associateWith { rule ->
        numOfIncomingPathsPerNode[rule]
      }

    return targetNodesIncomingPaths
      .toList()
      .sortedWith(
        compareByDescending<Pair<RuleHierarchyEntry, Int?>> {
          it.first in possibleRules.subtreeRootParserRules
        }.thenByDescending {
          it.second
        },
      ).map {
        it.first
      }.toImmutableList()
  }

  fun createNodeFromString(
    source: String,
    rule: String,
    parsingRelatedArguments: LatraArguments,
  ): AbstractSparTreeNode =
    tryToParserCode(
      code = source,
      ruleName = rule,
      parsingRelatedArguments = parsingRelatedArguments,
    )!!.detachRootFromTree()

  /**
   * find all nodes under sub-root with same token text as target node
   */
  fun findLexerRuleNodesInSubtree(
    subRoot: AbstractSparTreeNode,
    lexeme: String,
  ): ImmutableList<AbstractSparTreeNode> {
    require(lexeme.isNotEmpty() && !lexeme.first().isWhitespace() && !lexeme.last().isWhitespace())
    val builder = ImmutableList.Builder<AbstractSparTreeNode>()
    subRoot.preOrderVisit { node ->
      if (node.isTokenNode() && ((node as LexerRuleSparTreeNode).token.lexemeText == lexeme)) {
        builder.add(node)
      }
      node.immutableChildView
    }
    return builder.build()
  }

  fun hasBalancedParentheses(tokens: List<LexerRuleSparTreeNode>): Boolean {
    val stack = SimpleStack<String>()

    for (token in tokens) {
      when (val tokenValue = token.token.lexemeText) {
        "(", "{", "[" -> {
          stack.add(tokenValue)
        }

        ")" -> {
          if (stack.isEmpty() || stack.remove() != "(") {
            return false
          }
        }

        "}" -> {
          if (stack.isEmpty() || stack.remove() != "{") {
            return false
          }
        }

        "]" -> {
          if (stack.isEmpty() || stack.remove() != "[") {
            return false
          }
        }
      }
    }
    return stack.isEmpty()
  }

  /**
   * Returns the root of the subtree that contains exactly the nodes,
   * null is returned if such a subtree doesn't exist
   */
  fun findMinimalSubtreeRootForTokens(nodes: List<LexerRuleSparTreeNode>): AbstractSparTreeNode? {
    val lowestCommonAncestor = findLowestAncestor(nodes)
    return if (lowestCommonAncestor.leafNodeSequence().count() == nodes.size) {
      lowestCommonAncestor
    } else {
      null
    }
  }

  private fun generateBalancedTokenSplits(
    tokens: List<LexerRuleSparTreeNode>,
    holes: List<Hole>,
    isBalanced: (List<LexerRuleSparTreeNode>) -> Boolean,
  ): List<List<Pair<Int, Int>>> {
    val results = mutableListOf<List<Pair<Int, Int>>>()
    val nTokens = tokens.size

    fun backtrack(
      start: Int,
      holeIndex: Int,
      path: MutableList<Pair<Int, Int>>,
    ) {
      if (holeIndex == holes.size) {
        if (start == nTokens) {
          results.add(path.toList())
        }
        return
      }

      val hole = holes[holeIndex]
      if (hole.greedyKleenePlusMatching) {
        for (i in (start + 1)..nTokens) {
          val segment = tokens.subList(start, i)
          if (isBalanced(segment)) {
            path.add(start to i)
            backtrack(i, holeIndex + 1, path)
            path.removeLast()
          }
        }
      } else {
        if (start < nTokens) {
          path.add(start to (start + 1))
          backtrack(start + 1, holeIndex + 1, path)
          path.removeLast()
        }
      }
    }

    backtrack(0, 0, mutableListOf())
    return results
  }

  sealed class TokenHoleMatchingResult {
    class Success(
      val hole2tokenMap: ImmutableListMultimap<HoleName, AbstractSparTreeNode>,
    ) : TokenHoleMatchingResult()

    data object Failure : TokenHoleMatchingResult()
  }

  fun matchTokensToHoles(
    holesToMatch: List<Hole>,
    tokensToMatch: List<LexerRuleSparTreeNode>,
  ): TokenHoleMatchingResult {
    require(holesToMatch.isNotEmpty()) { "Holes should not be empty." }
    require(tokensToMatch.isNotEmpty()) { "Tokens should nto be empty." }
    val totalHoleCount = holesToMatch.size
    lazyAssert { holesToMatch.toHashSet().size == totalHoleCount }
    val greedyHoles = holesToMatch.filter { it.greedyKleenePlusMatching }

    // Case 1&2: Only at most one greedy hole
    // TODO(Yiran): this seems to be a heuristic. (Fixed) What if one hole after the current token
    //              is also a kleene hole?
    // I refactored this algorithm trying all valid token splits
    if (greedyHoles.size <= 1) {
      return matchTokensToHolesForAtMostOneGreedyHole(
        holesToMatch,
        tokensToMatch,
      )
    }
    return matchTokensToHolesForAtLeastTwoGreedyHoles(tokensToMatch, holesToMatch)
  }

  private fun matchTokensToHolesForAtLeastTwoGreedyHoles(
    tokensToMatch: List<LexerRuleSparTreeNode>,
    holesToMatch: List<Hole>,
  ): TokenHoleMatchingResult {
    lazyAssert { holesToMatch.count { it.greedyKleenePlusMatching } >= 2 }
    // Case 3: Multiple greedy holes —> try all valid token splits
    val splitPlans =
      generateBalancedTokenSplits(
        tokens = tokensToMatch,
        holes = holesToMatch,
        isBalanced = TransformationUtility::hasBalancedParentheses,
      )

    for (plan in splitPlans) {
      val map = ImmutableListMultimap.builder<HoleName, AbstractSparTreeNode>()
      var valid = true

      for ((i, hole) in holesToMatch.withIndex()) {
        val (start, end) = plan[i]
        if (start >= end || end > tokensToMatch.size) {
          valid = false
          break
        }

        val segment = tokensToMatch.subList(start, end)

        if (hole.greedyKleenePlusMatching) {
          val root = findMinimalSubtreeRootForTokens(segment)
          if (root != null) {
            map.put(hole.holeName, root)
          } else {
            segment.forEach { map.put(hole.holeName, it) }
          }
        } else {
          if (segment.size != 1) {
            valid = false
            break
          }
          map.put(hole.holeName, segment[0])
        }
      }

      if (valid) {
        return TokenHoleMatchingResult.Success(
          hole2tokenMap = map.build(),
        )
      }
    }
    return TokenHoleMatchingResult.Failure
  }

  private fun matchTokensToHolesForAtMostOneGreedyHole(
    holesToMatch: List<Hole>,
    tokensToMatch: List<LexerRuleSparTreeNode>,
  ): TokenHoleMatchingResult {
    val totalTokenCount = tokensToMatch.size
    val totalHoleCount = holesToMatch.size
    val hole2tokenMap = ImmutableListMultimap.builder<HoleName, AbstractSparTreeNode>()
    var currentTokenIndex = 0

    for ((holeIndex, currentHole) in holesToMatch.withIndex()) {
      if (!currentHole.greedyKleenePlusMatching) {
        hole2tokenMap.put(currentHole.holeName, tokensToMatch[currentTokenIndex])
        ++currentTokenIndex
        continue
      }
      check(currentHole.greedyKleenePlusMatching)
      val numTokensToMatch =
        (totalTokenCount - currentTokenIndex) - (totalHoleCount - holeIndex - 1)
      if (numTokensToMatch <= 0) {
        return TokenHoleMatchingResult.Failure
      }
      val targetTokenCandidatesForCurrentHole =
        tokensToMatch.subList(
          currentTokenIndex,
          currentTokenIndex + numTokensToMatch,
        )
      val minimalSubtreeRoot =
        findMinimalSubtreeRootForTokens(targetTokenCandidatesForCurrentHole)
      if (minimalSubtreeRoot == null) {
        for (targetNode in targetTokenCandidatesForCurrentHole) {
          hole2tokenMap.put(currentHole.holeName, targetNode)
        }
      } else {
        hole2tokenMap.put(currentHole.holeName, minimalSubtreeRoot)
      }
      currentTokenIndex += numTokensToMatch
    }
    return if (currentTokenIndex == totalTokenCount) {
      TokenHoleMatchingResult.Success(hole2tokenMap = hole2tokenMap.build())
    } else {
      TokenHoleMatchingResult.Failure
    }
  }

  sealed class PatternMatchingResult {
    class Match(
      val holeBindings: ImmutableMap<HoleName, ImmutableList<AbstractSparTreeNode>>,
      val concreteTokenBindings: ImmutableMap<ConcreteToken, LexerRuleSparTreeNode>,
    ) : PatternMatchingResult()

    data object NoMatch : PatternMatchingResult()
  }

  // TODO(cnsun): this algorithm needs to have a re-design. The current algorithm is adhoc.
  fun matchTokensToPattern(
    pattern: AbstractLatraPattern,
    tokens: List<LexerRuleSparTreeNode>,
  ): PatternMatchingResult {
    val patternElements = pattern.nonTriviaElements

    // more pattern elements than token elements -> mismatch
    if (tokens.size < patternElements.size) {
      return PatternMatchingResult.NoMatch
    }

    val holeBindingMap = ImmutableMap.builder<HoleName, ImmutableList<AbstractSparTreeNode>>()
    var prevConcretePatternElementInTokens = -1
    var currTokenIndex = -1
    val holesToMatch = mutableListOf<Hole>()
    val concreteTokenBindings = mutableMapOf<ConcreteToken, LexerRuleSparTreeNode>()

    for (patternElement in patternElements) {
      if (patternElement is Hole) {
        ++currTokenIndex
        if (currTokenIndex >= tokens.size) {
          return PatternMatchingResult.NoMatch
        }
        if (holesToMatch.isEmpty() && !patternElement.greedyKleenePlusMatching) {
          val currentToken = tokens[currTokenIndex]
          holeBindingMap.put(patternElement.holeName, ImmutableList.of(currentToken))
          prevConcretePatternElementInTokens = currTokenIndex
        } else {
          holesToMatch.add(patternElement)
        }
        continue
      }
      check(patternElement is ConcreteToken) {
        "Expected to see a concrete token here. $patternElement"
      }
      val concretePatternElement = patternElement.token.text
      if (holesToMatch.isEmpty()) {
        ++currTokenIndex
        // the index goes beyond the number of tokens -> mismatch
        if (currTokenIndex >= tokens.size) {
          return PatternMatchingResult.NoMatch
        }

        val currentToken = tokens[currTokenIndex]
        if (currentToken.token.lexemeText != concretePatternElement) {
          return PatternMatchingResult.NoMatch
        } else {
          check(concreteTokenBindings.put(patternElement, currentToken) == null) {
            "There is already a binding for the concrete token $patternElement"
          }
        }
        prevConcretePatternElementInTokens = currTokenIndex
        continue
      }
      check(holesToMatch.isNotEmpty()) { "holesToMatch is empty." }
      var matched = false
      while (true) {
        ++currTokenIndex
        if (currTokenIndex >= tokens.size) {
          break
        }

        val token = tokens[currTokenIndex].token.lexemeText
        if (token != concretePatternElement) {
          continue
        }
        check(token == concretePatternElement)
        val tokensToMatch =
          tokens.subList(
            prevConcretePatternElementInTokens + 1,
            currTokenIndex,
          )
        if (holesToMatch.size > tokensToMatch.size) {
          continue
        }
        if (!hasBalancedParentheses(tokensToMatch)) {
          continue
        }
        val tokensToHolesMatchResult =
          matchTokensToHoles(
            holesToMatch = holesToMatch,
            tokensToMatch = tokensToMatch,
          )
        if (tokensToHolesMatchResult is TokenHoleMatchingResult.Failure) {
          continue
        }
        check(
          tokensToHolesMatchResult is TokenHoleMatchingResult.Success,
        ) { tokensToHolesMatchResult }
        tokensToHolesMatchResult.hole2tokenMap.asMap().entries.forEach { entry ->
          holeBindingMap.put(entry.key, ImmutableList.copyOf(entry.value))
        }
        holesToMatch.clear()
        prevConcretePatternElementInTokens = currTokenIndex
        matched = true
        break
      }
      if (!matched) {
        return PatternMatchingResult.NoMatch
      }
    }

    if (holesToMatch.isNotEmpty()) {
      val tokensToMatch = tokens.subList(prevConcretePatternElementInTokens + 1, tokens.size)
      when (val result = matchTokensToHoles(holesToMatch, tokensToMatch)) {
        is TokenHoleMatchingResult.Failure -> {
          return PatternMatchingResult.NoMatch
        }

        is TokenHoleMatchingResult.Success -> {
          result.hole2tokenMap.asMap().entries.forEach { entry ->
            holeBindingMap.put(entry.key, ImmutableList.copyOf(entry.value))
          }
        }
      }
      return PatternMatchingResult.Match(
        holeBindings = holeBindingMap.build(),
        concreteTokenBindings = concreteTokenBindings.entries.toImmutableMap(),
      )
    }

    // extra tokens left -> mismatch
    return if (currTokenIndex != tokens.size - 1) {
      PatternMatchingResult.NoMatch
    } else {
      PatternMatchingResult.Match(
        holeBindings = holeBindingMap.build(),
        concreteTokenBindings = concreteTokenBindings.toImmutableMap(),
      )
    }
  }

  fun looseMatch(
    pattern: AbstractLatraPattern,
    suchAsClause: SuchAsClause,
    rootToStartMatching: AbstractSparTreeNode,
    latraArguments: LatraArguments,
  ): ImmutableList<SparTreeHoleMatch> {
    val matches = ImmutableList.builder<SparTreeHoleMatch>()
    val seenLabelMap = mutableSetOf<ImmutableMap<HoleName, ImmutableList<AbstractSparTreeNode>>>()

    val possibleParserRulesAsPatternRoots =
      if (suchAsClause.isEmpty()) {
        ImmutableList.of()
      } else {
        inferParserRule(suchAsClause.sourceCode, latraArguments).also {
          check(it.isNotEmpty()) {
            "No parser rules for the $suchAsClause"
          }
        }
      }

    rootToStartMatching.fixLinkIntegrity()

    rootToStartMatching.preOrderVisit { node ->
      val antlrRule = node.antlrRule
      if (possibleParserRulesAsPatternRoots.isNotEmpty() &&
        (antlrRule == null || !possibleParserRulesAsPatternRoots.contains(antlrRule))
      ) {
        return@preOrderVisit node.immutableChildView
      }
      if (pattern == AbstractLatraPattern.EMPTY_MATCHING) {
        // An empty pattern means we only match according to the pattern roots, i.e., a such_as
        // clause must exist
        check(possibleParserRulesAsPatternRoots.isNotEmpty())
        matches.add(SparTreeHoleMatch(node, AbstractPatternElementBindings.NonScopedBindings.EMPTY))
        return@preOrderVisit node.immutableChildView
      }
      val matchResult =
        matchTokensToPattern(
          pattern,
          node.leafNodeSequence().toList(),
        )
      if (matchResult is PatternMatchingResult.NoMatch) {
        return@preOrderVisit node.immutableChildView
      }
      check(matchResult is PatternMatchingResult.Match)
      // When the pattern has no hole (i.e., all concrete tokens)
      // the match is found but then there is no matched holes (i.e., empty)
      if (pattern.hasNoHoles() || seenLabelMap.add(matchResult.holeBindings)) {
        matches.add(
          SparTreeHoleMatch(
            node,
            NonScopedBindings(
              holeBindings = matchResult.holeBindings,
              concreteTokenBindings = matchResult.concreteTokenBindings,
            ),
          ),
        )
        return@preOrderVisit ImmutableList.of()
      }
      node.immutableChildView
    }

    return matches.build()
  }
}
