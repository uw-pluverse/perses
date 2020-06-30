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
import com.google.common.base.Preconditions;
import org.antlr.v4.parse.ANTLRLexer;

import java.io.PrintStream;
import java.util.List;

public final class PersesTerminalAst extends AbstractPersesTerminalAst {

  private final int tokenType;

  public PersesTerminalAst(String text, int tokenType) {
    super(text);
    Preconditions.checkArgument(text.length() > 0);
    this.tokenType = tokenType;
  }

  @Override
  public AbstractPersesRuleElement createWithNewChildren(
      List<AbstractPersesRuleElement> newChildren) {
    return new PersesTerminalAst(text, tokenType);
  }

  @Override
  public void toSourceCode(PrintStream stream, int indent, boolean multiLineMode) {
    stream.print(getText());
  }

  public int getTokenType() {
    return tokenType;
  }

  public boolean isStringLiteral() {
    boolean result = text.charAt(0) == '\'';
    Preconditions.checkState(!result || text.charAt(text.length() - 1) == '\'');
    return result;
  }

  public boolean isEOF() {
    boolean result = text.equals("EOF");
    Preconditions.checkState(!result || tokenType == ANTLRLexer.TOKEN_REF);
    return result;
  }

  @Override
  protected String getExtraLabelForTreeStructurePrinting() {
    return super.getExtraLabelForTreeStructurePrinting() + ", token=" + text;
  }

  @Override
  public AstTag getTag() {
    return AstTag.TERMINAL;
  }

  @Override
  public String toString() {
    return MoreObjects.toStringHelper(this).add("text", text).add("type", tokenType).toString();
  }

  @Override
  protected boolean extraEquivalenceTest(AbstractPersesRuleElement other) {
    PersesTerminalAst ast = (PersesTerminalAst) other;
    return text.equals(ast.text) && tokenType == ast.tokenType;
  }
}
