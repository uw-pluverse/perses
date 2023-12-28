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
import java.io.PrintStream

/** TODO: test  */
class LexerModeWithLexerRules(
  val modeName: String,
  val lexerRules: ImmutableList<AbstractPersesLexerRuleAst>,
) : AbstractPersesAst() {

  override fun toSourceCode(stream: PrintStream, indent: Indent, multiLineMode: Boolean) {
    stream.append("mode ").append(modeName).append(";").print('\n')
    val childCount = childCount
    for (i in 0 until childCount) {
      getChild(i).toSourceCode(stream, Indent.FOUR_CHAR_EMPTY_INDENT, multiLineMode)
    }
  }

  override val childCount: Int
    get() = lexerRules.size

  override fun getChild(index: Int): AbstractPersesLexerRuleAst {
    return lexerRules[index]
  }

  fun copyWithNewLexerRules(
    newLexerRules: ImmutableList<AbstractPersesLexerRuleAst>,
  ): LexerModeWithLexerRules {
    return LexerModeWithLexerRules(modeName, newLexerRules)
  }

  override val tag: AstTag
    get() = AstTag.LEXER_MODE
}
