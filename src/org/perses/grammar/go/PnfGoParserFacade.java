package org.perses.grammar.go;

import org.antlr.v4.runtime.ANTLRInputStream;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.tree.ParseTree;
import org.perses.antlr.ParseTreeWithParser;
import org.perses.grammar.AbstractDefaultParserFacade;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.StringReader;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;

public final class PnfGoParserFacade extends AbstractDefaultParserFacade<GoLexer, PnfGoParser> {

  public PnfGoParserFacade() {
    super(createSeparateAntlrGrammar("PnfGoParser.g4", "GoLexer.g4", PnfGoParserFacade.class));
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

  public ParseTreeWithParser parseWithOrigGoParser(File file) throws IOException {
    try (BufferedReader reader = Files.newBufferedReader(file.toPath(), StandardCharsets.UTF_8)) {
      return parseWithOrigGoParser(reader, file.getPath());
    }
  }

  public ParseTreeWithParser parseWithOrigGoParser(String goProgram) throws IOException {
    try (BufferedReader reader = new BufferedReader(new StringReader(goProgram))) {
      return parseWithOrigGoParser(reader, "<in-memory>");
    }
  }

  private static ParseTreeWithParser parseWithOrigGoParser(BufferedReader reader, String fileName)
      throws IOException {
    return parseReader(
        fileName,
        reader,
        antlrInputStream -> new GoLexer(antlrInputStream),
        commonTokenStream -> new GoParser(commonTokenStream),
        GoParser::sourceFile);
  }
}
