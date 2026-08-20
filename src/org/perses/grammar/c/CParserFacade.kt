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
package org.perses.grammar.c

import com.google.common.primitives.ImmutableIntArray
import org.perses.grammar.AbstractParserFacade

/** This C parser facade is kept for testing only. */
class CParserFacade :
  AbstractParserFacade(
    language = LanguageC,
    antlrGrammar =
      createCombinedAntlrGrammar(
        startRuleName = "translationUnit",
        antlrGrammarFileName = "implicit_token_outlined_dir/OptC.g4",
        CParserFacade::class.java,
      ),
    identifierTokenTypes = ImmutableIntArray.of(OptCLexer.Identifier),
    includeAutoDetectedIdentifierTokenTypes = false,
    lexerClass = OptCLexer::class.java,
    parserClass = OptCParser::class.java,
  )
