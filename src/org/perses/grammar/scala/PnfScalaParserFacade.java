package org.perses.grammar.scala;

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

public final class PnfScalaParserFacade
    extends AbstractDefaultParserFacade<PnfScalaLexer, PnfScalaParser> {

  public PnfScalaParserFacade() {
    super(createCombinedAntlrGrammar("PnfScala.g4", PnfScalaParserFacade.class));
  }

  @Override
  protected PnfScalaLexer createLexer(ANTLRInputStream inputStream) {
    return new PnfScalaLexer(inputStream);
  }

  @Override
  protected PnfScalaParser createParser(CommonTokenStream tokens) {
    return new PnfScalaParser(tokens);
  }

  @Override
  protected ParseTree startParsing(PnfScalaParser parser) {
    return parser.compilationUnit();
  }

  public ParseTreeWithParser parseWithOrigScalaParser(File file) throws IOException {
    try (BufferedReader reader = Files.newBufferedReader(file.toPath(), StandardCharsets.UTF_8)) {
      return parseWithOrigScalaParser(reader, file.getPath());
    }
  }

  public ParseTreeWithParser parseWithOrigScalaParser(String scalaProgram) throws IOException {
    try (BufferedReader reader = new BufferedReader(new StringReader(scalaProgram))) {
      return parseWithOrigScalaParser(reader, "<in-memory>");
    }
  }

  public ParseTreeWithParser parseWithOrigScalaParser(String goProgram, String fileName)
      throws IOException {
    try (BufferedReader reader = new BufferedReader(new StringReader(goProgram))) {
      return parseWithOrigScalaParser(reader, fileName);
    }
  }

  private static ParseTreeWithParser parseWithOrigScalaParser(
      BufferedReader reader, String fileName) throws IOException {
    return parseReader(
        fileName,
        reader,
        antlrInputStream -> new ScalaLexer(antlrInputStream),
        commonTokenStream -> new ScalaParser(commonTokenStream),
        ScalaParser::compilationUnit);
  }
}
