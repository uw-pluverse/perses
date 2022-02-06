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
package org.perses.grammar.solidity.preprocessed;

import com.google.common.primitives.ImmutableIntArray;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.StringReader;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.tree.ParseTree;
import org.perses.antlr.ParseTreeWithParser;
import org.perses.grammar.AbstractDefaultParserFacade;
import org.perses.grammar.solidity.LanguageSolidity;

public final class PnfSolidityParserFacade
    extends AbstractDefaultParserFacade<SolidityLexer, PnfSolidityParser> {

  public PnfSolidityParserFacade() {
    super(
        LanguageSolidity.INSTANCE,
        createSeparateAntlrGrammar(
            "PnfSolidity.g4", "SolidityLexer.g4", PnfSolidityParserFacade.class),
        SolidityLexer.class,
        PnfSolidityParser.class,
        ImmutableIntArray.of(SolidityLexer.Identifier));
  }

  @Override
  protected SolidityLexer createLexer(CharStream inputStream) {
    return new SolidityLexer(inputStream);
  }

  @Override
  protected PnfSolidityParser createParser(CommonTokenStream tokens) {
    return new PnfSolidityParser(tokens);
  }

  @Override
  protected ParseTree startParsing(PnfSolidityParser parser) {
    return parser.sourceUnit();
  }

  public ParseTreeWithParser parseWithOrigSolidityParser(Path file) throws IOException {
    try (BufferedReader reader = Files.newBufferedReader(file, StandardCharsets.UTF_8)) {
      return parseWithOrigSolidityParser(reader, file.toString());
    }
  }

  public ParseTreeWithParser parseWithOrigSolidityParser(String goProgram) throws IOException {
    try (BufferedReader reader = new BufferedReader(new StringReader(goProgram))) {
      return parseWithOrigSolidityParser(reader, "<in-memory>");
    }
  }

  public ParseTreeWithParser parseWithOrigSolidityParser(String goProgram, String fileName)
      throws IOException {
    try (BufferedReader reader = new BufferedReader(new StringReader(goProgram))) {
      return parseWithOrigSolidityParser(reader, fileName);
    }
  }

  private static ParseTreeWithParser parseWithOrigSolidityParser(
      BufferedReader reader, String fileName) throws IOException {
    return parseReader(
        fileName, reader, SolidityLexer::new, SolidityParser::new, SolidityParser::sourceUnit);
  }
}
