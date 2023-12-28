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

import com.google.common.collect.ImmutableList
import org.perses.util.ast.Indent
import org.perses.util.toImmutableList
import java.io.PrintStream

class PersesTokenSetAst(
  private val terminals: ImmutableList<AbstractPersesTerminalAst>,
) : AbstractPersesRuleElement() {

  private val sortedTerminals =
    terminals.asSequence().sorted().toImmutableList()

  init {
    require(terminals.size > 1)
    check(sortedTerminals.size == terminals.size)
  }

  override fun toSourceCode(stream: PrintStream, indent: Indent, multiLineMode: Boolean) {
    val size = terminals.size
    val newIndent = indent.increasedIndent
    check(size > 1)
    stream.print("(")
    terminals[0].toSourceCode(stream, newIndent, false)
    for (i in 1 until size) {
      stream.print(" | ")
      terminals[i].toSourceCode(stream, newIndent, false)
    }
    stream.print(")")
  }

  override fun getChild(index: Int): AbstractPersesRuleElement {
    return terminals[index]
  }

  override fun getChildForEquivalenceChecking(index: Int): AbstractPersesRuleElement {
    return sortedTerminals[index]
  }

  override val childCount: Int
    get() = terminals.size
  override val tag: AstTag
    get() = AstTag.TOKEN_SET

  override fun createWithNewChildren(
    newChildren: List<AbstractPersesRuleElement>,
  ): AbstractPersesRuleElement {
    return PersesTokenSetAst(
      newChildren
        .asSequence()
        .map { it as AbstractPersesTerminalAst }
        .toImmutableList(),
    )
  }
}
