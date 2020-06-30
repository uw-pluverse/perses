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
import org.antlr.v4.parse.ANTLRLexer;
import org.antlr.v4.tool.ast.GrammarAST;

import java.io.PrintStream;
import java.util.List;

public final class PersesLexerCharSet extends AbstractPersesTerminalAst {

  public PersesLexerCharSet(String text) {
    super(text);
  }

  @Override
  public void toSourceCode(PrintStream stream, int indent, boolean multiLineMode) {
    stream.print(text);
  }


  public static boolean isLexerCharSet(GrammarAST ast) {
    return ast.getToken().getType() == ANTLRLexer.LEXER_CHAR_SET;
  }

  @Override
  public AstTag getTag() {
    return AstTag.LEXER_CHAR_SET;
  }

  @Override
  public AbstractPersesRuleElement createWithNewChildren(
      List<AbstractPersesRuleElement> newChildren) {
    Preconditions.checkArgument(newChildren.isEmpty());
    return new PersesLexerCharSet(text);
  }

  @Override
  public boolean extraEquivalenceTest(AbstractPersesRuleElement other) {
    PersesLexerCharSet charSet = (PersesLexerCharSet) other;
    return text.equals(charSet.text);
  }
}
