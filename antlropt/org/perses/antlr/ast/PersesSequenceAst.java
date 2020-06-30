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

import com.google.common.base.MoreObjects;
import com.google.common.collect.ImmutableList;

import java.io.PrintStream;
import java.util.List;

import static com.google.common.base.Preconditions.checkArgument;

public final class PersesSequenceAst extends AbstractPersesRuleElement {

  private final ImmutableList<AbstractPersesRuleElement> children;

  public PersesSequenceAst(ImmutableList<AbstractPersesRuleElement> children) {
    checkArgument(children.size() > 1);
    for (AbstractPersesRuleElement child : children) {
      checkArgument(child.getTag() != AstTag.EPSILON);
      checkArgument(child.getTag() != AstTag.SEQUENCE);
    }
    this.children = children;
  }

  @Override
  public AbstractPersesRuleElement createWithNewChildren(
      List<AbstractPersesRuleElement> newChildren) {
    return new PersesSequenceAst(ImmutableList.copyOf(newChildren));
  }

  public ImmutableList<AbstractPersesRuleElement> getChildren() {
    return children;
  }

  @Override
  public void toSourceCode(PrintStream stream, int indent, boolean multiLineMode) {
    boolean isFirst = true;
    for (AbstractPersesAst child : children) {
      if (isFirst) {
        isFirst = false;
      } else {
        stream.print(' ');
      }
      if (child.getPrecedence().gt(getPrecedence())) {
        child.toSourceCode(stream, indent, false);
      } else {
        stream.print('(');
        child.toSourceCode(stream, indent, false);
        stream.print(')');
      }
    }
  }

  @Override
  public AbstractPersesRuleElement getChild(int index) {
    return children.get(index);
  }

  public AbstractPersesRuleElement getFirstChild() {
    return children.get(0);
  }

  public AbstractPersesRuleElement getLastChild() {
    return children.get(children.size() - 1);
  }

  @Override
  public int getChildCount() {
    return children.size();
  }

  @Override
  public AstTag getTag() {
    return AstTag.SEQUENCE;
  }

  @Override
  public String toString() {
    return MoreObjects.toStringHelper(this).add("code", getSourceCode()).toString();
  }

  public AbstractPersesRuleElement subsequence(int from, int toExcusive) {
    final int size = getChildCount();
    checkArgument(from >= 0 && from < size, "Invalid index %s", from);
    checkArgument(toExcusive > from && toExcusive <= size);
    if (from == 0 && toExcusive == size) {
      return this;
    }
    if (from + 1 == toExcusive) {
      return getChild(from);
    }
    ImmutableList.Builder<AbstractPersesRuleElement> builder = ImmutableList.builder();
    for (int i = from; i < toExcusive; ++i) {
      builder.add(getChild(i));
    }
    return new PersesSequenceAst(builder.build());
  }

  public AbstractPersesRuleElement subsequence(int from) {
    return subsequence(from, children.size());
  }
}
