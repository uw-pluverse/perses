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
package org.perses.grammar.python3;

import com.google.common.primitives.ImmutableIntArray;
import java.io.IOException;
import java.io.StringReader;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.tree.ParseTree;
import org.perses.antlr.ParseTreeWithParser;
import org.perses.grammar.AbstractDefaultParserFacade;

public final class Python3ParserFacade
    extends AbstractDefaultParserFacade<Python3Lexer, PnfPython3Parser> {

  public Python3ParserFacade() {
    super(
        LanguagePython3.INSTANCE,
        createSeparateAntlrGrammar(
            "PnfPython3Parser.g4", "Python3Lexer.g4", Python3ParserFacade.class),
        Python3Lexer.class,
        PnfPython3Parser.class,
        ImmutableIntArray.of(Python3Lexer.NAME));
  }

  @Override
  protected Python3Lexer createLexer(CharStream inputStream) {
    return new Python3Lexer(inputStream);
  }

  @Override
  protected PnfPython3Parser createParser(CommonTokenStream tokens) {
    return new PnfPython3Parser(tokens);
  }

  @Override
  protected ParseTree startParsing(PnfPython3Parser parser) {
    return parser.file_input();
  }

  public ParseTreeWithParser parseWithOrigParser(String program) throws IOException {
    try (StringReader reader = new StringReader(program)) {
      return parseReader(
          "<dummy-file>",
          reader,
          charStream -> new Python3Lexer(charStream),
          commonTokenStream -> new PnfPython3Parser(commonTokenStream),
          PnfPython3Parser::file_input);
    }
  }
}
