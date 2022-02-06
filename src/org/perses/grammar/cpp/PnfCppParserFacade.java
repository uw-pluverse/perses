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
package org.perses.grammar.cpp;

import com.google.common.primitives.ImmutableIntArray;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.tree.ParseTree;
import org.perses.grammar.AbstractDefaultParserFacade;

public final class PnfCppParserFacade
    extends AbstractDefaultParserFacade<CPP14Lexer, PnfCPP14Parser> {

  public PnfCppParserFacade() {
    super(
        LanguageCpp.INSTANCE,
        createSeparateAntlrGrammar("PnfCPP14Parser.g4", "CPP14Lexer.g4", PnfCppParserFacade.class),
        CPP14Lexer.class,
        PnfCPP14Parser.class,
        ImmutableIntArray.of(CPP14Lexer.Identifier));
  }

  @Override
  protected CPP14Lexer createLexer(CharStream inputStream) {
    return new CPP14Lexer(inputStream);
  }

  @Override
  protected PnfCPP14Parser createParser(CommonTokenStream tokens) {
    return new PnfCPP14Parser(tokens);
  }

  @Override
  protected ParseTree startParsing(PnfCPP14Parser parser) {
    return parser.translationUnit();
  }
}
