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

enum class AstTag(val precedence: Precedence) {
  GRAMMAR(Precedence.NONE),
  OPTIONS(Precedence.NONE),
  NAMED_ACTION(Precedence.NONE),
  LEXER_RULE_LIST(Precedence.RULE),
  LEXER_MODE(Precedence.RULE),
  RULE_DEFINITION_PARSER(Precedence.RULE),
  RULE_DEFINITION_LEXER(Precedence.RULE),
  RULE_DEFINITION_LEXER_FRAGMENT(Precedence.RULE),
  LEXER_COMMAND(Precedence.LEXER_COMMAND),
  ALTERNATIVE_BLOCK(Precedence.ALTERNATIVE),
  SEQUENCE(Precedence.SEQUENCE),
  NOT(Precedence.NOT),
  STAR(Precedence.QUANTIFIER),
  PLUS(Precedence.QUANTIFIER),
  OPTIONAL(Precedence.QUANTIFIER),
  ACTION(Precedence.UNIT),
  RULE_ELEMENT_LABEL(Precedence.UNIT),
  RULE_ELEMENT_OPTION(Precedence.UNIT),
  TOKEN_SET(Precedence.UNIT),
  TERMINAL(Precedence.UNIT),
  RULE_REF(Precedence.UNIT),
  LEXER_CHAR_SET(Precedence.UNIT),
  LEXER_RANGE_OPERATOR(Precedence.UNIT),
  UNKNOWN_TERMINAL_WITH_UNIT_PRECEDENCE(Precedence.UNIT),
  EPSILON(Precedence.NONE),
  ;

  fun isQuantifier(): Boolean {
    return this == STAR || this == PLUS || this == OPTIONAL
  }
}
