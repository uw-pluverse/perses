/*
 * Copyright (C) 2018-2025 University of Waterloo.
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
package org.perses.grammar.php

import com.google.common.primitives.ImmutableIntArray
import org.antlr.v4.runtime.CharStream
import org.antlr.v4.runtime.CommonTokenStream
import org.perses.antlr.ParseTreeWithParser
import org.perses.grammar.AbstractParserFacade
import java.io.StringReader

class PhpParserFacade :
  AbstractParserFacade(
    language = LanguagePhp,
    antlrGrammar =
      createSeparateAntlrGrammar(
        startRuleName = "htmlDocument",
        antlrParserGrammarFileName = "PnfPhpParser.g4",
        antlrLexerGrammarFileName = "PhpLexer.g4",
        classUnderSamePkg = PhpParserFacade::class.java,
      ),
    identifierTokenTypes = ImmutableIntArray.of(PhpLexer.VarName),
    lexerClass = PhpLexer::class.java,
    parserClass = PnfPhpParser::class.java,
  ) {
  fun parseWithOrigParser(program: String?): ParseTreeWithParser {
    StringReader(program).use { reader ->
      return parseReader(
        "<dummy-file>",
        reader,
        { charStream: CharStream? -> PhpLexer(charStream) },
        { commonTokenStream: CommonTokenStream? -> PhpParser(commonTokenStream) },
      ) { obj: PhpParser -> obj.htmlDocument() }
    }
  }
}
