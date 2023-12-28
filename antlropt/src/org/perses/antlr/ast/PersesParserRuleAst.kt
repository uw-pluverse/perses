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

import org.perses.antlr.ast.RuleNameRegistry.RuleNameHandle
import org.perses.util.ast.Indent
import java.io.PrintStream

class PersesParserRuleAst(
  ruleNameHandle: RuleNameHandle,
  body: AbstractPersesRuleElement,
  val attributes: ParserRuleAttributes,
) : AbstractPersesRuleDefAst(ruleNameHandle, body) {

  class ParserRuleAttributes(
    val arguments: PersesActionAst?,
    val returns: PersesActionAst?,
    val locals: PersesActionAst?,
  ) {

    fun toSourceCode(stream: PrintStream?) {
      val emptyIndent = Indent.FOUR_CHAR_EMPTY_INDENT
      if (arguments != null) {
        stream!!.print(" [")
        arguments.toSourceCode(stream, emptyIndent, false)
        stream.print("]")
      }
      if (returns != null) {
        stream!!.print(" returns [")
        returns.toSourceCode(stream, emptyIndent, false)
        stream.print("]")
      }
      if (locals != null) {
        stream!!.print(" locals [")
        locals.toSourceCode(stream, emptyIndent, false)
        stream.print("]")
      }
    }

    fun hasReturn(): Boolean {
      return returns != null
    }

    fun hasArguments(): Boolean {
      return arguments != null
    }

    fun hasLocals(): Boolean {
      return locals != null
    }

    fun isNotEmpty() = hasReturn() || hasArguments() || hasLocals()

    fun isEmpty() = !isNotEmpty()

    fun copyWithNewLocals(newLocals: PersesActionAst?): ParserRuleAttributes {
      return ParserRuleAttributes(arguments, returns, newLocals)
    }

    fun copyWithReturn(newReturn: PersesActionAst?): ParserRuleAttributes {
      return ParserRuleAttributes(arguments, newReturn, locals)
    }

    fun copyWithArguments(newArguments: PersesActionAst?): ParserRuleAttributes {
      return ParserRuleAttributes(newArguments, returns, locals)
    }

    companion object {
      @JvmField
      val EMPTY = ParserRuleAttributes(null, null, null)
    }
  }

  override fun copyWithNewBody(newBody: AbstractPersesRuleElement): PersesParserRuleAst {
    return PersesParserRuleAst(ruleNameHandle, newBody, attributes)
  }

  override fun afterPrintRuleName(stream: PrintStream?) {
    attributes.toSourceCode(stream)
  }

  override val tag = AstTag.RULE_DEFINITION_PARSER

  override val isLexerRule: Boolean
    get() = false

  fun copyWithNewAttributes(newRuleAttributes: ParserRuleAttributes): PersesParserRuleAst {
    return PersesParserRuleAst(ruleNameHandle, body, newRuleAttributes)
  }
}
