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
package org.perses.grammar.sysverilog;

import com.google.common.primitives.ImmutableIntArray;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.tree.ParseTree;
import org.perses.grammar.AbstractDefaultParserFacade;

public final class PnfSysverilogParserFacade
    extends AbstractDefaultParserFacade<SV3_1aLexer, PnfSysVerilogHDL> {

  public PnfSysverilogParserFacade() {
    super(
        LanguageSystemVerilog.INSTANCE,
        createSeparateAntlrGrammar(
            "PnfSysVerilogHDL.g4", "SV3_1aLexer.g4", PnfSysverilogParserFacade.class),
        SV3_1aLexer.class,
        PnfSysVerilogHDL.class,
        ImmutableIntArray.of(SV3_1aLexer.Escaped_identifier, SV3_1aLexer.Simple_identifier));
  }

  @Override
  protected SV3_1aLexer createLexer(CharStream inputStream) {
    return new SV3_1aLexer(inputStream);
  }

  @Override
  protected PnfSysVerilogHDL createParser(CommonTokenStream tokens) {
    return new PnfSysVerilogHDL(tokens);
  }

  @Override
  protected ParseTree startParsing(PnfSysVerilogHDL parser) {
    return parser.source_text();
  }
}
