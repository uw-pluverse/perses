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
import com.google.common.collect.ImmutableList;

import java.io.PrintStream;
import java.util.List;

public class PersesAlternativeBlockAst extends AbstractPersesRuleElement {

  private final ImmutableList<AbstractPersesRuleElement> alternatives;
  private final ImmutableList<AbstractPersesRuleElement> sortedAlternatives;

  public PersesAlternativeBlockAst(ImmutableList<AbstractPersesRuleElement> alternatives) {
    final int size = alternatives.size();
    Preconditions.checkArgument(size > 1, alternatives);
    this.alternatives = alternatives;
    sortedAlternatives = alternatives.stream().sorted().collect(ImmutableList.toImmutableList());
    checkNoDuplicates();
  }

  private void checkNoDuplicates() {
    final int size = alternatives.size();
    for (int i = 0; i < size - 1; ++i) {
      final AbstractPersesRuleElement prev = alternatives.get(i);
      for (int j = i + 1; j < size; ++j) {
        final AbstractPersesRuleElement current = alternatives.get(j);
        if (prev.isEquivalent(current)) {
          final StringBuilder builder = new StringBuilder();
          builder.append("Duplicate alternatives are found. \n");
          builder.append("prev=" + prev.getSourceCode()).append("\n");
          builder.append("current=" + current.getSourceCode()).append("\n");
          builder.append("All alternatives: \n");
          for (AbstractPersesRuleElement alt : alternatives) {
            builder.append("  " + alt.getSourceCode()).append("\n");
          }
          throw new RuntimeException(builder.toString());
        }
        Preconditions.checkArgument(!prev.isEquivalent(current));
      }
    }
  }

  @Override
  protected AbstractPersesRuleElement getChildForEquivalenceChecking(int index) {
    return sortedAlternatives.get(index);
  }

  public ImmutableList<AbstractPersesRuleElement> getAlternatives() {
    return alternatives;
  }

  @Override
  public void toSourceCode(PrintStream stream, int indent, boolean multiLineMode) {
    boolean first = true;
    for (AbstractPersesRuleElement alt : alternatives) {
      if (first) {
        first = false;
      } else {
        if (multiLineMode) {
          stream.println();
          printIndent(stream, indent).append("| ");
        } else {
          stream.append(" | ");
        }
      }
      alt.toSourceCode(stream, indent, false);
    }
  }

  @Override
  public int getChildCount() {
    return alternatives.size();
  }

  @Override
  public AbstractPersesRuleElement getChild(int index) {
    return alternatives.get(index);
  }

  @Override
  public AstTag getTag() {
    return AstTag.ALTERNATIVE_BLOCK;
  }

  @Override
  public AbstractPersesRuleElement createWithNewChildren(
      List<AbstractPersesRuleElement> newChildren) {
    return new PersesAlternativeBlockAst(ImmutableList.copyOf(newChildren));
  }

  @Override
  public String toString() {
    return getSourceCode();
  }
}
