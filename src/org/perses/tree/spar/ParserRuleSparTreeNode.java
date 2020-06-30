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

package org.perses.tree.spar;

import org.perses.antlr.RuleHierarchyInfo;
import org.perses.antlr.RuleType;

import java.util.Optional;

/** A spar-tree node for a parser rule. */
public final class ParserRuleSparTreeNode extends AbstractSparTreeNode {

  private LexerRuleSparTreeNode beginToken;
  private LexerRuleSparTreeNode endToken;

  ParserRuleSparTreeNode(int nodeId, RuleType nodeType, RuleHierarchyInfo antlrRule) {
    super(nodeId, nodeType, Optional.of(antlrRule));
  }

  @Override
  public final String getLabelPrefix() {
    switch (nodeType) {
      case KLEENE_PLUS:
        return "(+)";
      case KLEENE_STAR:
        return "(*)";
      case OPTIONAL:
        return "(?)";
      case OTHER_RULE:
        return getRuleName();
      default:
        throw new AssertionError("Cannot reach here. " + this);
    }
  }

  @Override
  public ParserRuleSparTreeNode asParserRule() {
    return this;
  }

  @Override
  public LexerRuleSparTreeNode beginToken() {
    return beginToken;
  }

  @Override
  public LexerRuleSparTreeNode endToken() {
    return endToken;
  }

  void setBeginToken(LexerRuleSparTreeNode beginToken) {
    this.beginToken = beginToken;
  }

  void setEndToken(LexerRuleSparTreeNode endToken) {
    this.endToken = endToken;
  }
}
