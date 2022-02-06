/*
 * Copyright (C) 2018-2022 University of Waterloo.
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
package org.perses.antlr.pnf;

import com.google.common.base.Preconditions;
import java.io.Closeable;
import java.io.IOException;
import java.io.PrintStream;
import java.nio.charset.StandardCharsets;
import org.perses.antlr.GrammarTestingUtility;
import org.perses.antlr.ast.PersesGrammar;
import org.perses.grammar.c.CParserFacade;
import org.perses.util.FileNameContentPair;

public class DumpPnfPassManagerLog {

  public static void main(String[] args) throws IOException {
    Preconditions.checkArgument(args.length == 1);
    final String output = args[0];

    CParserFacade facade = new CParserFacade();
    final String antlrGrammarContent =
        facade.readAntlrGrammarContent("OrigC.g4", CParserFacade.class);
    PersesGrammar grammar = GrammarTestingUtility.loadGrammarFromString(antlrGrammarContent);
    PnfPassManager manager = new PnfPassManager();
    try (PassListener listener = new PassListener(output)) {
      final FileNameContentPair lexerGrammar = null;
      manager.process(grammar, "compilationUnit", lexerGrammar, listener);
    }
  }

  private static class PassListener extends PnfPassManager.Listener implements Closeable {

    private final PrintStream stream;

    public PassListener(String file) throws IOException {
      stream = new PrintStream(file, StandardCharsets.UTF_8.name());
    }

    @Override
    public void close() {
      stream.close();
    }

    @Override
    public void start(PersesGrammar grammar, String startRuleName) {
      stream.println(grammar.getSourceCode().trim());
    }

    @Override
    public void afterPass(PersesGrammar grammar, Class<?> passClass, int iteration) {
      print(passClass, iteration);
      stream.println(grammar.getSourceCode().trim());
    }

    private void print(Class<?> passClass, int iteration) {
      stream.printf("Iteration %d, pass=%s", iteration, passClass);
    }
  }
}
