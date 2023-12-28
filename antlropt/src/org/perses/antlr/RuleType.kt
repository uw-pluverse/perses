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
package org.perses.antlr

import org.antlr.v4.tool.Grammar
import org.perses.util.toImmutableList

/** The type of a Antlr grammar node.  */
enum class RuleType(val signaturePrefix: String, val isLexerRule: Boolean) {
  /**
   * The children of this node are all optional.
   *
   *
   * The counterpart in regular expressions is '*'
   */
  KLEENE_STAR("kleene_star__", isLexerRule = false),

  /**
   * The children of this node are all optional except one.
   *
   *
   * The counterpart in regular expressions is '+'
   */
  KLEENE_PLUS("kleene_plus__", isLexerRule = false),

  /**
   * This node has only one child or none. And the child is optional.
   *
   *
   * The counterpart in regular expressions is '?'
   */
  OPTIONAL("optional__", isLexerRule = false),
  ALT_BLOCKS("altnt_block__", isLexerRule = false),

  /** This is a token node.  */
  TOKEN("AUX_TOKEN__", isLexerRule = true),

  /** The other rules  */
  OTHER_RULE("aux_rule__", isLexerRule = false), ;

  val isParserRule: Boolean
    get() = !isLexerRule

  fun addPrefixIfMissing(suffix: String): String {
    require(suffix.isNotBlank())
    return if (suffix.startsWith(signaturePrefix)) {
      suffix
    } else {
      signaturePrefix + suffix
    }
  }

  companion object {

    @JvmStatic
    val VALUES = values().asSequence().toImmutableList()

    @JvmStatic
    fun isLexerRule(ruleName: String) = Grammar.isTokenName(ruleName)

    @JvmStatic
    fun isParserRule(ruleName: String) = !isLexerRule(ruleName)
  }
}
