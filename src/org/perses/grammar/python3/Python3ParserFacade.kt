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
package org.perses.grammar.python3

import com.google.common.primitives.ImmutableIntArray
import org.antlr.v4.runtime.CharStream
import org.antlr.v4.runtime.CommonTokenStream
import org.perses.antlr.ParseTreeWithParser
import org.perses.grammar.AbstractParserFacade
import java.io.StringReader

class Python3ParserFacade :
  AbstractParserFacade(
    language = LanguagePython3,
    antlrGrammar =
      createSeparateAntlrGrammar(
        startRuleName = "file_input",
        antlrParserGrammarFileName = "PnfPython3Parser.g4",
        antlrLexerGrammarFileName = "Python3Lexer.g4",
        Python3ParserFacade::class.java,
      ),
    identifierTokenTypes = ImmutableIntArray.of(Python3Lexer.NAME),
    lexerClass = Python3Lexer::class.java,
    parserClass = PnfPython3Parser::class.java,
  ) {
  fun parseWithOrigParser(program: String?): ParseTreeWithParser {
    StringReader(program).use { reader ->
      return parseReader(
        "<dummy-file>",
        reader,
        { charStream: CharStream? -> Python3Lexer(charStream) },
        { commonTokenStream: CommonTokenStream? -> PnfPython3Parser(commonTokenStream) },
      ) { obj -> obj.file_input() }
    }
  }
}
