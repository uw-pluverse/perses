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
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.grammar.ParseErrorHandling
import org.perses.grammar.c.CParserFacade
import org.perses.program.TokenPosition
import org.perses.reduction.reducer.latra.TransformationUtility.PatternMatchingResult
import org.perses.reduction.reducer.latra.language.AbstractLatraPattern
import org.perses.reduction.reducer.latra.language.AbstractPatternElement.Hole
import org.perses.reduction.reducer.latra.language.AbstractPatternElement.Hole.HoleName
import org.perses.reduction.reducer.latra.language.SuchAsClause
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.AbstractTreeNode.NodeIdCopyStrategy.ReuseNodeIdStrategy
import org.perses.spartree.SparTreeNodeFactory
import org.perses.util.toImmutableMap
import org.perses.util.transformToImmutableList

@RunWith(JUnit4::class)
class TransformationUtilityForCTest {
  private val inputString = "int main() { }"
  private val facade = CParserFacade()
  private val parseTree = facade.parseString(inputString, errorMode = ParseErrorHandling.STRICT)
  private val parsingRelatedArguments =
    LatraArguments(
      canonicalParserFacade = facade,
      sparTreeNodeFactory =
        SparTreeNodeFactory(
          facade,
        ),
      programPrinter = IProgramPrinter.create(facade),
      prefixLabelFromRootToHere = "[test]",
    )

  private val input =
    """
    int func1(int a, int b) {return a+b;}
    """.trimIndent()

  private val tree =
    TestUtility.createSparTreeFromString(
      input,
      facade,
      simplifyTree = false,
    )

  private val tokens = tree.realRoot.leafNodeSequence().toList()

  val position = TokenPosition(line = 1, charPositionInLine = 2)

  @Test
  fun testCreateStringFromNodes() {
    val source =
      """
      int main ( ) {
        func_1 ( g ) ;
        String a  = "}" ;
        return 0 ;
      }
      
      """.trimIndent()
    val sparTree =
      TestUtility.createSparTreeFromString(
        source,
        facade,
        false,
        sparTreeNodeFactory = parsingRelatedArguments.sparTreeNodeFactory,
      )
    val tokens = sparTree.realRoot.leafNodeSequence().toList()
    val result = parsingRelatedArguments.createStringFromNodes(tokens)
    assertThat(result).isEqualTo(source)
  }

  @Test
  fun testRangeMarkupForStatement() {
    testInferParserRule(
      source =
        """
        int main () {
          {:
            if (a < 3) {
              printf("");
            }
          :}
        }
        """.trimIndent(),
      expected = listOf("selectionStatement"),
    )
  }

  @Test
  fun testRangeMarkupForDeclaration() {
    testInferParserRule(
      source =
        """
        int main() {
            {:int x = 5;:}
            return 0;
        }
        """.trimIndent(),
      expected = listOf("declaration"),
    )
  }

  @Test
  fun testRangeMarkupForLoop() {
    testInferParserRule(
      source =
        """
        int main() {
          {:for (int i = 0; i < 10; i++) {
              printf("%d", i);
          }:}
          return 0;
        }
        """.trimIndent(),
      expected = listOf("iterationStatement"),
    )
  }

  @Test
  fun testProcessSourceWithRangeMarkersNoMarks() {
    val source = "int a;"
    TransformationUtility.processSourceWithRangeMarkers(source).let { result ->
      assertThat(result).isInstanceOf(TransformationUtility.SourceWithoutRangeMarkers::class.java)
      check(result is TransformationUtility.SourceWithoutRangeMarkers)
      assertThat(result.source).isEqualTo(source)
    }
  }

  @Test
  fun testProcessSourceWithRangeMarkersSpecificMarks() {
    val source =
      """
      |int main() {
      |  {:int x = 5;:}
      |  return 0;
      |}
      """.trimMargin()
    val expected =
      """
          |int main() {
          |    int x = 5;
          |  return 0;
          |}    
      """.trimMargin()
    testProcessSourceWithRangeMarkers(
      source,
      expectedEntireSourceWithoutMarks = expected,
      expectedSourceWithinMarks = "int x = 5;",
      expectedPreferMostGeneralRule = false,
    )
  }

  @Test
  fun testProcessSourceWithRangeMarkersGeneralMarks() {
    val source =
      """
      |int main() {
      |  {g:int x = 5;:}
      |  return 0;
      |}
      """.trimMargin()
    val expected =
      """
          |int main() {
          |     int x = 5;
          |  return 0;
          |}    
      """.trimMargin()
    testProcessSourceWithRangeMarkers(
      source,
      expectedEntireSourceWithoutMarks = expected,
      expectedSourceWithinMarks = "int x = 5;",
      expectedPreferMostGeneralRule = true,
    )
  }

  private fun testProcessSourceWithRangeMarkers(
    source: String,
    expectedEntireSourceWithoutMarks: String,
    expectedSourceWithinMarks: String,
    expectedPreferMostGeneralRule: Boolean,
  ) {
    TransformationUtility.processSourceWithRangeMarkers(source).let { result ->
      check(result is TransformationUtility.SourceWithRangeMarkers)
      assertThat(removeTrailingSpaces(result.entireSourceWithoutMarks)).isEqualTo(
        removeTrailingSpaces(expectedEntireSourceWithoutMarks),
      )
      assertThat(removeTrailingSpaces(result.computeSourceWithinMarks())).isEqualTo(
        removeTrailingSpaces(expectedSourceWithinMarks),
      )
      assertThat(result.preferMostGeneralRule).isEqualTo(expectedPreferMostGeneralRule)
    }
  }

  private fun removeTrailingSpaces(string: String): List<String> =
    string
      .lineSequence()
      .filter {
        it.isNotBlank()
      }.map { it.trimEnd() }
      .toList()

  @Test
  fun testRangeMarkupForFunction() {
    testInferParserRule(
      source =
        """
        {:void greet() {
            printf("Hello, World!");
        }:}

        int main() {
            greet();
            return 0;
        }
        """.trimIndent(),
      expected = listOf("functionDefinition"),
    )
  }

  @Test
  fun testRangeMarkupForStruct() {
    testInferParserRule(
      source =
        """
        {:struct Person {
          char name[50];
          int age;
        };:}

        int main() {
          struct Person p1 = {"Alice", 25};
          return 0;
        }
        """.trimIndent(),
      expected = listOf("declaration"),
    )
  }

  @Test
  fun testRuleStatement() {
    testInferParserRule(
      source =
        """
        if (x > 0) {
            if (y < 10) {
                printf("Nested condition met");
            }
        }
        """.trimIndent(),
      expected =
        listOf(
          "selectionStatement",
          "statement",
          "nestedParenthesesBlock",
          "blockItem",
        ),
    )
  }

  @Test
  fun testRuleDeclaration() {
    testInferParserRule(
      source =
        """
        int result = max(10, 20);
        """.trimIndent(),
      expected =
        listOf(
          "declaration",
          "nestedParenthesesBlock",
          "blockItem",
          "translationUnit",
          "externalDeclaration",
          "compilationUnit",
        ),
    )
  }

  @Test
  fun testRuleSwitch() {
    testInferParserRule(
      source =
        """
        switch(option) {
          case 1:
              printf("One");
              break;
          case 2:
              printf("Two");
              break;
          default:
              printf("Other");
        }
        """.trimIndent(),
      expected =
        listOf(
          "selectionStatement",
          "statement",
          "nestedParenthesesBlock",
          "blockItem",
        ),
    )
  }

  @Test
  fun testRuleLoop() {
    testInferParserRule(
      source =
        """
        for (int i = 0; i < n; i++) {
          printf("%d ", i);
        }
        """.trimIndent(),
      expected =
        listOf(
          "iterationStatement",
          "statement",
          "nestedParenthesesBlock",
          "blockItem",
        ),
    )
  }

  @Test
  fun testRuleExpression() {
    testInferParserRule(
      source = "printNumbers(5);",
      expected =
        listOf(
          "expressionStatement",
          "statement",
          "nestedParenthesesBlock",
          "blockItem",
        ),
    )
  }

  @Test
  fun testRuleStruct() {
    testInferParserRule(
      source =
        """
        struct Student {
          char name[50];
          int age;
        };
        """.trimIndent(),
      expected =
        listOf(
          "declaration",
          "structDeclaration",
          "nestedParenthesesBlock",
          "blockItem",
          "translationUnit",
          "externalDeclaration",
          "compilationUnit",
        ),
    )
  }

  @Test
  fun testRankedRules() {
    testInferParserRule(
      source =
        """
        struct Student {
          char name[50];
          int age;
        };
        """.trimIndent(),
      expected =
        listOf(
          "declaration",
          "structDeclaration",
          "nestedParenthesesBlock",
          "blockItem",
          "translationUnit",
          "externalDeclaration",
          "compilationUnit",
        ),
    )
  }

  private fun testInferParserRule(
    source: String,
    expected: List<String>,
  ) {
    TransformationUtility.inferParserRule(source, parsingRelatedArguments).let {
      assertThat(it.map { it.ruleName }).isEqualTo(expected)
    }
  }

  @Test
  fun testBalancedParentheses() {
    val source =
      """
      int main ( ) {
        func_1 ( g ) ;
        String a  = "(";
        return 0 ; }
      """.trimIndent()
    val sparTree =
      TestUtility.createSparTreeFromString(
        source,
        facade,
        false,
      )
    val tokens = sparTree.realRoot.leafNodeSequence().toList()
    assertThat(TransformationUtility.hasBalancedParentheses(tokens)).isTrue()
  }

  @Test
  fun testUnbalancedParentheses() {
    val source =
      """
      int main ( ) {
        func_1 ( g ) ;
        String a  = "}" ;
        return 0 ;
      }
      """.trimIndent()
    val sparTree =
      TestUtility.createSparTreeFromString(
        source,
        facade,
        false,
      )
    var tokens = sparTree.realRoot.leafNodeSequence().toList()
    tokens = tokens.subList(0, tokens.size - 1)
    assertThat(TransformationUtility.hasBalancedParentheses(tokens)).isFalse()
  }

  @Test
  fun testMinimalSubtreeRootForTokens() {
    val source =
      """
      int main ( ) {
        func_1 ( g ) ;
        return 0 ;
      }
      """.trimIndent()
    val sparTree =
      TestUtility.createSparTreeFromString(
        source,
        facade,
        false,
      )
    var tokens = sparTree.realRoot.leafNodeSequence().toList()
    tokens = tokens.subList(5, 10)
    assertThat(
      TransformationUtility.findMinimalSubtreeRootForTokens(tokens)?.ruleName,
    ).isEqualTo("declaration")
  }

  @Test
  fun testMinimalSubtreeRootForTokensWhenNull() {
    val source =
      """
      int main ( ) {
        func_1 ( g ) ;
        return 0 ;
      }
      """.trimIndent()
    val sparTree =
      TestUtility.createSparTreeFromString(
        source,
        facade,
        false,
      )
    var tokens = sparTree.realRoot.leafNodeSequence().toList()
    tokens = tokens.subList(5, 8)
    assertThat(
      TransformationUtility.findMinimalSubtreeRootForTokens(tokens)?.ruleName,
    ).isEqualTo(null)
  }

  @Test
  fun testMatchTokensToHoles() {
    val source =
      """
      func_1 ( g ) ;
      """.trimIndent()
    val sparTree =
      TestUtility.createSparTreeFromString(
        source,
        facade,
        false,
      )
    val tokens = sparTree.realRoot.leafNodeSequence().toList()
    val nameHole = Hole.create("name", greedyKleenePlusMatching = false, position)
    val leftHole = Hole.create("left", greedyKleenePlusMatching = false, position)
    val paramHole = Hole.create("param", greedyKleenePlusMatching = false, position)
    val rightHole = Hole.create("right", greedyKleenePlusMatching = false, position)
    val endHole = Hole.create("end", greedyKleenePlusMatching = false, position)
    val holesToMatch =
      ImmutableList.of(
        nameHole,
        leftHole,
        paramHole,
        rightHole,
        endHole,
      )
    val expected =
      ImmutableListMultimap
        .builder<HoleName, AbstractSparTreeNode>()
        .put(HoleName("name"), tokens[0])
        .put(HoleName("left"), tokens[1])
        .put(HoleName("param"), tokens[2])
        .put(HoleName("right"), tokens[3])
        .put(HoleName("end"), tokens[4])
        .build()
    val labelMapResult = TransformationUtility.matchTokensToHoles(holesToMatch, tokens)
    check(labelMapResult is TransformationUtility.TokenHoleMatchingResult.Success)
    assertThat(labelMapResult.hole2tokenMap).isEqualTo(expected)
  }

  @Test
  fun testMatchTokensToGreedyHoles() {
    val source =
      """
      int func1(int a, int b);
      """.trimIndent()
    val sparTree =
      TestUtility.createSparTreeFromString(
        source,
        facade,
        false,
      )
    val tokens = sparTree.realRoot.leafNodeSequence().toList()
    val typeHole = Hole.create("type", greedyKleenePlusMatching = false, position)
    val nameHole = Hole.create("name", greedyKleenePlusMatching = false, position)
    val leftHole = Hole.create("left", greedyKleenePlusMatching = false, position)
    val paramHole = Hole.create("param", greedyKleenePlusMatching = true, position)
    val rightHole = Hole.create("right", greedyKleenePlusMatching = false, position)
    val endHole = Hole.create("end", greedyKleenePlusMatching = false, position)
    val holesToMatch =
      ImmutableList.of(
        typeHole,
        nameHole,
        leftHole,
        paramHole,
        rightHole,
        endHole,
      )
    val expectedNode = TransformationUtility.findMinimalSubtreeRootForTokens(tokens.subList(3, 8))
    val expected =
      ImmutableListMultimap
        .builder<HoleName, AbstractSparTreeNode>()
        .put(HoleName("type"), tokens[0])
        .put(HoleName("name"), tokens[1])
        .put(HoleName("left"), tokens[2])
        .put(HoleName("param"), expectedNode!!)
        .put(HoleName("right"), tokens[8])
        .put(HoleName("end"), tokens[9])
        .build()
    val labelMapResult = TransformationUtility.matchTokensToHoles(holesToMatch, tokens)
    check(labelMapResult is TransformationUtility.TokenHoleMatchingResult.Success)
    assertThat(labelMapResult.hole2tokenMap).isEqualTo(expected)
  }

  @Test
  fun testMatchTokensToMultipleGreedyHolesWithBalancedDelimiters_C() {
    val source =
      """
      int func(int a, int b[10]) { return a + b[0]; }
      """.trimIndent()
    val sparTree =
      TestUtility.createSparTreeFromString(
        source,
        facade,
        false,
      )
    val tokens = sparTree.realRoot.leafNodeSequence().toList()

    val returnTypeHole = Hole.create("returnType", greedyKleenePlusMatching = false, position)
    val nameHole = Hole.create("name", greedyKleenePlusMatching = false, position)
    val paramsHole = Hole.create("params", greedyKleenePlusMatching = true, position)
    val bodyHole = Hole.create("body", greedyKleenePlusMatching = true, position)

    val holesToMatch =
      ImmutableList.of(
        returnTypeHole,
        nameHole,
        paramsHole,
        bodyHole,
      )

    val expected =
      ImmutableListMultimap
        .builder<HoleName, AbstractSparTreeNode>()
        .put(HoleName("returnType"), tokens[0])
        .put(HoleName("name"), tokens[1])
        .put(
          HoleName("params"),
          // (int a, int b[10])
          TransformationUtility.findMinimalSubtreeRootForTokens(tokens.subList(2, 12))!!,
        ).put(
          HoleName("body"),
          // { return a + b[0]; }
          TransformationUtility.findMinimalSubtreeRootForTokens(tokens.subList(12, tokens.size))!!,
        ).build()

    val labelMapResult = TransformationUtility.matchTokensToHoles(holesToMatch, tokens)
    check(labelMapResult is TransformationUtility.TokenHoleMatchingResult.Success)
    assertThat(labelMapResult.hole2tokenMap).isEqualTo(expected)
  }

  @Test
  fun testMatchTokensToPatternZeroHole() {
    val patternElements =
      AbstractLatraPattern.parseMatchingPattern(
        "int func1(int a, int b){return a+b;}",
        facade,
      )
    val labelMapBuilder =
      TransformationUtility.matchTokensToPattern(
        patternElements,
        tokens,
      )
    check(labelMapBuilder is PatternMatchingResult.Match) { labelMapBuilder }
    assertThat(labelMapBuilder.holeBindings).hasSize(0)
  }

  @Test
  fun testMatchTokensToPatternOneHole() {
    val patternElements =
      AbstractLatraPattern.parseMatchingPattern(
        "int func1(:[param+]){return a+b;}",
        facade,
      )
    val result =
      TransformationUtility.matchTokensToPattern(
        patternElements,
        tokens,
      ) as PatternMatchingResult.Match
    val expectedNode = TransformationUtility.findMinimalSubtreeRootForTokens(tokens.subList(3, 8))!!
    assertThat(result.holeBindings).hasSize(1)
    assertThat(result.holeBindings).containsEntry(HoleName("param"), ImmutableList.of(expectedNode))
  }

  @Test
  fun testMatchTokensToPatternOneHoleNoMatch() {
    val patternElements =
      AbstractLatraPattern.parseMatchingPattern(
        "double func1(:[param+]){return a+b;}",
        facade,
      )
    val result =
      TransformationUtility.matchTokensToPattern(
        patternElements,
        tokens,
      )
    assertThat(result).isInstanceOf(PatternMatchingResult.NoMatch::class.java)
  }

  @Test
  fun testMatchTokensToPatternTwoHoles() {
    val patternElements =
      AbstractLatraPattern.parseMatchingPattern(
        "int :[name](:[param+]){return a+b;}",
        facade,
      )
    val result =
      TransformationUtility
        .matchTokensToPattern(
          patternElements,
          tokens,
        ).let { (it as PatternMatchingResult.Match).holeBindings }
    val expectedNode = TransformationUtility.findMinimalSubtreeRootForTokens(tokens.subList(3, 8))!!
    assertThat(result).isEqualTo(
      convertToExpectedResult(
        listOf(
          "name" to tokens[1],
          "param" to expectedNode,
        ),
      ),
    )
  }

  @Test
  fun testMatchTokensToPatternThreeHoles() {
    val patternElements =
      AbstractLatraPattern.parseMatchingPattern(
        ":[type] :[name](:[param+]){return a+b;}",
        facade,
      )
    val result =
      TransformationUtility
        .matchTokensToPattern(
          patternElements,
          tokens,
        ).let { (it as PatternMatchingResult.Match).holeBindings }
    val expectedNode = TransformationUtility.findMinimalSubtreeRootForTokens(tokens.subList(3, 8))!!
    assertThat(result).isEqualTo(
      convertToExpectedResult(
        listOf(
          "type" to tokens[0],
          "name" to tokens[1],
          "param" to expectedNode,
        ),
      ),
    )
  }

  @Test
  fun testMatchTokensToPatternFourHoles() {
    val patternElements =
      AbstractLatraPattern.parseMatchingPattern(
        ":[type] :[name](:[param+]) :[body+]",
        facade,
      )
    val result =
      TransformationUtility
        .matchTokensToPattern(
          patternElements,
          tokens,
        ).let { (it as PatternMatchingResult.Match).holeBindings }
    val expectedParam =
      TransformationUtility.findMinimalSubtreeRootForTokens(tokens.subList(3, 8))!!
    val expectedBody =
      TransformationUtility.findMinimalSubtreeRootForTokens(
        tokens.subList(9, tokens.size),
      )!!
    assertThat(result).isEqualTo(
      convertToExpectedResult(
        listOf(
          "type" to tokens[0],
          "name" to tokens[1],
          "param" to expectedParam,
          "body" to expectedBody,
        ),
      ),
    )
  }

  private fun convertToExpectedResult(
    data: List<Pair<String, AbstractSparTreeNode>>,
  ): ImmutableMap<HoleName, ImmutableList<AbstractSparTreeNode>> =
    data
      .map {
        HoleName(it.first) to ImmutableList.of(it.second)
      }.toImmutableMap()

  @Test
  fun testMatchTokensToPatternError() {
    // more pattern elements than tokens
    val patternElements =
      AbstractLatraPattern.parseMatchingPattern(
        "int func1(int a, int b){return a+b;} ;",
        facade,
      )
    val result =
      TransformationUtility.matchTokensToPattern(
        patternElements,
        tokens,
      )
    assertThat(result).isInstanceOf(PatternMatchingResult.NoMatch::class.java)
  }

  @Test
  fun testMatchTokensToPatternErrorIndex() {
    // token index goes beyond number of tokens
    val patternElements =
      AbstractLatraPattern.parseMatchingPattern(
        "int func1(:[param+]){:[body+]} ;",
        facade,
      )
    val result =
      TransformationUtility.matchTokensToPattern(
        patternElements,
        tokens,
      )
    assertThat(result).isInstanceOf(PatternMatchingResult.NoMatch::class.java)
  }

  @Test
  fun testMatchTokensToPatternErrorEnding() {
    // extra tokens at the end
    val patternElements =
      AbstractLatraPattern.parseMatchingPattern(
        "int func1(:[param+])",
        facade,
      )
    val result =
      TransformationUtility.matchTokensToPattern(
        patternElements,
        tokens,
      )
    assertThat(result).isInstanceOf(PatternMatchingResult.NoMatch::class.java)
  }

  private data class SparTreeWithTokens(
    val sparTreeNode: AbstractSparTreeNode,
    val tokens: List<AbstractSparTreeNode>,
  )

  private fun parseWithTokens(source: String): SparTreeWithTokens {
    val sparTreeNode = createSparTreeNode(source)
    val tokens = sparTreeNode.leafNodeSequence().toList()
    return SparTreeWithTokens(sparTreeNode, tokens)
  }

  private fun createSparTreeNode(source: String): AbstractSparTreeNode =
    parsingRelatedArguments.createSparTree(source).realRoot

  private fun getLooseMatchResult(
    sparTreeNode: AbstractSparTreeNode,
  ): ImmutableList<SparTreeHoleMatch> =
    TransformationUtility.looseMatch(
      pattern = AbstractLatraPattern.parseMatchingPattern("typedef :[type] :[alias];", facade),
      suchAsClause = SuchAsClause("typedef int ll;"),
      sparTreeNode,
      parsingRelatedArguments,
    )

  private fun createExpectedLabelMap(
    typeTokenIndex: Int,
    aliasTokenIndex: Int,
    tokens: List<AbstractSparTreeNode>,
  ): ImmutableMap<HoleName, ImmutableList<AbstractSparTreeNode>> =
    convertToExpectedResult(
      listOf(
        "type" to tokens[typeTokenIndex],
        "alias" to tokens[aliasTokenIndex],
      ),
    )

  @Test
  fun testLooseMatch() {
    val (sparTreeNode, tokens) =
      parseWithTokens(
        """
        typedef long int64_t;
        int64_t g;
        int main() {
          func_2(func_12(g_14));
        }
        """.trimIndent(),
      )
    val result = getLooseMatchResult(sparTreeNode)

    assertThat(result).hasSize(1)
    assertThat(result.single().holeBindings.holeBindings).hasSize(2)

    val expected = createExpectedLabelMap(typeTokenIndex = 1, aliasTokenIndex = 2, tokens)
    assertThat(result[0].holeBindings.holeBindings).isEqualTo(expected)
  }

  @Test
  fun testSparTreeHoleMatch() {
    val source = "typedef long int64_t;"
    val sparTree = parsingRelatedArguments.createSparTree(source)
    val sparTreeNode = sparTree.realRoot
    val match = getLooseMatchResult(sparTreeNode)
    assertThat(match).hasSize(1)

    val sparTreeCopy = sparTree.deepCopy(ReuseNodeIdStrategy)
    val matchOnSparTreeCopy = match[0].portToTreeCopy(sparTreeCopy)
    assertThat(matchOnSparTreeCopy.holeBindings.holeBindings.size).isEqualTo(
      match[0].holeBindings.holeBindings.size,
    )

    match[0].holeBindings.holeBindings.forEach { holeName, nodes ->
      assertThat(
        matchOnSparTreeCopy.holeBindings.holeBindings[holeName] ==
          nodes.transformToImmutableList {
            sparTreeCopy.getCopyNode(
              it,
            )!!
          },
      )
    }
  }

  @Test
  fun testTwoLooseMatches() {
    val (sparTreeNode, tokens) =
      parseWithTokens(
        """
        typedef long int64_t;
        typedef char uint8_t;
        int64_t g;
        uint8_t t;
        int main() {
          func_2(func_12(g_14));
        }
        """.trimIndent(),
      )
    val result = getLooseMatchResult(sparTreeNode)

    assertThat(result).hasSize(2)
    assertThat(result[0].holeBindings.holeBindings).hasSize(2)
    assertThat(result[1].holeBindings.holeBindings).hasSize(2)

    val expected1 = createExpectedLabelMap(typeTokenIndex = 1, aliasTokenIndex = 2, tokens)
    val expected2 = createExpectedLabelMap(typeTokenIndex = 5, aliasTokenIndex = 6, tokens)
    assertThat(result[0].holeBindings.holeBindings).isEqualTo(expected1)
    assertThat(result[1].holeBindings.holeBindings).isEqualTo(expected2)
  }

  @Test
  fun testLooseMatchOnlyTokens() {
    val (sparTreeNode, _) =
      parseWithTokens(
        """
        typedef long int64_t;
        int64_t g;
        int main() {
          func_2(func_12(g_14));
        }
        """.trimIndent(),
      )

    val match =
      TransformationUtility.looseMatch(
        pattern = AbstractLatraPattern.parseMatchingPattern("int64_t", facade),
        suchAsClause = SuchAsClause.EMPTY,
        sparTreeNode,
        parsingRelatedArguments,
      )

    assertThat(match.size).isEqualTo(2)
    assertThat(match[0].holeBindings.holeBindings).isEmpty()
    assertThat(match[1].holeBindings.holeBindings).isEmpty()
  }
}
