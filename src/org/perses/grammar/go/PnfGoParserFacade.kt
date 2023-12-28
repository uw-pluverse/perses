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
package org.perses.grammar.go

import com.google.common.primitives.ImmutableIntArray
import org.antlr.v4.runtime.CharStream
import org.antlr.v4.runtime.CommonTokenStream
import org.antlr.v4.runtime.tree.ParseTree
import org.perses.antlr.ParseTreeWithParser
import org.perses.grammar.AbstractDefaultParserFacade
import java.io.BufferedReader
import java.io.IOException
import java.io.StringReader
import java.nio.charset.StandardCharsets
import java.nio.file.Files
import java.nio.file.Path

class PnfGoParserFacade : AbstractDefaultParserFacade<GoLexer, PnfGoParser>(
  LanguageGo,
  createSeparateAntlrGrammar("PnfGoParser.g4", "GoLexer.g4", PnfGoParserFacade::class.java),
  GoLexer::class.java,
  PnfGoParser::class.java,
  ImmutableIntArray.of(GoLexer.IDENTIFIER),
) {
  override fun createLexer(inputStream: CharStream): GoLexer {
    return GoLexer(inputStream)
  }

  override fun createParser(tokens: CommonTokenStream): PnfGoParser {
    return PnfGoParser(tokens)
  }

  protected override fun startParsing(parser: PnfGoParser): ParseTree {
    return parser.sourceFile()
  }

  @Throws(IOException::class)
  fun parseWithOrigGoParser(file: Path): ParseTreeWithParser {
    Files.newBufferedReader(file, StandardCharsets.UTF_8)
      .use { reader -> return parseWithOrigGoParser(reader, file.toString()) }
  }

  @Throws(IOException::class)
  fun parseWithOrigGoParser(goProgram: String?): ParseTreeWithParser {
    BufferedReader(
      StringReader(goProgram),
    ).use { reader -> return parseWithOrigGoParser(reader, "<in-memory>") }
  }

  @Throws(IOException::class)
  fun parseWithOrigGoParser(goProgram: String?, fileName: String): ParseTreeWithParser {
    BufferedReader(
      StringReader(goProgram),
    ).use { reader -> return parseWithOrigGoParser(reader, fileName) }
  }

  companion object {
    @Throws(IOException::class)
    private fun parseWithOrigGoParser(
      reader: BufferedReader,
      fileName: String,
    ): ParseTreeWithParser {
      return parseReader(
        fileName,
        reader,
        { input: CharStream? -> GoLexer(input) },
        { input: CommonTokenStream? -> GoParser(input) },
      ) { obj: GoParser -> obj.sourceFile() }
    }
  }
}
