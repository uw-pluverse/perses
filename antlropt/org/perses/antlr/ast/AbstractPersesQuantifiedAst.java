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

public abstract class AbstractPersesQuantifiedAst extends AbstractPersesRuleElement {
  protected final AbstractPersesRuleElement body;
  protected final boolean isGreedy;

  public AbstractPersesQuantifiedAst(AbstractPersesRuleElement body, boolean isGreedy) {
    this.body = body;
    this.isGreedy = isGreedy;
  }

  public final boolean isGreedy() {
    return isGreedy;
  }

  @Override
  public void toSourceCode(PrintStream stream, int indent, boolean multiLineMode) {
    if (body.getPrecedence().lt(getPrecedence())) {
      stream.append('(');
      body.toSourceCode(stream, indent + 4, false);
      stream.append(')');
    } else {
      body.toSourceCode(stream, indent + 4, false);
    }
    stream.print(getOperator());
    if (!isGreedy) {
      stream.print('?');
    }
  }

  public AbstractPersesRuleElement getBody() {
    return body;
  }

  @Override
  public int getChildCount() {
    return 1;
  }

  @Override
  public AbstractPersesRuleElement getChild(int index) {
    Preconditions.checkArgument(index == 0);
    return getBody();
  }

  protected abstract String getOperator();
}
