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
package org.perses.grammar;

import org.antlr.v4.runtime.ANTLRErrorListener;
import org.antlr.v4.runtime.Parser;
import org.antlr.v4.runtime.RecognitionException;
import org.antlr.v4.runtime.Recognizer;
import org.antlr.v4.runtime.atn.ATNConfigSet;
import org.antlr.v4.runtime.dfa.DFA;

import java.util.BitSet;

public class FailOnErrorAntlrErrorListener implements ANTLRErrorListener {

  private final String sourceFile;

  public FailOnErrorAntlrErrorListener(String sourceFile) {
    this.sourceFile = sourceFile;
  }

  @Override
  public void syntaxError(
      Recognizer<?, ?> recognizer,
      Object offendingSymbol,
      int line,
      int charPositionInLine,
      String msg,
      RecognitionException e) {
    final StringBuilder details = new StringBuilder();
    details.append("recognizer: ").append(recognizer).append('\n');
    details.append("offendingSymbol: ").append(offendingSymbol).append('\n');
    details.append("line: ").append(line).append('\n');
    details.append("column: ").append(charPositionInLine).append('\n');
    details.append("msg: ").append(msg).append('\n');
    throw new AntlrFailureException(e, sourceFile, details.toString());
  }

  @Override
  public void reportAmbiguity(
      Parser parser, DFA dfa, int i, int i1, boolean b, BitSet bitSet, ATNConfigSet atnConfigSet) {}

  @Override
  public void reportAttemptingFullContext(
      Parser parser, DFA dfa, int i, int i1, BitSet bitSet, ATNConfigSet atnConfigSet) {}

  @Override
  public void reportContextSensitivity(
      Parser parser, DFA dfa, int i, int i1, int i2, ATNConfigSet atnConfigSet) {}
}
