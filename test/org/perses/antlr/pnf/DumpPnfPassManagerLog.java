package org.perses.antlr.pnf;

import com.google.common.base.Preconditions;
import org.perses.antlr.GrammarTestingUtility;
import org.perses.antlr.ast.PersesGrammar;
import org.perses.grammar.c.CParserFacade;

import java.io.Closeable;
import java.io.IOException;
import java.io.PrintStream;
import java.nio.charset.StandardCharsets;

public class DumpPnfPassManagerLog {

  public static void main(String[] args) throws IOException {
    Preconditions.checkArgument(args.length == 1);
    final String output = args[0];

    CParserFacade facade = new CParserFacade();
    final String antlrGrammarContent = facade.readAntlrGrammarContent("OrigC.g4");
    PersesGrammar grammar = GrammarTestingUtility.loadGrammarFromString(antlrGrammarContent);
    PnfPassManager manager = new PnfPassManager();
    try (PassListener listener = new PassListener(output)) {
      manager.process(grammar, "compilationUnit", listener);
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
    protected void start(PersesGrammar grammar, String startRuleName) {
      stream.println(grammar.getSourceCode().trim());
    }

    @Override
    protected void afterPass(ImmutableRuleDefMap grammar, Class<?> passClass, int iteration) {
      print(passClass, iteration);
      stream.println(grammar.getPersesGrammar().getSourceCode().trim());
    }

    private void print(Class<?> passClass, int iteration) {
      stream.printf("Iteration %d, pass=%s", iteration, passClass);
    }
  }
}
