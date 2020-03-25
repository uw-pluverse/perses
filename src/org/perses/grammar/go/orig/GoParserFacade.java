package org.perses.grammar.go.orig;

import org.antlr.v4.runtime.ANTLRInputStream;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.tree.ParseTree;
import org.perses.grammar.AbstractDefaultParserFacade;

public final class GoParserFacade extends AbstractDefaultParserFacade<GoLexer, GoParser> {

  public GoParserFacade() {
    super(createSeparateAntlrGrammar("GoParser.g4", "GoLexer.g4", GoParserFacade.class));
  }

  @Override
  protected GoLexer createLexer(ANTLRInputStream inputStream) {
    return new GoLexer(inputStream);
  }

  @Override
  protected GoParser createParser(CommonTokenStream tokens) {
    return new GoParser(tokens);
  }

  @Override
  protected ParseTree startParsing(GoParser parser) {
    return parser.sourceFile();
  }
}
