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

import org.perses.util.ast.Indent
import java.io.PrintStream

class PersesRangeAst(
  private val first: PersesTerminalAst,
  private val second: PersesTerminalAst,
) : AbstractPersesRuleElement() {

  override fun toSourceCode(stream: PrintStream, indent: Indent, multiLineMode: Boolean) {
    first.toSourceCode(stream, indent, multiLineMode)
    stream.append("..")
    second.toSourceCode(stream, indent, multiLineMode)
  }

  override val childCount: Int
    get() = 2

  override fun getChild(index: Int): AbstractPersesRuleElement {
    return when (index) {
      0 -> first
      1 -> second
      else -> throw RuntimeException("Invalid index: $index")
    }
  }

  override val tag = AstTag.LEXER_RANGE_OPERATOR

  override fun createWithNewChildren(
    newChildren: List<AbstractPersesRuleElement>,
  ): AbstractPersesRuleElement {
    require(newChildren.size == 2)
    val first = newChildren[0]
    val second = newChildren[1]
    require(first is PersesTerminalAst)
    require(second is PersesTerminalAst)
    return PersesRangeAst(first, second)
  }
}
