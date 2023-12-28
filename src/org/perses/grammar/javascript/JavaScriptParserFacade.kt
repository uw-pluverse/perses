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
package org.perses.grammar.javascript

import com.google.common.primitives.ImmutableIntArray
import org.antlr.v4.runtime.CharStream
import org.antlr.v4.runtime.CommonTokenStream
import org.antlr.v4.runtime.tree.ParseTree
import org.perses.grammar.AbstractDefaultParserFacade

/** This is the facade for Java parsers  */
class JavaScriptParserFacade : AbstractDefaultParserFacade<JavaScriptLexer, PnfJavaScriptParser>(
  LanguageJavaScript,
  createSeparateAntlrGrammar(
    "PnfJavaScriptParser.g4",
    "JavaScriptLexer.g4",
    JavaScriptParserFacade::class.java,
  ),
  JavaScriptLexer::class.java,
  PnfJavaScriptParser::class.java,
  ImmutableIntArray.of(JavaScriptLexer.Identifier),
) {

  override fun createLexer(inputStream: CharStream): JavaScriptLexer {
    return JavaScriptLexer(inputStream)
  }

  override fun createParser(tokens: CommonTokenStream): PnfJavaScriptParser {
    return PnfJavaScriptParser(tokens)
  }

  override fun startParsing(parser: PnfJavaScriptParser): ParseTree {
    return parser.program()
  }
}
