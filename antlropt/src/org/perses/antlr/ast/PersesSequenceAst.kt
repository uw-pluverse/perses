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
package org.perses.antlr.ast

import com.google.common.base.MoreObjects
import com.google.common.collect.ImmutableList
import org.perses.util.ast.Indent
import org.perses.util.toImmutableList
import java.io.PrintStream

class PersesSequenceAst(
  val children: ImmutableList<AbstractPersesRuleElement>,
) : AbstractPersesRuleElement() {

  init {
    require(children.size > 1)
    for (child in children) {
      require(child.tag !== AstTag.EPSILON)
      require(child.tag !== AstTag.SEQUENCE) {
        "Cannot nest another sequence inside a sequence"
      }
    }
    children.zipWithNext { first, second ->
      require(!SmartAstConstructor.areMergeableQuantifiedNodesInSequence(first, second))
    }
  }

  override fun createWithNewChildren(
    newChildren: List<AbstractPersesRuleElement>,
  ): AbstractPersesRuleElement {
    return PersesSequenceAst(ImmutableList.copyOf(newChildren))
  }

  override fun toSourceCode(stream: PrintStream, indent: Indent, multiLineMode: Boolean) {
    var isFirst = true
    for (child in children) {
      if (isFirst) {
        isFirst = false
      } else {
        stream.print(' ')
      }
      if (child.precedence.gt(precedence)) {
        child.toSourceCode(stream, indent, false)
      } else {
        stream.print('(')
        child.toSourceCode(stream, indent, false)
        stream.print(')')
      }
    }
  }

  override fun getChild(index: Int): AbstractPersesRuleElement {
    return children[index]
  }

  val firstChild: AbstractPersesRuleElement
    get() = children[0]

  val lastChild: AbstractPersesRuleElement
    get() = children[children.size - 1]

  override val childCount: Int
    get() = children.size

  override val tag: AstTag
    get() = AstTag.SEQUENCE

  override fun toString(): String {
    return MoreObjects.toStringHelper(this).add("code", sourceCode).toString()
  }

  @JvmOverloads
  fun subsequence(from: Int, toExcusive: Int = children.size): AbstractPersesRuleElement {
    val size = childCount
    require(from in 0 until size) { "Invalid index $from" }
    require(toExcusive in from..size) {
      "toExclusive:$toExcusive, size=$size, from=$from"
    }

    if (from == 0 && toExcusive == size) {
      return this
    }
    if (from == toExcusive) {
      return PersesEpsilonAst()
    }
    if (from + 1 == toExcusive) {
      return getChild(from)
    }
    val builder = ImmutableList.builder<AbstractPersesRuleElement>()
    for (i in from until toExcusive) {
      builder.add(getChild(i))
    }
    return PersesSequenceAst(builder.build())
  }

  fun deleteElements(
    toBeDeleted: Collection<AbstractPersesRuleElement?>,
  ): AbstractPersesRuleElement {
    val remaining = children
      .asSequence()
      .filter { !toBeDeleted.contains(it) }
      .toImmutableList()
    return SmartAstConstructor.createForSequence(remaining)
  }

  companion object {

    // TODO: need tests.
    @JvmStatic
    fun flatten(
      children: List<AbstractPersesRuleElement>,
    ): ImmutableList<AbstractPersesRuleElement> {
      return ImmutableList.builderWithExpectedSize<AbstractPersesRuleElement>(children.size)
        .apply { children.forEach { flatten(it, this) } }
        .build()
    }

    private fun flatten(
      child: AbstractPersesRuleElement,
      builder: ImmutableList.Builder<AbstractPersesRuleElement>,
    ) {
      if (child.tag === AstTag.SEQUENCE) {
        child.foreachChildRuleElement { flatten(it, builder) }
      } else {
        builder.add(child)
      }
    }
  }
}
