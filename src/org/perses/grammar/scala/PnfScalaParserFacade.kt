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
package org.perses.grammar.scala

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

class PnfScalaParserFacade : AbstractDefaultParserFacade<PnfScalaLexer, PnfScalaParser>(
  LanguageScala,
  createCombinedAntlrGrammar("PnfScala.g4", PnfScalaParserFacade::class.java),
  PnfScalaLexer::class.java,
  PnfScalaParser::class.java,
  ImmutableIntArray.of(PnfScalaLexer.Id, PnfScalaLexer.BoundVarid, PnfScalaLexer.Varid),
) {
  override fun createLexer(inputStream: CharStream): PnfScalaLexer {
    return PnfScalaLexer(inputStream)
  }

  override fun createParser(tokens: CommonTokenStream): PnfScalaParser {
    return PnfScalaParser(tokens)
  }

  protected override fun startParsing(parser: PnfScalaParser): ParseTree {
    return parser.compilationUnit()
  }

  @Throws(IOException::class)
  fun parseWithOrigScalaParser(file: Path): ParseTreeWithParser {
    Files.newBufferedReader(file, StandardCharsets.UTF_8)
      .use { reader -> return parseWithOrigScalaParser(reader, file.toString()) }
  }

  @Throws(IOException::class)
  fun parseWithOrigScalaParser(scalaProgram: String?): ParseTreeWithParser {
    BufferedReader(
      StringReader(scalaProgram),
    ).use { reader -> return parseWithOrigScalaParser(reader, "<in-memory>") }
  }

  @Throws(IOException::class)
  fun parseWithOrigScalaParser(goProgram: String?, fileName: String): ParseTreeWithParser {
    BufferedReader(
      StringReader(goProgram),
    ).use { reader -> return parseWithOrigScalaParser(reader, fileName) }
  }

  companion object {
    @Throws(IOException::class)
    private fun parseWithOrigScalaParser(
      reader: BufferedReader,
      fileName: String,
    ): ParseTreeWithParser {
      return parseReader(
        fileName,
        reader,
        { charStream: CharStream? -> ScalaLexer(charStream) },
        { commonTokenStream: CommonTokenStream? -> ScalaParser(commonTokenStream) },
      ) { obj: ScalaParser -> obj.compilationUnit() }
    }
  }
}
