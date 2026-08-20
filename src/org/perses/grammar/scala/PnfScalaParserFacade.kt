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
package org.perses.grammar.scala

import com.google.common.primitives.ImmutableIntArray
import org.antlr.v4.runtime.CharStream
import org.antlr.v4.runtime.CommonTokenStream
import org.perses.antlr.ParseTreeWithParser
import org.perses.grammar.AbstractParserFacade
import java.io.BufferedReader
import java.io.IOException
import java.io.StringReader
import java.nio.charset.StandardCharsets
import java.nio.file.Files
import java.nio.file.Path

class PnfScalaParserFacade :
  AbstractParserFacade(
    language = LanguageScala,
    antlrGrammar =
      createCombinedAntlrGrammar(
        startRuleName = "compilationUnit",
        antlrGrammarFileName = "PnfScala.g4",
        classUnderSamePkg = PnfScalaParserFacade::class.java,
      ),
    identifierTokenTypes =
      ImmutableIntArray.of(
        PnfScalaLexer.Id,
        PnfScalaLexer.BoundVarid,
        PnfScalaLexer.Varid,
      ),
    includeAutoDetectedIdentifierTokenTypes = false,
    lexerClass = PnfScalaLexer::class.java,
    parserClass = PnfScalaParser::class.java,
  ) {
  @Throws(IOException::class)
  fun parseWithOrigScalaParser(file: Path): ParseTreeWithParser {
    Files
      .newBufferedReader(file, StandardCharsets.UTF_8)
      .use { reader -> return parseWithOrigScalaParser(reader, file.toString()) }
  }

  @Throws(IOException::class)
  fun parseWithOrigScalaParser(scalaProgram: String?): ParseTreeWithParser {
    BufferedReader(
      StringReader(scalaProgram),
    ).use { reader -> return parseWithOrigScalaParser(reader, "<in-memory>") }
  }

  @Throws(IOException::class)
  fun parseWithOrigScalaParser(
    goProgram: String?,
    fileName: String,
  ): ParseTreeWithParser {
    BufferedReader(
      StringReader(goProgram),
    ).use { reader -> return parseWithOrigScalaParser(reader, fileName) }
  }

  companion object {
    @Throws(IOException::class)
    private fun parseWithOrigScalaParser(
      reader: BufferedReader,
      fileName: String,
    ): ParseTreeWithParser =
      parseReader(
        reader,
        { charStream: CharStream? -> ScalaLexer(charStream) },
        { commonTokenStream: CommonTokenStream? -> ScalaParser(commonTokenStream) },
      ) { obj: ScalaParser -> obj.compilationUnit() }
  }
}
