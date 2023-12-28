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
import org.perses.util.ast.Indent
import java.io.PrintStream

abstract class AbstractPersesQuantifiedAst(
  val body: AbstractPersesRuleElement,
  val isGreedy: Boolean,
) : AbstractPersesRuleElement() {

  init {
    when (body.tag) {
      AstTag.EPSILON, AstTag.STAR, AstTag.PLUS, AstTag.OPTIONAL ->
        error(
          "Kleene node is disallowed in a quantified node: " +
            "${body::class.java}, current=${this::class.java}." +
            "body=${body.sourceCode}",
        )
      else -> Unit
    }
  }

  override fun toSourceCode(stream: PrintStream, indent: Indent, multiLineMode: Boolean) {
    val furtherIndent = indent.increasedIndent
    if (body.precedence.lt(precedence)) {
      stream.append('(')
      body.toSourceCode(stream, furtherIndent, false)
      stream.append(')')
    } else {
      body.toSourceCode(stream, furtherIndent, false)
    }
    stream.print(operator)
    if (!isGreedy) {
      stream.print('?')
    }
  }

  override val childCount: Int
    get() = 1

  override fun getChild(index: Int): AbstractPersesRuleElement {
    require(index == 0)
    return body
  }

  protected abstract val operator: String

  override fun toString(): String {
    return MoreObjects.toStringHelper(this).add("code", sourceCode).toString()
  }
}
