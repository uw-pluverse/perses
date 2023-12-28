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

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.grammar.c.CParserFacade
import org.perses.grammar.c.LanguageC
import org.perses.program.TokenizedProgramFactory
import org.perses.util.toImmutableList

@RunWith(JUnit4::class)
class PlaceholderSparTreeNodeTest {

  private val facade = CParserFacade()
  private val nodeFactory = SparTreeNodeFactory(
    facade.metaTokenInfoDb,
    TokenizedProgramFactory.createEmptyFactory(LanguageC),
    facade.ruleHierarchy,
  )
  private val tree = TestUtility.createSparTreeFromString(
    sourceCode = "int a();",
    facade = facade,
    simplifyTree = true,
  )

  /* Tree structure
  translationUnit {id=1}
  |___(+) {id=2,slot_type=kleene_plus__externalDeclaration}
    |___(|:declaration) {id=4,slot_type=[externalDeclaration,declaration]}
        |___(+) {id=5,slot_type=kleene_plus__declarationSpecifiers}
        |   |___Token:int {id=19,slot_type=[declarationSpecifier,typeSpecifier,Int]}
        |___(?) {id=6,slot_type=optional__initDeclaratorList}
        |   |___directDeclarator {id=11,slot_type=[initDeclaratorList,initDeclarator,declarator,directDeclarator]}
        |       |___Token:a {id=12,slot_type=Identifier}
        |       |___(*) {id=13,slot_type=kleene_star__directDeclaratorPart}
        |           |___(|:directDeclaratorPart) {id=14,slot_type=directDeclaratorPart}
        |               |___Token:( {id=15,slot_type=LeftParen}
        |               |___Token:) {id=16,slot_type=RightParen}
        |___Token:; {id=7,slot_type=Semi}
   */
  private val intNode = tree.root.leafNodeSequence().first()
  private val idNode = tree.root.leafNodeSequence().toImmutableList()[1]
  private val parenthesisNode = tree.root.leafNodeSequence().toImmutableList()[2]
  private val declarationNode = tree.root.getChild(0).getChild(0)

  @Test
  fun testMatchingPlaceholderNode() {
    val predicate = { node: AbstractSparTreeNode ->
      node.antlrRule?.ruleName == "Int"
    }
    val placeholder = PlaceholderSparTreeNode(1, "test", predicate)
    assertThat(placeholder.canBeReplacedBy(intNode)).isTrue()
    assertThat(placeholder.canBeReplacedBy(idNode)).isFalse()
    assertThat(placeholder.canBeReplacedBy(parenthesisNode)).isFalse()
    assertThat(placeholder.canBeReplacedBy(declarationNode)).isFalse()
  }

  @Test
  fun testPlaceholderNodeCreationGivenAntlrRule() {
    val antlrRule = nodeFactory.grammarHierarchy
      .getRuleHierarchyEntryWithNameOrThrow("declaration")
    val placeholder = nodeFactory.createPlaceholderSparTreeNode(antlrRule)
    assertThat(placeholder.canBeReplacedBy(intNode)).isFalse()
    assertThat(placeholder.canBeReplacedBy(idNode)).isFalse()
    assertThat(placeholder.canBeReplacedBy(parenthesisNode)).isFalse()
    assertThat(placeholder.canBeReplacedBy(declarationNode)).isTrue()
  }

  // gccAttribute
  // :   ~(Comma | LeftParen | RightParen) // relaxed def for "identifier or reserved word"
  // optional__gccAttributePart
  // ;
  @Test
  fun testPlaceholderNodeCreationGivenRuleElement() {
    val antlrRule = nodeFactory.grammarHierarchy
      .getRuleHierarchyEntryWithNameOrThrow("gccAttribute")
    val tokenSetNegation = antlrRule.ruleDef.body.getChild(0)
    val placeholder = nodeFactory.createPlaceholderSparTreeNode(tokenSetNegation)
    assertThat(placeholder.canBeReplacedBy(intNode)).isTrue()
    assertThat(placeholder.canBeReplacedBy(idNode)).isTrue()
    assertThat(placeholder.canBeReplacedBy(parenthesisNode)).isFalse()
    assertThat(placeholder.canBeReplacedBy(declarationNode)).isFalse()
  }
}
