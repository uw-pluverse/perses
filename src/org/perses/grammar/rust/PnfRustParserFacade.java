package org.perses.grammar.rust;

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

public final class PnfRustParserFacade
    extends AbstractDefaultParserFacade<PnfRustLexer, PnfRustParser> {

  public PnfRustParserFacade() {
    super(createCombinedAntlrGrammar("PnfRust.g4", PnfRustParserFacade.class));
  }

  @Override
  protected PnfRustLexer createLexer(ANTLRInputStream inputStream) {
    return new PnfRustLexer(inputStream);
  }

  @Override
  protected PnfRustParser createParser(CommonTokenStream tokens) {
    return new PnfRustParser(tokens);
  }

  @Override
  protected ParseTree startParsing(PnfRustParser parser) {
    return parser.crate();
  }

  public ParseTreeWithParser parseWithOrigRustParser(File file) throws IOException {
    try (BufferedReader reader = Files.newBufferedReader(file.toPath(), StandardCharsets.UTF_8)) {
      return parseWithOrigRustParser(reader, file.getPath());
    }
  }

  public ParseTreeWithParser parseWithOrigRustParser(String RustProgram) throws IOException {
    try (BufferedReader reader = new BufferedReader(new StringReader(RustProgram))) {
      return parseWithOrigRustParser(reader, "<in-memory>");
    }
  }

  public ParseTreeWithParser parseWithOrigRustParser(String goProgram, String fileName)
      throws IOException {
    try (BufferedReader reader = new BufferedReader(new StringReader(goProgram))) {
      return parseWithOrigRustParser(reader, fileName);
    }
  }

  private static ParseTreeWithParser parseWithOrigRustParser(
      BufferedReader reader, String fileName) throws IOException {
    return parseReader(
        fileName,
        reader,
        antlrInputStream -> new RustLexer(antlrInputStream),
        commonTokenStream -> new RustParser(commonTokenStream),
        RustParser::crate);
  }
}
