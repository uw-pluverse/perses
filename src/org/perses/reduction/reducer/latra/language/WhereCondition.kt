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
import org.antlr.v4.runtime.Token
import org.perses.reduction.reducer.latra.language.AbstractPatternElement.Hole
import org.perses.spartree.AbstractSparTreeNode
import org.perses.util.ast.Indent
import org.perses.util.transformToImmutableList
import java.io.PrintStream

@Suppress("UNCHECKED_CAST")
abstract class AbstractWhereConditionAst<Self : AbstractWhereConditionAst<Self>> :
  AbstractLatraAst() {
  final override fun equals(other: Any?): Boolean {
    if (this === other) return true
    if (other?.javaClass != javaClass) return false
    return extraEquals(other as Self)
  }

  abstract fun extraEquals(other: Self): Boolean

  final override fun hashCode(): Int = extraHashCode()

  abstract fun extraHashCode(): Int
}

abstract class AbstractWhereConditionOperand<Self : AbstractWhereConditionOperand<Self>> :
  AbstractWhereConditionAst<Self>() {
  override val childCount: Int
    get() = 0

  override fun getChild(index: Int): AbstractWhereConditionOperand<*> {
    error("Cannot get child of: $this")
  }

  abstract fun evaluate(
    holeBindingProvider: (Hole.HoleName) -> List<AbstractSparTreeNode>,
  ): ImmutableList<String>
}

class HoleOperand(
  val holeName: Hole.HoleName,
) : AbstractWhereConditionOperand<HoleOperand>() {
  override fun evaluate(
    holeBindingProvider: (Hole.HoleName) -> List<AbstractSparTreeNode>,
  ): ImmutableList<String> =
    holeBindingProvider
      .invoke(holeName)
      .flatMap { it.leafNodeSequence() }
      .transformToImmutableList { it.token.lexemeText }

  override fun toSourceCode(
    stream: PrintStream,
    indent: Indent,
    multiLineMode: Boolean,
  ) {
    stream.print(holeName.printAsHoleDefinition())
  }

  override fun extraEquals(other: HoleOperand): Boolean = holeName == other.holeName

  override fun extraHashCode(): Int = Objects.hashCode(holeName)
}

class ConcreteTokenOperand(
  val token: Token,
) : AbstractWhereConditionOperand<ConcreteTokenOperand>() {
  override fun evaluate(
    holeBindingProvider: (Hole.HoleName) -> List<AbstractSparTreeNode>,
  ): ImmutableList<String> = ImmutableList.of(token.text)

  override fun toSourceCode(
    stream: PrintStream,
    indent: Indent,
    multiLineMode: Boolean,
  ) {
    stream.print(token.text)
  }

  override fun extraEquals(other: ConcreteTokenOperand): Boolean = token.text == other.token.text

  override fun extraHashCode(): Int = Objects.hashCode(token.text)
}

class BinaryWhereCondition(
  val operator: EnumOperator,
  val left: HoleOperand,
  val right: AbstractWhereConditionOperand<*>,
) : AbstractWhereConditionAst<BinaryWhereCondition>() {
  override val childCount: Int
    get() = 2

  override fun getChild(index: Int): AbstractLatraAst =
    when (index) {
      0 -> left
      1 -> right
      else -> throw IndexOutOfBoundsException()
    }

  override fun extraHashCode(): Int = Objects.hashCode(operator, left, right)

  override fun extraEquals(other: BinaryWhereCondition): Boolean =
    operator == other.operator && left == other.left && right == other.right

  override fun toSourceCode(
    stream: PrintStream,
    indent: Indent,
    multiLineMode: Boolean,
  ) {
    left.toSourceCode(stream, indent, multiLineMode)
    stream.print(" ${operator.symbol} ")
    right.toSourceCode(stream, indent, multiLineMode)
  }

  fun evaluate(holeBindingProvider: (Hole.HoleName) -> List<AbstractSparTreeNode>): Boolean {
    val leftValue = left.evaluate(holeBindingProvider)
    val rightValue = right.evaluate(holeBindingProvider)
    val isEqual = leftValue == rightValue
    return when (operator) {
      EnumOperator.EQUAL -> isEqual
      EnumOperator.NOT_EQUAL -> !isEqual
    }
  }

  enum class EnumOperator(
    val symbol: String,
  ) {
    EQUAL("=="),
    NOT_EQUAL("!="),
    ;

    companion object {
      fun parse(symbol: String): EnumOperator =
        when (symbol) {
          "==" -> EQUAL
          "!=" -> NOT_EQUAL
          else -> error("Unknown operator $symbol")
        }
    }
  }
}
