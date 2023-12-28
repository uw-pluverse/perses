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

import org.antlr.v4.parse.ANTLRParser
import org.antlr.v4.tool.ast.GrammarAST
import org.perses.util.ast.Indent
import java.io.PrintStream

class PersesRuleElementOption(
  val key: String,
  val value: String,
) : AbstractPersesRuleElement() {

  override fun toSourceCode(stream: PrintStream, indent: Indent, multiLineMode: Boolean) {
    stream.append("<").append(key).append("=").append(value).append(">")
  }

  override val childCount: Int
    get() = 0

  @Deprecated("")
  override fun getChild(index: Int): AbstractPersesRuleElement {
    throw UnsupportedOperationException()
  }

  override val tag: AstTag
    get() = AstTag.RULE_ELEMENT_OPTION

  override fun createWithNewChildren(
    newChildren: List<AbstractPersesRuleElement>,
  ): AbstractPersesRuleElement {
    require(newChildren.isEmpty())
    return PersesRuleElementOption(key, value)
  }

  companion object {
    @JvmStatic
    fun isRuleElementOption(ast: GrammarAST): Boolean {
      return ast.getToken().type == ANTLRParser.ELEMENT_OPTIONS
    }
  }
}
