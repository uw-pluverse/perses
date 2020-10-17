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
package org.perses.grammar.rust;

import org.antlr.v4.runtime.ANTLRInputStream;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.atn.ATN;
import org.antlr.v4.runtime.atn.ATNDeserializer;
import org.antlr.v4.runtime.atn.LexerATNSimulator;
import org.antlr.v4.runtime.atn.ParserATNSimulator;
import org.antlr.v4.runtime.atn.PredictionContextCache;
import org.antlr.v4.runtime.atn.PredictionMode;
import org.antlr.v4.runtime.dfa.DFA;
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
    super(
        LanguageRust.INSTANCE, createCombinedAntlrGrammar("PnfRust.g4", PnfRustParserFacade.class));
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

  public ParseTreeWithParser parseWithOrigRustParser(String rustProgram) throws IOException {
    try (BufferedReader reader = new BufferedReader(new StringReader(rustProgram))) {
      return parseWithOrigRustParser(reader, "<in-memory>");
    }
  }

  public ParseTreeWithParser parseWithOrigRustParser(String rustProgram, String fileName)
      throws IOException {
    try (BufferedReader reader = new BufferedReader(new StringReader(rustProgram))) {
      return parseWithOrigRustParser(reader, fileName);
    }
  }

  private static RustLexer createOrigSlowRustLexerWithoutCaching(ANTLRInputStream stream) {
    final RustLexer lexer = new RustLexer(stream);
    final ATN atn = new ATNDeserializer().deserialize(RustLexer._serializedATN.toCharArray());
    final DFA[] decisionToDFA = new DFA[atn.getNumberOfDecisions()];
    for (int i = 0; i < atn.getNumberOfDecisions(); i++) {
      decisionToDFA[i] = new DFA(atn.getDecisionState(i), i);
    }
    lexer.setInterpreter(
        new LexerATNSimulator(lexer, atn, decisionToDFA, new PredictionContextCache()));
    return lexer;
  }

  private static RustParser createOrigSlowRustParserWithoutCaching(TokenStream input) {
    final RustParser parser = new RustParser(input);
    final ATN atn = new ATNDeserializer().deserialize(RustParser._serializedATN.toCharArray());
    final DFA[] decisionToDFA = new DFA[atn.getNumberOfDecisions()];
    for (int i = 0; i < atn.getNumberOfDecisions(); i++) {
      decisionToDFA[i] = new DFA(atn.getDecisionState(i), i);
    }
    parser.setInterpreter(
        new ParserATNSimulator(parser, atn, decisionToDFA, new PredictionContextCache()));
    parser.getInterpreter().setPredictionMode(PredictionMode.LL);
    return parser;
  }

  private static ParseTreeWithParser parseWithOrigRustParser(BufferedReader reader, String fileName)
      throws IOException {
    return parseReader(
        fileName,
        reader,
        PnfRustParserFacade::createOrigSlowRustLexerWithoutCaching,
        PnfRustParserFacade::createOrigSlowRustParserWithoutCaching,
        RustParser::crate);
  }
}
