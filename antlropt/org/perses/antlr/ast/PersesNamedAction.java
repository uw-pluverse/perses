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

public final class PersesNamedAction extends AbstractPersesAst {

  private final String name;
  private final String body;

  public PersesNamedAction(String name, String body) {
    this.name = name;
    this.body = body;
  }

  @Override
  public void toSourceCode(PrintStream stream, int indent, boolean multiLineMode) {
    stream.append('@').append(name).append(' ').append(body).append('\n');
  }

  @Override
  public int getChildCount() {
    return 0;
  }

  @Override
  public AbstractPersesAst getChild(int index) {
    throw new UnsupportedOperationException();
  }

  @Override
  public AstTag getTag() {
    return null;
  }
}
