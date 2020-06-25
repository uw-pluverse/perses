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
package org.perses.antlr.ast;

import com.google.common.base.Preconditions;

import java.util.List;

public class PersesPlusAst extends AbstractPersesQuantifiedAst {

  public static PersesPlusAst createGreedy(AbstractPersesRuleElement body) {
    return new PersesPlusAst(body, true);
  }

  public static PersesPlusAst createNonGreedy(AbstractPersesRuleElement body) {
    return new PersesPlusAst(body, false);
  }

  private PersesPlusAst(AbstractPersesRuleElement body, boolean isGreedy) {
    super(body, isGreedy);
  }

  @Override
  protected String getOperator() {
    return "+";
  }

  @Override
  public AstTag getTag() {
    return AstTag.PLUS;
  }

  @Override
  public AbstractPersesRuleElement createWithNewChildren(
      List<AbstractPersesRuleElement> newChildren) {
    Preconditions.checkState(newChildren.size() == 1);
    return new PersesPlusAst(newChildren.get(0), isGreedy);
  }
}
