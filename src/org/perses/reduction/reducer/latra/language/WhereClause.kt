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
package org.perses.reduction.reducer.latra.language

import com.google.common.base.Objects
import com.google.common.collect.ImmutableList
import org.perses.grammar.AbstractParserFacade
import org.perses.reduction.reducer.latra.language.AbstractPatternElement.Hole
import org.perses.spartree.AbstractSparTreeNode
import org.perses.util.ast.Indent
import java.io.PrintStream

class WhereClause(
  private val conditions: ImmutableList<BinaryWhereCondition>,
) : AbstractLatraAst() {
  override val childCount: Int
    get() = conditions.size

  override fun getChild(index: Int): AbstractLatraAst = conditions[index]

  override fun toSourceCode(
    stream: PrintStream,
    indent: Indent,
    multiLineMode: Boolean,
  ) {
    stream.print("where ")
    if (conditions.isNotEmpty()) {
      conditions[0].toSourceCode(stream, indent, multiLineMode)
      for (i in 1 until conditions.size) {
        stream.print(", ")
        conditions[i].toSourceCode(stream, indent, multiLineMode)
      }
    }
  }

  override fun equals(other: Any?): Boolean = other is WhereClause && conditions == other.conditions

  override fun hashCode(): Int = Objects.hashCode(conditions)

  fun evaluate(holeBindingProvider: (Hole.HoleName) -> List<AbstractSparTreeNode>): Boolean {
    for (condition in conditions) {
      if (!condition.evaluate(holeBindingProvider)) {
        return false
      }
    }
    return true
  }

  companion object {
    val EMPTY = WhereClause(conditions = ImmutableList.of())

    fun parseConditions(
      input: String,
      parserFacade: AbstractParserFacade,
    ): ImmutableList<BinaryWhereCondition> {
      if (input == "") {
        return ImmutableList.of()
      }
      val binaryWhereConditions = ImmutableList.builder<BinaryWhereCondition>()
      // FIXME(cnsun): this is hacky based on the ",". It is possible that the RHS is ",".
      val conditions = input.split(",")

      for (condition in conditions) {
        val operatorSplit = condition.split("==", "!=").map { it.trim() }
        // FIXME(cnsun): it is possible that the RHS is "==".
        check(operatorSplit.size == 2) { "Failed to split condition into LHS and RHS" }

        val leftHole =
          AbstractLatraPattern
            .parseMatchingPattern(
              operatorSplit[0],
              parserFacade,
            ).holes
        check(leftHole.size == 1) { "No hole found in LHS condition: $condition" }
        val leftOperand = HoleOperand(leftHole.single().holeName)

        val operator: BinaryWhereCondition.EnumOperator =
          when {
            "==" in condition -> BinaryWhereCondition.EnumOperator.EQUAL
            "!=" in condition -> BinaryWhereCondition.EnumOperator.NOT_EQUAL
            else -> error("No valid operator (== or !=) found in condition: $condition")
          }

        val rhsPattern = AbstractLatraPattern.parseMatchingPattern(operatorSplit[1], parserFacade)
        val rightOperand =
          if (rhsPattern.hasNoHoles()) {
            val element = rhsPattern.nonTriviaElements
            check(element.size == 1)
            ConcreteTokenOperand(
              (element.single() as AbstractPatternElement.ConcreteToken).token,
            )
          } else {
            val holes = rhsPattern.holes
            check(holes.size == 1)
            HoleOperand(holes.single().holeName)
          }

        binaryWhereConditions.add(BinaryWhereCondition(operator, leftOperand, rightOperand))
      }

      return binaryWhereConditions.build()
    }

    fun parse(
      patternContent: String,
      parserFacade: AbstractParserFacade,
    ): WhereClause = WhereClause(parseConditions(patternContent, parserFacade))
  }
}
