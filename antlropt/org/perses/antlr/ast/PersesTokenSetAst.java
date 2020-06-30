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

import com.google.common.collect.ImmutableList;

import java.io.PrintStream;
import java.util.List;

import static com.google.common.base.Preconditions.checkArgument;
import static com.google.common.base.Preconditions.checkState;

public class PersesTokenSetAst extends AbstractPersesRuleElement {

  private final ImmutableList<AbstractPersesTerminalAst> terminals;
  private final ImmutableList<AbstractPersesTerminalAst> sortedTerminals;

  public PersesTokenSetAst(ImmutableList<AbstractPersesTerminalAst> terminals) {
    checkArgument(terminals.size() > 1);
    this.terminals = terminals;
    sortedTerminals = terminals.stream().sorted().collect(ImmutableList.toImmutableList());
  }

  @Override
  public void toSourceCode(PrintStream stream, int indent, boolean multiLineMode) {
    final int size = terminals.size();
    final int newIndent = indent + 4;
    checkState(size > 1);

    stream.print("(");
    terminals.get(0).toSourceCode(stream, newIndent, false);
    for (int i = 1; i < size; ++i) {
      stream.print(" | ");
      terminals.get(i).toSourceCode(stream, newIndent, false);
    }
    stream.print(")");
  }

  @Override
  public AbstractPersesRuleElement getChild(int index) {
    return terminals.get(index);
  }

  @Override
  protected AbstractPersesRuleElement getChildForEquivalenceChecking(int index) {
    return sortedTerminals.get(index);
  }

  @Override
  public int getChildCount() {
    return terminals.size();
  }

  @Override
  public AstTag getTag() {
    return AstTag.TOKEN_SET;
  }

  @Override
  public AbstractPersesRuleElement createWithNewChildren(
      List<AbstractPersesRuleElement> newChildren) {
    return new PersesTokenSetAst(
        newChildren.stream()
            .map(c -> (AbstractPersesTerminalAst) c)
            .collect(ImmutableList.toImmutableList()));
  }
}
