/*
 * Copyright (C) 2018-2026 University of Waterloo.
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
import org.perses.grammar.AbstractParserFacade

class PnfSysverilogParserFacade :
  AbstractParserFacade(
    language = LanguageSystemVerilog,
    antlrGrammar =
      createSeparateAntlrGrammar(
        startRuleName = "source_text",
        antlrParserGrammarFileName = "PnfSysVerilogHDL.g4",
        antlrLexerGrammarFileName = "SV3_1aLexer.g4",
        classUnderSamePkg = PnfSysverilogParserFacade::class.java,
      ),
    identifierTokenTypes =
      ImmutableIntArray.of(
        SV3_1aLexer.Escaped_identifier,
        SV3_1aLexer.Simple_identifier,
      ),
    includeAutoDetectedIdentifierTokenTypes = false,
    lexerClass = SV3_1aLexer::class.java,
    parserClass = PnfSysVerilogHDL::class.java,
  )
