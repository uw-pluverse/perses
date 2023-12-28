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
import com.google.common.flogger.FluentLogger
import com.google.common.io.ByteStreams
import com.google.common.primitives.ImmutableIntArray
import org.antlr.v4.runtime.Lexer
import org.antlr.v4.runtime.Parser
import org.antlr.v4.runtime.Token
import org.antlr.v4.runtime.Token.DEFAULT_CHANNEL
import org.antlr.v4.runtime.tree.ParseTree
import org.antlr.v4.runtime.tree.TerminalNode
import org.perses.antlr.AbstractAntlrGrammar
import org.perses.antlr.GrammarHierarchy.Companion.createFromAntlrGrammar
import org.perses.antlr.MetaTokenInfoDB
import org.perses.antlr.ParseTreeWithParser
import org.perses.antlr.ast.PersesAstBuilder.Companion.loadGrammarFromString
import org.perses.antlr.atn.LexerAtnWrapper
import org.perses.antlr.toTokenType
import org.perses.program.LanguageKind
import org.perses.util.Util
import org.perses.util.Util.lazyAssert
import org.perses.util.transformToImmutableList
import java.io.IOException
import java.io.Reader
import java.io.StringReader
import java.io.UncheckedIOException
import java.nio.charset.StandardCharsets
import java.nio.file.Files
import java.nio.file.Path
import java.util.ArrayDeque

/** The base class for the parser facade  */
abstract class AbstractParserFacade protected constructor(
  val language: LanguageKind,
  val antlrGrammar: AbstractAntlrGrammar,
  identifierTokenTypes: ImmutableIntArray,
  val lexerClass: Class<out Lexer>,
  val parserClass: Class<out Parser>,
) {

  val ruleHierarchy = createFromAntlrGrammar(antlrGrammar)

  val identifierTokenTypes = identifierTokenTypes
    .toArray().asSequence().transformToImmutableList { it.toTokenType() }

  val metaTokenInfoDb: MetaTokenInfoDB
    get() = lexerAtnWrapper.metaTokenInfoDB

  val lexerAtnWrapper: LexerAtnWrapper<out Lexer> by lazy {
    LexerAtnWrapper(lexerClass)
  }
  init {
    require(identifierTokenTypes.toArray().distinct().size == identifierTokenTypes.length()) {
      "The identifier token types have duplicate elements: $identifierTokenTypes"
    }
  }

  fun parseFile(file: Path): ParseTreeWithParser {
    Files.newBufferedReader(file, StandardCharsets.UTF_8).use {
      return parseReader(file.toString(), it)
    }
  }

  fun parseIntoTokens(
    file: Path,
  ): ImmutableList<Token> {
    Files.newBufferedReader(file, StandardCharsets.UTF_8).use {
      return tokenize(file.toString(), it).also { tokens ->
        lazyAssert({ tokens.map { it.channel }.distinct().single() == DEFAULT_CHANNEL }) {
          tokens.joinToString()
        }
      }
    }
  }

  abstract fun transformLiteralIntoSingleToken(literal: String): Token

  fun parseString(string: String, filename: String = "<in memory>"): ParseTreeWithParser {
    val reader = StringReader(string)
    return parseReader(filename, reader)
  }

  fun isSourceCodeParsable(sourceCode: String): Boolean {
    return try {
      parseString(sourceCode)
      true
    } catch (e: Exception) {
      logger.atFine().withCause(e).log("The input source is not parsable.")
      false
    }
  }

  protected abstract fun parseReader(fileName: String, reader: Reader): ParseTreeWithParser
  protected abstract fun tokenize(fileName: String, reader: Reader): ImmutableList<Token>

  companion object {
    fun getTokens(tree: ParseTree): ImmutableList<Token> {
      val builder = ImmutableList.builderWithExpectedSize<Token>(500)
      val stack = ArrayDeque<ParseTree>()
      stack.push(tree)
      while (stack.size > 0) {
        val current = stack.pop()
        if (current is TerminalNode) {
          builder.add(current.symbol)
          continue
        }
        for (i in current.childCount - 1 downTo 0) {
          stack.push(current.getChild(i))
        }
      }
      return builder.build()
    }

    @JvmStatic
    fun readAntlrGrammarContent(
      antlrGrammarFileName: String,
      classUnderSamePkg: Class<*>,
    ): String {
      Util.openResourceAsStream(antlrGrammarFileName, classUnderSamePkg).use { stream ->
        return String(ByteStreams.toByteArray(stream), StandardCharsets.UTF_8)
      }
    }

    @JvmStatic
    protected fun createSeparateAntlrGrammar(
      antlrParserGrammarFileName: String,
      antlrLexerGrammarFileName: String,
      classUnderSamePkg: Class<*>,
    ): AbstractAntlrGrammar.SeparateAntlrGrammar {
      return try {
        val persesGrammar = loadGrammarFromString(
          readAntlrGrammarContent(antlrParserGrammarFileName, classUnderSamePkg),
        )
        val lexerGrammar = loadGrammarFromString(
          readAntlrGrammarContent(antlrLexerGrammarFileName, classUnderSamePkg),
        )
        AbstractAntlrGrammar.SeparateAntlrGrammar(persesGrammar, lexerGrammar)
      } catch (e: IOException) {
        throw UncheckedIOException(e)
      }
    }

    @JvmStatic
    protected fun createCombinedAntlrGrammar(
      antlrGrammarFileName: String,
      classUnderSamePkg: Class<*>,
    ): AbstractAntlrGrammar.CombinedAntlrGrammar {
      return try {
        val content = readAntlrGrammarContent(antlrGrammarFileName, classUnderSamePkg)
        val persesGrammar = loadGrammarFromString(content)
        AbstractAntlrGrammar.CombinedAntlrGrammar(persesGrammar)
      } catch (e: IOException) {
        throw UncheckedIOException(e)
      }
    }

    private val logger = FluentLogger.forEnclosingClass()
  }
}
