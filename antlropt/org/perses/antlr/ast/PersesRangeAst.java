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

import java.io.PrintStream;
import java.util.List;

public class PersesRangeAst extends AbstractPersesRuleElement {

  private final PersesTerminalAst first;
  private final PersesTerminalAst second;

  public PersesRangeAst(PersesTerminalAst first, PersesTerminalAst second) {
    this.first = first;
    this.second = second;
  }

  @Override
  public void toSourceCode(PrintStream stream, int indent, boolean multiLineMode) {
    first.toSourceCode(stream, indent, multiLineMode);
    stream.append("..");
    second.toSourceCode(stream, indent, multiLineMode);
  }

  @Override
  public int getChildCount() {
    return 2;
  }

  @Override
  public AbstractPersesRuleElement getChild(int index) {
    switch (index) {
      case 0:
        return first;
      case 1:
        return second;
      default:
        throw new RuntimeException("Invalid index: " + index);
    }
  }

  @Override
  public AstTag getTag() {
    return AstTag.LEXER_RANGE_OPERATOR;
  }

  @Override
  public AbstractPersesRuleElement createWithNewChildren(
      List<AbstractPersesRuleElement> newChildren) {
    Preconditions.checkArgument(newChildren.size() == 2);
    final AbstractPersesRuleElement first = newChildren.get(0);
    final AbstractPersesRuleElement second = newChildren.get(1);
    Preconditions.checkArgument(first instanceof PersesTerminalAst);
    Preconditions.checkArgument(second instanceof PersesTerminalAst);
    return new PersesRangeAst((PersesTerminalAst) first, (PersesTerminalAst) second);
  }
}
