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
package org.perses.grammar.smtlibv2;

import com.google.common.primitives.ImmutableIntArray;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.tree.ParseTree;
import org.perses.grammar.AbstractDefaultParserFacade;

public final class SmtLibV2ParserFacade
    extends AbstractDefaultParserFacade<PnfSMTLIBv2Lexer, PnfSMTLIBv2Parser> {

  public SmtLibV2ParserFacade() {
    super(
        LanguageSmtLibV2.INSTANCE,
        createCombinedAntlrGrammar("PnfSMTLIBv2.g4", SmtLibV2ParserFacade.class),
        PnfSMTLIBv2Lexer.class,
        PnfSMTLIBv2Parser.class,
        ImmutableIntArray.of(PnfSMTLIBv2Lexer.UndefinedSymbol));
  }

  @Override
  protected PnfSMTLIBv2Lexer createLexer(CharStream inputStream) {
    return new PnfSMTLIBv2Lexer(inputStream);
  }

  @Override
  protected PnfSMTLIBv2Parser createParser(CommonTokenStream tokens) {
    return new PnfSMTLIBv2Parser(tokens);
  }

  @Override
  protected ParseTree startParsing(PnfSMTLIBv2Parser parser) {
    return parser.start();
  }
}
