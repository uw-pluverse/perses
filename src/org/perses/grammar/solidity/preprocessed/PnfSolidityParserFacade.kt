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
package org.perses.grammar.solidity.preprocessed

import com.google.common.primitives.ImmutableIntArray
import org.antlr.v4.runtime.CharStream
import org.antlr.v4.runtime.CommonTokenStream
import org.perses.antlr.ParseTreeWithParser
import org.perses.grammar.AbstractParserFacade
import org.perses.grammar.solidity.LanguageSolidity
import java.io.BufferedReader
import java.io.IOException
import java.io.StringReader
import java.nio.charset.StandardCharsets
import java.nio.file.Files
import java.nio.file.Path

class PnfSolidityParserFacade :
  AbstractParserFacade(
    language = LanguageSolidity,
    antlrGrammar =
      createSeparateAntlrGrammar(
        startRuleName = "sourceUnit",
        antlrParserGrammarFileName = "PnfSolidity.g4",
        antlrLexerGrammarFileName = "SolidityLexer.g4",
        PnfSolidityParserFacade::class.java,
      ),
    identifierTokenTypes =
      ImmutableIntArray.of(SolidityLexer.Identifier, SolidityLexer.YulIdentifier),
    includeAutoDetectedIdentifierTokenTypes = false,
    lexerClass = SolidityLexer::class.java,
    parserClass = PnfSolidityParser::class.java,
  ) {
  fun parseWithOrigSolidityParser(file: Path): ParseTreeWithParser {
    Files
      .newBufferedReader(file, StandardCharsets.UTF_8)
      .use { reader -> return parseWithOrigSolidityParser(reader, file.toString()) }
  }

  fun parseWithOrigSolidityParser(goProgram: String?): ParseTreeWithParser {
    BufferedReader(
      StringReader(goProgram),
    ).use { reader -> return parseWithOrigSolidityParser(reader, "<in-memory>") }
  }

  fun parseWithOrigSolidityParser(
    goProgram: String?,
    fileName: String,
  ): ParseTreeWithParser {
    BufferedReader(
      StringReader(goProgram),
    ).use { reader -> return parseWithOrigSolidityParser(reader, fileName) }
  }

  companion object {
    @Throws(IOException::class)
    private fun parseWithOrigSolidityParser(
      reader: BufferedReader,
      fileName: String,
    ): ParseTreeWithParser =
      parseReader(
        reader,
        { input: CharStream? -> SolidityLexer(input) },
        { input: CommonTokenStream? -> SolidityParser(input) },
      ) { obj: SolidityParser -> obj.sourceUnit() }
  }
}
