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
package org.perses.grammar

import com.google.common.collect.ImmutableList
import com.google.common.primitives.ImmutableIntArray
import org.antlr.v4.runtime.CharStream
import org.antlr.v4.runtime.CharStreams
import org.antlr.v4.runtime.CommonTokenStream
import org.antlr.v4.runtime.DefaultErrorStrategy
import org.antlr.v4.runtime.Lexer
import org.antlr.v4.runtime.Parser
import org.antlr.v4.runtime.Token
import org.antlr.v4.runtime.atn.LexerATNSimulator
import org.antlr.v4.runtime.atn.ParserATNSimulator
import org.antlr.v4.runtime.atn.PredictionContextCache
import org.antlr.v4.runtime.atn.PredictionMode
import org.antlr.v4.runtime.tree.ParseTree
import org.perses.antlr.AbstractAntlrGrammar
import org.perses.antlr.ParseTreeWithParser
import org.perses.program.LanguageKind
import java.io.Reader
import java.util.function.Function

abstract class AbstractDefaultParserFacade<LEXER : Lexer, PARSER : Parser>
protected constructor(
  languageKind: LanguageKind,
  grammar: AbstractAntlrGrammar,
  lexerClass: Class<LEXER>,
  parserClass: Class<PARSER>,
  identifierTokenTypes: ImmutableIntArray,
) : AbstractParserFacade(languageKind, grammar, identifierTokenTypes, lexerClass, parserClass) {

  protected abstract fun createLexer(inputStream: CharStream): LEXER
  private fun createLexerWithoutCache(inputStream: CharStream): LEXER {
    val lexer = createLexer(inputStream)
    disableGlobalCachingIfInstructed(lexer)
    return lexer
  }

  protected abstract fun createParser(tokens: CommonTokenStream): PARSER
  private fun createParserWithoutCache(tokens: CommonTokenStream): PARSER {
    val parser = createParser(tokens)
    disableGlobalCachingIfInstructed(parser)
    return parser
  }

  protected abstract fun startParsing(parser: PARSER): ParseTree

  override fun parseReader(fileName: String, reader: Reader): ParseTreeWithParser {
    return parseReader(
      fileName,
      reader,
      { inputStream: CharStream -> createLexerWithoutCache(inputStream) },
      { tokens: CommonTokenStream -> createParserWithoutCache(tokens) },
    ) { parser: PARSER -> startParsing(parser) }
  }

  override fun transformLiteralIntoSingleToken(literal: String): Token {
    val lexer = createLexerWithoutCache(CharStreams.fromString(literal))
    val result = lexer.nextToken()
    val next = lexer.nextToken()
    check(next.type == Token.EOF) { next }
    return result
  }

  override fun tokenize(fileName: String, reader: Reader): ImmutableList<Token> {
    val lexer: Lexer = createLexerWithoutCache(CharStreams.fromReader(reader))
    val builder = ImmutableList.builder<Token>()
    var token: Token = lexer.nextToken()
    while (token.type != Token.EOF) {
      if (token.channel == Token.DEFAULT_CHANNEL) {
        builder.add(token)
      }
      token = lexer.nextToken()
    }
    return builder.build()
  }

  companion object {
    private const val DISABLE_GLOBAL_CACHING_FOR_BETTER_MEMORY_THO_AFFECT_EFFICIENCY = true

    @JvmStatic
    fun <LEXER : Lexer> disableGlobalCachingIfInstructed(lexer: LEXER): LEXER {
      if (DISABLE_GLOBAL_CACHING_FOR_BETTER_MEMORY_THO_AFFECT_EFFICIENCY) {
        lexer.interpreter = LexerATNSimulator(
          lexer,
          lexer.atn,
          lexer.interpreter.decisionToDFA,
          PredictionContextCache(),
        )
      }
      return lexer
    }

    @JvmStatic
    fun <PARSER : Parser> disableGlobalCachingIfInstructed(parser: PARSER): PARSER {
      if (DISABLE_GLOBAL_CACHING_FOR_BETTER_MEMORY_THO_AFFECT_EFFICIENCY) {
        // The following code is from.
        // https://github.com/antlr/antlr4/issues/499#issuecomment-38159752
        parser.interpreter = ParserATNSimulator(
          parser,
          parser.atn,
          parser.interpreter.decisionToDFA,
          PredictionContextCache(),
        )
        parser.interpreter.predictionMode = PredictionMode.LL
      }
      return parser
    }

    @JvmStatic
    fun <L : Lexer, P : Parser> parseReader(
      fileName: String,
      reader: Reader,
      lexerCreator: Function<CharStream, L>,
      parserCreator: Function<CommonTokenStream, P>,
      parseFunction: Function<P, ParseTree>,
    ): ParseTreeWithParser {
      val listener = FailOnErrorAntlrErrorListener(fileName)
      val lexer = lexerCreator.apply(CharStreams.fromReader(reader))
      lexer.removeErrorListeners()
      lexer.addErrorListener(listener)
      val tokens = CommonTokenStream(lexer)
      val parser = parserCreator.apply(tokens)
      if (DISABLE_GLOBAL_CACHING_FOR_BETTER_MEMORY_THO_AFFECT_EFFICIENCY) {
        parser.interpreter = ParserATNSimulator(
          parser,
          parser.atn,
          parser.interpreter.decisionToDFA,
          PredictionContextCache(),
        )
      }
      parser.removeErrorListeners()
      parser.errorHandler = DefaultErrorStrategy()
      parser.addErrorListener(listener)
      val tree = parseFunction.apply(parser)
      lexer.interpreter.clearDFA()
      lexer.interpreter.reset()
      parser.interpreter.clearDFA()
      parser.interpreter.reset()
      return ParseTreeWithParser(tree, parser, lexer)
    }
  }
}
