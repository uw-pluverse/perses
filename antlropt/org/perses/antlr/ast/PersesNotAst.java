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

public class PersesNotAst extends AbstractPersesRuleElement {

  private final AbstractPersesRuleElement tokens;

  public PersesNotAst(AbstractPersesRuleElement tokens) {
    this.tokens = tokens;
  }

  @Override
  public void toSourceCode(PrintStream stream, int indent, boolean multiLineMode) {
    stream.print("~");
    tokens.toSourceCode(stream, indent, false);
  }

  @Override
  public AbstractPersesRuleElement getChild(int index) {
    Preconditions.checkArgument(index == 0);
    return tokens;
  }

  @Override
  public int getChildCount() {
    return 1;
  }

  @Override
  public AstTag getTag() {
    return AstTag.NOT;
  }

  @Override
  public AbstractPersesRuleElement createWithNewChildren(
      List<AbstractPersesRuleElement> newChildren) {
    Preconditions.checkArgument(newChildren.size() == 1);
    return new PersesNotAst(newChildren.get(0));
  }
}
