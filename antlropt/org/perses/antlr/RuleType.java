/*
 * Copyright (C) 2018-2020 University of Waterloo.
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
package org.perses.antlr;

import org.antlr.v4.tool.Grammar;

/** The type of a Antlr grammar node. */
public enum RuleType {

  /**
   * The children of this node are all optional.
   *
   * <p>The counterpart in regular expressions is '*'
   */
  KLEENE_STAR("kleene_star__", /*isLexerRule=*/ false),

  /**
   * The children of this node are all optional except one.
   *
   * <p>The counterpart in regular expressions is '+'
   */
  KLEENE_PLUS("kleene_plus__", /*isLexerRule=*/ false),

  /**
   * This node has only one child or none. And the child is optional.
   *
   * <p>The counterpart in regular expressions is '?'
   */
  OPTIONAL("optional__", /*isLexerRule=*/ false),

  ALT_BLOCKS("alternative__", /*isLexerRule=*/ false),

  /** This is a token node. */
  TOKEN("", /*isLexerRule=*/ true),

  /** The other rules */
  OTHER_RULE("", /*isLexerRule=*/ false);

  public static boolean isKleeneStar(String ruleName) {
    return ruleName.startsWith(KLEENE_STAR.signaturePrefix);
  }

  public static boolean isKleenePlus(String ruleName) {
    return ruleName.startsWith(KLEENE_PLUS.signaturePrefix);
  }

  public static boolean isOptional(String ruleName) {
    return ruleName.startsWith(OPTIONAL.signaturePrefix);
  }

  public static boolean isAltBlocks(String ruleName) {
    return ruleName.startsWith(ALT_BLOCKS.signaturePrefix);
  }

  public static RuleType determineType(String ruleName) {
    if (isKleenePlus(ruleName)) {
      return KLEENE_PLUS;
    }
    if (isKleeneStar(ruleName)) {
      return KLEENE_STAR;
    }
    if (isOptional(ruleName)) {
      return OPTIONAL;
    }
    if (isAltBlocks(ruleName)) {
      return ALT_BLOCKS;
    }
    if (Grammar.isTokenName(ruleName)) {
      return TOKEN;
    }
    return OTHER_RULE;
  }

  private final String signaturePrefix;
  private final boolean isLexerRule;

  RuleType(String signaturePrefix, boolean isLexerRule) {
    this.signaturePrefix = signaturePrefix;
    this.isLexerRule = isLexerRule;
  }

  public boolean isLexerRule() {
    return isLexerRule;
  }

  public boolean isParserRule() {
    return !isLexerRule;
  }

  public String getSignaturePrefix() {
    return signaturePrefix;
  }
}
