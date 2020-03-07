package org.perses.grammar.c;

import org.antlr.v4.runtime.ANTLRInputStream;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.tree.ParseTree;
import org.perses.grammar.AbstractDefaultParserFacade;

public final class PnfCParserFacade extends AbstractDefaultParserFacade<PnfCLexer, PnfCParser> {

  public PnfCParserFacade() {
    super(createCombinedAntlrGrammar("PnfC.g4", PnfCParserFacade.class));
  }

  @Override
  protected PnfCLexer createLexer(ANTLRInputStream inputStream) {
    return new PnfCLexer(inputStream);
  }

  @Override
  protected PnfCParser createParser(CommonTokenStream tokens) {
    return new PnfCParser(tokens);
  }

  @Override
  protected ParseTree startParsing(PnfCParser parser) {
    return parser.translationUnit();
  }
}
