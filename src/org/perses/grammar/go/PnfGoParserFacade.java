package org.perses.grammar.go;

import org.antlr.v4.runtime.ANTLRInputStream;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.tree.ParseTree;
import org.perses.grammar.AbstractDefaultParserFacade;

public final class PnfGoParserFacade extends AbstractDefaultParserFacade<GoLexer, PnfGoParser> {

  public PnfGoParserFacade() {
    super("PnfGoParser.g4");
  }

  @Override
  protected GoLexer createLexer(ANTLRInputStream inputStream) {
    return new GoLexer(inputStream);
  }

  @Override
  protected PnfGoParser createParser(CommonTokenStream tokens) {
    return new PnfGoParser(tokens);
  }

  @Override
  protected ParseTree startParsing(PnfGoParser parser) {
    return parser.sourceFile();
  }
}
