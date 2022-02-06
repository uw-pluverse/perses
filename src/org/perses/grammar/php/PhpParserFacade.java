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
package org.perses.grammar.php;

import com.google.common.primitives.ImmutableIntArray;
import java.io.IOException;
import java.io.StringReader;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.tree.ParseTree;
import org.perses.antlr.ParseTreeWithParser;
import org.perses.grammar.AbstractDefaultParserFacade;

public final class PhpParserFacade extends AbstractDefaultParserFacade<PhpLexer, PnfPhpParser> {

  public PhpParserFacade() {
    super(
        LanguagePhp.INSTANCE,
        createSeparateAntlrGrammar("PnfPhpParser.g4", "PhpLexer.g4", PhpParserFacade.class),
        PhpLexer.class,
        PnfPhpParser.class,
        ImmutableIntArray.of(PhpLexer.VarName));
  }

  @Override
  protected PhpLexer createLexer(CharStream inputStream) {
    return new PhpLexer(inputStream);
  }

  @Override
  protected PnfPhpParser createParser(CommonTokenStream tokens) {
    return new PnfPhpParser(tokens);
  }

  @Override
  protected ParseTree startParsing(PnfPhpParser parser) {
    return parser.htmlDocument();
  }

  public ParseTreeWithParser parseWithOrigParser(String program) throws IOException {
    try (StringReader reader = new StringReader(program)) {
      return parseReader(
          "<dummy-file>",
          reader,
          charStream -> new PhpLexer(charStream),
          commonTokenStream -> new PhpParser(commonTokenStream),
          PhpParser::htmlDocument);
    }
  }
}
