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
package org.perses.grammar.php

import com.google.common.primitives.ImmutableIntArray
import org.antlr.v4.runtime.CharStream
import org.antlr.v4.runtime.CommonTokenStream
import org.antlr.v4.runtime.tree.ParseTree
import org.perses.antlr.ParseTreeWithParser
import org.perses.grammar.AbstractDefaultParserFacade
import java.io.StringReader

class PhpParserFacade : AbstractDefaultParserFacade<PhpLexer, PnfPhpParser>(
  LanguagePhp,
  createSeparateAntlrGrammar("PnfPhpParser.g4", "PhpLexer.g4", PhpParserFacade::class.java),
  PhpLexer::class.java,
  PnfPhpParser::class.java,
  ImmutableIntArray.of(PhpLexer.VarName),
) {
  override fun createLexer(inputStream: CharStream): PhpLexer {
    return PhpLexer(inputStream)
  }

  override fun createParser(tokens: CommonTokenStream): PnfPhpParser {
    return PnfPhpParser(tokens)
  }

  protected override fun startParsing(parser: PnfPhpParser): ParseTree {
    return parser.htmlDocument()
  }

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
