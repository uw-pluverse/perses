/*
 * Copyright (C) 2018-2024 University of Waterloo.
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
  private val statementRule = ruleList.find {
    it.ruleName == "statement"
  }!!.ruleDef

  @Test
  fun testPreGeneratedCandidateSparTree() {
    assertThat(generator.ruleToPreGeneratedCandidateSparTreeNodeMap.size)
      .isEqualTo(ruleList.filter { it.ruleDef.tag != AstTag.RULE_DEFINITION_LEXER_FRAGMENT }.size)
    val candidateSparTreeNodes = generator
      .ruleToPreGeneratedCandidateSparTreeNodeMap[statementRule.ruleNameHandle]!!
    assertThat(candidateSparTreeNodes.size).isEqualTo(8)
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
    assertThat(
      generator.ruleToPreGeneratedCandidateSparTreeNodeMap[statementRule.ruleNameHandle]!!.map {
        it.leafTokenCount
      },
    ).isEqualTo(ImmutableList.of(3, 2, 1, 5, 7, 2, 4, 5))
  }

  @Test
  fun testGenerateNodeFromDesignatedAlternatives() {
    val tree = generator.generateNodeFromDesignatedAlternative(
      nonEmptyOriginalLexerRuleNodeList,
      statementRule.ruleNameHandle,
      1,
    )!!
    assertEqualTreeDumps(
      dump1 = tree.printTreeStructure(),
      dump2 = """
      (|:statement) {id=3267}
      |___compoundStatement {id=605,slot_type=compoundStatement}
          |___Token:{ {id=27340,slot_type=LeftBrace}
          |___(?) {id=252,slot_type=optional__compoundStatement_1}
          |___Token:} {id=27341,slot_type=RightBrace}
    
      """.trimIndent().replace(Regex("id=\\d+"), "id="),
    )
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
    assertEqualTreeDumps(
      dump1 = tree.printTreeStructure(),
      dump2 = """
      (|:statement) {id=3266}
      |___labeledStatement {id=1124,slot_type=labeledStatement}
          |___(|:altnt_block__labeledStatement_1) {id=354,slot_type=altnt_block__labeledStatement_1}
          |   |___Token:test {id=27340,slot_type=Identifier}
          |___Token:: {id=27341,slot_type=Colon}
          |___(|:statement) {id=842,slot_type=statement}
              |___expressionStatement {id=607,slot_type=expressionStatement}
                  |___(?) {id=212,slot_type=optional__postfixExpression_1}
                  |___Token:; {id=27342,slot_type=Semi}

      """.trimIndent(),
    )
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
