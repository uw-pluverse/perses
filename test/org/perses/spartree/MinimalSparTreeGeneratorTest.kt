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
import org.perses.program.TokenizedProgramFactory

@RunWith(JUnit4::class)
class MinimalSparTreeGeneratorTest {
  private val parserFacade = PnfCParserFacade()
  private val sparTreeNodeFactory = SparTreeNodeFactory(
    metaTokenInfoDb = parserFacade.metaTokenInfoDb,
    TokenizedProgramFactory.createEmptyFactory(
      languageKind = parserFacade.language,
    ),
    grammarHierarchy = parserFacade.ruleHierarchy,
  )
  private val generator = MinimalSparTreeGenerator(parserFacade, sparTreeNodeFactory)

  private val nonEmptyOriginalLexerRuleNodeList = ImmutableList.of(
    LexerRuleSparTreeNode(
      nodeId = 0,
      PersesTokenFactory().createPersesToken(
        parserFacade.transformLiteralIntoSingleToken("if"),
      ),
      parserFacade.ruleHierarchy.getRuleHierarchyEntryWithNameOrThrow("If"),
    ),
  )

  private val ruleList = parserFacade.ruleHierarchy.ruleList

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
  private val statementRule = ruleList.single { entry ->
    val body = entry.ruleDef.body
    if (body !is PersesAlternativeBlockAst) {
      return@single false
    }
    val alternatives = body.alternatives
    listOf("labeledStatement", "compoundStatement", "expressionStatement")
      .all { ruleName ->
        alternatives.any { it is PersesRuleReferenceAst && it.ruleNameHandle.ruleName == ruleName }
      }
  }.ruleDef

  @Test
  fun testPreGeneratedCandidateSparTree() {
    assertThat(generator.ruleToPreGeneratedCandidateSparTreeNodeMap.size)
      .isEqualTo(ruleList.filter { it.ruleDef.tag != AstTag.RULE_DEFINITION_LEXER_FRAGMENT }.size)
    val candidateSparTreeNodes = generator
      .ruleToPreGeneratedCandidateSparTreeNodeMap[statementRule.ruleNameHandle]!!
    assertThat(
      candidateSparTreeNodes.map {
        it.leafNodeSequence().joinToString(separator = "") { it.token.text }
      }.toList(),
    )
      .containsExactly(
        ":;",
        ";",
        "{}",
        "if();",
        "do;while();",
        "continue;",
        "asm();",
      )
  }

  @Test
  fun testGenerateCandidateSparTreeNodes() {
    val indicesOfAlternativesWithSmallerSize = generator.getIndicesOfAlternativesWithSmallerSize(
      statementRule.ruleNameHandle,
      4,
    )
    val indicesOfAlternativesWithSameSize = generator.getIndicesOfAlternativesWithSameSize(
      statementRule.ruleNameHandle,
      4,
    )
    assertThat(indicesOfAlternativesWithSmallerSize)
      .isEqualTo(ImmutableIntArray.of(0, 1, 2, 5))
    assertThat(indicesOfAlternativesWithSameSize)
      .isEqualTo(ImmutableIntArray.of(6))
    val abstractSparTreeNodes =
      generator.ruleToPreGeneratedCandidateSparTreeNodeMap[statementRule.ruleNameHandle]!!
        .map { it.leafNodeSequence().map { it.token.text }.joinToString(separator = "") }
    assertThat(
      abstractSparTreeNodes,
    ).containsExactly(
      ":;",
      "{}",
      ";",
      "if();",
      "do;while();",
      "continue;",
      "asm();",
//      "switch();" FIXME(zhenyang)
//      "while();"
    )
  }

  @Test
  fun testGenerateNodeFromDesignatedAlternatives() {
    val tree = generator.generateNodeFromDesignatedAlternative(
      nonEmptyOriginalLexerRuleNodeList,
      statementRule.ruleNameHandle,
      1,
    )!!
    assertThat(tree.leafNodeSequence().joinToString(separator = "") { it.token.text })
      .isEqualTo("{}")
  }

  @Test
  fun testGenerateNodeFromDesignatedAlternativesUsesOriginalToken() {
    val tree = generator.generateNodeFromDesignatedAlternative(
      ImmutableList.of(
        LexerRuleSparTreeNode(
          nodeId = 0,
          PersesTokenFactory().createPersesToken(
            CommonTokenFactory().create(
              parserFacade.identifierTokenTypes[0].antlrTokenType,
              "test",
            ),
          ),
          parserFacade.ruleHierarchy.getRuleHierarchyEntryWithNameOrThrow("Identifier"),
        ),
      ),
      statementRule.ruleNameHandle,
      0,
    )!!
    assertThat(tree.leafNodeSequence().joinToString(separator = "") { it.token.text })
      .isEqualTo("test:;")
  }

  private fun removeIdFromTreeDump(treeDump: String): String = treeDump.replace(
    Regex("id=\\d+"),
    "id=",
  )

  private fun assertEqualTreeDumps(dump1: String, dump2: String) {
    assertThat(removeIdFromTreeDump(dump1)).isEqualTo(removeIdFromTreeDump(dump2))
  }

  @Test
  fun testGenerateNodeFromDesignatedAlternativesWithInsufficientOriginalToken() {
    val tree = generator.generateNodeFromDesignatedAlternative(
      nonEmptyOriginalLexerRuleNodeList,
      statementRule.ruleNameHandle,
      0,
    )
    assertThat(tree).isNull()
  }
}
