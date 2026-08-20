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
import org.antlr.v4.runtime.CommonToken
import org.junit.Assert
import org.junit.Test
import org.perses.TestUtility
import org.perses.grammar.c.OrigCParserFacade
import org.perses.program.TokenPosition
import org.perses.spartree.AbstractSparTreeNode

class WhereClauseTest {
  private val parserFacade = OrigCParserFacade()

  private fun makeHoleOperand(holeNameStr: String = "var"): HoleOperand {
    val holeName = AbstractPatternElement.Hole.HoleName(holeNameStr)
    val hole =
      AbstractPatternElement.Hole(
        holeName,
        greedyKleenePlusMatching = false,
        tokenPosition =
          TokenPosition(
            line = TokenPosition.FIRST_LINE_NUMBER,
            charPositionInLine = TokenPosition.FIRST_CHAR_POSITION_IN_LINE,
          ),
      )
    return HoleOperand(hole.holeName)
  }

  private fun makeConcreteTokenOperand(text: String): ConcreteTokenOperand =
    ConcreteTokenOperand(CommonToken(0, text))

  private fun getMatchedNode(code: String): AbstractSparTreeNode =
    TestUtility
      .createSparTreeFromString(code, parserFacade, simplifyTree = false)
      .realRoot
      .leafNodeSequence()
      .toList()[1]

  private fun createBindingProvider(
    node: AbstractSparTreeNode,
    holeNameStr: String = "var",
  ): (AbstractPatternElement.Hole.HoleName) -> List<AbstractSparTreeNode> =
    { name ->
      check(name.name == holeNameStr) { "Unexpected hole name: ${name.name}" }
      listOf(node)
    }

  @Test
  fun testEvaluateConditionReturnsTrue() {
    val holeOperand = makeHoleOperand()
    val tokenOperandX = makeConcreteTokenOperand("x")
    val tokenOperandY = makeConcreteTokenOperand("y")

    val matchedX = getMatchedNode("int x = 0;")
    val equalCondition =
      BinaryWhereCondition(BinaryWhereCondition.EnumOperator.EQUAL, holeOperand, tokenOperandX)
    assertThat(equalCondition.evaluate(createBindingProvider(matchedX))).isTrue()

    val matchedZ = getMatchedNode("int z = 0;")
    val notEqualCondition =
      BinaryWhereCondition(BinaryWhereCondition.EnumOperator.NOT_EQUAL, holeOperand, tokenOperandY)
    assertThat(notEqualCondition.evaluate(createBindingProvider(matchedZ))).isTrue()
  }

  @Test
  fun testEvaluateConditionReturnsFalse() {
    val holeOperand = makeHoleOperand()
    val tokenOperandX = makeConcreteTokenOperand("x")
    val tokenOperandY = makeConcreteTokenOperand("y")

    val matchedX = getMatchedNode("int x = 0;")
    val notEqualCondition =
      BinaryWhereCondition(BinaryWhereCondition.EnumOperator.NOT_EQUAL, holeOperand, tokenOperandX)
    assertThat(notEqualCondition.evaluate(createBindingProvider(matchedX))).isFalse()

    val matchedZ = getMatchedNode("int z = 0;")
    val equalCondition =
      BinaryWhereCondition(BinaryWhereCondition.EnumOperator.EQUAL, holeOperand, tokenOperandY)
    assertThat(equalCondition.evaluate(createBindingProvider(matchedZ))).isFalse()
  }

  @Test
  fun testParseSingleCondition() {
    val binaryConditions = WhereClause.parseConditions(":[name] == func1", parserFacade)
    assertThat(binaryConditions).hasSize(1)
    assertThat(binaryConditions.single().left).isEqualTo(makeHoleOperand("name"))
    assertThat(binaryConditions.single().operator.symbol).isEqualTo("==")
    assertThat(binaryConditions.single().right).isEqualTo(makeConcreteTokenOperand("func1"))
  }

  @Test
  fun testParseConditions() {
    val binaryConditions =
      WhereClause.parseConditions(
        ":[type1]  ==  int, :[type2]!= int",
        parserFacade,
      )
    val tokenOperandInt = makeConcreteTokenOperand("int")

    assertThat(binaryConditions).hasSize(2)
    assertThat(binaryConditions[0].left).isEqualTo(makeHoleOperand("type1"))
    assertThat(binaryConditions[0].operator.symbol).isEqualTo("==")
    assertThat(binaryConditions[0].right).isEqualTo(tokenOperandInt)
    assertThat(binaryConditions[1].left).isEqualTo(makeHoleOperand("type2"))
    assertThat(binaryConditions[1].operator.symbol).isEqualTo("!=")
    assertThat(binaryConditions[1].right).isEqualTo(tokenOperandInt)
  }

  @Test
  fun testParseConditionsWithHoleOnRHS() {
    val conditions = WhereClause.parseConditions(":[type1] == :[type2]", parserFacade)
    assertThat(conditions).hasSize(1)
    assertThat(conditions[0].left).isEqualTo(makeHoleOperand("type1"))
    assertThat(conditions[0].right).isEqualTo(makeHoleOperand("type2"))
  }

  @Test
  fun testParseConditionsError() {
    Assert.assertThrows(Exception::class.java) {
      WhereClause.parseConditions(":[type1] > 1", parserFacade)
    }

    Assert.assertThrows(Exception::class.java) {
      WhereClause.parseConditions(":[type1] == ", parserFacade)
    }

    Assert.assertThrows(Exception::class.java) {
      WhereClause.parseConditions(":[type1] == int,", parserFacade)
    }

    Assert.assertThrows(Exception::class.java) {
      WhereClause.parseConditions("int == :[type1]", parserFacade)
    }

    Assert.assertThrows(Exception::class.java) {
      WhereClause.parseConditions("int == :[type1]", parserFacade)
    }

    Assert.assertThrows(IllegalStateException::class.java) {
      WhereClause.parseConditions(":[type1] == int,, :[type2] == int", parserFacade)
    }
  }
}
