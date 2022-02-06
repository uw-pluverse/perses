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
package org.perses.grammar.c;

import com.google.common.flogger.FluentLogger;
import com.google.common.primitives.ImmutableIntArray;
import java.io.BufferedReader;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.tree.ParseTree;
import org.perses.antlr.ParseTreeWithParser;
import org.perses.grammar.AbstractDefaultParserFacade;

/** This is the facade for C parsers. TODO: clean up this class. */
public final class CParserFacade extends AbstractDefaultParserFacade<OptCLexer, OptCParser> {

  private static final FluentLogger logger = FluentLogger.forEnclosingClass();

  public CParserFacade() {
    super(
        LanguageC.INSTANCE,
        createCombinedAntlrGrammar("OptC.g4", CParserFacade.class),
        OptCLexer.class,
        OptCParser.class,
        ImmutableIntArray.of(OptCLexer.Identifier));
  }

  @Override
  protected OptCLexer createLexer(CharStream inputStream) {
    return new OptCLexer(inputStream);
  }

  @Override
  protected OptCParser createParser(CommonTokenStream tokens) {
    return new OptCParser(tokens);
  }

  @Override
  protected ParseTree startParsing(OptCParser parser) {
    return parser.translationUnit();
  }

  public ParseTreeWithParser parseWithOrigCParser(Path file) throws IOException {
    logger.atFine().log("Parsing file with %s", OrigCParser.class);
    try (BufferedReader reader = Files.newBufferedReader(file, StandardCharsets.UTF_8)) {
      return parseReader(
          file.toString(),
          reader,
          charStream -> new OrigCLexer(charStream),
          commonTokenStream -> new OrigCParser(commonTokenStream),
          OrigCParser::translationUnit);
    }
  }
}
