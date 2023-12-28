/*
 * Copyright (C) 2018-2024 University of Waterloo.
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
package org.perses.grammar.sysverilog

import com.google.common.primitives.ImmutableIntArray
import org.antlr.v4.runtime.CharStream
import org.antlr.v4.runtime.CommonTokenStream
import org.antlr.v4.runtime.tree.ParseTree
import org.perses.grammar.AbstractDefaultParserFacade

class PnfSysverilogParserFacade : AbstractDefaultParserFacade<SV3_1aLexer, PnfSysVerilogHDL>(
  LanguageSystemVerilog,
  createSeparateAntlrGrammar(
    "PnfSysVerilogHDL.g4",
    "SV3_1aLexer.g4",
    PnfSysverilogParserFacade::class.java,
  ),
  SV3_1aLexer::class.java,
  PnfSysVerilogHDL::class.java,
  ImmutableIntArray.of(SV3_1aLexer.Escaped_identifier, SV3_1aLexer.Simple_identifier),
) {
  override fun createLexer(inputStream: CharStream): SV3_1aLexer {
    return SV3_1aLexer(inputStream)
  }

  override fun createParser(tokens: CommonTokenStream): PnfSysVerilogHDL {
    return PnfSysVerilogHDL(tokens)
  }

  protected override fun startParsing(parser: PnfSysVerilogHDL): ParseTree {
    return parser.source_text()
  }
}
