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
package org.perses.grammar.dyck

import com.google.common.collect.ImmutableList
import org.antlr.v4.runtime.CommonToken
import org.antlr.v4.runtime.Lexer
import org.antlr.v4.runtime.Token
import org.perses.antlr.atn.LexerAtnWrapper
import org.perses.grammar.AbstractLexerAdaptor
import org.perses.grammar.DroppedCharacter
import org.perses.grammar.ErrorTolerantLexer

// The single Dyck lexer: which balanced-delimiter characters it recognizes is a constructor
// argument, so brace-only vs brace+parenthesis is a configured value rather than a subclass. All
// tokens carry DyckTokens type numbers -- the shared vocabulary both Dyck parsers reference via
// tokenVocab -- so the lexer and either parser agree on numbering.
class DyckLexer(
  private val underlyingLexer: Lexer,
  // Decides, once per input, which balanced-delimiter kinds this lexer recognizes; any delimiter
  // whose kind is disabled, and any other token text, becomes [otherTokenType]. A fixed
  // [Configuration] (e.g. [BRACE]) is its own selector; [AdaptiveDyckConfigurationSelector] derives
  // the kinds from the delimiters the input actually contains.
  private val configurationSelector: ConfigurationSelector,
) : AbstractLexerAdaptor(underlyingLexer.inputStream) {
  private val otherTokenType: Int = DyckTokens.OTHER

  private val fabricatedNewlineTokenType: Int = DyckTokens.FABRICATED_NEWLINE

  override fun computeAllTokens(): ImmutableList<Token> {
    // The dropped characters the real lexer cannot tokenize (e.g. a `\` line-continuation in an
    // unparseable file) are merged in by source position as ordinary OTHER tokens. Without this a
    // `\`-newline splice like `st\<newline>atic` loses its `\`, the synthesized newline joins `st`
    // and `atic` directly, and reconstruction no longer round-trips (the C preprocessor cannot rejoin
    // `static`). The merge happens before the newline synthesis below, so a dropped character on the
    // preceding line is placed before its delimiter.
    val adaptedTokens =
      ErrorTolerantLexer { underlyingLexer }
        .readAllDefaultChannelTokensWithDroppedCharacters(
          adaptToken = ::adaptToken,
          adaptDroppedCharacter = ::adaptDroppedCharacter,
        )
    // The delimiter kinds are decided only after the whole stream is adapted, because an adaptive
    // selector reads them off the delimiters the input actually contains. Token types are therefore
    // assigned here, not while adapting.
    val configuration = configurationSelector.selectFor(adaptedTokens)
    val builder = ImmutableList.builder<Token>()
    for (i in adaptedTokens.indices) {
      val current = adaptedTokens[i]
      current.type = tokenTypeFor(current.text, configuration)
      builder.add(current)
      // A delimiter is synthesized at every source-line break between adjacent
      // tokens, regardless of their types. This includes breaks next to braces
      // (e.g. after `{` or before/after `}`), so a newline that starts a line
      // with no preceding node -- such as the one right after `{` in a block whose
      // body begins on the next line -- is materialized and parses as the grammar's
      // bare-`FABRICATED_NEWLINE` line. One delimiter is emitted per line break
      // regardless of how many blank lines were skipped.
      val next = adaptedTokens.getOrNull(i + 1) ?: continue
      if (next.line > current.line) {
        builder.add(createFabricatedNewlineToken(current))
      }
    }
    return builder.build()
  }

  // Spans no input: the real newline was consumed on the underlying lexer's
  // skip channel, so this token is manufactured purely to delimit lines. The
  // negative start/stop index marks it as fabricated (see
  // AbstractParserFacade.isFabricatedToken) so SparTreeBuilder drops it from the
  // tree once it has served its parse-time delimiting role.
  private fun createFabricatedNewlineToken(precedingToken: Token): CommonToken =
    CommonToken(fabricatedNewlineTokenType, "\n").apply {
      line = precedingToken.line
      charPositionInLine = precedingToken.charPositionInLine + precedingToken.text.length
      startIndex = -1
      stopIndex = -1
    }

  private fun adaptToken(oldToken: Token): CommonToken {
    val text = oldToken.text
    val newToken = convertToNewToken(text)
    newToken.charPositionInLine = oldToken.charPositionInLine
    newToken.line = oldToken.line
    newToken.startIndex = oldToken.startIndex
    newToken.stopIndex = oldToken.stopIndex
    return newToken
  }

  private fun adaptDroppedCharacter(dropped: DroppedCharacter): CommonToken =
    convertToNewToken(dropped.text).apply {
      charPositionInLine = dropped.column
      line = dropped.line
      startIndex = dropped.charIndex
      stopIndex = dropped.charIndex + dropped.text.length - 1
    }

  // The type is left undecided here: it depends on the configuration, which is only known once every
  // token has been read (see [computeAllTokens]).
  private fun convertToNewToken(text: String): CommonToken = CommonToken(Token.INVALID_TYPE, text)

  private fun tokenTypeFor(
    text: String,
    configuration: Configuration,
  ): Int =
    when (text) {
      "{" -> if (configuration.enableBraces) DyckTokens.OPEN_BRACE else otherTokenType
      "}" -> if (configuration.enableBraces) DyckTokens.CLOSE_BRACE else otherTokenType
      "(" -> if (configuration.enableParentheses) DyckTokens.OPEN_PARENTHESIS else otherTokenType
      ")" -> if (configuration.enableParentheses) DyckTokens.CLOSE_PARENTHESIS else otherTokenType
      "[" -> if (configuration.enableBrackets) DyckTokens.OPEN_BRACKET else otherTokenType
      "]" -> if (configuration.enableBrackets) DyckTokens.CLOSE_BRACKET else otherTokenType
      else -> otherTokenType
    }

  /**
   * Chooses the delimiter kinds for one input, given the whole adapted token stream. Separating this
   * from [Configuration] is what lets a facade be *adaptive*: the delimiters need not be picked
   * before the input is seen.
   */
  fun interface ConfigurationSelector {
    fun selectFor(tokens: List<Token>): Configuration
  }

  /**
   * A fixed choice of delimiter kinds. It is its own [ConfigurationSelector] -- it answers the same
   * configuration for every input -- so a facade parameterized by a selector accepts either a fixed
   * configuration or an adaptive selector without a wrapper.
   */
  class Configuration(
    val enableBraces: Boolean,
    val enableBrackets: Boolean,
    val enableParentheses: Boolean,
  ) : ConfigurationSelector {
    override fun selectFor(tokens: List<Token>): Configuration = this
  }

  companion object {
    // Required, and consumed only reflectively by the exact field name "LEXER_WRAPPER" -- which is why
    // nothing appears to reference it:
    //  - AbstractLexerAdaptor's init contract requires every adaptor to expose a static LEXER_WRAPPER
    //    field of type LexerAtnWrapper, or construction fails.
    //  - AbstractParserFacade reads it to obtain the token vocabulary/ATN metadata used at parse time.
    // It is derived from the generated DyckTokens lexer -- the same grammar that defines this lexer's
    // token vocabulary -- so the metadata matches the tokens DyckLexer emits. @JvmField makes it a real
    // static field so the reflective lookups find it.
    @JvmField
    val LEXER_WRAPPER: LexerAtnWrapper =
      LexerAtnWrapper.createLexerWrapperFromLexerClass(DyckTokens::class.java)

    val BRACE: Configuration =
      Configuration(enableBraces = true, enableBrackets = false, enableParentheses = false)

    val BRACE_PARENTHESIS: Configuration =
      Configuration(enableBraces = true, enableBrackets = false, enableParentheses = true)

    val BRACE_PARENTHESIS_BRACKET: Configuration =
      Configuration(enableBraces = true, enableBrackets = true, enableParentheses = true)
  }
}
