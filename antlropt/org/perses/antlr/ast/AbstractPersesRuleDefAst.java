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
import org.perses.antlr.RuleType;

import java.io.PrintStream;

public abstract class AbstractPersesRuleDefAst extends AbstractPersesAst {

  final RuleNameRegistry.RuleNameHandle ruleNameHandle;
  final AbstractPersesRuleElement body;

  protected AbstractPersesRuleDefAst(
      RuleNameRegistry.RuleNameHandle ruleNameHandle, AbstractPersesRuleElement body) {
    this.ruleNameHandle = ruleNameHandle;
    this.body = body;

    RuleType type = ruleNameHandle.getType();
    Preconditions.checkState(
        type.isLexerRule() == this.isLexerRule(), "%s ::= %s", ruleNameHandle, body);
    Preconditions.checkState(
        type.isParserRule() == this.isParserRule(), "%s ::= %s", ruleNameHandle, body);
  }

  public final RuleNameRegistry.RuleNameHandle getRuleNameHandle() {
    return ruleNameHandle;
  }

  public final AbstractPersesRuleElement getBody() {
    return body;
  }

  public abstract boolean isLexerRule();

  public final boolean isParserRule() {
    return !isLexerRule();
  }

  @Override
  public void toSourceCode(PrintStream stream, /*not used*/ int indent, boolean multiLineMode) {
    stream.println(ruleNameHandle.get());
    final int newIndent = INDENT_INCREAMENT;
    printIndent(stream, newIndent).append(": ");
    body.toSourceCode(stream, newIndent, true);
    stream.println();
    printIndent(stream, newIndent).append(';').println();
  }

  @Override
  public final int getChildCount() {
    return 1;
  }

  @Override
  public final AbstractPersesAst getChild(int index) {
    Preconditions.checkArgument(index == 0);
    return body;
  }

  @Override
  protected final String getExtraLabelForTreeStructurePrinting() {
    return super.getExtraLabelForTreeStructurePrinting() + ", rule=" + ruleNameHandle.get();
  }
}
