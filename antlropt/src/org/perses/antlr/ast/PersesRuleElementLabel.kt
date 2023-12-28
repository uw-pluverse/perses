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

import com.google.common.base.Strings
import org.antlr.v4.parse.ANTLRParser
import org.antlr.v4.tool.ast.GrammarAST
import org.perses.util.ast.Indent
import java.io.PrintStream

/** https://github.com/antlr/antlr4/blob/master/doc/parser-rules.md#rule-element-labels  */
class PersesRuleElementLabel(
  private val label: String,
  private val operator: String,
  val child: AbstractPersesRuleElement,
) : AbstractPersesRuleElement() {

  init {
    require(!Strings.isNullOrEmpty(label))
    require("=" == operator || "+=" == operator)
  }

  override fun toSourceCode(stream: PrintStream, indent: Indent, multiLineMode: Boolean) {
    stream.append(label).append(operator)
    val needParentheses = when (child.tag) {
      AstTag.ALTERNATIVE_BLOCK, AstTag.SEQUENCE -> true
      else -> false
    }
    if (needParentheses) {
      stream.append('(')
    }
    child.toSourceCode(stream, indent, false)
    if (needParentheses) {
      stream.append(')')
    }
  }

  override val childCount: Int
    get() = 1

  override fun getChild(index: Int): AbstractPersesRuleElement {
    require(index == 0)
    return child
  }

  override val tag = AstTag.RULE_ELEMENT_LABEL

  override fun createWithNewChildren(
    newChildren: List<AbstractPersesRuleElement>,
  ): AbstractPersesRuleElement {
    check(newChildren.size == 1)
    return PersesRuleElementLabel(label, operator, newChildren[0])
  }

  companion object {
    @JvmStatic
    fun isRuleElementLabel(node: GrammarAST): Boolean {
      val type = node.getToken().type
      if (type != ANTLRParser.ASSIGN && type != ANTLRParser.PLUS_ASSIGN) {
        return false
      }
      val size = node.childCount
      if (size != 2) {
        return false
      }
      val left = node.getChild(0) as GrammarAST
      return left.getToken().type == ANTLRParser.ID
    }
  }
}
