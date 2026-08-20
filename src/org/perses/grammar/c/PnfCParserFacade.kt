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

class PnfCParserFacade :
  AbstractParserFacade(
    language = LanguageC,
    antlrGrammar =
      createCombinedAntlrGrammar(
        // compilationUnit, not translationUnit: only compilationUnit anchors the parse to EOF
        // (`translationUnit? EOF`), so trailing input the grammar cannot consume -- e.g. a
        // preprocessing directive after the last declaration -- is a parse error instead of being
        // silently ignored. translationUnit alone accepts any valid prefix and drops the rest.
        startRuleName = "compilationUnit",
        antlrGrammarFileName = "PnfC.g4",
        PnfCParserFacade::class.java,
      ),
    identifierTokenTypes = ImmutableIntArray.of(PnfCLexer.Identifier),
    includeAutoDetectedIdentifierTokenTypes = false,
    lexerClass = PnfCLexer::class.java,
    parserClass = PnfCParser::class.java,
  )
