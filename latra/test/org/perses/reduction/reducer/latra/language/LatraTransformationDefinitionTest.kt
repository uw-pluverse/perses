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
package org.perses.reduction.reducer.latra.language

import com.google.common.truth.Truth.assertThat
import org.junit.Assert
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.grammar.AbstractParserFacade
import org.perses.grammar.c.CParserFacade
import org.perses.grammar.c.OrigCParserFacade
import org.perses.reduction.reducer.latra.IProgramPrinter
import org.perses.reduction.reducer.latra.LatraArguments
import org.perses.reduction.reducer.latra.TransformationUtility
import org.perses.spartree.SparTreeNodeFactory

@RunWith(JUnit4::class)
class LatraTransformationDefinitionTest {
  val parserFacade = CParserFacade()
  private val facade: AbstractParserFacade = OrigCParserFacade()
  private val printer = IProgramPrinter.create(facade)
  private val latraArguments =
    LatraArguments(
      canonicalParserFacade = facade,
      sparTreeNodeFactory =
        SparTreeNodeFactory(
          facade,
        ),
      programPrinter = printer,
      prefixLabelFromRootToHere = "[test]",
    )

  @Test
  fun testGetHoleDefinition() {
    val from =
      FromClause.parse(
        patternContent = ":[name]",
        parserFacade = parserFacade,
      )
    assertThat(from.getHoleDefinition(AbstractPatternElement.Hole.HoleName("name")))
      .isEqualTo(from.pattern.holes.single())
  }

  @Test
  fun testExceptionCaseOnDuplicateHoleNames() {
    Assert.assertThrows(Exception::class.java) {
      FromClause.parse("  :[name] :[name]  ", parserFacade)
    }
  }

  @Test
  fun testParsingFromYamlString() {
    val name = "test"
    val from = "int a :[term]"
    val yaml =
      """---
      |name: $name
      |from: "$from"
      |to: ""
      """.trimMargin()
    val def =
      LatraTransformationDefinition.parseYamlDefinition(
        rawDefinition = yaml,
        parserFacade,
      )
    val expected =
      LatraTransformationDefinition(
        name = name,
        matchingTemplate =
          LatraTransformationDefinition.MatchingTemplate(
            from = FromClause.parse(from, parserFacade),
          ),
        rewritingTemplate =
          LatraTransformationDefinition.RewritingTemplate(
            to = ToClause.parse("", parserFacade),
          ),
      )
    assertThat(def.toYamlString()).isEqualTo(expected.toYamlString())
  }

  @Test
  fun testEmptyWhereClause() {
    assertThat(WhereClause.EMPTY.evaluate { _ -> emptyList() }).isTrue()
  }

  @Test
  fun testPerformRewrite() {
    val holeName = AbstractPatternElement.Hole.HoleName("decl")
    val fromClause = FromClause.parse(":[decl+]", parserFacade)
    val toClause = ToClause.parse(":[decl]", parserFacade)
    toClause.pattern
    val source = "typedef long int64_t;"
    val sparTree = latraArguments.createSparTree(source)
    val sparTreeNode = sparTree.realRoot
    val match =
      TransformationUtility.looseMatch(
        pattern = fromClause.pattern,
        suchAsClause = SuchAsClause.EMPTY,
        rootToStartMatching = sparTreeNode,
        latraArguments = latraArguments,
      )
    assertThat(match.size).isEqualTo(1)

    val matchedNodes = match.single().holeBindings.holeBindings[holeName]!!
    val expected =
      matchedNodes
        .single()
        .recursiveDeepCopy(
          latraArguments.sparTreeNodeFactory,
        ).result
    val rewriteResult =
      toClause.performRewrite(
        latraArguments.sparTreeNodeFactory,
        match.single().holeBindings,
      )
    assertThat(rewriteResult.result.nodeId).isNotEqualTo(expected.nodeId)
    assertThat(
      rewriteResult.result
        .leafNodeSequence()
        .map { it.token.lexemeText }
        .toList(),
    ).isEqualTo(
      expected.leafNodeSequence().map { it.token.lexemeText }.toList(),
    )
  }
}
