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
package org.perses.grammar.solidity.preprocessed

import com.google.common.primitives.ImmutableIntArray
import org.antlr.v4.runtime.CharStream
import org.antlr.v4.runtime.CommonTokenStream
import org.antlr.v4.runtime.tree.ParseTree
import org.perses.antlr.ParseTreeWithParser
import org.perses.grammar.AbstractDefaultParserFacade
import org.perses.grammar.solidity.LanguageSolidity
import java.io.BufferedReader
import java.io.IOException
import java.io.StringReader
import java.nio.charset.StandardCharsets
import java.nio.file.Files
import java.nio.file.Path

class PnfSolidityParserFacade : AbstractDefaultParserFacade<SolidityLexer, PnfSolidityParser>(
  LanguageSolidity,
  createSeparateAntlrGrammar(
    "PnfSolidity.g4",
    "SolidityLexer.g4",
    PnfSolidityParserFacade::class.java,
  ),
  SolidityLexer::class.java,
  PnfSolidityParser::class.java,
  ImmutableIntArray.of(SolidityLexer.Identifier),
) {
  override fun createLexer(inputStream: CharStream): SolidityLexer {
    return SolidityLexer(inputStream)
  }

  override fun createParser(tokens: CommonTokenStream): PnfSolidityParser {
    return PnfSolidityParser(tokens)
  }

  protected override fun startParsing(parser: PnfSolidityParser): ParseTree {
    return parser.sourceUnit()
  }

  @Throws(IOException::class)
  fun parseWithOrigSolidityParser(file: Path): ParseTreeWithParser {
    Files.newBufferedReader(file, StandardCharsets.UTF_8)
      .use { reader -> return parseWithOrigSolidityParser(reader, file.toString()) }
  }

  @Throws(IOException::class)
  fun parseWithOrigSolidityParser(goProgram: String?): ParseTreeWithParser {
    BufferedReader(
      StringReader(goProgram),
    ).use { reader -> return parseWithOrigSolidityParser(reader, "<in-memory>") }
  }

  @Throws(IOException::class)
  fun parseWithOrigSolidityParser(goProgram: String?, fileName: String): ParseTreeWithParser {
    BufferedReader(
      StringReader(goProgram),
    ).use { reader -> return parseWithOrigSolidityParser(reader, fileName) }
  }

  companion object {
    @Throws(IOException::class)
    private fun parseWithOrigSolidityParser(
      reader: BufferedReader,
      fileName: String,
    ): ParseTreeWithParser {
      return parseReader(
        fileName,
        reader,
        { input: CharStream? -> SolidityLexer(input) },
        { input: CommonTokenStream? -> SolidityParser(input) },
      ) { obj: SolidityParser -> obj.sourceUnit() }
    }
  }
}
