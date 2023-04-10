/*
 * Copyright (C) 2018-2022 University of Waterloo.
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

// TODO: test
class LexerRuleList(
  val defaultModeLexerRules: ImmutableList<AbstractPersesLexerRuleAst>,
  val nonDefaultModes: ImmutableList<LexerModeWithLexerRules>,
) : AbstractPersesAst() {

  init {
    val modeNames = nonDefaultModes
      .asSequence()
      .map { obj: LexerModeWithLexerRules -> obj.modeName }
      .distinct()
      .toImmutableList()
    check(!modeNames.contains(DEFAULT_LEXER_MODe))
    check(modeNames.size == nonDefaultModes.size)
  }

  private val allChildren = ImmutableList.builder<AbstractPersesAst>()
    .addAll(defaultModeLexerRules)
    .addAll(nonDefaultModes)
    .build()

  fun flattern(): ImmutableList<AbstractPersesLexerRuleAst> {
    val builder = ImmutableList.builder<AbstractPersesLexerRuleAst>()
    builder.addAll(defaultModeLexerRules)
    nonDefaultModes
      .asSequence()
      .map { it.lexerRules }
      .forEach { builder.addAll(it) }
    return builder.build()
  }

  override fun toSourceCode(stream: PrintStream, indent: Indent, multiLineMode: Boolean) {
    for (defaultModeRule in defaultModeLexerRules) {
      defaultModeRule.toSourceCode(stream, indent, multiLineMode)
    }
    for (modeRules in nonDefaultModes) {
      modeRules.toSourceCode(stream, indent, multiLineMode)
    }
  }

  override val childCount: Int
    get() = allChildren.size

  override fun getChild(index: Int): AbstractPersesAst {
    return allChildren[index]
  }

  override val tag: AstTag
    get() = AstTag.LEXER_RULE_LIST

  companion object {
    @JvmStatic
    val DEFAULT_LEXER_MODe = "DEFAULT_MODE"
  }
}
