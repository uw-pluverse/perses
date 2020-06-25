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

// TODO: merge with PersesLexerSkipCommandAst to remove duplicate code.
public class PersesLexerChannelCommandAst extends AbstractPersesRuleElement {

  private final String channelName;
  private final AbstractPersesRuleElement body;

  public PersesLexerChannelCommandAst(String channelName, AbstractPersesRuleElement body) {
    this.channelName = channelName;
    this.body = body;
  }

  @Override
  public void toSourceCode(PrintStream stream, int indent, boolean multiLineMode) {
    if (body.getPrecedence().lt(getPrecedence())) {
      stream.print('(');
      body.toSourceCode(stream, indent, multiLineMode);
      stream.println(')');
    } else {
      body.toSourceCode(stream, indent, multiLineMode);
    }
    stream.printf(" -> channel(%s)\n", channelName);
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
    return body;
  }

  @Override
  public AstTag getTag() {
    return AstTag.LEXER_CHANNEL_COMMAND;
  }

  @Override
  public AbstractPersesRuleElement createWithNewChildren(
      List<AbstractPersesRuleElement> newChildren) {
    Preconditions.checkArgument(newChildren.size() == 1);
    return new PersesLexerChannelCommandAst(channelName, newChildren.get(0));
  }
}
