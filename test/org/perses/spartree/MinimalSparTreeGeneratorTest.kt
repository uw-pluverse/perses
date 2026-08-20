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
package org.perses.spartree

import com.google.common.collect.ImmutableList
import com.google.common.primitives.ImmutableIntArray
import com.google.common.truth.Truth.assertThat
import org.antlr.v4.runtime.CommonTokenFactory
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.antlr.ast.AstTag
import org.perses.antlr.ast.PersesAlternativeBlockAst
import org.perses.antlr.ast.PersesRuleReferenceAst
import org.perses.grammar.c.PnfCParserFacade
import org.perses.program.PersesTokenFactory

@RunWith(JUnit4::class)
class MinimalSparTreeGeneratorTest {
  private val parserFacade = PnfCParserFacade()
  private val sparTreeNodeFactory =
    SparTreeNodeFactory(parserFacade)
  private val generator = MinimalSparTreeGenerator(parserFacade, sparTreeNodeFactory)

  private val nonEmptyOriginalLexerRuleNodeList =
    ImmutableList.of(
      LexerRuleSparTreeNode(
        nodeId = 0,
        PersesTokenFactory.createPersesToken(
          parserFacade.transformLiteralIntoSingleToken("if"),
          overridingPosition = null,
        ),
        parserFacade.ruleHierarchy.getRuleHierarchyEntryWithNameOrThrow("If"),
      ),
    )

  private val ruleList = parserFacade.ruleHierarchy.ruleList

  @Test
  fun testCanGenerateSingleTokens() {
    val rulesWithSingleTokens =
      generator.ruleToPreGeneratedCandidateSparTreeNodeMap.entries
        .map { (ruleName, nodeList) ->
          ruleName to
            nodeList.withIndex().filter { node ->
              node.value.isTokenNode() &&
                node.value
                  .asLexerRule()
                  .token
                  .isPlaceholder()
                  .not()
            }
        }.filter { entry ->
          entry.second.isNotEmpty()
        }.flatMap { entry ->
          entry.second.map { entry.first to it }
        }
    assertThat(rulesWithSingleTokens).isNotEmpty()
    rulesWithSingleTokens.forEach { (ruleName, alternative) ->
      check(alternative.value.isTokenNode()) {
        alternative.value.printTreeStructure()
      }
      val generatedNode =
        generator.generateNodeFromDesignatedAlternative(
          originalLexerRuleNodeList =
            ImmutableList.of(
              alternative.value
                .recursiveDeepCopy(
                  AbstractTreeNode.NodeIdCopyStrategy.ReuseNodeIdStrategy,
                ).result
                .asLexerRule(),
            ),
          ruleNameHandle = ruleName,
          indexOfAlternative = alternative.index,
        )
      assertThat(generatedNode).isNotNull()
      checkNotNull(generatedNode) { "This is null" }
      assertThat(generatedNode.isTokenNode()).isTrue()
      assertThat(
        generatedNode.asLexerRule().token.lexemeText,
      ).isEqualTo(
        alternative.value
          .asLexerRule()
          .token.lexemeText,
      )
      assertThat(
        generatedNode
          .asLexerRule()
          .token
          .asAntlrToken()
          .position,
      ).isEqualTo(
        alternative.value
          .asLexerRule()
          .token
          .asAntlrToken()
          .position,
      )
    }
  }

  // statement
  //    : labeledStatement
  //    | compoundStatement
  //    | expressionStatement
  //    | aux_rule__statement_3
  //    | aux_rule__statement_4
  //    | jumpStatement
  //    | asmStatement
  //    | aux_rule__statement_5
  //    ;
  private val statementRule =
    ruleList
      .single { entry ->
        val body = entry.ruleDef.body
        if (body !is PersesAlternativeBlockAst) {
          return@single false
        }
        val alternatives = body.alternatives
        listOf("labeledStatement", "compoundStatement", "expressionStatement")
          .all { ruleName ->
            alternatives.any {
              it is PersesRuleReferenceAst && it.ruleNameHandle.ruleName == ruleName
            }
          }
      }.ruleDef

  @Test
  fun testPreGeneratedCandidateSparTree() {
    assertThat(generator.ruleToPreGeneratedCandidateSparTreeNodeMap.size)
      .isEqualTo(ruleList.filter { it.ruleDef.tag != AstTag.RULE_DEFINITION_LEXER_FRAGMENT }.size)
    val candidateSparTreeNodes =
      generator
        .ruleToPreGeneratedCandidateSparTreeNodeMap[statementRule.ruleNameHandle]!!
    assertThat(
      candidateSparTreeNodes
        .map {
          it.leafNodeSequence().joinToString(separator = "") { it.token.lexemeText }
        }.toList(),
    ).containsExactly(
      "<!PLACEHOLDER!>:;",
      ";",
      "{}",
      "if(<!PLACEHOLDER!>);",
      "do;while(<!PLACEHOLDER!>);",
      "continue;",
      "asm();",
    )
  }

  @Test
  fun testGenerateCandidateSparTreeNodes() {
    val indicesOfAlternativesWithSmallerSize =
      generator.getIndicesOfAlternativesWithSmallerSize(
        statementRule.ruleNameHandle,
        4,
      )
    val indicesOfAlternativesWithSameSize =
      generator.getIndicesOfAlternativesWithSameSize(
        statementRule.ruleNameHandle,
        4,
      )
    assertThat(indicesOfAlternativesWithSmallerSize)
      .isEqualTo(ImmutableIntArray.of(0, 1, 2, 5))
    assertThat(indicesOfAlternativesWithSameSize)
      .isEqualTo(ImmutableIntArray.of(6))
    val abstractSparTreeNodes =
      generator.ruleToPreGeneratedCandidateSparTreeNodeMap[statementRule.ruleNameHandle]!!
        .map { it.leafNodeSequence().map { it.token.lexemeText }.joinToString(separator = "") }
    assertThat(
      abstractSparTreeNodes,
    ).containsExactly(
      "<!PLACEHOLDER!>:;",
      "{}",
      ";",
      "if(<!PLACEHOLDER!>);",
      "do;while(<!PLACEHOLDER!>);",
      "continue;",
      "asm();",
//      "switch();" FIXME(zhenyang), TODO(cnsun)
//      "while();"
    )
  }

  @Test
  fun testGenerateNodeFromDesignatedAlternatives() {
    val tree =
      generator.generateNodeFromDesignatedAlternative(
        nonEmptyOriginalLexerRuleNodeList,
        statementRule.ruleNameHandle,
        1,
      )!!
    assertThat(tree.leafNodeSequence().joinToString(separator = "") { it.token.lexemeText })
      .isEqualTo("{}")
  }

  @Test
  fun testGenerateNodeFromDesignatedAlternativesUsesOriginalToken() {
    val tree =
      generator.generateNodeFromDesignatedAlternative(
        ImmutableList.of(
          LexerRuleSparTreeNode(
            nodeId = 0,
            PersesTokenFactory.createPersesToken(
              CommonTokenFactory().create(
                parserFacade.fusedIdentifierTokenTypes[0].antlrTokenType,
                "test",
              ),
              overridingPosition = null,
            ),
            parserFacade.ruleHierarchy.getRuleHierarchyEntryWithNameOrThrow("Identifier"),
          ),
        ),
        statementRule.ruleNameHandle,
        0,
      )!!
    assertThat(tree.leafNodeSequence().joinToString(separator = "") { it.token.lexemeText })
      .isEqualTo("test:;")
  }

  private fun removeIdFromTreeDump(treeDump: String): String =
    treeDump.replace(
      Regex("id=\\d+"),
      "id=",
    )

  private fun assertEqualTreeDumps(
    dump1: String,
    dump2: String,
  ) {
    assertThat(removeIdFromTreeDump(dump1)).isEqualTo(removeIdFromTreeDump(dump2))
  }

  @Test
  fun testGenerateNodeFromDesignatedAlternativesWithInsufficientOriginalToken() {
    val tree =
      generator.generateNodeFromDesignatedAlternative(
        nonEmptyOriginalLexerRuleNodeList,
        statementRule.ruleNameHandle,
        0,
      )
    assertThat(tree).isNull()
  }
}
