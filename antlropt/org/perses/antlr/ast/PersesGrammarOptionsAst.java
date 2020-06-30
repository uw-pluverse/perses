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

public final class PersesGrammarOptionsAst extends AbstractPersesAst {

  public static final PersesGrammarOptionsAst EMPTY =
      new PersesGrammarOptionsAst(ImmutableList.of());

  public static final class Option {
    public final String name;
    public final String value;

    public Option(String name, String value) {
      this.name = name;
      this.value = value;
    }
  }

  private final ImmutableList<Option> options;

  public PersesGrammarOptionsAst(ImmutableList<Option> options) {
    this.options = options;
  }

  @Override
  public void toSourceCode(PrintStream stream, int indent, boolean multiLineMode) {
    if (options.isEmpty()) {
      return;
    }
    stream.print("options {\n");
    final int newIndent = indent + INDENT_INCREAMENT;
    for (Option option : options) {
      printIndent(stream, newIndent);
      stream.printf("%s=%s;\n", option.name, option.value);
    }
    printIndent(stream, indent);
    stream.print("}\n");
  }

  @Override
  public int getChildCount() {
    return 0;
  }

  @Deprecated
  @Override
  public AbstractPersesAst getChild(int index) {
    throw new UnsupportedOperationException();
  }

  @Override
  public AstTag getTag() {
    return null;
  }
}
