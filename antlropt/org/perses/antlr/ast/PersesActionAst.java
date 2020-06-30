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

import java.io.PrintStream;
import java.util.List;

public class PersesActionAst extends AbstractPersesRuleElement {

  private final String body;

  PersesActionAst(String body) {
    this.body = body;
  }

  @Override
  public void toSourceCode(PrintStream stream, int indent, boolean multiLineMode) {
    stream.print(body);
  }

  @Deprecated
  @Override
  public AbstractPersesRuleElement getChild(int index) {
    throw new UnsupportedOperationException();
  }

  @Override
  public int getChildCount() {
    return 0;
  }

  @Override
  public AstTag getTag() {
    return AstTag.ACTION;
  }

  @Override
  public AbstractPersesRuleElement createWithNewChildren(
      List<AbstractPersesRuleElement> newChildren) {
    return new PersesActionAst(body);
  }

  @Override
  protected boolean extraEquivalenceTest(AbstractPersesRuleElement other) {
    final PersesActionAst otherAction = (PersesActionAst) other;
    return body.equals(otherAction.body);
  }
}
