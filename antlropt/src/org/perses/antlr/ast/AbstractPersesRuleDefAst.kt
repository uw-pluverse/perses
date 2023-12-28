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

import org.perses.antlr.RuleType
import org.perses.antlr.ast.RuleNameRegistry.RuleNameHandle
import org.perses.util.ast.Indent
import java.io.PrintStream

abstract class AbstractPersesRuleDefAst protected constructor(
  val ruleNameHandle: RuleNameHandle,
  val body: AbstractPersesRuleElement,
) : AbstractPersesAst() {

  init {
    require(RuleType.isLexerRule(ruleNameHandle.ruleName) == isLexerRule) {
      "$ruleNameHandle ::= body"
    }
    require(RuleType.isParserRule(ruleNameHandle.ruleName) == isParserRule) {
      "$ruleNameHandle ::= body"
    }
  }

  abstract val isLexerRule: Boolean

  val isParserRule: Boolean
    get() = !isLexerRule

  abstract fun copyWithNewBody(newBody: AbstractPersesRuleElement): AbstractPersesRuleDefAst

  override fun toSourceCode(
    stream: PrintStream,
    indent: Indent,
    multiLineMode: Boolean,
  ) {
    stream.print(ruleNameHandle.ruleName)
    afterPrintRuleName(stream)
    stream.print('\n')
    val newIndent = indent.increasedIndent
    newIndent.printIndent(stream).append(": ")
    body.toSourceCode(stream, newIndent, true)
    stream.print('\n')
    newIndent.printIndent(stream).append(';').print('\n')
  }

  protected open fun afterPrintRuleName(stream: PrintStream?) {}

  override val childCount: Int
    get() = 1

  override fun getChild(index: Int): AbstractPersesAst {
    require(index == 0)
    return body
  }

  override val extraLabelForTreeStructurePrinting: String
    get() = super.extraLabelForTreeStructurePrinting + ", rule=" + ruleNameHandle.ruleName
}
